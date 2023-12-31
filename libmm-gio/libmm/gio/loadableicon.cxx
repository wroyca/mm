// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/loadableicon.hxx>
#include <libmm/gio/loadableicon_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>

namespace gio
{

  auto
  LoadableIcon::load (const int size,
                      glib::ustring& type,
                      const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<InputStream>
  {
    char* c_type;
    GError* gerror = nullptr;
    auto retval = glib::wrap (g_loadable_icon_load (gobj (),
                                                    size,
                                                    &c_type,
                                                    glib::unwrap (cancellable),
                                                    &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);

    type = c_type;
    g_free (c_type);
    if (retval)
      retval->reference ();
    return retval;
  }

  auto
  LoadableIcon::load (const int size, glib::ustring& type) -> glib::RefPtr<InputStream>
  {
    char* c_type;
    GError* gerror = nullptr;
    auto retval = glib::wrap (
        g_loadable_icon_load (gobj (), size, &c_type, nullptr, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);

    type = c_type;
    g_free (c_type);
    if (retval)
      retval->reference ();
    return retval;
  }

  auto
  LoadableIcon::load_async (const int size,
                            const SlotAsyncReady& slot,
                            const glib::RefPtr<Cancellable>& cancellable) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_loadable_icon_load_async (gobj (),
                                size,
                                glib::unwrap (cancellable),
                                &SignalProxy_async_callback,
                                slot_copy);
  }

  auto
  LoadableIcon::load_async (const int size, const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_loadable_icon_load_async (gobj (),
                                size,
                                nullptr,
                                &SignalProxy_async_callback,
                                slot_copy);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GLoadableIcon* object, const bool take_copy) -> RefPtr<gio::LoadableIcon>
  {
    return glib::make_refptr_for_instance<gio::LoadableIcon> (
        glib::wrap_auto_interface<gio::LoadableIcon> ((GObject*) object,
                                                      take_copy));
  }

} // namespace glib

namespace gio
{

  auto
  LoadableIcon_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LoadableIcon_Class::iface_init_function;

      gtype_ = g_loadable_icon_get_type ();
    }

    return *this;
  }

  auto
  LoadableIcon_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  LoadableIcon_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new LoadableIcon ((GLoadableIcon*) object);
  }

  LoadableIcon::LoadableIcon ()
    : Interface (loadableicon_class_.init ())
  {
  }

  LoadableIcon::LoadableIcon (GLoadableIcon* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  LoadableIcon::LoadableIcon (const glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  LoadableIcon::LoadableIcon (LoadableIcon&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  LoadableIcon::operator= (LoadableIcon&& src) noexcept -> LoadableIcon&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  LoadableIcon::~LoadableIcon () noexcept = default;

  auto
  LoadableIcon::add_interface (const GType gtype_implementer) -> void
  {
    loadableicon_class_.init ().add_interface (gtype_implementer);
  }

  LoadableIcon::CppClassType LoadableIcon::loadableicon_class_;

  auto
  LoadableIcon::get_type () -> GType
  {
    return loadableicon_class_.init ().get_type ();
  }

  auto
  LoadableIcon::get_base_type () -> GType
  {
    return g_loadable_icon_get_type ();
  }

} // namespace gio
