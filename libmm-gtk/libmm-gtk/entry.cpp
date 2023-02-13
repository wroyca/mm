


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/entry.hpp>
#include <mm/gtk/private/entry_p.hpp>


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

using IconPosition = Gtk::Entry::IconPosition;

namespace Gtk
{

auto Entry::set_icon_from_icon_name (const Glib::ustring &icon_name, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_from_icon_name(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), icon_name.c_str());
}

auto Entry::set_icon_from_gicon (
  const Glib::RefPtr <Gio::Icon> &icon, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_from_gicon(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), Glib::unwrap<Gio::Icon>(icon));
}

auto Entry::unset_icon (IconPosition icon_pos) -> void
{
  //We could use any one of these set_icon_from_* functions:
  gtk_entry_set_icon_from_paintable(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), nullptr);
}

auto Entry::set_icon_activatable (
  const bool activatable, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_activatable(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), activatable);
}

auto Entry::set_icon_tooltip_text (const Glib::ustring &tooltip, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_tooltip_text(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), tooltip.c_str());
}

auto Entry::set_icon_tooltip_markup (const Glib::ustring &tooltip, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_tooltip_markup(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), tooltip.c_str());
}

auto Entry::get_icon_area(IconPosition icon_pos) const -> Gdk::Rectangle
{
  Gdk::Rectangle result;
  gtk_entry_get_icon_area(const_cast<GtkEntry*>(gobj()), (GtkEntryIconPosition)icon_pos, result.gobj());
  return result;
}

} //namespace Gtk

