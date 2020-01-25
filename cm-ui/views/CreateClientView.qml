import QtQuick 2.9
import "../assets"
import "../components"

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colorBackground
        Text {
            anchors.centerIn: parent
            text: "Create Client View"
        }
    }
    CommandBar {
        commandList: masterController.ui_commandController.ui_createClientViewContextCommands
    }
}
