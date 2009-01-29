/*
 * This file is part of TelepathyQt4
 *
 * Copyright (C) 2008 Collabora Ltd. <http://www.collabora.co.uk/>
 * Copyright (C) 2008 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _TelepathyQt4_cli_contact_h_HEADER_GUARD_
#define _TelepathyQt4_cli_contact_h_HEADER_GUARD_

#ifndef IN_TELEPATHY_QT4_HEADER
#error IN_TELEPATHY_QT4_HEADER
#endif

#include <QObject>
#include <QVariantMap>

namespace Telepathy
{
namespace Client
{
class Connection;
class ContactManager;
class ReferencedHandles;

class Contact : public QObject
{
    Q_OBJECT

public:
    enum Feature {
        _Padding = 0xFFFFFFFF
    };
    Q_DECLARE_FLAGS(Features, Feature);

    Connection *connection() const;

    ReferencedHandles handle() const;
    QString id() const;

    ~Contact();

private:
    Q_DISABLE_COPY(Contact);

    Contact(Connection *parent, const ReferencedHandles &handle, const QVariantMap &attributes);

    struct Private;
    friend class PendingContacts;
    friend struct Private;
    Private *mPriv;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(Contact::Features)

} // Telepathy::Client
} // Telepathy

#endif