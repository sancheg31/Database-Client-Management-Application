pragma Singleton
import QtQuick 2.9

Item {
    property alias fontAwesome: fontAwesomeLoader.name

    readonly property color colorBackground: "#efefef"

    readonly property color colorNavigationBarBackground: "#000000"
    readonly property color colorNavigationBarFont: "#ffffff"
    readonly property color colorNavigationBarHover: "#993333"

    readonly property color colorCommandBarBackground: "#cecece"
    readonly property color colorCommandBarFont: colorCommandBarBackground
    readonly property color colorCommandBarFontDisabled: "#636363"

    readonly property real widthNavigationButtonIcon: 80
    readonly property real heightNavigationButtonIcon: widthNavigationButtonIcon

    readonly property real widthNavigationButtonDescription: 140
    readonly property real heightNavigationButtonDescription: heightNavigationButtonIcon

    readonly property real widthNavigationButton: widthNavigationButtonIcon + widthNavigationButtonDescription
    readonly property real heightNavigationButton: Math.max(heightNavigationButtonIcon, heightNavigationButtonDescription)

    readonly property real widthNavigationBarCollapsed: widthNavigationButtonIcon
    readonly property real widthNavigationBarExpanded: widthNavigationButton

    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton
    readonly property real heightCommandBar: heightCommandButton

    readonly property int pixelSizeCommandBarIcon: 32
    readonly property int pixelSizeNavigationBarIcon: 42
    readonly property int pixelSizeCommandBarDescription: 12
    readonly property int pixelSizeNavigationBarDescription: 22


    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }
}
