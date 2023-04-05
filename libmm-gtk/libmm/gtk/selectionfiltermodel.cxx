// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/selectionfiltermodel.hxx>
#include <libmm/gtk/selectionfiltermodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkSelectionFilterModel* object, bool take_copy) -> glib::RefPtr<gtk::SelectionFilterModel>
  {
    return glib::make_refptr_for_instance<gtk::SelectionFilterModel> (
        dynamic_cast<gtk::SelectionFilterModel*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SelectionFilterModel_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SelectionFilterModel_Class::class_init_function;

      gtype_ = gtk_selection_filter_model_get_type ();
    }

    return *this;
  }

  auto
  SelectionFilterModel_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SelectionFilterModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SelectionFilterModel ((GtkSelectionFilterModel*) object);
  }

  auto
  SelectionFilterModel::gobj_copy () -> GtkSelectionFilterModel*
  {
    reference ();
    return gobj ();
  }

  SelectionFilterModel::SelectionFilterModel (
      const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SelectionFilterModel::SelectionFilterModel (GtkSelectionFilterModel* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SelectionFilterModel::SelectionFilterModel (
      SelectionFilterModel&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src))
  {
  }

  auto
  SelectionFilterModel::operator= (SelectionFilterModel&& src) noexcept -> SelectionFilterModel&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    return *this;
  }

  SelectionFilterModel::~SelectionFilterModel () noexcept {}

  SelectionFilterModel::CppClassType
      SelectionFilterModel::selectionfiltermodel_class_;

  auto
  SelectionFilterModel::get_type () -> GType
  {
    return selectionfiltermodel_class_.init ().get_type ();
  }

  auto
  SelectionFilterModel::get_base_type () -> GType
  {
    return gtk_selection_filter_model_get_type ();
  }

  SelectionFilterModel::SelectionFilterModel (
      const glib::RefPtr<SelectionModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (selectionfiltermodel_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  SelectionFilterModel::create (const glib::RefPtr<SelectionModel>& model) -> glib::RefPtr<SelectionFilterModel>
  {
    return glib::make_refptr_for_instance<SelectionFilterModel> (
        new SelectionFilterModel (model));
  }

  auto
  SelectionFilterModel::set_model (const glib::RefPtr<SelectionModel>& model) -> void
  {
    gtk_selection_filter_model_set_model (gobj (), glib::unwrap (model));
  }

  auto
  SelectionFilterModel::get_model () -> glib::RefPtr<SelectionModel>
  {
    auto retvalue = glib::wrap (gtk_selection_filter_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SelectionFilterModel::get_model () const -> glib::RefPtr<const SelectionModel>
  {
    return const_cast<SelectionFilterModel*> (this)->get_model ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SelectionFilterModel::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<SelectionModel>>::value,
      "Type glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SelectionFilterModel::property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<SelectionModel>> (this, "model");
  }

  auto
  SelectionFilterModel::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>> (this,
                                                                       "model");
  }

  auto
  SelectionFilterModel::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
