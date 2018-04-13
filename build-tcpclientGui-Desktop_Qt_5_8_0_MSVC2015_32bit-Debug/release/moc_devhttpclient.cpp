/****************************************************************************
** Meta object code from reading C++ file 'devhttpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpclientGui/devhttpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devhttpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DevHttpClient_t {
    QByteArrayData data[20];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DevHttpClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DevHttpClient_t qt_meta_stringdata_DevHttpClient = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DevHttpClient"
QT_MOC_LITERAL(1, 14, 18), // "ErrorHandlerSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "errorno"
QT_MOC_LITERAL(4, 42, 18), // "LastDataSendSignal"
QT_MOC_LITERAL(5, 61, 3), // "str"
QT_MOC_LITERAL(6, 65, 16), // "HttpClientSignal"
QT_MOC_LITERAL(7, 82, 10), // "byte_array"
QT_MOC_LITERAL(8, 93, 12), // "finishedSlot"
QT_MOC_LITERAL(9, 106, 14), // "QNetworkReply*"
QT_MOC_LITERAL(10, 121, 5), // "reply"
QT_MOC_LITERAL(11, 127, 7), // "Initial"
QT_MOC_LITERAL(12, 135, 12), // "TimeoutSlot2"
QT_MOC_LITERAL(13, 148, 18), // "onMsgForHttpSignal"
QT_MOC_LITERAL(14, 167, 4), // "temp"
QT_MOC_LITERAL(15, 172, 12), // "RTCtimerSlot"
QT_MOC_LITERAL(16, 185, 16), // "onsendParaSignal"
QT_MOC_LITERAL(17, 202, 3), // "msg"
QT_MOC_LITERAL(18, 206, 20), // "onSend2DevhttpSignal"
QT_MOC_LITERAL(19, 227, 5) // "devid"

    },
    "DevHttpClient\0ErrorHandlerSignal\0\0"
    "errorno\0LastDataSendSignal\0str\0"
    "HttpClientSignal\0byte_array\0finishedSlot\0"
    "QNetworkReply*\0reply\0Initial\0TimeoutSlot2\0"
    "onMsgForHttpSignal\0temp\0RTCtimerSlot\0"
    "onsendParaSignal\0msg\0onSend2DevhttpSignal\0"
    "devid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevHttpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   73,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    0,   77,    2, 0x0a /* Public */,
      13,    1,   78,    2, 0x0a /* Public */,
      15,    0,   81,    2, 0x0a /* Public */,
      16,    1,   82,    2, 0x0a /* Public */,
      18,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    5,   19,

       0        // eod
};

void DevHttpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DevHttpClient *_t = static_cast<DevHttpClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ErrorHandlerSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->LastDataSendSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->HttpClientSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 4: _t->Initial(); break;
        case 5: _t->TimeoutSlot2(); break;
        case 6: _t->onMsgForHttpSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->RTCtimerSlot(); break;
        case 8: _t->onsendParaSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onSend2DevhttpSignal((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            typedef void (DevHttpClient::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DevHttpClient::ErrorHandlerSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DevHttpClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DevHttpClient::LastDataSendSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DevHttpClient::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DevHttpClient::HttpClientSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject DevHttpClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DevHttpClient.data,
      qt_meta_data_DevHttpClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DevHttpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DevHttpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DevHttpClient.stringdata0))
        return static_cast<void*>(const_cast< DevHttpClient*>(this));
    return QObject::qt_metacast(_clname);
}

int DevHttpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DevHttpClient::ErrorHandlerSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DevHttpClient::LastDataSendSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DevHttpClient::HttpClientSignal(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
