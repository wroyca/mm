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
  wrap (AdwLeafletPage* object, bool take_copy) -> glib::RefPtr<adw::LeafletPage>
  {
    return glib::make_refptr_for_instance<adw::LeafletPage> (
        dynamic_cast<adw::LeafletPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  LeafletPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_page_get_type ();
    }

    return *this;
  }

  auto
  LeafletPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new LeafletPage ((AdwLeafletPage*) object);
  }

  auto
  LeafletPage::gobj_copy () -> AdwLeafletPage*
  {
    reference ();
    return gobj ();
  }

  LeafletPage::LeafletPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  LeafletPage::LeafletPage (AdwLeafletPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  LeafletPage::LeafletPage (LeafletPage&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  LeafletPage::operator= (LeafletPage&& src) noexcept -> LeafletPage&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  LeafletPage::~LeafletPage () noexcept {}

  LeafletPage::CppClassType LeafletPage::leafletpage_class_;

  auto
  LeafletPage::get_type () -> GType
  {
    return leafletpage_class_.init ().get_type ();
  }

  auto
  LeafletPage::get_base_type () -> GType
  {
    return adw_leaflet_page_get_type ();
  }

  LeafletPage::LeafletPage ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (leafletpage_class_.init ()))
  {
  }

  auto
  LeafletPage::create () -> glib::RefPtr<LeafletPage>
  {
    return glib::make_refptr_for_instance<LeafletPage> (new LeafletPage ());
  }

  auto
  LeafletPage::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_leaflet_page_get_child (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  LeafletPage::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_page_get_name (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  LeafletPage::get_navigatable () const -> bool
  {
    return adw_leaflet_page_get_navigatable (
        const_cast<AdwLeafletPage*> (gobj ()));
  }

  auto
  LeafletPage::set_name (const glib::ustring& name) -> void
  {
    adw_leaflet_page_set_name (gobj (), name.c_str ());
  }

  auto
  LeafletPage::set_navigatable (bool navigatable) -> void
  {
    adw_leaflet_page_set_navigatable (gobj (), static_cast<int> (navigatable));
  }

  auto
  LeafletPage::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  LeafletPage::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  LeafletPage::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  LeafletPage::property_navigatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "navigatable");
  }

  auto
  LeafletPage::property_navigatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "navigatable");
  }

} // namespace adw
