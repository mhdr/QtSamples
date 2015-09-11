import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id : mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Create Object")

    Flow {
        id: flow1
        width: 640
        height: 480
        flow: Flow.TopToBottom
        layoutDirection: Qt.LeftToRight

        Button {
            id: button1
            x: 186
            y: 143
            text: qsTr("Button")
            onClicked: {
                var spriteComponent= Qt.createComponent("Sprite.qml")
                //spriteComponent.createObject(flow1, {"x": 100, "y": 100})
                spriteComponent.createObject(flow1)
            }
        }
    }
}

