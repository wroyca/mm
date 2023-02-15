// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/window.hxx>
#include <libmm-adw/window_p.hxx>

#include <adwaita.h>
#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwWindow* object, bool take_copy) -> Adw::Window*
  {
    return dynamic_cast<Adw::Window*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Window_Class::init () -> const Glib::Class&
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
  Window_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new Window ((AdwWindow*) (o));
  }

  Window::Window (const Glib::ConstructParams& construct_params)
    : Gtk::Window (construct_params)
  {
  }

  Window::Window (AdwWindow* castitem)
    : Gtk::Window ((GtkWindow*) (castitem))
  {
  }

  Window::Window (Window&& src) noexcept
    : Gtk::Window (std::move (src))
  {
  }

  auto
  Window::operator= (Window&& src) noexcept -> Window&
  {
    Gtk::Window::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Window (Glib::ConstructParams (window_class_.init ()))
  {
  }

  auto
  Window::get_content () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_window_get_content (const_cast<AdwWindow*> (gobj ())));
  }

  auto
  Window::set_content (Gtk::Widget* content) -> void
  {
    adw_window_set_content (gobj (), (GtkWidget*) Glib::unwrap (content));
  }

  auto
  Window::property_content () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "content");
  }

  auto
  Window::property_content () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "content");
  }

} // namespace Adw
