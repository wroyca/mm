


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/toplevel.hpp>
#include <libmm-gdk/toplevel_p.hpp>


/* Copyright (C) 2020 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gdk/gdk.h>

using State = Gdk::Toplevel::State;

namespace
{
// Hand-coded because the slot can't be called with a non-const temporary ToplevelSize.
auto Toplevel_signal_compute_size_callback (
  GdkToplevel *self, GdkToplevelSize *p0, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(ToplevelSize&)>;

  const auto obj = dynamic_cast<Toplevel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if (const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
      {
        // This works because Gdk::ToplevelSize neither copies nor deletes *p0.
        ToplevelSize toplevelsize(p0);
        (*static_cast<SlotType*>(slot))(toplevelsize);
      }
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

} // anonymous namespace

namespace
{


const Glib::SignalProxyInfo Toplevel_signal_compute_size_info =
{
  "compute-size",
  (GCallback) &Toplevel_signal_compute_size_callback,
  (GCallback) &Toplevel_signal_compute_size_callback
};


} // anonymous namespace

// static
auto Glib::Value<Gdk::SurfaceEdge>::value_type() -> GType
{
  return gdk_surface_edge_get_type();
}

// static
auto Glib::Value<Gdk::FullscreenMode>::value_type() -> GType
{
  return gdk_fullscreen_mode_get_type();
}

// static
auto Glib::Value<Gdk::Toplevel::State>::value_type() -> GType
{
  return gdk_toplevel_state_get_type();
}


namespace Glib
{

auto wrap(GdkToplevel* object, const bool take_copy) -> RefPtr<Gdk::Toplevel>
{
  return Glib::make_refptr_for_instance<Gdk::Toplevel>( Glib::wrap_auto_interface<Gdk::Toplevel> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gdk
{


/* The *_Class implementation: */

auto Toplevel_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &Toplevel_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gdk_toplevel_get_type();
  }

  return *this;
}

auto Toplevel_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto Toplevel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new Toplevel((GdkToplevel*)object);
}


/* The implementation: */

Toplevel::Toplevel()
: Interface(toplevel_class_.init())
{}

Toplevel::Toplevel(GdkToplevel* castitem)
: Interface((GObject*)castitem)
{}

