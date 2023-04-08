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
  wrap (AdwViewSwitcherBar* object, bool take_copy) -> adw::view_switcher_bar*
  {
    return dynamic_cast<adw::view_switcher_bar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  view_switcher_bar_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_bar_get_type ();
    }

    return *this;
  }

  auto
  view_switcher_bar_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new view_switcher_bar ((AdwViewSwitcherBar*) (o)));
  }

  view_switcher_bar::view_switcher_bar (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  view_switcher_bar::view_switcher_bar (AdwViewSwitcherBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  view_switcher_bar::view_switcher_bar (view_switcher_bar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  view_switcher_bar::operator= (view_switcher_bar&& src) noexcept -> view_switcher_bar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  view_switcher_bar::~view_switcher_bar () noexcept
  {
    destroy_ ();
  }

  view_switcher_bar::CppClassType view_switcher_bar::viewswitcherbar_class_;

  auto
  view_switcher_bar::get_type () -> GType
  {
    return viewswitcherbar_class_.init ().get_type ();
  }

  auto
  view_switcher_bar::get_base_type () -> GType
  {
    return adw_view_switcher_bar_get_type ();
  }

  view_switcher_bar::view_switcher_bar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitcherbar_class_.init ()))
  {
  }

  auto
  view_switcher_bar::get_reveal () const -> bool
  {
    return adw_view_switcher_bar_get_reveal (
        const_cast<AdwViewSwitcherBar*> (gobj ()));
  }

  auto
  view_switcher_bar::get_stack () const -> view_stack*
  {
    return glib::wrap (adw_view_switcher_bar_get_stack (
        const_cast<AdwViewSwitcherBar*> (gobj ())));
  }

  auto
  view_switcher_bar::set_reveal (bool reveal) -> void
  {
    adw_view_switcher_bar_set_reveal (gobj (), static_cast<int> (reveal));
  }

  auto
  view_switcher_bar::set_stack (view_stack* stack) -> void
  {
    adw_view_switcher_bar_set_stack (gobj (),
                                     (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  view_switcher_bar::property_reveal () -> glib::PropertyProxy<bool>
  {
    return {this, "reveal"};
  }

  auto
  view_switcher_bar::property_reveal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "reveal"};
  }

  auto
  view_switcher_bar::property_stack () -> glib::PropertyProxy<view_stack*>
  {
    return {this, "stack"};
  }

  auto
  view_switcher_bar::property_stack () const -> glib::PropertyProxy_ReadOnly<view_stack*>
  {
    return {this, "stack"};
  }

} // namespace adw
