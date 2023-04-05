// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendererspin.hxx>
  #include <libmm/gtk/cellrendererspin_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/adjustment.hxx>

namespace gtk
{

  auto
  CellRendererSpin::_property_renderable () -> glib::PropertyProxy_Base
  {
    return CellRendererText::_property_renderable ();
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellRendererSpin* object, bool take_copy) -> gtk::CellRendererSpin*
  {
    return dynamic_cast<gtk::CellRendererSpin*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererSpin_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererSpin_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_spin_get_type ());
    }

    return *this;
  }

  auto
  CellRendererSpin_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererSpin_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererSpin ((GtkCellRendererSpin*) (o)));
  }

  CellRendererSpin::CellRendererSpin (
      const glib::ConstructParams& construct_params)
    : gtk::CellRendererText (construct_params)
  {
  }

  CellRendererSpin::CellRendererSpin (GtkCellRendererSpin* castitem)
    : gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererSpin::CellRendererSpin (CellRendererSpin&& src) noexcept
    : gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererSpin::operator= (CellRendererSpin&& src) noexcept -> CellRendererSpin&
  {
    gtk::CellRendererText::operator= (std::move (src));
    return *this;
  }

  CellRendererSpin::~CellRendererSpin () noexcept
  {
    destroy_ ();
  }

  CellRendererSpin::CppClassType CellRendererSpin::cellrendererspin_class_;

  auto
  CellRendererSpin::get_type () -> GType
  {
    return cellrendererspin_class_.init ().get_type ();
  }

  auto
  CellRendererSpin::get_base_type () -> GType
  {
    return gtk_cell_renderer_spin_get_type ();
  }

  CellRendererSpin::CellRendererSpin ()
    : glib::ObjectBase (nullptr),
      gtk::CellRendererText (
          glib::ConstructParams (cellrendererspin_class_.init ()))
  {
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Adjustment>>::value,
      "Type glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  CellRendererSpin::property_adjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy<glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  CellRendererSpin::property_adjustment () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  auto
  CellRendererSpin::property_climb_rate () -> glib::PropertyProxy<double>
  {
    return glib::PropertyProxy<double> (this, "climb-rate");
  }

  auto
  CellRendererSpin::property_climb_rate () const -> glib::PropertyProxy_ReadOnly<double>
  {
    return glib::PropertyProxy_ReadOnly<double> (this, "climb-rate");
  }

  auto
  CellRendererSpin::property_digits () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "digits");
  }

  auto
  CellRendererSpin::property_digits () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "digits");
  }

} // namespace gtk

#endif
