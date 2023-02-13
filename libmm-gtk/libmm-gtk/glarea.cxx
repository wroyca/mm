


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/glarea.hxx>
#include <libmm-gtk/glarea_p.hxx>


/*
 * Copyright (C) 2015 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

namespace Gtk
{

auto GLArea::has_error() const -> bool
{
  return gtk_gl_area_get_error(const_cast<GtkGLArea*>(gobj()));
}

auto GLArea::throw_if_error () const -> void
{
  const GError* error = gtk_gl_area_get_error(const_cast<GtkGLArea*>(gobj()));
  if(error)
  {
    Glib::Error::throw_exception(g_error_copy(error));
  }
}

auto GLArea::unset_error () -> void
{
  gtk_gl_area_set_error(gobj(), nullptr);
}

} //namespace Gtk

namespace
{


auto GLArea_signal_create_context_callback(GtkGLArea* self, void* data) -> GdkGLContext*
{
  using namespace Gtk;
  using SlotType = sigc::slot<Glib::RefPtr<Gdk::GLContext>()>;

  const auto obj = dynamic_cast<GLArea*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return unwrap_copy((*static_cast<SlotType*>(slot))());
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkGLContext*;
  return RType();
}

auto GLArea_signal_create_context_notify_callback(GtkGLArea* self,  void* data) -> GdkGLContext*
{
  using namespace Gtk;
  using SlotType = sigc::slot<void()>;

  const auto obj = dynamic_cast<GLArea*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))();
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = GdkGLContext*;
  return RType();
}

const Glib::SignalProxyInfo GLArea_signal_create_context_info =
{
  "create_context",
  (GCallback) &GLArea_signal_create_context_callback,
  (GCallback) &GLArea_signal_create_context_notify_callback
};


auto GLArea_signal_render_callback(GtkGLArea* self, GdkGLContext* p0,void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<bool(const Glib::RefPtr<Gdk::GLContext>&)>;

  const auto obj = dynamic_cast<GLArea*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        return (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
        );
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

auto GLArea_signal_render_notify_callback(GtkGLArea* self, GdkGLContext* p0, void* data) -> gboolean
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gdk::GLContext>&)>;

  const auto obj = dynamic_cast<GLArea*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
  }

  using RType = gboolean;
  return RType();
}

const Glib::SignalProxyInfo GLArea_signal_render_info =
{
  "render",
  (GCallback) &GLArea_signal_render_callback,
  (GCallback) &GLArea_signal_render_notify_callback
};


auto GLArea_signal_resize_callback (GtkGLArea *self, const gint p0, const gint p1, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(int, int)>;

  const auto obj = dynamic_cast<GLArea*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo GLArea_signal_resize_info =
{
  "resize",
  (GCallback) &GLArea_signal_resize_callback,
  (GCallback) &GLArea_signal_resize_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkGLArea* object, const bool take_copy) -> Gtk::GLArea*
{
  return dynamic_cast<Gtk::GLArea *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto GLArea_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GLArea_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gl_area_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto GLArea_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->create_context = &create_context_callback;
  klass->render = &render_callback;
  klass->resize = &resize_callback;
}


auto GLArea_Class::create_context_callback(GtkGLArea* self) -> GdkGLContext*
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
        return unwrap_copy(obj->on_create_context());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->create_context)
    return (*base->create_context)(self);

  using RType = GdkGLContext*;
  return RType();
}
auto GLArea_Class::render_callback(GtkGLArea* self, GdkGLContext* p0) -> gboolean
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
        return obj->on_render(Glib::wrap(p0, true)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->render)
    return (*base->render)(self, p0);

  using RType = gboolean;
  return RType();
}
auto GLArea_Class::resize_callback (GtkGLArea *self, const gint p0, const gint p1) -> void
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
        obj->on_resize(p0
, p1
);
        return;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const auto base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->resize)
    (*base->resize)(self, p0, p1);
}


auto GLArea_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new GLArea((GtkGLArea*)o));

}


/* The implementation: */

GLArea::GLArea(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

GLArea::GLArea(GtkGLArea* castitem)
: Widget((GtkWidget*)castitem)
{
  }


GLArea::GLArea(GLArea&& src) noexcept
: Widget(std::move(src))
{}

auto GLArea::operator=(GLArea&& src) noexcept -> GLArea&
{
  Widget::operator=(std::move(src));
  return *this;
}

GLArea::~GLArea() noexcept
{
  destroy_();
}

GLArea::CppClassType GLArea::glarea_class_; // initialize static member

auto GLArea::get_type() -> GType
{
  return glarea_class_.init().get_type();
}


auto GLArea::get_base_type() -> GType
{
  return gtk_gl_area_get_type();
}


GLArea::GLArea()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(glarea_class_.init()))
{


}

