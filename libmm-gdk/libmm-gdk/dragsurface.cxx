

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
  wrap (GdkDragSurface* object, const bool take_copy) -> RefPtr<Gdk::DragSurface>
  {
    return Glib::make_refptr_for_instance<Gdk::DragSurface> (
        Glib::wrap_auto_interface<Gdk::DragSurface> ((GObject*) object,
                                                     take_copy));
  }

} // namespace Glib

namespace Gdk
{

  auto
  DragSurface_Class::init () -> const Interface_Class&
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
    return new DragSurface ((GdkDragSurface*) object);
  }

  DragSurface::DragSurface ()
    : Interface (dragsurface_class_.init ())
  {
  }

  DragSurface::DragSurface (GdkDragSurface* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  DragSurface::DragSurface (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  DragSurface::DragSurface (DragSurface&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  DragSurface::operator= (DragSurface&& src) noexcept -> DragSurface&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  DragSurface::~DragSurface () noexcept = default;

  auto
  DragSurface::add_interface (const GType gtype_implementer) -> void
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
  DragSurface::present (const int width, const int height) -> bool
  {
    return gdk_drag_surface_present (gobj (), width, height);
  }

} // namespace Gdk
