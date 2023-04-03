// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/avatar.hxx>
#include <libmm/adw/avatar_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwAvatar* object, bool take_copy) -> Adw::Avatar*
  {
    return dynamic_cast<Adw::Avatar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  Avatar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_avatar_get_type ();
    }

    return *this;
  }

  auto
  Avatar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Avatar ((AdwAvatar*) (o)));
  }

  Avatar::Avatar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  Avatar::Avatar (AdwAvatar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  Avatar::Avatar (Avatar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  Avatar::operator= (Avatar&& src) noexcept -> Avatar&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (avatar_class_.init ()))
  {
  }

  Avatar::Avatar (int size, const Glib::ustring& text, bool show_initials)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (avatar_class_.init (),
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
  Avatar::draw_to_texture (int scale_factor) -> Glib::RefPtr<Gdk::Texture>
  {
    auto retvalue =
        Glib::wrap (adw_avatar_draw_to_texture (gobj (), scale_factor));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Avatar::get_custom_image () const -> Glib::RefPtr<Gdk::Paintable>
  {
    auto retvalue = Glib::wrap (
        adw_avatar_get_custom_image (const_cast<AdwAvatar*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Avatar::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  Avatar::get_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_avatar_get_text (const_cast<AdwAvatar*> (gobj ())));
  }

  auto
  Avatar::set_custom_image (const Glib::RefPtr<Gdk::Paintable>& custom_image) -> void
  {
    adw_avatar_set_custom_image (gobj (), Glib::unwrap (custom_image));
  }

  auto
  Avatar::set_icon_name (const Glib::ustring& icon_name) -> void
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
  Avatar::set_text (const Glib::ustring& text) -> void
  {
    adw_avatar_set_text (gobj (), text.c_str ());
  }

  auto
  Avatar::property_size () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "size");
  }

  auto
  Avatar::property_size () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "size");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Paintable>>::value,
      "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Avatar::property_custom_image () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>> (this,
                                                              "custom-image");
  }

  auto
  Avatar::property_custom_image () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "custom-image");
  }

  auto
  Avatar::property_show_initials () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-initials");
  }

  auto
  Avatar::property_show_initials () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-initials");
  }

  auto
  Avatar::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text");
  }

  auto
  Avatar::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text");
  }

  auto
  Avatar::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  Avatar::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

} // namespace Adw
