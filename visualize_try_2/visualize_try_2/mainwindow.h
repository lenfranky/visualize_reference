#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMdiarea>
#include <QMdiSubWindow>

#include <QGLWidget>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();

	public slots:
		void slotExit();
		//void slot3DView();

signals:


private:
	QMenu *m_file_menu;
	QMenuBar *m_menu_bar;

	//bool m_draw;

};

#endif // MAINWINDOW_H