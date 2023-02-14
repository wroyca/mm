// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fixed.hxx>
#include <libmm-gtk/fixed_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFixed* object, const bool take_copy) -> Gtk::Fixed*
  {
    return dynamic_cast<Gtk::Fixed*> (wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Fixed_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Fixed_Class::class_init_function;

      register_derived_type (gtk_fixed_get_type ());
    }

    return *this;
  }

  auto
  Fixed_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Fixed_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Fixed ((GtkFixed*) o));
  }

  Fixed::Fixed (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  Fixed::Fixed (GtkFixed* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  Fixed::Fixed (Fixed&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  Fixed::operator= (Fixed&& src) noexcept -> Fixed&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  Fixed::~Fixed () noexcept
  {
    destroy_ ();
  }

  Fixed::CppClassType Fixed::fixed_class_;

  auto
  Fixed::get_type () -> GType
  {
    return fixed_class_.init ().get_type ();
  }

  auto
  Fixed::get_base_type () -> GType
  {
    return gtk_fixed_get_type ();
  }

  Fixed::Fixed ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (fixed_class_.init ()))
  {
  }

  auto
  Fixed::put (Widget& widget, const double x, const double y) -> void
  {
    gtk_fixed_put (gobj (), widget.gobj (), x, y);
  }

  auto
  Fixed::remove (Widget& widget) -> void
  {
    gtk_fixed_remove (gobj (), widget.gobj ());
  }

  auto
  Fixed::move (Widget& widget, const double x, const double y) -> void
  {
    gtk_fixed_move (gobj (), widget.gobj (), x, y);
  }

  auto
  Fixed::get_child_position (Widget& widget, double& x, double& y) const -> void
  {
    gtk_fixed_get_child_position (const_cast<GtkFixed*> (gobj ()),
                                  widget.gobj (),
                                  &x,
                                  &y);
  }

} // namespace Gtk
