/****************************************************************************
** Meta object code from reading C++ file 'paradlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tcpclientGui/paradlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paradlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_paradlg_t {
    QByteArrayData data[13];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_paradlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_paradlg_t qt_meta_stringdata_paradlg = {
    {
QT_MOC_LITERAL(0, 0, 7), // "paradlg"
QT_MOC_LITERAL(1, 8, 14), // "sendParaSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "block"
QT_MOC_LITERAL(4, 30, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 52, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(6, 76, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(7, 100, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(8, 124, 23), // "on_pushButton_6_clicked"
QT_MOC_LITERAL(9, 148, 15), // "ParaSettingSlot"
QT_MOC_LITERAL(10, 164, 4), // "data"
QT_MOC_LITERAL(11, 169, 12), // "UsernameSlot"
QT_MOC_LITERAL(12, 182, 8) // "userName"

    },
    "paradlg\0sendParaSignal\0\0block\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked\0ParaSettingSlot\0"
    "data\0UsernameSlot\0userName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_paradlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    1,   62,    2, 0x08 /* Private */,
      11,    1,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,   10,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void paradlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        paradlg *_t = static_cast<paradlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendParaSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_4_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        case 5: _t->on_pushButton_6_clicked(); break;
        case 6: _t->ParaSettingSlot((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 7: _t->UsernameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (paradlg::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&paradlg::sendParaSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject paradlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_paradlg.data,
      qt_meta_data_paradlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *paradlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *paradlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_paradlg.stringdata0))
        return static_cast<void*>(const_cast< paradlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int paradlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void paradlg::sendParaSignal(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
