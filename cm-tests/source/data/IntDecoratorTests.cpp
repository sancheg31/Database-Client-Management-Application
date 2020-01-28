#include "IntDecoratorTests.h"

#include <QSignalSpy>

#include "data/Entity.h"

namespace cm {
namespace data {

static IntDecoratorTests instance;

IntDecoratorTests::IntDecoratorTests(): cm::TestSuite("IntDecoratorTests") { }

} //data

namespace data {

void IntDecoratorTests::initTestCase() {
    defaultValue = 0;

    testLabel = QString("Test Label");
    testKey = QString("Test Key");

    value = 99;
    newValue = value+1;

    defaultJson = QJsonValue::fromVariant(defaultValue);
    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson1.insert("Test Key", QJsonValue::fromVariant(newValue));
    testJson1.insert("Key 3", QJsonValue::fromVariant(defaultValue));

    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson2.insert("Key 2", QJsonValue::fromVariant(newValue));
    testJson2.insert("Key 3", QJsonValue::fromVariant(defaultValue));
}

void IntDecoratorTests::cleanupTestCase() {

}

void IntDecoratorTests::init() {
    parentEntity = new Entity;
    defaultDecorator = new IntDecorator();
    testDecorator = new IntDecorator(parentEntity, testKey, testLabel, value);
}

void IntDecoratorTests::cleanup() {
    delete testDecorator;
    delete defaultDecorator;
}

void IntDecoratorTests::constructor_givenNoParameters_setsDefaultProperties() {
    QCOMPARE(defaultDecorator->parentEntity(), nullptr);
    QCOMPARE(defaultDecorator->key(), QString(""));
    QCOMPARE(defaultDecorator->label(), QString(""));
    QCOMPARE(defaultDecorator->value(), defaultValue);
}

void IntDecoratorTests::constructor_givenParameters_setsProperties() {
    QCOMPARE(testDecorator->parentEntity(), parentEntity);
    QCOMPARE(testDecorator->key(), testKey);
    QCOMPARE(testDecorator->label(), testLabel);
    QCOMPARE(testDecorator->value(), value);
}

void IntDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal() {
    QSignalSpy valChanged(defaultDecorator, &IntDecorator::valueChanged);
    QCOMPARE(defaultDecorator->value(), defaultValue);
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->value(), value);
    QCOMPARE(valChanged.count(), 1);
}

void IntDecoratorTests::setValue_givenSameValue_takesNoAction() {
    QSignalSpy valChanged(testDecorator, &IntDecorator::valueChanged);
    QCOMPARE(testDecorator->value(), value);
    testDecorator->setValue(value);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(valChanged.count(), 0);
}

void IntDecoratorTests::jsonValue_whenDefaultValue_returnsJson() {
    QCOMPARE(defaultDecorator->jsonValue(), defaultJson);
}

void IntDecoratorTests::jsonValue_whenValueSet_returnsJson() {
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->jsonValue(), QJsonValue::fromVariant(value));
}

void IntDecoratorTests::update_whenPresentInJson_updatesValue() {
    QSignalSpy valChanged(testDecorator, &IntDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson1);
    QCOMPARE(testDecorator->value(), newValue);
    QCOMPARE(valChanged.count(), 1);
}

void IntDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault() {
    QSignalSpy valChanged(testDecorator, &IntDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson2);
    QCOMPARE(testDecorator->value(), defaultValue);
    QCOMPARE(valChanged.count(), 1);
}


} //data
} //cm
