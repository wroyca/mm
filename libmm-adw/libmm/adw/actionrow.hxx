// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <libmm/adw/mm-adwconfig.hxx>
#include <libmm/adw/preferencesrow.hxx>

#include <libmm/glib/ustring.hxx>

#include <adwaita.h>
#include <sigc++/sigc++.h>

namespace adw
{
  class LIBMM_ADW_SYMEXPORT action_row_class;
  class LIBMM_ADW_SYMEXPORT action_row : public preferences_row
  {
    using cpp_object_type = action_row;
    using cpp_class_type = action_row_class;
    using base_object_type = AdwActionRow;
    using base_class_type = AdwActionRowClass;

  public:
    action_row ();
    action_row (action_row &&src) noexcept;
    action_row (const action_row &) = delete;
    ~action_row () noexcept override;

    auto operator= (action_row &&src) noexcept -> action_row &;
    auto operator= (const action_row &) -> action_row & = delete;

    static auto get_type () -> GType G_GNUC_CONST;
    static auto get_base_type () -> GType G_GNUC_CONST;

    auto gobj () -> AdwActionRow *;
    auto gobj () const -> const AdwActionRow *;

    auto activate () -> void;
    auto remove (Widget &widget) -> void;

    auto get_icon_name () const -> glib::ustring;
    auto get_subtitle () const -> glib::ustring;
    auto get_activatable_widget () const -> Widget *;
    auto get_subtitle_lines () const -> int;
    auto get_title_lines () const -> int;

    auto add_prefix (Widget &widget) -> void;
    auto add_suffix (Widget &widget) -> void;

    auto set_activatable_widget (Widget *widget) const -> void;
    auto set_icon_name (const glib::ustring &icon_name) -> void;
    auto set_subtitle (const glib::ustring &subtitle) -> void;
    auto set_subtitle_lines (int subtitle_lines) -> void;
    auto set_title_lines (int title_lines) -> void;

    auto property_icon_name () -> glib::PropertyProxy<glib::ustring>;
    auto property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_subtitle () -> glib::PropertyProxy<glib::ustring>;
    auto property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;
    auto property_activatable_widget () -> glib::PropertyProxy<Widget *>;
    auto property_activatable_widget () const -> glib::PropertyProxy_ReadOnly<Widget *>;
    auto property_subtitle_lines () -> glib::PropertyProxy<int>;
    auto property_subtitle_lines () const -> glib::PropertyProxy_ReadOnly<int>;
    auto property_title_lines () -> glib::PropertyProxy<int>;
    auto property_title_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto signal_activated () -> glib::SignalProxy<void  ()>;

  protected:
    explicit action_row (const glib::ConstructParams &construct_params);
    explicit action_row (AdwActionRow *castitem);

  private:
    friend class action_row_class;
    static cpp_class_type actionrow_class_;
  };
} // namespace adw

namespace glib
{
  auto wrap (AdwActionRow* object, bool take_copy = false) -> adw::action_row*;
}
