// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESROW_H
#define _LIBADWAITAMM_PREFERENCESROW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwPreferencesRow = struct _AdwPreferencesRow;
using AdwPreferencesRowClass = struct _AdwPreferencesRowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT PreferencesRow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesRow : public Gtk::ListBoxRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PreferencesRow CppObjectType;
    typedef PreferencesRow_Class CppClassType;
    typedef AdwPreferencesRow BaseObjectType;
    typedef AdwPreferencesRowClass BaseClassType;
#endif

    PreferencesRow (PreferencesRow&& src) noexcept;
    auto
    operator= (PreferencesRow&& src) noexcept -> PreferencesRow&;

    PreferencesRow (const PreferencesRow&) = delete;
    auto
    operator= (const PreferencesRow&) -> PreferencesRow& = delete;

    ~PreferencesRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class PreferencesRow_Class;
    static CppClassType preferencesrow_class_;

  protected:
    explicit PreferencesRow (const Glib::ConstructParams& construct_params);
    explicit PreferencesRow (AdwPreferencesRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPreferencesRow*
    {
      return reinterpret_cast<AdwPreferencesRow*> (gobject_);
    }

    auto
    gobj () const -> const AdwPreferencesRow*
    {
      return reinterpret_cast<AdwPreferencesRow*> (gobject_);
    }

  private:
  public:
    PreferencesRow ();

    auto
    get_title () const -> Glib::ustring;

    auto
    get_title_selectable () const -> bool;

    auto
    get_use_markup () const -> bool;

    auto
    get_use_underline () const -> bool;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    set_title_selectable (bool title_selectable) -> void;

    auto
    set_use_markup (bool use_markup) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_title_selectable () -> Glib::PropertyProxy<bool>;

    auto
    property_title_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwPreferencesRow* object, bool take_copy = false) -> Adw::PreferencesRow*;
}

#endif