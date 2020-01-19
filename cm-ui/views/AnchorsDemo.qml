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
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 110
        anchors.horizontalCenterOffset: 110
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreLB
        width: 100
        height: 100
        anchors.centerIn: parent
        anchors.verticalCenterOffset: 110
        anchors.horizontalCenterOffset: -110
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreRT
        width: 100
        height: 100
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -110
        anchors.horizontalCenterOffset: 110
        color: "#008000"
    }
    Rectangle {
        id: greenRectangleInTheCentreLT
        width: 100
        height: 100
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -110
        anchors.horizontalCenterOffset: -110
        color: "#008000"
    }

    Rectangle {
        id: redRectangleTopLeftCorner
        width: 100
        height: 100
        anchors {
            top: parent.top
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
        }
        color: "#000080"
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




