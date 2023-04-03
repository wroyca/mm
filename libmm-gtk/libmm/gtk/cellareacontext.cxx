// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellareacontext.hxx>
  #include <libmm/gtk/cellareacontext_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/cellarea.hxx>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellAreaContext* object, bool take_copy) -> Glib::RefPtr<Gtk::CellAreaContext>
  {
    return Glib::make_refptr_for_instance<Gtk::CellAreaContext> (
        dynamic_cast<Gtk::CellAreaContext*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellAreaContext_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellAreaContext_Class::class_init_function;

      register_derived_type (gtk_cell_area_context_get_type ());
    }

    return *this;
  }

  auto
  CellAreaContext_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellAreaContext_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CellAreaContext ((GtkCellAreaContext*) object);
  }

  auto
  CellAreaContext::gobj_copy () -> GtkCellAreaContext*
  {
    reference ();
    return gobj ();
  }

  CellAreaContext::CellAreaContext (
      const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  CellAreaContext::CellAreaContext (GtkCellAreaContext* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  CellAreaContext::CellAreaContext (CellAreaContext&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  CellAreaContext::operator= (CellAreaContext&& src) noexcept -> CellAreaContext&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  CellAreaContext::~CellAreaContext () noexcept {}

  CellAreaContext::CppClassType CellAreaContext::cellareacontext_class_;

  auto
  CellAreaContext::get_type () -> GType
  {
    return cellareacontext_class_.init ().get_type ();
  }

  auto
  CellAreaContext::get_base_type () -> GType
  {
    return gtk_cell_area_context_get_type ();
  }

  auto
  CellAreaContext::get_area () -> Glib::RefPtr<CellArea>
  {
    auto retvalue = Glib::wrap (gtk_cell_area_context_get_area (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CellAreaContext::get_area () const -> Glib::RefPtr<const CellArea>
  {
    return const_cast<CellAreaContext*> (this)->get_area ();
  }

  auto
  CellAreaContext::allocate (int width, int height) -> void
  {
    gtk_cell_area_context_allocate (gobj (), width, height);
  }

  auto
  CellAreaContext::reset () -> void
  {
    gtk_cell_area_context_reset (gobj ());
  }

  auto
  CellAreaContext::get_preferred_width (int& minimum_width,
                                        int& natural_width) const -> void
  {
    gtk_cell_area_context_get_preferred_width (
        const_cast<GtkCellAreaContext*> (gobj ()),
        &(minimum_width),
        &(natural_width));
  }

  auto
  CellAreaContext::get_preferred_height (int& minimum_height,
                                         int& natural_height) const -> void
  {
    gtk_cell_area_context_get_preferred_height (
        const_cast<GtkCellAreaContext*> (gobj ()),
        &(minimum_height),
        &(natural_height));
  }

  auto
  CellAreaContext::get_preferred_height_for_width (int width,
                                                   int& minimum_height,
                                                   int& natural_height) const -> void
  {
    gtk_cell_area_context_get_preferred_height_for_width (
        const_cast<GtkCellAreaContext*> (gobj ()),
        width,
        &(minimum_height),
        &(natural_height));
  }

  auto
  CellAreaContext::get_preferred_width_for_height (int height,
                                                   int& minimum_width,
                                                   int& natural_width) const -> void
  {
    gtk_cell_area_context_get_preferred_width_for_height (
        const_cast<GtkCellAreaContext*> (gobj ()),
        height,
        &(minimum_width),
        &(natural_width));
  }

  auto
  CellAreaContext::get_allocation (int& width, int& height) const -> void
  {
    gtk_cell_area_context_get_allocation (
        const_cast<GtkCellAreaContext*> (gobj ()),
        &(width),
        &(height));
  }

  auto
  CellAreaContext::push_preferred_width (int minimum_width, int natural_width) -> void
  {
    gtk_cell_area_context_push_preferred_width (gobj (),
                                                minimum_width,
                                                natural_width);
  }

  auto
  CellAreaContext::push_preferred_height (int minimum_height,
                                          int natural_height) -> void
  {
    gtk_cell_area_context_push_preferred_height (gobj (),
                                                 minimum_height,
                                                 natural_height);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<CellArea*>::value,
      "Type CellArea* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellAreaContext::property_area () const -> Glib::PropertyProxy_ReadOnly<CellArea*>
  {
    return Glib::PropertyProxy_ReadOnly<CellArea*> (this, "area");
  }

  auto
  CellAreaContext::property_minimum_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "minimum-width");
  }

  auto
  CellAreaContext::property_natural_width () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "natural-width");
  }

  auto
  CellAreaContext::property_minimum_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "minimum-height");
  }

  auto
  CellAreaContext::property_natural_height () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "natural-height");
  }

} // namespace Gtk

#endif
