// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_ACTIONROW_H
#define _LIBADWAITAMM_ACTIONROW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class ActionRow_Class;
}
#endif

namespace Adw
{

  class ActionRow : public Adw::PreferencesRow
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
    explicit ActionRow (const Glib::ConstructParams& construct_params);
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
    get_icon_name () const -> Glib::ustring;

    auto
    get_subtitle () const -> Glib::ustring;

    auto
    get_activatable_widget () const -> Gtk::Widget*;

    auto
    get_subtitle_lines () const -> int;

    auto
    get_title_lines () const -> int;

    auto
    activate () -> void;

    auto
    add_prefix (Gtk::Widget& widget) -> void;

    auto
    add_suffix (Gtk::Widget& widget) -> void;

    auto
    set_activatable_widget (Gtk::Widget* widget) const -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_subtitle (const Glib::ustring& subtitle) -> void;

    auto
    set_subtitle_lines (int subtitle_lines) -> void;

    auto
    set_title_lines (int title_lines) -> void;

    auto
    remove (Gtk::Widget& widget) -> void;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_subtitle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_activatable_widget () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_activatable_widget () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_subtitle_lines () -> Glib::PropertyProxy<int>;

    auto
    property_subtitle_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_title_lines () -> Glib::PropertyProxy<int>;

    auto
    property_title_lines () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    signal_activated () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwActionRow* object, bool take_copy = false) -> Adw::ActionRow*;
}

#endif
