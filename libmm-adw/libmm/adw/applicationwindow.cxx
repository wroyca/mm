// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/applicationwindow.hxx>
#include <libmm/adw/applicationwindow_p.hxx>

#include <adwaita.h>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwApplicationWindow* object, bool take_copy) -> Adw::ApplicationWindow*
  {
    return dynamic_cast<Adw::ApplicationWindow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ApplicationWindow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ApplicationWindow_Class::class_init_function;

      register_derived_type (adw_application_window_get_type ());
    }

    return *this;
  }

  auto
  ApplicationWindow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ApplicationWindow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new ApplicationWindow ((AdwApplicationWindow*) (o));
  }

  ApplicationWindow::ApplicationWindow (
      const Glib::ConstructParams& construct_params)
    : Gtk::ApplicationWindow (construct_params)
  {
  }

  ApplicationWindow::ApplicationWindow (AdwApplicationWindow* castitem)
    : Gtk::ApplicationWindow ((GtkApplicationWindow*) (castitem))
  {
  }

  ApplicationWindow::ApplicationWindow (ApplicationWindow&& src) noexcept
    : Gtk::ApplicationWindow (std::move (src))
  {
  }

  auto
  ApplicationWindow::operator= (ApplicationWindow&& src) noexcept -> ApplicationWindow&
  {
    Gtk::ApplicationWindow::operator= (std::move (src));
    return *this;
  }

  ApplicationWindow::~ApplicationWindow () noexcept
  {
    destroy_ ();
  }

  ApplicationWindow::CppClassType ApplicationWindow::applicationwindow_class_;

  auto
  ApplicationWindow::get_type () -> GType
  {
    return applicationwindow_class_.init ().get_type ();
  }

  auto
  ApplicationWindow::get_base_type () -> GType
  {
    return adw_application_window_get_type ();
  }

  ApplicationWindow::ApplicationWindow ()
    : Glib::ObjectBase (nullptr),
      Gtk::ApplicationWindow (
          Glib::ConstructParams (applicationwindow_class_.init ()))
  {
  }

  ApplicationWindow::ApplicationWindow (
      const Glib::RefPtr<Gtk::Application>& application)
    : Glib::ObjectBase (nullptr),
      Gtk::ApplicationWindow (
          Glib::ConstructParams (applicationwindow_class_.init (),
                                 "application",
                                 Glib::unwrap (application),
                                 nullptr))
  {
  }

  auto
  ApplicationWindow::get_content () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_application_window_get_content (
        const_cast<AdwApplicationWindow*> (gobj ())));
  }

  auto
  ApplicationWindow::set_content (Gtk::Widget* content) -> void
  {
    adw_application_window_set_content (gobj (),
                                        (GtkWidget*) Glib::unwrap (content));
  }

  auto
  ApplicationWindow::property_content () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "content");
  }

  auto
  ApplicationWindow::property_content () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "content");
  }

} // namespace Adw
