

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/noselection.hxx>
#include <libmm-gtk/noselection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkNoSelection* object, const bool take_copy) -> RefPtr<Gtk::NoSelection>
  {
    return Glib::make_refptr_for_instance<Gtk::NoSelection> (
        dynamic_cast<Gtk::NoSelection*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  NoSelection_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &NoSelection_Class::class_init_function;

      gtype_ = gtk_no_selection_get_type ();
    }

    return *this;
  }

  auto
  NoSelection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  NoSelection_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new NoSelection ((GtkNoSelection*) object);
  }

  auto
  NoSelection::gobj_copy () -> GtkNoSelection*
  {
    reference ();
    return gobj ();
  }

  NoSelection::NoSelection (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  NoSelection::NoSelection (GtkNoSelection* castitem)
    : Object ((GObject*) castitem)
  {
  }

  NoSelection::NoSelection (NoSelection&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src)),
      SelectionModel (std::move (src))
  {
  }

  auto
  NoSelection::operator= (NoSelection&& src) noexcept -> NoSelection&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    return *this;
  }

  NoSelection::~NoSelection () noexcept = default;

  NoSelection::CppClassType NoSelection::noselection_class_;

  auto
  NoSelection::get_type () -> GType
  {
    return noselection_class_.init ().get_type ();
  }

  auto
  NoSelection::get_base_type () -> GType
  {
    return gtk_no_selection_get_type ();
  }

  NoSelection::NoSelection ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (noselection_class_.init ()))
  {
  }

  NoSelection::NoSelection (const Glib::RefPtr<ListModel>& model)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (noselection_class_.init (),
                                     "model",
                                     Glib::unwrap (model),
                                     nullptr))
  {
  }

  auto
  NoSelection::create () -> Glib::RefPtr<NoSelection>
  {
    return Glib::make_refptr_for_instance<NoSelection> (new NoSelection ());
  }

  auto
  NoSelection::create (const Glib::RefPtr<ListModel>& model) -> Glib::RefPtr<NoSelection>
  {
    return Glib::make_refptr_for_instance<NoSelection> (
        new NoSelection (model));
  }

  auto
  NoSelection::get_model () -> Glib::RefPtr<ListModel>
  {
    auto retvalue = Glib::wrap (gtk_no_selection_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  NoSelection::get_model () const -> Glib::RefPtr<const ListModel>
  {
    return const_cast<NoSelection*> (this)->get_model ();
  }

  auto
  NoSelection::set_model (const Glib::RefPtr<ListModel>& model) -> void
  {
    gtk_no_selection_set_model (gobj (), Glib::unwrap (model));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  NoSelection::property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  NoSelection::property_model () -> Glib::PropertyProxy<Glib::RefPtr<ListModel>>
  {
    return {this, "model"};
  }

  auto
  NoSelection::property_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListModel>>
  {
    return {this, "model"};
  }

  auto
  NoSelection::property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

} // namespace Gtk
