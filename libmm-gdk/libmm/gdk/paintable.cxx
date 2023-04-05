// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/paintable.hxx>
#include <libmm/gdk/paintable_p.hxx>

#include <gdk/gdk.h>
#include <libmm/gdk/snapshot.hxx>

using Flags = gdk::Paintable::Flags;

namespace
{

  static const glib::SignalProxyInfo Paintable_signal_invalidate_contents_info =
      {"invalidate-contents",
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
       (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

  static const glib::SignalProxyInfo Paintable_signal_invalidate_size_info = {
      "invalidate-size",
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

} // namespace

auto
glib::Value<gdk::Paintable::Flags>::value_type () -> GType
{
  return gdk_paintable_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GdkPaintable* object, bool take_copy) -> glib::RefPtr<gdk::Paintable>
  {
    return glib::make_refptr_for_instance<gdk::Paintable> (
        dynamic_cast<gdk::Paintable*> (
            glib::wrap_auto_interface<gdk::Paintable> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace glib

namespace gdk
{

  auto
  Paintable_Class::init () -> const glib::Interface_Class&
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
                                            double width,
                                            double height) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->snapshot_vfunc (glib::wrap (snapshot, true), width, height);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->snapshot)
      (*base->snapshot) (self, snapshot, width, height);
  }

  auto
  Paintable_Class::get_current_image_vfunc_callback (GdkPaintable* self) -> GdkPaintable*
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return glib::unwrap (obj->get_current_image_vfunc ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

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
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_aspect_ratio)
      return (*base->get_intrinsic_aspect_ratio) (self);

    using RType = double;
    return RType ();
  }

  auto
  Paintable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Paintable ((GdkPaintable*) (object));
  }

  Paintable::Paintable ()
    : glib::Interface (paintable_class_.init ())
  {
  }

  Paintable::Paintable (GdkPaintable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Paintable::Paintable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Paintable::Paintable (Paintable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Paintable::operator= (Paintable&& src) noexcept -> Paintable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Paintable::~Paintable () noexcept {}

  auto
  Paintable::add_interface (GType gtype_implementer) -> void
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
  Paintable::snapshot (const glib::RefPtr<gdk::Snapshot>& snapshot,
                       double width,
                       double height) -> void
  {
    gdk_paintable_snapshot (gobj (), glib::unwrap (snapshot), width, height);
  }

  auto
  Paintable::get_current_image () const -> glib::RefPtr<const Paintable>
  {
    return glib::wrap (
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
  Paintable::compute_concrete_size (double specified_width,
                                    double specified_height,
                                    double default_width,
                                    double default_height,
                                    double& concrete_width,
                                    double& concrete_height) const -> void
  {
    gdk_paintable_compute_concrete_size (const_cast<GdkPaintable*> (gobj ()),
                                         specified_width,
                                         specified_height,
                                         default_width,
                                         default_height,
                                         &(concrete_width),
                                         &(concrete_height));
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
  Paintable::signal_invalidate_contents () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &Paintable_signal_invalidate_contents_info);
  }

  auto
  Paintable::signal_invalidate_size () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (this,
                                       &Paintable_signal_invalidate_size_info);
  }

  auto
  gdk::Paintable::snapshot_vfunc (const glib::RefPtr<gdk::Snapshot>& snapshot,
                                  double width,
                                  double height) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->snapshot)
    {
      (*base->snapshot) (gobj (), glib::unwrap (snapshot), width, height);
    }
  }

  auto
  gdk::Paintable::get_current_image_vfunc () const -> glib::RefPtr<Paintable>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_current_image)
    {
      glib::RefPtr<Paintable> retval (glib::wrap (
          (*base->get_current_image) (const_cast<GdkPaintable*> (gobj ())),
          true));
      return retval;
    }

    using RType = glib::RefPtr<Paintable>;
    return RType ();
  }

  auto
  gdk::Paintable::get_flags_vfunc () const -> Flags
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_flags)
    {
      Flags retval (static_cast<Flags> (
          (*base->get_flags) (const_cast<GdkPaintable*> (gobj ()))));
      return retval;
    }

    using RType = Flags;
    return RType ();
  }

  auto
  gdk::Paintable::get_intrinsic_width_vfunc () const -> int
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_width)
    {
      int retval (
          (*base->get_intrinsic_width) (const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  gdk::Paintable::get_intrinsic_height_vfunc () const -> int
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_height)
    {
      int retval (
          (*base->get_intrinsic_height) (const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

  auto
  gdk::Paintable::get_intrinsic_aspect_ratio_vfunc () const -> double
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_intrinsic_aspect_ratio)
    {
      double retval ((*base->get_intrinsic_aspect_ratio) (
          const_cast<GdkPaintable*> (gobj ())));
      return retval;
    }

    using RType = double;
    return RType ();
  }

} // namespace gdk
