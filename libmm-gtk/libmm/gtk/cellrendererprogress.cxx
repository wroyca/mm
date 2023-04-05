// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrendererprogress.hxx>
  #include <libmm/gtk/cellrendererprogress_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  auto
  CellRendererProgress::_property_renderable () -> glib::PropertyProxy_Base
  {
    return property_value ();
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellRendererProgress* object, bool take_copy) -> gtk::CellRendererProgress*
  {
    return dynamic_cast<gtk::CellRendererProgress*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererProgress_Class::init () -> const glib::Class&
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
  CellRendererProgress_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererProgress ((GtkCellRendererProgress*) (o)));
  }

  CellRendererProgress::CellRendererProgress (
      const glib::ConstructParams& construct_params)
    : gtk::CellRenderer (construct_params)
  {
  }

  CellRendererProgress::CellRendererProgress (GtkCellRendererProgress* castitem)
    : gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererProgress::CellRendererProgress (
      CellRendererProgress&& src) noexcept
    : gtk::CellRenderer (std::move (src)),
      Orientable (std::move (src))
  {
  }

  auto
  CellRendererProgress::operator= (CellRendererProgress&& src) noexcept -> CellRendererProgress&
  {
    gtk::CellRenderer::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::CellRenderer (
          glib::ConstructParams (cellrendererprogress_class_.init ()))
  {
  }

  auto
  CellRendererProgress::property_value () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "value");
  }

  auto
  CellRendererProgress::property_value () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "value");
  }

  auto
  CellRendererProgress::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  CellRendererProgress::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  auto
  CellRendererProgress::property_pulse () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "pulse");
  }

  auto
  CellRendererProgress::property_pulse () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "pulse");
  }

  auto
  CellRendererProgress::property_text_xalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "text-xalign");
  }

  auto
  CellRendererProgress::property_text_xalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "text-xalign");
  }

  auto
  CellRendererProgress::property_text_yalign () -> glib::PropertyProxy<float>
  {
    return glib::PropertyProxy<float> (this, "text-yalign");
  }

  auto
  CellRendererProgress::property_text_yalign () const -> glib::PropertyProxy_ReadOnly<float>
  {
    return glib::PropertyProxy_ReadOnly<float> (this, "text-yalign");
  }

  auto
  CellRendererProgress::property_inverted () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inverted");
  }

  auto
  CellRendererProgress::property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inverted");
  }

} // namespace gtk

#endif
