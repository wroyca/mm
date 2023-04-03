// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewswitcherbar.hxx>
#include <libmm/adw/viewswitcherbar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwViewSwitcherBar* object, bool take_copy) -> Adw::ViewSwitcherBar*
  {
    return dynamic_cast<Adw::ViewSwitcherBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ViewSwitcherBar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_bar_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcherBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ViewSwitcherBar ((AdwViewSwitcherBar*) (o)));
  }

  ViewSwitcherBar::ViewSwitcherBar (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ViewSwitcherBar::ViewSwitcherBar (AdwViewSwitcherBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcherBar::ViewSwitcherBar (ViewSwitcherBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcherBar::operator= (ViewSwitcherBar&& src) noexcept -> ViewSwitcherBar&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (viewswitcherbar_class_.init ()))
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
    return Glib::wrap (adw_view_switcher_bar_get_stack (
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
                                     (AdwViewStack*) Glib::unwrap (stack));
  }

  auto
  ViewSwitcherBar::property_reveal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "reveal");
  }

  auto
  ViewSwitcherBar::property_reveal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "reveal");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ViewStack*>::value,
      "Type ViewStack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ViewSwitcherBar::property_stack () -> Glib::PropertyProxy<ViewStack*>
  {
    return Glib::PropertyProxy<ViewStack*> (this, "stack");
  }

  auto
  ViewSwitcherBar::property_stack () const -> Glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return Glib::PropertyProxy_ReadOnly<ViewStack*> (this, "stack");
  }

} // namespace Adw
