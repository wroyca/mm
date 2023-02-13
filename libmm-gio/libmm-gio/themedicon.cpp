


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/themedicon.hpp>
#include <libmm-gio/themedicon_p.hpp>


/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>

namespace Gio
{

ThemedIcon::ThemedIcon(const Glib::ustring& iconname, const bool use_default_fallbacks)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(themedicon_class_.init(), "name",iconname.c_str(),"use-default-fallbacks",gboolean(use_default_fallbacks), nullptr))
{
}

ThemedIcon::ThemedIcon(const std::vector<Glib::ustring>& iconnames)
: // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(themedicon_class_.init(), "names",Glib::ArrayHandler<Glib::ustring>::vector_to_array(iconnames).data(), nullptr))
{
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GThemedIcon* object, const bool take_copy) -> RefPtr<Gio::ThemedIcon>
{
  return Glib::make_refptr_for_instance<Gio::ThemedIcon>( dynamic_cast<Gio::ThemedIcon*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ThemedIcon_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ThemedIcon_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_themed_icon_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Icon::add_interface(get_type());

  }

  return *this;
}


auto ThemedIcon_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ThemedIcon_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ThemedIcon((GThemedIcon*)object);
}


/* The implementation: */

auto ThemedIcon::gobj_copy() -> GThemedIcon*
{
  reference();
  return gobj();
}

ThemedIcon::ThemedIcon(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ThemedIcon::ThemedIcon(GThemedIcon* castitem)
: Object((GObject*)castitem)
{}


ThemedIcon::ThemedIcon(ThemedIcon&& src) noexcept
: Object(std::move(src))
  , Icon(std::move(src))
{}

auto ThemedIcon::operator=(ThemedIcon&& src) noexcept -> ThemedIcon&
{
  Object::operator=(std::move(src));
  Icon::operator=(std::move(src));
  return *this;
}


ThemedIcon::~ThemedIcon() noexcept = default;

ThemedIcon::CppClassType ThemedIcon::themedicon_class_; // initialize static member

auto ThemedIcon::get_type() -> GType
{
  return themedicon_class_.init().get_type();
}


auto ThemedIcon::get_base_type() -> GType
{
  return g_themed_icon_get_type();
}


auto ThemedIcon::create(const Glib::ustring& iconname, const bool use_default_fallbacks) -> Glib::RefPtr<ThemedIcon>
{
  return Glib::make_refptr_for_instance<ThemedIcon>( new ThemedIcon(iconname, use_default_fallbacks) );
}

auto ThemedIcon::create(const std::vector<Glib::ustring>& iconnames) -> Glib::RefPtr<ThemedIcon>
{
  return Glib::make_refptr_for_instance<ThemedIcon>( new ThemedIcon(iconnames) );
}

auto ThemedIcon::prepend_name (const Glib::ustring &iconname) -> void
{
  g_themed_icon_prepend_name(gobj(), iconname.c_str());
}

auto ThemedIcon::append_name (const Glib::ustring &iconname) -> void
{
  g_themed_icon_append_name(gobj(), iconname.c_str());
}

auto ThemedIcon::get_names() const -> std::vector<Glib::ustring>
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_themed_icon_get_names(const_cast<GThemedIcon*>(gobj())), Glib::OWNERSHIP_NONE);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<std::vector<Glib::ustring>>::value,
  "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ThemedIcon::property_names() const -> Glib::PropertyProxy_ReadOnly< std::vector<Glib::ustring> >
{
  return {this, "names"};
}

auto ThemedIcon::property_use_default_fallbacks() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-default-fallbacks"};
}


} // namespace Gio


