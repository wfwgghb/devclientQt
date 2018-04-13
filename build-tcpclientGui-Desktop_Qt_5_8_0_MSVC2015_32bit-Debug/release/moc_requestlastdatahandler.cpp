/****************************************************************************
** Meta object code from reading C++ file 'requestlastdatahandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpclientGui/requestlastdatahandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'requestlastdatahandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_requestLastDataHandler_t {
    QByteArrayData data[22];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_requestLastDataHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_requestLastDataHandler_t qt_meta_stringdata_requestLastDataHandler = {
    {
QT_MOC_LITERAL(0, 0, 22), // "requestLastDataHandler"
QT_MOC_LITERAL(1, 23, 18), // "ErrorHandlerSignal"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "errorno"
QT_MOC_LITERAL(4, 51, 18), // "LastDataSendSignal"
QT_MOC_LITERAL(5, 70, 3), // "str"
QT_MOC_LITERAL(6, 74, 16), // "HttpClientSignal"
QT_MOC_LITERAL(7, 91, 10), // "byte_array"
QT_MOC_LITERAL(8, 102, 18), // "Send2DevhttpSignal"
QT_MOC_LITERAL(9, 121, 3), // "cmd"
QT_MOC_LITERAL(10, 125, 6), // "dev_id"
QT_MOC_LITERAL(11, 132, 12), // "finishedSlot"
QT_MOC_LITERAL(12, 145, 14), // "QNetworkReply*"
QT_MOC_LITERAL(13, 160, 5), // "reply"
QT_MOC_LITERAL(14, 166, 7), // "Initial"
QT_MOC_LITERAL(15, 174, 12), // "TimeoutSlot2"
QT_MOC_LITERAL(16, 187, 12), // "TimeoutSlot3"
QT_MOC_LITERAL(17, 200, 18), // "onMsgForHttpSignal"
QT_MOC_LITERAL(18, 219, 4), // "temp"
QT_MOC_LITERAL(19, 224, 18), // "DevattrChangedSlot"
QT_MOC_LITERAL(20, 243, 16), // "onsendParaSignal"
QT_MOC_LITERAL(21, 260, 3) // "msg"

    },
    "requestLastDataHandler\0ErrorHandlerSignal\0"
    "\0errorno\0LastDataSendSignal\0str\0"
    "HttpClientSignal\0byte_array\0"
    "Send2DevhttpSignal\0cmd\0dev_id\0"
    "finishedSlot\0QNetworkReply*\0reply\0"
    "Initial\0TimeoutSlot2\0TimeoutSlot3\0"
    "onMsgForHttpSignal\0temp\0DevattrChangedSlot\0"
    "onsendParaSignal\0msg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_requestLastDataHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       8,    2,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   83,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,
      16,    0,   88,    2, 0x0a /* Public */,
      17,    1,   89,    2, 0x0a /* Public */,
      19,    0,   92,    2, 0x0a /* Public */,
      20,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,

       0        // eod
};

void requestLastDataHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        requestLastDataHandler *_t = static_cast<requestLastDataHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ErrorHandlerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->LastDataSendSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->HttpClientSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->Send2DevhttpSignal((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->Initial(); break;
        case 6: _t->TimeoutSlot2(); break;
        case 7: _t->TimeoutSlot3(); break;
        case 8: _t->onMsgForHttpSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->DevattrChangedSlot(); break;
        case 10: _t->onsendParaSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (requestLastDataHandler::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&requestLastDataHandler::ErrorHandlerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (requestLastDataHandler::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&requestLastDataHandler::LastDataSendSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (requestLastDataHandler::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&requestLastDataHandler::HttpClientSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (requestLastDataHandler::*_t)(QByteArray , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&requestLastDataHandler::Send2DevhttpSignal)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject requestLastDataHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_requestLastDataHandler.data,
      qt_meta_data_requestLastDataHandler,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *requestLastDataHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *requestLastDataHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_requestLastDataHandler.stringdata0))
        return static_cast<void*>(const_cast< requestLastDataHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int requestLastDataHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void requestLastDataHandler::ErrorHandlerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void requestLastDataHandler::LastDataSendSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void requestLastDataHandler::HttpClientSignal(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void requestLastDataHandler::Send2DevhttpSignal(QByteArray _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
