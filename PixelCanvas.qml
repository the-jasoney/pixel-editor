import QtQuick
import mbpe4

Canvas {
    id: pixelCanvas
    width: parent.width
    height: parent.height

    // 1 for in
    // 0 for none
    // -1 for out
    property int zoomMode: 0;

    onPaint: {
        let ctx = getContext('2d');
        let zoom = EditorState.zoom;
        let x = EditorState.zoomX;
        let y = EditorState.zoomY;

        ctx.reset(0, 0, width, height);

        let t = ctx.transform(1, 0, 0, 0, 1, 0);
        ctx.resetTransform();
        if (zoomMode > 0) ctx.translate(x, y);
        ctx.scale(zoom, zoom);
        if (zoomMode > 0) ctx.translate(-x, -y)
        ctx.transform(t.a, t.b, t.c, t.d, t.e, t.f);
        console.log(`${t}: [${t.a} ${t.b} ${t.c}; ${t.d} ${t.e} ${t.f}; 0 0 1`)

        ctx.fillStyle = Qt.rgba(1, 0, 0, 1);
        ctx.fillRect(0, 0, 10, 10);
    }

    Connections {
        target: EditorState

        function onZoomChanged() {
            requestPaint();
        }
    }

    WheelHandler {
        onWheel:
            (wheel) => {
                zoomMode = (wheel.angleDelta.y > 0 ? 1 : -1);

                var newValue = EditorState.zoom + zoomMode;

                if (newValue <= 0)
                    return;

                EditorState.zoom = newValue;
                EditorState.zoomX = wheel.x;
                EditorState.zoomY = wheel.y;
            }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent

    }
}
