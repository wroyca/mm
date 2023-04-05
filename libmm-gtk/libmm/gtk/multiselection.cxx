// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/multiselection.hxx>
#include <libmm/gtk/multiselection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkMultiSelection* object, bool take_copy) -> glib::RefPtr<gtk::MultiSelection>
  {
    return glib::make_refptr_for_instance<gtk::MultiSelection> (
        dynamic_cast<gtk::MultiSelection*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  MultiSelection_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MultiSelection_Class::class_init_function;

      gtype_ = gtk_multi_selection_get_type ();
    }

    return *this;
  }

  auto
  MultiSelection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MultiSelection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MultiSelection ((GtkMultiSelection*) object);
  }

  auto
  MultiSelection::gobj_copy () -> GtkMultiSelection*
  {
    reference ();
    return gobj ();
  }

  MultiSelection::MultiSelection (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  MultiSelection::MultiSelection (GtkMultiSelection* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  MultiSelection::MultiSelection (MultiSelection&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src)),
      SelectionModel (std::move (src))
  {
  }

  auto
  MultiSelection::operator= (MultiSelection&& src) noexcept -> MultiSelection&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    return *this;
  }

  MultiSelection::~MultiSelection () noexcept {}

  MultiSelection::CppClassType MultiSelection::multiselection_class_;

  auto
  MultiSelection::get_type () -> GType
  {
    return multiselection_class_.init ().get_type ();
  }

  auto
  MultiSelection::get_base_type () -> GType
  {
    return gtk_multi_selection_get_type ();
  }

  MultiSelection::MultiSelection ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (multiselection_class_.init ()))
  {
  }

  MultiSelection::MultiSelection (const glib::RefPtr<gio::ListModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (multiselection_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  MultiSelection::create () -> glib::RefPtr<MultiSelection>
  {
    return glib::make_refptr_for_instance<MultiSelection> (
        new MultiSelection ());
  }

  auto
  MultiSelection::create (const glib::RefPtr<gio::ListModel>& model) -> glib::RefPtr<MultiSelection>
  {
    return glib::make_refptr_for_instance<MultiSelection> (
        new MultiSelection (model));
  }

  auto
  MultiSelection::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_multi_selection_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MultiSelection::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<MultiSelection*> (this)->get_model ();
  }

  auto
  MultiSelection::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_multi_selection_set_model (gobj (), glib::unwrap (model));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MultiSelection::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MultiSelection::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  MultiSelection::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  MultiSelection::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
