// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/buttoncontent.hxx>
#include <libmm/adw/buttoncontent_p.hxx>

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
  wrap (AdwButtonContent* object, bool take_copy) -> adw::button_content*
  {
    return dynamic_cast<adw::button_content*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  button_content_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_button_content_get_type ();
    }

    return *this;
  }

  auto
  button_content_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new button_content ((AdwButtonContent*) (o)));
  }

  button_content::button_content (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  button_content::button_content (AdwButtonContent* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  button_content::button_content (button_content&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  button_content::operator= (button_content&& src) noexcept -> button_content&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  button_content::~button_content () noexcept
  {
    destroy_ ();
  }

  button_content::CppClassType button_content::buttoncontent_class_;

  auto
  button_content::get_type () -> GType
  {
    return buttoncontent_class_.init ().get_type ();
  }

  auto
  button_content::get_base_type () -> GType
  {
    return adw_button_content_get_type ();
  }

  button_content::button_content ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (buttoncontent_class_.init ()))
  {
  }

  auto
  button_content::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_icon_name (
            const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  button_content::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_label (const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  button_content::get_use_underline () const -> bool
  {
    return adw_button_content_get_use_underline (
        const_cast<AdwButtonContent*> (gobj ()));
  }

  auto
  button_content::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_button_content_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  button_content::set_label (const glib::ustring& label) -> void
  {
    adw_button_content_set_label (gobj (), label.c_str ());
  }

  auto
  button_content::set_use_underline (bool use_underline) -> void
  {
    adw_button_content_set_use_underline (gobj (),
                                          static_cast<int> (use_underline));
  }

  auto
  button_content::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  button_content::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  button_content::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  button_content::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  button_content::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  button_content::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
