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
  wrap (AdwButtonContent* object, bool take_copy) -> adw::ButtonContent*
  {
    return dynamic_cast<adw::ButtonContent*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  ButtonContent_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_button_content_get_type ();
    }

    return *this;
  }

  auto
  ButtonContent_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ButtonContent ((AdwButtonContent*) (o)));
  }

  ButtonContent::ButtonContent (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  ButtonContent::ButtonContent (AdwButtonContent* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ButtonContent::ButtonContent (ButtonContent&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  ButtonContent::operator= (ButtonContent&& src) noexcept -> ButtonContent&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  ButtonContent::~ButtonContent () noexcept
  {
    destroy_ ();
  }

  ButtonContent::CppClassType ButtonContent::buttoncontent_class_;

  auto
  ButtonContent::get_type () -> GType
  {
    return buttoncontent_class_.init ().get_type ();
  }

  auto
  ButtonContent::get_base_type () -> GType
  {
    return adw_button_content_get_type ();
  }

  ButtonContent::ButtonContent ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (buttoncontent_class_.init ()))
  {
  }

  auto
  ButtonContent::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_icon_name (
            const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  ButtonContent::get_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_label (const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  ButtonContent::get_use_underline () const -> bool
  {
    return adw_button_content_get_use_underline (
        const_cast<AdwButtonContent*> (gobj ()));
  }

  auto
  ButtonContent::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_button_content_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ButtonContent::set_label (const glib::ustring& label) -> void
  {
    adw_button_content_set_label (gobj (), label.c_str ());
  }

  auto
  ButtonContent::set_use_underline (bool use_underline) -> void
  {
    adw_button_content_set_use_underline (gobj (),
                                          static_cast<int> (use_underline));
  }

  auto
  ButtonContent::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  ButtonContent::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  ButtonContent::property_label () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  ButtonContent::property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "label"};
  }

  auto
  ButtonContent::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  ButtonContent::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
