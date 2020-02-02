import QtQuick 2.0
import "../components"
import "../assets"
import CM 1.0
Item {
    property Client client
    Panel {
        contentComponent:
        Column {
            id: column
            spacing: Style.sizeControlSpacing
            StringEditorSingleLine {
                stringDecorator: client.ui_reference
                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
            StringEditorSingleLine {
                stringDecorator: client.ui_name
                left: parent.left
                right: parent.right
            }
        }
    }
}
