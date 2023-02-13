


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/columnview.hxx>
#include <libmm-gtk/columnview_p.hxx>


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


auto ColumnView_signal_activate_callback (GtkColumnView *self, const guint p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(guint)>;

  const auto obj = dynamic_cast<ColumnView*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo ColumnView_signal_activate_info =
{
  "activate",
  (GCallback) &ColumnView_signal_activate_callback,
  (GCallback) &ColumnView_signal_activate_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkColumnView* object, const bool take_copy) -> Gtk::ColumnView*
{
  return dynamic_cast<Gtk::ColumnView *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto ColumnView_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ColumnView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_column_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Scrollable::add_interface(get_type());

  }

  return *this;
}


auto ColumnView_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ColumnView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new ColumnView((GtkColumnView*)o));

}


/* The implementation: */

ColumnView::ColumnView(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

ColumnView::ColumnView(GtkColumnView* castitem)
: Widget((GtkWidget*)castitem)
{
  }


ColumnView::ColumnView(ColumnView&& src) noexcept
: Widget(std::move(src))
  , Scrollable(std::move(src))
{}

auto ColumnView::operator=(ColumnView&& src) noexcept -> ColumnView&
{
  Widget::operator=(std::move(src));
  Scrollable::operator=(std::move(src));
  return *this;
}

ColumnView::~ColumnView() noexcept
{
  destroy_();
}

ColumnView::CppClassType ColumnView::columnview_class_; // initialize static member

auto ColumnView::get_type() -> GType
{
  return columnview_class_.init().get_type();
}


auto ColumnView::get_base_type() -> GType
{
  return gtk_column_view_get_type();
}


ColumnView::ColumnView(const Glib::RefPtr<SelectionModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(columnview_class_.init(), "model", Glib::unwrap(model), nullptr))
{


}

auto ColumnView::get_columns() -> Glib::RefPtr<Gio::ListModel>
{
  auto retvalue = Glib::wrap(gtk_column_view_get_columns(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnView::get_columns() const -> Glib::RefPtr<const Gio::ListModel>
{
  return const_cast<ColumnView*>(this)->get_columns();
}

auto ColumnView::append_column (const Glib::RefPtr <ColumnViewColumn> &column) -> void
{
  gtk_column_view_append_column(gobj(), Glib::unwrap(column));
}

auto ColumnView::remove_column (const Glib::RefPtr <ColumnViewColumn> &column) -> void
{
  gtk_column_view_remove_column(gobj(), Glib::unwrap(column));
}

auto ColumnView::insert_column (
  const guint position, const Glib::RefPtr <ColumnViewColumn> &column) -> void
{
  gtk_column_view_insert_column(gobj(), position, Glib::unwrap(column));
}

auto ColumnView::get_model() -> Glib::RefPtr<SelectionModel>
{
  auto retvalue = Glib::wrap(gtk_column_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnView::get_model() const -> Glib::RefPtr<const SelectionModel>
{
  return const_cast<ColumnView*>(this)->get_model();
}

auto ColumnView::set_model (const Glib::RefPtr <SelectionModel> &model) -> void
{
  gtk_column_view_set_model(gobj(), Glib::unwrap(model));
}

auto ColumnView::get_show_row_separators() const -> bool
{
  return gtk_column_view_get_show_row_separators(const_cast<GtkColumnView*>(gobj()));
}

auto ColumnView::set_show_row_separators (
  const bool show_separators) -> void
{
  gtk_column_view_set_show_row_separators(gobj(), show_separators);
}

auto ColumnView::get_show_column_separators() const -> bool
{
  return gtk_column_view_get_show_column_separators(const_cast<GtkColumnView*>(gobj()));
}

auto ColumnView::set_show_column_separators (
  const bool show_separators) -> void
{
  gtk_column_view_set_show_column_separators(gobj(), show_separators);
}

auto ColumnView::get_sorter() -> Glib::RefPtr<Sorter>
{
  auto retvalue = Glib::wrap(gtk_column_view_get_sorter(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto ColumnView::get_sorter() const -> Glib::RefPtr<const Sorter>
{
  return const_cast<ColumnView*>(this)->get_sorter();
}

auto ColumnView::sort_by_column (
  const Glib::RefPtr <ColumnViewColumn> &column, SortType direction) -> void
{
  gtk_column_view_sort_by_column(gobj(), Glib::unwrap(column), static_cast<GtkSortType>(direction));
}

auto ColumnView::set_single_click_activate (
  const bool single_click_activate) -> void
{
  gtk_column_view_set_single_click_activate(gobj(), single_click_activate);
}

auto ColumnView::get_single_click_activate() const -> bool
{
  return gtk_column_view_get_single_click_activate(const_cast<GtkColumnView*>(gobj()));
}

auto ColumnView::set_reorderable (
  const bool reorderable) -> void
{
  gtk_column_view_set_reorderable(gobj(), reorderable);
}

auto ColumnView::get_reorderable() const -> bool
{
  return gtk_column_view_get_reorderable(const_cast<GtkColumnView*>(gobj()));
}

auto ColumnView::set_enable_rubberband (
  const bool enable_rubberband) -> void
{
  gtk_column_view_set_enable_rubberband(gobj(), enable_rubberband);
}

auto ColumnView::get_enable_rubberband() const -> bool
{
  return gtk_column_view_get_enable_rubberband(const_cast<GtkColumnView*>(gobj()));
}


auto ColumnView::signal_activate() -> Glib::SignalProxy<void(guint)>
{
  return {this, &ColumnView_signal_activate_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gio::ListModel>>::value,
  "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnView::property_columns() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::ListModel> >
{
  return {this, "columns"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<SelectionModel>>::value,
  "Type Glib::RefPtr<SelectionModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<SelectionModel> >
{
  return {this, "model"};
}

auto ColumnView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SelectionModel> >
{
  return {this, "model"};
}

auto ColumnView::property_show_row_separators() -> Glib::PropertyProxy< bool >
{
  return {this, "show-row-separators"};
}

auto ColumnView::property_show_row_separators() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-row-separators"};
}

auto ColumnView::property_show_column_separators() -> Glib::PropertyProxy< bool >
{
  return {this, "show-column-separators"};
}

auto ColumnView::property_show_column_separators() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-column-separators"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Sorter>>::value,
  "Type Glib::RefPtr<Sorter> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ColumnView::property_sorter() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Sorter> >
{
  return {this, "sorter"};
}

auto ColumnView::property_single_click_activate() -> Glib::PropertyProxy< bool >
{
  return {this, "single-click-activate"};
}

auto ColumnView::property_single_click_activate() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "single-click-activate"};
}

auto ColumnView::property_reorderable() -> Glib::PropertyProxy< bool >
{
  return {this, "reorderable"};
}

auto ColumnView::property_reorderable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "reorderable"};
}

auto ColumnView::property_enable_rubberband() -> Glib::PropertyProxy< bool >
{
  return {this, "enable-rubberband"};
}

auto ColumnView::property_enable_rubberband() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "enable-rubberband"};
}


} // namespace Gtk


