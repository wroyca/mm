/* Copyright (C) 2007 The gtkmm Development Team
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

#include <mm/glib/exceptionhandler.hpp>
#include <mm/gio/asyncresult.hpp>
#include <mm/gio/slot_async.hpp>

namespace Gio
{

auto SignalProxy_async_callback (GObject *, GAsyncResult *res, void *data) -> void
{
  const SlotAsyncReady * the_slot = static_cast<SlotAsyncReady *>(data);

  try
  {
    auto result = Glib::wrap(res, true /* take copy */);
    (*the_slot)(result);
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }

  delete the_slot;
}

} // namespace Gio
