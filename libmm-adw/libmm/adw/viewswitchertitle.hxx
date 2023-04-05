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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT ViewSwitcherTitle_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ViewSwitcherTitle : public gtk::Widget
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
    explicit ViewSwitcherTitle (const glib::ConstructParams& construct_params);
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
    get_subtitle () const -> glib::ustring;

    auto
    get_title () const -> glib::ustring;

    auto
    get_title_visible () const -> bool;

    auto
    get_view_switcher_enabled () const -> bool;

    auto
    set_stack (ViewStack* stack) -> void;

    auto
    set_subtitle (const glib::ustring& subtitle) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_view_switcher_enabled (bool enabled) -> void;

    auto
    property_stack () -> glib::PropertyProxy<ViewStack*>;

    auto
    property_stack () const -> glib::PropertyProxy_ReadOnly<ViewStack*>;

    auto
    property_subtitle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_title_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_view_switcher_enabled () -> glib::PropertyProxy<bool>;

    auto
    property_view_switcher_enabled () const
        -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewSwitcherTitle* object, bool take_copy = false) -> adw::ViewSwitcherTitle*;
}

#endif
