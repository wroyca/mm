// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/entryrow.hxx>
#include <libmm-adw/entryrow_p.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo EntryRow_signal_apply_info = {
      "apply",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static const Glib::SignalProxyInfo EntryRow_signal_entry_activated_info = {
      "entry-activated",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace Glib
{

  auto
  wrap (AdwEntryRow* object, bool take_copy) -> Adw::EntryRow*
  {
    return dynamic_cast<Adw::EntryRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  EntryRow_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &EntryRow_Class::class_init_function;

      register_derived_type (adw_entry_row_get_type ());

      Gtk::Editable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  EntryRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  EntryRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new EntryRow ((AdwEntryRow*) (o)));
  }

  EntryRow::EntryRow (const Glib::ConstructParams& construct_params)
    : Adw::PreferencesRow (construct_params)
  {
  }

  EntryRow::EntryRow (AdwEntryRow* castitem)
    : Adw::PreferencesRow ((AdwPreferencesRow*) (castitem))
  {
  }

  EntryRow::EntryRow (EntryRow&& src) noexcept
    : Adw::PreferencesRow (std::move (src)),
      Gtk::Editable (std::move (src))
  {
  }

  auto
  EntryRow::operator= (EntryRow&& src) noexcept -> EntryRow&
  {
    Adw::PreferencesRow::operator= (std::move (src));
    Gtk::Editable::operator= (std::move (src));
    return *this;
  }

  EntryRow::~EntryRow () noexcept
  {
    destroy_ ();
  }

  EntryRow::CppClassType EntryRow::entryrow_class_;

  auto
  EntryRow::get_type () -> GType
  {
    return entryrow_class_.init ().get_type ();
  }

  auto
  EntryRow::get_base_type () -> GType
  {
    return adw_entry_row_get_type ();
  }

  EntryRow::EntryRow ()
    : Glib::ObjectBase (nullptr),
      Adw::PreferencesRow (Glib::ConstructParams (entryrow_class_.init ()))
  {
  }

  auto
  EntryRow::add_prefix (Gtk::Widget* widget) -> void
  {
    adw_entry_row_add_prefix (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  EntryRow::add_suffix (Gtk::Widget* widget) -> void
  {
    adw_entry_row_add_suffix (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  EntryRow::get_activates_default () const -> bool
  {
    return adw_entry_row_get_activates_default (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  EntryRow::get_attributes () const -> Pango::AttrList
  {
    return Pango::AttrList (
        (adw_entry_row_get_attributes (const_cast<AdwEntryRow*> (gobj ()))));
  }

  auto
  EntryRow::get_enable_moji_completion () const -> bool
  {
    return adw_entry_row_get_enable_emoji_completion (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  EntryRow::get_input_hints () const -> Gtk::InputHints
  {
    return static_cast<Gtk::InputHints> (
        adw_entry_row_get_input_hints (const_cast<AdwEntryRow*> (gobj ())));
  }

  auto
  EntryRow::get_input_purpose () const -> Gtk::InputPurpose
  {
    return static_cast<Gtk::InputPurpose> (
        adw_entry_row_get_input_purpose (const_cast<AdwEntryRow*> (gobj ())));
  }

  auto
  EntryRow::get_show_apply_button () const -> bool
  {
    return adw_entry_row_get_show_apply_button (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  EntryRow::remove (Gtk::Widget* widget) -> void
  {
    adw_entry_row_remove (gobj (), (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  EntryRow::set_activates_default (bool activates) -> void
  {
    adw_entry_row_set_activates_default (gobj (), static_cast<int> (activates));
  }

  auto
  EntryRow::set_attributes (Pango::AttrList& attributes) -> void
  {
    adw_entry_row_set_attributes (gobj (), (attributes).gobj ());
  }

  auto
  EntryRow::set_enable_emoji_completion (bool activates) -> void
  {
    adw_entry_row_set_enable_emoji_completion (gobj (),
                                               static_cast<int> (activates));
  }

  auto
  EntryRow::set_input_hints (Gtk::InputHints hints) -> void
  {
    adw_entry_row_set_input_hints (gobj (), static_cast<GtkInputHints> (hints));
  }

  auto
  EntryRow::set_input_purpose (Gtk::InputPurpose purpose) -> void
  {
    adw_entry_row_set_input_purpose (gobj (),
                                     static_cast<GtkInputPurpose> (purpose));
  }

  auto
  EntryRow::set_show_apply_button (bool activates) -> void
  {
    adw_entry_row_set_show_apply_button (gobj (), static_cast<int> (activates));
  }

  auto
  EntryRow::signal_apply () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &EntryRow_signal_apply_info);
  }

  auto
  EntryRow::signal_entry_activated () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &EntryRow_signal_entry_activated_info);
  }

  auto
  EntryRow::property_activates_default () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "activates-default");
  }

  auto
  EntryRow::property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "activates-default");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Pango::AttrList>::value,
      "Type Pango::AttrList cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  EntryRow::property_attributes () -> Glib::PropertyProxy<Pango::AttrList>
  {
    return Glib::PropertyProxy<Pango::AttrList> (this, "attributes");
  }

  auto
  EntryRow::property_attributes () const -> Glib::PropertyProxy_ReadOnly<Pango::AttrList>
  {
    return Glib::PropertyProxy_ReadOnly<Pango::AttrList> (this, "attributes");
  }

  auto
  EntryRow::property_enable_emoji_completion () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enable-emoji-completion");
  }

  auto
  EntryRow::property_enable_emoji_completion () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enable-emoji-completion");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::InputHints>::value,
      "Type Gtk::InputHints cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  EntryRow::property_input_hints () -> Glib::PropertyProxy<Gtk::InputHints>
  {
    return Glib::PropertyProxy<Gtk::InputHints> (this, "input-hints");
  }

  auto
  EntryRow::property_input_hints () const -> Glib::PropertyProxy_ReadOnly<Gtk::InputHints>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::InputHints> (this, "input-hints");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::InputPurpose>::value,
      "Type Gtk::InputPurpose cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  EntryRow::property_input_purpose () -> Glib::PropertyProxy<Gtk::InputPurpose>
  {
    return Glib::PropertyProxy<Gtk::InputPurpose> (this, "input-purpose");
  }

  auto
  EntryRow::property_input_purpose () const -> Glib::PropertyProxy_ReadOnly<Gtk::InputPurpose>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::InputPurpose> (this,
                                                            "input-purpose");
  }

  auto
  EntryRow::property_show_apply_button () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-apply-button");
  }

  auto
  EntryRow::property_show_apply_button () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-apply-button");
  }

} // namespace Adw
