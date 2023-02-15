// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_STATUSPAGE_H
#define _LIBADWAITAMM_STATUSPAGE_H

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
  class StatusPage_Class;
}
#endif

namespace Adw
{

  class StatusPage : public Gtk::Widget
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
    explicit StatusPage (const Glib::ConstructParams& construct_params);
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
    get_child () const -> Gtk::Widget*;

    auto
    get_description () const -> Glib::ustring;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_paintable () const -> Glib::RefPtr<Gdk::Paintable>;

    auto
    get_title () const -> Glib::ustring;

    auto
    set_child (Gtk::Widget* child) -> void;

    auto
    set_description (const Glib::ustring& description) -> void;

    auto
    set_icon_name (const Glib::ustring& description) -> void;

    auto
    set_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    property_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_description () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_description () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>;

    auto
    property_paintable () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>;

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
  wrap (AdwStatusPage* object, bool take_copy = false) -> Adw::StatusPage*;
}

#endif
