#include "editorstate.h"

EditorState::EditorState(QObject *parent)
    : QObject{parent}
{

}

int EditorState::canvasHeight() const {
    return m_canvasHeight;
}

int EditorState::canvasWidth() const {
    return m_canvasWidth;
}

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

bool EditorState::initializeCanvas() {
    if (m_canvasWidth > 0 && m_canvasHeight > 0) {
        // initialize new blank
        canvas.resize(m_canvasHeight * m_canvasWidth * 4);
    }

    return canvas.isEmpty();
}

bool EditorState::canvasExists() const {
    return canvas.isEmpty();
}
