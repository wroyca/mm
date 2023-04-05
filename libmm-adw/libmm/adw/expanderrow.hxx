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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT ExpanderRow_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ExpanderRow : public adw::PreferencesRow
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
    explicit ExpanderRow (const glib::ConstructParams& construct_params);
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
    add_action (gtk::Widget* widget) -> void;

    auto
    add_prefix (gtk::Widget* widget) -> void;

    auto
    add_row (gtk::Widget* child) -> void;

    auto
    get_enable_expansion () const -> bool;

    auto
    get_expanded () const -> bool;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_show_enable_switch () const -> bool;

    auto
    get_subtitle () const -> glib::ustring;

    auto
    remove (gtk::Widget* child) -> void;

    auto
    set_enable_expansion (bool enable_expansion) -> void;

    auto
    set_expanded (bool expanded) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_show_enable_switch (bool show_enable_switch) -> void;

    auto
    set_subtitle (const glib::ustring& subtitle) -> void;

    auto
    property_enable_expansion () -> glib::PropertyProxy<bool>;

    auto
    property_enable_expansion () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expanded () -> glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_show_enable_switch () -> glib::PropertyProxy<bool>;

    auto
    property_show_enable_switch () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_subtitle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwExpanderRow* object, bool take_copy = false) -> adw::ExpanderRow*;
}

#endif
