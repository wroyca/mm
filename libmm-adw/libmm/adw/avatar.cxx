// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/avatar.hxx>
#include <libmm/adw/avatar_p.hxx>

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
  wrap (AdwAvatar* object, bool take_copy) -> adw::Avatar*
  {
    return dynamic_cast<adw::Avatar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  Avatar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_avatar_get_type ();
    }

    return *this;
  }

  auto
  Avatar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new Avatar ((AdwAvatar*) (o)));
  }

  Avatar::Avatar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  Avatar::Avatar (AdwAvatar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Avatar::Avatar (Avatar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  Avatar::operator= (Avatar&& src) noexcept -> Avatar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  Avatar::~Avatar () noexcept
  {
    destroy_ ();
  }

  Avatar::CppClassType Avatar::avatar_class_;

  auto
  Avatar::get_type () -> GType
  {
    return avatar_class_.init ().get_type ();
  }

  auto
  Avatar::get_base_type () -> GType
  {
    return adw_avatar_get_type ();
  }

  Avatar::Avatar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (avatar_class_.init ()))
  {
  }

  Avatar::Avatar (int size, const glib::ustring& text, bool show_initials)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (avatar_class_.init (),
                                          "size",
                                          size,
                                          "text",
                                          text.c_str (),
                                          "show_initials",
                                          static_cast<int> (show_initials),
                                          nullptr))
  {
  }

  auto
  Avatar::draw_to_texture (int scale_factor) -> glib::RefPtr<gdk::Texture>
  {
    auto retvalue =
        glib::wrap (adw_avatar_draw_to_texture (gobj (), scale_factor));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Avatar::get_custom_image () const -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        adw_avatar_get_custom_image (const_cast<AdwAvatar*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Avatar::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_avatar_get_icon_name (const_cast<AdwAvatar*> (gobj ())));
  }

  auto
  Avatar::get_show_initials () const -> bool
  {
    return adw_avatar_get_show_initials (const_cast<AdwAvatar*> (gobj ()));
  }

  auto
  Avatar::get_size () const -> int
  {
    return adw_avatar_get_size (const_cast<AdwAvatar*> (gobj ()));
  }

  auto
  Avatar::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_avatar_get_text (const_cast<AdwAvatar*> (gobj ())));
  }

  auto
  Avatar::set_custom_image (const glib::RefPtr<gdk::Paintable>& custom_image) -> void
  {
    adw_avatar_set_custom_image (gobj (), glib::unwrap (custom_image));
  }

  auto
  Avatar::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_avatar_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  Avatar::set_show_initials (bool show_initials) -> void
  {
    adw_avatar_set_show_initials (gobj (), static_cast<int> (show_initials));
  }

  auto
  Avatar::set_size (int size) -> void
  {
    adw_avatar_set_size (gobj (), size);
  }

  auto
  Avatar::set_text (const glib::ustring& text) -> void
  {
    adw_avatar_set_text (gobj (), text.c_str ());
  }

  auto
  Avatar::property_size () -> glib::PropertyProxy<int>
  {
    return {this, "size"};
  }

  auto
  Avatar::property_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "size"};
  }

  auto
  Avatar::property_custom_image () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "custom-image"};
  }

  auto
  Avatar::property_custom_image () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "custom-image"};
  }

  auto
  Avatar::property_show_initials () -> glib::PropertyProxy<bool>
  {
    return {this, "show-initials"};
  }

  auto
  Avatar::property_show_initials () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-initials"};
  }

  auto
  Avatar::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "text"};
  }

  auto
  Avatar::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "text"};
  }

  auto
  Avatar::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  Avatar::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

} // namespace adw
