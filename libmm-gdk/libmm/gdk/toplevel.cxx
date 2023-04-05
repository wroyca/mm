// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/toplevel.hxx>
#include <libmm/gdk/toplevel_p.hxx>

#include <gdk/gdk.h>

using State = gdk::Toplevel::State;

namespace
{

  static auto
  Toplevel_signal_compute_size_callback (GdkToplevel* self,
                                         GdkToplevelSize* p0,
                                         void* data) -> void
  {
    using namespace gdk;
    using SlotType = sigc::slot<void (ToplevelSize&)>;

    auto obj = dynamic_cast<Toplevel*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
        {
          ToplevelSize toplevelsize (p0);
          (*static_cast<SlotType*> (slot)) (toplevelsize);
        }
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

} // namespace

namespace
{

  static const glib::SignalProxyInfo Toplevel_signal_compute_size_info = {
      "compute-size",
      (GCallback) &Toplevel_signal_compute_size_callback,
      (GCallback) &Toplevel_signal_compute_size_callback};

}

auto
glib::Value<gdk::SurfaceEdge>::value_type () -> GType
{
  return gdk_surface_edge_get_type ();
}

auto
glib::Value<gdk::FullscreenMode>::value_type () -> GType
{
  return gdk_fullscreen_mode_get_type ();
}

auto
glib::Value<gdk::Toplevel::State>::value_type () -> GType
{
  return gdk_toplevel_state_get_type ();
}

namespace glib
{

