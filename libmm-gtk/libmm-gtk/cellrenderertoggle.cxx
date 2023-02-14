

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/cellrenderertoggle.hxx>
#include <libmm-gtk/cellrenderertoggle_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  auto
  CellRendererToggle::_property_renderable () -> Glib::PropertyProxy_Base
  {
    return property_active ();
  }

} // namespace Gtk

namespace
{

  auto
  CellRendererToggle_signal_toggled_callback (GtkCellRendererToggle* self,
                                              const gchar* p0,
                                              void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    const auto obj = dynamic_cast<CellRendererToggle*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo CellRendererToggle_signal_toggled_info = {
      "toggled",
      (GCallback) &CellRendererToggle_signal_toggled_callback,
      (GCallback) &CellRendererToggle_signal_toggled_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkCellRendererToggle* object, const bool take_copy) -> Gtk::CellRendererToggle*
  {
    return dynamic_cast<Gtk::CellRendererToggle*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellRendererToggle_Class::init () -> const Class&
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
  CellRendererToggle_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new CellRendererToggle ((GtkCellRendererToggle*) o));
  }

  CellRendererToggle::CellRendererToggle (
      const Glib::ConstructParams& construct_params)
    : CellRenderer (construct_params)
  {
  }

  CellRendererToggle::CellRendererToggle (GtkCellRendererToggle* castitem)
    : CellRenderer ((GtkCellRenderer*) castitem)
  {
  }

  CellRendererToggle::CellRendererToggle (CellRendererToggle&& src) noexcept
    : CellRenderer (std::move (src))
  {
  }

  auto
  CellRendererToggle::operator= (CellRendererToggle&& src) noexcept -> CellRendererToggle&
  {
    CellRenderer::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      CellRenderer (Glib::ConstructParams (cellrenderertoggle_class_.init ()))
  {
  }

  auto
  CellRendererToggle::get_radio () const -> bool
  {
    return gtk_cell_renderer_toggle_get_radio (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_radio (const bool radio) -> void
  {
    gtk_cell_renderer_toggle_set_radio (gobj (), radio);
  }

  auto
  CellRendererToggle::get_active () const -> bool
  {
    return gtk_cell_renderer_toggle_get_active (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_active (const bool setting) -> void
  {
    gtk_cell_renderer_toggle_set_active (gobj (), setting);
  }

  auto
  CellRendererToggle::get_activatable () const -> bool
  {
    return gtk_cell_renderer_toggle_get_activatable (
        const_cast<GtkCellRendererToggle*> (gobj ()));
  }

  auto
  CellRendererToggle::set_activatable (const bool setting) -> void
  {
    gtk_cell_renderer_toggle_set_activatable (gobj (), setting);
  }

  auto
  CellRendererToggle::signal_toggled () -> Glib::SignalProxy<void (const Glib::ustring&)>
  {
    return {this, &CellRendererToggle_signal_toggled_info};
  }

  auto
  CellRendererToggle::property_activatable () -> Glib::PropertyProxy<bool>
  {
    return {this, "activatable"};
  }

  auto
  CellRendererToggle::property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "activatable"};
  }

  auto
  CellRendererToggle::property_active () -> Glib::PropertyProxy<bool>
  {
    return {this, "active"};
  }

  auto
  CellRendererToggle::property_active () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "active"};
  }

  auto
  CellRendererToggle::property_inconsistent () -> Glib::PropertyProxy<bool>
  {
    return {this, "inconsistent"};
  }

  auto
  CellRendererToggle::property_inconsistent () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "inconsistent"};
  }

  auto
  CellRendererToggle::property_radio () -> Glib::PropertyProxy<bool>
  {
    return {this, "radio"};
  }

  auto
  CellRendererToggle::property_radio () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "radio"};
  }

} // namespace Gtk
