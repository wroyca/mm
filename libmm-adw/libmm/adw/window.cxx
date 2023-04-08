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
  wrap (AdwWindow* object, bool take_copy) -> adw::Window*
  {
    return dynamic_cast<adw::Window*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Window_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Window_Class::class_init_function;

      register_derived_type (adw_window_get_type ());
    }

    return *this;
  }

  auto
  Window_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Window_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new Window ((AdwWindow*) (o));
  }

  Window::Window (const glib::ConstructParams& construct_params)
    : gtk::Window (construct_params)
  {
  }

  Window::Window (AdwWindow* castitem)
    : gtk::Window ((GtkWindow*) (castitem))
  {
  }

  Window::Window (Window&& src) noexcept
    : gtk::Window (std::move (src))
  {
  }

  auto
  Window::operator= (Window&& src) noexcept -> Window&
  {
    gtk::Window::operator= (std::move (src));
    return *this;
  }

  Window::~Window () noexcept
  {
    destroy_ ();
  }

  Window::CppClassType Window::window_class_;

  auto
  Window::get_type () -> GType
  {
    return window_class_.init ().get_type ();
  }

  auto
  Window::get_base_type () -> GType
  {
    return adw_window_get_type ();
  }

  Window::Window ()
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (window_class_.init ()))
  {
  }

  auto
  Window::get_content () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_window_get_content (const_cast<AdwWindow*> (gobj ())));
  }

  auto
  Window::set_content (gtk::Widget* content) -> void
  {
    adw_window_set_content (gobj (), (GtkWidget*) glib::unwrap (content));
  }

  auto
  Window::property_content () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "content"};
  }

  auto
  Window::property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "content"};
  }

} // namespace adw
