import QtQuick 2.9
import "../assets"

Item {
    property alias commandList: commandRepeater.model

    anchors {
        left: parent.left
        bottom: parent.bottom
        right: parent.right
    }
    height: Style.heightCommandBar

    Rectangle {
        anchors.fill: parent
        color: Style.colourCommandBarBackground

        Row {
            anchors {
                top: parent.top
                bottom: parent.bottom
                left: parent.left
            }

            Repeater {
                id: commandRepeater
                delegate: CommandButton {
                    command: modelData
                }
            }
        }
    }
}
