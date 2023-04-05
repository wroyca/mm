// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/actionrow.hxx>
#include <libmm/adw/actionrow_p.hxx>

namespace adw
{

}

namespace
{

  static const glib::SignalProxyInfo ActionRow_signal_activated_info = {
      "activated",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (AdwActionRow* object, bool take_copy) -> adw::ActionRow*
  {
    return dynamic_cast<adw::ActionRow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ActionRow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ActionRow_Class::class_init_function;

      register_derived_type (adw_action_row_get_type ());
    }

    return *this;
  }

  auto
  ActionRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ActionRow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ActionRow ((AdwActionRow*) (o)));
  }

  ActionRow::ActionRow (const glib::ConstructParams& construct_params)
    : adw::PreferencesRow (construct_params)
  {
  }

  ActionRow::ActionRow (AdwActionRow* castitem)
    : adw::PreferencesRow ((AdwPreferencesRow*) (castitem))
  {
  }

  ActionRow::ActionRow (ActionRow&& src) noexcept
    : adw::PreferencesRow (std::move (src))
  {
  }

  auto
  ActionRow::operator= (ActionRow&& src) noexcept -> ActionRow&
  {
    adw::PreferencesRow::operator= (std::move (src));
    return *this;
  }

  ActionRow::~ActionRow () noexcept
  {
    destroy_ ();
  }

  ActionRow::CppClassType ActionRow::actionrow_class_;

  auto
  ActionRow::get_type () -> GType
  {
    return actionrow_class_.init ().get_type ();
  }

  auto
  ActionRow::get_base_type () -> GType
  {
    return adw_action_row_get_type ();
  }

  ActionRow::ActionRow ()
    : glib::ObjectBase (nullptr),
      adw::PreferencesRow (glib::ConstructParams (actionrow_class_.init ()))
  {
  }

  auto
  ActionRow::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_action_row_get_icon_name (const_cast<AdwActionRow*> (gobj ())));
  }

  auto
  ActionRow::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_action_row_get_subtitle (const_cast<AdwActionRow*> (gobj ())));
  }

  auto
  ActionRow::get_activatable_widget () const -> gtk::Widget*
  {
    return glib::wrap (adw_action_row_get_activatable_widget (
        const_cast<AdwActionRow*> (gobj ())));
  }

  auto
  ActionRow::get_subtitle_lines () const -> int
  {
    return adw_action_row_get_subtitle_lines (
        const_cast<AdwActionRow*> (gobj ()));
  }

  auto
  ActionRow::get_title_lines () const -> int
  {
    return adw_action_row_get_title_lines (const_cast<AdwActionRow*> (gobj ()));
  }

  auto
  ActionRow::activate () -> void
  {
    adw_action_row_activate (gobj ());
  }

  auto
  ActionRow::add_prefix (gtk::Widget& widget) -> void
  {
    adw_action_row_add_prefix (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::add_suffix (gtk::Widget& widget) -> void
  {
    adw_action_row_add_suffix (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::set_activatable_widget (gtk::Widget* widget) const -> void
  {
    adw_action_row_set_activatable_widget (const_cast<AdwActionRow*> (gobj ()),
                                           (GtkWidget*) glib::unwrap (widget));
  }

  auto
  ActionRow::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_action_row_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ActionRow::set_subtitle (const glib::ustring& subtitle) -> void
  {
    adw_action_row_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  ActionRow::set_subtitle_lines (int subtitle_lines) -> void
  {
    adw_action_row_set_subtitle_lines (gobj (), subtitle_lines);
  }

  auto
  ActionRow::set_title_lines (int title_lines) -> void
  {
    adw_action_row_set_title_lines (gobj (), title_lines);
  }

  auto
  ActionRow::remove (gtk::Widget& widget) -> void
  {
    adw_action_row_remove (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::signal_activated () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this, &ActionRow_signal_activated_info);
  }

  auto
  ActionRow::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  ActionRow::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  ActionRow::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "subtitle");
  }

  auto
  ActionRow::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "subtitle");
  }

  auto
  ActionRow::property_activatable_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "activatable-widget");
  }

  auto
  ActionRow::property_activatable_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this,
                                                       "activatable-widget");
  }

  auto
  ActionRow::property_subtitle_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "subtitle-lines");
  }

  auto
  ActionRow::property_subtitle_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "subtitle-lines");
  }

  auto
  ActionRow::property_title_lines () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "title-lines");
  }

  auto
  ActionRow::property_title_lines () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "title-lines");
  }

} // namespace adw
