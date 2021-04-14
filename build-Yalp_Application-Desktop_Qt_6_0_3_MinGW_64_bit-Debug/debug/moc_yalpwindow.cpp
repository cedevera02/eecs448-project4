/****************************************************************************
** Meta object code from reading C++ file 'yalpwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Yalp_Application/yalpwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'yalpwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_YalpWindow_t {
    const uint offsetsAndSize[26];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_YalpWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_YalpWindow_t qt_meta_stringdata_YalpWindow = {
    {
QT_MOC_LITERAL(0, 10), // "YalpWindow"
QT_MOC_LITERAL(11, 17), // "on_Min1RB_clicked"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 17), // "on_Min2RB_clicked"
QT_MOC_LITERAL(48, 17), // "on_Min3RB_clicked"
QT_MOC_LITERAL(66, 17), // "on_Max1RB_clicked"
QT_MOC_LITERAL(84, 17), // "on_Max2RB_clicked"
QT_MOC_LITERAL(102, 17), // "on_Max3RB_clicked"
QT_MOC_LITERAL(120, 29), // "on_searchFilterButton_clicked"
QT_MOC_LITERAL(150, 28), // "on_publicRRadioButtn_clicked"
QT_MOC_LITERAL(179, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(204, 32), // "on_cusineTypeLineEdit_textEdited"
QT_MOC_LITERAL(237, 4) // "arg1"

    },
    "YalpWindow\0on_Min1RB_clicked\0\0"
    "on_Min2RB_clicked\0on_Min3RB_clicked\0"
    "on_Max1RB_clicked\0on_Max2RB_clicked\0"
    "on_Max3RB_clicked\0on_searchFilterButton_clicked\0"
    "on_publicRRadioButtn_clicked\0"
    "on_radioButton_2_clicked\0"
    "on_cusineTypeLineEdit_textEdited\0arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_YalpWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x08,    0 /* Private */,
       3,    0,   75,    2, 0x08,    1 /* Private */,
       4,    0,   76,    2, 0x08,    2 /* Private */,
       5,    0,   77,    2, 0x08,    3 /* Private */,
       6,    0,   78,    2, 0x08,    4 /* Private */,
       7,    0,   79,    2, 0x08,    5 /* Private */,
       8,    0,   80,    2, 0x08,    6 /* Private */,
       9,    0,   81,    2, 0x08,    7 /* Private */,
      10,    0,   82,    2, 0x08,    8 /* Private */,
      11,    1,   83,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void YalpWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<YalpWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Min1RB_clicked(); break;
        case 1: _t->on_Min2RB_clicked(); break;
        case 2: _t->on_Min3RB_clicked(); break;
        case 3: _t->on_Max1RB_clicked(); break;
        case 4: _t->on_Max2RB_clicked(); break;
        case 5: _t->on_Max3RB_clicked(); break;
        case 6: _t->on_searchFilterButton_clicked(); break;
        case 7: _t->on_publicRRadioButtn_clicked(); break;
        case 8: _t->on_radioButton_2_clicked(); break;
        case 9: _t->on_cusineTypeLineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject YalpWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_YalpWindow.offsetsAndSize,
    qt_meta_data_YalpWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_YalpWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *YalpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *YalpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_YalpWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int YalpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
