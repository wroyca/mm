// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  auto
  SignalProxy_async_callback (GObject*, GAsyncResult* res, void* data) -> void
  {
    const SlotAsyncReady* the_slot = static_cast<SlotAsyncReady*> (data);

    try
    {
      auto result = glib::wrap (res, true);
      (*the_slot) (result);
    }
    catch (...)
    {
      glib::exception_handlers_invoke ();
    }

    delete the_slot;
  }

} // namespace gio
