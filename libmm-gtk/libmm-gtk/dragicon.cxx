


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/dragicon.hxx>
#include <libmm-gtk/dragicon_p.hxx>


/* Copyright (C) 2020 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace Gtk
{

auto DragIcon::unset_child () -> void
{
  gtk_drag_icon_set_child(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkDragIcon* object, const bool take_copy) -> Gtk::DragIcon*
{
  return dynamic_cast<Gtk::DragIcon *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto DragIcon_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DragIcon_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = gtk_drag_icon_get_type();

  }

  return *this;
}


auto DragIcon_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto DragIcon_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new DragIcon((GtkDragIcon*)o));

}


/* The implementation: */

DragIcon::DragIcon(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

DragIcon::DragIcon(GtkDragIcon* castitem)
: Widget((GtkWidget*)castitem)
{
  }


DragIcon::DragIcon(DragIcon&& src) noexcept
: Widget(std::move(src))
  , Native(std::move(src))
  , Root(std::move(src))
{}

auto DragIcon::operator=(DragIcon&& src) noexcept -> DragIcon&
{
  Widget::operator=(std::move(src));
  Native::operator=(std::move(src));
  Root::operator=(std::move(src));
  return *this;
}

DragIcon::~DragIcon() noexcept
{
  destroy_();
}

DragIcon::CppClassType DragIcon::dragicon_class_; // initialize static member

auto DragIcon::get_type() -> GType
{
  return dragicon_class_.init().get_type();
}


auto DragIcon::get_base_type() -> GType
{
  return gtk_drag_icon_get_type();
}


auto DragIcon::get_for_drag(const Glib::RefPtr<Gdk::Drag>& drag) -> DragIcon*
{
  return Glib::wrap((GtkDragIcon*)gtk_drag_icon_get_for_drag(Glib::unwrap(drag)));
}

auto DragIcon::set_child (Widget &child) -> void
{
  gtk_drag_icon_set_child(gobj(), child.gobj());
}

auto DragIcon::get_child() -> Widget*
{
  return Glib::wrap(gtk_drag_icon_get_child(gobj()));
}

auto DragIcon::get_child() const -> const Widget*
{
  return const_cast<DragIcon*>(this)->get_child();
}

auto DragIcon::set_from_paintable (
  const Glib::RefPtr <Gdk::Drag> &drag, const Glib::RefPtr <Gdk::Paintable> &paintable, const int hot_x, const int hot_y) -> void
{
  gtk_drag_icon_set_from_paintable(Glib::unwrap(drag), Glib::unwrap(paintable), hot_x, hot_y);
}

auto DragIcon::create_widget_for_value(const Glib::ValueBase& value) -> Widget*
{
  return Glib::wrap(gtk_drag_icon_create_widget_for_value(value.gobj()));
}


auto DragIcon::property_child() -> Glib::PropertyProxy< Widget* >
{
  return {this, "child"};
}

auto DragIcon::property_child() const -> Glib::PropertyProxy_ReadOnly< Widget* >
{
  return {this, "child"};
}


} // namespace Gtk

