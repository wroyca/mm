// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/multiselection.hxx>
#include <libmm/gtk/multiselection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMultiSelection* object, bool take_copy) -> Glib::RefPtr<Gtk::MultiSelection>
  {
    return Glib::make_refptr_for_instance<Gtk::MultiSelection> (
        dynamic_cast<Gtk::MultiSelection*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MultiSelection_Class::init () -> const Glib::Class&
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
  MultiSelection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MultiSelection ((GtkMultiSelection*) object);
  }

  auto
  MultiSelection::gobj_copy () -> GtkMultiSelection*
  {
    reference ();
    return gobj ();
  }

  MultiSelection::MultiSelection (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  MultiSelection::MultiSelection (GtkMultiSelection* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  MultiSelection::MultiSelection (MultiSelection&& src) noexcept
    : Glib::Object (std::move (src)),
      Gio::ListModel (std::move (src)),
      SelectionModel (std::move (src))
  {
  }

  auto
  MultiSelection::operator= (MultiSelection&& src) noexcept -> MultiSelection&
  {
    Glib::Object::operator= (std::move (src));
    Gio::ListModel::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (multiselection_class_.init ()))
  {
  }

  MultiSelection::MultiSelection (const Glib::RefPtr<Gio::ListModel>& model)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (multiselection_class_.init (),
                                           "model",
                                           Glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  MultiSelection::create () -> Glib::RefPtr<MultiSelection>
  {
    return Glib::make_refptr_for_instance<MultiSelection> (
        new MultiSelection ());
  }

  auto
  MultiSelection::create (const Glib::RefPtr<Gio::ListModel>& model) -> Glib::RefPtr<MultiSelection>
  {
    return Glib::make_refptr_for_instance<MultiSelection> (
        new MultiSelection (model));
  }

  auto
  MultiSelection::get_model () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_multi_selection_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MultiSelection::get_model () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<MultiSelection*> (this)->get_model ();
  }

  auto
  MultiSelection::set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void
  {
    gtk_multi_selection_set_model (gobj (), Glib::unwrap (model));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MultiSelection::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return Glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MultiSelection::property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "model");
  }

  auto
  MultiSelection::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  MultiSelection::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace Gtk
