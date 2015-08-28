import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextField {
        id: textField1
        x: 255
        y: 151
        placeholderText: qsTr("")
    }

    Button {
        id: button1
        x: 274
        y: 197
        text: qsTr("Welcome")
        onClicked:
        {
            if (textField1.text.length>0)
            {
                var name=textField1.text;
                var welcome= greetingClass.welcome(name);
                label1.text=welcome;
            }
        }
    }

    Label {
        id: label1
        x: 306
        y: 259
        text: qsTr("")
    }


}

