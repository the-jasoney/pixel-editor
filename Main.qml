import QtQuick
import QtQuick.Window

Window {
    width: 1920
    height: 1080
    visible: true
    visibility: "FullScreen"

    title: qsTr("Hello World")

    Editor { anchors.fill: parent }
}
