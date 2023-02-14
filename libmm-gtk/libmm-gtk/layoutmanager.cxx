// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/layoutmanager.hxx>
#include <libmm-gtk/layoutmanager_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/layoutchild.hxx>
#include <libmm-gtk/widget.hxx>

namespace Gtk
{

  auto
  LayoutManager_Class::measure_vfunc_callback (GtkLayoutManager* self,
                                               GtkWidget* widget,
                                               GtkOrientation orientation,
                                               const int for_size,
                                               int* minimum,
                                               int* natural,
                                               int* minimum_baseline,
                                               int* natural_baseline) -> void
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
          int no_minimum = 0;
          int no_natural = 0;
          int no_minimum_baseline = 0;
          int no_natural_baseline = 0;
          obj->measure_vfunc (
              *Glib::wrap (widget),
              static_cast<Orientation> (orientation),
              for_size,
              minimum ? *minimum : no_minimum,
              natural ? *natural : no_natural,
              minimum_baseline ? *minimum_baseline : no_minimum_baseline,
              natural_baseline ? *natural_baseline : no_natural_baseline);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->measure)
      (*base->measure) (self,
                        widget,
                        orientation,
                        for_size,
                        minimum,
                        natural,
                        minimum_baseline,
                        natural_baseline);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkLayoutManager* object, const bool take_copy) -> RefPtr<Gtk::LayoutManager>
  {
    return Glib::make_refptr_for_instance<Gtk::LayoutManager> (
        dynamic_cast<Gtk::LayoutManager*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  LayoutManager_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LayoutManager_Class::class_init_function;

      register_derived_type (gtk_layout_manager_get_type ());
    }

    return *this;
  }

  auto
  LayoutManager_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->get_request_mode = &get_request_mode_vfunc_callback;
    klass->measure = &measure_vfunc_callback;
    klass->allocate = &allocate_vfunc_callback;
    klass->create_layout_child = &create_layout_child_vfunc_callback;
    klass->root = &root_vfunc_callback;
    klass->unroot = &unroot_vfunc_callback;
  }

  auto
  LayoutManager_Class::get_request_mode_vfunc_callback (GtkLayoutManager* self,
                                                        GtkWidget* widget) -> GtkSizeRequestMode
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
          return static_cast<GtkSizeRequestMode> (
              obj->get_request_mode_vfunc (*Glib::wrap (widget)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->get_request_mode)
      return (*base->get_request_mode) (self, widget);

    using RType = GtkSizeRequestMode;
    return RType ();
  }

  auto
  LayoutManager_Class::allocate_vfunc_callback (GtkLayoutManager* self,
                                                GtkWidget* widget,
                                                const int width,
                                                const int height,
                                                const int baseline) -> void
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
          obj->allocate_vfunc (*Glib::wrap (widget), width, height, baseline);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->allocate)
      (*base->allocate) (self, widget, width, height, baseline);
  }

  auto
  LayoutManager_Class::create_layout_child_vfunc_callback (
      GtkLayoutManager* self,
      GtkWidget* widget,
      GtkWidget* for_child) -> GtkLayoutChild*
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
          return Glib::unwrap (
              obj->create_layout_child_vfunc (*Glib::wrap (widget),
                                              *Glib::wrap (for_child)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->create_layout_child)
      return (*base->create_layout_child) (self, widget, for_child);

    using RType = GtkLayoutChild*;
    return RType ();
  }

  auto
  LayoutManager_Class::root_vfunc_callback (GtkLayoutManager* self) -> void
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
          obj->root_vfunc ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->root)
      (*base->root) (self);
  }

  auto
  LayoutManager_Class::unroot_vfunc_callback (GtkLayoutManager* self) -> void
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
          obj->unroot_vfunc ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->unroot)
      (*base->unroot) (self);
  }

  auto
  LayoutManager_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new LayoutManager ((GtkLayoutManager*) object);
  }

  auto
  LayoutManager::gobj_copy () -> GtkLayoutManager*
  {
    reference ();
    return gobj ();
  }

  LayoutManager::LayoutManager (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  LayoutManager::LayoutManager (GtkLayoutManager* castitem)
    : Object ((GObject*) castitem)
  {
  }

  LayoutManager::LayoutManager (LayoutManager&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  LayoutManager::operator= (LayoutManager&& src) noexcept -> LayoutManager&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  LayoutManager::~LayoutManager () noexcept = default;

  LayoutManager::CppClassType LayoutManager::layoutmanager_class_;

  auto
  LayoutManager::get_type () -> GType
  {
    return layoutmanager_class_.init ().get_type ();
  }

  auto
  LayoutManager::get_base_type () -> GType
  {
    return gtk_layout_manager_get_type ();
  }

  LayoutManager::LayoutManager ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (layoutmanager_class_.init ()))
  {
  }

  auto
  LayoutManager::measure (Widget& widget,
                          Orientation orientation,
                          const int for_size,
                          int& minimum,
                          int& natural,
                          int& minimum_baseline,
                          int& natural_baseline) const -> void
  {
    gtk_layout_manager_measure (const_cast<GtkLayoutManager*> (gobj ()),
                                widget.gobj (),
                                static_cast<GtkOrientation> (orientation),
                                for_size,
                                &minimum,
                                &natural,
                                &minimum_baseline,
                                &natural_baseline);
  }

  auto
  LayoutManager::allocate (Widget& widget,
                           const int width,
                           const int height,
                           const int baseline) -> void
  {
    gtk_layout_manager_allocate (gobj (),
                                 widget.gobj (),
                                 width,
                                 height,
                                 baseline);
  }

  auto
  LayoutManager::get_request_mode () const -> SizeRequestMode
  {
    return static_cast<SizeRequestMode> (gtk_layout_manager_get_request_mode (
        const_cast<GtkLayoutManager*> (gobj ())));
  }

  auto
  LayoutManager::get_widget () -> Widget*
  {
    return Glib::wrap (gtk_layout_manager_get_widget (gobj ()));
  }

  auto
  LayoutManager::get_widget () const -> const Widget*
  {
    return const_cast<LayoutManager*> (this)->get_widget ();
  }

  auto
  LayoutManager::layout_changed () -> void
  {
    gtk_layout_manager_layout_changed (gobj ());
  }

  auto
  LayoutManager::get_layout_child (Widget& child) -> Glib::RefPtr<LayoutChild>
  {
    auto retvalue = Glib::wrap (
        gtk_layout_manager_get_layout_child (gobj (), child.gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  LayoutManager::get_layout_child (Widget& child) const -> Glib::RefPtr<const LayoutChild>
  {
    return const_cast<LayoutManager*> (this)->get_layout_child (child);
  }

  auto
  LayoutManager::get_request_mode_vfunc (const Widget& widget) const -> SizeRequestMode
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->get_request_mode)
    {
      const SizeRequestMode retval (static_cast<SizeRequestMode> (
          (*base->get_request_mode) (const_cast<GtkLayoutManager*> (gobj ()),
                                     const_cast<GtkWidget*> (widget.gobj ()))));
      return retval;
    }

    using RType = SizeRequestMode;
    return RType ();
  }

  auto
  LayoutManager::measure_vfunc (const Widget& widget,
                                Orientation orientation,
                                const int for_size,
                                int& minimum,
                                int& natural,
                                int& minimum_baseline,
                                int& natural_baseline) const -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->measure)
    {
      (*base->measure) (const_cast<GtkLayoutManager*> (gobj ()),
                        const_cast<GtkWidget*> (widget.gobj ()),
                        static_cast<GtkOrientation> (orientation),
                        for_size,
                        &minimum,
                        &natural,
                        &minimum_baseline,
                        &natural_baseline);
    }
  }

  auto
  LayoutManager::allocate_vfunc (const Widget& widget,
                                 const int width,
                                 const int height,
                                 const int baseline) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->allocate)
    {
      (*base->allocate) (gobj (),
                         const_cast<GtkWidget*> (widget.gobj ()),
                         width,
                         height,
                         baseline);
    }
  }

  auto
  LayoutManager::create_layout_child_vfunc (const Widget& widget,
                                            const Widget& for_child) -> Glib::RefPtr<LayoutChild>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_layout_child)
    {
      Glib::RefPtr<LayoutChild> retval (
          Glib::wrap ((*base->create_layout_child) (
                          gobj (),
                          const_cast<GtkWidget*> (widget.gobj ()),
                          const_cast<GtkWidget*> (for_child.gobj ())),
                      true));
      return retval;
    }

    using RType = Glib::RefPtr<LayoutChild>;
    return {};
  }

  auto
  LayoutManager::root_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->root)
    {
      (*base->root) (gobj ());
    }
  }

  auto
  LayoutManager::unroot_vfunc () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->unroot)
    {
      (*base->unroot) (gobj ());
    }
  }

} // namespace Gtk
