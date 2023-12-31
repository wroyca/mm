// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/glarea.hxx>
#include <libmm/gtk/glarea_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  auto
  GLArea::has_error () const -> bool
  {
    return gtk_gl_area_get_error (const_cast<GtkGLArea*> (gobj ()));
  }

  auto
  GLArea::throw_if_error () const -> void
  {
    GError* error = gtk_gl_area_get_error (const_cast<GtkGLArea*> (gobj ()));
    if (error)
    {
      glib::Error::throw_exception (g_error_copy (error));
    }
  }

  auto
  GLArea::unset_error () -> void
  {
    gtk_gl_area_set_error (gobj (), nullptr);
  }

} // namespace gtk

namespace
{

  static auto
  GLArea_signal_create_context_callback (GtkGLArea* self, void* data) -> GdkGLContext*
  {
    using namespace gtk;
    using SlotType = sigc::slot<glib::RefPtr<gdk::GLContext> ()>;

    auto obj = dynamic_cast<GLArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return glib::unwrap_copy ((*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkGLContext*;
    return RType ();
  }

  static auto
  GLArea_signal_create_context_notify_callback (GtkGLArea* self, void* data) -> GdkGLContext*
  {
    using namespace gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<GLArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = GdkGLContext*;
    return RType ();
  }

  static const glib::SignalProxyInfo GLArea_signal_create_context_info = {
      "create_context",
      (GCallback) &GLArea_signal_create_context_callback,
      (GCallback) &GLArea_signal_create_context_notify_callback};

  static auto
  GLArea_signal_render_callback (GtkGLArea* self, GdkGLContext* p0, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool (const glib::RefPtr<gdk::GLContext>&)>;

    auto obj = dynamic_cast<GLArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> (
              (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true)));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  GLArea_signal_render_notify_callback (GtkGLArea* self,
                                        GdkGLContext* p0,
                                        void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (const glib::RefPtr<gdk::GLContext>&)>;

    auto obj = dynamic_cast<GLArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (glib::wrap (p0, true));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo GLArea_signal_render_info = {
      "render",
      (GCallback) &GLArea_signal_render_callback,
      (GCallback) &GLArea_signal_render_notify_callback};

  static auto
  GLArea_signal_resize_callback (GtkGLArea* self, gint p0, gint p1, void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int, int)>;

    auto obj = dynamic_cast<GLArea*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo GLArea_signal_resize_info = {
      "resize",
      (GCallback) &GLArea_signal_resize_callback,
      (GCallback) &GLArea_signal_resize_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkGLArea* object, bool take_copy) -> gtk::GLArea*
  {
    return dynamic_cast<gtk::GLArea*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  GLArea_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &GLArea_Class::class_init_function;

      register_derived_type (gtk_gl_area_get_type ());
    }

    return *this;
  }

  auto
  GLArea_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->create_context = &create_context_callback;
    klass->render = &render_callback;
    klass->resize = &resize_callback;
  }

  auto
  GLArea_Class::create_context_callback (GtkGLArea* self) -> GdkGLContext*
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
          return glib::unwrap_copy (obj->on_create_context ());
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->create_context)
      return (*base->create_context) (self);

