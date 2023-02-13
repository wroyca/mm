


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellrenderercombo.hpp>
#include <mm/gtk/private/cellrenderercombo_p.hpp>


/*
 * Copyright 2004 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

///This is used only by signal_changed's generated implementation.
static auto _get_model(GtkCellRendererCombo* renderer) -> GtkTreeModel*
{
  if(!renderer)
    return nullptr;

  GtkTreeModel* combo_model = nullptr;
  g_object_get(G_OBJECT(renderer), "model", &combo_model, nullptr);
  return combo_model;
}

namespace Gtk
{

auto CellRendererCombo::_property_renderable() -> Glib::PropertyProxy_Base
{
  return CellRendererText::_property_renderable();
}

} //namespace Gtk

namespace
{


auto CellRendererCombo_signal_changed_callback (
  GtkCellRendererCombo *self, const gchar *p0, GtkTreeIter *p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&, const TreeModel::iterator&)>;

  const auto obj = dynamic_cast<CellRendererCombo*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
, TreeModel::iterator(_get_model(self), p1)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo CellRendererCombo_signal_changed_info =
{
  "changed",
  (GCallback) &CellRendererCombo_signal_changed_callback,
  (GCallback) &CellRendererCombo_signal_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellRendererCombo* object, const bool take_copy) -> Gtk::CellRendererCombo*
{
  return dynamic_cast<Gtk::CellRendererCombo *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellRendererCombo_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererCombo_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_combo_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto CellRendererCombo_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellRendererCombo_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellRendererCombo((GtkCellRendererCombo*)o));

}


/* The implementation: */

CellRendererCombo::CellRendererCombo(const Glib::ConstructParams& construct_params)
: CellRendererText(construct_params)
{
  }

CellRendererCombo::CellRendererCombo(GtkCellRendererCombo* castitem)
: CellRendererText((GtkCellRendererText*)castitem)
{
  }


CellRendererCombo::CellRendererCombo(CellRendererCombo&& src) noexcept
: CellRendererText(std::move(src))
{}

auto CellRendererCombo::operator=(CellRendererCombo&& src) noexcept -> CellRendererCombo&
{
  CellRendererText::operator=(std::move(src));
  return *this;
}

CellRendererCombo::~CellRendererCombo() noexcept
{
  destroy_();
}

CellRendererCombo::CppClassType CellRendererCombo::cellrenderercombo_class_; // initialize static member

auto CellRendererCombo::get_type() -> GType
{
  return cellrenderercombo_class_.init().get_type();
}


auto CellRendererCombo::get_base_type() -> GType
{
  return gtk_cell_renderer_combo_get_type();
}


CellRendererCombo::CellRendererCombo()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
CellRendererText(Glib::ConstructParams(cellrenderercombo_class_.init()))
{


}


auto CellRendererCombo::signal_changed() -> Glib::SignalProxy<void(const Glib::ustring&, const TreeModel::iterator&)>
{
  return {this, &CellRendererCombo_signal_changed_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<Gtk::TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellRendererCombo::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto CellRendererCombo::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto CellRendererCombo::property_text_column() -> Glib::PropertyProxy< int >
{
  return {this, "text-column"};
}

auto CellRendererCombo::property_text_column() const -> Glib::PropertyProxy_ReadOnly< int >
{
  return {this, "text-column"};
}

auto CellRendererCombo::property_has_entry() -> Glib::PropertyProxy< bool >
{
  return {this, "has-entry"};
}

auto CellRendererCombo::property_has_entry() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-entry"};
}


} // namespace Gtk


