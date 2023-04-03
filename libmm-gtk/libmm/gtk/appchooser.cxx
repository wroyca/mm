// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/appchooser.hxx>
  #include <libmm/gtk/appchooser_p.hxx>

  #include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkAppChooser* object, bool take_copy) -> Glib::RefPtr<Gtk::AppChooser>
  {
    return Glib::make_refptr_for_instance<Gtk::AppChooser> (
        dynamic_cast<Gtk::AppChooser*> (
            Glib::wrap_auto_interface<Gtk::AppChooser> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AppChooser_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppChooser_Class::iface_init_function;

      gtype_ = gtk_app_chooser_get_type ();
    }

    return *this;
  }

  auto
  AppChooser_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  AppChooser_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AppChooser ((GtkAppChooser*) (object));
  }

  AppChooser::AppChooser ()
    : Glib::Interface (appchooser_class_.init ())
  {
  }

  AppChooser::AppChooser (GtkAppChooser* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  AppChooser::AppChooser (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  AppChooser::AppChooser (AppChooser&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  AppChooser::operator= (AppChooser&& src) noexcept -> AppChooser&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  AppChooser::~AppChooser () noexcept {}

  auto
  AppChooser::add_interface (GType gtype_implementer) -> void
  {
    appchooser_class_.init ().add_interface (gtype_implementer);
  }

  AppChooser::CppClassType AppChooser::appchooser_class_;

  auto
  AppChooser::get_type () -> GType
  {
    return appchooser_class_.init ().get_type ();
  }

  auto
  AppChooser::get_base_type () -> GType
  {
    return gtk_app_chooser_get_type ();
  }

  auto
  AppChooser::get_app_info () -> Glib::RefPtr<Gio::AppInfo>
  {
    auto retvalue = Glib::wrap (gtk_app_chooser_get_app_info (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AppChooser::get_app_info () const -> Glib::RefPtr<const Gio::AppInfo>
  {
    return const_cast<AppChooser*> (this)->get_app_info ();
  }

  auto
  AppChooser::get_content_type () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_app_chooser_get_content_type (
            const_cast<GtkAppChooser*> (gobj ())));
  }

  auto
  AppChooser::refresh () -> void
  {
    gtk_app_chooser_refresh (gobj ());
  }

  auto
  AppChooser::property_content_type () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "content-type");
  }

} // namespace Gtk

#endif