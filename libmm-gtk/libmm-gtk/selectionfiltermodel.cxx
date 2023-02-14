

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/selectionfiltermodel.hxx>
#include <libmm-gtk/selectionfiltermodel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkSelectionFilterModel* object, const bool take_copy) -> RefPtr<Gtk::SelectionFilterModel>
  {
    return Glib::make_refptr_for_instance<Gtk::SelectionFilterModel> (
        dynamic_cast<Gtk::SelectionFilterModel*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SelectionFilterModel_Class::init () -> const Class&
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
  SelectionFilterModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SelectionFilterModel::SelectionFilterModel (GtkSelectionFilterModel* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SelectionFilterModel::SelectionFilterModel (
      SelectionFilterModel&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  SelectionFilterModel::operator= (SelectionFilterModel&& src) noexcept -> SelectionFilterModel&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  SelectionFilterModel::~SelectionFilterModel () noexcept = default;

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
      const Glib::RefPtr<SelectionModel>& model)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (selectionfiltermodel_class_.init (),
                                     "model",
                                     Glib::unwrap (model),
                                     nullptr))
  {
  }

  auto
  SelectionFilterModel::create (const Glib::RefPtr<SelectionModel>& model) -> Glib::RefPtr<SelectionFilterModel>
  {
    return Glib::make_refptr_for_instance<SelectionFilterModel> (
        new SelectionFilterModel (model));
  }

  auto
  SelectionFilterModel::set_model (const Glib::RefPtr<SelectionModel>& model) -> void
  {
    gtk_selection_filter_model_set_model (gobj (), Glib::unwrap (model));
  }

  auto
  SelectionFilterModel::get_model () -> Glib::RefPtr<SelectionModel>
  {
    auto retvalue = Glib::wrap (gtk_selection_filter_model_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  SelectionFilterModel::get_model () const -> Glib::RefPtr<const SelectionModel>
  {
    return const_cast<SelectionFilterModel*> (this)->get_model ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SelectionFilterModel::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<SelectionModel>>::value,
      "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SelectionFilterModel::property_model () -> Glib::PropertyProxy<Glib::RefPtr<SelectionModel>>
  {
    return {this, "model"};
  }

  auto
  SelectionFilterModel::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>
  {
    return {this, "model"};
  }

  auto
  SelectionFilterModel::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

} // namespace Gtk
