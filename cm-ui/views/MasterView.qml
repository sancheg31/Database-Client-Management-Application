import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import "../assets"
import "../components"

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Client Management")

    Connections {
        target: masterController.ui_navigationController
        onCreateClientView: contentFrame.replace("qrc:/views/CreateClientView.qml")
        onGoDashboardView: contentFrame.replace("qrc:/views/DashboardView.qml")
        onGoEditClientView: contentFrame.replace("qrc:/views/EditClientView.qml", {selectedClient: client })
        onGoFindClientView: contentFrame.replace("qrc:/views/FindClientView.qml")
    }


    StackView {
        clip: true
        id: contentFrame
        width: parent.width
        height: parent.height
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.left
        }
        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }

    NavigationBar {
        id: navigationBar
        isCollapsed: false
    }


}
