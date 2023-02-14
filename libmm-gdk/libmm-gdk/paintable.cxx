

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/paintable.hxx>
#include <libmm-gdk/paintable_p.hxx>

#include <gdk/gdk.h>
#include <libmm-gdk/snapshot.hxx>

using Flags = Gdk::Paintable::Flags;

namespace
{

  const Glib::SignalProxyInfo Paintable_signal_invalidate_contents_info = {
      "invalidate-contents",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  const Glib::SignalProxyInfo Paintable_signal_invalidate_size_info = {
      "invalidate-size",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
Glib::Value<Gdk::Paintable::Flags>::value_type () -> GType
{
  return gdk_paintable_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GdkPaintable* object, const bool take_copy) -> RefPtr<Gdk::Paintable>
  {
    return Glib::make_refptr_for_instance<Gdk::Paintable> (
        Glib::wrap_auto_interface<Gdk::Paintable> ((GObject*) object,
                                                   take_copy));
  }

} // namespace Glib

namespace Gdk
{

  auto
  Paintable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Paintable_Class::iface_init_function;

      gtype_ = gdk_paintable_get_type ();
    }

    return *this;
  }

  auto
  Paintable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->snapshot = &snapshot_vfunc_callback;
    klass->get_current_image = &get_current_image_vfunc_callback;
    klass->get_flags = &get_flags_vfunc_callback;
    klass->get_intrinsic_width = &get_intrinsic_width_vfunc_callback;
    klass->get_intrinsic_height = &get_intrinsic_height_vfunc_callback;
    klass->get_intrinsic_aspect_ratio =
        &get_intrinsic_aspect_ratio_vfunc_callback;
  }

  auto
  Paintable_Class::snapshot_vfunc_callback (GdkPaintable* self,
                                            GdkSnapshot* snapshot,
                                            const double width,
                                            const double height) -> void
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->snapshot_vfunc (Glib::wrap (snapshot, true), width, height);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->snapshot)
      (*base->snapshot) (self, snapshot, width, height);
  }

  auto
  Paintable_Class::get_current_image_vfunc_callback (GdkPaintable* self) -> GdkPaintable*
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return Glib::unwrap (obj->get_current_image_vfunc ());
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_current_image)
      return (*base->get_current_image) (self);

    using RType = GdkPaintable*;
    return RType ();
  }

  auto
  Paintable_Class::get_flags_vfunc_callback (GdkPaintable* self) -> GdkPaintableFlags
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<GdkPaintableFlags> (obj->get_flags_vfunc ());
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_flags)
      return (*base->get_flags) (self);

    using RType = GdkPaintableFlags;
    return RType ();
  }

  auto
  Paintable_Class::get_intrinsic_width_vfunc_callback (GdkPaintable* self) -> int
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_intrinsic_width_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_width)
      return (*base->get_intrinsic_width) (self);

    using RType = int;
    return RType ();
  }

  auto
  Paintable_Class::get_intrinsic_height_vfunc_callback (GdkPaintable* self) -> int
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_intrinsic_height_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_height)
      return (*base->get_intrinsic_height) (self);

    using RType = int;
    return RType ();
  }

  auto
  Paintable_Class::get_intrinsic_aspect_ratio_vfunc_callback (
      GdkPaintable* self) -> double
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->get_intrinsic_aspect_ratio_vfunc ();
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_aspect_ratio)
      return (*base->get_intrinsic_aspect_ratio) (self);

    using RType = double;
    return RType ();
  }

  auto
  Paintable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Paintable ((GdkPaintable*) object);
  }

  Paintable::Paintable ()
    : Interface (paintable_class_.init ())
  {
  }

  Paintable::Paintable (GdkPaintable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Paintable::Paintable (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Paintable::Paintable (Paintable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Paintable::operator= (Paintable&& src) noexcept -> Paintable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Paintable::~Paintable () noexcept = default;

  auto
  Paintable::add_interface (const GType gtype_implementer) -> void
  {
    paintable_class_.init ().add_interface (gtype_implementer);
  }

  Paintable::CppClassType Paintable::paintable_class_;

  auto
  Paintable::get_type () -> GType
  {
    return paintable_class_.init ().get_type ();
  }

  auto
  Paintable::get_base_type () -> GType
  {
    return gdk_paintable_get_type ();
  }

  auto
  Paintable::snapshot (const Glib::RefPtr<Snapshot>& snapshot,
                       const double width,
                       const double height) -> void
  {
    gdk_paintable_snapshot (gobj (), Glib::unwrap (snapshot), width, height);
  }

  auto
  Paintable::get_current_image () const -> Glib::RefPtr<const Paintable>
  {
    return Glib::wrap (
        gdk_paintable_get_current_image (const_cast<GdkPaintable*> (gobj ())));
  }

  auto
  Paintable::get_flags () const -> Flags
  {
    return static_cast<Flags> (
        gdk_paintable_get_flags (const_cast<GdkPaintable*> (gobj ())));
  }

  auto
  Paintable::get_intrinsic_width () const -> int
  {
    return gdk_paintable_get_intrinsic_width (
        const_cast<GdkPaintable*> (gobj ()));
  }

  auto
  Paintable::get_intrinsic_height () const -> int
  {
    return gdk_paintable_get_intrinsic_height (
        const_cast<GdkPaintable*> (gobj ()));
  }

  auto
  Paintable::get_intrinsic_aspect_ratio () const -> double
  {
    return gdk_paintable_get_intrinsic_aspect_ratio (
        const_cast<GdkPaintable*> (gobj ()));
  }

  auto
  Paintable::compute_concrete_size (const double specified_width,
                                    const double specified_height,
                                    const double default_width,
                                    const double default_height,
                                    double& concrete_width,
                                    double& concrete_height) const -> void
  {
    gdk_paintable_compute_concrete_size (const_cast<GdkPaintable*> (gobj ()),
                                         specified_width,
                                         specified_height,
                                         default_width,
                                         default_height,
                                         &concrete_width,
                                         &concrete_height);
  }

  auto
  Paintable::invalidate_contents () -> void
  {
    gdk_paintable_invalidate_contents (gobj ());
  }

  auto
  Paintable::invalidate_size () -> void
  {
    gdk_paintable_invalidate_size (gobj ());
  }

  auto
  Paintable::signal_invalidate_contents () -> Glib::SignalProxy<void ()>
  {
    return {this, &Paintable_signal_invalidate_contents_info};
  }

  auto
  Paintable::signal_invalidate_size () -> Glib::SignalProxy<void ()>
  {
    return {this, &Paintable_signal_invalidate_size_info};
  }

  auto
  Paintable::snapshot_vfunc (const Glib::RefPtr<Snapshot>& snapshot,
                             const double width,
                             const double height) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->snapshot)
    {
      (*base->snapshot) (gobj (), Glib::unwrap (snapshot), width, height);
    }
  }

  auto
  Paintable::get_current_image_vfunc () const -> Glib::RefPtr<Paintable>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_current_image)
    {
      Glib::RefPtr<Paintable> retval (Glib::wrap (
          (*base->get_current_image) (const_cast<GdkPaintable*> (gobj ())),
          true));
      return retval;
    }

    using RType = Glib::RefPtr<Paintable>;
    return {};
  }

  auto
  Paintable::get_flags_vfunc () const -> Flags
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_flags)
    {
      const Flags retval (static_cast<Flags> (
          (*base->get_flags) (const_cast<GdkPaintable*> (gobj ()))));
      return retval;
    }

    using RType = Flags;
    return RType ();
  }

  auto
  Paintable::get_intrinsic_width_vfunc () const -> int
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_intrinsic_width)
    {
      const int retval (
          (*base->get_intrinsic_width) (const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  Paintable::get_intrinsic_height_vfunc () const -> int
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_intrinsic_height)
    {
      const int retval (
          (*base->get_intrinsic_height) (const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  Paintable::get_intrinsic_aspect_ratio_vfunc () const -> double
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_intrinsic_aspect_ratio)
    {
      const double retval ((*base->get_intrinsic_aspect_ratio) (
          const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = double;
    return RType ();
  }

} // namespace Gdk
