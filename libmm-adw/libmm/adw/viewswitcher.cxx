// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewswitcher.hxx>
#include <libmm/adw/viewswitcher_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::ViewSwitcherPolicy>::value_type () -> GType
{
  return adw_view_switcher_policy_get_type ();
}

namespace glib
{

  auto
  wrap (AdwViewSwitcher* object, bool take_copy) -> adw::ViewSwitcher*
  {
    return dynamic_cast<adw::ViewSwitcher*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ViewSwitcher_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcher_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ViewSwitcher ((AdwViewSwitcher*) (o)));
  }

  ViewSwitcher::ViewSwitcher (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ViewSwitcher::ViewSwitcher (AdwViewSwitcher* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcher::ViewSwitcher (ViewSwitcher&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcher::operator= (ViewSwitcher&& src) noexcept -> ViewSwitcher&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitcher_class_.init ()))
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
    return glib::wrap (
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
    adw_view_switcher_set_stack (gobj (), (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  ViewSwitcher::property_policy () -> glib::PropertyProxy<ViewSwitcherPolicy>
  {
    return {this, "policy"};
  }

  auto
  ViewSwitcher::property_policy () const -> glib::PropertyProxy_ReadOnly<ViewSwitcherPolicy>
  {
    return {this, "policy"};
  }

  auto
  ViewSwitcher::property_stack () -> glib::PropertyProxy<ViewStack*>
  {
    return {this, "stack"};
  }

  auto
  ViewSwitcher::property_stack () const -> glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return {this, "stack"};
  }

} // namespace adw
