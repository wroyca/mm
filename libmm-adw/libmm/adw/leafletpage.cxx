// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/leafletpage.hxx>
#include <libmm/adw/leafletpage_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
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
  wrap (AdwLeafletPage* object, bool take_copy) -> glib::RefPtr<adw::leaflet_page>
  {
    return glib::make_refptr_for_instance<adw::leaflet_page> (
        dynamic_cast<adw::leaflet_page*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  leaflet_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_page_get_type ();
    }

    return *this;
  }

  auto
  leaflet_page_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new leaflet_page ((AdwLeafletPage*) object);
  }

  auto
  leaflet_page::gobj_copy () -> AdwLeafletPage*
  {
    reference ();
    return gobj ();
  }

  leaflet_page::leaflet_page (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  leaflet_page::leaflet_page (AdwLeafletPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  leaflet_page::leaflet_page (leaflet_page&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  leaflet_page::operator= (leaflet_page&& src) noexcept -> leaflet_page&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  leaflet_page::~leaflet_page () noexcept {}

  leaflet_page::CppClassType leaflet_page::leafletpage_class_;

  auto
  leaflet_page::get_type () -> GType
  {
    return leafletpage_class_.init ().get_type ();
  }

  auto
  leaflet_page::get_base_type () -> GType
  {
    return adw_leaflet_page_get_type ();
  }

  leaflet_page::leaflet_page ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (leafletpage_class_.init ()))
  {
  }

  auto
  leaflet_page::create () -> glib::RefPtr<leaflet_page>
  {
    return glib::make_refptr_for_instance<leaflet_page> (new leaflet_page ());
  }

  auto
  leaflet_page::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_page_get_child (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  leaflet_page::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_page_get_name (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  leaflet_page::get_navigatable () const -> bool
  {
    return adw_leaflet_page_get_navigatable (
        const_cast<AdwLeafletPage*> (gobj ()));
  }

  auto
  leaflet_page::set_name (const glib::ustring& name) -> void
  {
    adw_leaflet_page_set_name (gobj (), name.c_str ());
  }

  auto
  leaflet_page::set_navigatable (bool navigatable) -> void
  {
    adw_leaflet_page_set_navigatable (gobj (), static_cast<int> (navigatable));
  }

  auto
  leaflet_page::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  leaflet_page::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  leaflet_page::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  leaflet_page::property_navigatable () -> glib::PropertyProxy<bool>
  {
    return {this, "navigatable"};
  }

  auto
  leaflet_page::property_navigatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "navigatable"};
  }

} // namespace adw
