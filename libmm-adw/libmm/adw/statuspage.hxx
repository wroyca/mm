// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_STATUSPAGE_H
#define _LIBADWAITAMM_STATUSPAGE_H

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
  class LIBMM_ADW_SYMEXPORT StatusPage_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT StatusPage : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef StatusPage CppObjectType;
    typedef StatusPage_Class CppClassType;
    typedef AdwStatusPage BaseObjectType;
    typedef AdwStatusPageClass BaseClassType;
#endif

    StatusPage (StatusPage&& src) noexcept;
    auto
    operator= (StatusPage&& src) noexcept -> StatusPage&;

    StatusPage (const StatusPage&) = delete;
    auto
    operator= (const StatusPage&) -> StatusPage& = delete;

    ~StatusPage () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class StatusPage_Class;
    static CppClassType statuspage_class_;

  protected:
    explicit StatusPage (const glib::ConstructParams& construct_params);
    explicit StatusPage (AdwStatusPage* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwStatusPage*
    {
      return reinterpret_cast<AdwStatusPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwStatusPage*
    {
      return reinterpret_cast<AdwStatusPage*> (gobject_);
    }

  private:
  public:
    StatusPage ();

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_description () const -> glib::ustring;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_paintable () const -> glib::RefPtr<gdk::Paintable>;

    auto
    get_title () const -> glib::ustring;

    auto
    set_child (gtk::Widget* child) -> void;

    auto
    set_description (const glib::ustring& description) -> void;

    auto
    set_icon_name (const glib::ustring& description) -> void;

    auto
    set_paintable (const glib::RefPtr<gdk::Paintable>& paintable) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_description () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_description () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>;

    auto
    property_paintable () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>;

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
  wrap (AdwStatusPage* object, bool take_copy = false) -> adw::StatusPage*;
}

#endif
