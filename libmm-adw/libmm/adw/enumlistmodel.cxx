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
  wrap (AdwEnumListModel* object, bool take_copy) -> glib::RefPtr<adw::enum_list_model>
  {
    return glib::make_refptr_for_instance<adw::enum_list_model> (
        dynamic_cast<adw::enum_list_model*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  enum_list_model_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_enum_list_model_get_type ();
    }

    return *this;
  }

  auto
  enum_list_model_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new enum_list_model ((AdwEnumListModel*) object);
  }

  auto
  enum_list_model::gobj_copy () -> AdwEnumListModel*
  {
    reference ();
    return gobj ();
  }

  enum_list_model::enum_list_model (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  enum_list_model::enum_list_model (AdwEnumListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  enum_list_model::enum_list_model (enum_list_model&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  enum_list_model::operator= (enum_list_model&& src) noexcept -> enum_list_model&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  enum_list_model::~enum_list_model () noexcept {}

  enum_list_model::CppClassType enum_list_model::enumlistmodel_class_;

  auto
  enum_list_model::get_type () -> GType
  {
    return enumlistmodel_class_.init ().get_type ();
  }

  auto
  enum_list_model::get_base_type () -> GType
  {
    return adw_enum_list_model_get_type ();
  }

  enum_list_model::enum_list_model ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistmodel_class_.init ()))
  {
  }

  enum_list_model::enum_list_model (GType enum_type)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (enumlistmodel_class_.init (),
                                           "enum_type",
                                           enum_type,
                                           nullptr))
  {
  }

  auto
  enum_list_model::create (GType enum_type) -> glib::RefPtr<enum_list_model>
  {
    return glib::make_refptr_for_instance<enum_list_model> (
        new enum_list_model (enum_type));
  }

  auto
  enum_list_model::find_position (int value) const -> guint
  {
    return adw_enum_list_model_find_position (
        const_cast<AdwEnumListModel*> (gobj ()),
        value);
  }

  auto
  enum_list_model::get_enum_type () const -> GType
  {
    return adw_enum_list_model_get_enum_type (
        const_cast<AdwEnumListModel*> (gobj ()));
  }

  auto
  enum_list_model::property_enum_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "enum-type"};
  }

} // namespace adw
