import QtQuick 2.9
import "../assets"

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourDashboardBackground

        Image {
            id: logo
            source: "qrc:/assets/Dashboard.png"
            anchors.centerIn: parent
            width: Style.sizeDashboardLogo
            height: Style.sizeDashboardLogo
        }

        Text {
            anchors {
                top: logo.bottom
                horizontalCenter: logo.horizontalCenter
            }
            text: "Client Management System"
            color: Style.colourDashboardFont
            font.pixelSize: Style.pixelSizeDashboard
        }
    }
}

