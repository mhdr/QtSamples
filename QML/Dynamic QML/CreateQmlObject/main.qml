import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Create QML Object")

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
                var qmlStr="import QtQuick 2.5
import QtQuick.Controls 1.4

Rectangle{
    width: 80
    height: 50
    color: 'red'
}
"
                Qt.createQmlObject(qmlStr,flow1)
            }
        }
    }
}

