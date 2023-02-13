


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/cellview.hxx>
#include <libmm-gtk/cellview_p.hxx>


/*
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/cellrenderertext.hxx>
#include <libmm-gtk/cellrendererpixbuf.hxx>
#include <gtk/gtk.h>

namespace Gtk
{

CellView::CellView(const Glib::ustring& text, const bool use_markup)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(cellview_class_.init()))
{
  const auto cell = manage(new CellRendererText());

  if(use_markup)
  {
    cell->property_markup() = text;
  }
  else
  {
    cell->property_text() = text;
  }

  pack_start(*cell);
}

CellView::CellView(const Glib::RefPtr<Gdk::Texture>& texture)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(cellview_class_.init()))
{
  const auto cell = manage(new CellRendererPixbuf());

  cell->property_texture() = texture;

  pack_start(*cell);
}

auto CellView::unset_model () -> void
{
  gtk_cell_view_set_model(gobj(), nullptr);
}


} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellView* object, const bool take_copy) -> Gtk::CellView*
{
  return dynamic_cast<Gtk::CellView *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellView_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());
  Orientable::add_interface(get_type());

  }

  return *this;
}


auto CellView_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellView((GtkCellView*)o));

}


/* The implementation: */

CellView::CellView(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

CellView::CellView(GtkCellView* castitem)
: Widget((GtkWidget*)castitem)
{
  }


CellView::CellView(CellView&& src) noexcept
: Widget(std::move(src))
  , CellLayout(std::move(src))
  , Orientable(std::move(src))
{}

auto CellView::operator=(CellView&& src) noexcept -> CellView&
{
  Widget::operator=(std::move(src));
  CellLayout::operator=(std::move(src));
  Orientable::operator=(std::move(src));
  return *this;
}

CellView::~CellView() noexcept
{
  destroy_();
}

CellView::CppClassType CellView::cellview_class_; // initialize static member

auto CellView::get_type() -> GType
{
  return cellview_class_.init().get_type();
}


auto CellView::get_base_type() -> GType
{
  return gtk_cell_view_get_type();
}


CellView::CellView()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(cellview_class_.init()))
{


}

auto CellView::set_model (const Glib::RefPtr <TreeModel> &model) -> void
{
  gtk_cell_view_set_model(gobj(), Glib::unwrap(model));
}

auto CellView::get_model() -> Glib::RefPtr<TreeModel>
{
  auto retvalue = Glib::wrap(gtk_cell_view_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto CellView::get_model() const -> Glib::RefPtr<const TreeModel>
{
  return const_cast<CellView*>(this)->get_model();
}

auto CellView::set_displayed_row (const TreeModel::Path &path) -> void
{
  gtk_cell_view_set_displayed_row(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}

auto CellView::get_displayed_row() const -> TreeModel::Path
{
  return TreePath(gtk_cell_view_get_displayed_row(const_cast<GtkCellView*>(gobj())), false);
}

auto CellView::get_draw_sensitive() const -> bool
{
  return gtk_cell_view_get_draw_sensitive(const_cast<GtkCellView*>(gobj()));
}

auto CellView::set_draw_sensitive (
  const bool draw_sensitive) -> void
{
  gtk_cell_view_set_draw_sensitive(gobj(), draw_sensitive);
}

auto CellView::get_fit_model() const -> bool
{
  return gtk_cell_view_get_fit_model(const_cast<GtkCellView*>(gobj()));
}

auto CellView::set_fit_model (
  const bool fit_model) -> void
{
  gtk_cell_view_set_fit_model(gobj(), fit_model);
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

auto CellView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return {this, "model"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellArea>>::value,
  "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >
{
  return {this, "cell-area"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellAreaContext>>::value,
  "Type Glib::RefPtr<CellAreaContext> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_cell_area_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> >
{
  return {this, "cell-area-context"};
}

auto CellView::property_draw_sensitive() -> Glib::PropertyProxy< bool >
{
  return {this, "draw-sensitive"};
}

auto CellView::property_draw_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "draw-sensitive"};
}

auto CellView::property_fit_model() -> Glib::PropertyProxy< bool >
{
  return {this, "fit-model"};
}

auto CellView::property_fit_model() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "fit-model"};
}


} // namespace Gtk

