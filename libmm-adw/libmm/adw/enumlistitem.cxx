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
  wrap (AdwEnumListItem* object, bool take_copy) -> glib::RefPtr<adw::EnumListItem>
  {
    return glib::make_refptr_for_instance<adw::EnumListItem> (
        dynamic_cast<adw::EnumListItem*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  EnumListItem_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_item_get_type ();
    }

    return *this;
  }

  auto
  EnumListItem_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EnumListItem ((AdwEnumListItem*) object);
  }

  auto
  EnumListItem::gobj_copy () -> AdwEnumListItem*
  {
    reference ();
    return gobj ();
  }

  EnumListItem::EnumListItem (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  EnumListItem::EnumListItem (AdwEnumListItem* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  EnumListItem::EnumListItem (EnumListItem&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  EnumListItem::operator= (EnumListItem&& src) noexcept -> EnumListItem&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  EnumListItem::~EnumListItem () noexcept {}

  EnumListItem::CppClassType EnumListItem::enumlistitem_class_;

  auto
  EnumListItem::get_type () -> GType
  {
    return enumlistitem_class_.init ().get_type ();
  }

  auto
  EnumListItem::get_base_type () -> GType
  {
    return adw_enum_list_item_get_type ();
  }

  EnumListItem::EnumListItem ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistitem_class_.init ()))
  {
  }

  auto
  EnumListItem::create () -> glib::RefPtr<EnumListItem>
  {
    return glib::make_refptr_for_instance<EnumListItem> (new EnumListItem ());
  }

  auto
  EnumListItem::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_name (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  EnumListItem::get_nick () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_nick (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  EnumListItem::get_value () const -> int
  {
    return adw_enum_list_item_get_value (
        const_cast<AdwEnumListItem*> (gobj ()));
  }

  auto
  EnumListItem::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  EnumListItem::property_nick () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "nick"};
  }

  auto
  EnumListItem::property_value () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "value"};
  }

} // namespace adw
