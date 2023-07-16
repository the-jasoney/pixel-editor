#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include <QObject>
#include <QQmlEngine>
#include <QByteArray>
#include <QVariantList>

class EditorState : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

    Q_PROPERTY(int canvasHeight READ canvasHeight WRITE setCanvasHeight NOTIFY canvasHeightChanged)
    Q_PROPERTY(int canvasWidth READ canvasWidth WRITE setCanvasWidth NOTIFY canvasWidthChanged)
    Q_PROPERTY(bool canvasExists READ canvasExists NOTIFY canvasExistsChanged)
    Q_PROPERTY(QByteArray canvas READ canvas NOTIFY canvasChanged)
    Q_PROPERTY(float zoom READ zoom WRITE setZoom NOTIFY zoomChanged)
    Q_PROPERTY(float zoomX READ zoomX WRITE setZoomX NOTIFY zoomXChanged)
    Q_PROPERTY(float zoomY READ zoomY WRITE setZoomY NOTIFY zoomYChanged FINAL)

public:
    explicit EditorState(QObject *parent = nullptr) {};

    // -- getters --
    /// Canvas width
    int canvasWidth() const;

    /// Canvas height
    int canvasHeight() const;

    /// Whether or not the canvas exists
    bool canvasExists() const;

    /// The canvas
    QByteArray canvas() const;

    /// The zoom value
    float zoom() const;

    /// The zoom X value
    float zoomX() const;

    /// The zoom Y value
    float zoomY() const;

    // -- setters --
    /// Canvas width
    void setCanvasWidth(int width);

    /// Canvas height
    void setCanvasHeight(int height);

    /// Canvas zoom
    void setZoom(float zoom);

    /// Zoom X
    void setZoomX(float zoomX);

    /// Zoom Y
    void setZoomY(float zoomY);

public slots: // methods
    /// Initialize the canvas with the dimensions `canvasWidth` x `canvasHeight`.
    /// Returns true when successful.
    bool initializeCanvas();

    /// Set a pixel.
    /// Returns true when successful
    QByteArray setPixel(int x, int y, int r, int g, int b, int a);

signals:
    void canvasWidthChanged();
    void canvasHeightChanged();
    void canvasExistsChanged();
    void canvasChanged();
    void zoomChanged();
    void zoomXChanged();
    void zoomYChanged();

private:
    /// Canvas Width (pixels). Any value < 0 means that it has not been set.
    int m_canvasWidth = -1;

    /// Canvas Height (pixels). Any value < 0 means that it has not been set.
    int m_canvasHeight = -1;

    /// Canvas Zoom Value
    float m_zoom = 1.0F;

    /// Canvas Zoom X
    float m_zoomX = 0.0F;

    /// Canvas Zoom Y
    float m_zoomY = 0.0F;

    /// Canvas as a QByteArray of size m_canvasWidth * m_canvasHeight * 4 (RGBA)
    QByteArray m_canvas = QByteArray();
};

#endif // EDITORSTATE_H
