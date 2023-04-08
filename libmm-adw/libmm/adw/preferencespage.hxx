// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESPAGE_H
#define _LIBADWAITAMM_PREFERENCESPAGE_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/preferencesgroup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT preferences_page_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_page : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = preferences_page;
    using CppClassType = preferences_page_class;
    using BaseObjectType = AdwPreferencesPage;
    using BaseClassType = AdwPreferencesPageClass;
#endif

    preferences_page (preferences_page&& src) noexcept;
    auto
    operator= (preferences_page&& src) noexcept -> preferences_page&;

    preferences_page (const preferences_page&) = delete;
    auto
    operator= (const preferences_page&) -> preferences_page& = delete;

    ~preferences_page () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class preferences_page_class;
    static CppClassType preferencespage_class_;

  protected:
    explicit preferences_page (const glib::ConstructParams& construct_params);
    explicit preferences_page (AdwPreferencesPage* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPreferencesPage*
    {
      return reinterpret_cast<AdwPreferencesPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwPreferencesPage*
    {
      return reinterpret_cast<AdwPreferencesPage*> (gobject_);
    }

  private:
  public:
    preferences_page ();

    auto
    add (preferences_group* group) -> void;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_name () const -> glib::ustring;

    auto
    get_title () const -> glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    remove (preferences_group* group) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_name (const glib::ustring& name) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

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
  wrap (AdwPreferencesPage* object, bool take_copy = false) -> adw::preferences_page*;
}

#endif
