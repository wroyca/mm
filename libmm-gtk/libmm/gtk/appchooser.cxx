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

namespace glib
{

  auto
  wrap (GtkAppChooser* object, bool take_copy) -> glib::RefPtr<gtk::AppChooser>
  {
    return glib::make_refptr_for_instance<gtk::AppChooser> (
        dynamic_cast<gtk::AppChooser*> (
            glib::wrap_auto_interface<gtk::AppChooser> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  AppChooser_Class::init () -> const glib::Interface_Class&
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
  AppChooser_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AppChooser ((GtkAppChooser*) (object));
  }

  AppChooser::AppChooser ()
    : glib::Interface (appchooser_class_.init ())
  {
  }

  AppChooser::AppChooser (GtkAppChooser* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  AppChooser::AppChooser (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  AppChooser::AppChooser (AppChooser&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  AppChooser::operator= (AppChooser&& src) noexcept -> AppChooser&
  {
    glib::Interface::operator= (std::move (src));
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
  AppChooser::get_app_info () -> glib::RefPtr<gio::AppInfo>
  {
    auto retvalue = glib::wrap (gtk_app_chooser_get_app_info (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  AppChooser::get_app_info () const -> glib::RefPtr<const gio::AppInfo>
  {
    return const_cast<AppChooser*> (this)->get_app_info ();
  }

  auto
  AppChooser::get_content_type () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_app_chooser_get_content_type (
            const_cast<GtkAppChooser*> (gobj ())));
  }

  auto
  AppChooser::refresh () -> void
  {
    gtk_app_chooser_refresh (gobj ());
  }

  auto
  AppChooser::property_content_type () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "content-type");
  }

} // namespace gtk

#endif
