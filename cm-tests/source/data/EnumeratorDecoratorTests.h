#pragma once

#include <QHash>
#include <QTest>

#include "source/TestSuite.h"
#include "data/Entity.h"
#include "models/Contact.h"
#include "data/EnumeratorDecorator.h"


namespace cm {
namespace data {

class EnumeratorDecoratorTests : public TestSuite
{
    Q_OBJECT
public:
    EnumeratorDecoratorTests();

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

    EnumeratorDecorator* defaultDecorator;
    EnumeratorDecorator* testDecorator;
    Entity* parentEntity;

    QString testLabel;
    QString testKey;

    QJsonValue defaultJson;
    QJsonObject testJson1;
    QJsonObject testJson2;

    int defaultValue;
    QString defaultDescription;

    int value;
    QString description;

    int newValue;
    QString newDescription;
};

} //data
} // cm