namespace
{


const Glib::SignalProxyInfo Entry_signal_activate_info =
{
  "activate",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto Entry_signal_icon_release_callback (
  GtkEntry *self, GtkEntryIconPosition p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(IconPosition)>;

  const auto obj = dynamic_cast<Entry*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<IconPosition>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Entry_signal_icon_release_info =
{
  "icon-release",
  (GCallback) &Entry_signal_icon_release_callback,
  (GCallback) &Entry_signal_icon_release_callback
};


auto Entry_signal_icon_press_callback (GtkEntry *self, GtkEntryIconPosition p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(IconPosition)>;

  const auto obj = dynamic_cast<Entry*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(static_cast<IconPosition>(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo Entry_signal_icon_press_info =
{
  "icon-press",
  (GCallback) &Entry_signal_icon_press_callback,
  (GCallback) &Entry_signal_icon_press_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gtk::Entry::IconPosition>::value_type() -> GType
{
  return gtk_entry_icon_position_get_type();
}


namespace Glib
{

auto wrap(GtkEntry* object, const bool take_copy) -> Gtk::Entry*
{
  return dynamic_cast<Gtk::Entry *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto Entry_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Entry_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_entry_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Editable::add_interface(get_type());
  CellEditable::add_interface(get_type());

  }

  return *this;
}


auto Entry_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto Entry_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new Entry((GtkEntry*)o));

}


/* The implementation: */

Entry::Entry(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

Entry::Entry(GtkEntry* castitem)
: Widget((GtkWidget*)castitem)
{
  }


Entry::Entry(Entry&& src) noexcept
: Widget(std::move(src))
  , Editable(std::move(src))
  , CellEditable(std::move(src))
{}

auto Entry::operator=(Entry&& src) noexcept -> Entry&
{
  Widget::operator=(std::move(src));
  Editable::operator=(std::move(src));
  CellEditable::operator=(std::move(src));
  return *this;
}

Entry::~Entry() noexcept
{
  destroy_();
}

Entry::CppClassType Entry::entry_class_; // initialize static member

auto Entry::get_type() -> GType
{
  return entry_class_.init().get_type();
}


auto Entry::get_base_type() -> GType
{
  return gtk_entry_get_type();
}


Entry::Entry()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(entry_class_.init()))
{


}

Entry::Entry(const Glib::RefPtr<EntryBuffer>& buffer)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(entry_class_.init(), "buffer", Glib::unwrap(buffer), nullptr))
{


}

auto Entry::get_buffer() -> Glib::RefPtr<EntryBuffer>
{
  auto retvalue = Glib::wrap(gtk_entry_get_buffer(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Entry::get_buffer() const -> Glib::RefPtr<const EntryBuffer>
{
  return const_cast<Entry*>(this)->get_buffer();
}

auto Entry::set_buffer (const Glib::RefPtr <EntryBuffer> &buffer) -> void
{
  gtk_entry_set_buffer(gobj(), Glib::unwrap(buffer));
}

auto Entry::set_visibility (
  const bool visible) -> void
{
  gtk_entry_set_visibility(gobj(), visible);
}

auto Entry::get_visibility() const -> bool
{
  return gtk_entry_get_visibility(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_invisible_char (
  const gunichar ch) -> void
{
  gtk_entry_set_invisible_char(gobj(), ch);
}

auto Entry::unset_invisible_char () -> void
{
  gtk_entry_unset_invisible_char(gobj());
}

auto Entry::get_invisible_char() const -> gunichar
{
  return gtk_entry_get_invisible_char(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_has_frame (
  const bool setting) -> void
{
  gtk_entry_set_has_frame(gobj(), setting);
}

auto Entry::get_has_frame() const -> bool
{
  return gtk_entry_get_has_frame(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_overwrite_mode (
  const bool overwrite) -> void
{
  gtk_entry_set_overwrite_mode(gobj(), overwrite);
}

auto Entry::get_overwrite_mode() const -> bool
{
  return gtk_entry_get_overwrite_mode(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_max_length (
  const int max) -> void
{
  gtk_entry_set_max_length(gobj(), max);
}

auto Entry::get_max_length() const -> int
{
  return gtk_entry_get_max_length(const_cast<GtkEntry*>(gobj()));
}

auto Entry::get_text_length() const -> guint16
{
  return gtk_entry_get_text_length(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_activates_default (
  const bool setting) -> void
{
  gtk_entry_set_activates_default(gobj(), setting);
}

auto Entry::get_activates_default() const -> gboolean
{
  return gtk_entry_get_activates_default(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_alignment (
  const float xalign) -> void
{
  gtk_entry_set_alignment(gobj(), xalign);
}

auto Entry::set_alignment (
  const Align xalign) -> void
{
  gtk_entry_set_alignment(gobj(), _gtkmm_align_float_from_enum(xalign));
}

auto Entry::get_alignment() const -> float
{
  return gtk_entry_get_alignment(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_completion (const Glib::RefPtr <EntryCompletion> &completion) -> void
{
  gtk_entry_set_completion(gobj(), Glib::unwrap(completion));
}

auto Entry::get_completion() -> Glib::RefPtr<EntryCompletion>
{
  auto retvalue = Glib::wrap(gtk_entry_get_completion(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Entry::get_completion() const -> Glib::RefPtr<const EntryCompletion>
{
  return const_cast<Entry*>(this)->get_completion();
}

auto Entry::set_progress_fraction (
  const double fraction) -> void
{
  gtk_entry_set_progress_fraction(gobj(), fraction);
}

auto Entry::get_progress_fraction() const -> double
{
  return gtk_entry_get_progress_fraction(const_cast<GtkEntry*>(gobj()));
}

auto Entry::set_progress_pulse_step (
  const double fraction) -> void
{
  gtk_entry_set_progress_pulse_step(gobj(), fraction);
}

auto Entry::get_progress_pulse_step() -> double
{
  return gtk_entry_get_progress_pulse_step(gobj());
}

auto Entry::progress_pulse () -> void
{
  gtk_entry_progress_pulse(gobj());
}

auto Entry::get_placeholder_text() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_entry_get_placeholder_text(const_cast<GtkEntry*>(gobj())));
}

auto Entry::set_placeholder_text (const Glib::ustring &text) -> void
{
  gtk_entry_set_placeholder_text(gobj(), text.c_str());
}

auto Entry::set_icon_from_paintable (
  const Glib::RefPtr <Gdk::Paintable> &paintable, IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_from_paintable(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), Glib::unwrap(paintable));
}

auto Entry::get_icon_storage_type(IconPosition icon_pos) const -> Image::Type
{
  return static_cast<Image::Type>(gtk_entry_get_icon_storage_type(const_cast<GtkEntry*>(gobj()), static_cast<GtkEntryIconPosition>(icon_pos)));
}

auto Entry::get_icon_paintable(IconPosition icon_pos) -> Glib::RefPtr<Gdk::Paintable>
{
  auto retvalue = Glib::wrap(gtk_entry_get_icon_paintable(gobj(), static_cast<GtkEntryIconPosition>(icon_pos)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Entry::get_icon_paintable(
  const IconPosition icon_pos) const -> Glib::RefPtr<const Gdk::Paintable>
{
  return const_cast<Entry*>(this)->get_icon_paintable(icon_pos);
}

auto Entry::get_icon_name(IconPosition icon_pos) const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_entry_get_icon_name(const_cast<GtkEntry*>(gobj()), static_cast<GtkEntryIconPosition>(icon_pos)));
}

auto Entry::get_icon_gicon(IconPosition icon_pos) -> Glib::RefPtr<Gio::Icon>
{
  auto retvalue = Glib::wrap(gtk_entry_get_icon_gicon(gobj(), static_cast<GtkEntryIconPosition>(icon_pos)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Entry::get_icon_gicon(
  const IconPosition icon_pos) const -> Glib::RefPtr<const Gio::Icon>
{
  return const_cast<Entry*>(this)->get_icon_gicon(icon_pos);
}

auto Entry::get_icon_activatable(IconPosition icon_pos) const -> bool
{
  return gtk_entry_get_icon_activatable(const_cast<GtkEntry*>(gobj()), static_cast<GtkEntryIconPosition>(icon_pos));
}

auto Entry::set_icon_sensitive (IconPosition icon_pos, const bool sensitive) -> void
{
  gtk_entry_set_icon_sensitive(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), sensitive);
}

auto Entry::get_icon_sensitive(IconPosition icon_pos) -> bool
{
  return gtk_entry_get_icon_sensitive(gobj(), static_cast<GtkEntryIconPosition>(icon_pos));
}

auto Entry::get_icon_at_pos(
  const int x, const int y) const -> int
{
  return gtk_entry_get_icon_at_pos(const_cast<GtkEntry*>(gobj()), x, y);
}

auto Entry::get_icon_tooltip_text(IconPosition icon_pos) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_entry_get_icon_tooltip_text(const_cast<GtkEntry*>(gobj()), static_cast<GtkEntryIconPosition>(icon_pos)));
}

auto Entry::get_icon_tooltip_markup(IconPosition icon_pos) const -> Glib::ustring
{
  return Glib::convert_return_gchar_ptr_to_ustring(gtk_entry_get_icon_tooltip_markup(const_cast<GtkEntry*>(gobj()), static_cast<GtkEntryIconPosition>(icon_pos)));
}

auto Entry::set_icon_drag_source (
  const Glib::RefPtr <Gdk::ContentProvider> &provider, Gdk::DragAction actions,
  IconPosition icon_pos) -> void
{
  gtk_entry_set_icon_drag_source(gobj(), static_cast<GtkEntryIconPosition>(icon_pos), Glib::unwrap(provider), static_cast<GdkDragAction>(actions));
}

auto Entry::get_current_icon_drag_source() -> int
{
  return gtk_entry_get_current_icon_drag_source(gobj());
}

auto Entry::reset_im_context () -> void
{
  gtk_entry_reset_im_context(gobj());
}

auto Entry::set_input_purpose (InputPurpose purpose) -> void
{
  gtk_entry_set_input_purpose(gobj(), static_cast<GtkInputPurpose>(purpose));
}

auto Entry::get_input_purpose() const -> InputPurpose
{
  return static_cast<InputPurpose>(gtk_entry_get_input_purpose(const_cast<GtkEntry*>(gobj())));
}

auto Entry::set_input_hints (InputHints hints) -> void
{
  gtk_entry_set_input_hints(gobj(), static_cast<GtkInputHints>(hints));
}

auto Entry::get_input_hints() const -> InputHints
{
  return static_cast<InputHints>(gtk_entry_get_input_hints(const_cast<GtkEntry*>(gobj())));
}

auto Entry::set_attributes (Pango::AttrList &attrs) -> void
{
  gtk_entry_set_attributes(gobj(), attrs.gobj());
}

auto Entry::get_attributes() const -> Pango::AttrList
{
  return Pango::AttrList(gtk_entry_get_attributes(const_cast<GtkEntry*>(gobj())));
}

auto Entry::set_tabs (const Pango::TabArray &tabs) -> void
{
  gtk_entry_set_tabs(gobj(), const_cast<Pango::TabArray&>(tabs).gobj());
}

auto Entry::get_tabs() const -> Pango::TabArray
{
  return Pango::TabArray(gtk_entry_get_tabs(const_cast<GtkEntry*>(gobj())));
}

auto Entry::grab_focus_without_selecting () -> void
{
  gtk_entry_grab_focus_without_selecting(gobj());
}

auto Entry::set_extra_menu (const Glib::RefPtr <Gio::MenuModel> &model) -> void
{
  gtk_entry_set_extra_menu(gobj(), Glib::unwrap(model));
}

auto Entry::get_extra_menu() -> Glib::RefPtr<Gio::MenuModel>
{
  auto retvalue = Glib::wrap(gtk_entry_get_extra_menu(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto Entry::get_extra_menu() const -> Glib::RefPtr<const Gio::MenuModel>
{
  return const_cast<Entry*>(this)->get_extra_menu();
}


auto Entry::signal_activate() -> Glib::SignalProxy<void()>
{
  return {this, &Entry_signal_activate_info};
}


auto Entry::signal_icon_release() -> Glib::SignalProxy<void(IconPosition)>
{
  return {this, &Entry_signal_icon_release_info};
}


auto Entry::signal_icon_press() -> Glib::SignalProxy<void(IconPosition)>
{
  return {this, &Entry_signal_icon_press_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<EntryBuffer>>::value,
  "Type Glib::RefPtr<EntryBuffer> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_buffer() -> Glib::PropertyProxy< Glib::RefPtr<EntryBuffer> >
{
  return {this, "buffer"};
}

auto Entry::property_buffer() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryBuffer> >
{
  return {this, "buffer"};
}

auto Entry::property_max_length() -> Glib::PropertyProxy< int >
{
  return {this, "max-length"};
}

auto Entry::property_max_length() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "max-length"};
}

auto Entry::property_visibility() -> Glib::PropertyProxy< bool >
{
  return {this, "visibility"};
}

auto Entry::property_visibility() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "visibility"};
}

auto Entry::property_has_frame() -> Glib::PropertyProxy< bool >
{
  return {this, "has-frame"};
}

auto Entry::property_has_frame() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-frame"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<gunichar>::value,
  "Type gunichar cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_invisible_char() -> Glib::PropertyProxy< gunichar >
{
  return {this, "invisible-char"};
}

auto Entry::property_invisible_char() const -> Glib::PropertyProxy_ReadOnly< gunichar >
{
  return {this, "invisible-char"};
}

auto Entry::property_invisible_char_set() -> Glib::PropertyProxy< bool >
{
  return {this, "invisible-char-set"};
}

auto Entry::property_invisible_char_set() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "invisible-char-set"};
}

auto Entry::property_activates_default() -> Glib::PropertyProxy< bool >
{
  return {this, "activates-default"};
}

auto Entry::property_activates_default() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "activates-default"};
}

auto Entry::property_scroll_offset() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "scroll-offset"};
}

auto Entry::property_truncate_multiline() -> Glib::PropertyProxy< bool >
{
  return {this, "truncate-multiline"};
}

auto Entry::property_truncate_multiline() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "truncate-multiline"};
}

auto Entry::property_overwrite_mode() -> Glib::PropertyProxy< bool >
{
  return {this, "overwrite-mode"};
}

auto Entry::property_overwrite_mode() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "overwrite-mode"};
}

auto Entry::property_text_length() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "text-length"};
}

auto Entry::property_progress_fraction() -> Glib::PropertyProxy< double >
{
  return {this, "progress-fraction"};
}

auto Entry::property_progress_fraction() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "progress-fraction"};
}

auto Entry::property_progress_pulse_step() -> Glib::PropertyProxy< double >
{
  return {this, "progress-pulse-step"};
}

auto Entry::property_progress_pulse_step() const -> Glib::PropertyProxy_ReadOnly< double >
{
  return {this, "progress-pulse-step"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Paintable>>::value,
  "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_primary_icon_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "primary-icon-paintable"};
}

auto Entry::property_primary_icon_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "primary-icon-paintable"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::Paintable>>::value,
  "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_secondary_icon_paintable() -> Glib::PropertyProxy< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "secondary-icon-paintable"};
}

auto Entry::property_secondary_icon_paintable() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Paintable> >
{
  return {this, "secondary-icon-paintable"};
}

auto Entry::property_primary_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "primary-icon-name"};
}

auto Entry::property_primary_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "primary-icon-name"};
}

auto Entry::property_secondary_icon_name() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "secondary-icon-name"};
}

auto Entry::property_secondary_icon_name() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "secondary-icon-name"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Icon>>::value,
  "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_primary_icon_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >
{
  return {this, "primary-icon-gicon"};
}

auto Entry::property_primary_icon_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >
{
  return {this, "primary-icon-gicon"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::Icon>>::value,
  "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_secondary_icon_gicon() -> Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >
{
  return {this, "secondary-icon-gicon"};
}

auto Entry::property_secondary_icon_gicon() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >
{
  return {this, "secondary-icon-gicon"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
  "Type Image::Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_primary_icon_storage_type() const -> Glib::PropertyProxy_ReadOnly< Image::Type >
{
  return {this, "primary-icon-storage-type"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Image::Type>::value,
  "Type Image::Type cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_secondary_icon_storage_type() const -> Glib::PropertyProxy_ReadOnly< Image::Type >
{
  return {this, "secondary-icon-storage-type"};
}

auto Entry::property_primary_icon_activatable() -> Glib::PropertyProxy< bool >
{
  return {this, "primary-icon-activatable"};
}

auto Entry::property_primary_icon_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "primary-icon-activatable"};
}

auto Entry::property_secondary_icon_activatable() -> Glib::PropertyProxy< bool >
{
  return {this, "secondary-icon-activatable"};
}

auto Entry::property_secondary_icon_activatable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "secondary-icon-activatable"};
}

auto Entry::property_primary_icon_sensitive() -> Glib::PropertyProxy< bool >
{
  return {this, "primary-icon-sensitive"};
}

auto Entry::property_primary_icon_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "primary-icon-sensitive"};
}

auto Entry::property_secondary_icon_sensitive() -> Glib::PropertyProxy< bool >
{
  return {this, "secondary-icon-sensitive"};
}

auto Entry::property_secondary_icon_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "secondary-icon-sensitive"};
}

auto Entry::property_primary_icon_tooltip_text() -> Glib::PropertyProxy< bool >
{
  return {this, "primary-icon-tooltip-text"};
}

auto Entry::property_primary_icon_tooltip_text() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "primary-icon-tooltip-text"};
}

