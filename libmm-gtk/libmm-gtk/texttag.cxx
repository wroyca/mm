


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/texttag.hxx>
#include <libmm-gtk/texttag_p.hxx>


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

#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTextTag* object, const bool take_copy) -> RefPtr<Gtk::TextTag>
{
  return Glib::make_refptr_for_instance<Gtk::TextTag>( dynamic_cast<Gtk::TextTag*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto TextTag_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TextTag_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_text_tag_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto TextTag_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto TextTag_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TextTag((GtkTextTag*)object);
}


/* The implementation: */

auto TextTag::gobj_copy() -> GtkTextTag*
{
  reference();
  return gobj();
}

TextTag::TextTag(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

TextTag::TextTag(GtkTextTag* castitem)
: Object((GObject*)castitem)
{}


TextTag::TextTag(TextTag&& src) noexcept
: Object(std::move(src))
{}

auto TextTag::operator=(TextTag&& src) noexcept -> TextTag&
{
  Object::operator=(std::move(src));
  return *this;
}


TextTag::~TextTag() noexcept = default;

TextTag::CppClassType TextTag::texttag_class_; // initialize static member

auto TextTag::get_type() -> GType
{
  return texttag_class_.init().get_type();
}


auto TextTag::get_base_type() -> GType
{
  return gtk_text_tag_get_type();
}


TextTag::TextTag()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(texttag_class_.init()))
{


}

TextTag::TextTag(const Glib::ustring& name)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(texttag_class_.init(), "name", name.c_str(), nullptr))
{


}

auto TextTag::create() -> Glib::RefPtr<TextTag>
{
  return Glib::make_refptr_for_instance<TextTag>( new TextTag() );
}

auto TextTag::create(const Glib::ustring& name) -> Glib::RefPtr<TextTag>
{
  return Glib::make_refptr_for_instance<TextTag>( new TextTag(name) );
}

auto TextTag::get_priority() const -> int
{
  return gtk_text_tag_get_priority(const_cast<GtkTextTag*>(gobj()));
}

auto TextTag::set_priority (
  const int priority) -> void
{
  gtk_text_tag_set_priority(gobj(), priority);
}

auto TextTag::tag_changed (
  const bool size_changed) -> void
{
  gtk_text_tag_changed(gobj(), size_changed);
}


auto TextTag::property_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "name"};
}

auto TextTag::property_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return {this, "background"};
}

auto TextTag::property_foreground() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return {this, "foreground"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "background-rgba"};
}

auto TextTag::property_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "background-rgba"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_foreground_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "foreground-rgba"};
}

auto TextTag::property_foreground_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "foreground-rgba"};
}

auto TextTag::property_font() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "font"};
}

auto TextTag::property_font() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "font"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::FontDescription>::value,
  "Type Pango::FontDescription cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_font_desc() -> Glib::PropertyProxy< Pango::FontDescription >
{
  return {this, "font-desc"};
}

auto TextTag::property_font_desc() const -> Glib::PropertyProxy_ReadOnly< Pango::FontDescription >
{
  return {this, "font-desc"};
}

auto TextTag::property_family() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "family"};
}

auto TextTag::property_family() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "family"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Style>::value,
  "Type Pango::Style cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_style() -> Glib::PropertyProxy< Pango::Style >
{
  return {this, "style"};
}

auto TextTag::property_style() const -> Glib::PropertyProxy_ReadOnly< Pango::Style >
{
  return {this, "style"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Variant>::value,
  "Type Pango::Variant cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_variant() -> Glib::PropertyProxy< Pango::Variant >
{
  return {this, "variant"};
}

auto TextTag::property_variant() const -> Glib::PropertyProxy_ReadOnly< Pango::Variant >
{
  return {this, "variant"};
}

auto TextTag::property_weight() -> Glib::PropertyProxy< int >
{
  return {this, "weight"};
}

auto TextTag::property_weight() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "weight"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Stretch>::value,
  "Type Pango::Stretch cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_stretch() -> Glib::PropertyProxy< Pango::Stretch >
{
  return {this, "stretch"};
}

auto TextTag::property_stretch() const -> Glib::PropertyProxy_ReadOnly< Pango::Stretch >
{
  return {this, "stretch"};
}

auto TextTag::property_size() -> Glib::PropertyProxy< int >
{
  return {this, "size"};
}

auto TextTag::property_size() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "size"};
}

