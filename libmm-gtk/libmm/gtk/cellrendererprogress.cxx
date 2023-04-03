// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendererprogress.hxx>
  #include <libmm/gtk/cellrendererprogress_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  auto
  CellRendererProgress::_property_renderable () -> Glib::PropertyProxy_Base
  {
    return property_value ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellRendererProgress* object, bool take_copy) -> Gtk::CellRendererProgress*
  {
    return dynamic_cast<Gtk::CellRendererProgress*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererProgress_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererProgress_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_progress_get_type ());

      Orientable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CellRendererProgress_Class::class_init_function (void* g_class,
                                                   void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererProgress_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererProgress ((GtkCellRendererProgress*) (o)));
  }

  CellRendererProgress::CellRendererProgress (
      const Glib::ConstructParams& construct_params)
    : Gtk::CellRenderer (construct_params)
  {
  }

  CellRendererProgress::CellRendererProgress (GtkCellRendererProgress* castitem)
    : Gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererProgress::CellRendererProgress (
      CellRendererProgress&& src) noexcept
    : Gtk::CellRenderer (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CellRendererProgress::operator= (CellRendererProgress&& src) noexcept -> CellRendererProgress&
  {
    Gtk::CellRenderer::operator= (std::move (src));
    Orientable::operator= (std::move (src));
    return *this;
  }

  CellRendererProgress::~CellRendererProgress () noexcept
  {
    destroy_ ();
  }

  CellRendererProgress::CppClassType
      CellRendererProgress::cellrendererprogress_class_;

  auto
  CellRendererProgress::get_type () -> GType
  {
    return cellrendererprogress_class_.init ().get_type ();
  }

  auto
  CellRendererProgress::get_base_type () -> GType
  {
    return gtk_cell_renderer_progress_get_type ();
  }

  CellRendererProgress::CellRendererProgress ()
    : Glib::ObjectBase (nullptr),
      Gtk::CellRenderer (
          Glib::ConstructParams (cellrendererprogress_class_.init ()))
  {
  }

  auto
  CellRendererProgress::property_value () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "value");
  }

  auto
  CellRendererProgress::property_value () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "value");
  }

  auto
  CellRendererProgress::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "text");
  }

  auto
  CellRendererProgress::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "text");
  }

  auto
  CellRendererProgress::property_pulse () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "pulse");
  }

  auto
  CellRendererProgress::property_pulse () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "pulse");
  }

  auto
  CellRendererProgress::property_text_xalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "text-xalign");
  }

  auto
  CellRendererProgress::property_text_xalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "text-xalign");
  }

  auto
  CellRendererProgress::property_text_yalign () -> Glib::PropertyProxy<float>
  {
    return Glib::PropertyProxy<float> (this, "text-yalign");
  }

  auto
  CellRendererProgress::property_text_yalign () const -> Glib::PropertyProxy_ReadOnly<float>
  {
    return Glib::PropertyProxy_ReadOnly<float> (this, "text-yalign");
  }

  auto
  CellRendererProgress::property_inverted () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  CellRendererProgress::property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

} // namespace Gtk

#endif
