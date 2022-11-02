// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!


#include <mm/glib/mm-glib.hpp>

#include <mm/gtk/cellview.hpp>
#include <mm/gtk/private/cellview_p.hpp>


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

#include <mm/gtk/cellrenderertext.hpp>
#include <mm/gtk/cellrendererpixbuf.hpp>
#include <gtk/gtk.h>

namespace Gtk
{

CellView::CellView(const Glib::ustring& text, bool use_markup)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{
  auto cell = Gtk::manage(new Gtk::CellRendererText());

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
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{
  auto cell = Gtk::manage(new Gtk::CellRendererPixbuf());

  cell->property_texture() = texture;

  pack_start(*cell);
}

void CellView::unset_model()
{
  gtk_cell_view_set_model(gobj(), nullptr);
}


} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkCellView* object, bool take_copy) -> Gtk::CellView*
{
  return dynamic_cast<Gtk::CellView *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto CellView_Class::init() -> const Glib::Class&
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


void CellView_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto CellView_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new CellView((GtkCellView*)(o)));

}


/* The implementation: */

CellView::CellView(const Glib::ConstructParams& construct_params)
:
  Gtk::Widget(construct_params)
{
  }

CellView::CellView(GtkCellView* castitem)
:
  Gtk::Widget((GtkWidget*)(castitem))
{
  }


CellView::CellView(CellView&& src) noexcept
: Gtk::Widget(std::move(src))
  , CellLayout(std::move(src))
  , Orientable(std::move(src))
{}

auto CellView::operator=(CellView&& src) noexcept -> CellView&
{
  Gtk::Widget::operator=(std::move(src));
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
  Glib::ObjectBase(nullptr),
  Gtk::Widget(Glib::ConstructParams(cellview_class_.init()))
{


}

void CellView::set_model(const Glib::RefPtr<TreeModel>& model)
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

void CellView::set_displayed_row(const TreeModel::Path& path)
{
  gtk_cell_view_set_displayed_row(gobj(), const_cast<GtkTreePath*>((path).gobj()));
}

auto CellView::get_displayed_row() const -> TreeModel::Path
{
  return Gtk::TreePath(gtk_cell_view_get_displayed_row(const_cast<GtkCellView*>(gobj())), false);
}

auto CellView::get_draw_sensitive() const -> bool
{
  return gtk_cell_view_get_draw_sensitive(const_cast<GtkCellView*>(gobj()));
}

void CellView::set_draw_sensitive(bool draw_sensitive)
{
  gtk_cell_view_set_draw_sensitive(gobj(), static_cast<int>(draw_sensitive));
}

auto CellView::get_fit_model() const -> bool
{
  return gtk_cell_view_get_fit_model(const_cast<GtkCellView*>(gobj()));
}

void CellView::set_fit_model(bool fit_model)
{
  gtk_cell_view_set_fit_model(gobj(), static_cast<int>(fit_model));
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<TreeModel>>::value,
  "Type Glib::RefPtr<TreeModel> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_model() -> Glib::PropertyProxy< Glib::RefPtr<TreeModel> >
{
  return Glib::PropertyProxy< Glib::RefPtr<TreeModel> >(this, "model");
}

auto CellView::property_model() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >(this, "model");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellArea>>::value,
  "Type Glib::RefPtr<CellArea> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_cell_area() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellArea> >(this, "cell-area");
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<CellAreaContext>>::value,
  "Type Glib::RefPtr<CellAreaContext> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto CellView::property_cell_area_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> >
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<CellAreaContext> >(this, "cell-area-context");
}

auto CellView::property_draw_sensitive() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "draw-sensitive");
}

auto CellView::property_draw_sensitive() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "draw-sensitive");
}

auto CellView::property_fit_model() -> Glib::PropertyProxy< bool >
{
  return Glib::PropertyProxy< bool >(this, "fit-model");
}

auto CellView::property_fit_model() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "fit-model");
}


} // namespace Gtk


