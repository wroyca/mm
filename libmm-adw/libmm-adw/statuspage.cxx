// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/statuspage.hxx>
#include <libmm-adw/statuspage_p.hxx>

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
  wrap (AdwStatusPage* object, bool take_copy) -> Adw::StatusPage*
  {
    return dynamic_cast<Adw::StatusPage*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  StatusPage_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_status_page_get_type ();
    }

    return *this;
  }

  auto
  StatusPage_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new StatusPage ((AdwStatusPage*) (o)));
  }

  StatusPage::StatusPage (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  StatusPage::StatusPage (AdwStatusPage* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  StatusPage::StatusPage (StatusPage&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  StatusPage::operator= (StatusPage&& src) noexcept -> StatusPage&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (statuspage_class_.init ()))
  {
  }

  auto
  StatusPage::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_status_page_get_child (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_description (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_icon_name (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::get_paintable () const -> Glib::RefPtr<Gdk::Paintable>
  {
    auto retvalue = Glib::wrap (
        adw_status_page_get_paintable (const_cast<AdwStatusPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  StatusPage::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_status_page_get_title (const_cast<AdwStatusPage*> (gobj ())));
  }

  auto
  StatusPage::set_child (Gtk::Widget* child) -> void
  {
    adw_status_page_set_child (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  StatusPage::set_description (const Glib::ustring& description) -> void
  {
    adw_status_page_set_description (gobj (), description.c_str ());
  }

  auto
  StatusPage::set_icon_name (const Glib::ustring& description) -> void
  {
    adw_status_page_set_icon_name (
        gobj (),
        description.empty () ? nullptr : description.c_str ());
  }

  auto
  StatusPage::set_paintable (const Glib::RefPtr<Gdk::Paintable>& paintable) -> void
  {
    adw_status_page_set_paintable (gobj (), Glib::unwrap (paintable));
  }

  auto
  StatusPage::set_title (const Glib::ustring& title) -> void
  {
    adw_status_page_set_title (gobj (), title.c_str ());
  }

  auto
  StatusPage::property_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "child");
  }

  auto
  StatusPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  StatusPage::property_description () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "description");
  }

  auto
  StatusPage::property_description () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "description");
  }

  auto
  StatusPage::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  StatusPage::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gdk::Paintable>>::value,
      "Type Glib::RefPtr<Gdk::Paintable> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  StatusPage::property_paintable () -> Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gdk::Paintable>> (this,
                                                              "paintable");
  }

  auto
  StatusPage::property_paintable () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Paintable>> (
        this,
        "paintable");
  }

  auto
  StatusPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  StatusPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

} // namespace Adw
