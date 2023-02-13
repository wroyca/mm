


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/gridview.hpp>
#include <libmm-gtk/gridview_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

namespace
{


auto GridView_signal_activate_callback (GtkGridView *self, const guint p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint)>;

  const auto obj = dynamic_cast<GridView*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GridView_signal_activate_info =
{
  "activate",
  (GCallback) &GridView_signal_activate_callback,
  (GCallback) &GridView_signal_activate_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGridView* object, const bool take_copy) -> Gtk::GridView*
{
  return dynamic_cast<Gtk::GridView *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto GridView_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GridView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_grid_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GridView_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto GridView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new GridView((GtkGridView*)o));

}


/* The implementation: */

GridView::GridView(const Glib::ConstructParams& construct_params)
:
  ListBase(construct_params)
{
  }

GridView::GridView(GtkGridView* castitem)
:
  ListBase((GtkListBase*)castitem)
{
  }


GridView::GridView(GridView&& src) noexcept
: ListBase(std::move(src))
{}

auto GridView::operator=(GridView&& src) noexcept -> GridView&
{
  ListBase::operator=(std::move(src));
  return *this;
}

GridView::~GridView() noexcept
{
  destroy_();
}

GridView::CppClassType GridView::gridview_class_; // initialize static member

auto GridView::get_type() -> GType
{
  return gridview_class_.init().get_type();
}


auto GridView::get_base_type() -> GType
{
  return gtk_grid_view_get_type();
}


GridView::GridView(const Glib::RefPtr<SelectionModel>& model, const Glib::RefPtr<ListItemFactory>& factory)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  ListBase(Glib::ConstructParams(gridview_class_.init(), "model", Glib::unwrap(model), "factory", Glib::unwrap(factory), nullptr))
{


}

auto GridView::get_model() -> Glib::RefPtr<SelectionModel>
{
  auto retvalue = Glib::wrap(gtk_grid_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto GridView::get_model() const -> Glib::RefPtr<const SelectionModel>
{
  return const_cast<GridView*>(this)->get_model();
}

auto GridView::set_model (const Glib::RefPtr <SelectionModel> &model) -> void
{
  gtk_grid_view_set_model(gobj(), Glib::unwrap(model));
}

auto GridView::set_factory (const Glib::RefPtr <ListItemFactory> &factory) -> void
{
  gtk_grid_view_set_factory(gobj(), Glib::unwrap(factory));
}

auto GridView::get_factory() -> Glib::RefPtr<ListItemFactory>
{
  auto retvalue = Glib::wrap(gtk_grid_view_get_factory(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto GridView::get_factory() const -> Glib::RefPtr<const ListItemFactory>
{
  return const_cast<GridView*>(this)->get_factory();
}

auto GridView::get_min_columns() const -> guint
{
  return gtk_grid_view_get_min_columns(const_cast<GtkGridView*>(gobj()));
}

auto GridView::set_min_columns (
  const guint min_columns) -> void
{
  gtk_grid_view_set_min_columns(gobj(), min_columns);
}

auto GridView::get_max_columns() const -> guint
{
  return gtk_grid_view_get_max_columns(const_cast<GtkGridView*>(gobj()));
}

auto GridView::set_max_columns (
  const guint max_columns) -> void
{
  gtk_grid_view_set_max_columns(gobj(), max_columns);
}

auto GridView::set_enable_rubberband (
  const bool enable_rubberband) -> void
{
  gtk_grid_view_set_enable_rubberband(gobj(), enable_rubberband);
}

auto GridView::get_enable_rubberband() const -> bool
{
  return gtk_grid_view_get_enable_rubberband(const_cast<GtkGridView*>(gobj()));
}

auto GridView::set_single_click_activate (
  const bool single_click_activate) -> void
{
  gtk_grid_view_set_single_click_activate(gobj(), single_click_activate);
}

auto GridView::get_single_click_activate() const -> bool
{
  return gtk_grid_view_get_single_click_activate(const_cast<GtkGridView*>(gobj()));
}


auto GridView::signal_activate() -> Glib::SignalProxy<void(guint)>
{
  return {this, &GridView_signal_activate_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<ListItemFactory>>::value,
  "Type Glib::RefPtr<ListItemFactory> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto GridView::property_factory() -> Glib::PropertyProxy< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

auto GridView::property_factory() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<ListItemFactory> >
{
  return {this, "factory"};
}

auto GridView::property_max_columns() -> Glib::PropertyProxy< guint >
{
  return {this, "max-columns"};
}

auto GridView::property_max_columns() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "max-columns"};
}

auto GridView::property_min_columns() -> Glib::PropertyProxy< guint >
{
  return {this, "min-columns"};
}

auto GridView::property_min_columns() const -> Glib::PropertyProxy_ReadOnly< guint >
{
  return {this, "min-columns"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SelectionModel>>::value,
  "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto GridView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >
{
  return {this, "model"};
}

auto GridView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >
{
  return {this, "model"};
}

auto GridView::property_single_click_activate() -> Glib::PropertyProxy< bool >
{
  return {this, "single-click-activate"};
}

auto GridView::property_single_click_activate() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "single-click-activate"};
}

auto GridView::property_enable_rubberband() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-rubberband"};
}

auto GridView::property_enable_rubberband() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-rubberband"};
}


} // namespace Gtk


