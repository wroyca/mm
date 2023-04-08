// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewswitcherbar.hxx>
#include <libmm/adw/viewswitcherbar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwViewSwitcherBar* object, bool take_copy) -> adw::ViewSwitcherBar*
  {
    return dynamic_cast<adw::ViewSwitcherBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ViewSwitcherBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_bar_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcherBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ViewSwitcherBar ((AdwViewSwitcherBar*) (o)));
  }

  ViewSwitcherBar::ViewSwitcherBar (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ViewSwitcherBar::ViewSwitcherBar (AdwViewSwitcherBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcherBar::ViewSwitcherBar (ViewSwitcherBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcherBar::operator= (ViewSwitcherBar&& src) noexcept -> ViewSwitcherBar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ViewSwitcherBar::~ViewSwitcherBar () noexcept
  {
    destroy_ ();
  }

  ViewSwitcherBar::CppClassType ViewSwitcherBar::viewswitcherbar_class_;

  auto
  ViewSwitcherBar::get_type () -> GType
  {
    return viewswitcherbar_class_.init ().get_type ();
  }

  auto
  ViewSwitcherBar::get_base_type () -> GType
  {
    return adw_view_switcher_bar_get_type ();
  }

  ViewSwitcherBar::ViewSwitcherBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitcherbar_class_.init ()))
  {
  }

  auto
  ViewSwitcherBar::get_reveal () const -> bool
  {
    return adw_view_switcher_bar_get_reveal (
        const_cast<AdwViewSwitcherBar*> (gobj ()));
  }

  auto
  ViewSwitcherBar::get_stack () const -> ViewStack*
  {
    return glib::wrap (adw_view_switcher_bar_get_stack (
        const_cast<AdwViewSwitcherBar*> (gobj ())));
  }

  auto
  ViewSwitcherBar::set_reveal (bool reveal) -> void
  {
    adw_view_switcher_bar_set_reveal (gobj (), static_cast<int> (reveal));
  }

  auto
  ViewSwitcherBar::set_stack (ViewStack* stack) -> void
  {
    adw_view_switcher_bar_set_stack (gobj (),
                                     (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  ViewSwitcherBar::property_reveal () -> glib::PropertyProxy<bool>
  {
    return {this, "reveal"};
  }

  auto
  ViewSwitcherBar::property_reveal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reveal"};
  }

  auto
  ViewSwitcherBar::property_stack () -> glib::PropertyProxy<ViewStack*>
  {
    return {this, "stack"};
  }

  auto
  ViewSwitcherBar::property_stack () const -> glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return {this, "stack"};
  }

} // namespace adw
