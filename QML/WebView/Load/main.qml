import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtWebKit 3.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    WebView {
        url: "http://localhost:63342/p01/greeting.html?name=Mahmood Ramzani"
        anchors.fill: parent
    }
}

