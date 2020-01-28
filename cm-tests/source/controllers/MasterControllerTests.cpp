#include "MasterControllerTests.h"

namespace cm {
namespace controllers {

static MasterControllerTests instance;

MasterControllerTests::MasterControllerTests(): TestSuite("MasterControllerTests") { }

void MasterControllerTests::initTestCase() {

}

void MasterControllerTests::cleanupTestCase() {

}

void MasterControllerTests::init() {

}

void MasterControllerTests:: cleanup() {

}

void MasterControllerTests::welcomeMessage_returnsCorrectMessage() {
    QCOMPARE(masterController.welcomeMessage(), QString("Welcome to the Client Management system!"));
}

} //controllers
} //cm





















