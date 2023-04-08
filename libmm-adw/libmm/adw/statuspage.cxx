// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/statuspage.hxx>
#include <libmm/adw/statuspage_p.hxx>

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
  wrap (AdwStatusPage* object, bool take_copy) -> adw::status_page*
  {
    return dynamic_cast<adw::status_page*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  status_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_status_page_get_type ();
    }

    return *this;
  }

  auto
  status_page_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new status_page ((AdwStatusPage*) (o)));
  }

  status_page::status_page (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  status_page::status_page (AdwStatusPage* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  status_page::status_page (status_page&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  status_page::operator= (status_page&& src) noexcept -> status_page&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  status_page::~status_page () noexcept
  {
    destroy_ ();
  }

  status_page::CppClassType status_page::statuspage_class_;

  auto
  status_page::get_type () -> GType
  {
    return statuspage_class_.init ().get_type ();
  }

  auto
  status_page::get_base_type () -> GType
  {
    return adw_status_page_get_type ();
  }

  status_page::status_page ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (statuspage_class_.init ()))
  {
  }

  auto
  status_page::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_status_page_get_child (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  status_page::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_description (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  status_page::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_icon_name (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  status_page::get_paintable () const -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        adw_status_page_get_paintable (const_cast<AdwStatusPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  status_page::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_title (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  status_page::set_child (gtk::Widget* child) -> void
  {
    adw_status_page_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  status_page::set_description (const glib::ustring& description) -> void
  {
    adw_status_page_set_description (gobj (), description.c_str ());
  }

  auto
  status_page::set_icon_name (const glib::ustring& description) -> void
  {
    adw_status_page_set_icon_name (
        gobj (),
        description.empty () ? nullptr : description.c_str ());
  }

  auto
  status_page::set_paintable (const glib::RefPtr<gdk::Paintable>& paintable) -> void
  {
    adw_status_page_set_paintable (gobj (), glib::unwrap (paintable));
  }

  auto
  status_page::set_title (const glib::ustring& title) -> void
  {
    adw_status_page_set_title (gobj (), title.c_str ());
  }

  auto
  status_page::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  status_page::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  status_page::property_description () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  status_page::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  status_page::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  status_page::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  status_page::property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "paintable"};
  }

  auto
  status_page::property_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return {this, "paintable"};
  }

  auto
  status_page::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  status_page::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

} // namespace adw
