


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/centerbox.hxx>
#include <libmm-gtk/centerbox_p.hxx>


/* Copyright (C) 2017 The gtkmm Development Team
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
auto CenterBox::unset_start_widget () -> void
{
  gtk_center_box_set_start_widget(gobj(), nullptr);
}

auto CenterBox::unset_center_widget () -> void
{
  gtk_center_box_set_center_widget(gobj(), nullptr);
}

auto CenterBox::unset_end_widget () -> void
{
  gtk_center_box_set_end_widget(gobj(), nullptr);
}
} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCenterBox* object, const bool take_copy) -> Gtk::CenterBox*
{
  return dynamic_cast<Gtk::CenterBox *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CenterBox_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CenterBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_center_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto CenterBox_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CenterBox_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CenterBox((GtkCenterBox*)o));

}


/* The implementation: */

CenterBox::CenterBox(const Glib::ConstructParams& construct_params)
:
  Widget(construct_params)
{
  }

CenterBox::CenterBox(GtkCenterBox* castitem)
:
  Widget((GtkWidget*)castitem)
{
  }


CenterBox::CenterBox(CenterBox&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto CenterBox::operator=(CenterBox&& src) noexcept -> CenterBox&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

CenterBox::~CenterBox() noexcept
{
  destroy_();
}

CenterBox::CppClassType CenterBox::centerbox_class_; // initialize static member

auto CenterBox::get_type() -> GType
{
  return centerbox_class_.init().get_type();
}


auto CenterBox::get_base_type() -> GType
{
  return gtk_center_box_get_type();
}


CenterBox::CenterBox()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(centerbox_class_.init()))
{


}

auto CenterBox::set_start_widget (Widget &child) -> void
{
  gtk_center_box_set_start_widget(gobj(), child.gobj());
}

auto CenterBox::get_start_widget() -> Widget*
{
  return Glib::wrap(gtk_center_box_get_start_widget(gobj()));
}

auto CenterBox::get_start_widget() const -> const Widget*
{
  return const_cast<CenterBox*>(this)->get_start_widget();
}

auto CenterBox::set_center_widget (Widget &child) -> void
{
  gtk_center_box_set_center_widget(gobj(), child.gobj());
}

auto CenterBox::get_center_widget() -> Widget*
{
  return Glib::wrap(gtk_center_box_get_center_widget(gobj()));
}

auto CenterBox::get_center_widget() const -> const Widget*
{
  return const_cast<CenterBox*>(this)->get_center_widget();
}

auto CenterBox::set_end_widget (Widget &child) -> void
{
  gtk_center_box_set_end_widget(gobj(), child.gobj());
}

auto CenterBox::get_end_widget() -> Widget*
{
  return Glib::wrap(gtk_center_box_get_end_widget(gobj()));
}

auto CenterBox::get_end_widget() const -> const Widget*
{
  return const_cast<CenterBox*>(this)->get_end_widget();
}

auto CenterBox::set_baseline_position (BaselinePosition position) -> void
{
  gtk_center_box_set_baseline_position(gobj(), static_cast<GtkBaselinePosition>(position));
}

auto CenterBox::get_baseline_position() -> BaselinePosition
{
  return static_cast<BaselinePosition>(gtk_center_box_get_baseline_position(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<BaselinePosition>::value,
  "Type BaselinePosition cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CenterBox::property_baseline_position() -> Glib::PropertyProxy< BaselinePosition >
{
  return {this, "baseline-position"};
}

auto CenterBox::property_baseline_position() const -> Glib::PropertyProxy_ReadOnly< BaselinePosition >
{
  return {this, "baseline-position"};
}


} // namespace Gtk


