#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

#include <GL/gl.h>
#include <GL/glu.h>

#define TEXTURE_SIDE 261

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

    void load_texture(const char *filename, int j, int alpha);

    struct Texture {
        byte b[TEXTURE_SIDE * TEXTURE_SIDE * 4];
        byte g[TEXTURE_SIDE * TEXTURE_SIDE * 4];
        byte r[TEXTURE_SIDE * TEXTURE_SIDE * 4];
        byte a[TEXTURE_SIDE * TEXTURE_SIDE * 4];
    };
    typedef struct Texture texture_t;

    texture_t texture[3];
};

#endif // OPENGLWIDGET_H
