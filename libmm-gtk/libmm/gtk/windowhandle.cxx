// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/windowhandle.hxx>
#include <libmm/gtk/windowhandle_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  WindowHandle::unset_child () -> void
  {
    gtk_window_handle_set_child (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkWindowHandle* object, bool take_copy) -> gtk::WindowHandle*
  {
    return dynamic_cast<gtk::WindowHandle*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  WindowHandle_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &WindowHandle_Class::class_init_function;

      gtype_ = gtk_window_handle_get_type ();
    }

    return *this;
  }

  auto
  WindowHandle_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  WindowHandle_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new WindowHandle ((GtkWindowHandle*) (o)));
  }

  WindowHandle::WindowHandle (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  WindowHandle::WindowHandle (GtkWindowHandle* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  WindowHandle::WindowHandle (WindowHandle&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  WindowHandle::operator= (WindowHandle&& src) noexcept -> WindowHandle&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  WindowHandle::~WindowHandle () noexcept
  {
    destroy_ ();
  }

  WindowHandle::CppClassType WindowHandle::windowhandle_class_;

  auto
  WindowHandle::get_type () -> GType
  {
    return windowhandle_class_.init ().get_type ();
  }

  auto
  WindowHandle::get_base_type () -> GType
  {
    return gtk_window_handle_get_type ();
  }

  WindowHandle::WindowHandle ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (windowhandle_class_.init ()))
  {
  }

  auto
  WindowHandle::set_child (Widget& child) -> void
  {
    gtk_window_handle_set_child (gobj (), (child).gobj ());
  }

  auto
  WindowHandle::get_child () -> Widget*
  {
    return glib::wrap (gtk_window_handle_get_child (gobj ()));
  }

  auto
  WindowHandle::get_child () const -> const Widget*
  {
    return const_cast<WindowHandle*> (this)->get_child ();
  }

  auto
  WindowHandle::property_child () -> glib::PropertyProxy<Widget*>
  {
    return glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  WindowHandle::property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace gtk
