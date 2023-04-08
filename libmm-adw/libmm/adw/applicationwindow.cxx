// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/applicationwindow.hxx>
#include <libmm/adw/applicationwindow_p.hxx>

#include <adwaita.h>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwApplicationWindow* object, bool take_copy) -> adw::ApplicationWindow*
  {
    return dynamic_cast<adw::ApplicationWindow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ApplicationWindow_Class::init () -> const glib::Class&
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
  ApplicationWindow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new ApplicationWindow ((AdwApplicationWindow*) (o));
  }

  ApplicationWindow::ApplicationWindow (
      const glib::ConstructParams& construct_params)
    : gtk::ApplicationWindow (construct_params)
  {
  }

  ApplicationWindow::ApplicationWindow (AdwApplicationWindow* castitem)
    : gtk::ApplicationWindow ((GtkApplicationWindow*) (castitem))
  {
  }

  ApplicationWindow::ApplicationWindow (ApplicationWindow&& src) noexcept
    : gtk::ApplicationWindow (std::move (src))
  {
  }

  auto
  ApplicationWindow::operator= (ApplicationWindow&& src) noexcept -> ApplicationWindow&
  {
    gtk::ApplicationWindow::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::ApplicationWindow (
          glib::ConstructParams (applicationwindow_class_.init ()))
  {
  }

  ApplicationWindow::ApplicationWindow (
      const glib::RefPtr<gtk::Application>& application)
    : glib::ObjectBase (nullptr),
      gtk::ApplicationWindow (
          glib::ConstructParams (applicationwindow_class_.init (),
                                 "application",
                                 glib::unwrap (application),
                                 nullptr))
  {
  }

  auto
  ApplicationWindow::get_content () const -> gtk::Widget*
  {
    return glib::wrap (adw_application_window_get_content (
        const_cast<AdwApplicationWindow*> (gobj ())));
  }

  auto
  ApplicationWindow::set_content (gtk::Widget* content) -> void
  {
    adw_application_window_set_content (gobj (),
                                        (GtkWidget*) glib::unwrap (content));
  }

  auto
  ApplicationWindow::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  ApplicationWindow::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "content"};
  }

} // namespace adw
