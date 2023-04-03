// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/buttoncontent.hxx>
#include <libmm/adw/buttoncontent_p.hxx>

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
  wrap (AdwButtonContent* object, bool take_copy) -> Adw::ButtonContent*
  {
    return dynamic_cast<Adw::ButtonContent*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  ButtonContent_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_button_content_get_type ();
    }

    return *this;
  }

  auto
  ButtonContent_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ButtonContent ((AdwButtonContent*) (o)));
  }

  ButtonContent::ButtonContent (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  ButtonContent::ButtonContent (AdwButtonContent* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  ButtonContent::ButtonContent (ButtonContent&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  ButtonContent::operator= (ButtonContent&& src) noexcept -> ButtonContent&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (buttoncontent_class_.init ()))
  {
  }

  auto
  ButtonContent::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_icon_name (
            const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  ButtonContent::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_button_content_get_label (const_cast<AdwButtonContent*> (gobj ())));
  }

  auto
  ButtonContent::get_use_underline () const -> bool
  {
    return adw_button_content_get_use_underline (
        const_cast<AdwButtonContent*> (gobj ()));
  }

  auto
  ButtonContent::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_button_content_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ButtonContent::set_label (const Glib::ustring& label) -> void
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
  ButtonContent::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  ButtonContent::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  ButtonContent::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  ButtonContent::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  auto
  ButtonContent::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  ButtonContent::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace Adw
