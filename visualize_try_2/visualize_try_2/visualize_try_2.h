#ifndef VISUALIZE_TRY_2_H
#define VISUALIZE_TRY_2_H

#include <QtGui/QMainWindow>
#include "ui_visualize_try_2.h"

class visualize_try_2 : public QMainWindow
{
	Q_OBJECT

public:
	visualize_try_2(QWidget *parent = 0, Qt::WFlags flags = 0);
	~visualize_try_2();

private:
	Ui::visualize_try_2Class ui;
};

#endif // VISUALIZE_TRY_2_H
