#include "MasterControllerTests.h"

namespace cm {
namespace controllers {

static MasterControllerTests instance;

MasterControllerTests::MasterControllerTests()
    : TestSuite( "MasterControllerTests" ) { }


void MasterControllerTests::initTestCase() { }

void MasterControllerTests::cleanupTestCase() { }

void MasterControllerTests::init() {
    masterController = new MasterController(this, &mockObjectFactory);
}

void MasterControllerTests::cleanup() {
    if(masterController != nullptr) {
        masterController->deleteLater();
        masterController = nullptr;
    }
}

void MasterControllerTests::welcomeMessage_returnsCorrectMessage()
{
    QCOMPARE( masterController->welcomeMessage(), QString("Welcome to the Client Management system!") );
}

} //controllers
} //cm





















