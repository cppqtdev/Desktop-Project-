import QtQuick 2.12
import QtGraphicalEffects 1.15

Item {
    id: acrylicRoot

    property alias color: rect.color
    property real radius: 0
    property alias acrylicOpacity: rect.opacity
    property var source: acrylicRoot
    clip: true
    Rectangle {
        id: rect
        color: "#1e222a"
        opacity: 0.9
        border.width: 1
        border.color : "gray"
        radius: parent.radius
        anchors.centerIn: parent
        anchors.fill: parent
    }

//    ShaderEffectSource {
//        id: ses
//        clip: true
//        sourceItem : parent.source
//        anchors.centerIn: rect
//        width: rect.width
//        height: rect.height
//        sourceRect: Qt.rect(x, y, width, height)
//    }

//    GaussianBlur {
//        clip: true
//        source: ses
//        anchors.fill: ses
//        radius: 64
//        samples: 1 + radius * 2 // as per Qt docs
//    }
}
