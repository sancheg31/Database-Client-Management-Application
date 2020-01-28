#pragma once


#include <QScopedPointer>
#include <controllers/IDataBaseController.h>
#include "data/StringDecorator.h"
#include "data/Entity.h"
#include "data/EntityCollection.h"
#include "models/Client.h"

#include "cm-lib_global.h"

namespace cm {
namespace models {

class CMLIB_EXPORT ClientSearch : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY( cm::data::StringDecorator* ui_searchText READ searchText CONSTANT )
    Q_PROPERTY( QQmlListProperty<cm::models::Client> ui_searchResults READ ui_searchResults NOTIFY searchResultsChanged )

public:
    ClientSearch(QObject* parent = nullptr, controllers::IDatabaseController* databaseController = nullptr);
    ~ClientSearch();

    data::StringDecorator* searchText();
    QQmlListProperty<Client> ui_searchResults();
    void search();

signals:
    void searchResultsChanged();

private:
    class Implementation;
    QScopedPointer<Implementation> impl;
};

} //models
} //cm
