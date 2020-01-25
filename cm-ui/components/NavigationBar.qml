import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import "../assets"
import "../components"

Rectangle {
    id: navigationBar
    anchors {
    }
    Column {
        //Toggle Menu
        NavigationButton {
            iconCharacter: "\uf0c9"
            description: ""
        }
        //Dashboard
        NavigationButton {
            iconCharacter: "\uf015"
            description: "Dashboard"
        }
        //New Client
        NavigationButton {
            iconCharacter: "\uf234"
            description: "New Client"
        }
        //Find Client
        NavigationButton {
            iconCharacter: "\uf002"
            description: "Find Client"
        }
    }
}
