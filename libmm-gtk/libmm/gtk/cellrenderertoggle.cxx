// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/cellrenderertoggle.hxx>
  #include <libmm/gtk/cellrenderertoggle_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  auto
  CellRendererToggle::_property_renderable () -> glib::PropertyProxy_Base
  {
    return property_active ();
  }

} // namespace gtk

namespace
{

  static auto
  CellRendererToggle_signal_toggled_callback (GtkCellRendererToggle* self,
                                              const gchar* p0,
                                              void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<CellRendererToggle*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo CellRendererToggle_signal_toggled_info = {
      "toggled",
      (GCallback) &CellRendererToggle_signal_toggled_callback,
      (GCallback) &CellRendererToggle_signal_toggled_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkCellRendererToggle* object, bool take_copy) -> gtk::CellRendererToggle*
  {
    return dynamic_cast<gtk::CellRendererToggle*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  CellRendererToggle_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellRendererToggle_Class::class_init_function;

      register_derived_type (gtk_cell_renderer_toggle_get_type ());
    }

    return *this;
  }

  auto
  CellRendererToggle_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CellRendererToggle_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new CellRendererToggle ((GtkCellRendererToggle*) (o)));
  }

  CellRendererToggle::CellRendererToggle (
      const glib::ConstructParams& construct_params)
    : gtk::CellRenderer (construct_params)
  {
  }

  CellRendererToggle::CellRendererToggle (GtkCellRendererToggle* castitem)
    : gtk::CellRenderer ((GtkCellRenderer*) (castitem))
  {
  }

  CellRendererToggle::CellRendererToggle (CellRendererToggle&& src) noexcept
    : gtk::CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererToggle::operator= (CellRendererToggle&& src) noexcept -> CellRendererToggle&
  {
    gtk::CellRenderer::operator= (std::move (src));
    return *this;
  }

  CellRendererToggle::~CellRendererToggle () noexcept
  {
    destroy_ ();
  }

  CellRendererToggle::CppClassType
      CellRendererToggle::cellrenderertoggle_class_;

  auto
  CellRendererToggle::get_type () -> GType
  {
    return cellrenderertoggle_class_.init ().get_type ();
  }

  auto
  CellRendererToggle::get_base_type () -> GType
  {
    return gtk_cell_renderer_toggle_get_type ();
  }

  CellRendererToggle::CellRendererToggle ()
    : glib::ObjectBase (nullptr),
      gtk::CellRenderer (
          glib::ConstructParams (cellrenderertoggle_class_.init ()))
  {
  }

  auto
  CellRendererToggle::get_radio () const -> bool
  {
    return gtk_cell_renderer_toggle_get_radio (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_radio (bool radio) -> void
  {
    gtk_cell_renderer_toggle_set_radio (gobj (), static_cast<int> (radio));
  }

  auto
  CellRendererToggle::get_active () const -> bool
  {
    return gtk_cell_renderer_toggle_get_active (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_active (bool setting) -> void
  {
    gtk_cell_renderer_toggle_set_active (gobj (), static_cast<int> (setting));
  }

  auto
  CellRendererToggle::get_activatable () const -> bool
  {
    return gtk_cell_renderer_toggle_get_activatable (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_activatable (bool setting) -> void
  {
    gtk_cell_renderer_toggle_set_activatable (gobj (),
                                              static_cast<int> (setting));
  }

  auto
  CellRendererToggle::signal_toggled () -> glib::SignalProxy<void (const glib::ustring&)>
  {
    return glib::SignalProxy<void (const glib::ustring&)> (
        this,
        &CellRendererToggle_signal_toggled_info);
  }

  auto
  CellRendererToggle::property_activatable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "activatable");
  }

  auto
  CellRendererToggle::property_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "activatable");
  }

  auto
  CellRendererToggle::property_active () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "active");
  }

  auto
  CellRendererToggle::property_active () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "active");
  }

  auto
  CellRendererToggle::property_inconsistent () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "inconsistent");
  }

  auto
  CellRendererToggle::property_inconsistent () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "inconsistent");
  }

  auto
  CellRendererToggle::property_radio () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "radio");
  }

  auto
  CellRendererToggle::property_radio () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "radio");
  }

} // namespace gtk

#endif
