import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import "../assets"
import "../components"

Item {
    id: navigationBar

    property bool isCollapsed: true
    property real currentWidth: isCollapsed ? Style.widthNavigationBarCollapsed : Style.widthNavigationBarExpanded
    property bool isNavigationButtonIconVisible: true
    property bool isNavigationButtonDescriptionVisible: isCollapsed ? false: true

    width: currentWidth

    anchors {
        top: parent.top
        left: parent.left
        bottom: parent.bottom
    }

    Rectangle {
        anchors.fill: parent
        width: parent.width
        color: Style.colorNavigationBarBackground
        Column {
            width: parent.width
            //Toggle Menu
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                currentWidth: parent.width
                hoverColor: Style.colorNavigationBarHover
                isDescriptionVisible: isNavigationButtonDescriptionVisible
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            //Dashboard
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                currentWidth: parent.width
                hoverColor: Style.colorNavigationBarHover
                isDescriptionVisible: isNavigationButtonDescriptionVisible
                onNavigationButtonClicked: masterController.ui_navigationController.goDashboardView()
            }
            //New Client
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
                currentWidth: parent.width
                hoverColor: Style.colorNavigationBarHover
                isDescriptionVisible: isNavigationButtonDescriptionVisible
                onNavigationButtonClicked: masterController.ui_navigationController.createClientView()
            }
            //Find Client
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
                currentWidth: parent.width
                hoverColor: Style.colorNavigationBarHover
                isDescriptionVisible: isNavigationButtonDescriptionVisible
                onNavigationButtonClicked: masterController.ui_navigationController.goFindClientView()
            }
        }
    }
}
