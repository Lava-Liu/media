/****************************************************************************
** Meta object code from reading C++ file 'readthread.h'
**
** Created: Tue Nov 26 14:53:42 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TcpClient/readthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'readthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReadThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ReadThread[] = {
    "ReadThread\0\0sendImg(QPixmap)\0"
    "sendData(QByteArray)\0"
};

const QMetaObject ReadThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReadThread,
      qt_meta_data_ReadThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReadThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReadThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReadThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReadThread))
        return static_cast<void*>(const_cast< ReadThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ReadThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendImg((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 1: sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ReadThread::sendImg(QPixmap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReadThread::sendData(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
