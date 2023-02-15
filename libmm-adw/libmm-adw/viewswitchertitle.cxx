// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/viewswitchertitle.hxx>
#include <libmm-adw/viewswitchertitle_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwViewSwitcherTitle* object, bool take_copy) -> Adw::ViewSwitcherTitle*
  {
    return dynamic_cast<Adw::ViewSwitcherTitle*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ViewSwitcherTitle_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_switcher_title_get_type ();
    }

    return *this;
  }

  auto
  ViewSwitcherTitle_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ViewSwitcherTitle ((AdwViewSwitcherTitle*) (o)));
  }

  ViewSwitcherTitle::ViewSwitcherTitle (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ViewSwitcherTitle::ViewSwitcherTitle (AdwViewSwitcherTitle* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ViewSwitcherTitle::ViewSwitcherTitle (ViewSwitcherTitle&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ViewSwitcherTitle::operator= (ViewSwitcherTitle&& src) noexcept -> ViewSwitcherTitle&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (viewswitchertitle_class_.init ()))
  {
  }

  auto
  ViewSwitcherTitle::get_stack () const -> ViewStack*
  {
    return Glib::wrap (adw_view_switcher_title_get_stack (
        const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  ViewSwitcherTitle::get_subtitle () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_view_switcher_title_get_subtitle (
            const_cast<AdwViewSwitcherTitle*> (gobj ())));
  }

  auto
  ViewSwitcherTitle::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
                                       (AdwViewStack*) Glib::unwrap (stack));
  }

  auto
  ViewSwitcherTitle::set_subtitle (const Glib::ustring& subtitle) -> void
  {
    adw_view_switcher_title_set_subtitle (gobj (), subtitle.c_str ());
  }

  auto
  ViewSwitcherTitle::set_title (const Glib::ustring& title) -> void
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
      Glib::Traits::ValueCompatibleWithWrapProperty<ViewStack*>::value,
      "Type ViewStack* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ViewSwitcherTitle::property_stack () -> Glib::PropertyProxy<ViewStack*>
  {
    return Glib::PropertyProxy<ViewStack*> (this, "stack");
  }

  auto
  ViewSwitcherTitle::property_stack () const -> Glib::PropertyProxy_ReadOnly<ViewStack*>
  {
    return Glib::PropertyProxy_ReadOnly<ViewStack*> (this, "stack");
  }

  auto
  ViewSwitcherTitle::property_subtitle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "subtitle");
  }

  auto
  ViewSwitcherTitle::property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "subtitle");
  }

  auto
  ViewSwitcherTitle::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ViewSwitcherTitle::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ViewSwitcherTitle::property_title_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "title-visible");
  }

  auto
  ViewSwitcherTitle::property_view_switcher_enabled () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "view-switcher-enabled");
  }

  auto
  ViewSwitcherTitle::property_view_switcher_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "view-switcher-enabled");
  }

} // namespace Adw
