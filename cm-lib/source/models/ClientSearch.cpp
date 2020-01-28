#include "ClientSearch.h"

#include <QDebug>

using namespace cm::controllers;
using namespace cm::data;

namespace cm {
namespace models {

class ClientSearch::Implementation
{
public:
    Implementation(ClientSearch* _clientSearch, IDatabaseController* _databaseController)
        : clientSearch(_clientSearch)
        , databaseController(_databaseController)
    {
    }

    ClientSearch* clientSearch{nullptr};
    IDatabaseController* databaseController{nullptr};
    data::StringDecorator* searchText{nullptr};
    data::EntityCollection<Client>* searchResults{nullptr};
};

ClientSearch::ClientSearch(QObject* parent, IDatabaseController* databaseController)
    : Entity(parent, "ClientSearch")
{
    impl.reset(new Implementation(this, databaseController));
    impl->searchText = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this, "searchText", "Search Text")));
    impl->searchResults = static_cast<EntityCollection<Client>*>(addChildCollection(new EntityCollection<Client>(this, "searchResults")));

    connect(impl->searchResults, &EntityCollection<Client>::collectionChanged, this, &ClientSearch::searchResultsChanged);
}

ClientSearch::~ClientSearch()
{
}

StringDecorator* ClientSearch::searchText()
{
    return impl->searchText;
}

QQmlListProperty<Client> ClientSearch::ui_searchResults()
{
    return QQmlListProperty<Client>(this, impl->searchResults->derivedEntities());
}

void ClientSearch::search()
{
    qDebug() << "Searching for " << impl->searchText->value() << "...";

    auto resultsArray = impl->databaseController->find("client", impl->searchText->value());
    impl->searchResults->update(resultsArray);

    qDebug() << "Found " << impl->searchResults->baseEntities().size() << " matches";
}

} //models
} //cm
