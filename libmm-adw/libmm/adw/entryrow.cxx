// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/entryrow.hxx>
#include <libmm/adw/entryrow_p.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo EntryRow_signal_apply_info = {
      "apply",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo EntryRow_signal_entry_activated_info = {
      "entry-activated",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

namespace glib
{

  auto
  wrap (AdwEntryRow* object, bool take_copy) -> adw::entry_row*
  {
    return dynamic_cast<adw::entry_row*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  entry_row_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &entry_row_class::class_init_function;

      register_derived_type (adw_entry_row_get_type ());

      gtk::Editable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  entry_row_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  entry_row_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new entry_row ((AdwEntryRow*) (o)));
  }

  entry_row::entry_row (const glib::ConstructParams& construct_params)
    : adw::preferences_row (construct_params)
  {
  }

  entry_row::entry_row (AdwEntryRow* castitem)
    : adw::preferences_row ((AdwPreferencesRow*) (castitem))
  {
  }

  entry_row::entry_row (entry_row&& src) noexcept
    : adw::preferences_row (std::move (src)),
      gtk::Editable (std::move (src))
  {
  }

  auto
  entry_row::operator= (entry_row&& src) noexcept -> entry_row&
  {
    adw::preferences_row::operator= (std::move (src));
    gtk::Editable::operator= (std::move (src));
    return *this;
  }

  entry_row::~entry_row () noexcept
  {
    destroy_ ();
  }

  entry_row::CppClassType entry_row::entryrow_class_;

  auto
  entry_row::get_type () -> GType
  {
    return entryrow_class_.init ().get_type ();
  }

  auto
  entry_row::get_base_type () -> GType
  {
    return adw_entry_row_get_type ();
  }

  entry_row::entry_row ()
    : glib::ObjectBase (nullptr),
      adw::preferences_row (glib::ConstructParams (entryrow_class_.init ()))
  {
  }

  auto
  entry_row::add_prefix (gtk::Widget* widget) -> void
  {
    adw_entry_row_add_prefix (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  entry_row::add_suffix (gtk::Widget* widget) -> void
  {
    adw_entry_row_add_suffix (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  entry_row::get_activates_default () const -> bool
  {
    return adw_entry_row_get_activates_default (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  entry_row::get_attributes () const -> pango::AttrList
  {
    return pango::AttrList (
        (adw_entry_row_get_attributes (const_cast<AdwEntryRow*> (gobj ()))));
  }

  auto
  entry_row::get_enable_moji_completion () const -> bool
  {
    return adw_entry_row_get_enable_emoji_completion (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  entry_row::get_input_hints () const -> gtk::InputHints
  {
    return static_cast<gtk::InputHints> (
        adw_entry_row_get_input_hints (const_cast<AdwEntryRow*> (gobj ())));
  }

  auto
  entry_row::get_input_purpose () const -> gtk::InputPurpose
  {
    return static_cast<gtk::InputPurpose> (
        adw_entry_row_get_input_purpose (const_cast<AdwEntryRow*> (gobj ())));
  }

  auto
  entry_row::get_show_apply_button () const -> bool
  {
    return adw_entry_row_get_show_apply_button (
        const_cast<AdwEntryRow*> (gobj ()));
  }

  auto
  entry_row::remove (gtk::Widget* widget) -> void
  {
    adw_entry_row_remove (gobj (), (GtkWidget*) glib::unwrap (widget));
  }

  auto
  entry_row::set_activates_default (bool activates) -> void
  {
    adw_entry_row_set_activates_default (gobj (), static_cast<int> (activates));
  }

  auto
  entry_row::set_attributes (pango::AttrList& attributes) -> void
  {
    adw_entry_row_set_attributes (gobj (), (attributes).gobj ());
  }

  auto
  entry_row::set_enable_emoji_completion (bool activates) -> void
  {
    adw_entry_row_set_enable_emoji_completion (gobj (),
                                               static_cast<int> (activates));
  }

  auto
  entry_row::set_input_hints (gtk::InputHints hints) -> void
  {
    adw_entry_row_set_input_hints (gobj (), static_cast<GtkInputHints> (hints));
  }

  auto
  entry_row::set_input_purpose (gtk::InputPurpose purpose) -> void
  {
    adw_entry_row_set_input_purpose (gobj (),
                                     static_cast<GtkInputPurpose> (purpose));
  }

  auto
  entry_row::set_show_apply_button (bool activates) -> void
  {
    adw_entry_row_set_show_apply_button (gobj (), static_cast<int> (activates));
  }

  auto
  entry_row::signal_apply () -> glib::SignalProxy<void ()>
  {
    return {this, &EntryRow_signal_apply_info};
  }

  auto
  entry_row::signal_entry_activated () -> glib::SignalProxy<void ()>
  {
    return {this, &EntryRow_signal_entry_activated_info};
  }

  auto
  entry_row::property_activates_default () -> glib::PropertyProxy<bool>
  {
    return {this, "activates-default"};
  }

  auto
  entry_row::property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "activates-default"};
  }

  auto
  entry_row::property_attributes () -> glib::PropertyProxy<pango::AttrList>
  {
    return {this, "attributes"};
  }

  auto
  entry_row::property_attributes () const -> glib::PropertyProxy_ReadOnly<pango::AttrList>
  {
    return {this, "attributes"};
  }

  auto
  entry_row::property_enable_emoji_completion () -> glib::PropertyProxy<bool>
  {
    return {this, "enable-emoji-completion"};
  }

  auto
  entry_row::property_enable_emoji_completion () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enable-emoji-completion"};
  }

  auto
  entry_row::property_input_hints () -> glib::PropertyProxy<gtk::InputHints>
  {
    return {this, "input-hints"};
  }

  auto
  entry_row::property_input_hints () const -> glib::PropertyProxy_ReadOnly<gtk::InputHints>
  {
    return {this, "input-hints"};
  }

  auto
  entry_row::property_input_purpose () -> glib::PropertyProxy<gtk::InputPurpose>
  {
    return {this, "input-purpose"};
  }

  auto
  entry_row::property_input_purpose () const -> glib::PropertyProxy_ReadOnly<gtk::InputPurpose>
  {
    return {this, "input-purpose"};
  }

  auto
  entry_row::property_show_apply_button () -> glib::PropertyProxy<bool>
  {
    return {this, "show-apply-button"};
  }

  auto
  entry_row::property_show_apply_button () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-apply-button"};
  }

} // namespace adw
