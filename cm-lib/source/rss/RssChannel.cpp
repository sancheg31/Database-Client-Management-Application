#include "RssChannel.h"
#include <QtXml/QDomDocument>

namespace cm {
namespace rss {

class RssChannel::Implementation
{
public:
    QString description;            // Mandatory.  Phrase or sentence describing the channel.
    RssImage* image{nullptr};       // Optional.  Image representing the channel.
    QList<RssItem*> items;          // Optional.  Collection representing stories.
    QString link;                   // Mandatory.  URL to the corresponding HTML website.
    QString title;                  // Mandatory.  THe name of the Channel.

    void update(const QDomNode& domNode)
    {
        QDomElement channelDescription = domNode.firstChildElement("description");
        if(!channelDescription.isNull()) {
            description = channelDescription.text();
        }

        QDomElement channelLink = domNode.firstChildElement("link");
        if(!channelLink.isNull()) {
            link = channelLink.text();
        }

        QDomElement channelTitle = domNode.firstChildElement("title");
        if(!channelTitle.isNull()) {
            title = channelTitle.text();
        }
    }
};

RssChannel::RssChannel(QObject* parent, const QDomNode& domNode)
    : QObject(parent)
{
    impl.reset(new Implementation());
    impl->update(domNode);
}

RssChannel::~RssChannel()
{
}

void RssChannel::addItem(RssItem* item)
{
    if(!impl->items.contains(item)) {
        item->setParent(this);
        impl->items.push_back(item);
    }
}

const QString&  RssChannel::description() const
{
    return impl->description;
}

RssImage* RssChannel::image() const
{
    return impl->image;
}

const QList<RssItem*>&  RssChannel::items() const
{
    return impl->items;
}

const QString&  RssChannel::link() const
{
    return impl->link;
}

void RssChannel::setImage(RssImage* image)
{
    if(impl->image) {
        impl->image->deleteLater();
        impl->image = nullptr;
    }

    image->setParent(this);
    impl->image = image;
}

const QString& RssChannel::title() const
{
    return impl->title;
}
QQmlListProperty<RssItem> RssChannel::ui_items()
{
    return QQmlListProperty<RssItem>(this, impl->items);
}

RssChannel* RssChannel::fromXml(const QByteArray& xmlData, QObject* parent)
{
    QDomDocument doc;
    doc.setContent(xmlData);

    auto channelNodes = doc.elementsByTagName("channel");

    // Rss must have 1 channel
    if(channelNodes.size() != 1) return nullptr;

    RssChannel* channel = new RssChannel(parent, channelNodes.at(0));
    auto imageNodes = doc.elementsByTagName("image");
    if(imageNodes.size() > 0) {
        channel->setImage(new RssImage(channel, imageNodes.at(0)));
    }

    auto itemNodes = doc.elementsByTagName("item");
    for (auto i = 0; i < itemNodes.size(); ++i) {
        channel->addItem(new RssItem(channel, itemNodes.item(i)));
    }

    return channel;
}

} //rss
} //cm
