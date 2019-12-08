#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

class OpenGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit OpenGLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

private:
    GLfloat wx;
    GLfloat wy;
    GLfloat rx;
    GLfloat ry;
    bool rotate;

    void drawTopLeaf();
    void drawBottomLeaf();
    void drawLeftLeaf();
    void drawRightLeaf();
    void drawStem();
    void draw();
};

#endif // OPENGLWIDGET_H
