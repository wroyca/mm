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
  wrap (AdwStatusPage* object, bool take_copy) -> adw::StatusPage*
  {
    return dynamic_cast<adw::StatusPage*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  StatusPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_status_page_get_type ();
    }

    return *this;
  }

  auto
  StatusPage_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new StatusPage ((AdwStatusPage*) (o)));
  }

  StatusPage::StatusPage (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  StatusPage::StatusPage (AdwStatusPage* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  StatusPage::StatusPage (StatusPage&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  StatusPage::operator= (StatusPage&& src) noexcept -> StatusPage&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  StatusPage::~StatusPage () noexcept
  {
    destroy_ ();
  }

  StatusPage::CppClassType StatusPage::statuspage_class_;

  auto
  StatusPage::get_type () -> GType
  {
    return statuspage_class_.init ().get_type ();
  }

  auto
  StatusPage::get_base_type () -> GType
  {
    return adw_status_page_get_type ();
  }

  StatusPage::StatusPage ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (statuspage_class_.init ()))
  {
  }

  auto
  StatusPage::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_status_page_get_child (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_description (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_icon_name (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_paintable () const -> glib::RefPtr<gdk::Paintable>
  {
    auto retvalue = glib::wrap (
        adw_status_page_get_paintable (const_cast<AdwStatusPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StatusPage::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_title (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::set_child (gtk::Widget* child) -> void
  {
    adw_status_page_set_child (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  StatusPage::set_description (const glib::ustring& description) -> void
  {
    adw_status_page_set_description (gobj (), description.c_str ());
  }

  auto
  StatusPage::set_icon_name (const glib::ustring& description) -> void
  {
    adw_status_page_set_icon_name (
        gobj (),
        description.empty () ? nullptr : description.c_str ());
  }

  auto
  StatusPage::set_paintable (const glib::RefPtr<gdk::Paintable>& paintable) -> void
  {
    adw_status_page_set_paintable (gobj (), glib::unwrap (paintable));
  }

  auto
  StatusPage::set_title (const glib::ustring& title) -> void
  {
    adw_status_page_set_title (gobj (), title.c_str ());
  }

  auto
  StatusPage::property_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return glib::PropertyProxy<gtk::Widget*> (this, "child");
  }

  auto
  StatusPage::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  StatusPage::property_description () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "description");
  }

  auto
  StatusPage::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "description");
  }

  auto
  StatusPage::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  StatusPage::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::Paintable>>::value,
      "Type glib::RefPtr<gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  StatusPage::property_paintable () -> glib::PropertyProxy<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy<glib::RefPtr<gdk::Paintable>> (this,
                                                              "paintable");
  }

  auto
  StatusPage::property_paintable () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Paintable>> (
        this,
        "paintable");
  }

  auto
  StatusPage::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  StatusPage::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

} // namespace adw
