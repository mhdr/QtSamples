import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property date myDate: "2014-05-30"
    property string myStr: "http://www.google.com"
    property url myUrl: "http://www.google.com"

    Flow{
        flow: Flow.TopToBottom
        Text {
            id: dateTextId
            text: myDate
        }

        Text {
            id: dateText2Id
            text: Qt.formatDate(myDate,"yyyy-MMM-dd")
        }

        Text {
            id: str1Id
            text: myStr
        }

        Text {
            id: url1Id
            text: myUrl
        }
    }

    Rectangle{
        id: rectId
        color: "#d4d3f5"
        anchors.centerIn: parent
        width: text1.implicitWidth+10
        height: text1.implicitHeight+10

        Text {
            id: text1
            text: qsTr("Hello World")
            anchors.centerIn: parent
            font.pixelSize: 24
        }
    }
}

