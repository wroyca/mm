// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LINKBUTTON_H
#define _GTKMM_LINKBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/button.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLinkButton = struct _GtkLinkButton;
using GtkLinkButtonClass = struct _GtkLinkButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API LinkButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API LinkButton : public Button
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef LinkButton CppObjectType;
    typedef LinkButton_Class CppClassType;
    typedef GtkLinkButton BaseObjectType;
    typedef GtkLinkButtonClass BaseClassType;
#endif

    LinkButton (LinkButton&& src) noexcept;
    auto
    operator= (LinkButton&& src) noexcept -> LinkButton&;

    LinkButton (const LinkButton&) = delete;
    auto
    operator= (const LinkButton&) -> LinkButton& = delete;

    ~LinkButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class LinkButton_Class;
    static CppClassType linkbutton_class_;

  protected:
    explicit LinkButton (const Glib::ConstructParams& construct_params);
    explicit LinkButton (GtkLinkButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLinkButton*
    {
      return reinterpret_cast<GtkLinkButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkLinkButton*
    {
      return reinterpret_cast<GtkLinkButton*> (gobject_);
    }

  private:
  public:
    LinkButton ();
    explicit LinkButton (const Glib::ustring& uri);

    explicit LinkButton (const Glib::ustring& uri, const Glib::ustring& label);

    auto
    get_uri () const -> Glib::ustring;

    void
    set_uri (const Glib::ustring& uri);

    auto
    get_visited () const -> bool;

    void
    set_visited (bool visited = true);

    auto
    property_uri () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_visited () -> Glib::PropertyProxy<bool>;

    auto
    property_visited () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate_link () -> Glib::SignalProxy<bool ()>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkLinkButton* object, bool take_copy = false) -> Gtk::LinkButton*;
} // namespace Glib

#endif
