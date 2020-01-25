import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1024
    height: 768
    title: qsTr("Scratchpad")
    color: "#ffffff"
    Rectangle {
        id: paleYellowBackground
        anchors.fill: parent
        color: "#cece9e"
    }

    Rectangle {
        id: blackRectangleInTheCentre
        width: 120
        height: 120
        anchors.centerIn: parent
        color: "#000000"
    }

    Rectangle {
        id: greenRectangleInTheCentreRB
        width: 100
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: (blackRectangleInTheCentre.width+this.width) / 2
            horizontalCenterOffset: (blackRectangleInTheCentre.height+this.height) / 2
            margins: 20
        }
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreLB
        width: 100
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: (blackRectangleInTheCentre.width+this.width) / 2
            horizontalCenterOffset: - (blackRectangleInTheCentre.height+this.height) / 2
            margins: 20
        }
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreRT
        width: 100
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: -(blackRectangleInTheCentre.width+this.width) / 2
            horizontalCenterOffset: (blackRectangleInTheCentre.height+this.height) / 2
            margins: 20
        }
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreLT
        width: 100
        height: 100
        anchors {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
            verticalCenterOffset: -(blackRectangleInTheCentre.width+this.width) / 2
            horizontalCenterOffset: -(blackRectangleInTheCentre.height+this.height) / 2
            margins: 20
        }
        color: "#008000"
    }

    Rectangle {
        id: redRectangleTopLeftCorner
        width: 100
        height: 100
        anchors {
            top: parent.top
            margins: 20
            left: parent.left
        }
        color: "#800000"
    }

    Rectangle {
        id: blueRectangleTopLeftCorner
        width: 100
        height: 100
        anchors {
            top: redRectangleTopLeftCorner.bottom
            left: parent.left
            margins: 20
        }
        color: "#000080"
    }

    Rectangle {
        id: purpleRectangleTopLeftCorner
        width: 100
        height: 100
        anchors {
            top: blueRectangleTopLeftCorner.bottom
            left: parent.left
            margins: 20
        }
        color: "#800080"
    }

    Rectangle {
        id: tRectangleBottomRightCorner
        width: 100
        height: 100
        anchors {
            bottom: parent.bottom
            right: parent.right
            margins: 20
        }
        color: "#008080"
    }

}




