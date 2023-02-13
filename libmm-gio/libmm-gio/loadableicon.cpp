


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/loadableicon.hpp>
#include <mm/gio/private/loadableicon_p.hpp>


/* Copyright (C) 2007 The giomm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <mm/glib/error.hpp>
#include <mm/gio/slot_async.hpp>

namespace Gio
{

auto
LoadableIcon::load(
  const int size, Glib::ustring& type, const Glib::RefPtr<Cancellable>& cancellable) -> Glib::RefPtr<InputStream>
{
  char* c_type;
  GError* gerror = nullptr;
  auto retval =
    Glib::wrap(g_loadable_icon_load(gobj(), size, &c_type, Glib::unwrap(cancellable), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  type = c_type;
  g_free(c_type);
  if (retval)
    retval->reference(); // The function does not do a ref for us.
  return retval;
}

auto
LoadableIcon::load(
  const int size, Glib::ustring& type) -> Glib::RefPtr<InputStream>
{
  char* c_type;
  GError* gerror = nullptr;
  auto retval = Glib::wrap(g_loadable_icon_load(gobj(), size, &c_type, nullptr, &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  type = c_type;
  g_free(c_type);
  if (retval)
    retval->reference(); // The function does not do a ref for us.
  return retval;
}

auto LoadableIcon::load_async (
  const int size, const SlotAsyncReady &slot, const Glib::RefPtr <Cancellable> &cancellable) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_loadable_icon_load_async(
    gobj(), size, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

auto LoadableIcon::load_async (
  const int size, const SlotAsyncReady &slot) -> void
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  const auto slot_copy = new SlotAsyncReady(slot);

  g_loadable_icon_load_async(gobj(), size, nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GLoadableIcon* object, const bool take_copy) -> RefPtr<Gio::LoadableIcon>
{
  return Glib::make_refptr_for_instance<Gio::LoadableIcon>( Glib::wrap_auto_interface<Gio::LoadableIcon> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

auto LoadableIcon_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &LoadableIcon_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_loadable_icon_get_type();
  }

  return *this;
}

auto LoadableIcon_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);


}


auto LoadableIcon_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new LoadableIcon((GLoadableIcon*)object);
}


/* The implementation: */

LoadableIcon::LoadableIcon()
: Interface(loadableicon_class_.init())
{}

LoadableIcon::LoadableIcon(GLoadableIcon* castitem)
: Interface((GObject*)castitem)
{}

LoadableIcon::LoadableIcon(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

LoadableIcon::LoadableIcon(LoadableIcon&& src) noexcept
: Interface(std::move(src))
{}

auto LoadableIcon::operator=(LoadableIcon&& src) noexcept -> LoadableIcon&
{
  Interface::operator=(std::move(src));
  return *this;
}

LoadableIcon::~LoadableIcon() noexcept = default;

// static
auto LoadableIcon::add_interface (
  const GType gtype_implementer) -> void
{
  loadableicon_class_.init().add_interface(gtype_implementer);
}

LoadableIcon::CppClassType LoadableIcon::loadableicon_class_; // initialize static member

auto LoadableIcon::get_type() -> GType
{
  return loadableicon_class_.init().get_type();
}


auto LoadableIcon::get_base_type() -> GType
{
  return g_loadable_icon_get_type();
}


} // namespace Gio


