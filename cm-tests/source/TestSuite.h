#pragma once

#include <QObject>
#include <QString>
#include <QtTest/QtTest>
#include <QTest>
#include <QVector>

namespace cm {

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(const QString& test = "");
    virtual ~TestSuite();

    QString testName;
    static QVector<TestSuite*>& testList();
signals:

};

} //cm



