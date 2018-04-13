/****************************************************************************
** Meta object code from reading C++ file 'devhttpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpclientGui/devhttpclient.h"
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
    QByteArrayData data[23];
    char stringdata0[271];
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
QT_MOC_LITERAL(8, 93, 17), // "httpConnectSignal"
QT_MOC_LITERAL(9, 111, 3), // "msg"
QT_MOC_LITERAL(10, 115, 12), // "finishedSlot"
QT_MOC_LITERAL(11, 128, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 143, 5), // "reply"
QT_MOC_LITERAL(13, 149, 7), // "Initial"
QT_MOC_LITERAL(14, 157, 12), // "TimeoutSlot2"
QT_MOC_LITERAL(15, 170, 18), // "onMsgForHttpSignal"
QT_MOC_LITERAL(16, 189, 4), // "temp"
QT_MOC_LITERAL(17, 194, 12), // "RTCtimerSlot"
QT_MOC_LITERAL(18, 207, 16), // "onsendParaSignal"
QT_MOC_LITERAL(19, 224, 15), // "onsendrtcSignal"
QT_MOC_LITERAL(20, 240, 5), // "devid"
QT_MOC_LITERAL(21, 246, 3), // "rtc"
QT_MOC_LITERAL(22, 250, 20) // "onSend2DevhttpSignal"

    },
    "DevHttpClient\0ErrorHandlerSignal\0\0"
    "errorno\0LastDataSendSignal\0str\0"
    "HttpClientSignal\0byte_array\0"
    "httpConnectSignal\0msg\0finishedSlot\0"
    "QNetworkReply*\0reply\0Initial\0TimeoutSlot2\0"
    "onMsgForHttpSignal\0temp\0RTCtimerSlot\0"
    "onsendParaSignal\0onsendrtcSignal\0devid\0"
    "rtc\0onSend2DevhttpSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DevHttpClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       8,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   86,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    1,   91,    2, 0x0a /* Public */,
      17,    0,   94,    2, 0x0a /* Public */,
      18,    1,   95,    2, 0x0a /* Public */,
      19,    2,   98,    2, 0x0a /* Public */,
      22,    2,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   20,   21,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    5,   20,

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
        case 3: _t->httpConnectSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->finishedSlot((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 5: _t->Initial(); break;
        case 6: _t->TimeoutSlot2(); break;
        case 7: _t->onMsgForHttpSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->RTCtimerSlot(); break;
        case 9: _t->onsendParaSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->onsendrtcSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->onSend2DevhttpSignal((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
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
        {
            typedef void (DevHttpClient::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DevHttpClient::httpConnectSignal)) {
                *result = 3;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
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

// SIGNAL 3
void DevHttpClient::httpConnectSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
