// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/windowtitle.hxx>
#include <libmm/adw/windowtitle_p.hxx>

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
  wrap (AdwWindowTitle* object, bool take_copy) -> adw::WindowTitle*
  {
    return dynamic_cast<adw::WindowTitle*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  WindowTitle_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_window_title_get_type ();
    }

    return *this;
  }

  auto
  WindowTitle_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new WindowTitle ((AdwWindowTitle*) (o)));
  }

  WindowTitle::WindowTitle (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  WindowTitle::WindowTitle (AdwWindowTitle* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  WindowTitle::WindowTitle (WindowTitle&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  WindowTitle::operator= (WindowTitle&& src) noexcept -> WindowTitle&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (windowtitle_class_.init ()))
  {
  }

  WindowTitle::WindowTitle (const glib::ustring& title,
                            const glib::ustring& subtitle)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (windowtitle_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "subtitle",
                                          subtitle.c_str (),
                                          nullptr))
  {
  }

  auto
  WindowTitle::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_subtitle (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  WindowTitle::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_title (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  WindowTitle::set_subtitle (const glib::ustring& str) -> void
  {
    adw_window_title_set_subtitle (gobj (), str.c_str ());
  }

  auto
  WindowTitle::set_title (const glib::ustring& str) -> void
  {
    adw_window_title_set_title (gobj (), str.c_str ());
  }

  auto
  WindowTitle::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  WindowTitle::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  WindowTitle::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  WindowTitle::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

} // namespace adw
