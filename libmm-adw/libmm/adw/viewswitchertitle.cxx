// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewswitchertitle.hxx>
#include <libmm/adw/viewswitchertitle_p.hxx>

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
  wrap (AdwViewSwitcherTitle* object, bool take_copy) -> adw::ViewSwitcherTitle*
  {
    return dynamic_cast<adw::ViewSwitcherTitle*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ViewSwitcherTitle_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_title_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcherTitle_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ViewSwitcherTitle ((AdwViewSwitcherTitle*) (o)));
  }

  ViewSwitcherTitle::ViewSwitcherTitle (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ViewSwitcherTitle::ViewSwitcherTitle (AdwViewSwitcherTitle* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcherTitle::ViewSwitcherTitle (ViewSwitcherTitle&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcherTitle::operator= (ViewSwitcherTitle&& src) noexcept -> ViewSwitcherTitle&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ViewSwitcherTitle::~ViewSwitcherTitle () noexcept
  {
    destroy_ ();
  }

  ViewSwitcherTitle::CppClassType ViewSwitcherTitle::viewswitchertitle_class_;

  auto
  ViewSwitcherTitle::get_type () -> GType
  {
    return viewswitchertitle_class_.init ().get_type ();
  }

  auto
  ViewSwitcherTitle::get_base_type () -> GType
  {
    return adw_view_switcher_title_get_type ();
  }

  ViewSwitcherTitle::ViewSwitcherTitle ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitchertitle_class_.init ()))
  {
  }

  auto
  ViewSwitcherTitle::get_stack () const -> ViewStack*
  {
    return glib::wrap (adw_view_switcher_title_get_stack (
        const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  ViewSwitcherTitle::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_switcher_title_get_subtitle (
            const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  ViewSwitcherTitle::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_switcher_title_get_title (
            const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  ViewSwitcherTitle::get_title_visible () const -> bool
  {
    return adw_view_switcher_title_get_title_visible (
        const_cast<AdwViewSwitcherTitle*> (gobj ()));
  }

  auto
  ViewSwitcherTitle::get_view_switcher_enabled () const -> bool
  {
    return adw_view_switcher_title_get_view_switcher_enabled (
        const_cast<AdwViewSwitcherTitle*> (gobj ()));
  }

  auto
  ViewSwitcherTitle::set_stack (ViewStack* stack) -> void
  {
    adw_view_switcher_title_set_stack (gobj (),
                                       (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  ViewSwitcherTitle::set_subtitle (const glib::ustring& subtitle) -> void
  {
    adw_view_switcher_title_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  ViewSwitcherTitle::set_title (const glib::ustring& title) -> void
  {
    adw_view_switcher_title_set_title (gobj (), title.c_str ());
  }

  auto
  ViewSwitcherTitle::set_view_switcher_enabled (bool enabled) -> void
  {
    adw_view_switcher_title_set_view_switcher_enabled (
        gobj (),
        static_cast<int> (enabled));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ViewStack*>::value,
      "Type ViewStack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ViewSwitcherTitle::property_stack () -> glib::PropertyProxy<ViewStack*>
  {
    return {this, "stack"};
  }

  auto
  ViewSwitcherTitle::property_stack () const -> glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return {this, "stack"};
  }

  auto
  ViewSwitcherTitle::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  ViewSwitcherTitle::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  ViewSwitcherTitle::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  ViewSwitcherTitle::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  ViewSwitcherTitle::property_title_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "title-visible"};
  }

  auto
  ViewSwitcherTitle::property_view_switcher_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "view-switcher-enabled"};
  }

  auto
  ViewSwitcherTitle::property_view_switcher_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "view-switcher-enabled"};
  }

} // namespace adw
