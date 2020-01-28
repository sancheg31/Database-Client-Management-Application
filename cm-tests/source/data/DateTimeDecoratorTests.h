#pragma once

#include <QTest>

#include "source/TestSuite.h"
#include "data/DateTimeDecorator.h"
#include "data/Entity.h"

namespace cm {
namespace data {

class DateTimeDecoratorTests : public cm::TestSuite
{
    Q_OBJECT
public:
    DateTimeDecoratorTests();
private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void constructor_givenNoParameters_setsDefaultProperties();
    void constructor_givenParameters_setsProperties();
    void setValue_givenNewValue_updatesValueAndEmitsSignal();
    void setValue_givenSameValue_takesNoAction();
    void jsonValue_whenDefaultValue_returnsJson();
    void jsonValue_whenValueSet_returnsJson();
    void update_whenPresentInJson_updatesValue();
    void update_whenNotPresentInJson_updatesValueToDefault();

private:

    DateTimeDecorator* defaultDecorator;
    DateTimeDecorator* testDecorator;
    Entity* parentEntity;

    QString testLabel;
    QString testKey;

    QDate date;
    QTime time;

    QJsonValue defaultJson;
    QJsonObject testJson1;
    QJsonObject testJson2;

    QDateTime defaultValue;
    QDateTime value;
    QDateTime newValue;
};

} //data
} // cm


