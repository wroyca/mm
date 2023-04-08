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
  wrap (AdwAvatar* object, bool take_copy) -> adw::avatar*
  {
    return dynamic_cast<adw::avatar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  avatar_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_avatar_get_type ();
    }

    return *this;
  }

  auto
  avatar_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new avatar ((AdwAvatar*) (o)));
  }

  avatar::avatar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  avatar::avatar (AdwAvatar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  avatar::avatar (avatar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  avatar::operator= (avatar&& src) noexcept -> avatar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  avatar::~avatar () noexcept
  {
    destroy_ ();
  }

  avatar::CppClassType avatar::avatar_class_;

  auto
  avatar::get_type () -> GType
  {
    return avatar_class_.init ().get_type ();
  }

  auto
  avatar::get_base_type () -> GType
  {
    return adw_avatar_get_type ();
  }

  avatar::avatar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (avatar_class_.init ()))
  {
  }

  avatar::avatar (int size, const glib::ustring& text, bool show_initials)
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
  avatar::draw_to_texture (int scale_factor) -> glib::RefPtr<gdk::Texture>
  {
    auto retvalue =
        glib::wrap (adw_avatar_draw_to_texture (gobj (), scale_factor));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  avatar::get_custom_image () const -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        adw_avatar_get_custom_image (const_cast<AdwAvatar*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  avatar::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_avatar_get_icon_name (const_cast<AdwAvatar*> (gobj ())));
  }

  auto
  avatar::get_show_initials () const -> bool
  {
    return adw_avatar_get_show_initials (const_cast<AdwAvatar*> (gobj ()));
  }

  auto
  avatar::get_size () const -> int
  {
    return adw_avatar_get_size (const_cast<AdwAvatar*> (gobj ()));
  }

  auto
  avatar::get_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_avatar_get_text (const_cast<AdwAvatar*> (gobj ())));
  }

  auto
  avatar::set_custom_image (const glib::RefPtr<gdk::Paintable>& custom_image) -> void
  {
    adw_avatar_set_custom_image (gobj (), glib::unwrap (custom_image));
  }

  auto
  avatar::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_avatar_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  avatar::set_show_initials (bool show_initials) -> void
  {
    adw_avatar_set_show_initials (gobj (), static_cast<int> (show_initials));
  }

  auto
  avatar::set_size (int size) -> void
  {
    adw_avatar_set_size (gobj (), size);
  }

  auto
  avatar::set_text (const glib::ustring& text) -> void
  {
    adw_avatar_set_text (gobj (), text.c_str ());
  }

  auto
  avatar::property_size () -> glib::PropertyProxy<int>
  {
    return {this, "size"};
  }

  auto
  avatar::property_size () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "size"};
  }

  auto
  avatar::property_custom_image () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "custom-image"};
  }

  auto
  avatar::property_custom_image () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "custom-image"};
  }

  auto
  avatar::property_show_initials () -> glib::PropertyProxy<bool>
  {
    return {this, "show-initials"};
  }

  auto
  avatar::property_show_initials () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-initials"};
  }

  auto
  avatar::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "text"};
  }

  auto
  avatar::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "text"};
  }

  auto
  avatar::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  avatar::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

} // namespace adw
