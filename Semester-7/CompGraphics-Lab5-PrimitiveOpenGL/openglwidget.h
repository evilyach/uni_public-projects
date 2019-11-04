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

private:
    void draw();
};

#endif // OPENGLWIDGET_H
