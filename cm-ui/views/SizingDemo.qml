import QtQuick 2.9
import QtQuick.Window 2.2
import "../assets"


Window {
    visible: true
    width: 1024
    height: 768
    title: qsTr("scrathpad")
    color: Style.colorNavigationBarBackground
    Column {
        id: columnWithText
        Text {
            id: text1
            text: "Text 1"
        }
        Text {
            id: text2
            text: "Text 2"
            width: 300
            height: 20
        }
        Text {
            id: text3
            text: "Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3 Text 3"
        }
        Text {
            id: text4
            text: "Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4 Text 4"
            width: 300
        }
        Text {
            id: text5
            text: "Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5 Text 5"
            width: 300
            wrapMode: Text.Wrap
        }
    }
    Column {
        id: columnWithRectangle
        Rectangle {
            id: rectangle
            anchors.fill: parent
        }
    }
    Component.onCompleted: {
        console.log("Fuck you")
    }
}
