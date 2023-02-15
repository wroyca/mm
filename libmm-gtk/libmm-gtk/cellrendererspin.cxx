// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/cellrendererspin.hxx>
  #include <libmm-gtk/cellrendererspin_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm-gtk/adjustment.hxx>

namespace Gtk
{

  auto
  CellRendererSpin::_property_renderable () -> Glib::PropertyProxy_Base
  {
    return CellRendererText::_property_renderable ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellRendererSpin* object, bool take_copy) -> Gtk::CellRendererSpin*
  {
    return dynamic_cast<Gtk::CellRendererSpin*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererSpin_Class::init () -> const Glib::Class&
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
  CellRendererSpin_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererSpin ((GtkCellRendererSpin*) (o)));
  }

  CellRendererSpin::CellRendererSpin (
      const Glib::ConstructParams& construct_params)
    : Gtk::CellRendererText (construct_params)
  {
  }

  CellRendererSpin::CellRendererSpin (GtkCellRendererSpin* castitem)
    : Gtk::CellRendererText ((GtkCellRendererText*) (castitem))
  {
  }

  CellRendererSpin::CellRendererSpin (CellRendererSpin&& src) noexcept
    : Gtk::CellRendererText (std::move (src))
  {
  }

  auto
  CellRendererSpin::operator= (CellRendererSpin&& src) noexcept -> CellRendererSpin&
  {
    Gtk::CellRendererText::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::CellRendererText (
          Glib::ConstructParams (cellrendererspin_class_.init ()))
  {
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Adjustment>>::value,
      "Type Glib::RefPtr<Adjustment> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  CellRendererSpin::property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Adjustment>> (this, "adjustment");
  }

  auto
  CellRendererSpin::property_adjustment () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>> (
        this,
        "adjustment");
  }

  auto
  CellRendererSpin::property_climb_rate () -> Glib::PropertyProxy<double>
  {
    return Glib::PropertyProxy<double> (this, "climb-rate");
  }

  auto
  CellRendererSpin::property_climb_rate () const -> Glib::PropertyProxy_ReadOnly<double>
  {
    return Glib::PropertyProxy_ReadOnly<double> (this, "climb-rate");
  }

  auto
  CellRendererSpin::property_digits () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "digits");
  }

  auto
  CellRendererSpin::property_digits () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "digits");
  }

} // namespace Gtk

#endif
