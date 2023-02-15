// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/windowtitle.hxx>
#include <libmm-adw/windowtitle_p.hxx>

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
  wrap (AdwWindowTitle* object, bool take_copy) -> Adw::WindowTitle*
  {
    return dynamic_cast<Adw::WindowTitle*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  WindowTitle_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_window_title_get_type ();
    }

    return *this;
  }

  auto
  WindowTitle_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new WindowTitle ((AdwWindowTitle*) (o)));
  }

  WindowTitle::WindowTitle (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  WindowTitle::WindowTitle (AdwWindowTitle* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  WindowTitle::WindowTitle (WindowTitle&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  WindowTitle::operator= (WindowTitle&& src) noexcept -> WindowTitle&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  WindowTitle::~WindowTitle () noexcept
  {
    destroy_ ();
  }

  WindowTitle::CppClassType WindowTitle::windowtitle_class_;

  auto
  WindowTitle::get_type () -> GType
  {
    return windowtitle_class_.init ().get_type ();
  }

  auto
  WindowTitle::get_base_type () -> GType
  {
    return adw_window_title_get_type ();
  }

  WindowTitle::WindowTitle ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (windowtitle_class_.init ()))
  {
  }

  WindowTitle::WindowTitle (const Glib::ustring& title,
                            const Glib::ustring& subtitle)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (windowtitle_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "subtitle",
                                          subtitle.c_str (),
                                          nullptr))
  {
  }

  auto
  WindowTitle::get_subtitle () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_subtitle (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  WindowTitle::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_title (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  WindowTitle::set_subtitle (const Glib::ustring& str) -> void
  {
    adw_window_title_set_subtitle (gobj (), str.c_str ());
  }

  auto
  WindowTitle::set_title (const Glib::ustring& str) -> void
  {
    adw_window_title_set_title (gobj (), str.c_str ());
  }

  auto
  WindowTitle::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  WindowTitle::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  WindowTitle::property_subtitle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "subtitle");
  }

  auto
  WindowTitle::property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "subtitle");
  }

} // namespace Adw
