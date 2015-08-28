import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button1
        x: 274
        y: 174
        text: qsTr("Button")
        onClicked: messageClass.triggerWelcome("Mahmood")
    }

    Label {
        id: label1
        x: 306
        y: 252
        text: qsTr("Label")
    }


    function welcome(msg)
    {
        label1.text=msg;
    }
}

