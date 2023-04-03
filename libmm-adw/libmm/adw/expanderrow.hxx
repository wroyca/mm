// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_EXPANDERROW_H
#define _LIBADWAITAMM_EXPANDERROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/preferencesrow.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ExpanderRow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ExpanderRow : public Adw::PreferencesRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ExpanderRow CppObjectType;
    typedef ExpanderRow_Class CppClassType;
    typedef AdwExpanderRow BaseObjectType;
    typedef AdwExpanderRowClass BaseClassType;
#endif

    ExpanderRow (ExpanderRow&& src) noexcept;
    auto
    operator= (ExpanderRow&& src) noexcept -> ExpanderRow&;

    ExpanderRow (const ExpanderRow&) = delete;
    auto
    operator= (const ExpanderRow&) -> ExpanderRow& = delete;

    ~ExpanderRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ExpanderRow_Class;
    static CppClassType expanderrow_class_;

  protected:
    explicit ExpanderRow (const Glib::ConstructParams& construct_params);
    explicit ExpanderRow (AdwExpanderRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwExpanderRow*
    {
      return reinterpret_cast<AdwExpanderRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwExpanderRow*
    {
      return reinterpret_cast<AdwExpanderRow*> (gobject_);
    }

  private:
  public:
    ExpanderRow ();

    auto
    add_action (Gtk::Widget* widget) -> void;

    auto
    add_prefix (Gtk::Widget* widget) -> void;

    auto
    add_row (Gtk::Widget* child) -> void;

    auto
    get_enable_expansion () const -> bool;

    auto
    get_expanded () const -> bool;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_show_enable_switch () const -> bool;

    auto
    get_subtitle () const -> Glib::ustring;

    auto
    remove (Gtk::Widget* child) -> void;

    auto
    set_enable_expansion (bool enable_expansion) -> void;

    auto
    set_expanded (bool expanded) -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_show_enable_switch (bool show_enable_switch) -> void;

    auto
    set_subtitle (const Glib::ustring& subtitle) -> void;

    auto
    property_enable_expansion () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_expansion () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expanded () -> Glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_enable_switch () -> Glib::PropertyProxy<bool>;

    auto
    property_show_enable_switch () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_subtitle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwExpanderRow* object, bool take_copy = false) -> Adw::ExpanderRow*;
}

#endif
