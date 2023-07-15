import QtQuick
import QtQuick.Controls

import mbpe4

SplitView {
    id: verticalSplitView
    orientation: Qt.Vertical
    anchors.fill: parent

    handle: Rectangle {
        id: verticalHandleDelegate
        implicitWidth: 8
        implicitHeight: 8
        color: SplitHandle.pressed ? "#000000"
            : (SplitHandle.hovered ? Qt.lighter("#555555", 1.1) : "#999999")
    }

    Item {
        SplitView.preferredHeight: parent.height * 0.8

        SplitView {
            id: horizontalSplitView
            anchors.fill: parent
            orientation: Qt.Horizontal

            handle: Rectangle {
                id: horizontalHandleDelegate
                implicitWidth: 8
                implicitHeight: 8
                color: SplitHandle.pressed ? "#000000"
                    : (SplitHandle.hovered ? Qt.lighter("#555555", 1.1) : "#999999")
            }

            Item {
                SplitView.preferredWidth: parent.width * 0.2
            }

            Item {
                SplitView.fillWidth: true
                SplitView.preferredWidth: parent.width * 0.6
            }

            Item {
                SplitView.preferredWidth: parent.width * 0.2
            }
        }
    }

    Item {
        SplitView.preferredHeight: parent.height * 0.2
    }
}
