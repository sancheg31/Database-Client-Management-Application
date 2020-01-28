#include "DateTimeDecoratorTests.h"

#include <QSignalSpy>

#include "data/Entity.h"

namespace cm {
namespace data {

static DateTimeDecoratorTests instance;


DateTimeDecoratorTests::DateTimeDecoratorTests(): cm::TestSuite("DateTimeDecoratorTests") { }

} //data

namespace data {

void DateTimeDecoratorTests::initTestCase() {
    defaultValue = QDateTime();

    testLabel = QString("Test Label");
    testKey = QString("Test Key");

    date = QDate(2001, 9, 11);
    time = QTime(5, 36, 20);

    value = QDateTime(date, time);
    newValue = value;
    newValue.setTime(time.addSecs(30));

    defaultJson = QJsonValue::fromVariant(defaultValue.toString(Qt::ISODate));
    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson1.insert("Test Key", QJsonValue::fromVariant(newValue));
    testJson1.insert("Key 3", QJsonValue::fromVariant(defaultValue));

    testJson1.insert("Key 1", QJsonValue::fromVariant(defaultValue));
    testJson2.insert("Key 2", QJsonValue::fromVariant(newValue));
    testJson2.insert("Key 3", QJsonValue::fromVariant(defaultValue));
}

void DateTimeDecoratorTests::cleanupTestCase() {

}

void DateTimeDecoratorTests::init() {
    parentEntity = new Entity;
    defaultDecorator = new DateTimeDecorator();
    testDecorator = new DateTimeDecorator(parentEntity, testKey, testLabel, value);
}

void DateTimeDecoratorTests::cleanup() {
    delete testDecorator;
    delete defaultDecorator;
}

void DateTimeDecoratorTests::constructor_givenNoParameters_setsDefaultProperties() {
    QCOMPARE(defaultDecorator->parentEntity(), nullptr);
    QCOMPARE(defaultDecorator->key(), QString(""));
    QCOMPARE(defaultDecorator->label(), QString(""));
    QCOMPARE(defaultDecorator->value(), defaultValue);
}

void DateTimeDecoratorTests::constructor_givenParameters_setsProperties() {
    QCOMPARE(testDecorator->parentEntity(), parentEntity);
    QCOMPARE(testDecorator->key(), testKey);
    QCOMPARE(testDecorator->label(), testLabel);
    QCOMPARE(testDecorator->value(), value);
}

void DateTimeDecoratorTests::setValue_givenNewValue_updatesValueAndEmitsSignal() {
    QSignalSpy valChanged(defaultDecorator, &DateTimeDecorator::valueChanged);
    QCOMPARE(defaultDecorator->value(), defaultValue);
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->value(), value);
    QCOMPARE(valChanged.count(), 1);
}

void DateTimeDecoratorTests::setValue_givenSameValue_takesNoAction() {
    QSignalSpy valChanged(testDecorator, &DateTimeDecorator::valueChanged);
    QCOMPARE(testDecorator->value(), value);
    testDecorator->setValue(value);
    QCOMPARE(testDecorator->value(), value);
    QCOMPARE(valChanged.count(), 0);
}

void DateTimeDecoratorTests::jsonValue_whenDefaultValue_returnsJson() {
    QCOMPARE(defaultDecorator->jsonValue(), defaultJson);
    qDebug() << defaultDecorator->jsonValue().toString() << " " << defaultDecorator->jsonValue().toString();
}

void DateTimeDecoratorTests::jsonValue_whenValueSet_returnsJson() {
    defaultDecorator->setValue(value);
    QCOMPARE(defaultDecorator->jsonValue(), QJsonValue::fromVariant(value.toString(Qt::ISODate)));
}

void DateTimeDecoratorTests::update_whenPresentInJson_updatesValue() {
    QSignalSpy valChanged(testDecorator, &DateTimeDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson1);
    QCOMPARE(testDecorator->value(), newValue);
    QCOMPARE(valChanged.count(), 1);
}

void DateTimeDecoratorTests::update_whenNotPresentInJson_updatesValueToDefault() {
    QSignalSpy valChanged(testDecorator, &DateTimeDecorator::valueChanged);

    QCOMPARE(testDecorator->value(), value);
    testDecorator->update(testJson2);
    QCOMPARE(testDecorator->value(), defaultValue);
    QCOMPARE(valChanged.count(), 1);
}


} //data
} //cm
