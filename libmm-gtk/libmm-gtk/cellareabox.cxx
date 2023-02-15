// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/cellareabox.hxx>
  #include <libmm-gtk/cellareabox_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellAreaBox* object, bool take_copy) -> Glib::RefPtr<Gtk::CellAreaBox>
  {
    return Glib::make_refptr_for_instance<Gtk::CellAreaBox> (
        dynamic_cast<Gtk::CellAreaBox*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellAreaBox_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellAreaBox_Class::class_init_function;

      register_derived_type (gtk_cell_area_box_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CellAreaBox_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellAreaBox_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CellAreaBox ((GtkCellAreaBox*) object);
  }

  auto
  CellAreaBox::gobj_copy () -> GtkCellAreaBox*
  {
    reference ();
    return gobj ();
  }

  CellAreaBox::CellAreaBox (const Glib::ConstructParams& construct_params)
    : CellArea (construct_params)
  {
  }

  CellAreaBox::CellAreaBox (GtkCellAreaBox* castitem)
    : CellArea ((GtkCellArea*) (castitem))
  {
  }

  CellAreaBox::CellAreaBox (CellAreaBox&& src) noexcept
    : CellArea (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CellAreaBox::operator= (CellAreaBox&& src) noexcept -> CellAreaBox&
  {
    CellArea::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  CellAreaBox::~CellAreaBox () noexcept {}

  CellAreaBox::CppClassType CellAreaBox::cellareabox_class_;

  auto
  CellAreaBox::get_type () -> GType
  {
    return cellareabox_class_.init ().get_type ();
  }

  auto
  CellAreaBox::get_base_type () -> GType
  {
    return gtk_cell_area_box_get_type ();
  }

  CellAreaBox::CellAreaBox ()
    : Glib::ObjectBase (nullptr),
      CellArea (Glib::ConstructParams (cellareabox_class_.init ()))
  {
  }

  auto
  CellAreaBox::create () -> Glib::RefPtr<CellAreaBox>
  {
    return Glib::make_refptr_for_instance<CellAreaBox> (new CellAreaBox ());
  }

  auto
  CellAreaBox::pack_start (CellRenderer& renderer,
                           bool expand,
                           bool align,
                           bool fixed) -> void
  {
    gtk_cell_area_box_pack_start (gobj (),
                                  (renderer).gobj (),
                                  static_cast<int> (expand),
                                  static_cast<int> (align),
                                  static_cast<int> (fixed));
  }

  auto
  CellAreaBox::pack_end (CellRenderer& renderer,
                         bool expand,
                         bool align,
                         bool fixed) -> void
  {
    gtk_cell_area_box_pack_end (gobj (),
                                (renderer).gobj (),
                                static_cast<int> (expand),
                                static_cast<int> (align),
                                static_cast<int> (fixed));
  }

  auto
  CellAreaBox::get_spacing () const -> int
  {
    return gtk_cell_area_box_get_spacing (
        const_cast<GtkCellAreaBox*> (gobj ()));
  }

  auto
  CellAreaBox::set_spacing (int spacing) -> void
  {
    gtk_cell_area_box_set_spacing (gobj (), spacing);
  }

  auto
  CellAreaBox::property_spacing () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "spacing");
  }

  auto
  CellAreaBox::property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "spacing");
  }

} // namespace Gtk

#endif
