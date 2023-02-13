


#include <libmm-glib/mm-glib.hpp>

#include <libmm-pango/context.hpp>
#include <libmm-pango/context_p.hpp>


/*
 * Copyright 1998-1999 The Gtk-- Development Team
 * Copyright 2001      Free Software Foundation
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

#include <pango/pangocairo.h>

namespace Pango
{

auto Context::list_families() const -> std::vector<Glib::RefPtr<FontFamily>>
{
  //Get array:
  PangoFontFamily** pFamilies = nullptr;
  int n_families = 0;
  pango_context_list_families(const_cast<PangoContext*>(gobj()), &pFamilies, &n_families);

  return Glib::ArrayHandler<Glib::RefPtr<FontFamily>>::array_to_vector
      (pFamilies, n_families, Glib::OWNERSHIP_SHALLOW);
}

auto Context::get_metrics(const FontDescription& desc) const -> FontMetrics
{
  return FontMetrics(pango_context_get_metrics(const_cast<PangoContext*>(gobj()), desc.gobj(), nullptr));
}

struct ItemTraits
{
  typedef Item CppType;
  typedef const PangoItem*  CType;
  typedef PangoItem*        CTypeNonConst;

  static auto   to_c_type      (const CppType& obj) -> CType { return obj.gobj(); }
  static auto   to_c_type      (const CType ptr) -> CType { return ptr; }
  static auto to_cpp_type    (const CType ptr) -> CppType { return CppType(const_cast<CTypeNonConst>(ptr), true); }
  static auto release_c_type (const CType ptr) -> void { pango_item_free(const_cast<CTypeNonConst>(ptr)); }
};

using ListHandler_Item = Glib::ListHandler<Item, ItemTraits>;

auto Context::itemize(const Glib::ustring& text, const AttrList& attrs) const -> std::vector<Item>
{
  return ListHandler_Item::list_to_vector(
      pango_itemize(const_cast<PangoContext*>(gobj()),
                    text.c_str(), 0, text.bytes(),
                    const_cast<PangoAttrList*>(attrs.gobj()), nullptr),
      Glib::OWNERSHIP_DEEP);
}

auto Context::itemize(const Glib::ustring& text, const int start_index, const int length,
                                 const AttrList& attrs, AttrIter& cached_iter) const -> std::vector<Item>
{
  return ListHandler_Item::list_to_vector(
      pango_itemize(const_cast<PangoContext*>(gobj()),
                    text.c_str(), start_index, length,
                    const_cast<PangoAttrList*>(attrs.gobj()), cached_iter.gobj()),
      Glib::OWNERSHIP_DEEP);
}

auto Context::update_from_cairo_context (const Cairo::RefPtr <Cairo::Context> &context) -> void
{
  pango_cairo_update_context(context->cobj(), gobj());
}

auto Context::get_matrix() const -> Matrix
{
  const auto* matrix = pango_context_get_matrix(const_cast<PangoContext*>(gobj()));
  if(matrix)
    return *matrix;
  else
  {
    const PangoMatrix identity_transform = PANGO_MATRIX_INIT;
    return identity_transform;
  }
}

} /* namespace Pango */

namespace
{
} // anonymous namespace

// static
auto Glib::Value<Pango::Direction>::value_type() -> GType
{
  return pango_direction_get_type();
}

// static
auto Glib::Value<Pango::GravityHint>::value_type() -> GType
{
  return pango_gravity_hint_get_type();
}


