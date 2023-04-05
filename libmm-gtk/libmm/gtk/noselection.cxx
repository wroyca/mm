// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/noselection.hxx>
#include <libmm/gtk/noselection_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkNoSelection* object, bool take_copy) -> glib::RefPtr<gtk::NoSelection>
  {
    return glib::make_refptr_for_instance<gtk::NoSelection> (
        dynamic_cast<gtk::NoSelection*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  NoSelection_Class::init () -> const glib::Class&
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
  NoSelection_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new NoSelection ((GtkNoSelection*) object);
  }

  auto
  NoSelection::gobj_copy () -> GtkNoSelection*
  {
    reference ();
    return gobj ();
  }

  NoSelection::NoSelection (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  NoSelection::NoSelection (GtkNoSelection* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  NoSelection::NoSelection (NoSelection&& src) noexcept
    : glib::Object (std::move (src)),
      gio::ListModel (std::move (src)),
      SelectionModel (std::move (src))
  {
  }

  auto
  NoSelection::operator= (NoSelection&& src) noexcept -> NoSelection&
  {
    glib::Object::operator= (std::move (src));
    gio::ListModel::operator= (std::move (src));
    SelectionModel::operator= (std::move (src));
    return *this;
  }

  NoSelection::~NoSelection () noexcept {}

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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (noselection_class_.init ()))
  {
  }

  NoSelection::NoSelection (const glib::RefPtr<gio::ListModel>& model)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (noselection_class_.init (),
                                           "model",
                                           glib::unwrap (model),
                                           nullptr))
  {
  }

  auto
  NoSelection::create () -> glib::RefPtr<NoSelection>
  {
    return glib::make_refptr_for_instance<NoSelection> (new NoSelection ());
  }

  auto
  NoSelection::create (const glib::RefPtr<gio::ListModel>& model) -> glib::RefPtr<NoSelection>
  {
    return glib::make_refptr_for_instance<NoSelection> (
        new NoSelection (model));
  }

  auto
  NoSelection::get_model () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_no_selection_get_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  NoSelection::get_model () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<NoSelection*> (this)->get_model ();
  }

  auto
  NoSelection::set_model (const glib::RefPtr<gio::ListModel>& model) -> void
  {
    gtk_no_selection_set_model (gobj (), glib::unwrap (model));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  NoSelection::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return glib::PropertyProxy_ReadOnly<GType> (this, "item-type");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  NoSelection::property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "model");
  }

  auto
  NoSelection::property_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (this,
                                                                       "model");
  }

  auto
  NoSelection::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return glib::PropertyProxy_ReadOnly<unsigned int> (this, "n-items");
  }

} // namespace gtk
