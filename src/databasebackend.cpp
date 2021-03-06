/******************************************************************************
 * This file is part of the Gluon Development Platform
 * Copyright (c) 2011 Laszlo Papp <djszapi@archlinux.us>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "databasebackend.h"

using namespace LibQGit2;

DatabaseBackend::DatabaseBackend( QObject* parent )
{
}

DatabaseBackend::DatabaseBackend( const DatabaseBackend& other )
{
}

DatabaseBackend::~DatabaseBackend()
{
}

int DatabaseBackend::pack(const QString& objectsDir)
{
    return git_odb_backend_pack(&m_databaseBackend, objectsDir.toAscii().constData());
}

int DatabaseBackend::loose(const QString& objectsDir)
{
    return git_odb_backend_loose(&m_databaseBackend, objectsDir.toAscii().constData());
}

git_odb_backend* DatabaseBackend::data() const
{
    return m_databaseBackend;
}

const git_odb_backend* DatabaseBackend::constData() const
{
    return const_cast<const git_odb_backend *>(m_databaseBackend);
}
