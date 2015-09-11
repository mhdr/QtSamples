import QtQuick 2.5
import QtQuick.Controls 1.4

Row{
    id : rootId
    property int textFieldWidth: 100

    Label{
        id:labelId
        text: qsTr("Label")
    }

    TextField{
        id:textFieldId
        width: textFieldWidth
    }
}

