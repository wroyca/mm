// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/slicelistmodel.hxx>
#include <libmm-gtk/slicelistmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSliceListModel* object, bool take_copy) -> Glib::RefPtr<Gtk::SliceListModel>
  {
    return Glib::make_refptr_for_instance<Gtk::SliceListModel> (
        dynamic_cast<Gtk::SliceListModel*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SliceListModel_Class::init () -> const Glib::Class&
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
  SliceListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SliceListModel ((GtkSliceListModel*) object);
  }

  auto
  SliceListModel::gobj_copy () -> GtkSliceListModel*
  {
    reference ();
    return gobj ();
  }

  SliceListModel::SliceListModel (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  SliceListModel::SliceListModel (GtkSliceListModel* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  SliceListModel::SliceListModel (SliceListModel&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src))
  {
  }

  auto
  SliceListModel::operator= (SliceListModel&& src) noexcept -> SliceListModel&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
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

  SliceListModel::SliceListModel (const Glib::RefPtr<Gio::ListModel>& model,
                                  guint offset,
                                  guint size)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (slicelistmodel_class_.init (),
                                           "model",
                                           Glib::unwrap (model),
                                           "offset",
                                           offset,
                                           "size",
                                           size,
                                           nullptr))
  {
  }

  auto
  SliceListModel::create (const Glib::RefPtr<Gio::ListModel>& model,
                          guint offset,
                          guint size) -> Glib::RefPtr<SliceListModel>
  {
    return Glib::make_refptr_for_instance<SliceListModel> (
        new SliceListModel (model, offset, size));
  }

  auto
  SliceListModel::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_slice_list_model_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  SliceListModel::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_slice_list_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SliceListModel::get_model () const -> Glib::RefPtr<const Gio::ListModel>
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
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SliceListModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SliceListModel::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  SliceListModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  SliceListModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

  auto
  SliceListModel::property_offset () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "offset");
  }

  auto
  SliceListModel::property_offset () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "offset");
  }

  auto
  SliceListModel::property_size () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "size");
  }

  auto
  SliceListModel::property_size () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "size");
  }

} // namespace Gtk
