import QtQuick 2.9
import CM 1.0
import "../assets"

Item {

    property Command command
    property color fontColor: command.ui_canExecute ? Style.colorCommandBarFont : Style.colorCommandBarFontDisabled
    width: Style.widthCommandButton
    height: Style.heightCommandButton


    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colorNavigationBarBackground

        Text {
            id: textIcon
            anchors {
                centerIn: parent
                verticalCenterOffset: -10
            }
            font {
                family: Style.fontAwesome
                pixelSize: Style.pixelSizeCommandBarIcon
            }

            color: fontColor
            text: command.ui_iconCharacter
            verticalAlignment: Text.AlignHCenter
        }

        Text {
            id: textDescription
            anchors {
                top: textIcon.bottom
                bottom: parent.bottom
                left: parent.left
                right: parent.right
            }
            font {
                family: Style.fontAwesome
                pixelSize: Style.pixelSizeCommandBarDescription
            }
            color: fontColor
            text: command.ui_description
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            anchors.fill: parent
            width: parent.width
            height: parent.height
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: if (command.ui_canExecute) {
                           command.executed();
                       }
        }

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: Qt.darker(Style.colorCommandBarBackground)
                }
            }

        ]
    }
}














