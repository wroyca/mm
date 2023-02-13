


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/fontset.hpp>
#include <libmm-pango/fontset_p.hpp>


/*
 * Copyright 2001      The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

static auto fontset_foreach_callback(PangoFontset* /* fontset */, PangoFont* font, const gpointer data) -> gboolean
{
  try
  {
    const auto& slot = *static_cast<Pango::Fontset::ForeachSlot*>(data);
    const auto cppFont = Glib::wrap(font, true /* take_copy */);

    return slot(cppFont);
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return false; //arbitrary default
}


namespace Pango
{

auto Fontset::foreach (const ForeachSlot &slot) -> void
{
  pango_fontset_foreach(gobj(), &fontset_foreach_callback, (void*)&slot);
}

} //namespace

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(PangoFontset* object, const bool take_copy) -> RefPtr<Pango::Fontset>
{
  return Glib::make_refptr_for_instance<Pango::Fontset>( dynamic_cast<Pango::Fontset*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto Fontset_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Fontset_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_fontset_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Fontset_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Fontset_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Fontset((PangoFontset*)object);
}


/* The implementation: */

auto Fontset::gobj_copy() -> PangoFontset*
{
  reference();
  return gobj();
}

Fontset::Fontset(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Fontset::Fontset(PangoFontset* castitem)
: Object((GObject*)castitem)
{}


Fontset::Fontset(Fontset&& src) noexcept
: Object(std::move(src))
{}

auto Fontset::operator=(Fontset&& src) noexcept -> Fontset&
{
  Object::operator=(std::move(src));
  return *this;
}


Fontset::~Fontset() noexcept = default;

Fontset::CppClassType Fontset::fontset_class_; // initialize static member

auto Fontset::get_type() -> GType
{
  return fontset_class_.init().get_type();
}


auto Fontset::get_base_type() -> GType
{
  return pango_fontset_get_type();
}


auto Fontset::get_font(
  const guint wc) const -> Glib::RefPtr<Font>
{
  return Glib::wrap(pango_fontset_get_font(const_cast<PangoFontset*>(gobj()), wc));
}

auto Fontset::get_metrics() const -> FontMetrics
{
  return FontMetrics(pango_fontset_get_metrics(const_cast<PangoFontset*>(gobj())));
}


} // namespace Pango


