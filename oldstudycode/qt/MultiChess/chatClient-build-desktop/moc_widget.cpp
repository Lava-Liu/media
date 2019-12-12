/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Fri Nov 22 14:27:37 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatClient/widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      39,    7,    7,    7, 0x0a,
      57,    7,    7,    7, 0x0a,
      74,    7,    7,    7, 0x0a,
     100,    7,    7,    7, 0x0a,
     128,    7,    7,    7, 0x0a,
     159,    7,    7,    7, 0x0a,
     188,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0textEditReturnPressed(QString)\0"
    "startBtnClicked()\0gmerTimerStart()\0"
    "clientConnectHandler(int)\0"
    "chatMessageHandler(QString)\0"
    "commandMessageHandler(QString)\0"
    "chessMessageHandler(QString)\0"
    "chessErrorHandler()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: textEditReturnPressed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: startBtnClicked(); break;
        case 2: gmerTimerStart(); break;
        case 3: clientConnectHandler((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: chatMessageHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: commandMessageHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: chessMessageHandler((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: chessErrorHandler(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
