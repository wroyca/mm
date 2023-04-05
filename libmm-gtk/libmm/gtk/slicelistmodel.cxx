// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/slicelistmodel.hxx>
#include <libmm/gtk/slicelistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSliceListModel* object, bool take_copy) -> glib::RefPtr<gtk::SliceListModel>
  {
    return glib::make_refptr_for_instance<gtk::SliceListModel> (
        dynamic_cast<gtk::SliceListModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SliceListModel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SliceListModel_Class::class_init_function;

      gtype_ = gtk_slice_list_model_get_type ();
    }

    return *this;
  }

  auto
  SliceListModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SliceListModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SliceListModel ((GtkSliceListModel*) object);
  }

  auto
  SliceListModel::gobj_copy () -> GtkSliceListModel*
  {
    reference ();
    return gobj ();
  }

  SliceListModel::SliceListModel (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SliceListModel::SliceListModel (GtkSliceListModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SliceListModel::SliceListModel (SliceListModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  SliceListModel::operator= (SliceListModel&& src) noexcept -> SliceListModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  SliceListModel::~SliceListModel () noexcept {}

  SliceListModel::CppClassType SliceListModel::slicelistmodel_class_;

  auto
  SliceListModel::get_type () -> GType
  {
    return slicelistmodel_class_.init ().get_type ();
  }

  auto
  SliceListModel::get_base_type () -> GType
  {
    return gtk_slice_list_model_get_type ();
  }

  SliceListModel::SliceListModel (const glib::RefPtr<gio::ListModel>& model,
                                  guint offset,
                                  guint size)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (slicelistmodel_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           "offset",
                                           offset,
                                           "size",
                                           size,
                                           nullptr))
  {
  }

  auto
  SliceListModel::create (const glib::RefPtr<gio::ListModel>& model,
                          guint offset,
                          guint size) -> glib::RefPtr<SliceListModel>
  {
    return glib::make_refptr_for_instance<SliceListModel> (
        new SliceListModel (model, offset, size));
  }

  auto
  SliceListModel::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_slice_list_model_set_model (gobj (), glib::unwrap (model));
  }

  auto
  SliceListModel::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_slice_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SliceListModel::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<SliceListModel*> (this)->get_model ();
  }

  auto
  SliceListModel::set_offset (guint offset) -> void
  {
    gtk_slice_list_model_set_offset (gobj (), offset);
  }

  auto
  SliceListModel::get_offset () const -> guint
  {
    return gtk_slice_list_model_get_offset (
        const_cast<GtkSliceListModel*> (gobj ()));
  }

  auto
  SliceListModel::set_size (guint size) -> void
  {
    gtk_slice_list_model_set_size (gobj (), size);
  }

  auto
  SliceListModel::get_size () const -> guint
  {
    return gtk_slice_list_model_get_size (
        const_cast<GtkSliceListModel*> (gobj ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SliceListModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SliceListModel::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  SliceListModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  SliceListModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  SliceListModel::property_offset () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "offset");
  }

  auto
  SliceListModel::property_offset () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "offset");
  }

  auto
  SliceListModel::property_size () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "size");
  }

  auto
  SliceListModel::property_size () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "size");
  }

} // namespace gtk
