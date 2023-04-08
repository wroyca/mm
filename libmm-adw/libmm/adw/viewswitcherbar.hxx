// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSWITCHERBAR_H
#define _LIBADWAITAMM_VIEWSWITCHERBAR_H

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
  class LIBMM_ADW_SYMEXPORT view_switcher_bar_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT view_switcher_bar : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = view_switcher_bar;
    using CppClassType = view_switcher_bar_class;
    using BaseObjectType = AdwViewSwitcherBar;
    using BaseClassType = AdwViewSwitcherBarClass;
#endif

    view_switcher_bar (view_switcher_bar&& src) noexcept;
    auto
    operator= (view_switcher_bar&& src) noexcept -> view_switcher_bar&;

    view_switcher_bar (const view_switcher_bar&) = delete;
    auto
    operator= (const view_switcher_bar&) -> view_switcher_bar& = delete;

    ~view_switcher_bar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class view_switcher_bar_class;
    static CppClassType viewswitcherbar_class_;

  protected:
    explicit view_switcher_bar (const glib::ConstructParams& construct_params);
    explicit view_switcher_bar (AdwViewSwitcherBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwViewSwitcherBar*
    {
      return reinterpret_cast<AdwViewSwitcherBar*> (gobject_);
    }

    auto
    gobj () const -> const AdwViewSwitcherBar*
    {
      return reinterpret_cast<AdwViewSwitcherBar*> (gobject_);
    }

  private:
  public:
    view_switcher_bar ();

    auto
    get_reveal () const -> bool;

    auto
    get_stack () const -> view_stack*;

    auto
    set_reveal (bool reveal) -> void;

    auto
    set_stack (view_stack* stack) -> void;

    auto
    property_reveal () -> glib::PropertyProxy<bool>;

    auto
    property_reveal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_stack () -> glib::PropertyProxy<view_stack*>;

    auto
    property_stack () const -> glib::PropertyProxy_ReadOnly<view_stack*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewSwitcherBar* object, bool take_copy = false) -> adw::view_switcher_bar*;
}

#endif
