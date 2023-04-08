// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/actionrow.hxx>
#include <libmm/adw/actionrow_p.hxx>

namespace adw
{
  action_row::cpp_class_type action_row::actionrow_class_;

  auto
  action_row_class::init () -> const Class &
  {
    if (!gtype_)
    {
      class_init_func_ = &action_row_class::class_init_function;
      register_derived_type (adw_action_row_get_type ());
    }

    return *this;
  }

  auto
  action_row_class::class_init_function (void *g_class,
                                        void *class_data) -> void
  {
    const auto klass = static_cast<BaseClassType *> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  action_row_class::wrap_new (GObject *object) -> glib::ObjectBase *
  {
    return manage (new action_row (std::bit_cast<AdwActionRow *> (object)));
  }

  namespace
  {
    const glib::SignalProxyInfo signal_activated_info = {
      "activated",
      std::bit_cast<GCallback> (&glib::SignalProxyNormal::slot0_void_callback),
      std::bit_cast<GCallback> (&glib::SignalProxyNormal::slot0_void_callback)
    };
  }

  action_row::action_row (): ObjectBase (nullptr), preferences_row (glib::ConstructParams (actionrow_class_.init ())) { }
  action_row::action_row (const glib::ConstructParams &construct_params): preferences_row (construct_params) { }
  action_row::action_row (AdwActionRow *castitem): preferences_row (std::bit_cast<AdwPreferencesRow *> (castitem)) { }
  action_row::action_row (action_row &&src) noexcept: preferences_row (std::move (src)) { }
  action_row::~action_row () noexcept
  {
    destroy_ ();
  }

  auto
  action_row::operator= (action_row &&src) noexcept -> action_row &
  {
    preferences_row::operator= (std::move (src));
    return *this;
  }

  auto
  action_row::get_type () -> GType
  {
    return actionrow_class_.init ().get_type ();
  }

  auto
  action_row::get_base_type () -> GType
  {
    return adw_action_row_get_type ();
  }

  auto
  action_row::gobj () -> AdwActionRow * {
    return reinterpret_cast<AdwActionRow *> (gobject_);
  }

  auto
  action_row::gobj () const -> const AdwActionRow * {
    return reinterpret_cast<AdwActionRow *> (gobject_);
  }

  auto
  action_row::activate () -> void
  {
    adw_action_row_activate (gobj ());
  }

  auto
  action_row::remove (Widget &widget) -> void
  {
    adw_action_row_remove (gobj (), widget.gobj ());
  }

  auto
  action_row::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_action_row_get_icon_name (const_cast<AdwActionRow *> (gobj ())));
  }

  auto
  action_row::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
      adw_action_row_get_subtitle (const_cast<AdwActionRow *> (gobj ())));
  }

  auto
  action_row::get_activatable_widget () const -> Widget *
  {
    return glib::wrap (
      adw_action_row_get_activatable_widget (const_cast<AdwActionRow *> (gobj ())));
  }

  auto
  action_row::get_subtitle_lines () const -> int
  {
    return adw_action_row_get_subtitle_lines (const_cast<AdwActionRow *> (gobj ()));
  }

  auto
  action_row::get_title_lines () const -> int
  {
    return adw_action_row_get_title_lines (const_cast<AdwActionRow *> (gobj ()));
  }

  auto
  action_row::add_prefix (Widget &widget) -> void
  {
    adw_action_row_add_prefix (gobj (), widget.gobj ());
  }

  auto
  action_row::add_suffix (Widget &widget) -> void
  {
    adw_action_row_add_suffix (gobj (), widget.gobj ());
  }

  auto
  action_row::set_activatable_widget (Widget *widget) const -> void
  {
    adw_action_row_set_activatable_widget (const_cast<AdwActionRow *> (gobj ()), glib::unwrap (widget));
  }

  auto
  action_row::set_icon_name (const glib::ustring &icon_name) -> void
  {
    adw_action_row_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  action_row::set_subtitle (const glib::ustring &subtitle) -> void
  {
    adw_action_row_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  action_row::set_subtitle_lines (const int subtitle_lines) -> void
  {
    adw_action_row_set_subtitle_lines (gobj (), subtitle_lines);
  }

  auto
  action_row::set_title_lines (const int title_lines) -> void
  {
    adw_action_row_set_title_lines (gobj (), title_lines);
  }

  auto
  action_row::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  action_row::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  action_row::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  action_row::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  action_row::property_activatable_widget () -> glib::PropertyProxy<Widget *>
  {
    return {this, "activatable-widget"};
  }

  auto
  action_row::property_activatable_widget () const -> glib::PropertyProxy_ReadOnly<Widget *>
  {
    return {this, "activatable-widget"};
  }

  auto
  action_row::property_subtitle_lines () -> glib::PropertyProxy<int>
  {
    return {this, "subtitle-lines"};
  }

  auto
  action_row::property_subtitle_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "subtitle-lines"};
  }

  auto
  action_row::property_title_lines () -> glib::PropertyProxy<int>
  {
    return {this, "title-lines"};
  }

  auto
  action_row::property_title_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "title-lines"};
  }

  auto
  action_row::signal_activated () -> glib::SignalProxy<void  ()>
  {
    return {this, &signal_activated_info};
  }
} // namespace adw

namespace glib
{
  auto
  wrap (AdwActionRow *object,
        const bool take_copy) -> adw::action_row *
  {
    return dynamic_cast<adw::action_row *> (
      wrap_auto (std::bit_cast<GObject *> (object), take_copy));
  }
} // namespace glib
