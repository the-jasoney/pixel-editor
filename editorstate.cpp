#include "editorstate.h"
#include <QDebug>

// getters
int EditorState::canvasHeight() const {
    return m_canvasHeight;
}

int EditorState::canvasWidth() const {
    return m_canvasWidth;
}

bool EditorState::canvasExists() const {
    return !m_canvas.isEmpty();
}

QByteArray EditorState::canvas() const {
    return m_canvas;
}

float EditorState::zoom() const {
    return m_zoom;
}

float EditorState::zoomX() const {
    return m_zoomX;
}

float EditorState::zoomY() const {
    return m_zoomY;
}

// setters
void EditorState::setCanvasHeight(int canvasHeight) {
    if (canvasHeight != m_canvasHeight) {
        m_canvasHeight = canvasHeight;
        emit canvasHeightChanged();
    }
}

void EditorState::setCanvasWidth(int canvasWidth) {
    if (canvasWidth != m_canvasWidth) {
        m_canvasWidth = canvasWidth;
        emit canvasWidthChanged();
    }
}

void EditorState::setZoom(float zoom) {
    if (zoom != m_zoom) {
        m_zoom = zoom;
        emit zoomChanged();
    }
}

void EditorState::setZoomX(float zoomX) {
    if (zoomX != m_zoomX) {
        m_zoomX = zoomX;
        emit zoomXChanged();
    }
}

void EditorState::setZoomY(float zoomY) {
    if (zoomY != m_zoomY) {
        m_zoomY = zoomY;
        emit zoomYChanged();
    }
}

// methods
bool EditorState::initializeCanvas() {
    bool previousExists = m_canvas.isEmpty();
    QByteArray previousCanvas = m_canvas;

    if (m_canvasWidth > 0 && m_canvasHeight > 0)
        // initialize new blank
        m_canvas.resize(m_canvasHeight * m_canvasWidth * 4);

    if (previousExists != m_canvas.isEmpty())
        emit canvasExistsChanged();

    if (previousCanvas != m_canvas)
        emit canvasChanged();

    return m_canvas.isEmpty();
}

QByteArray EditorState::setPixel(int x, int y, int r, int g, int b, int a) {
    if (canvasExists()) {
        int index = (x + y * m_canvasWidth) * 4;
        m_canvas[index] = r;
        m_canvas[index + 1] = g;
        m_canvas[index + 2] = b;
        m_canvas[index + 3] = a;

        emit canvasChanged();
    }

    return m_canvas;
}
