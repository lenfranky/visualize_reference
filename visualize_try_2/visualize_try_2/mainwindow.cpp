#include "mainwindow.h"

#include <QCoreApplication>
#include <QGridLayout>
#include <QDockWidget>

MainWindow::MainWindow()
{
	setWindowTitle(tr("MainWindow"));
	setMinimumSize(1366, 900);

	m_menu_bar = new QMenuBar(this);
	setMenuBar(m_menu_bar);

	m_file_menu = new QMenu(tr("&File"));
	m_menu_bar->addMenu(m_file_menu);
	QAction *exitAction = new QAction(tr("Exit"), this);
	exitAction->setStatusTip(tr("Exit"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(slotExit()));
	m_file_menu->addAction(exitAction);

	QAction *file_open_action = new QAction(tr("open"), this);
	file_open_action->setToolTip(tr("open_2"));
	//connect(exitAction, SIGNAL(triggered()), this, SLOT(slotExit()));
	m_file_menu->addAction(file_open_action);

}

MainWindow::~MainWindow()
{

}

void MainWindow::slotExit()
{
	qApp->exit();
}