namespace Glib
{

auto wrap(PangoContext* object, const bool take_copy) -> RefPtr<Pango::Context>
{
  return Glib::make_refptr_for_instance<Pango::Context>( dynamic_cast<Pango::Context*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Pango
{


/* The *_Class implementation: */

auto Context_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Context_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(pango_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto Context_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Context_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Context((PangoContext*)object);
}


/* The implementation: */

auto Context::gobj_copy() -> PangoContext*
{
  reference();
  return gobj();
}

Context::Context(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

Context::Context(PangoContext* castitem)
: Object((GObject*)castitem)
{}


Context::Context(Context&& src) noexcept
: Object(std::move(src))
{}

auto Context::operator=(Context&& src) noexcept -> Context&
{
  Object::operator=(std::move(src));
  return *this;
}


Context::~Context() noexcept = default;

Context::CppClassType Context::context_class_; // initialize static member

auto Context::get_type() -> GType
{
  return context_class_.init().get_type();
}


auto Context::get_base_type() -> GType
{
  return pango_context_get_type();
}


Context::Context()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(context_class_.init()))
{


}

auto Context::set_font_map (const Glib::RefPtr <FontMap> &font_map) -> void
{
  pango_context_set_font_map(gobj(), Glib::unwrap(font_map));
}

auto Context::get_font_map() -> Glib::RefPtr<FontMap>
{
  auto retvalue = Glib::wrap(pango_context_get_font_map(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Context::get_font_map() const -> Glib::RefPtr<const FontMap>
{
  return const_cast<Context*>(this)->get_font_map();
}

auto Context::get_serial() const -> guint
{
  return pango_context_get_serial(const_cast<PangoContext*>(gobj()));
}

auto Context::load_font(const FontDescription& desc) const -> Glib::RefPtr<Font>
{
  return Glib::wrap(pango_context_load_font(const_cast<PangoContext*>(gobj()), desc.gobj()));
}

auto Context::load_fontset(const FontDescription& desc, const Language& language) const -> Glib::RefPtr<Fontset>
{
  return Glib::wrap(pango_context_load_fontset(const_cast<PangoContext*>(gobj()), desc.gobj(), const_cast<PangoLanguage*>(language.gobj())));
}

auto Context::get_metrics(const FontDescription& desc, const Language& language) const -> FontMetrics
{
  return FontMetrics(pango_context_get_metrics(const_cast<PangoContext*>(gobj()), desc.gobj(), const_cast<PangoLanguage*>(language.gobj())));
}

auto Context::set_font_description (const FontDescription &desc) -> void
{
  pango_context_set_font_description(gobj(), desc.gobj());
}

auto Context::get_font_description() const -> FontDescription
{
  return FontDescription(pango_context_get_font_description(const_cast<PangoContext*>(gobj())));
}

auto Context::get_language() const -> Language
{
  return Language(pango_context_get_language(const_cast<PangoContext*>(gobj())));
}

auto Context::set_language (const Language &language) -> void
{
  pango_context_set_language(gobj(), const_cast<PangoLanguage*>(language.gobj()));
}

auto Context::set_base_dir (Direction direction) -> void
{
  pango_context_set_base_dir(gobj(), static_cast<PangoDirection>(direction));
}

auto Context::get_base_dir() const -> Direction
{
  return static_cast<Direction>(pango_context_get_base_dir(const_cast<PangoContext*>(gobj())));
}

auto Context::set_base_gravity (Gravity gravity) -> void
{
  pango_context_set_base_gravity(gobj(), static_cast<PangoGravity>(gravity));
}

auto Context::get_base_gravity() const -> Gravity
{
  return static_cast<Gravity>(pango_context_get_base_gravity(const_cast<PangoContext*>(gobj())));
}

auto Context::get_gravity() const -> Gravity
{
  return static_cast<Gravity>(pango_context_get_gravity(const_cast<PangoContext*>(gobj())));
}

auto Context::set_gravity_hint (GravityHint hint) -> void
{
  pango_context_set_gravity_hint(gobj(), static_cast<PangoGravityHint>(hint));
}

auto Context::get_gravity_hint() const -> GravityHint
{
  return static_cast<GravityHint>(pango_context_get_gravity_hint(const_cast<PangoContext*>(gobj())));
}

auto Context::set_matrix (const Matrix &matrix) -> void
{
  pango_context_set_matrix(gobj(), &matrix);
}

auto Context::set_cairo_font_options (const Cairo::FontOptions &options) -> void
{
  pango_cairo_context_set_font_options(gobj(), options.cobj());
}

auto Context::get_font_options() const -> Cairo::FontOptions
{
  return Cairo::FontOptions(const_cast< cairo_font_options_t*>(pango_cairo_context_get_font_options(const_cast<PangoContext*>(gobj()))), false /* take_copy */);
}

auto Context::set_resolution (
  const double dpi) -> void
{
  pango_cairo_context_set_resolution(gobj(), dpi);
}

auto Context::get_resolution() const -> double
{
  return pango_cairo_context_get_resolution(const_cast<PangoContext*>(gobj()));
}


} // namespace Pango


