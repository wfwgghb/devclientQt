/****************************************************************************
** Meta object code from reading C++ file 'loghandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpclientGui/loghandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loghandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogHandler_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogHandler_t qt_meta_stringdata_LogHandler = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LogHandler"
QT_MOC_LITERAL(1, 11, 17), // "SqlfinishedSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "Initial"
QT_MOC_LITERAL(4, 38, 11), // "onLogSignal"
QT_MOC_LITERAL(5, 50, 7), // "olddata"
QT_MOC_LITERAL(6, 58, 12), // "UsernameSlot"
QT_MOC_LITERAL(7, 71, 8) // "userName"

    },
    "LogHandler\0SqlfinishedSignal\0\0Initial\0"
    "onLogSignal\0olddata\0UsernameSlot\0"
    "userName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void LogHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LogHandler *_t = static_cast<LogHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SqlfinishedSignal(); break;
        case 1: _t->Initial(); break;
        case 2: _t->onLogSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->UsernameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LogHandler::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LogHandler::SqlfinishedSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject LogHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LogHandler.data,
      qt_meta_data_LogHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LogHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LogHandler.stringdata0))
        return static_cast<void*>(const_cast< LogHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int LogHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LogHandler::SqlfinishedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
