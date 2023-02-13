


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/text.hxx>
#include <libmm-gtk/text_p.hxx>


/* Copyright (C) 2019 The gtkmm Development Team
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

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkText* object, const bool take_copy) -> Gtk::Text*
{
  return dynamic_cast<Gtk::Text *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Text_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Text_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_text_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Editable::add_interface(get_type());

  }

  return *this;
}


auto Text_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Text_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Text((GtkText*)o));

}


/* The implementation: */

Text::Text(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Text::Text(GtkText* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Text::Text(Text&& src) noexcept
: Widget(std::move(src))
  , Editable(std::move(src))
{}

auto Text::operator=(Text&& src) noexcept -> Text&
{
  Widget::operator=(std::move(src));
  Editable::operator=(std::move(src));
  return *this;
}

Text::~Text() noexcept
{
  destroy_();
}

Text::CppClassType Text::text_class_; // initialize static member

auto Text::get_type() -> GType
{
  return text_class_.init().get_type();
}


auto Text::get_base_type() -> GType
{
  return gtk_text_get_type();
}


Text::Text()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(text_class_.init()))
{


}

Text::Text(const Glib::RefPtr<EntryBuffer>& buffer)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(text_class_.init(), "buffer", Glib::unwrap(buffer), nullptr))
{


}

auto Text::get_buffer() -> Glib::RefPtr<EntryBuffer>
{
  auto retvalue = Glib::wrap(gtk_text_get_buffer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Text::get_buffer() const -> Glib::RefPtr<const EntryBuffer>
{
  return const_cast<Text*>(this)->get_buffer();
}

auto Text::set_buffer (const Glib::RefPtr <EntryBuffer> &buffer) -> void
{
  gtk_text_set_buffer(gobj(), Glib::unwrap(buffer));
}

auto Text::set_visibility (
  const bool visible) -> void
{
  gtk_text_set_visibility(gobj(), visible);
}

auto Text::get_visibility() const -> bool
{
  return gtk_text_get_visibility(const_cast<GtkText*>(gobj()));
}

auto Text::set_invisible_char (
  const gunichar ch) -> void
{
  gtk_text_set_invisible_char(gobj(), ch);
}

auto Text::unset_invisible_char () -> void
{
  gtk_text_unset_invisible_char(gobj());
}

auto Text::get_invisible_char() const -> gunichar
{
  return gtk_text_get_invisible_char(const_cast<GtkText*>(gobj()));
}

auto Text::set_overwrite_mode (
  const bool overwrite) -> void
{
  gtk_text_set_overwrite_mode(gobj(), overwrite);
}

auto Text::get_overwrite_mode() const -> bool
{
  return gtk_text_get_overwrite_mode(const_cast<GtkText*>(gobj()));
}

auto Text::set_max_length (
  const int max) -> void
{
  gtk_text_set_max_length(gobj(), max);
}

auto Text::get_max_length() const -> int
{
  return gtk_text_get_max_length(const_cast<GtkText*>(gobj()));
}

auto Text::get_text_length() const -> guint16
{
  return gtk_text_get_text_length(const_cast<GtkText*>(gobj()));
}

auto Text::set_activates_default (
  const bool setting) -> void
{
  gtk_text_set_activates_default(gobj(), setting);
}

auto Text::get_activates_default() const -> bool
{
  return gtk_text_get_activates_default(const_cast<GtkText*>(gobj()));
}

auto Text::get_placeholder_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_text_get_placeholder_text(const_cast<GtkText*>(gobj())));
}

auto Text::set_placeholder_text (const Glib::ustring &text) -> void
{
  gtk_text_set_placeholder_text(gobj(), text.c_str());
}

auto Text::set_input_purpose (InputPurpose purpose) -> void
{
  gtk_text_set_input_purpose(gobj(), static_cast<GtkInputPurpose>(purpose));
}

auto Text::get_input_purpose() const -> InputPurpose
{
  return static_cast<InputPurpose>(gtk_text_get_input_purpose(const_cast<GtkText*>(gobj())));
}

auto Text::set_input_hints (InputHints hints) -> void
{
  gtk_text_set_input_hints(gobj(), static_cast<GtkInputHints>(hints));
}

auto Text::get_input_hints() const -> InputHints
{
  return static_cast<InputHints>(gtk_text_get_input_hints(const_cast<GtkText*>(gobj())));
}

auto Text::set_attributes (Pango::AttrList &attrs) -> void
{
  gtk_text_set_attributes(gobj(), attrs.gobj());
}

auto Text::get_attributes() const -> Pango::AttrList
{
  return Pango::AttrList(gtk_text_get_attributes(const_cast<GtkText*>(gobj())));
}

auto Text::set_tabs (const Pango::TabArray &tabs) -> void
{
  gtk_text_set_tabs(gobj(), const_cast<Pango::TabArray&>(tabs).gobj());
}

