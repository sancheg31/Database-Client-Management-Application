#include "TestSuite.h"

namespace cm {

TestSuite::TestSuite(const QString& test): QObject(), testName(test) {
    //qDebug() << "creating test" << testName;
    testList().push_back(this);
    //qDebug() << testList().size() << " tests recorded";
}

TestSuite::~TestSuite() {
    //qDebug() << "destroying test";
}

QVector<TestSuite*>& TestSuite::testList() {
    static QVector<TestSuite*> instance{};
    return instance;
}


} //cm