Toplevel::Toplevel(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

Toplevel::Toplevel(Toplevel&& src) noexcept
: Interface(std::move(src))
{}

auto Toplevel::operator=(Toplevel&& src) noexcept -> Toplevel&
{
  Interface::operator=(std::move(src));
  return *this;
}

Toplevel::~Toplevel() noexcept = default;

// static
auto Toplevel::add_interface (
  const GType gtype_implementer) -> void
{
  toplevel_class_.init().add_interface(gtype_implementer);
}

Toplevel::CppClassType Toplevel::toplevel_class_; // initialize static member

auto Toplevel::get_type() -> GType
{
  return toplevel_class_.init().get_type();
}


auto Toplevel::get_base_type() -> GType
{
  return gdk_toplevel_get_type();
}


auto Toplevel::present (const Glib::RefPtr <ToplevelLayout> &layout) -> void
{
  gdk_toplevel_present(gobj(), Glib::unwrap(layout));
}

auto Toplevel::minimize() -> bool
{
  return gdk_toplevel_minimize(gobj());
}

auto Toplevel::lower() -> bool
{
  return gdk_toplevel_lower(gobj());
}

auto Toplevel::focus (
  const guint32 timestamp) -> void
{
  gdk_toplevel_focus(gobj(), timestamp);
}

auto Toplevel::get_state() const -> State
{
  return static_cast<State>(gdk_toplevel_get_state(const_cast<GdkToplevel*>(gobj())));
}

auto Toplevel::set_title (const Glib::ustring &title) -> void
{
  gdk_toplevel_set_title(gobj(), title.c_str());
}

auto Toplevel::set_startup_id (const Glib::ustring &startup_id) -> void
{
  gdk_toplevel_set_startup_id(gobj(), startup_id.c_str());
}

auto Toplevel::set_transient_for (const Glib::RefPtr <Surface> &parent) -> void
{
  gdk_toplevel_set_transient_for(gobj(), Glib::unwrap(parent));
}

auto Toplevel::set_modal (
  const bool modal) -> void
{
  gdk_toplevel_set_modal(gobj(), modal);
}

auto Toplevel::set_icon_list (const std::vector <Glib::RefPtr <Texture>> &surfaces) -> void
{
  gdk_toplevel_set_icon_list(gobj(), Glib::ListHandler<Glib::RefPtr<Texture>>::vector_to_list(surfaces).data());
}

auto Toplevel::show_window_menu(const Glib::RefPtr<Event>& event) -> bool
{
  return gdk_toplevel_show_window_menu(gobj(), Glib::unwrap(event));
}

auto Toplevel::set_decorated (
  const bool decorated) -> void
{
  gdk_toplevel_set_decorated(gobj(), decorated);
}

auto Toplevel::set_deletable (
  const bool deletable) -> void
{
  gdk_toplevel_set_deletable(gobj(), deletable);
}

auto Toplevel::supports_edge_constraints() const -> bool
{
  return gdk_toplevel_supports_edge_constraints(const_cast<GdkToplevel*>(gobj()));
}

auto Toplevel::inhibit_system_shortcuts (const Glib::RefPtr <Event> &event) -> void
{
  gdk_toplevel_inhibit_system_shortcuts(gobj(), Glib::unwrap(event));
}

auto Toplevel::restore_system_shortcuts () -> void
{
  gdk_toplevel_restore_system_shortcuts(gobj());
}

auto Toplevel::begin_resize (
  SurfaceEdge edge, const Glib::RefPtr <Device> &device, const int button, const double x, const double y, const guint32 timestamp) -> void
{
  gdk_toplevel_begin_resize(gobj(), static_cast<GdkSurfaceEdge>(edge), Glib::unwrap(device), button, x, y, timestamp);
}

auto Toplevel::begin_move (
  const Glib::RefPtr <Device> &device, const int button, const double x, const double y, const guint32 timestamp) -> void
{
  gdk_toplevel_begin_move(gobj(), Glib::unwrap(device), button, x, y, timestamp);
}


auto Toplevel::signal_compute_size() -> Glib::SignalProxy<void(ToplevelSize&)>
{
  return {this, &Toplevel_signal_compute_size_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<State>::value,
  "Type State cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Toplevel::property_state() const -> Glib::PropertyProxy_ReadOnly< State >
{
  return {this, "state"};
}

auto Toplevel::property_title() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "title"};
}

auto Toplevel::property_title() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "title"};
}

auto Toplevel::property_startup_id() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "startup-id"};
}

auto Toplevel::property_startup_id() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "startup-id"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Surface>>::value,
  "Type Glib::RefPtr<Surface> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Toplevel::property_transient_for() -> Glib::PropertyProxy< Glib::RefPtr<Surface> >
{
  return {this, "transient-for"};
}

auto Toplevel::property_transient_for() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Surface> >
{
  return {this, "transient-for"};
}

auto Toplevel::property_modal() -> Glib::PropertyProxy< bool >
{
  return {this, "modal"};
}

auto Toplevel::property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "modal"};
}

auto Toplevel::property_decorated() -> Glib::PropertyProxy< bool >
{
  return {this, "decorated"};
}

auto Toplevel::property_decorated() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "decorated"};
}

auto Toplevel::property_deletable() -> Glib::PropertyProxy< bool >
{
  return {this, "deletable"};
}

auto Toplevel::property_deletable() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "deletable"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<FullscreenMode>::value,
  "Type FullscreenMode cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto Toplevel::property_fullscreen_mode() -> Glib::PropertyProxy< FullscreenMode >
{
  return {this, "fullscreen-mode"};
}

auto Toplevel::property_fullscreen_mode() const -> Glib::PropertyProxy_ReadOnly< FullscreenMode >
{
  return {this, "fullscreen-mode"};
}

auto Toplevel::property_shortcuts_inhibited() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "shortcuts-inhibited"};
}


} // namespace Gdk


