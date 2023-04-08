// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_PREFERENCESGROUP_H
#define _LIBADWAITAMM_PREFERENCESGROUP_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT preferences_group_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT preferences_group : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef preferences_group CppObjectType;
    typedef preferences_group_class CppClassType;
    typedef AdwPreferencesGroup BaseObjectType;
    typedef AdwPreferencesGroupClass BaseClassType;
#endif

    preferences_group (preferences_group&& src) noexcept;
    auto
    operator= (preferences_group&& src) noexcept -> preferences_group&;

    preferences_group (const preferences_group&) = delete;
    auto
    operator= (const preferences_group&) -> preferences_group& = delete;

    ~preferences_group () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class preferences_group_class;
    static CppClassType preferencesgroup_class_;

  protected:
    explicit preferences_group (const glib::ConstructParams& construct_params);
    explicit preferences_group (AdwPreferencesGroup* castitem);

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
    preferences_group ();

    auto
    add (gtk::Widget* child) -> void;

    auto
    get_description () const -> glib::ustring;

    auto
    get_header_suffix () const -> gtk::Widget*;

    auto
    get_title () const -> glib::ustring;

    auto
    remove (gtk::Widget* child) -> void;

    auto
    set_description (const glib::ustring& description) -> void;

    auto
    set_header_suffix (gtk::Widget* suffix) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    property_description () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_description () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_header_suffix () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_header_suffix () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwPreferencesGroup* object, bool take_copy = false) -> adw::preferences_group*;
}

#endif
