#ifndef C3DQGLWIDGET_H
#define C3DQGLWIDGET_H

#include <QGLWidget>
#include <windows.h>
#include <stdio.h>
#include <glut.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>
#include <QColor>

class C3DQGLWidget : public QGLWidget
{
	Q_OBJECT

public:
	C3DQGLWidget(QWidget *parent);
	~C3DQGLWidget();
	
};


#endif // C3DQGLWIDGET_H
