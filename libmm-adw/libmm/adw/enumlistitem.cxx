// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/enumlistitem.hxx>
#include <libmm/adw/enumlistitem_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwEnumListItem* object, bool take_copy) -> Glib::RefPtr<Adw::EnumListItem>
  {
    return Glib::make_refptr_for_instance<Adw::EnumListItem> (
        dynamic_cast<Adw::EnumListItem*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  EnumListItem_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_item_get_type ();
    }

    return *this;
  }

  auto
  EnumListItem_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EnumListItem ((AdwEnumListItem*) object);
  }

  auto
  EnumListItem::gobj_copy () -> AdwEnumListItem*
  {
    reference ();
    return gobj ();
  }

  EnumListItem::EnumListItem (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  EnumListItem::EnumListItem (AdwEnumListItem* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  EnumListItem::EnumListItem (EnumListItem&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  EnumListItem::operator= (EnumListItem&& src) noexcept -> EnumListItem&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (enumlistitem_class_.init ()))
  {
  }

  auto
  EnumListItem::create () -> Glib::RefPtr<EnumListItem>
  {
    return Glib::make_refptr_for_instance<EnumListItem> (new EnumListItem ());
  }

  auto
  EnumListItem::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_name (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  EnumListItem::get_nick () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_enum_list_item_get_nick (const_cast<AdwEnumListItem*> (gobj ())));
  }

  auto
  EnumListItem::get_value () const -> int
  {
    return adw_enum_list_item_get_value (
        const_cast<AdwEnumListItem*> (gobj ()));
  }

  auto
  EnumListItem::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  EnumListItem::property_nick () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "nick");
  }

  auto
  EnumListItem::property_value () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "value");
  }

} // namespace Adw
