// SPDX-License-Identifier: LGPL-2.1-or-later

#include <gtk/gtk.h>
#include <libmm-glib/quark.hxx>
#include <libmm-gtk/object.hxx>
#include <libmm-gtk/object_p.hxx>

namespace Gtk
{

  Object::Object (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
    _init_unmanage ();
  }

  Object::Object (GObject* castitem)
    : Glib::Object (castitem)
  {
    _init_unmanage ();
  }

  auto
  Object::_init_unmanage () -> void
  {
    if (gobject_)
    {
      if (g_object_is_floating (gobject_))

      {
        GLIBMM_DEBUG_REFERENCE (this, gobject_);
        g_object_ref_sink (gobject_);

#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning (
            "gtkmm after sink: C++ instance: %p, C instance: %p, refcount=%d\n",
            (void*) (Glib::ObjectBase*) this,
            (void*) gobject_,
            G_OBJECT (gobject_)->ref_count);
        g_warning ("    c instance gtype: %s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

        referenced_ = true;
      }
      else
      {
        if (GTK_IS_WINDOW (gobject_))
          referenced_ = true;
        else
          referenced_ = false;
      }
    }
  }

  auto
  Object::_release_c_instance () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Gtk::Object::_release_c_instance() this=%p, gobject_=%p\n",
               (void*) (Glib::ObjectBase*) this,
               (void*) gobject_);
    if (gobject_)
      g_warning ("  gtypename: %s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

    cpp_destruction_in_progress_ = true;

    GObject* object = gobj ();

    if (object)
    {
      g_assert (G_IS_OBJECT (object));
      bool prevent_creation_of_another_wrapper = true;

      if (referenced_ || (GTK_IS_WIDGET (object) &&
                          !gtk_widget_get_parent (GTK_WIDGET (object))))
      {
#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("final unref: gtypename: %s, refcount: %d\n",
                   G_OBJECT_TYPE_NAME (object),
                   ((GObject*) object)->ref_count);
#endif

        if (!referenced_ && g_object_is_floating (object))
        {
          GLIBMM_DEBUG_REFERENCE (this, object);

          g_object_ref_sink (object);
        }

        GLIBMM_DEBUG_UNREFERENCE (this, object);
        g_object_unref (object);

        if (gobject_)
        {
#ifdef GLIBMM_DEBUG_REFCOUNTING
          g_warning ("Gtk::Object::_release_c_instance(): Calling "
                     "g_object_run_dispose(): "
                     "gobject_=%p, gtypename=%s\n",
                     (void*) object,
                     G_OBJECT_TYPE_NAME (object));
#endif

          g_assert (G_IS_OBJECT (object));
          if (GTK_IS_WIDGET (object) &&
              gtk_widget_get_parent (GTK_WIDGET (object)))

            prevent_creation_of_another_wrapper = false;
          else
            g_object_run_dispose (object);
        }
      }
      else
      {
#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("Gtk::Object::_release_c_instance(): Calling "
                   "g_object_run_dispose(): gobject_=%p\n",
                   (void*) gobject_);
#endif

        g_assert (G_IS_OBJECT (object));
        if (GTK_IS_WIDGET (object) &&
            gtk_widget_get_parent (GTK_WIDGET (object)))
          prevent_creation_of_another_wrapper = false;
        else
          g_object_run_dispose (object);
      }

      disconnect_cpp_wrapper (prevent_creation_of_another_wrapper);
    }
  }

  Object::Object (Object&& src) noexcept
    : Glib::Object (std::move (src)),
      referenced_ (std::move (src.referenced_))
  {
  }

  auto
  Object::operator= (Object&& src) noexcept -> Object&
  {
    Glib::Object::operator= (std::move (src));
    referenced_ = std::move (src.referenced_);
    return *this;
  }

  Object::~Object () noexcept
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Gtk::Object::~Object() gobject_=%p\n", (void*) gobject_);
#endif

    _release_c_instance ();
  }

  auto
  Object::disconnect_cpp_wrapper (bool prevent_creation_of_another_wrapper) -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Gtk::Object::disconnect_cpp_wrapper() this=%p, gobject_=%p\n",
               (void*) (Glib::ObjectBase*) this,
               (void*) gobject_);
    if (gobject_)
      g_warning ("  gtypename: %s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

    if (gobj ())
    {
      g_object_steal_qdata ((GObject*) gobj (), Glib::quark_);

      if (prevent_creation_of_another_wrapper)

        g_object_set_qdata ((GObject*) gobj (),
                            Glib::quark_cpp_wrapper_deleted_,
                            (gpointer) true);

      gobject_ = nullptr;
    }
  }

  auto
  Object::destroy_notify_ () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Gtk::Object::destroy_notify_: this=%p, gobject_=%p\n",
               (void*) (Glib::ObjectBase*) this,
               (void*) gobject_);
    if (gobject_)
      g_warning ("  gtypename=%s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

    gobject_ = nullptr;

    if (!cpp_destruction_in_progress_)

    {
      if (!referenced_)
      {
#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("Gtk::Object::destroy_notify_: before delete this.\n");
#endif
        delete this;
      }
      else
      {
#ifdef GLIBMM_DEBUG_REFCOUNTING
        g_warning ("Gtk::Object::destroy_notify_: setting gobject_ to 0\n");
#endif
      }
    }
  }

  auto
  Object::destroy_ () -> void
  {
#ifdef GLIBMM_DEBUG_REFCOUNTING
    g_warning ("Gtk::Object::destroy_(): gobject_: %p\n", (void*) gobject_);
    if (gobject_)
      g_warning ("  gtypename: %s\n", G_OBJECT_TYPE_NAME (gobject_));
#endif

    if (!cpp_destruction_in_progress_)
    {
      cpp_destruction_in_progress_ = true;

      _release_c_instance ();
    }
  }

  auto
  Object::set_manage () -> void
  {
    if (!referenced_)
      return;

    if (gobject_->ref_count >= 1)

    {
#ifdef GLIBMM_DEBUG_REFCOUNTING
      g_warning ("Object::set_manage(): setting GTK_FLOATING: gobject_ = %p",
                 (void*) gobj ());
      g_warning ("  gtypename=%s\n", G_OBJECT_TYPE_NAME (gobj ()));
#endif

      g_object_force_floating (gobject_);
    }
    else
    {
      g_warning ("Object::set_manage(). Refcount seems to be 0. %s\n",
                 G_OBJECT_TYPE_NAME (gobject_));
    }

    referenced_ = false;
  }

  auto
  Object::is_managed_ () const -> bool
  {
    return !referenced_;
  }

} // namespace Gtk

namespace Gtk
{

  auto
  Object_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Object_Class::class_init_function;

      register_derived_type (g_object_get_type ());
    }

    return *this;
  }

  auto
  Object_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    BaseClassType* const klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Object_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new Object ((GObject*) (o)));
  }

  Object::CppClassType Object::object_class_;

  auto
  Object::get_type () -> GType
  {
    return object_class_.init ().get_type ();
  }

  auto
  Object::get_base_type () -> GType
  {
    return g_object_get_type ();
  }

} // namespace Gtk
