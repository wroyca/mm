// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/cellrendererspinner.hxx>
  #include <libmm-gtk/cellrendererspinner_p.hxx>

  #include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellRendererSpinner* object, bool take_copy) -> Gtk::CellRendererSpinner*
  {
    return dynamic_cast<Gtk::CellRendererSpinner*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererSpinner_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererSpinner_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_spinner_get_type ());
    }

    return *this;
  }

  auto
  CellRendererSpinner_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererSpinner_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererSpinner ((GtkCellRendererSpinner*) (o)));
  }

  CellRendererSpinner::CellRendererSpinner (
      const Glib::ConstructParams& construct_params)
    : Gtk::CellRenderer (construct_params)
  {
  }

  CellRendererSpinner::CellRendererSpinner (GtkCellRendererSpinner* castitem)
    : Gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererSpinner::CellRendererSpinner (CellRendererSpinner&& src) noexcept
    : Gtk::CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererSpinner::operator= (CellRendererSpinner&& src) noexcept -> CellRendererSpinner&
  {
    Gtk::CellRenderer::operator= (std::move (src));
    return *this;
  }

  CellRendererSpinner::~CellRendererSpinner () noexcept
  {
    destroy_ ();
  }

  CellRendererSpinner::CppClassType
      CellRendererSpinner::cellrendererspinner_class_;

  auto
  CellRendererSpinner::get_type () -> GType
  {
    return cellrendererspinner_class_.init ().get_type ();
  }

  auto
  CellRendererSpinner::get_base_type () -> GType
  {
    return gtk_cell_renderer_spinner_get_type ();
  }

  CellRendererSpinner::CellRendererSpinner ()
    : Glib::ObjectBase (nullptr),
      Gtk::CellRenderer (
          Glib::ConstructParams (cellrendererspinner_class_.init ()))
  {
  }

  auto
  CellRendererSpinner::property_active () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "active");
  }

  auto
  CellRendererSpinner::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  auto
  CellRendererSpinner::property_pulse () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "pulse");
  }

  auto
  CellRendererSpinner::property_pulse () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "pulse");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Gtk::IconSize>::value,
      "Type Gtk::IconSize cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRendererSpinner::property_size () -> Glib::PropertyProxy<Gtk::IconSize>
  {
    return Glib::PropertyProxy<Gtk::IconSize> (this, "size");
  }

  auto
  CellRendererSpinner::property_size () const -> Glib::PropertyProxy_ReadOnly<Gtk::IconSize>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::IconSize> (this, "size");
  }

} // namespace Gtk

#endif
