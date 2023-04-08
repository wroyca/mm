// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/enumlistmodel.hxx>
#include <libmm/adw/enumlistmodel_p.hxx>

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
  wrap (AdwEnumListModel* object, bool take_copy) -> glib::RefPtr<adw::EnumListModel>
  {
    return glib::make_refptr_for_instance<adw::EnumListModel> (
        dynamic_cast<adw::EnumListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  EnumListModel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_model_get_type ();
    }

    return *this;
  }

  auto
  EnumListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new EnumListModel ((AdwEnumListModel*) object);
  }

  auto
  EnumListModel::gobj_copy () -> AdwEnumListModel*
  {
    reference ();
    return gobj ();
  }

  EnumListModel::EnumListModel (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  EnumListModel::EnumListModel (AdwEnumListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  EnumListModel::EnumListModel (EnumListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  EnumListModel::operator= (EnumListModel&& src) noexcept -> EnumListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistmodel_class_.init ()))
  {
  }

  EnumListModel::EnumListModel (GType enum_type)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistmodel_class_.init (),
                                           "enum_type",
                                           enum_type,
                                           nullptr))
  {
  }

  auto
  EnumListModel::create (GType enum_type) -> glib::RefPtr<EnumListModel>
  {
    return glib::make_refptr_for_instance<EnumListModel> (
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

  auto
  EnumListModel::property_enum_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "enum-type"};
  }

} // namespace adw
