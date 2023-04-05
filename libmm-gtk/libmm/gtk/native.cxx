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

namespace glib
{

  auto
  wrap (GtkNative* object, bool take_copy) -> glib::RefPtr<gtk::Native>
  {
    return glib::make_refptr_for_instance<gtk::Native> (
        dynamic_cast<gtk::Native*> (
            glib::wrap_auto_interface<gtk::Native> ((GObject*) (object),
                                                    take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Native_Class::init () -> const glib::Interface_Class&
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
  Native_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Native ((GtkNative*) (object));
  }

  Native::Native ()
    : glib::Interface (native_class_.init ())
  {
  }

  Native::Native (GtkNative* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Native::Native (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Native::Native (Native&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Native::operator= (Native&& src) noexcept -> Native&
  {
    glib::Interface::operator= (std::move (src));
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
  Native::get_for_surface (const glib::RefPtr<const gdk::Surface>& surface) -> Native*
  {
    return dynamic_cast<Native*> (glib::wrap_auto (
        (GObject*) (gtk_native_get_for_surface (
            const_cast<GdkSurface*> (glib::unwrap<gdk::Surface> (surface)))),
        false));
  }

  auto
  Native::get_surface () -> glib::RefPtr<gdk::Surface>
  {
    auto retvalue = glib::wrap (gtk_native_get_surface (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Native::get_surface () const -> glib::RefPtr<const gdk::Surface>
  {
    return const_cast<Native*> (this)->get_surface ();
  }

  auto
  Native::get_surface_transform (double& x, double& y) -> void
  {
    gtk_native_get_surface_transform (gobj (), &(x), &(y));
  }

} // namespace gtk
