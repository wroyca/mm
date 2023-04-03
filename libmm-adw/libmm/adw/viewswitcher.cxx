// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewswitcher.hxx>
#include <libmm/adw/viewswitcher_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

auto
Glib::Value<Adw::ViewSwitcherPolicy>::value_type () -> GType
{
  return adw_view_switcher_policy_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwViewSwitcher* object, bool take_copy) -> Adw::ViewSwitcher*
  {
    return dynamic_cast<Adw::ViewSwitcher*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ViewSwitcher_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcher_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ViewSwitcher ((AdwViewSwitcher*) (o)));
  }

  ViewSwitcher::ViewSwitcher (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ViewSwitcher::ViewSwitcher (AdwViewSwitcher* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcher::ViewSwitcher (ViewSwitcher&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcher::operator= (ViewSwitcher&& src) noexcept -> ViewSwitcher&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ViewSwitcher::~ViewSwitcher () noexcept
  {
    destroy_ ();
  }

  ViewSwitcher::CppClassType ViewSwitcher::viewswitcher_class_;

  auto
  ViewSwitcher::get_type () -> GType
  {
    return viewswitcher_class_.init ().get_type ();
  }

  auto
  ViewSwitcher::get_base_type () -> GType
  {
    return adw_view_switcher_get_type ();
  }

  ViewSwitcher::ViewSwitcher ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (viewswitcher_class_.init ()))
  {
  }

  auto
  ViewSwitcher::get_policy () const -> ViewSwitcherPolicy
  {
    return static_cast<ViewSwitcherPolicy> (
        adw_view_switcher_get_policy (const_cast<AdwViewSwitcher*> (gobj ())));
  }

  auto
  ViewSwitcher::get_stack () const -> ViewStack*
  {
    return Glib::wrap (
        adw_view_switcher_get_stack (const_cast<AdwViewSwitcher*> (gobj ())));
  }

  auto
  ViewSwitcher::set_policy (ViewSwitcherPolicy policy) -> void
  {
    adw_view_switcher_set_policy (gobj (),
                                  static_cast<AdwViewSwitcherPolicy> (policy));
  }

  auto
  ViewSwitcher::set_stack (ViewStack* stack) -> void
  {
    adw_view_switcher_set_stack (gobj (), (AdwViewStack*) Glib::unwrap (stack));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ViewSwitcherPolicy>::value,
      "Type ViewSwitcherPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ViewSwitcher::property_policy () -> Glib::PropertyProxy<ViewSwitcherPolicy>
  {
    return Glib::PropertyProxy<ViewSwitcherPolicy> (this, "policy");
  }

  auto
  ViewSwitcher::property_policy () const -> Glib::PropertyProxy_ReadOnly<ViewSwitcherPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<ViewSwitcherPolicy> (this, "policy");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ViewStack*>::value,
      "Type ViewStack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ViewSwitcher::property_stack () -> Glib::PropertyProxy<ViewStack*>
  {
    return Glib::PropertyProxy<ViewStack*> (this, "stack");
  }

  auto
  ViewSwitcher::property_stack () const -> Glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return Glib::PropertyProxy_ReadOnly<ViewStack*> (this, "stack");
  }

} // namespace Adw
