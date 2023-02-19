// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESPAGE_H
#define _LIBADWAITAMM_PREFERENCESPAGE_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm-adw/preferencesgroup.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT PreferencesPage_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesPage : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PreferencesPage CppObjectType;
    typedef PreferencesPage_Class CppClassType;
    typedef AdwPreferencesPage BaseObjectType;
    typedef AdwPreferencesPageClass BaseClassType;
#endif

    PreferencesPage (PreferencesPage&& src) noexcept;
    auto
    operator= (PreferencesPage&& src) noexcept -> PreferencesPage&;

    PreferencesPage (const PreferencesPage&) = delete;
    auto
    operator= (const PreferencesPage&) -> PreferencesPage& = delete;

    ~PreferencesPage () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class PreferencesPage_Class;
    static CppClassType preferencespage_class_;

  protected:
    explicit PreferencesPage (const Glib::ConstructParams& construct_params);
    explicit PreferencesPage (AdwPreferencesPage* castitem);

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
    PreferencesPage ();

    auto
    add (PreferencesGroup* group) -> void;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_title () const -> Glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    remove (PreferencesGroup* group) -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_name (const Glib::ustring& name) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

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
  wrap (AdwPreferencesPage* object, bool take_copy = false) -> Adw::PreferencesPage*;
}

#endif
