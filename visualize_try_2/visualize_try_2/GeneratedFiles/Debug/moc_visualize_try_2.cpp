/****************************************************************************
** Meta object code from reading C++ file 'visualize_try_2.h'
**
** Created: Mon Nov 20 19:10:10 2017
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../visualize_try_2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualize_try_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_visualize_try_2[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_visualize_try_2[] = {
    "visualize_try_2\0"
};

const QMetaObject visualize_try_2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_visualize_try_2,
      qt_meta_data_visualize_try_2, 0 }
};

const QMetaObject *visualize_try_2::metaObject() const
{
    return &staticMetaObject;
}

void *visualize_try_2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_visualize_try_2))
	return static_cast<void*>(const_cast< visualize_try_2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int visualize_try_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
