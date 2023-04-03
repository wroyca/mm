// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSWITCHERTITLE_H
#define _LIBADWAITAMM_VIEWSWITCHERTITLE_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm/adw/viewstack.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ViewSwitcherTitle_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ViewSwitcherTitle : public Gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ViewSwitcherTitle CppObjectType;
    typedef ViewSwitcherTitle_Class CppClassType;
    typedef AdwViewSwitcherTitle BaseObjectType;
    typedef AdwViewSwitcherTitleClass BaseClassType;
#endif

    ViewSwitcherTitle (ViewSwitcherTitle&& src) noexcept;
    auto
    operator= (ViewSwitcherTitle&& src) noexcept -> ViewSwitcherTitle&;

    ViewSwitcherTitle (const ViewSwitcherTitle&) = delete;
    auto
    operator= (const ViewSwitcherTitle&) -> ViewSwitcherTitle& = delete;

    ~ViewSwitcherTitle () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ViewSwitcherTitle_Class;
    static CppClassType viewswitchertitle_class_;

  protected:
    explicit ViewSwitcherTitle (const Glib::ConstructParams& construct_params);
    explicit ViewSwitcherTitle (AdwViewSwitcherTitle* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwViewSwitcherTitle*
    {
      return reinterpret_cast<AdwViewSwitcherTitle*> (gobject_);
    }

    auto
    gobj () const -> const AdwViewSwitcherTitle*
    {
      return reinterpret_cast<AdwViewSwitcherTitle*> (gobject_);
    }

  private:
  public:
    ViewSwitcherTitle ();

    auto
    get_stack () const -> ViewStack*;

    auto
    get_subtitle () const -> Glib::ustring;

    auto
    get_title () const -> Glib::ustring;

    auto
    get_title_visible () const -> bool;

    auto
    get_view_switcher_enabled () const -> bool;

    auto
    set_stack (ViewStack* stack) -> void;

    auto
    set_subtitle (const Glib::ustring& subtitle) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    set_view_switcher_enabled (bool enabled) -> void;

    auto
    property_stack () -> Glib::PropertyProxy<ViewStack*>;

    auto
    property_stack () const -> Glib::PropertyProxy_ReadOnly<ViewStack*>;

    auto
    property_subtitle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_title_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_view_switcher_enabled () -> Glib::PropertyProxy<bool>;

    auto
    property_view_switcher_enabled () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwViewSwitcherTitle* object, bool take_copy = false) -> Adw::ViewSwitcherTitle*;
}

#endif
