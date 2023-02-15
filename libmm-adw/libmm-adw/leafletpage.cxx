// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/leafletpage.hxx>
#include <libmm-adw/leafletpage_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>
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
  wrap (AdwLeafletPage* object, bool take_copy) -> Glib::RefPtr<Adw::LeafletPage>
  {
    return Glib::make_refptr_for_instance<Adw::LeafletPage> (
        dynamic_cast<Adw::LeafletPage*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  LeafletPage_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_leaflet_page_get_type ();
    }

    return *this;
  }

  auto
  LeafletPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new LeafletPage ((AdwLeafletPage*) object);
  }

  auto
  LeafletPage::gobj_copy () -> AdwLeafletPage*
  {
    reference ();
    return gobj ();
  }

  LeafletPage::LeafletPage (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  LeafletPage::LeafletPage (AdwLeafletPage* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  LeafletPage::LeafletPage (LeafletPage&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  LeafletPage::operator= (LeafletPage&& src) noexcept -> LeafletPage&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (leafletpage_class_.init ()))
  {
  }

  auto
  LeafletPage::create () -> Glib::RefPtr<LeafletPage>
  {
    return Glib::make_refptr_for_instance<LeafletPage> (new LeafletPage ());
  }

  auto
  LeafletPage::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_leaflet_page_get_child (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  LeafletPage::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_leaflet_page_get_name (const_cast<AdwLeafletPage*> (gobj ())));
  }

  auto
  LeafletPage::get_navigatable () const -> bool
  {
    return adw_leaflet_page_get_navigatable (
        const_cast<AdwLeafletPage*> (gobj ()));
  }

  auto
  LeafletPage::set_name (const Glib::ustring& name) -> void
  {
    adw_leaflet_page_set_name (gobj (), name.c_str ());
  }

  auto
  LeafletPage::set_navigatable (bool navigatable) -> void
  {
    adw_leaflet_page_set_navigatable (gobj (), static_cast<int> (navigatable));
  }

  auto
  LeafletPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  LeafletPage::property_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "name");
  }

  auto
  LeafletPage::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  LeafletPage::property_navigatable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "navigatable");
  }

  auto
  LeafletPage::property_navigatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "navigatable");
  }

} // namespace Adw
