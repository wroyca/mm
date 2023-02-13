


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gdk/pixbufloader.hpp>
#include <libmm-gdk/pixbufloader_p.hpp>


/* Copyright 1998-2002 The gtkmm Development Team
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

#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

namespace
{

/* We use this helper function in the constructor to be able to throw
 * before the base class' (Glib::Object) constructor is called.
 */
auto pixbuf_loader_create_with_type(const Glib::ustring& image_type, const bool mime_type) -> GdkPixbufLoader*
{
  GError* error = nullptr;
  GdkPixbufLoader* loader = nullptr;

  if(mime_type)
    loader = gdk_pixbuf_loader_new_with_mime_type(image_type.c_str(), &error);
  else
    loader = gdk_pixbuf_loader_new_with_type(image_type.c_str(), &error);

  if(error)
    Glib::Error::throw_exception(error);

  return loader;
}

} // anonymous namespace


namespace Gdk
{

PixbufLoader::PixbufLoader(const Glib::ustring& image_type, const bool mime_type)
: ObjectBase(nullptr),
  Object((GObject*) pixbuf_loader_create_with_type(image_type, mime_type))
{}

} // namespace Gdk


namespace
{


const Glib::SignalProxyInfo PixbufLoader_signal_area_prepared_info =
{
  "area_prepared",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto PixbufLoader_signal_area_updated_callback (
  GdkPixbufLoader *self, const gint p0, const gint p1, const gint p2, const gint p3, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(int, int, int, int)>;

  const auto obj = dynamic_cast<PixbufLoader*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
, p2
, p3
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo PixbufLoader_signal_area_updated_info =
{
  "area_updated",
  (GCallback) &PixbufLoader_signal_area_updated_callback,
  (GCallback) &PixbufLoader_signal_area_updated_callback
};


const Glib::SignalProxyInfo PixbufLoader_signal_closed_info =
{
  "closed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto PixbufLoader_signal_size_prepared_callback (
  GdkPixbufLoader *self, const gint p0, const gint p1, void *data) -> void
{
  using namespace Gdk;
  using SlotType = sigc::slot<void(int, int)>;

  const auto obj = dynamic_cast<PixbufLoader*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
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

const Glib::SignalProxyInfo PixbufLoader_signal_size_prepared_info =
{
  "size_prepared",
  (GCallback) &PixbufLoader_signal_size_prepared_callback,
  (GCallback) &PixbufLoader_signal_size_prepared_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GdkPixbufLoader* object, const bool take_copy) -> RefPtr<Gdk::PixbufLoader>
{
  return Glib::make_refptr_for_instance<Gdk::PixbufLoader>( dynamic_cast<Gdk::PixbufLoader*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

auto PixbufLoader_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PixbufLoader_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_pixbuf_loader_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto PixbufLoader_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->area_prepared = &area_prepared_callback;
  klass->area_updated = &area_updated_callback;
  klass->closed = &closed_callback;
  klass->size_prepared = &size_prepared_callback;
}


auto PixbufLoader_Class::area_prepared_callback (GdkPixbufLoader *self) -> void
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
        obj->on_area_prepared();
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
  if(base && base->area_prepared)
    (*base->area_prepared)(self);
}
auto PixbufLoader_Class::area_updated_callback (
  GdkPixbufLoader *self, const gint p0, const gint p1, const gint p2, const gint p3) -> void
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
        obj->on_area_updated(p0
, p1
, p2
, p3
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
  if(base && base->area_updated)
    (*base->area_updated)(self, p0, p1, p2, p3);
}
auto PixbufLoader_Class::closed_callback (GdkPixbufLoader *self) -> void
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
        obj->on_closed();
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
  if(base && base->closed)
    (*base->closed)(self);
}
auto PixbufLoader_Class::size_prepared_callback (GdkPixbufLoader *self, const gint p0, const gint p1) -> void
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
        obj->on_size_prepared(p0
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
  if(base && base->size_prepared)
    (*base->size_prepared)(self, p0, p1);
}


auto PixbufLoader_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new PixbufLoader((GdkPixbufLoader*)object);
}


/* The implementation: */

auto PixbufLoader::gobj_copy() -> GdkPixbufLoader*
{
  reference();
  return gobj();
}

PixbufLoader::PixbufLoader(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

PixbufLoader::PixbufLoader(GdkPixbufLoader* castitem)
: Object((GObject*)castitem)
{}


PixbufLoader::PixbufLoader(PixbufLoader&& src) noexcept
: Object(std::move(src))
{}

auto PixbufLoader::operator=(PixbufLoader&& src) noexcept -> PixbufLoader&
{
  Object::operator=(std::move(src));
  return *this;
}


PixbufLoader::~PixbufLoader() noexcept = default;

PixbufLoader::CppClassType PixbufLoader::pixbufloader_class_; // initialize static member

auto PixbufLoader::get_type() -> GType
{
  return pixbufloader_class_.init().get_type();
}


auto PixbufLoader::get_base_type() -> GType
{
  return gdk_pixbuf_loader_get_type();
}


PixbufLoader::PixbufLoader()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(pixbufloader_class_.init()))
{


}

auto PixbufLoader::create() -> Glib::RefPtr<PixbufLoader>
{
  return Glib::make_refptr_for_instance<PixbufLoader>( new PixbufLoader() );
}

auto PixbufLoader::create(const Glib::ustring& image_type, const bool mime_type) -> Glib::RefPtr<PixbufLoader>
{
  return Glib::make_refptr_for_instance<PixbufLoader>( new PixbufLoader(image_type, mime_type) );
}

auto PixbufLoader::set_size (
  const int width, const int height) -> void
{
  gdk_pixbuf_loader_set_size(gobj(), width, height);
}

auto PixbufLoader::write (const guint8 *buf, const gsize count) -> void
{
  GError* gerror = nullptr;
  gdk_pixbuf_loader_write(gobj(), buf, count, &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto PixbufLoader::close () -> void
{
  GError* gerror = nullptr;
  gdk_pixbuf_loader_close(gobj(), &gerror);
  if(gerror)
    Glib::Error::throw_exception(gerror);
}

auto PixbufLoader::get_pixbuf() -> Glib::RefPtr<Pixbuf>
{
  auto retvalue = Glib::wrap(gdk_pixbuf_loader_get_pixbuf(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PixbufLoader::get_animation() -> Glib::RefPtr<PixbufAnimation>
{
  auto retvalue = Glib::wrap(gdk_pixbuf_loader_get_animation(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

auto PixbufLoader::get_format() const -> PixbufFormat
{
  return PixbufFormat(gdk_pixbuf_loader_get_format(const_cast<GdkPixbufLoader*>(gobj())));
}


auto PixbufLoader::signal_area_prepared() -> Glib::SignalProxy<void()>
{
  return {this, &PixbufLoader_signal_area_prepared_info};
}


auto PixbufLoader::signal_area_updated() -> Glib::SignalProxy<void(int, int, int, int)>
{
  return {this, &PixbufLoader_signal_area_updated_info};
}


auto PixbufLoader::signal_closed() -> Glib::SignalProxy<void()>
{
  return {this, &PixbufLoader_signal_closed_info};
}


auto PixbufLoader::signal_size_prepared() -> Glib::SignalProxy<void(int, int)>
{
  return {this, &PixbufLoader_signal_size_prepared_info};
}


auto PixbufLoader::on_area_prepared () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->area_prepared)
    (*base->area_prepared)(gobj());
}
auto PixbufLoader::on_area_updated (
  const int x, const int y, const int width, const int height) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->area_updated)
    (*base->area_updated)(gobj(),x,y,width,height);
}
auto PixbufLoader::on_closed () -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->closed)
    (*base->closed)(gobj());
}
auto PixbufLoader::on_size_prepared (
  const int width, const int height) -> void
{
  const auto base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->size_prepared)
    (*base->size_prepared)(gobj(),width,height);
}


} // namespace Gdk


