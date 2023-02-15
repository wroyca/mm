// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/pixbufloader.hxx>
#include <libmm-gdk/pixbufloader_p.hxx>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gdk/gdk.h>

namespace
{

  static auto
  pixbuf_loader_create_with_type (const Glib::ustring& image_type,
                                  bool mime_type) -> GdkPixbufLoader*
  {
    GError* error = nullptr;
    GdkPixbufLoader* loader = nullptr;

    if (mime_type)
      loader = gdk_pixbuf_loader_new_with_mime_type (image_type.c_str (),
                                                     &error);
    else
      loader = gdk_pixbuf_loader_new_with_type (image_type.c_str (), &error);

    if (error)
      Glib::Error::throw_exception (error);

    return loader;
  }

} // namespace

namespace Gdk
{

  PixbufLoader::PixbufLoader (const Glib::ustring& image_type, bool mime_type)
    : Glib::ObjectBase (nullptr),
      Glib::Object (
          (GObject*) pixbuf_loader_create_with_type (image_type, mime_type))
  {
  }

} // namespace Gdk

namespace
{

  static const Glib::SignalProxyInfo PixbufLoader_signal_area_prepared_info = {
      "area_prepared",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  PixbufLoader_signal_area_updated_callback (GdkPixbufLoader* self,
                                             gint p0,
                                             gint p1,
                                             gint p2,
                                             gint p3,
                                             void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (int, int, int, int)>;

    auto obj = dynamic_cast<PixbufLoader*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2, p3);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo PixbufLoader_signal_area_updated_info = {
      "area_updated",
      (GCallback) &PixbufLoader_signal_area_updated_callback,
      (GCallback) &PixbufLoader_signal_area_updated_callback};

  static const Glib::SignalProxyInfo PixbufLoader_signal_closed_info = {
      "closed",
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
      (GCallback) &Glib::SignalProxyNormal::slot0_void_callback};

  static auto
  PixbufLoader_signal_size_prepared_callback (GdkPixbufLoader* self,
                                              gint p0,
                                              gint p1,
                                              void* data) -> void
  {
    using namespace Gdk;
    using SlotType = sigc::slot<void (int, int)>;

    auto obj = dynamic_cast<PixbufLoader*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo PixbufLoader_signal_size_prepared_info = {
      "size_prepared",
      (GCallback) &PixbufLoader_signal_size_prepared_callback,
      (GCallback) &PixbufLoader_signal_size_prepared_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GdkPixbufLoader* object, bool take_copy) -> Glib::RefPtr<Gdk::PixbufLoader>
  {
    return Glib::make_refptr_for_instance<Gdk::PixbufLoader> (
        dynamic_cast<Gdk::PixbufLoader*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gdk
{

  auto
  PixbufLoader_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PixbufLoader_Class::class_init_function;

      register_derived_type (gdk_pixbuf_loader_get_type ());
    }

    return *this;
  }

  auto
  PixbufLoader_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->area_prepared = &area_prepared_callback;
    klass->area_updated = &area_updated_callback;
    klass->closed = &closed_callback;
    klass->size_prepared = &size_prepared_callback;
  }

  auto
  PixbufLoader_Class::area_prepared_callback (GdkPixbufLoader* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_area_prepared ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->area_prepared)
      (*base->area_prepared) (self);
  }

  auto
  PixbufLoader_Class::area_updated_callback (GdkPixbufLoader* self,
                                             gint p0,
                                             gint p1,
                                             gint p2,
                                             gint p3) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_area_updated (p0, p1, p2, p3);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->area_updated)
      (*base->area_updated) (self, p0, p1, p2, p3);
  }

  auto
  PixbufLoader_Class::closed_callback (GdkPixbufLoader* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_closed ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->closed)
      (*base->closed) (self);
  }

  auto
  PixbufLoader_Class::size_prepared_callback (GdkPixbufLoader* self,
                                              gint p0,
                                              gint p1) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_size_prepared (p0, p1);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->size_prepared)
      (*base->size_prepared) (self, p0, p1);
  }

  auto
  PixbufLoader_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new PixbufLoader ((GdkPixbufLoader*) object);
  }

  auto
  PixbufLoader::gobj_copy () -> GdkPixbufLoader*
  {
    reference ();
    return gobj ();
  }

  PixbufLoader::PixbufLoader (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  PixbufLoader::PixbufLoader (GdkPixbufLoader* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  PixbufLoader::PixbufLoader (PixbufLoader&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  PixbufLoader::operator= (PixbufLoader&& src) noexcept -> PixbufLoader&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  PixbufLoader::~PixbufLoader () noexcept {}

  PixbufLoader::CppClassType PixbufLoader::pixbufloader_class_;

  auto
  PixbufLoader::get_type () -> GType
  {
    return pixbufloader_class_.init ().get_type ();
  }

  auto
  PixbufLoader::get_base_type () -> GType
  {
    return gdk_pixbuf_loader_get_type ();
  }

  PixbufLoader::PixbufLoader ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (pixbufloader_class_.init ()))
  {
  }

  auto
  PixbufLoader::create () -> Glib::RefPtr<PixbufLoader>
  {
    return Glib::make_refptr_for_instance<PixbufLoader> (new PixbufLoader ());
  }

  auto
  PixbufLoader::create (const Glib::ustring& image_type, bool mime_type) -> Glib::RefPtr<PixbufLoader>
  {
    return Glib::make_refptr_for_instance<PixbufLoader> (
        new PixbufLoader (image_type, mime_type));
  }

  auto
  PixbufLoader::set_size (int width, int height) -> void
  {
    gdk_pixbuf_loader_set_size (gobj (), width, height);
  }

  auto
  PixbufLoader::write (const guint8* buf, gsize count) -> void
  {
    GError* gerror = nullptr;
    gdk_pixbuf_loader_write (gobj (), (buf), count, &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
  }

  auto
  PixbufLoader::close () -> void
  {
    GError* gerror = nullptr;
    gdk_pixbuf_loader_close (gobj (), &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
  }

  auto
  PixbufLoader::get_pixbuf () -> Glib::RefPtr<Gdk::Pixbuf>
  {
    auto retvalue = Glib::wrap (gdk_pixbuf_loader_get_pixbuf (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PixbufLoader::get_animation () -> Glib::RefPtr<Gdk::PixbufAnimation>
  {
    auto retvalue = Glib::wrap (gdk_pixbuf_loader_get_animation (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PixbufLoader::get_format () const -> PixbufFormat
  {
    return PixbufFormat (
        gdk_pixbuf_loader_get_format (const_cast<GdkPixbufLoader*> (gobj ())));
  }

  auto
  PixbufLoader::signal_area_prepared () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this,
                                       &PixbufLoader_signal_area_prepared_info);
  }

  auto
  PixbufLoader::signal_area_updated () -> Glib::SignalProxy<void (int, int, int, int)>
  {
    return Glib::SignalProxy<void (int, int, int, int)> (
        this,
        &PixbufLoader_signal_area_updated_info);
  }

  auto
  PixbufLoader::signal_closed () -> Glib::SignalProxy<void ()>
  {
    return Glib::SignalProxy<void ()> (this, &PixbufLoader_signal_closed_info);
  }

  auto
  PixbufLoader::signal_size_prepared () -> Glib::SignalProxy<void (int, int)>
  {
    return Glib::SignalProxy<void (int, int)> (
        this,
        &PixbufLoader_signal_size_prepared_info);
  }

  auto
  Gdk::PixbufLoader::on_area_prepared () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->area_prepared)
      (*base->area_prepared) (gobj ());
  }

  auto
  Gdk::PixbufLoader::on_area_updated (int x, int y, int width, int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->area_updated)
      (*base->area_updated) (gobj (), x, y, width, height);
  }

  auto
  Gdk::PixbufLoader::on_closed () -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->closed)
      (*base->closed) (gobj ());
  }

  auto
  Gdk::PixbufLoader::on_size_prepared (int width, int height) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->size_prepared)
      (*base->size_prepared) (gobj (), width, height);
  }

} // namespace Gdk