auto GLArea::get_context() -> Glib::RefPtr<Gdk::GLContext>
{
  auto retvalue = Glib::wrap(gtk_gl_area_get_context(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto GLArea::get_context() const -> Glib::RefPtr<const Gdk::GLContext>
{
  return const_cast<GLArea*>(this)->get_context();
}

auto GLArea::make_current () -> void
{
  gtk_gl_area_make_current(gobj());
}

auto GLArea::queue_render () -> void
{
  gtk_gl_area_queue_render(gobj());
}

auto GLArea::attach_buffers () -> void
{
  gtk_gl_area_attach_buffers(gobj());
}

auto GLArea::set_error (const Glib::Error &error) -> void
{
  gtk_gl_area_set_error(gobj(), error.gobj());
}

auto GLArea::get_has_depth_buffer() const -> bool
{
  return gtk_gl_area_get_has_depth_buffer(const_cast<GtkGLArea*>(gobj()));
}

auto GLArea::set_has_depth_buffer (
  const bool has_depth_buffer) -> void
{
  gtk_gl_area_set_has_depth_buffer(gobj(), has_depth_buffer);
}

auto GLArea::get_has_stencil_buffer() const -> bool
{
  return gtk_gl_area_get_has_stencil_buffer(const_cast<GtkGLArea*>(gobj()));
}

auto GLArea::set_has_stencil_buffer (
  const bool has_stencil_buffer) -> void
{
  gtk_gl_area_set_has_stencil_buffer(gobj(), has_stencil_buffer);
}

auto GLArea::get_auto_render() const -> bool
{
  return gtk_gl_area_get_auto_render(const_cast<GtkGLArea*>(gobj()));
}

auto GLArea::set_auto_render (
  const bool auto_render) -> void
{
  gtk_gl_area_set_auto_render(gobj(), auto_render);
}

auto GLArea::get_required_version (int &major, int &minor) const -> void
{
  gtk_gl_area_get_required_version(const_cast<GtkGLArea*>(gobj()), &major, &minor);
}

auto GLArea::set_required_version (
  const int major, const int minor) -> void
{
  gtk_gl_area_set_required_version(gobj(), major, minor);
}

auto GLArea::get_use_es() const -> bool
{
  return gtk_gl_area_get_use_es(const_cast<GtkGLArea*>(gobj()));
}

auto GLArea::set_use_es (
  const bool use_es) -> void
{
  gtk_gl_area_set_use_es(gobj(), use_es);
}


auto GLArea::signal_create_context() -> Glib::SignalProxy<Glib::RefPtr<Gdk::GLContext>()>
{
  return {this, &GLArea_signal_create_context_info};
}


auto GLArea::signal_render() -> Glib::SignalProxy<bool(const Glib::RefPtr<Gdk::GLContext>&)>
{
  return {this, &GLArea_signal_render_info};
}


auto GLArea::signal_resize() -> Glib::SignalProxy<void(int, int)>
{
  return {this, &GLArea_signal_resize_info};
}


auto GLArea::property_auto_render() -> Glib::PropertyProxy< bool >
{
  return {this, "auto-render"};
}

auto GLArea::property_auto_render() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "auto-render"};
}

static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<Glib::RefPtr<Gdk::GLContext>>::value,
  "Type Glib::RefPtr<Gdk::GLContext> cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto GLArea::property_context() const -> Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::GLContext> >
{
  return {this, "context"};
}

auto GLArea::property_has_depth_buffer() -> Glib::PropertyProxy< bool >
{
  return {this, "has-depth-buffer"};
}

auto GLArea::property_has_depth_buffer() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-depth-buffer"};
}

auto GLArea::property_has_stencil_buffer() -> Glib::PropertyProxy< bool >
{
  return {this, "has-stencil-buffer"};
}

auto GLArea::property_has_stencil_buffer() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "has-stencil-buffer"};
}

auto GLArea::property_use_es() -> Glib::PropertyProxy< bool >
{
  return {this, "use-es"};
}

auto GLArea::property_use_es() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "use-es"};
}


auto GLArea::on_create_context() -> Glib::RefPtr<Gdk::GLContext>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->create_context)
    return Glib::wrap((*base->create_context)(gobj()));

  using RType = Glib::RefPtr<Gdk::GLContext>;
  return {};
}
auto GLArea::on_render(const Glib::RefPtr<Gdk::GLContext>& context) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->render)
    return (*base->render)(gobj(),Glib::unwrap(context));

  using RType = bool;
  return RType();
}
auto GLArea::on_resize (
  const int width, const int height) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->resize)
    (*base->resize)(gobj(),width,height);
}


} // namespace Gtk


