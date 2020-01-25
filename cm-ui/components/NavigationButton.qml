import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import "../assets"

Item {
    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text
    property color hoverColor: Style.colorNavigationBarBackground
    property real currentWidth: Style.widthNavigationButton
    property real currentHeight: Style.heightNavigationButton

    property bool isDescriptionVisible: true
    property bool isIconVisible: true

    signal navigationButtonClicked()

    width: currentWidth
    height: currentHeight

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colorNavigationBarBackground

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColor
                }
            }
        ]

        Row {
            Text {
                id: textIcon
                width: Style.widthNavigationButtonIcon
                height: Style.heightNavigationButtonIcon

                font {
                    family: Style.fontAwesome
                    pixelSize: Style.pixelSizeNavigationBarIcon
                }
                color: Style.colorNavigationBarFont
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                visible: isIconVisible
                text: "\uf11a"
            }
            Text {
                id: textDescription
                width: Style.widthNavigationButtonDescription
                height: Style.heightNavigationButtonDescription
                color: Style.colorNavigationBarFont
                verticalAlignment: Text.AlignVCenter
                visible: isDescriptionVisible
                text: "Default Text"
                font {
                    pixelSize: Style.pixelSizeNavigationBarDescription
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            width: parent.width
            height: parent.height
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: navigationButtonClicked()
        }
    }
}
