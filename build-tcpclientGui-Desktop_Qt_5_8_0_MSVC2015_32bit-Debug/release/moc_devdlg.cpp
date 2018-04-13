/****************************************************************************
** Meta object code from reading C++ file 'devdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpclientGui/devdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_devdlg_t {
    QByteArrayData data[20];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_devdlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_devdlg_t qt_meta_stringdata_devdlg = {
    {
QT_MOC_LITERAL(0, 0, 6), // "devdlg"
QT_MOC_LITERAL(1, 7, 10), // "SendSignal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "block"
QT_MOC_LITERAL(4, 25, 8), // "sendData"
QT_MOC_LITERAL(5, 34, 8), // "recvdata"
QT_MOC_LITERAL(6, 43, 20), // "DevattrChangedSignal"
QT_MOC_LITERAL(7, 64, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 86, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(9, 110, 23), // "on_pushButton_7_clicked"
QT_MOC_LITERAL(10, 134, 23), // "on_pushButton_8_clicked"
QT_MOC_LITERAL(11, 158, 14), // "deleDeviceSlot"
QT_MOC_LITERAL(12, 173, 12), // "UsernameSlot"
QT_MOC_LITERAL(13, 186, 8), // "userName"
QT_MOC_LITERAL(14, 195, 15), // "slotContextMenu"
QT_MOC_LITERAL(15, 211, 3), // "pos"
QT_MOC_LITERAL(16, 215, 15), // "OpenSetttingDlg"
QT_MOC_LITERAL(17, 231, 16), // "OpenSetttingDlg1"
QT_MOC_LITERAL(18, 248, 11), // "receiveData"
QT_MOC_LITERAL(19, 260, 12) // "receiveData1"

    },
    "devdlg\0SendSignal\0\0block\0sendData\0"
    "recvdata\0DevattrChangedSignal\0"
    "on_pushButton_clicked\0on_pushButton_6_clicked\0"
    "on_pushButton_7_clicked\0on_pushButton_8_clicked\0"
    "deleDeviceSlot\0UsernameSlot\0userName\0"
    "slotContextMenu\0pos\0OpenSetttingDlg\0"
    "OpenSetttingDlg1\0receiveData\0receiveData1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_devdlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   91,    2, 0x08 /* Private */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    1,   96,    2, 0x08 /* Private */,
      14,    1,   99,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      19,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void devdlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        devdlg *_t = static_cast<devdlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendSignal((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->DevattrChangedSignal(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_6_clicked(); break;
        case 5: _t->on_pushButton_7_clicked(); break;
        case 6: _t->on_pushButton_8_clicked(); break;
        case 7: _t->deleDeviceSlot(); break;
        case 8: _t->UsernameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slotContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 10: _t->OpenSetttingDlg(); break;
        case 11: _t->OpenSetttingDlg1(); break;
        case 12: _t->receiveData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->receiveData1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (devdlg::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&devdlg::SendSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (devdlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&devdlg::sendData)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (devdlg::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&devdlg::DevattrChangedSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject devdlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_devdlg.data,
      qt_meta_data_devdlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *devdlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *devdlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_devdlg.stringdata0))
        return static_cast<void*>(const_cast< devdlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int devdlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void devdlg::SendSignal(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void devdlg::sendData(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void devdlg::DevattrChangedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
