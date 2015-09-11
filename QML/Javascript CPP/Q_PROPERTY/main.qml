import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Component.onCompleted:
    {
        messageClass.message="Initialize"
    }

    Button {
        id: button1
        x: 274
        y: 226
        text: qsTr("Show")
        onClicked: messageClass.doMessage()
    }

    Label {
        id: label1
        x: 306
        y: 298
        text: messageClass.message
    }

}

