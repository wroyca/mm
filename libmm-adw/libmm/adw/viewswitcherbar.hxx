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
  class LIBMM_ADW_SYMEXPORT ViewSwitcherBar_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ViewSwitcherBar : public gtk::Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ViewSwitcherBar CppObjectType;
    typedef ViewSwitcherBar_Class CppClassType;
    typedef AdwViewSwitcherBar BaseObjectType;
    typedef AdwViewSwitcherBarClass BaseClassType;
#endif

    ViewSwitcherBar (ViewSwitcherBar&& src) noexcept;
    auto
    operator= (ViewSwitcherBar&& src) noexcept -> ViewSwitcherBar&;

    ViewSwitcherBar (const ViewSwitcherBar&) = delete;
    auto
    operator= (const ViewSwitcherBar&) -> ViewSwitcherBar& = delete;

    ~ViewSwitcherBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ViewSwitcherBar_Class;
    static CppClassType viewswitcherbar_class_;

  protected:
    explicit ViewSwitcherBar (const glib::ConstructParams& construct_params);
    explicit ViewSwitcherBar (AdwViewSwitcherBar* castitem);

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
    ViewSwitcherBar ();

    auto
    get_reveal () const -> bool;

    auto
    get_stack () const -> ViewStack*;

    auto
    set_reveal (bool reveal) -> void;

    auto
    set_stack (ViewStack* stack) -> void;

    auto
    property_reveal () -> glib::PropertyProxy<bool>;

    auto
    property_reveal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_stack () -> glib::PropertyProxy<ViewStack*>;

    auto
    property_stack () const -> glib::PropertyProxy_ReadOnly<ViewStack*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewSwitcherBar* object, bool take_copy = false) -> adw::ViewSwitcherBar*;
}

#endif
