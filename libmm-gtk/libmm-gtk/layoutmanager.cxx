


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/layoutmanager.hpp>
#include <libmm-gtk/layoutmanager_p.hpp>


/* Copyright (C) 2019 The gtkmm Development Team
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

#include <libmm-gtk/layoutchild.hpp>
#include <libmm-gtk/widget.hpp>
#include <gtk/gtk.h>

namespace Gtk
{
// This vfunc callback is custom implemented because we want the output
// arguments of the C++ vfunc to be int& (not int*), and the vfunc_callback
// function may be called from gtk with NULL pointers.
auto LayoutManager_Class::measure_vfunc_callback (
  GtkLayoutManager *self,
  GtkWidget *widget, GtkOrientation orientation, const int for_size,
  int *minimum, int *natural, int *minimum_baseline, int *natural_baseline) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if (obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if (obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        int no_minimum = 0;
        int no_natural = 0;
        int no_minimum_baseline = 0;
        int no_natural_baseline = 0;
        obj->measure_vfunc(*Glib::wrap(widget),
          static_cast<Orientation>(orientation), for_size,
          minimum ? *minimum : no_minimum,
          natural ? *natural : no_natural,
          minimum_baseline ? *minimum_baseline : no_minimum_baseline,
          natural_baseline ? *natural_baseline : no_natural_baseline);
        return;
      }
      catch (...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->measure)
    (*base->measure)(self, widget, orientation, for_size, minimum, natural, minimum_baseline, natural_baseline);
}

} // namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkLayoutManager* object, const bool take_copy) -> RefPtr<Gtk::LayoutManager>
{
  return Glib::make_refptr_for_instance<Gtk::LayoutManager>( dynamic_cast<Gtk::LayoutManager*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

auto LayoutManager_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &LayoutManager_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_layout_manager_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto LayoutManager_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->get_request_mode = &get_request_mode_vfunc_callback;
  klass->measure = &measure_vfunc_callback;
  klass->allocate = &allocate_vfunc_callback;
  klass->create_layout_child = &create_layout_child_vfunc_callback;
  klass->root = &root_vfunc_callback;
  klass->unroot = &unroot_vfunc_callback;

}

auto LayoutManager_Class::get_request_mode_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget) -> GtkSizeRequestMode
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<GtkSizeRequestMode>(obj->get_request_mode_vfunc(*Glib::wrap(widget)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->get_request_mode)
    return (*base->get_request_mode)(self, widget);

  using RType = GtkSizeRequestMode;
  return RType();
}
auto LayoutManager_Class::allocate_vfunc_callback (
  GtkLayoutManager *self, GtkWidget *widget, const int width, const int height, const int baseline) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->allocate_vfunc(*Glib::wrap(widget)
, width, height, baseline);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->allocate)
    (*base->allocate)(self, widget, width, height, baseline);
}
auto LayoutManager_Class::create_layout_child_vfunc_callback(GtkLayoutManager* self, GtkWidget* widget, GtkWidget* for_child) -> GtkLayoutChild*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return Glib::unwrap(obj->create_layout_child_vfunc(*Glib::wrap(widget)
, *Glib::wrap(for_child)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->create_layout_child)
    return (*base->create_layout_child)(self, widget, for_child);

  using RType = GtkLayoutChild*;
  return RType();
}
auto LayoutManager_Class::root_vfunc_callback (GtkLayoutManager *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->root_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->root)
    (*base->root)(self);
}
auto LayoutManager_Class::unroot_vfunc_callback (GtkLayoutManager *self) -> void
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        obj->unroot_vfunc();
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->unroot)
    (*base->unroot)(self);
}


auto LayoutManager_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new LayoutManager((GtkLayoutManager*)object);
}


/* The implementation: */

auto LayoutManager::gobj_copy() -> GtkLayoutManager*
{
  reference();
  return gobj();
}

