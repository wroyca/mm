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
glib::Value<adw::view_switcher_policy>::value_type () -> GType
{
  return adw_view_switcher_policy_get_type ();
}

namespace glib
{

  auto
  wrap (AdwViewSwitcher* object, bool take_copy) -> adw::view_switcher*
  {
    return dynamic_cast<adw::view_switcher*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  view_switcher_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_get_type ();
    }

    return *this;
  }

  auto
  view_switcher_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new view_switcher ((AdwViewSwitcher*) (o)));
  }

  view_switcher::view_switcher (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  view_switcher::view_switcher (AdwViewSwitcher* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  view_switcher::view_switcher (view_switcher&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  view_switcher::operator= (view_switcher&& src) noexcept -> view_switcher&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  view_switcher::~view_switcher () noexcept
  {
    destroy_ ();
  }

  view_switcher::CppClassType view_switcher::viewswitcher_class_;

  auto
  view_switcher::get_type () -> GType
  {
    return viewswitcher_class_.init ().get_type ();
  }

  auto
  view_switcher::get_base_type () -> GType
  {
    return adw_view_switcher_get_type ();
  }

  view_switcher::view_switcher ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitcher_class_.init ()))
  {
  }

  auto
  view_switcher::get_policy () const -> view_switcher_policy
  {
    return static_cast<view_switcher_policy> (
        adw_view_switcher_get_policy (const_cast<AdwViewSwitcher*> (gobj ())));
  }

  auto
  view_switcher::get_stack () const -> view_stack*
  {
    return glib::wrap (
        adw_view_switcher_get_stack (const_cast<AdwViewSwitcher*> (gobj ())));
  }

  auto
  view_switcher::set_policy (view_switcher_policy policy) -> void
  {
    adw_view_switcher_set_policy (gobj (),
                                  static_cast<AdwViewSwitcherPolicy> (policy));
  }

  auto
  view_switcher::set_stack (view_stack* stack) -> void
  {
    adw_view_switcher_set_stack (gobj (), (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  view_switcher::property_policy () -> glib::PropertyProxy<view_switcher_policy>
  {
    return {this, "policy"};
  }

  auto
  view_switcher::property_policy () const -> glib::PropertyProxy_ReadOnly<view_switcher_policy>
  {
    return {this, "policy"};
  }

  auto
  view_switcher::property_stack () -> glib::PropertyProxy<view_stack*>
  {
    return {this, "stack"};
  }

  auto
  view_switcher::property_stack () const -> glib::PropertyProxy_ReadOnly<view_stack*>
  {
    return {this, "stack"};
  }

} // namespace adw