auto TextTag::property_size_points() -> Glib::PropertyProxy< double >
{
  return {this, "size-points"};
}

auto TextTag::property_size_points() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "size-points"};
}

auto TextTag::property_scale() -> Glib::PropertyProxy< double >
{
  return {this, "scale"};
}

auto TextTag::property_scale() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "scale"};
}

auto TextTag::property_pixels_above_lines() -> Glib::PropertyProxy< int >
{
  return {this, "pixels-above-lines"};
}

auto TextTag::property_pixels_above_lines() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pixels-above-lines"};
}

auto TextTag::property_pixels_below_lines() -> Glib::PropertyProxy< int >
{
  return {this, "pixels-below-lines"};
}

auto TextTag::property_pixels_below_lines() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pixels-below-lines"};
}

auto TextTag::property_pixels_inside_wrap() -> Glib::PropertyProxy< int >
{
  return {this, "pixels-inside-wrap"};
}

auto TextTag::property_pixels_inside_wrap() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "pixels-inside-wrap"};
}

auto TextTag::property_editable() -> Glib::PropertyProxy< bool >
{
  return {this, "editable"};
}

auto TextTag::property_editable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "editable"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<WrapMode>::value,
  "Type WrapMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_wrap_mode() -> Glib::PropertyProxy< WrapMode >
{
  return {this, "wrap-mode"};
}

auto TextTag::property_wrap_mode() const -> Glib::PropertyProxy_ReadOnly< WrapMode >
{
  return {this, "wrap-mode"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Justification>::value,
  "Type Justification cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_justification() -> Glib::PropertyProxy< Justification >
{
  return {this, "justification"};
}

auto TextTag::property_justification() const -> Glib::PropertyProxy_ReadOnly< Justification >
{
  return {this, "justification"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
  "Type TextDirection cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_direction() -> Glib::PropertyProxy< TextDirection >
{
  return {this, "direction"};
}

auto TextTag::property_direction() const -> Glib::PropertyProxy_ReadOnly< TextDirection >
{
  return {this, "direction"};
}

auto TextTag::property_left_margin() -> Glib::PropertyProxy< int >
{
  return {this, "left-margin"};
}

auto TextTag::property_left_margin() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "left-margin"};
}

auto TextTag::property_indent() -> Glib::PropertyProxy< int >
{
  return {this, "indent"};
}

auto TextTag::property_indent() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "indent"};
}

auto TextTag::property_line_height() -> Glib::PropertyProxy< float >
{
  return {this, "line-height"};
}

auto TextTag::property_line_height() const -> Glib::PropertyProxy_ReadOnly< float >
{
  return {this, "line-height"};
}

auto TextTag::property_strikethrough() -> Glib::PropertyProxy< bool >
{
  return {this, "strikethrough"};
}

auto TextTag::property_strikethrough() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "strikethrough"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_strikethrough_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "strikethrough-rgba"};
}

auto TextTag::property_strikethrough_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "strikethrough-rgba"};
}

auto TextTag::property_right_margin() -> Glib::PropertyProxy< int >
{
  return {this, "right-margin"};
}

auto TextTag::property_right_margin() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "right-margin"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Underline>::value,
  "Type Pango::Underline cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_underline() -> Glib::PropertyProxy< Pango::Underline >
{
  return {this, "underline"};
}

auto TextTag::property_underline() const -> Glib::PropertyProxy_ReadOnly< Pango::Underline >
{
  return {this, "underline"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_underline_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "underline-rgba"};
}

