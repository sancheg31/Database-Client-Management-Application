#include "EnumeratorDecoratorTests.h"

#include <QSignalSpy>

#include "data/Entity.h"

using namespace cm::models;

namespace cm {
namespace data {

static EnumeratorDecoratorTests instance;

EnumeratorDecoratorTests::EnumeratorDecoratorTests(): cm::TestSuite("EnumeratorDecoratorTests") { }

void EnumeratorDecoratorTests::initTestCase() {

    defaultValue = 0;
    defaultDescription = Contact::contactTypeMapper[0];

    testLabel = QString("Test Label");
    testKey = QString("Test Key");

    value = 1;
    description = Contact::contactTypeMapper[1];
    newValue = 2;
    newDescription = Contact::contactTypeMapper[2];

    defaultJson = QJsonValue::fromVariant(defaultValue);
    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson1.insert(testKey, QJsonValue::fromVariant(newValue));
    testJson1.insert("Key 3", QJsonValue::fromVariant(defaultValue));

    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson2.insert("Key 2", QJsonValue::fromVariant(newValue));
    testJson2.insert("Key 3", QJsonValue::fromVariant(defaultValue));

}

void EnumeratorDecoratorTests::cleanupTestCase() {

}

void EnumeratorDecoratorTests::init() {
    parentEntity = new Entity;
    defaultDecorator = new EnumeratorDecorator();
    testDecorator = new EnumeratorDecorator(parentEntity, testKey, testLabel, value, Contact::contactTypeMapper);
}

void EnumeratorDecoratorTests::cleanup() {
    delete testDecorator;
    delete defaultDecorator;
}

void EnumeratorDecoratorTests::constructor_givenNoParameters_setsDefaultProperties() {
    QCOMPARE(defaultDecorator->parentEntity(), nullptr);
    QCOMPARE(defaultDecorator->key(), QString(""));
    QCOMPARE(defaultDecorator->label(), QString(""));
    QCOMPARE(defaultDecorator->value(), defaultValue);
    QCOMPARE(defaultDecorator->valueDescription(), defaultDescription);
}

void EnumeratorDecoratorTests::constructor_givenParameters_setsProperties() {
    QCOMPARE(testDecorator->parentEntity(), parentEntity);
    QCOMPARE(testDecorator->key(), testKey);
    QCOMPARE(testDecorator->label(), testLabel);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
}

void EnumeratorDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal() {
    QSignalSpy valChanged(defaultDecorator, &EnumeratorDecorator::valueChanged);
    QCOMPARE(defaultDecorator->value(), defaultValue);
    QCOMPARE(defaultDecorator->valueDescription(), defaultDescription);
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
    QCOMPARE(valChanged.count(), 1);
}

void EnumeratorDecoratorTests::setValue_givenSameValue_takesNoAction() {
    QSignalSpy valChanged(testDecorator, &EnumeratorDecorator::valueChanged);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
    testDecorator->setValue(value);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
    QCOMPARE(valChanged.count(), 0);
}

void EnumeratorDecoratorTests::jsonValue_whenDefaultValue_returnsJson() {
    QCOMPARE(defaultDecorator->jsonValue(), defaultJson);
}

void EnumeratorDecoratorTests::jsonValue_whenValueSet_returnsJson() {
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->jsonValue(), QJsonValue::fromVariant(value));
}

void EnumeratorDecoratorTests::update_whenPresentInJson_updatesValue() {
    QSignalSpy valChanged(testDecorator, &EnumeratorDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
    testDecorator->update(testJson1);
    QCOMPARE(testDecorator->value(), newValue);
    QCOMPARE(testDecorator->valueDescription(), newDescription);
    QCOMPARE(valChanged.count(), 1);
}

void EnumeratorDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault() {
    QSignalSpy valChanged(testDecorator, &EnumeratorDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(testDecorator->valueDescription(), description);
    testDecorator->update(testJson2);
    QCOMPARE(testDecorator->value(), defaultValue);
    QCOMPARE(testDecorator->valueDescription(), defaultDescription);
    QCOMPARE(valChanged.count(), 1);
}


} //data
} //cm
