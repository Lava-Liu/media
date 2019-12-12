/****************************************************************************
** Meta object code from reading C++ file 'chatthread.h'
**
** Created: Thu Nov 21 20:02:44 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatClient/chatthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChatThread[] = {

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
      37,   11,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ChatThread[] = {
    "ChatThread\0\0sendChatMessage(QString)\0"
    "sendCommandMessage(QString)\0"
};

const QMetaObject ChatThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ChatThread,
      qt_meta_data_ChatThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChatThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChatThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChatThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChatThread))
        return static_cast<void*>(const_cast< ChatThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ChatThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendChatMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: sendCommandMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ChatThread::sendChatMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChatThread::sendCommandMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
