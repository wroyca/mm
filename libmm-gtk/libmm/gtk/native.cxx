// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/native.hxx>
#include <libmm/gtk/native_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/surface.hxx>
#include <libmm/gtk/widget.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkNative* object, bool take_copy) -> Glib::RefPtr<Gtk::Native>
  {
    return Glib::make_refptr_for_instance<Gtk::Native> (
        dynamic_cast<Gtk::Native*> (
            Glib::wrap_auto_interface<Gtk::Native> ((GObject*) (object),
                                                    take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Native_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Native_Class::iface_init_function;

      gtype_ = gtk_native_get_type ();
    }

    return *this;
  }

  auto
  Native_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Native_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Native ((GtkNative*) (object));
  }

  Native::Native ()
    : Glib::Interface (native_class_.init ())
  {
  }

  Native::Native (GtkNative* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Native::Native (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Native::Native (Native&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Native::operator= (Native&& src) noexcept -> Native&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Native::~Native () noexcept {}

  auto
  Native::add_interface (GType gtype_implementer) -> void
  {
    native_class_.init ().add_interface (gtype_implementer);
  }

  Native::CppClassType Native::native_class_;

  auto
  Native::get_type () -> GType
  {
    return native_class_.init ().get_type ();
  }

  auto
  Native::get_base_type () -> GType
  {
    return gtk_native_get_type ();
  }

  auto
  Native::realize () -> void
  {
    gtk_native_realize (gobj ());
  }

  auto
  Native::unrealize () -> void
  {
    gtk_native_unrealize (gobj ());
  }

  auto
  Native::get_for_surface (const Glib::RefPtr<const Gdk::Surface>& surface) -> Native*
  {
    return dynamic_cast<Native*> (Glib::wrap_auto (
        (GObject*) (gtk_native_get_for_surface (
            const_cast<GdkSurface*> (Glib::unwrap<Gdk::Surface> (surface)))),
        false));
  }

  auto
  Native::get_surface () -> Glib::RefPtr<Gdk::Surface>
  {
    auto retvalue = Glib::wrap (gtk_native_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Native::get_surface () const -> Glib::RefPtr<const Gdk::Surface>
  {
    return const_cast<Native*> (this)->get_surface ();
  }

  auto
  Native::get_surface_transform (double& x, double& y) -> void
  {
    gtk_native_get_surface_transform (gobj (), &(x), &(y));
  }

} // namespace Gtk