LayoutManager::LayoutManager(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

LayoutManager::LayoutManager(GtkLayoutManager* castitem)
: Object((GObject*)castitem)
{}


LayoutManager::LayoutManager(LayoutManager&& src) noexcept
: Object(std::move(src))
{}

auto LayoutManager::operator=(LayoutManager&& src) noexcept -> LayoutManager&
{
  Object::operator=(std::move(src));
  return *this;
}


LayoutManager::~LayoutManager() noexcept = default;

LayoutManager::CppClassType LayoutManager::layoutmanager_class_; // initialize static member

auto LayoutManager::get_type() -> GType
{
  return layoutmanager_class_.init().get_type();
}


auto LayoutManager::get_base_type() -> GType
{
  return gtk_layout_manager_get_type();
}


LayoutManager::LayoutManager()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(layoutmanager_class_.init()))
{


}

auto LayoutManager::measure (
  Widget &widget, Orientation orientation, const int for_size, int &minimum, int &natural,
  int &minimum_baseline, int &natural_baseline) const -> void
{
  gtk_layout_manager_measure(const_cast<GtkLayoutManager*>(gobj()), widget.gobj(), static_cast<GtkOrientation>(orientation), for_size, &minimum, &natural, &minimum_baseline, &natural_baseline);
}

auto LayoutManager::allocate (Widget &widget, const int width, const int height, const int baseline) -> void
{
  gtk_layout_manager_allocate(gobj(), widget.gobj(), width, height, baseline);
}

auto LayoutManager::get_request_mode() const -> SizeRequestMode
{
  return static_cast<SizeRequestMode>(gtk_layout_manager_get_request_mode(const_cast<GtkLayoutManager*>(gobj())));
}

auto LayoutManager::get_widget() -> Widget*
{
  return Glib::wrap(gtk_layout_manager_get_widget(gobj()));
}

auto LayoutManager::get_widget() const -> const Widget*
{
  return const_cast<LayoutManager*>(this)->get_widget();
}

auto LayoutManager::layout_changed () -> void
{
  gtk_layout_manager_layout_changed(gobj());
}

auto LayoutManager::get_layout_child(Widget& child) -> Glib::RefPtr<LayoutChild>
{
  auto retvalue = Glib::wrap(gtk_layout_manager_get_layout_child(gobj(), child.gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto LayoutManager::get_layout_child(Widget& child) const -> Glib::RefPtr<const LayoutChild>
{
  return const_cast<LayoutManager*>(this)->get_layout_child(child);
}


auto LayoutManager::get_request_mode_vfunc(const Widget& widget) const -> SizeRequestMode
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->get_request_mode)
  {
    const SizeRequestMode retval(static_cast<SizeRequestMode>((*base->get_request_mode)(const_cast<GtkLayoutManager*>(gobj()),const_cast<GtkWidget*>(widget.gobj()))));
    return retval;
  }

  using RType = SizeRequestMode;
  return RType();
}
auto LayoutManager::measure_vfunc (
  const Widget &widget, Orientation orientation, const int for_size, int &minimum, int &natural,
  int &minimum_baseline, int &natural_baseline) const -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->measure)
  {
    (*base->measure)(const_cast<GtkLayoutManager*>(gobj()),const_cast<GtkWidget*>(widget.gobj()),static_cast<GtkOrientation>(orientation),for_size,&minimum,&natural,&minimum_baseline,&natural_baseline);
  }
}
auto LayoutManager::allocate_vfunc (
  const Widget &widget, const int width, const int height, const int baseline) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->allocate)
  {
    (*base->allocate)(gobj(),const_cast<GtkWidget*>(widget.gobj()),width,height,baseline);
  }
}
auto LayoutManager::create_layout_child_vfunc(const Widget& widget, const Widget& for_child) -> Glib::RefPtr<LayoutChild>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->create_layout_child)
  {
    Glib::RefPtr<LayoutChild> retval(Glib::wrap((*base->create_layout_child)(gobj(),const_cast<GtkWidget*>(widget.gobj()),const_cast<GtkWidget*>(for_child.gobj())), true));
    return retval;
  }

  using RType = Glib::RefPtr<LayoutChild>;
  return {};
}
auto LayoutManager::root_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->root)
  {
    (*base->root)(gobj());
  }
}
auto LayoutManager::unroot_vfunc () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->unroot)
  {
    (*base->unroot)(gobj());
  }
}


} // namespace Gtk


