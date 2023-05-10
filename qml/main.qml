import QtQuick
import QtQuick.Controls

import AsciiArt

Window {
    width: 640
    height: 480
    visible: true
    title: "generate some ascii-art"

    Rectangle {
        x: 10
        y: 10

        width: Math.max(inputField.width, 50) + 4
        height: inputField.height + 4

        border.color: "black"
        border.width: 1

        TextInput {
            id: inputField

            x: 2
            y: 2

            font.family: "source code pro"

            text: "-- your text here --"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: inputField.focus = true
        }
    }

    TextArea {
        x: 10
        y: 30

        font.family: "source code pro"
        readOnly: true

        text: Backend.generateAsciiArt(inputField.text)
    }
}
