#include "openglwidget.h"

#include <QDir>
#include <QDebug>
#include <QException>
#include <QMessageBox>
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
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

    load_texture("TallGreenGrass.bmp", 0, 1);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    float planes[] = { 0.5f, 0.0f, 0.0f, 0.5f };
    float planet[] = { 0.0f, 0.5f, 0.0f, 0.5f };
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGenfv(GL_S, GL_OBJECT_LINEAR, planes);
    glTexGenfv(GL_T, GL_OBJECT_LINEAR, planet);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, TEXTURE_SIDE * 2, TEXTURE_SIDE * 2, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, &texture[0]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
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


#include <stdlib.h>
#include <vector>
#include <fstream>

#include <QDataStream>


void OpenGLWidget::load_texture(const char *filename, int j, int alpha)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        exit(-1);
    }

    QDataStream *stream = new QDataStream(&file);

    unsigned long size = file.size() - 54;

    stream->readRawData(nullptr, 54);

    for (unsigned long i = 0; i < size / 3 - 1; i++) {
        *stream >> texture[j].r[i];
        *stream >> texture[j].g[i];
        *stream >> texture[j].b[i];
        texture[j].a[i] = alpha;
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
}
