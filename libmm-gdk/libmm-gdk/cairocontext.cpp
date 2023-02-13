


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/cairocontext.hpp>
#include <libmm-gdk/cairocontext_p.hpp>


/* Copyright (C) 2018 The gtkmm Development Team
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

#include <gdk/gdk.h>
#include <libmm-gdk/cairoutils.hpp>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GdkCairoContext* object, const bool take_copy) -> RefPtr<Gdk::CairoContext>
{
  return Glib::make_refptr_for_instance<Gdk::CairoContext>( dynamic_cast<Gdk::CairoContext*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto CairoContext_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CairoContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_cairo_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CairoContext_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CairoContext_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new CairoContext((GdkCairoContext*)object);
}


/* The implementation: */

auto CairoContext::gobj_copy() -> GdkCairoContext*
{
  reference();
  return gobj();
}

CairoContext::CairoContext(const Glib::ConstructParams& construct_params)
: DrawContext(construct_params)
{

}

CairoContext::CairoContext(GdkCairoContext* castitem)
: DrawContext((GdkDrawContext*)castitem)
{}


CairoContext::CairoContext(CairoContext&& src) noexcept
: DrawContext(std::move(src))
{}

auto CairoContext::operator=(CairoContext&& src) noexcept -> CairoContext&
{
  DrawContext::operator=(std::move(src));
  return *this;
}


CairoContext::~CairoContext() noexcept = default;

CairoContext::CppClassType CairoContext::cairocontext_class_; // initialize static member

auto CairoContext::get_type() -> GType
{
  return cairocontext_class_.init().get_type();
}


auto CairoContext::get_base_type() -> GType
{
  return gdk_cairo_context_get_type();
}


CairoContext::CairoContext()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
DrawContext(Glib::ConstructParams(cairocontext_class_.init()))
{


}

auto CairoContext::cairo_create() -> ::Cairo::RefPtr< ::Cairo::Context>
{
  return Cairo::wrap(gdk_cairo_context_cairo_create(gobj()));
}


} // namespace Gdk


