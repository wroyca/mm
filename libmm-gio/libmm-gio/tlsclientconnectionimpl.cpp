/* Copyright (C) 2020 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <mm/gio/tlsclientconnectionimpl.hpp>
#include <utility> // std::move()

namespace Gio
{
TlsClientConnectionImpl::TlsClientConnectionImpl(GTlsConnection* castitem)
: ObjectBase(nullptr), TlsConnection(castitem)
{}

TlsClientConnectionImpl::TlsClientConnectionImpl(TlsClientConnectionImpl&& src) noexcept
: TlsClientConnection(std::move(src)),
  TlsConnection(std::move(src))
{}

auto TlsClientConnectionImpl::operator=(TlsClientConnectionImpl&& src) noexcept -> TlsClientConnectionImpl&
{
  TlsClientConnection::operator=(std::move(src));
  TlsConnection::operator=(std::move(src));
  return *this;
}

TlsClientConnectionImpl::~TlsClientConnectionImpl() noexcept = default;
} // namespace Gio
