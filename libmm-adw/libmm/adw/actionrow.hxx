// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ACTIONROW_H
#define _LIBADWAITAMM_ACTIONROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT ActionRow_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ActionRow : public adw::PreferencesRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ActionRow CppObjectType;
    typedef ActionRow_Class CppClassType;
    typedef AdwActionRow BaseObjectType;
    typedef AdwActionRowClass BaseClassType;
#endif

    ActionRow (ActionRow&& src) noexcept;
    auto
    operator= (ActionRow&& src) noexcept -> ActionRow&;

    ActionRow (const ActionRow&) = delete;
    auto
    operator= (const ActionRow&) -> ActionRow& = delete;

    ~ActionRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ActionRow_Class;
    static CppClassType actionrow_class_;

  protected:
    explicit ActionRow (const glib::ConstructParams& construct_params);
    explicit ActionRow (AdwActionRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwActionRow*
    {
      return reinterpret_cast<AdwActionRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwActionRow*
    {
      return reinterpret_cast<AdwActionRow*> (gobject_);
    }

  private:
  public:
    ActionRow ();

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_subtitle () const -> glib::ustring;

    auto
    get_activatable_widget () const -> gtk::Widget*;

    auto
    get_subtitle_lines () const -> int;

    auto
    get_title_lines () const -> int;

    auto
    activate () -> void;

    auto
    add_prefix (gtk::Widget& widget) -> void;

    auto
    add_suffix (gtk::Widget& widget) -> void;

    auto
    set_activatable_widget (gtk::Widget* widget) const -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_subtitle (const glib::ustring& subtitle) -> void;

    auto
    set_subtitle_lines (int subtitle_lines) -> void;

    auto
    set_title_lines (int title_lines) -> void;

    auto
    remove (gtk::Widget& widget) -> void;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_subtitle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_activatable_widget () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_activatable_widget () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_subtitle_lines () -> glib::PropertyProxy<int>;

    auto
    property_subtitle_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_title_lines () -> glib::PropertyProxy<int>;

    auto
    property_title_lines () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    signal_activated () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwActionRow* object, bool take_copy = false) -> adw::ActionRow*;
}

#endif