auto Text::get_tabs() const -> Pango::TabArray
{
  return Pango::TabArray(gtk_text_get_tabs(const_cast<GtkText*>(gobj())));
}

auto Text::grab_focus_without_selecting() -> bool
{
  return gtk_text_grab_focus_without_selecting(gobj());
}

auto Text::set_extra_menu (const Glib::RefPtr <Gio::MenuModel> &model) -> void
{
  gtk_text_set_extra_menu(gobj(), Glib::unwrap(model));
}

auto Text::get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_text_get_extra_menu(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Text::get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<Text*>(this)->get_extra_menu();
}

auto Text::set_enable_emoji_completion (
  const bool enable_emoji_completion) -> void
{
  gtk_text_set_enable_emoji_completion(gobj(), enable_emoji_completion);
}

auto Text::get_enable_emoji_completion() const -> bool
{
  return gtk_text_get_enable_emoji_completion(const_cast<GtkText*>(gobj()));
}

auto Text::set_propagate_text_width (
  const bool propagate_text_width) -> void
{
  gtk_text_set_propagate_text_width(gobj(), propagate_text_width);
}

auto Text::get_propagate_text_width() const -> bool
{
  return gtk_text_get_propagate_text_width(const_cast<GtkText*>(gobj()));
}

auto Text::set_truncate_multiline (
  const bool truncate_multiline) -> void
{
  gtk_text_set_truncate_multiline(gobj(), truncate_multiline);
}

auto Text::get_truncate_multiline() const -> bool
{
  return gtk_text_get_truncate_multiline(const_cast<GtkText*>(gobj()));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<EntryBuffer>>::value,
  "Type Glib::RefPtr<EntryBuffer> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_buffer() -> Glib::PropertyProxy< Glib::RefPtr<EntryBuffer> >
{
  return {this, "buffer"};
}

auto Text::property_buffer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryBuffer> >
{
  return {this, "buffer"};
}

auto Text::property_max_length() -> Glib::PropertyProxy< int >
{
  return {this, "max-length"};
}

auto Text::property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-length"};
}

auto Text::property_visibility() -> Glib::PropertyProxy< bool >
{
  return {this, "visibility"};
}

auto Text::property_visibility() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "visibility"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<gunichar>::value,
  "Type gunichar cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_invisible_char() -> Glib::PropertyProxy< gunichar >
{
  return {this, "invisible-char"};
}

auto Text::property_invisible_char() const -> Glib::PropertyProxy_ReadOnly< gunichar >
{
  return {this, "invisible-char"};
}

auto Text::property_invisible_char_set() -> Glib::PropertyProxy< bool >
{
  return {this, "invisible-char-set"};
}

auto Text::property_invisible_char_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "invisible-char-set"};
}

auto Text::property_activates_default() -> Glib::PropertyProxy< bool >
{
  return {this, "activates-default"};
}

auto Text::property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activates-default"};
}

auto Text::property_scroll_offset() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "scroll-offset"};
}

auto Text::property_truncate_multiline() -> Glib::PropertyProxy< bool >
{
  return {this, "truncate-multiline"};
}

auto Text::property_truncate_multiline() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "truncate-multiline"};
}

auto Text::property_overwrite_mode() -> Glib::PropertyProxy< bool >
{
  return {this, "overwrite-mode"};
}

auto Text::property_overwrite_mode() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "overwrite-mode"};
}

auto Text::property_im_module() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "im-module"};
}

auto Text::property_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "im-module"};
}

auto Text::property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto Text::property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "placeholder-text"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
  "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_input_purpose() -> Glib::PropertyProxy< InputPurpose >
{
  return {this, "input-purpose"};
}

auto Text::property_input_purpose() const -> Glib::PropertyProxy_ReadOnly< InputPurpose >
{
  return {this, "input-purpose"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
  "Type InputHints cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_input_hints() -> Glib::PropertyProxy< InputHints >
{
  return {this, "input-hints"};
}

auto Text::property_input_hints() const -> Glib::PropertyProxy_ReadOnly< InputHints >
{
  return {this, "input-hints"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
  "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_attributes() -> Glib::PropertyProxy< Pango::AttrList >
{
  return {this, "attributes"};
}

auto Text::property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >
{
  return {this, "attributes"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
  "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_tabs() -> Glib::PropertyProxy< Pango::TabArray >
{
  return {this, "tabs"};
}

auto Text::property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >
{
  return {this, "tabs"};
}

auto Text::property_enable_emoji_completion() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-emoji-completion"};
}

auto Text::property_enable_emoji_completion() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-emoji-completion"};
}

auto Text::property_propagate_text_width() -> Glib::PropertyProxy< bool >
{
  return {this, "propagate-text-width"};
}

auto Text::property_propagate_text_width() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "propagate-text-width"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Text::property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}

auto Text::property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}


} // namespace Gtk


