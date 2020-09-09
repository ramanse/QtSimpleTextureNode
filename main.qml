import QtQuick 2.12
import QtQuick.Window 2.12
import DisplayWindow 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ShaderEffectSource {
        id: displayWindowSource
        z: -1
        sourceItem: Image {
            //Use file://<AbsolutePath>
            source: "./404.png"
        }
        hideSource: true
    }
    DisplayWindow {
        id: displayWindow
        anchors.fill: parent
        anchors.margins: 30
        source: displayWindowSource
    }
    Rectangle{
        id: test
        width: 200
        height: 100
        color: "green"
    }


}
