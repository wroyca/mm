// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/dragsurface.hxx>
#include <libmm/gdk/dragsurface_p.hxx>

#include <gdk/gdk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GdkDragSurface* object, bool take_copy) -> glib::RefPtr<gdk::DragSurface>
  {
    return glib::make_refptr_for_instance<gdk::DragSurface> (
        dynamic_cast<gdk::DragSurface*> (
            glib::wrap_auto_interface<gdk::DragSurface> ((GObject*) (object),
                                                         take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  DragSurface_Class::init () -> const glib::Interface_Class&
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
  DragSurface_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new DragSurface ((GdkDragSurface*) (object));
  }

  DragSurface::DragSurface ()
    : glib::Interface (dragsurface_class_.init ())
  {
  }

  DragSurface::DragSurface (GdkDragSurface* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  DragSurface::DragSurface (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  DragSurface::DragSurface (DragSurface&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  DragSurface::operator= (DragSurface&& src) noexcept -> DragSurface&
  {
    glib::Interface::operator= (std::move (src));
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

} // namespace gdk