auto TextTag::property_underline_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "underline-rgba"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::Overline>::value,
  "Type Pango::Overline cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_overline() -> Glib::PropertyProxy< Pango::Overline >
{
  return {this, "overline"};
}

auto TextTag::property_overline() const -> Glib::PropertyProxy_ReadOnly< Pango::Overline >
{
  return {this, "overline"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_overline_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "overline-rgba"};
}

auto TextTag::property_overline_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "overline-rgba"};
}

auto TextTag::property_rise() -> Glib::PropertyProxy< int >
{
  return {this, "rise"};
}

auto TextTag::property_rise() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "rise"};
}

auto TextTag::property_background_full_height() -> Glib::PropertyProxy< bool >
{
  return {this, "background-full-height"};
}

auto TextTag::property_background_full_height() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "background-full-height"};
}

auto TextTag::property_language() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "language"};
}

auto TextTag::property_language() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "language"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
  "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_tabs() -> Glib::PropertyProxy< Pango::TabArray >
{
  return {this, "tabs"};
}

auto TextTag::property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >
{
  return {this, "tabs"};
}

auto TextTag::property_invisible() -> Glib::PropertyProxy< bool >
{
  return {this, "invisible"};
}

auto TextTag::property_invisible() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "invisible"};
}

auto TextTag::property_paragraph_background() -> Glib::PropertyProxy_WriteOnly< Glib::ustring >
{
  return {this, "paragraph-background"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Gdk::RGBA>::value,
  "Type Gdk::RGBA cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_paragraph_background_rgba() -> Glib::PropertyProxy< Gdk::RGBA >
{
  return {this, "paragraph-background-rgba"};
}

auto TextTag::property_paragraph_background_rgba() const -> Glib::PropertyProxy_ReadOnly< Gdk::RGBA >
{
  return {this, "paragraph-background-rgba"};
}

auto TextTag::property_font_features() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "font-features"};
}

auto TextTag::property_font_features() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "font-features"};
}

auto TextTag::property_allow_breaks() -> Glib::PropertyProxy< bool >
{
  return {this, "allow-breaks"};
}

auto TextTag::property_allow_breaks() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "allow-breaks"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::ShowFlags>::value,
  "Type Pango::ShowFlags cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_show_spaces() -> Glib::PropertyProxy< Pango::ShowFlags >
{
  return {this, "show-spaces"};
}

auto TextTag::property_show_spaces() const -> Glib::PropertyProxy_ReadOnly< Pango::ShowFlags >
{
  return {this, "show-spaces"};
}

auto TextTag::property_insert_hyphens() -> Glib::PropertyProxy< bool >
{
  return {this, "insert-hyphens"};
}

auto TextTag::property_insert_hyphens() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "insert-hyphens"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TextTransform>::value,
  "Type Pango::TextTransform cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto TextTag::property_text_transform() -> Glib::PropertyProxy< Pango::TextTransform >
{
  return {this, "text-transform"};
}

auto TextTag::property_text_transform() const -> Glib::PropertyProxy_ReadOnly< Pango::TextTransform >
{
  return {this, "text-transform"};
}

auto TextTag::property_word() -> Glib::PropertyProxy< bool >
{
  return {this, "word"};
}

auto TextTag::property_word() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "word"};
}

auto TextTag::property_sentence() -> Glib::PropertyProxy< bool >
{
  return {this, "sentence"};
}

auto TextTag::property_sentence() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "sentence"};
}

auto TextTag::property_accumulative_margin() -> Glib::PropertyProxy< bool >
{
  return {this, "accumulative-margin"};
}

auto TextTag::property_accumulative_margin() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "accumulative-margin"};
}

auto TextTag::property_background_set() -> Glib::PropertyProxy< bool >
{
  return {this, "background-set"};
}

auto TextTag::property_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "background-set"};
}

auto TextTag::property_foreground_set() -> Glib::PropertyProxy< bool >
{
  return {this, "foreground-set"};
}

auto TextTag::property_foreground_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "foreground-set"};
}

