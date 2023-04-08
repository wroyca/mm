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
  wrap (AdwWindowTitle* object, bool take_copy) -> adw::window_title*
  {
    return dynamic_cast<adw::window_title*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  window_title_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_window_title_get_type ();
    }

    return *this;
  }

  auto
  window_title_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new window_title ((AdwWindowTitle*) (o)));
  }

  window_title::window_title (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  window_title::window_title (AdwWindowTitle* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  window_title::window_title (window_title&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  window_title::operator= (window_title&& src) noexcept -> window_title&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  window_title::~window_title () noexcept
  {
    destroy_ ();
  }

  window_title::CppClassType window_title::windowtitle_class_;

  auto
  window_title::get_type () -> GType
  {
    return windowtitle_class_.init ().get_type ();
  }

  auto
  window_title::get_base_type () -> GType
  {
    return adw_window_title_get_type ();
  }

  window_title::window_title ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (windowtitle_class_.init ()))
  {
  }

  window_title::window_title (const glib::ustring& title,
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
  window_title::get_subtitle () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_subtitle (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  window_title::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_window_title_get_title (const_cast<AdwWindowTitle*> (gobj ())));
  }

  auto
  window_title::set_subtitle (const glib::ustring& str) -> void
  {
    adw_window_title_set_subtitle (gobj (), str.c_str ());
  }

  auto
  window_title::set_title (const glib::ustring& str) -> void
  {
    adw_window_title_set_title (gobj (), str.c_str ());
  }

  auto
  window_title::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  window_title::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  window_title::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "subtitle"};
  }

  auto
  window_title::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "subtitle"};
  }

} // namespace adw
