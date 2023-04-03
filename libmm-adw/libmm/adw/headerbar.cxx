// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/headerbar.hxx>
#include <libmm/adw/headerbar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

auto
Glib::Value<Adw::CenteringPolicy>::value_type () -> GType
{
  return adw_centering_policy_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwHeaderBar* object, bool take_copy) -> Adw::HeaderBar*
  {
    return dynamic_cast<Adw::HeaderBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  HeaderBar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_header_bar_get_type ();
    }

    return *this;
  }

  auto
  HeaderBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new HeaderBar ((AdwHeaderBar*) (o)));
  }

  HeaderBar::HeaderBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  HeaderBar::HeaderBar (AdwHeaderBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  HeaderBar::HeaderBar (HeaderBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  HeaderBar::operator= (HeaderBar&& src) noexcept -> HeaderBar&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  HeaderBar::~HeaderBar () noexcept
  {
    destroy_ ();
  }

  HeaderBar::CppClassType HeaderBar::headerbar_class_;

  auto
  HeaderBar::get_type () -> GType
  {
    return headerbar_class_.init ().get_type ();
  }

  auto
  HeaderBar::get_base_type () -> GType
  {
    return adw_header_bar_get_type ();
  }

  HeaderBar::HeaderBar ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (headerbar_class_.init ()))
  {
  }

  auto
  HeaderBar::get_centering_policy () const -> CenteringPolicy
  {
    return static_cast<CenteringPolicy> (adw_header_bar_get_centering_policy (
        const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  HeaderBar::get_decoration_layout () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_header_bar_get_decoration_layout (
            const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  HeaderBar::get_show_end_title_buttons () const -> bool
  {
    return adw_header_bar_get_show_end_title_buttons (
        const_cast<AdwHeaderBar*> (gobj ()));
  }

  auto
  HeaderBar::get_show_start_title_buttons () const -> bool
  {
    return adw_header_bar_get_show_start_title_buttons (
        const_cast<AdwHeaderBar*> (gobj ()));
  }

  auto
  HeaderBar::get_title_widget () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_header_bar_get_title_widget (const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  HeaderBar::pack_end (Gtk::Widget* child) -> void
  {
    adw_header_bar_pack_end (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  HeaderBar::pack_start (Gtk::Widget* child) -> void
  {
    adw_header_bar_pack_start (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  HeaderBar::remove (Gtk::Widget* child) -> void
  {
    adw_header_bar_remove (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  HeaderBar::set_centering_policy (CenteringPolicy centering_policy) -> void
  {
    adw_header_bar_set_centering_policy (
        gobj (),
        static_cast<AdwCenteringPolicy> (centering_policy));
  }

  auto
  HeaderBar::set_decoration_layout (const Glib::ustring& layout) -> void
  {
    adw_header_bar_set_decoration_layout (gobj (), layout.c_str ());
  }

  auto
  HeaderBar::set_show_end_title_buttons (bool setting) -> void
  {
    adw_header_bar_set_show_end_title_buttons (gobj (),
                                               static_cast<int> (setting));
  }

  auto
  HeaderBar::set_show_start_title_buttons (bool setting) -> void
  {
    adw_header_bar_set_show_start_title_buttons (gobj (),
                                                 static_cast<int> (setting));
  }

  auto
  HeaderBar::set_title_widget (Gtk::Widget* title_widget) -> void
  {
    adw_header_bar_set_title_widget (gobj (),
                                     (GtkWidget*) Glib::unwrap (title_widget));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CenteringPolicy>::value,
      "Type CenteringPolicy cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  HeaderBar::property_centering_policy () -> Glib::PropertyProxy<CenteringPolicy>
  {
    return Glib::PropertyProxy<CenteringPolicy> (this, "centering-policy");
  }

  auto
  HeaderBar::property_centering_policy () const -> Glib::PropertyProxy_ReadOnly<CenteringPolicy>
  {
    return Glib::PropertyProxy_ReadOnly<CenteringPolicy> (this,
                                                          "centering-policy");
  }

  auto
  HeaderBar::property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "decoration-layout");
  }

  auto
  HeaderBar::property_decoration_layout () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "decoration-layout");
  }

  auto
  HeaderBar::property_show_end_title_buttons () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-end-title-buttons");
  }

  auto
  HeaderBar::property_show_end_title_buttons () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-end-title-buttons");
  }

  auto
  HeaderBar::property_show_start_title_buttons () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-start-title-buttons");
  }

  auto
  HeaderBar::property_show_start_title_buttons () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this,
                                               "show-start-title-buttons");
  }

  auto
  HeaderBar::property_title_widget () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "title-widget");
  }

  auto
  HeaderBar::property_title_widget () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "title-widget");
  }

} // namespace Adw
