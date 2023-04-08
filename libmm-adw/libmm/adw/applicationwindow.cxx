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
  wrap (AdwApplicationWindow* object, bool take_copy) -> adw::application_window*
  {
    return dynamic_cast<adw::application_window*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  application_window_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &application_window_class::class_init_function;

      register_derived_type (adw_application_window_get_type ());
    }

    return *this;
  }

  auto
  application_window_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  application_window_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new application_window ((AdwApplicationWindow*) (o));
  }

  application_window::application_window (
      const glib::ConstructParams& construct_params)
    : gtk::ApplicationWindow (construct_params)
  {
  }

  application_window::application_window (AdwApplicationWindow* castitem)
    : gtk::ApplicationWindow ((GtkApplicationWindow*) (castitem))
  {
  }

  application_window::application_window (application_window&& src) noexcept
    : gtk::ApplicationWindow (std::move (src))
  {
  }

  auto
  application_window::operator= (application_window&& src) noexcept -> application_window&
  {
    gtk::ApplicationWindow::operator= (std::move (src));
    return *this;
  }

  application_window::~application_window () noexcept
  {
    destroy_ ();
  }

  application_window::CppClassType application_window::applicationwindow_class_;

  auto
  application_window::get_type () -> GType
  {
    return applicationwindow_class_.init ().get_type ();
  }

  auto
  application_window::get_base_type () -> GType
  {
    return adw_application_window_get_type ();
  }

  application_window::application_window ()
    : glib::ObjectBase (nullptr),
      gtk::ApplicationWindow (
          glib::ConstructParams (applicationwindow_class_.init ()))
  {
  }

  application_window::application_window (
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
  application_window::get_content () const -> gtk::Widget*
  {
    return glib::wrap (adw_application_window_get_content (
        const_cast<AdwApplicationWindow*> (gobj ())));
  }

  auto
  application_window::set_content (gtk::Widget* content) -> void
  {
    adw_application_window_set_content (gobj (),
                                        (GtkWidget*) glib::unwrap (content));
  }

  auto
  application_window::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  application_window::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "content"};
  }

} // namespace adw
