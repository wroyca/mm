// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESGROUP_H
#define _LIBADWAITAMM_PREFERENCESGROUP_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT PreferencesGroup_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT PreferencesGroup : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PreferencesGroup CppObjectType;
    typedef PreferencesGroup_Class CppClassType;
    typedef AdwPreferencesGroup BaseObjectType;
    typedef AdwPreferencesGroupClass BaseClassType;
#endif

    PreferencesGroup (PreferencesGroup&& src) noexcept;
    auto
    operator= (PreferencesGroup&& src) noexcept -> PreferencesGroup&;

    PreferencesGroup (const PreferencesGroup&) = delete;
    auto
    operator= (const PreferencesGroup&) -> PreferencesGroup& = delete;

    ~PreferencesGroup () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class PreferencesGroup_Class;
    static CppClassType preferencesgroup_class_;

  protected:
    explicit PreferencesGroup (const Glib::ConstructParams& construct_params);
    explicit PreferencesGroup (AdwPreferencesGroup* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwPreferencesGroup*
    {
      return reinterpret_cast<AdwPreferencesGroup*> (gobject_);
    }

    auto
    gobj () const -> const AdwPreferencesGroup*
    {
      return reinterpret_cast<AdwPreferencesGroup*> (gobject_);
    }

  private:
  public:
    PreferencesGroup ();

    auto
    add (Gtk::Widget* child) -> void;

    auto
    get_description () const -> Glib::ustring;

    auto
    get_header_suffix () const -> Gtk::Widget*;

    auto
    get_title () const -> Glib::ustring;

    auto
    remove (Gtk::Widget* child) -> void;

    auto
    set_description (const Glib::ustring& description) -> void;

    auto
    set_header_suffix (Gtk::Widget* suffix) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    property_description () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_description () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_header_suffix () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_header_suffix () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwPreferencesGroup* object, bool take_copy = false) -> Adw::PreferencesGroup*;
}

#endif
