import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.15
/*Import Directory*/

import "./Component"

/*Import C++ Class*/

ApplicationWindow {
    id:root
    width: 1290
    height: 780
    visible: true
    title: qsTr("Hello World")
    flags: Qt.Window | Qt.FramelessWindowHint
    color: "transparent"

    /*  For Moveable Window */

    DragHandler{
        onActiveChanged: {
            if(active){
                root.startSystemMove()
            }
        }
        target: null
    }


    /*  For Quit Application*/

    Shortcut {
        sequence: gShortcuts.quite
        context: Qt.ApplicationShortcut
        onActivated: Qt.quit()
    }

    /*  For Maximaized Application*/

    Shortcut {
        sequence: gShortcuts.maximized
        context: Qt.ApplicationShortcut
        onActivated: root.showMaximized()
    }

    /*  For Initial Width and height Of Application*/

    Shortcut {
        sequence: gShortcuts.show
        context: Qt.ApplicationShortcut
        onActivated: root.show()
    }

    /*  For Minimized Application*/

    Shortcut {
        sequence: gShortcuts.minimized
        context: Qt.ApplicationShortcut
        onActivated: root.showMinimized()
    }

    property alias backgroundAcrylic: img

    /* Apply Background and Border for Main Window or Application*/

    background:Rectangle{
        id:backgroundInfo
        anchors.fill: parent
        border.width: 20
        radius: 8
        color: gSystemTheme.solidColor
        border.color: "#333"

        /* Apply Wallpaper In Main Window or Application*/

        Image{
            id:img
            anchors.margins: parent.border.width
            anchors.fill: parent
            source: gSystemTheme.wallpaper
        }
    }

    /* Left Area of Main Application*/


    /* upper left, lower left rounded corners */

    Acrylic{
        radius: 8
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: bottomHeader.top
        anchors.bottomMargin: 10
        width: parent.width /2
        height: 80
        source: backgroundAcrylic
        color: "#1e222a"

        ListView{
            id:appsView
            clip: true
            width: parent.width
            height: parent.height * 0.75
            anchors.verticalCenter: parent.verticalCenter
            model: gAppsModel
            spacing: 10
            orientation: ListView.Horizontal
            delegate:IconButton{
                clip: true
                implicitHeight: 60
                implicitWidth: 60
                roundIcon: true
                iconHeight: 50
                iconWidth: 50
                setIcon: iconUrl
            }
        }
    }


    Image{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: ( backgroundInfo.border.width - sourceSize.width ) / 2
        source: "qrc:/Icons/lence.svg"
        sourceSize: Qt.size(backgroundInfo.border.width-6,backgroundInfo.border.width-6)
    }

    Pane{
        id:topHeader
        padding: 0
        anchors.top: parent.top
        anchors.topMargin: backgroundInfo.border.width
        anchors.horizontalCenter: parent.horizontalCenter
        height: 35
        width: parent.width - backgroundInfo.border.width * 2
        background: Rectangle{
            color: "#1e222a"
            opacity: 0.8
            anchors.fill: parent
        }
        RowLayout{
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            RowLayout{
                spacing: 10
                IconButton{
                    implicitHeight: 30
                    implicitWidth: 30
                    Layout.leftMargin: 25
                    setIconSize : 16
                    setIconText: "👨‍💻"
                    iconBackground: "#414244"
                    iconBackgroundColor: "#FFFFFF"
                    iconBackgroundBorder: 1
                }

                Text {
                    text: "TechCoderHub"
                    color: "white"
                    font.pixelSize: 14
                }
            }

            Item{
                Layout.preferredWidth: 10
            }

            RowLayout{
                spacing: 5
                IconButton{
                    rotation: 90
                    implicitHeight: 24
                    implicitWidth: 18
                    setIconSize : 18
                    setIconText:"🔋" //"🪫" //"🔋"
                }
                Text {
                    text: "70%"
                    color: "white"
                    font.pixelSize: 14
                }
            }

            Item{
                Layout.preferredWidth: 10
            }

            RowLayout{
                spacing: 5
                Text {
                    text: "80"
                    color: "white"
                    font.pixelSize: 14
                }
                IconButton{
                    implicitHeight: 24
                    implicitWidth: 24
                    setIconSize : 16
                    setIconText: "🌿"
                }
            }

            Item{
                Layout.fillWidth: true
            }

            IconButton{
                implicitHeight: 32
                implicitWidth: 32
                roundIcon: true
                iconWidth: 16
                iconHeight: 16
                setIcon: "qrc:/Icons/Tesla Logo.svg"
                onClicked: headerPopup.open()
            }

            IconButton{
                implicitHeight: 32
                implicitWidth: 32
                roundIcon: true
                iconWidth: 28
                iconHeight: 28
                setIcon: "qrc:/Icons/bluetooth.svg"
            }

            Item{
                Layout.preferredWidth: 1
            }

            Text {
                text: "+18°C"
                color: "white"
                font.pixelSize: 14
            }

            Item{
                Layout.preferredWidth: 10
            }

            Text {
                text: "12:00 AM"
                color: "white"
                font.pixelSize: 14
                Layout.rightMargin: 30
            }
        }
    }



    Popup{
        id:headerPopup
        y: (backgroundInfo.border.width + topHeader.height + 5)
        x: width
        padding: 0
        width: 300
        height: 400
        background:Acrylic{
            radius: 8
            anchors.fill: parent
            source: backgroundAcrylic
            color: "#1e222a"
        }
        onOpened:{
            x = (parent.width - width - backgroundInfo.border.width - 5)
        }
        onClosed:{
            x = width
        }


        Behavior on x {
            NumberAnimation {
                //This specifies how long the animation takes
                duration: 600
                //This selects an easing curve to interpolate with, the default is Easing.Linear
                easing.type: Easing.OutBounce
            }
        }
    }

    Pane{
        id:bottomHeader
        padding: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: backgroundInfo.border.width
        anchors.horizontalCenter: parent.horizontalCenter
        height: 70
        width: parent.width - backgroundInfo.border.width * 2
        background: Rectangle{
            color: "#000000"
            anchors.fill: parent
        }
        RowLayout{
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            IconButton{
                Layout.leftMargin: 35
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/model3-icon.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/defrost.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/heater.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/seat.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 55
                iconHeight: 55
                setIcon: "qrc:/Icons/Driver Temp.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/fan.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 55
                iconHeight: 55
                setIcon: "qrc:/Icons/Driver Temp.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                isMirror:true
                setIcon: "qrc:/Icons/seat.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/music.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/phone.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 32
                iconHeight: 32
                setIcon: "qrc:/Icons/volume.svg"
            }
            IconButton{
                roundIcon: true
                iconWidth: 42
                iconHeight: 42
                setIcon: "qrc:/Icons/brightness.svg"
            }
        }
    }
}
