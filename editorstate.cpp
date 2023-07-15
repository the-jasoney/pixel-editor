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
