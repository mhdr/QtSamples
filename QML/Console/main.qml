import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button{
        text: qsTr("Show")
        width: 80
        height: 30
        onClicked: {
            console.log("Hello World")
        }
    }
}

