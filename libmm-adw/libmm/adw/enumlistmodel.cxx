// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/enumlistmodel.hxx>
#include <libmm/adw/enumlistmodel_p.hxx>

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
  wrap (AdwEnumListModel* object, bool take_copy) -> Glib::RefPtr<Adw::EnumListModel>
  {
    return Glib::make_refptr_for_instance<Adw::EnumListModel> (
        dynamic_cast<Adw::EnumListModel*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  EnumListModel_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_model_get_type ();
    }

    return *this;
  }

  auto
  EnumListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new EnumListModel ((AdwEnumListModel*) object);
  }

  auto
  EnumListModel::gobj_copy () -> AdwEnumListModel*
  {
    reference ();
    return gobj ();
  }

  EnumListModel::EnumListModel (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  EnumListModel::EnumListModel (AdwEnumListModel* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  EnumListModel::EnumListModel (EnumListModel&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src))
  {
  }

  auto
  EnumListModel::operator= (EnumListModel&& src) noexcept -> EnumListModel&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
    return *this;
  }

  EnumListModel::~EnumListModel () noexcept {}

  EnumListModel::CppClassType EnumListModel::enumlistmodel_class_;

  auto
  EnumListModel::get_type () -> GType
  {
    return enumlistmodel_class_.init ().get_type ();
  }

  auto
  EnumListModel::get_base_type () -> GType
  {
    return adw_enum_list_model_get_type ();
  }

  EnumListModel::EnumListModel ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (enumlistmodel_class_.init ()))
  {
  }

  EnumListModel::EnumListModel (GType enum_type)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (enumlistmodel_class_.init (),
                                           "enum_type",
                                           enum_type,
                                           nullptr))
  {
  }

  auto
  EnumListModel::create (GType enum_type) -> Glib::RefPtr<EnumListModel>
  {
    return Glib::make_refptr_for_instance<EnumListModel> (
        new EnumListModel (enum_type));
  }

  auto
  EnumListModel::find_position (int value) const -> guint
  {
    return adw_enum_list_model_find_position (
        const_cast<AdwEnumListModel*> (gobj ()),
        value);
  }

  auto
  EnumListModel::get_enum_type () const -> GType
  {
    return adw_enum_list_model_get_enum_type (
        const_cast<AdwEnumListModel*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  EnumListModel::property_enum_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "enum-type");
  }

} // namespace Adw
