// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/dragsurface.hxx>
#include <libmm-gdk/dragsurface_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkDragSurface* object, bool take_copy) -> Glib::RefPtr<Gdk::DragSurface>
  {
    return Glib::make_refptr_for_instance<Gdk::DragSurface> (
        dynamic_cast<Gdk::DragSurface*> (
            Glib::wrap_auto_interface<Gdk::DragSurface> ((GObject*) (object),
                                                         take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  DragSurface_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &DragSurface_Class::iface_init_function;

      gtype_ = gdk_drag_surface_get_type ();
    }

    return *this;
  }

  auto
  DragSurface_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  DragSurface_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new DragSurface ((GdkDragSurface*) (object));
  }

  DragSurface::DragSurface ()
    : Glib::Interface (dragsurface_class_.init ())
  {
  }

  DragSurface::DragSurface (GdkDragSurface* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  DragSurface::DragSurface (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  DragSurface::DragSurface (DragSurface&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  DragSurface::operator= (DragSurface&& src) noexcept -> DragSurface&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  DragSurface::~DragSurface () noexcept {}

  auto
  DragSurface::add_interface (GType gtype_implementer) -> void
  {
    dragsurface_class_.init ().add_interface (gtype_implementer);
  }

  DragSurface::CppClassType DragSurface::dragsurface_class_;

  auto
  DragSurface::get_type () -> GType
  {
    return dragsurface_class_.init ().get_type ();
  }

  auto
  DragSurface::get_base_type () -> GType
  {
    return gdk_drag_surface_get_type ();
  }

  auto
  DragSurface::present (int width, int height) -> bool
  {
    return gdk_drag_surface_present (gobj (), width, height);
  }

} // namespace Gdk