    using RType = GdkGLContext*;
    return RType ();
  }

  auto
  GLArea_Class::render_callback (GtkGLArea* self, GdkGLContext* p0) -> gboolean
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
          return static_cast<int> (obj->on_render (glib::wrap (p0, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->render)
      return (*base->render) (self, p0);

    using RType = gboolean;
    return RType ();
  }

  auto
  GLArea_Class::resize_callback (GtkGLArea* self, gint p0, gint p1) -> void
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
          obj->on_resize (p0, p1);
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->resize)
      (*base->resize) (self, p0, p1);
  }

  auto
  GLArea_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new GLArea ((GtkGLArea*) (o)));
  }

  GLArea::GLArea (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  GLArea::GLArea (GtkGLArea* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  GLArea::GLArea (GLArea&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  GLArea::operator= (GLArea&& src) noexcept -> GLArea&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  GLArea::~GLArea () noexcept
  {
    destroy_ ();
  }

  GLArea::CppClassType GLArea::glarea_class_;

  auto
  GLArea::get_type () -> GType
  {
    return glarea_class_.init ().get_type ();
  }

  auto
  GLArea::get_base_type () -> GType
  {
    return gtk_gl_area_get_type ();
  }

  GLArea::GLArea ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (glarea_class_.init ()))
  {
  }

  auto
  GLArea::get_context () -> glib::RefPtr<gdk::GLContext>
  {
    auto retvalue = glib::wrap (gtk_gl_area_get_context (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  GLArea::get_context () const -> glib::RefPtr<const gdk::GLContext>
  {
    return const_cast<GLArea*> (this)->get_context ();
  }

  auto
  GLArea::make_current () -> void
  {
    gtk_gl_area_make_current (gobj ());
  }

  auto
  GLArea::queue_render () -> void
  {
    gtk_gl_area_queue_render (gobj ());
  }

  auto
  GLArea::attach_buffers () -> void
  {
    gtk_gl_area_attach_buffers (gobj ());
  }

  auto
  GLArea::set_error (const glib::Error& error) -> void
  {
    gtk_gl_area_set_error (gobj (), (error).gobj ());
  }

  auto
  GLArea::get_has_depth_buffer () const -> bool
  {
    return gtk_gl_area_get_has_depth_buffer (const_cast<GtkGLArea*> (gobj ()));
  }

  auto
  GLArea::set_has_depth_buffer (bool has_depth_buffer) -> void
  {
    gtk_gl_area_set_has_depth_buffer (gobj (),
                                      static_cast<int> (has_depth_buffer));
  }

  auto
  GLArea::get_has_stencil_buffer () const -> bool
  {
    return gtk_gl_area_get_has_stencil_buffer (
        const_cast<GtkGLArea*> (gobj ()));
  }

  auto
  GLArea::set_has_stencil_buffer (bool has_stencil_buffer) -> void
  {
    gtk_gl_area_set_has_stencil_buffer (gobj (),
                                        static_cast<int> (has_stencil_buffer));
  }

  auto
  GLArea::get_auto_render () const -> bool
  {
    return gtk_gl_area_get_auto_render (const_cast<GtkGLArea*> (gobj ()));
  }

  auto
  GLArea::set_auto_render (bool auto_render) -> void
  {
    gtk_gl_area_set_auto_render (gobj (), static_cast<int> (auto_render));
  }

  auto
  GLArea::get_required_version (int& major, int& minor) const -> void
  {
    gtk_gl_area_get_required_version (const_cast<GtkGLArea*> (gobj ()),
                                      &(major),
                                      &(minor));
  }

  auto
  GLArea::set_required_version (int major, int minor) -> void
  {
    gtk_gl_area_set_required_version (gobj (), major, minor);
  }

  auto
  GLArea::get_use_es () const -> bool
  {
    return gtk_gl_area_get_use_es (const_cast<GtkGLArea*> (gobj ()));
  }

  auto
  GLArea::set_use_es (bool use_es) -> void
  {
    gtk_gl_area_set_use_es (gobj (), static_cast<int> (use_es));
  }

  auto
  GLArea::signal_create_context () -> glib::SignalProxy<glib::RefPtr<gdk::GLContext> ()>
  {
    return glib::SignalProxy<glib::RefPtr<gdk::GLContext> ()> (
        this,
        &GLArea_signal_create_context_info);
  }

  auto
  GLArea::signal_render () -> glib::SignalProxy<bool (const glib::RefPtr<gdk::GLContext>&)>
  {
    return glib::SignalProxy<bool (const glib::RefPtr<gdk::GLContext>&)> (
        this,
        &GLArea_signal_render_info);
  }

  auto
  GLArea::signal_resize () -> glib::SignalProxy<void (int, int)>
  {
    return glib::SignalProxy<void (int, int)> (this,
                                               &GLArea_signal_resize_info);
  }

  auto
  GLArea::property_auto_render () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "auto-render");
  }

  auto
  GLArea::property_auto_render () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "auto-render");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gdk::GLContext>>::value,
      "Type glib::RefPtr<gdk::GLContext> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  GLArea::property_context () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::GLContext>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::GLContext>> (
        this,
        "context");
  }

  auto
  GLArea::property_has_depth_buffer () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-depth-buffer");
  }

  auto
  GLArea::property_has_depth_buffer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-depth-buffer");
  }

  auto
  GLArea::property_has_stencil_buffer () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-stencil-buffer");
  }

  auto
  GLArea::property_has_stencil_buffer () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-stencil-buffer");
  }

  auto
  GLArea::property_use_es () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-es");
  }

  auto
  GLArea::property_use_es () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-es");
  }

  auto
  gtk::GLArea::on_create_context () -> glib::RefPtr<gdk::GLContext>
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->create_context)
      return glib::wrap ((*base->create_context) (gobj ()));

    using RType = glib::RefPtr<gdk::GLContext>;
    return RType ();
  }

  auto
  gtk::GLArea::on_render (const glib::RefPtr<gdk::GLContext>& context) -> bool
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->render)
      return (*base->render) (gobj (), glib::unwrap (context));

    using RType = bool;
    return RType ();
  }

  auto
  gtk::GLArea::on_resize (int width, int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->resize)
      (*base->resize) (gobj (), width, height);
  }

} // namespace gtk
