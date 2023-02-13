


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/scale.hxx>
#include <libmm-gtk/scale_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <libmm-gtk/adjustment.hxx>

#include <gtk/gtk.h>
#include <math.h>
#include <cstring> //For strlen()
#include <memory>

using std::strlen;

namespace
{

auto SignalProxy_Scale_format_value_callback(GtkScale* /* scale */, const double value, const gpointer user_data) -> char*
{
  const auto the_slot = static_cast<Gtk::Scale::SlotFormatValue*>(user_data);

  try
  {
    return g_strdup((*the_slot)(value).c_str());
  }
  catch (...)
  {
    Glib::exception_handlers_invoke();
  }
  return g_strdup("?");
}

} // anonymous namespace

namespace Gtk
{

Scale::Scale(const Orientation orientation)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Range(Glib::ConstructParams(scale_class_.init(), "orientation",orientation, nullptr))
{
}

Scale::Scale(const Glib::RefPtr<Adjustment>& adjustment, const Orientation orientation)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Range(Glib::ConstructParams(scale_class_.init(), "adjustment",Glib::unwrap(adjustment),"orientation",orientation, nullptr))
{
}

auto Scale::set_format_value_func (const SlotFormatValue &slot) -> void
{
  // Create a copy of the slot object. A pointer to this will be passed
  // through the callback's data parameter. It will be deleted
  // when Glib::destroy_notify_delete<SlotFormatValue> is called.
  const auto slot_copy = new SlotFormatValue(slot);

  gtk_scale_set_format_value_func(gobj(),
    &SignalProxy_Scale_format_value_callback, slot_copy,
    &Glib::destroy_notify_delete<SlotFormatValue>);
}

auto Scale::unset_format_value_func () -> void
{
  gtk_scale_set_format_value_func(gobj(), nullptr, nullptr, nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkScale* object, const bool take_copy) -> Gtk::Scale*
{
  return dynamic_cast<Gtk::Scale *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Scale_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Scale_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_scale_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Scale_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Scale_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Scale((GtkScale*)o));

}


/* The implementation: */

Scale::Scale(const Glib::ConstructParams& construct_params)
: Range(construct_params)
{
  }

Scale::Scale(GtkScale* castitem)
: Range((GtkRange*)castitem)
{
  }


Scale::Scale(Scale&& src) noexcept
: Range(std::move(src))
{}

auto Scale::operator=(Scale&& src) noexcept -> Scale&
{
  Range::operator=(std::move(src));
  return *this;
}

Scale::~Scale() noexcept
{
  destroy_();
}

Scale::CppClassType Scale::scale_class_; // initialize static member

auto Scale::get_type() -> GType
{
  return scale_class_.init().get_type();
}


auto Scale::get_base_type() -> GType
{
  return gtk_scale_get_type();
}


Scale::Scale()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Range(Glib::ConstructParams(scale_class_.init()))
{


}

auto Scale::set_digits (
  const int digits) -> void
{
  gtk_scale_set_digits(gobj(), digits);
}

auto Scale::get_digits() const -> int
{
  return gtk_scale_get_digits(const_cast<GtkScale*>(gobj()));
}

auto Scale::set_draw_value (
  const bool draw_value) -> void
{
  gtk_scale_set_draw_value(gobj(), draw_value);
}

auto Scale::get_draw_value() const -> bool
{
  return gtk_scale_get_draw_value(const_cast<GtkScale*>(gobj()));
}

auto Scale::set_value_pos (PositionType pos) -> void
{
  gtk_scale_set_value_pos(gobj(), static_cast<GtkPositionType>(pos));
}

auto Scale::get_value_pos() const -> PositionType
{
  return static_cast<PositionType>(gtk_scale_get_value_pos(const_cast<GtkScale*>(gobj())));
}

auto Scale::set_has_origin (
  const bool has_origin) -> void
{
  gtk_scale_set_has_origin(gobj(), has_origin);
}

auto Scale::get_has_origin() const -> bool
{
  return gtk_scale_get_has_origin(const_cast<GtkScale*>(gobj()));
}

auto Scale::get_layout() -> Glib::RefPtr<Pango::Layout>
{
  auto retvalue = Glib::wrap(gtk_scale_get_layout(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Scale::get_layout() const -> Glib::RefPtr<const Pango::Layout>
{
  return const_cast<Scale*>(this)->get_layout();
}

auto Scale::get_layout_offsets (int &x, int &y) const -> void
{
  gtk_scale_get_layout_offsets(const_cast<GtkScale*>(gobj()), &x, &y);
}

auto Scale::add_mark (
  const double value, PositionType position, const Glib::ustring &markup) -> void
{
  gtk_scale_add_mark(gobj(), value, static_cast<GtkPositionType>(position), markup.c_str());
}

auto Scale::clear_marks () -> void
{
  gtk_scale_clear_marks(gobj());
}


auto Scale::property_digits() -> Glib::PropertyProxy< int >
{
  return {this, "digits"};
}

auto Scale::property_digits() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "digits"};
}

auto Scale::property_draw_value() -> Glib::PropertyProxy< bool >
{
  return {this, "draw-value"};
}

auto Scale::property_draw_value() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "draw-value"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<PositionType>::value,
  "Type PositionType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scale::property_value_pos() -> Glib::PropertyProxy< PositionType >
{
  return {this, "value-pos"};
}

auto Scale::property_value_pos() const -> Glib::PropertyProxy_ReadOnly< PositionType >
{
  return {this, "value-pos"};
}

auto Scale::property_has_origin() -> Glib::PropertyProxy< bool >
{
  return {this, "has-origin"};
}

auto Scale::property_has_origin() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-origin"};
}


} // namespace Gtk


