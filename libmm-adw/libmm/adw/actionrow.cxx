// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/actionrow.hxx>
#include <libmm/adw/actionrow_p.hxx>

namespace Adw
{

}

namespace
{

  static const Glib::SignalProxyInfo ActionRow_signal_activated_info = {
      "activated",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

}

namespace Glib
{

  auto
  wrap (AdwActionRow* object, bool take_copy) -> Adw::ActionRow*
  {
    return dynamic_cast<Adw::ActionRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ActionRow_Class::init () -> const Glib::Class&
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
  ActionRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ActionRow ((AdwActionRow*) (o)));
  }

  ActionRow::ActionRow (const Glib::ConstructParams& construct_params)
    : Adw::PreferencesRow (construct_params)
  {
  }

  ActionRow::ActionRow (AdwActionRow* castitem)
    : Adw::PreferencesRow ((AdwPreferencesRow*) (castitem))
  {
  }

  ActionRow::ActionRow (ActionRow&& src) noexcept
    : Adw::PreferencesRow (std::move (src))
  {
  }

  auto
  ActionRow::operator= (ActionRow&& src) noexcept -> ActionRow&
  {
    Adw::PreferencesRow::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Adw::PreferencesRow (Glib::ConstructParams (actionrow_class_.init ()))
  {
  }

  auto
  ActionRow::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_action_row_get_icon_name (const_cast<AdwActionRow*> (gobj ())));
  }

  auto
  ActionRow::get_subtitle () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_action_row_get_subtitle (const_cast<AdwActionRow*> (gobj ())));
  }

  auto
  ActionRow::get_activatable_widget () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_action_row_get_activatable_widget (
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
  ActionRow::add_prefix (Gtk::Widget& widget) -> void
  {
    adw_action_row_add_prefix (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::add_suffix (Gtk::Widget& widget) -> void
  {
    adw_action_row_add_suffix (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::set_activatable_widget (Gtk::Widget* widget) const -> void
  {
    adw_action_row_set_activatable_widget (const_cast<AdwActionRow*> (gobj ()),
                                           (GtkWidget*) Glib::unwrap (widget));
  }

  auto
  ActionRow::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_action_row_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ActionRow::set_subtitle (const Glib::ustring& subtitle) -> void
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
  ActionRow::remove (Gtk::Widget& widget) -> void
  {
    adw_action_row_remove (gobj (), (widget).gobj ());
  }

  auto
  ActionRow::signal_activated () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &ActionRow_signal_activated_info);
  }

  auto
  ActionRow::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  ActionRow::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  ActionRow::property_subtitle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "subtitle");
  }

  auto
  ActionRow::property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "subtitle");
  }

  auto
  ActionRow::property_activatable_widget () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "activatable-widget");
  }

  auto
  ActionRow::property_activatable_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this,
                                                       "activatable-widget");
  }

  auto
  ActionRow::property_subtitle_lines () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "subtitle-lines");
  }

  auto
  ActionRow::property_subtitle_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "subtitle-lines");
  }

  auto
  ActionRow::property_title_lines () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "title-lines");
  }

  auto
  ActionRow::property_title_lines () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "title-lines");
  }

} // namespace Adw