auto TextTag::property_family_set() -> Glib::PropertyProxy< bool >
{
  return {this, "family-set"};
}

auto TextTag::property_family_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "family-set"};
}

auto TextTag::property_style_set() -> Glib::PropertyProxy< bool >
{
  return {this, "style-set"};
}

auto TextTag::property_style_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "style-set"};
}

auto TextTag::property_variant_set() -> Glib::PropertyProxy< bool >
{
  return {this, "variant-set"};
}

auto TextTag::property_variant_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "variant-set"};
}

auto TextTag::property_weight_set() -> Glib::PropertyProxy< bool >
{
  return {this, "weight-set"};
}

auto TextTag::property_weight_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "weight-set"};
}

auto TextTag::property_stretch_set() -> Glib::PropertyProxy< bool >
{
  return {this, "stretch-set"};
}

auto TextTag::property_stretch_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "stretch-set"};
}

auto TextTag::property_size_set() -> Glib::PropertyProxy< bool >
{
  return {this, "size-set"};
}

auto TextTag::property_size_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "size-set"};
}

auto TextTag::property_scale_set() -> Glib::PropertyProxy< bool >
{
  return {this, "scale-set"};
}

auto TextTag::property_scale_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "scale-set"};
}

auto TextTag::property_pixels_above_lines_set() -> Glib::PropertyProxy< bool >
{
  return {this, "pixels-above-lines-set"};
}

auto TextTag::property_pixels_above_lines_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "pixels-above-lines-set"};
}

auto TextTag::property_pixels_below_lines_set() -> Glib::PropertyProxy< bool >
{
  return {this, "pixels-below-lines-set"};
}

auto TextTag::property_pixels_below_lines_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "pixels-below-lines-set"};
}

auto TextTag::property_pixels_inside_wrap_set() -> Glib::PropertyProxy< bool >
{
  return {this, "pixels-inside-wrap-set"};
}

auto TextTag::property_pixels_inside_wrap_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "pixels-inside-wrap-set"};
}

auto TextTag::property_editable_set() -> Glib::PropertyProxy< bool >
{
  return {this, "editable-set"};
}

auto TextTag::property_editable_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "editable-set"};
}

auto TextTag::property_wrap_mode_set() -> Glib::PropertyProxy< bool >
{
  return {this, "wrap-mode-set"};
}

auto TextTag::property_wrap_mode_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "wrap-mode-set"};
}

auto TextTag::property_justification_set() -> Glib::PropertyProxy< bool >
{
  return {this, "justification-set"};
}

auto TextTag::property_justification_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "justification-set"};
}

auto TextTag::property_left_margin_set() -> Glib::PropertyProxy< bool >
{
  return {this, "left-margin-set"};
}

auto TextTag::property_left_margin_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "left-margin-set"};
}

auto TextTag::property_indent_set() -> Glib::PropertyProxy< bool >
{
  return {this, "indent-set"};
}

auto TextTag::property_indent_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "indent-set"};
}

auto TextTag::property_line_height_set() -> Glib::PropertyProxy< bool >
{
  return {this, "line-height-set"};
}

auto TextTag::property_line_height_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "line-height-set"};
}

auto TextTag::property_strikethrough_set() -> Glib::PropertyProxy< bool >
{
  return {this, "strikethrough-set"};
}

auto TextTag::property_strikethrough_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "strikethrough-set"};
}

auto TextTag::property_strikethrough_rgba_set() -> Glib::PropertyProxy< bool >
{
  return {this, "strikethrough-rgba-set"};
}

auto TextTag::property_strikethrough_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "strikethrough-rgba-set"};
}

auto TextTag::property_right_margin_set() -> Glib::PropertyProxy< bool >
{
  return {this, "right-margin-set"};
}

auto TextTag::property_right_margin_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "right-margin-set"};
}

auto TextTag::property_underline_set() -> Glib::PropertyProxy< bool >
{
  return {this, "underline-set"};
}

auto TextTag::property_underline_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "underline-set"};
}

