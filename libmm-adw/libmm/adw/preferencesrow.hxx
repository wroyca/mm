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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT preferences_row_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_row : public gtk::ListBoxRow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = preferences_row;
    using CppClassType = preferences_row_class;
    using BaseObjectType = AdwPreferencesRow;
    using BaseClassType = AdwPreferencesRowClass;
#endif

    preferences_row (preferences_row&& src) noexcept;
    auto
    operator= (preferences_row&& src) noexcept -> preferences_row&;

    preferences_row (const preferences_row&) = delete;
    auto
    operator= (const preferences_row&) -> preferences_row& = delete;

    ~preferences_row () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class preferences_row_class;
    static CppClassType preferencesrow_class_;

  protected:
    explicit preferences_row (const glib::ConstructParams& construct_params);
    explicit preferences_row (AdwPreferencesRow* castitem);

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
    preferences_row ();

    auto
    get_title () const -> glib::ustring;

    auto
    get_title_selectable () const -> bool;

    auto
    get_use_markup () const -> bool;

    auto
    get_use_underline () const -> bool;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_title_selectable (bool title_selectable) -> void;

    auto
    set_use_markup (bool use_markup) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_title_selectable () -> glib::PropertyProxy<bool>;

    auto
    property_title_selectable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_markup () -> glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwPreferencesRow* object, bool take_copy = false) -> adw::preferences_row*;
}

#endif
