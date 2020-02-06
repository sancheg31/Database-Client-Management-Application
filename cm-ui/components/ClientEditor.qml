import QtQuick 2.0
import "../components"
import "../assets"
import CM 1.0

Panel {
    property StringDecorator reference
    property StringDecorator name
    contentComponent:
        Column {
            id: column
            spacing: Style.sizeControlSpacing
            StringEditorSingleLine {
                stringDecorator: reference
                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
            StringEditorSingleLine {
                stringDecorator: name
                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
        }
}
