/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtDBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the public API.  This header file may
// change from version to version without notice, or even be
// removed.
//
// We mean it.
//
//

#ifndef QDBUSMETAOBJECT_P_H
#define QDBUSMETAOBJECT_P_H

#include <QtCore/qmetaobject.h>
#include <qdbusmacros.h>

#ifndef QT_NO_DBUS

QT_BEGIN_NAMESPACE

class QDBusError;

struct QDBusMetaObjectPrivate;
struct Q_DBUS_EXPORT QDBusMetaObject: public QMetaObject
{
    bool cached;

    static QDBusMetaObject *createMetaObject(const QString &interface, const QString &xml,
                                             QHash<QString, QDBusMetaObject *> &map,
                                             QDBusError &error);
    ~QDBusMetaObject()
    {
        delete [] reinterpret_cast<const char *>(d.stringdata);
        delete [] d.data;
    }

    // methods (slots & signals):
    const int *inputTypesForMethod(int id) const;
    const int *outputTypesForMethod(int id) const;

    // properties:
    int propertyMetaType(int id) const;

private:
    QDBusMetaObject();
};

QT_END_NAMESPACE

#endif // QT_NO_DBUS
#endif
