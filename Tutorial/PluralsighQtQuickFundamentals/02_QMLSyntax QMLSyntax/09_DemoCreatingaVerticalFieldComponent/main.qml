import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:mainWindow

    Flow
    {
        anchors.centerIn: parent
        flow: Flow.TopToBottom
        width: mainWindow.width
        height: mainWindow.height

        HorizontalField{
            id: horizontalField1
            width: 200
        }

        HorizontalField{
            id: horizontalField2
            width: 200
            textFieldWidth: 150
        }
    }
}

