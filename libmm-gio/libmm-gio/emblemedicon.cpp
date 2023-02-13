


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gio/emblemedicon.hpp>
#include <libmm-gio/emblemedicon_p.hpp>


/* Copyright (C) 2008 Jonathon Jongsma
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

EmblemedIcon::EmblemedIcon(const Glib::RefPtr<Icon>& icon) : // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  ObjectBase(nullptr),
  Object(Glib::ConstructParams(emblemedicon_class_.init(), "icon",Glib::unwrap(icon), nullptr))
{
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GEmblemedIcon* object, const bool take_copy) -> RefPtr<Gio::EmblemedIcon>
{
  return Glib::make_refptr_for_instance<Gio::EmblemedIcon>( dynamic_cast<Gio::EmblemedIcon*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto EmblemedIcon_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &EmblemedIcon_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_emblemed_icon_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Icon::add_interface(get_type());

  }

  return *this;
}


auto EmblemedIcon_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto EmblemedIcon_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new EmblemedIcon((GEmblemedIcon*)object);
}


/* The implementation: */

auto EmblemedIcon::gobj_copy() -> GEmblemedIcon*
{
  reference();
  return gobj();
}

EmblemedIcon::EmblemedIcon(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

EmblemedIcon::EmblemedIcon(GEmblemedIcon* castitem)
: Object((GObject*)castitem)
{}


EmblemedIcon::EmblemedIcon(EmblemedIcon&& src) noexcept
: Object(std::move(src))
  , Icon(std::move(src))
{}

auto EmblemedIcon::operator=(EmblemedIcon&& src) noexcept -> EmblemedIcon&
{
  Object::operator=(std::move(src));
  Icon::operator=(std::move(src));
  return *this;
}


EmblemedIcon::~EmblemedIcon() noexcept = default;

EmblemedIcon::CppClassType EmblemedIcon::emblemedicon_class_; // initialize static member

auto EmblemedIcon::get_type() -> GType
{
  return emblemedicon_class_.init().get_type();
}


auto EmblemedIcon::get_base_type() -> GType
{
  return g_emblemed_icon_get_type();
}


EmblemedIcon::EmblemedIcon(const Glib::RefPtr<Icon>& icon, const Glib::RefPtr<Emblem>& emblem)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(emblemedicon_class_.init(), "icon", Glib::unwrap(icon), "emblem", Glib::unwrap(emblem), nullptr))
{


}

auto EmblemedIcon::create(const Glib::RefPtr<Icon>& icon, const Glib::RefPtr<Emblem>& emblem) -> Glib::RefPtr<EmblemedIcon>
{
  return Glib::make_refptr_for_instance<EmblemedIcon>( new EmblemedIcon(icon, emblem) );
}

auto EmblemedIcon::create(const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<EmblemedIcon>
{
  return Glib::make_refptr_for_instance<EmblemedIcon>( new EmblemedIcon(icon) );
}

auto EmblemedIcon::get_icon() -> Glib::RefPtr<Icon>
{
  return Glib::wrap(g_emblemed_icon_get_icon(gobj()));
}

auto EmblemedIcon::get_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<EmblemedIcon*>(this)->get_icon();
}

auto EmblemedIcon::get_emblems() -> std::vector<Glib::RefPtr<Emblem>>
{
  return Glib::ListHandler<Glib::RefPtr<Emblem>>::list_to_vector(g_emblemed_icon_get_emblems(gobj()), Glib::OWNERSHIP_NONE);
}

auto EmblemedIcon::get_emblems() const -> std::vector<Glib::RefPtr<const Emblem>>
{
  return Glib::ListHandler<Glib::RefPtr<const Emblem>>::list_to_vector(g_emblemed_icon_get_emblems(const_cast<GEmblemedIcon*>(gobj())), Glib::OWNERSHIP_NONE);
}

auto EmblemedIcon::add_emblem (const Glib::RefPtr <Emblem> &emblem) -> void
{
  g_emblemed_icon_add_emblem(gobj(), Glib::unwrap(emblem));
}

auto EmblemedIcon::clear_emblems () -> void
{
  g_emblemed_icon_clear_emblems(gobj());
}


} // namespace Gio


