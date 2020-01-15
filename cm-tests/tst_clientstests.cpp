#include <QtTest>

// add necessary includes here

class ClientsTests : public QObject
{
    Q_OBJECT

public:
    ClientsTests();
    ~ClientsTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

ClientsTests::ClientsTests()
{

}

ClientsTests::~ClientsTests()
{

}

void ClientsTests::initTestCase()
{

}

void ClientsTests::cleanupTestCase()
{

}

void ClientsTests::test_case1()
{

}

QTEST_APPLESS_MAIN(ClientsTests)

#include "tst_clientstests.moc"
