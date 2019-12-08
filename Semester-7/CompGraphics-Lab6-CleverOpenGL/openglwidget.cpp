#include "openglwidget.h"

#include <QMouseEvent>

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    return;
}

void OpenGLWidget::initializeGL()
{

}

void OpenGLWidget::paintGL()
{
    qglClearColor(Qt::darkGreen);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHTING);
    GLfloat position[] = { 50.0, 50.0, -50.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0);

    glLoadIdentity();
    glTranslatef(0, 0, -10);

    glViewport(0, 0, this->width(), this->height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, this->width() / this->height(), 3, 8);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -5);

    glEnable(GL_LIGHTING);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glScalef(0.2f, 0.2f, 0.2f);
    glRotatef(rx, 0, 1, 0);
    glRotatef(ry, 1, 0, 0);

    draw();
}

void OpenGLWidget::resizeGL(int w, int h)
{
    int side = qMin(w, h);
    glViewport((w - h) / 2, (h - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, +2, -2, +2, 1, 15);
}

void OpenGLWidget::mousePressEvent(QMouseEvent *e)
{
    this->wx = e->x();
    this->wy = e->y();
    rotate = true;
}

void OpenGLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    rotate = false;
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent *e)
{
    if (rotate) {
        rx += (e->x() - wx) / 2;
        ry += (e->y() - wy) / 2;
        wx = e->x();
        wy = e->y();

        InvalidateRect((HWND) QWidget::winId(), nullptr, false);
    }
}

void OpenGLWidget::drawTopLeaf()
{
    GLUnurbs *nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, GLU_FILL);

    GLfloat uknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    GLfloat vknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };

    GLfloat controlPoints[4][4][3] = {
        {
            {0, 1, 0},
            {3, 1, 3},
            {2, 1, 5},
            {0, 1, 3},
        },
        {
            {0, 1, 0},
            {1, 1, 2},
            {2, 1, 2},
            {0, 1, 3},
        },
        {
            {0, 1, 0},
            {-1, 1, 2},
            {-2, 1, 2},
            {0, 1, 3},
        },
        {
            {0, 1, 0},
            {-3, 1, 3},
            {-2, 1, 5},
            {0, 1, 3},
        }
    };

    qglColor(Qt::green);

    gluBeginSurface(nurb);
    gluNurbsSurface(nurb, 8, uknots, 8, vknots, 4 * 3, 3, &controlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurb);
    glDisable(GL_BLEND);
}

void OpenGLWidget::drawBottomLeaf()
{
    GLUnurbs *nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, GLU_FILL);

    GLfloat uknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    GLfloat vknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };

    GLfloat controlPoints[4][4][3] = {
        {
            {0, 1, 0},
            {3, 1, -3},
            {2, 1, -5},
            {0, 1, -3},
        },
        {
            {0, 1, 0},
            {1, 1, -2},
            {2, 1, -2},
            {0, 1, -3},
        },
        {
            {0, 1, 0},
            {-1, 1, -2},
            {-2, 1, -2},
            {0, 1, -3},
        },
        {
            {0, 1, 0},
            {-3, 1, -3},
            {-2, 1, -5},
            {0, 1, -3},
        }
    };

    qglColor(Qt::green);

    gluBeginSurface(nurb);
    gluNurbsSurface(nurb, 8, uknots, 8, vknots, 4 * 3, 3, &controlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurb);
    glDisable(GL_BLEND);
}

void OpenGLWidget::drawLeftLeaf()
{
    GLUnurbs *nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, GLU_FILL);

    GLfloat uknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    GLfloat vknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };

    GLfloat controlPoints[4][4][3] = {
        {
            {0, 1, 0},
            {-3, 1, 3},
            {-5, 1, 2},
            {-3, 1, 0},
        },
        {
            {0, 1, 0},
            {-2, 1, 1},
            {-2, 1, 2},
            {-3, 1, 0},
        },
        {
            {0, 1, 0},
            {-2, 1, -1},
            {-2, 1, -2},
            {-3, 1, 0},
        },
        {
            {0, 1, 0},
            {-3, 1, -3},
            {-5, 1, -2},
            {-3, 1, 0},
        }
    };

    qglColor(Qt::green);

    gluBeginSurface(nurb);
    gluNurbsSurface(nurb, 8, uknots, 8, vknots, 4 * 3, 3, &controlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurb);
    glDisable(GL_BLEND);
}

void OpenGLWidget::drawRightLeaf()
{
    GLUnurbs *nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, GLU_FILL);

    GLfloat uknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };
    GLfloat vknots[8] = { 0, 0, 0, 0, 1, 1, 1, 1 };

    GLfloat controlPoints[4][4][3] = {
        {
            {0, 1, 0},
            {3, 1, 3},
            {5, 1, 2},
            {3, 1, 0},
        },
        {
            {0, 1, 0},
            {2, 1, 1},
            {2, 1, 2},
            {3, 1, 0},
        },
        {
            {0, 1, 0},
            {2, 1, -1},
            {2, 1, -2},
            {3, 1, 0},
        },
        {
            {0, 1, 0},
            {3, 1, -3},
            {5, 1, -2},
            {3, 1, 0},
        }
    };

    qglColor(Qt::green);

    gluBeginSurface(nurb);
    gluNurbsSurface(nurb, 8, uknots, 8, vknots, 4 * 3, 3, &controlPoints[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurb);
    glDisable(GL_BLEND);
}

void OpenGLWidget::drawStem()
{
    GLUquadric *quadObj = gluNewQuadric();
    gluQuadricDrawStyle(quadObj, GLU_FILL);
    gluQuadricTexture(quadObj, GL_TRUE);

    qglColor(Qt::green);
    glRotated(90, 1, 0, 0);
    glTranslated(0, 0, -1);
    gluCylinder(quadObj, 0.1, 0.1, 7, 30, 30);
}

void OpenGLWidget::draw()
{
    drawTopLeaf();
    drawBottomLeaf();
    drawLeftLeaf();
    drawRightLeaf();
    drawStem();
}
