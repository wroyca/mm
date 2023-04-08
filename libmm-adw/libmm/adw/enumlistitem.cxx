// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/enumlistitem.hxx>
#include <libmm/adw/enumlistitem_p.hxx>

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
  wrap (AdwEnumListItem* object, bool take_copy) -> glib::RefPtr<adw::enum_list_item>
  {
    return glib::make_refptr_for_instance<adw::enum_list_item> (
        dynamic_cast<adw::enum_list_item*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  enum_list_item_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_item_get_type ();
    }

    return *this;
  }

  auto
  enum_list_item_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new enum_list_item ((AdwEnumListItem*) object);
  }

  auto
  enum_list_item::gobj_copy () -> AdwEnumListItem*
  {
    reference ();
    return gobj ();
  }

  enum_list_item::enum_list_item (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  enum_list_item::enum_list_item (AdwEnumListItem* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  enum_list_item::enum_list_item (enum_list_item&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  enum_list_item::operator= (enum_list_item&& src) noexcept -> enum_list_item&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  enum_list_item::~enum_list_item () noexcept {}

  enum_list_item::CppClassType enum_list_item::enumlistitem_class_;

  auto
  enum_list_item::get_type () -> GType
  {
    return enumlistitem_class_.init ().get_type ();
  }

  auto
  enum_list_item::get_base_type () -> GType
  {
    return adw_enum_list_item_get_type ();
  }

  enum_list_item::enum_list_item ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistitem_class_.init ()))
  {
  }

  auto
  enum_list_item::create () -> glib::RefPtr<enum_list_item>
  {
    return glib::make_refptr_for_instance<enum_list_item> (new enum_list_item ());
  }

  auto
  enum_list_item::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_name (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  enum_list_item::get_nick () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_nick (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  enum_list_item::get_value () const -> int
  {
    return adw_enum_list_item_get_value (
        const_cast<AdwEnumListItem*> (gobj ()));
  }

  auto
  enum_list_item::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  enum_list_item::property_nick () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "nick"};
  }

  auto
  enum_list_item::property_value () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "value"};
  }

} // namespace adw
