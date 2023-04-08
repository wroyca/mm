// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/headerbar.hxx>
#include <libmm/adw/headerbar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

auto
glib::Value<adw::CenteringPolicy>::value_type () -> GType
{
  return adw_centering_policy_get_type ();
}

namespace glib
{

  auto
  wrap (AdwHeaderBar* object, bool take_copy) -> adw::header_bar*
  {
    return dynamic_cast<adw::header_bar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  header_bar_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_header_bar_get_type ();
    }

    return *this;
  }

  auto
  header_bar_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new header_bar ((AdwHeaderBar*) (o)));
  }

  header_bar::header_bar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  header_bar::header_bar (AdwHeaderBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  header_bar::header_bar (header_bar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  header_bar::operator= (header_bar&& src) noexcept -> header_bar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  header_bar::~header_bar () noexcept
  {
    destroy_ ();
  }

  header_bar::CppClassType header_bar::headerbar_class_;

  auto
  header_bar::get_type () -> GType
  {
    return headerbar_class_.init ().get_type ();
  }

  auto
  header_bar::get_base_type () -> GType
  {
    return adw_header_bar_get_type ();
  }

  header_bar::header_bar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (headerbar_class_.init ()))
  {
  }

  auto
  header_bar::get_centering_policy () const -> CenteringPolicy
  {
    return static_cast<CenteringPolicy> (adw_header_bar_get_centering_policy (
        const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  header_bar::get_decoration_layout () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_header_bar_get_decoration_layout (
            const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  header_bar::get_show_end_title_buttons () const -> bool
  {
    return adw_header_bar_get_show_end_title_buttons (
        const_cast<AdwHeaderBar*> (gobj ()));
  }

  auto
  header_bar::get_show_start_title_buttons () const -> bool
  {
    return adw_header_bar_get_show_start_title_buttons (
        const_cast<AdwHeaderBar*> (gobj ()));
  }

  auto
  header_bar::get_title_widget () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_header_bar_get_title_widget (const_cast<AdwHeaderBar*> (gobj ())));
  }

  auto
  header_bar::pack_end (gtk::Widget* child) -> void
  {
    adw_header_bar_pack_end (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  header_bar::pack_start (gtk::Widget* child) -> void
  {
    adw_header_bar_pack_start (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  header_bar::remove (gtk::Widget* child) -> void
  {
    adw_header_bar_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  header_bar::set_centering_policy (CenteringPolicy centering_policy) -> void
  {
    adw_header_bar_set_centering_policy (
        gobj (),
        static_cast<AdwCenteringPolicy> (centering_policy));
  }

  auto
  header_bar::set_decoration_layout (const glib::ustring& layout) -> void
  {
    adw_header_bar_set_decoration_layout (gobj (), layout.c_str ());
  }

  auto
  header_bar::set_show_end_title_buttons (bool setting) -> void
  {
    adw_header_bar_set_show_end_title_buttons (gobj (),
                                               static_cast<int> (setting));
  }

  auto
  header_bar::set_show_start_title_buttons (bool setting) -> void
  {
    adw_header_bar_set_show_start_title_buttons (gobj (),
                                                 static_cast<int> (setting));
  }

  auto
  header_bar::set_title_widget (gtk::Widget* title_widget) -> void
  {
    adw_header_bar_set_title_widget (gobj (),
                                     (GtkWidget*) glib::unwrap (title_widget));
  }

  auto
  header_bar::property_centering_policy () -> glib::PropertyProxy<CenteringPolicy>
  {
    return {this, "centering-policy"};
  }

  auto
  header_bar::property_centering_policy () const -> glib::PropertyProxy_ReadOnly<CenteringPolicy>
  {
    return {this, "centering-policy"};
  }

  auto
  header_bar::property_decoration_layout () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "decoration-layout"};
  }

  auto
  header_bar::property_decoration_layout () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "decoration-layout"};
  }

  auto
  header_bar::property_show_end_title_buttons () -> glib::PropertyProxy<bool>
  {
    return {this, "show-end-title-buttons"};
  }

  auto
  header_bar::property_show_end_title_buttons () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-end-title-buttons"};
  }

  auto
  header_bar::property_show_start_title_buttons () -> glib::PropertyProxy<bool>
  {
    return {this, "show-start-title-buttons"};
  }

  auto
  header_bar::property_show_start_title_buttons () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-start-title-buttons"};
  }

  auto
  header_bar::property_title_widget () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "title-widget"};
  }

  auto
  header_bar::property_title_widget () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "title-widget"};
  }

} // namespace adw
