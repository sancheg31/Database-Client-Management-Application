#pragma once

#include <QtTest>

#include "source/TestSuite.h"
#include "controllers/MasterController.h"

#include "mocks/MockObjectFactory.h"


namespace cm {
namespace controllers {

class MasterControllerTests : public TestSuite
{
    Q_OBJECT
public:
    MasterControllerTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

private slots:
    void welcomeMessage_returnsCorrectMessage();

private:
    MasterController* masterController{nullptr};
    framework::MockObjectFactory mockObjectFactory;
};


} //controllers
} //cm


