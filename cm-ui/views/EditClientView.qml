import QtQuick 2.9
import QtQuick.Controls 2.2
import CM 1.0
import "../assets"
import "../components"

Item {
    property Client selectedClient

    Component.onCompleted: masterController.ui_commandController.setSelectedClient(selectedClient)

    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
    }

    ScrollView {
        id: scrollView
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: commandBar. top
            margins: Style.sizeScreenMargin
        }
        clip: true

        Column {
            spacing: Style.sizeScreenMargin
            width: scrollView.width

            ClientEditor {
                headerText: "Client Details"
                reference: selectedClient.ui_reference
                name: selectedClient.ui_name
            }

            AddressEditor {
                address: selectedClient.ui_supplyAddress
                headerText: "Supply Address"
            }

            AddressEditor {
                address: selectedClient.ui_billingAddress
                headerText: "Billing Address"
            }

            ContactEditor {
                width: scrollView.width
                client: selectedClient
                headerText: "Contact Details"
            }
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandController.ui_editClientViewContextCommands
    }
}
