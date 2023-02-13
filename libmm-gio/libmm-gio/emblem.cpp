


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/emblem.hpp>
#include <mm/gio/private/emblem_p.hpp>


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

using Origin = Gio::Emblem::Origin;

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GEmblem* object, const bool take_copy) -> RefPtr<Gio::Emblem>
{
  return Glib::make_refptr_for_instance<Gio::Emblem>( dynamic_cast<Gio::Emblem*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto Emblem_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Emblem_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_emblem_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Icon::add_interface(get_type());

  }

  return *this;
}


auto Emblem_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Emblem_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Emblem((GEmblem*)object);
}


/* The implementation: */

auto Emblem::gobj_copy() -> GEmblem*
{
  reference();
  return gobj();
}

Emblem::Emblem(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Emblem::Emblem(GEmblem* castitem)
: Object((GObject*)castitem)
{}


Emblem::Emblem(Emblem&& src) noexcept
: Object(std::move(src))
  , Icon(std::move(src))
{}

auto Emblem::operator=(Emblem&& src) noexcept -> Emblem&
{
  Object::operator=(std::move(src));
  Icon::operator=(std::move(src));
  return *this;
}


Emblem::~Emblem() noexcept = default;

Emblem::CppClassType Emblem::emblem_class_; // initialize static member

auto Emblem::get_type() -> GType
{
  return emblem_class_.init().get_type();
}


auto Emblem::get_base_type() -> GType
{
  return g_emblem_get_type();
}


Emblem::Emblem(const Glib::RefPtr<Icon>& icon)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(emblem_class_.init(), "icon", Glib::unwrap(icon), nullptr))
{


}

Emblem::Emblem(const Glib::RefPtr<Icon>& icon, const Origin origin)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(emblem_class_.init(), "icon", Glib::unwrap(icon), "origin", origin, nullptr))
{


}

auto Emblem::create(const Glib::RefPtr<Icon>& icon) -> Glib::RefPtr<Emblem>
{
  return Glib::make_refptr_for_instance<Emblem>( new Emblem(icon) );
}

auto Emblem::create(const Glib::RefPtr<Icon>& icon, const Origin origin) -> Glib::RefPtr<Emblem>
{
  return Glib::make_refptr_for_instance<Emblem>( new Emblem(icon, origin) );
}

auto Emblem::get_icon() -> Glib::RefPtr<Icon>
{
  return Glib::wrap(g_emblem_get_icon(gobj()));
}

auto Emblem::get_icon() const -> Glib::RefPtr<const Icon>
{
  return const_cast<Emblem*>(this)->get_icon();
}

auto Emblem::get_origin() const -> Origin
{
  return static_cast<Origin>(g_emblem_get_origin(const_cast<GEmblem*>(gobj())));
}


} // namespace Gio


