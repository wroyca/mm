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
  wrap (AdwViewSwitcherTitle* object, bool take_copy) -> adw::view_switcher_title*
  {
    return dynamic_cast<adw::view_switcher_title*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  view_switcher_title_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_title_get_type ();
    }

    return *this;
  }

  auto
  view_switcher_title_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new view_switcher_title ((AdwViewSwitcherTitle*) (o)));
  }

  view_switcher_title::view_switcher_title (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  view_switcher_title::view_switcher_title (AdwViewSwitcherTitle* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  view_switcher_title::view_switcher_title (view_switcher_title&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  view_switcher_title::operator= (view_switcher_title&& src) noexcept -> view_switcher_title&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  view_switcher_title::~view_switcher_title () noexcept
  {
    destroy_ ();
  }

  view_switcher_title::CppClassType view_switcher_title::viewswitchertitle_class_;

  auto
  view_switcher_title::get_type () -> GType
  {
    return viewswitchertitle_class_.init ().get_type ();
  }

  auto
  view_switcher_title::get_base_type () -> GType
  {
    return adw_view_switcher_title_get_type ();
  }

  view_switcher_title::view_switcher_title ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (viewswitchertitle_class_.init ()))
  {
  }

  auto
  view_switcher_title::get_stack () const -> view_stack*
  {
    return glib::wrap (adw_view_switcher_title_get_stack (
        const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  view_switcher_title::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_switcher_title_get_subtitle (
            const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  view_switcher_title::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_switcher_title_get_title (
            const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  view_switcher_title::get_title_visible () const -> bool
  {
    return adw_view_switcher_title_get_title_visible (
        const_cast<AdwViewSwitcherTitle*> (gobj ()));
  }

  auto
  view_switcher_title::get_view_switcher_enabled () const -> bool
  {
    return adw_view_switcher_title_get_view_switcher_enabled (
        const_cast<AdwViewSwitcherTitle*> (gobj ()));
  }

  auto
  view_switcher_title::set_stack (view_stack* stack) -> void
  {
    adw_view_switcher_title_set_stack (gobj (),
                                       (AdwViewStack*) glib::unwrap (stack));
  }

  auto
  view_switcher_title::set_subtitle (const glib::ustring& subtitle) -> void
  {
    adw_view_switcher_title_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  view_switcher_title::set_title (const glib::ustring& title) -> void
  {
    adw_view_switcher_title_set_title (gobj (), title.c_str ());
  }

  auto
  view_switcher_title::set_view_switcher_enabled (bool enabled) -> void
  {
    adw_view_switcher_title_set_view_switcher_enabled (
        gobj (),
        static_cast<int> (enabled));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<view_stack*>::value,
      "Type ViewStack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  view_switcher_title::property_stack () -> glib::PropertyProxy<view_stack*>
  {
    return {this, "stack"};
  }

  auto
  view_switcher_title::property_stack () const -> glib::PropertyProxy_ReadOnly<view_stack*>
  {
    return {this, "stack"};
  }

  auto
  view_switcher_title::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  view_switcher_title::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  view_switcher_title::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  view_switcher_title::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  view_switcher_title::property_title_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "title-visible"};
  }

  auto
  view_switcher_title::property_view_switcher_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "view-switcher-enabled"};
  }

  auto
  view_switcher_title::property_view_switcher_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "view-switcher-enabled"};
  }

} // namespace adw
