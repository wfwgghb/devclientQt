/****************************************************************************
** Meta object code from reading C++ file 'tcpconnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpclientGui/tcpconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpConnection_t {
    QByteArrayData data[22];
    char stringdata0[259];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpConnection_t qt_meta_stringdata_TcpConnection = {
    {
QT_MOC_LITERAL(0, 0, 13), // "TcpConnection"
QT_MOC_LITERAL(1, 14, 16), // "stopSocketSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "ConnectionSuccessSignal"
QT_MOC_LITERAL(4, 56, 11), // "errorSignal"
QT_MOC_LITERAL(5, 68, 4), // "flag"
QT_MOC_LITERAL(6, 73, 12), // "RcvmsgSignal"
QT_MOC_LITERAL(7, 86, 6), // "rcvmsg"
QT_MOC_LITERAL(8, 93, 14), // "SendDataSignal"
QT_MOC_LITERAL(9, 108, 8), // "recvdata"
QT_MOC_LITERAL(10, 117, 14), // "RTCtimerSignal"
QT_MOC_LITERAL(11, 132, 16), // "HttpClientSignal"
QT_MOC_LITERAL(12, 149, 3), // "msg"
QT_MOC_LITERAL(13, 153, 17), // "ParaSettingSignal"
QT_MOC_LITERAL(14, 171, 4), // "data"
QT_MOC_LITERAL(15, 176, 7), // "SendMsg"
QT_MOC_LITERAL(16, 184, 6), // "RcvMsg"
QT_MOC_LITERAL(17, 191, 7), // "Initial"
QT_MOC_LITERAL(18, 199, 13), // "sendHeartBeat"
QT_MOC_LITERAL(19, 213, 14), // "stopSocketSlot"
QT_MOC_LITERAL(20, 228, 12), // "RTCtimerSlot"
QT_MOC_LITERAL(21, 241, 17) // "sendDeviceRequest"

    },
    "TcpConnection\0stopSocketSignal\0\0"
    "ConnectionSuccessSignal\0errorSignal\0"
    "flag\0RcvmsgSignal\0rcvmsg\0SendDataSignal\0"
    "recvdata\0RTCtimerSignal\0HttpClientSignal\0"
    "msg\0ParaSettingSignal\0data\0SendMsg\0"
    "RcvMsg\0Initial\0sendHeartBeat\0"
    "stopSocketSlot\0RTCtimerSlot\0"
    "sendDeviceRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpConnection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    1,   91,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       8,    1,   97,    2, 0x06 /* Public */,
      10,    0,  100,    2, 0x06 /* Public */,
      11,    1,  101,    2, 0x06 /* Public */,
      13,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  107,    2, 0x0a /* Public */,
      16,    0,  110,    2, 0x0a /* Public */,
      17,    0,  111,    2, 0x0a /* Public */,
      18,    0,  112,    2, 0x0a /* Public */,
      19,    0,  113,    2, 0x0a /* Public */,
      20,    0,  114,    2, 0x0a /* Public */,
      21,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   12,
    QMetaType::Void, QMetaType::UChar,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpConnection *_t = static_cast<TcpConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopSocketSignal(); break;
        case 1: _t->ConnectionSuccessSignal(); break;
        case 2: _t->errorSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RcvmsgSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->SendDataSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->RTCtimerSignal(); break;
        case 6: _t->HttpClientSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->ParaSettingSignal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 8: _t->SendMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->RcvMsg(); break;
        case 10: _t->Initial(); break;
        case 11: _t->sendHeartBeat(); break;
        case 12: _t->stopSocketSlot(); break;
        case 13: _t->RTCtimerSlot(); break;
        case 14: _t->sendDeviceRequest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::stopSocketSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::ConnectionSuccessSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::errorSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::RcvmsgSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::SendDataSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::RTCtimerSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::HttpClientSignal)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (TcpConnection::*_t)(quint8 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpConnection::ParaSettingSignal)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject TcpConnection::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpConnection.data,
      qt_meta_data_TcpConnection,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpConnection.stringdata0))
        return static_cast<void*>(const_cast< TcpConnection*>(this));
    return QObject::qt_metacast(_clname);
}

int TcpConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TcpConnection::stopSocketSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TcpConnection::ConnectionSuccessSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TcpConnection::errorSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpConnection::RcvmsgSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpConnection::SendDataSignal(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpConnection::RTCtimerSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void TcpConnection::HttpClientSignal(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpConnection::ParaSettingSignal(quint8 _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
