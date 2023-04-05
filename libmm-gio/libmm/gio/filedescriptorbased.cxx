// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _WIN32

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gio/filedescriptorbased.hxx>
  #include <libmm/gio/filedescriptorbased_p.hxx>

  #include <gio/gfiledescriptorbased.h>
  #include <gio/gio.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GFileDescriptorBased* object, bool take_copy) -> glib::RefPtr<gio::FileDescriptorBased>
  {
    return glib::make_refptr_for_instance<gio::FileDescriptorBased> (
        dynamic_cast<gio::FileDescriptorBased*> (
            glib::wrap_auto_interface<gio::FileDescriptorBased> (
                (GObject*) (object),
                take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FileDescriptorBased_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileDescriptorBased_Class::iface_init_function;

      gtype_ = g_file_descriptor_based_get_type ();
    }

    return *this;
  }

  void
  FileDescriptorBased_Class::iface_init_function (void* g_iface, void*)
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_fd = &get_fd_vfunc_callback;
  }

  auto
  FileDescriptorBased_Class::get_fd_vfunc_callback (GFileDescriptorBased* self) -> int
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
          return obj->get_fd_vfunc ();
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

    if (base && base->get_fd)
      return (*base->get_fd) (self);

    using RType = int;
    return RType ();
  }

  auto
  FileDescriptorBased_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileDescriptorBased ((GFileDescriptorBased*) (object));
  }

  FileDescriptorBased::FileDescriptorBased ()
    : glib::Interface (filedescriptorbased_class_.init ())
  {
  }

  FileDescriptorBased::FileDescriptorBased (GFileDescriptorBased* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  FileDescriptorBased::FileDescriptorBased (
      const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  FileDescriptorBased::FileDescriptorBased (FileDescriptorBased&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  FileDescriptorBased::operator= (FileDescriptorBased&& src) noexcept -> FileDescriptorBased&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  FileDescriptorBased::~FileDescriptorBased () noexcept {}

  void
  FileDescriptorBased::add_interface (GType gtype_implementer)
  {
    filedescriptorbased_class_.init ().add_interface (gtype_implementer);
  }

  FileDescriptorBased::CppClassType
      FileDescriptorBased::filedescriptorbased_class_;

  auto
  FileDescriptorBased::get_type () -> GType
  {
    return filedescriptorbased_class_.init ().get_type ();
  }

  auto
  FileDescriptorBased::get_base_type () -> GType
  {
    return g_file_descriptor_based_get_type ();
  }

  auto
  FileDescriptorBased::get_fd () const -> int
  {
    return g_file_descriptor_based_get_fd (
        const_cast<GFileDescriptorBased*> (gobj ()));
  }

  auto
  gio::FileDescriptorBased::get_fd_vfunc () const -> int
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_fd)
    {
      int retval (
          (*base->get_fd) (const_cast<GFileDescriptorBased*> (gobj ())));
      return retval;
    }

    using RType = int;
    return RType ();
  }

} // namespace gio

#endif