auto Entry::property_secondary_icon_tooltip_text() -> Glib::PropertyProxy< bool >
{
  return {this, "secondary-icon-tooltip-text"};
}

auto Entry::property_secondary_icon_tooltip_text() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "secondary-icon-tooltip-text"};
}

auto Entry::property_primary_icon_tooltip_markup() -> Glib::PropertyProxy< bool >
{
  return {this, "primary-icon-tooltip-markup"};
}

auto Entry::property_primary_icon_tooltip_markup() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "primary-icon-tooltip-markup"};
}

auto Entry::property_secondary_icon_tooltip_markup() -> Glib::PropertyProxy< bool >
{
  return {this, "secondary-icon-tooltip-markup"};
}

auto Entry::property_secondary_icon_tooltip_markup() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "secondary-icon-tooltip-markup"};
}

auto Entry::property_im_module() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "im-module"};
}

auto Entry::property_im_module() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "im-module"};
}

auto Entry::property_placeholder_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "placeholder-text"};
}

auto Entry::property_placeholder_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "placeholder-text"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<EntryCompletion>>::value,
  "Type Glib::RefPtr<EntryCompletion> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_completion() -> Glib::PropertyProxy< Glib::RefPtr<EntryCompletion> >
{
  return {this, "completion"};
}

auto Entry::property_completion() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<EntryCompletion> >
{
  return {this, "completion"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<InputPurpose>::value,
  "Type InputPurpose cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_input_purpose() -> Glib::PropertyProxy< InputPurpose >
{
  return {this, "input-purpose"};
}

auto Entry::property_input_purpose() const -> Glib::PropertyProxy_ReadOnly< InputPurpose >
{
  return {this, "input-purpose"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<InputHints>::value,
  "Type InputHints cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_input_hints() -> Glib::PropertyProxy< InputHints >
{
  return {this, "input-hints"};
}

auto Entry::property_input_hints() const -> Glib::PropertyProxy_ReadOnly< InputHints >
{
  return {this, "input-hints"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
  "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_attributes() -> Glib::PropertyProxy< Pango::AttrList >
{
  return {this, "attributes"};
}

auto Entry::property_attributes() const -> Glib::PropertyProxy_ReadOnly< Pango::AttrList >
{
  return {this, "attributes"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Pango::TabArray>::value,
  "Type Pango::TabArray cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_tabs() -> Glib::PropertyProxy< Pango::TabArray >
{
  return {this, "tabs"};
}

auto Entry::property_tabs() const -> Glib::PropertyProxy_ReadOnly< Pango::TabArray >
{
  return {this, "tabs"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::MenuModel>>::value,
  "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Entry::property_extra_menu() -> Glib::PropertyProxy< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}

auto Entry::property_extra_menu() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::MenuModel> >
{
  return {this, "extra-menu"};
}

auto Entry::property_show_emoji_icon() -> Glib::PropertyProxy< bool >
{
  return {this, "show-emoji-icon"};
}

auto Entry::property_show_emoji_icon() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-emoji-icon"};
}

auto Entry::property_enable_emoji_completion() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-emoji-completion"};
}

auto Entry::property_enable_emoji_completion() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-emoji-completion"};
}


} // namespace Gtk


