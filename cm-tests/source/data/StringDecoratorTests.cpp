#include "StringDecoratorTests.h"

#include <QSignalSpy>

#include "data/Entity.h"

namespace cm {
namespace data {

static StringDecoratorTests instance;

StringDecoratorTests::StringDecoratorTests(): cm::TestSuite("StringDecoratorTests") { }

void StringDecoratorTests::initTestCase() {
    defaultValue = "";

    testLabel = QString("Test Label");
    testKey = QString("Test Key");

    value = "soso";
    newValue = value + "si";

    defaultJson = QJsonValue::fromVariant(defaultValue);
    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson1.insert("Test Key", QJsonValue::fromVariant(newValue));
    testJson1.insert("Key 3", QJsonValue::fromVariant(defaultValue));

    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson2.insert("Key 2", QJsonValue::fromVariant(newValue));
    testJson2.insert("Key 3", QJsonValue::fromVariant(defaultValue));
}

void StringDecoratorTests::cleanupTestCase() {

}

void StringDecoratorTests::init() {
    parentEntity = new Entity;
    defaultDecorator = new StringDecorator();
    testDecorator = new StringDecorator(parentEntity, testKey, testLabel, value);
}

void StringDecoratorTests::cleanup() {
    delete testDecorator;
    delete defaultDecorator;
}

void StringDecoratorTests::constructor_givenNoParameters_setsDefaultProperties() {
    QCOMPARE(defaultDecorator->parentEntity(), nullptr);
    QCOMPARE(defaultDecorator->key(), QString(""));
    QCOMPARE(defaultDecorator->label(), QString(""));
    QCOMPARE(defaultDecorator->value(), defaultValue);
}

void StringDecoratorTests::constructor_givenParameters_setsProperties() {
    QCOMPARE(testDecorator->parentEntity(), parentEntity);
    QCOMPARE(testDecorator->key(), testKey);
    QCOMPARE(testDecorator->label(), testLabel);
    QCOMPARE(testDecorator->value(), value);
}

void StringDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal() {
    QSignalSpy valChanged(defaultDecorator, &StringDecorator::valueChanged);
    QCOMPARE(defaultDecorator->value(), defaultValue);
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->value(), value);
    QCOMPARE(valChanged.count(), 1);
}

void StringDecoratorTests::setValue_givenSameValue_takesNoAction() {
    QSignalSpy valChanged(testDecorator, &StringDecorator::valueChanged);
    QCOMPARE(testDecorator->value(), value);
    testDecorator->setValue(value);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(valChanged.count(), 0);
}

void StringDecoratorTests::jsonValue_whenDefaultValue_returnsJson() {
    QCOMPARE(defaultDecorator->jsonValue(), defaultJson);
}

void StringDecoratorTests::jsonValue_whenValueSet_returnsJson() {
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->jsonValue(), QJsonValue::fromVariant(value));
}

void StringDecoratorTests::update_whenPresentInJson_updatesValue() {
    QSignalSpy valChanged(testDecorator, &StringDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson1);
    QCOMPARE(testDecorator->value(), newValue);
    QCOMPARE(valChanged.count(), 1);
}

void StringDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault() {
    QSignalSpy valChanged(testDecorator, &StringDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson2);
    QCOMPARE(testDecorator->value(), defaultValue);
    QCOMPARE(valChanged.count(), 1);
}


} //data
} //cm
