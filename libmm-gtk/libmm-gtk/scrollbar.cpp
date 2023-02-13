


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/scrollbar.hpp>
#include <mm/gtk/private/scrollbar_p.hpp>


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

#include <mm/gtk/adjustment.hpp>

#include <gtk/gtk.h>

namespace Gtk
{

Scrollbar::Scrollbar(const Glib::RefPtr<Adjustment>& adjustment, const Orientation orientation)
:
// Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(scrollbar_class_.init(), "adjustment",Glib::unwrap(adjustment),"orientation",orientation, nullptr))
{
}

auto Scrollbar::unset_adjustment () -> void
{
  gtk_scrollbar_set_adjustment(gobj(), nullptr);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkScrollbar* object, const bool take_copy) -> Gtk::Scrollbar*
{
  return dynamic_cast<Gtk::Scrollbar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Scrollbar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Scrollbar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_scrollbar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto Scrollbar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Scrollbar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Scrollbar((GtkScrollbar*)o));

}


/* The implementation: */

Scrollbar::Scrollbar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Scrollbar::Scrollbar(GtkScrollbar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Scrollbar::Scrollbar(Scrollbar&& src) noexcept
: Widget(std::move(src))
  , Orientable(std::move(src))
{}

auto Scrollbar::operator=(Scrollbar&& src) noexcept -> Scrollbar&
{
  Widget::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

Scrollbar::~Scrollbar() noexcept
{
  destroy_();
}

Scrollbar::CppClassType Scrollbar::scrollbar_class_; // initialize static member

auto Scrollbar::get_type() -> GType
{
  return scrollbar_class_.init().get_type();
}


auto Scrollbar::get_base_type() -> GType
{
  return gtk_scrollbar_get_type();
}


Scrollbar::Scrollbar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(scrollbar_class_.init()))
{


}

auto Scrollbar::set_adjustment (const Glib::RefPtr <Adjustment> &adjustment) -> void
{
  gtk_scrollbar_set_adjustment(gobj(), Glib::unwrap(adjustment));
}

auto Scrollbar::get_adjustment() -> Glib::RefPtr<Adjustment>
{
  auto retvalue = Glib::wrap(gtk_scrollbar_get_adjustment(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Scrollbar::get_adjustment() const -> Glib::RefPtr<const Adjustment>
{
  return const_cast<Scrollbar*>(this)->get_adjustment();
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Adjustment>>::value,
  "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Scrollbar::property_adjustment() -> Glib::PropertyProxy< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}

auto Scrollbar::property_adjustment() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Adjustment> >
{
  return {this, "adjustment"};
}


} // namespace Gtk