auto TextTag::property_underline_rgba_set() -> Glib::PropertyProxy< bool >
{
  return {this, "underline-rgba-set"};
}

auto TextTag::property_underline_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "underline-rgba-set"};
}

auto TextTag::property_overline_set() -> Glib::PropertyProxy< bool >
{
  return {this, "overline-set"};
}

auto TextTag::property_overline_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "overline-set"};
}

auto TextTag::property_overline_rgba_set() -> Glib::PropertyProxy< bool >
{
  return {this, "overline-rgba-set"};
}

auto TextTag::property_overline_rgba_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "overline-rgba-set"};
}

auto TextTag::property_rise_set() -> Glib::PropertyProxy< bool >
{
  return {this, "rise-set"};
}

auto TextTag::property_rise_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "rise-set"};
}

auto TextTag::property_background_full_height_set() -> Glib::PropertyProxy< bool >
{
  return {this, "background-full-height-set"};
}

auto TextTag::property_background_full_height_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "background-full-height-set"};
}

auto TextTag::property_language_set() -> Glib::PropertyProxy< bool >
{
  return {this, "language-set"};
}

auto TextTag::property_language_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "language-set"};
}

auto TextTag::property_tabs_set() -> Glib::PropertyProxy< bool >
{
  return {this, "tabs-set"};
}

auto TextTag::property_tabs_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "tabs-set"};
}

auto TextTag::property_invisible_set() -> Glib::PropertyProxy< bool >
{
  return {this, "invisible-set"};
}

auto TextTag::property_invisible_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "invisible-set"};
}

auto TextTag::property_paragraph_background_set() -> Glib::PropertyProxy< bool >
{
  return {this, "paragraph-background-set"};
}

auto TextTag::property_paragraph_background_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "paragraph-background-set"};
}

auto TextTag::property_fallback() -> Glib::PropertyProxy< bool >
{
  return {this, "fallback"};
}

auto TextTag::property_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "fallback"};
}

auto TextTag::property_fallback_set() -> Glib::PropertyProxy< bool >
{
  return {this, "fallback-set"};
}

auto TextTag::property_fallback_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "fallback-set"};
}

auto TextTag::property_letter_spacing() -> Glib::PropertyProxy< int >
{
  return {this, "letter-spacing"};
}

auto TextTag::property_letter_spacing() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "letter-spacing"};
}

auto TextTag::property_letter_spacing_set() -> Glib::PropertyProxy< bool >
{
  return {this, "letter-spacing-set"};
}

auto TextTag::property_letter_spacing_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "letter-spacing-set"};
}

auto TextTag::property_font_features_set() -> Glib::PropertyProxy< bool >
{
  return {this, "font-features-set"};
}

auto TextTag::property_font_features_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "font-features-set"};
}

auto TextTag::property_allow_breaks_set() -> Glib::PropertyProxy< bool >
{
  return {this, "allow-breaks-set"};
}

auto TextTag::property_allow_breaks_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "allow-breaks-set"};
}

auto TextTag::property_show_spaces_set() -> Glib::PropertyProxy< bool >
{
  return {this, "show-spaces-set"};
}

auto TextTag::property_show_spaces_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-spaces-set"};
}

auto TextTag::property_insert_hyphens_set() -> Glib::PropertyProxy< bool >
{
  return {this, "insert-hyphens-set"};
}

auto TextTag::property_insert_hyphens_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "insert-hyphens-set"};
}

auto TextTag::property_text_transform_set() -> Glib::PropertyProxy< bool >
{
  return {this, "text-transform-set"};
}

auto TextTag::property_text_transform_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "text-transform-set"};
}

auto TextTag::property_word_set() -> Glib::PropertyProxy< bool >
{
  return {this, "word-set"};
}

auto TextTag::property_word_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "word-set"};
}

auto TextTag::property_sentence_set() -> Glib::PropertyProxy< bool >
{
  return {this, "sentence-set"};
}

auto TextTag::property_sentence_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "sentence-set"};
}


} // namespace Gtk


