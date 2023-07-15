#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include <QObject>
#include <QQmlEngine>
#include <QByteArray>

class EditorState : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

    Q_PROPERTY(int canvasHeight READ canvasHeight WRITE setCanvasHeight NOTIFY canvasHeightChanged)
    Q_PROPERTY(int canvasWidth READ canvasWidth WRITE setCanvasWidth NOTIFY canvasWidthChanged)

public:
    explicit EditorState(QObject *parent = nullptr);

    int canvasWidth() const;
    int canvasHeight() const;

    bool canvasExists() const;

    void setCanvasWidth(int width);
    void setCanvasHeight(int height);

public slots:
    /// Initialize the canvas with the dimensions `canvasWidth` x `canvasHeight`.
    /// Returns true when successful.
    bool initializeCanvas();

signals:
    void canvasWidthChanged();
    void canvasHeightChanged();

private:
    /// Canvas Width (pixels). Any value < 0 means that it has not been set.
    int m_canvasWidth = -1;

    /// Canvas Height (pixels). Any value < 0 means that it has not been set.
    int m_canvasHeight = -1;

    /// Canvas as a QByteArray of size m_canvasWidth * m_canvasHeight * 4 (RGBA)
    QByteArray canvas = QByteArray();
};

#endif // EDITORSTATE_H
