#include "openglwidget.h"
#include "renderer.h"

#include <GL/gl.h>
#include <GL/glu.h>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    return;
}

void OpenGLWidget::initializeGL()
{
    qglClearColor(Qt::white);
}

void OpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);

    draw();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    int side = qMin(w, h);
    glViewport((w - h) / 2, (h - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1, 15);
#else
    glOrtho(-2, +2, -2, +2, 1, 15);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLWidget::draw()
{
    qglColor(Qt::black);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
        glVertex3d(-1, -1, 0);
        glVertex3d(+1, -1, 0);
        glVertex3d(0, 1, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3d(-0.5, 0, 0);
        glVertex3d(+0.5, 0, 0);
        glVertex3d(0, -1, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3d(-0.25, -0.5, 0);
        glVertex3d(+0.25, -0.5, 0);
        glVertex3d(0, 0, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3d(-0.125, -0.25, 0);
        glVertex3d(+0.125, -0.25, 0);
        glVertex3d(0, -0.5, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3d(-0.0625, -0.375, 0);
        glVertex3d(+0.0625, -0.375, 0);
        glVertex3d(0, -0.25, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex3d(-0.03125, -0.3125, 0);
        glVertex3d(+0.03125, -0.3125, 0);
        glVertex3d(0, -0.375, 0);
    glEnd();
}
