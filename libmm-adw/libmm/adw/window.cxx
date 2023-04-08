// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/window.hxx>
#include <libmm/adw/window_p.hxx>

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
  wrap (AdwWindow* object, bool take_copy) -> adw::window*
  {
    return dynamic_cast<adw::window*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  window_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &window_class::class_init_function;

      register_derived_type (adw_window_get_type ());
    }

    return *this;
  }

  auto
  window_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  window_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new window ((AdwWindow*) (o));
  }

  window::window (const glib::ConstructParams& construct_params)
    : gtk::Window (construct_params)
  {
  }

  window::window (AdwWindow* castitem)
    : gtk::Window ((GtkWindow*) (castitem))
  {
  }

  window::window (window&& src) noexcept
    : gtk::Window (std::move (src))
  {
  }

  auto
  window::operator= (window&& src) noexcept -> window&
  {
    gtk::Window::operator= (std::move (src));
    return *this;
  }

  window::~window () noexcept
  {
    destroy_ ();
  }

  window::CppClassType window::window_class_;

  auto
  window::get_type () -> GType
  {
    return window_class_.init ().get_type ();
  }

  auto
  window::get_base_type () -> GType
  {
    return adw_window_get_type ();
  }

  window::window ()
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (window_class_.init ()))
  {
  }

  auto
  window::get_content () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_window_get_content (const_cast<AdwWindow*> (gobj ())));
  }

  auto
  window::set_content (gtk::Widget* content) -> void
  {
    adw_window_set_content (gobj (), (GtkWidget*) glib::unwrap (content));
  }

  auto
  window::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  window::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "content"};
  }

} // namespace adw
