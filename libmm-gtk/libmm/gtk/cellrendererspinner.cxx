// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendererspinner.hxx>
  #include <libmm/gtk/cellrendererspinner_p.hxx>

  #include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellRendererSpinner* object, bool take_copy) -> gtk::CellRendererSpinner*
  {
    return dynamic_cast<gtk::CellRendererSpinner*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererSpinner_Class::init () -> const glib::Class&
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
  CellRendererSpinner_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererSpinner ((GtkCellRendererSpinner*) (o)));
  }

  CellRendererSpinner::CellRendererSpinner (
      const glib::ConstructParams& construct_params)
    : gtk::CellRenderer (construct_params)
  {
  }

  CellRendererSpinner::CellRendererSpinner (GtkCellRendererSpinner* castitem)
    : gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererSpinner::CellRendererSpinner (CellRendererSpinner&& src) noexcept
    : gtk::CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererSpinner::operator= (CellRendererSpinner&& src) noexcept -> CellRendererSpinner&
  {
    gtk::CellRenderer::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::CellRenderer (
          glib::ConstructParams (cellrendererspinner_class_.init ()))
  {
  }

  auto
  CellRendererSpinner::property_active () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "active");
  }

  auto
  CellRendererSpinner::property_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  auto
  CellRendererSpinner::property_pulse () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "pulse");
  }

  auto
  CellRendererSpinner::property_pulse () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "pulse");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<gtk::IconSize>::value,
      "Type gtk::IconSize cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererSpinner::property_size () -> glib::PropertyProxy<gtk::IconSize>
  {
    return glib::PropertyProxy<gtk::IconSize> (this, "size");
  }

  auto
  CellRendererSpinner::property_size () const -> glib::PropertyProxy_ReadOnly<gtk::IconSize>
  {
    return glib::PropertyProxy_ReadOnly<gtk::IconSize> (this, "size");
  }

} // namespace gtk

#endif