  auto
  wrap (GdkToplevel* object, bool take_copy) -> glib::RefPtr<gdk::Toplevel>
  {
    return glib::make_refptr_for_instance<gdk::Toplevel> (
        dynamic_cast<gdk::Toplevel*> (
            glib::wrap_auto_interface<gdk::Toplevel> ((GObject*) (object),
                                                      take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Toplevel_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Toplevel_Class::iface_init_function;

      gtype_ = gdk_toplevel_get_type ();
    }

    return *this;
  }

  auto
  Toplevel_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Toplevel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Toplevel ((GdkToplevel*) (object));
  }

  Toplevel::Toplevel ()
    : glib::Interface (toplevel_class_.init ())
  {
  }

  Toplevel::Toplevel (GdkToplevel* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Toplevel::Toplevel (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Toplevel::Toplevel (Toplevel&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Toplevel::operator= (Toplevel&& src) noexcept -> Toplevel&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Toplevel::~Toplevel () noexcept {}

  auto
  Toplevel::add_interface (GType gtype_implementer) -> void
  {
    toplevel_class_.init ().add_interface (gtype_implementer);
  }

  Toplevel::CppClassType Toplevel::toplevel_class_;

  auto
  Toplevel::get_type () -> GType
  {
    return toplevel_class_.init ().get_type ();
  }

  auto
  Toplevel::get_base_type () -> GType
  {
    return gdk_toplevel_get_type ();
  }

  auto
  Toplevel::present (const glib::RefPtr<ToplevelLayout>& layout) -> void
  {
    gdk_toplevel_present (gobj (), glib::unwrap (layout));
  }

  auto
  Toplevel::minimize () -> bool
  {
    return gdk_toplevel_minimize (gobj ());
  }

  auto
  Toplevel::lower () -> bool
  {
    return gdk_toplevel_lower (gobj ());
  }

  auto
  Toplevel::focus (guint32 timestamp) -> void
  {
    gdk_toplevel_focus (gobj (), timestamp);
  }

  auto
  Toplevel::get_state () const -> State
  {
    return static_cast<State> (
        gdk_toplevel_get_state (const_cast<GdkToplevel*> (gobj ())));
  }

  auto
  Toplevel::set_title (const glib::ustring& title) -> void
  {
    gdk_toplevel_set_title (gobj (), title.c_str ());
  }

  auto
  Toplevel::set_startup_id (const glib::ustring& startup_id) -> void
  {
    gdk_toplevel_set_startup_id (gobj (), startup_id.c_str ());
  }

  auto
  Toplevel::set_transient_for (const glib::RefPtr<Surface>& parent) -> void
  {
    gdk_toplevel_set_transient_for (gobj (), glib::unwrap (parent));
  }

  auto
  Toplevel::set_modal (bool modal) -> void
  {
    gdk_toplevel_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  Toplevel::set_icon_list (const std::vector<glib::RefPtr<Texture>>& surfaces) -> void
  {
    gdk_toplevel_set_icon_list (
        gobj (),
        glib::ListHandler<glib::RefPtr<Texture>>::vector_to_list (surfaces)
            .data ());
  }

  auto
  Toplevel::show_window_menu (const glib::RefPtr<Event>& event) -> bool
  {
    return gdk_toplevel_show_window_menu (gobj (), glib::unwrap (event));
  }

  auto
  Toplevel::set_decorated (bool decorated) -> void
  {
    gdk_toplevel_set_decorated (gobj (), static_cast<int> (decorated));
  }

  auto
  Toplevel::set_deletable (bool deletable) -> void
  {
    gdk_toplevel_set_deletable (gobj (), static_cast<int> (deletable));
  }

  auto
  Toplevel::supports_edge_constraints () const -> bool
  {
    return gdk_toplevel_supports_edge_constraints (
        const_cast<GdkToplevel*> (gobj ()));
  }

  auto
  Toplevel::inhibit_system_shortcuts (const glib::RefPtr<Event>& event) -> void
  {
    gdk_toplevel_inhibit_system_shortcuts (gobj (), glib::unwrap (event));
  }

  auto
  Toplevel::restore_system_shortcuts () -> void
  {
    gdk_toplevel_restore_system_shortcuts (gobj ());
  }

  auto
  Toplevel::begin_resize (SurfaceEdge edge,
                          const glib::RefPtr<Device>& device,
                          int button,
                          double x,
                          double y,
                          guint32 timestamp) -> void
  {
    gdk_toplevel_begin_resize (gobj (),
                               static_cast<GdkSurfaceEdge> (edge),
                               glib::unwrap (device),
                               button,
                               x,
                               y,
                               timestamp);
  }

  auto
  Toplevel::begin_move (const glib::RefPtr<Device>& device,
                        int button,
                        double x,
                        double y,
                        guint32 timestamp) -> void
  {
    gdk_toplevel_begin_move (gobj (),
                             glib::unwrap (device),
                             button,
                             x,
                             y,
                             timestamp);
  }

  auto
  Toplevel::signal_compute_size () -> glib::SignalProxy<void (ToplevelSize&)>
  {
    return glib::SignalProxy<void (ToplevelSize&)> (
        this,
        &Toplevel_signal_compute_size_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<State>::value,
      "Type State cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Toplevel::property_state () const -> glib::PropertyProxy_ReadOnly<State>
  {
    return glib::PropertyProxy_ReadOnly<State> (this, "state");
  }

  auto
  Toplevel::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  Toplevel::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  Toplevel::property_startup_id () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "startup-id");
  }

  auto
  Toplevel::property_startup_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "startup-id");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Surface>>::value,
      "Type glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Toplevel::property_transient_for () -> glib::PropertyProxy<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy<glib::RefPtr<Surface>> (this, "transient-for");
  }

  auto
  Toplevel::property_transient_for () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>> (
        this,
        "transient-for");
  }

  auto
  Toplevel::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  Toplevel::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  Toplevel::property_decorated () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "decorated");
  }

  auto
  Toplevel::property_decorated () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "decorated");
  }

  auto
  Toplevel::property_deletable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "deletable");
  }

  auto
  Toplevel::property_deletable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "deletable");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<FullscreenMode>::value,
      "Type FullscreenMode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  Toplevel::property_fullscreen_mode () -> glib::PropertyProxy<FullscreenMode>
  {
    return glib::PropertyProxy<FullscreenMode> (this, "fullscreen-mode");
  }

  auto
  Toplevel::property_fullscreen_mode () const -> glib::PropertyProxy_ReadOnly<FullscreenMode>
  {
    return glib::PropertyProxy_ReadOnly<FullscreenMode> (this,
                                                         "fullscreen-mode");
  }

  auto
  Toplevel::property_shortcuts_inhibited () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "shortcuts-inhibited");
  }

} // namespace gdk
