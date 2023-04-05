// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _WIN32

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gio/unixinputstream.hxx>
  #include <libmm/gio/unixinputstream_p.hxx>

  #include <gio/gio.h>
  #include <gio/gunixinputstream.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GUnixInputStream* object, bool take_copy) -> glib::RefPtr<gio::UnixInputStream>
  {
    return glib::make_refptr_for_instance<gio::UnixInputStream> (
        dynamic_cast<gio::UnixInputStream*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixInputStream_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixInputStream_Class::class_init_function;

      register_derived_type (g_unix_input_stream_get_type ());

      PollableInputStream::add_interface (get_type ());
      FileDescriptorBased::add_interface (get_type ());
    }

    return *this;
  }

  void
  UnixInputStream_Class::class_init_function (void* g_class, void* class_data)
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixInputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixInputStream ((GUnixInputStream*) object);
  }

  auto
  UnixInputStream::gobj_copy () -> GUnixInputStream*
  {
    reference ();
    return gobj ();
  }

  UnixInputStream::UnixInputStream (
      const glib::ConstructParams& construct_params)
    : gio::InputStream (construct_params)
  {
  }

  UnixInputStream::UnixInputStream (GUnixInputStream* castitem)
    : gio::InputStream ((GInputStream*) (castitem))
  {
  }

  UnixInputStream::UnixInputStream (UnixInputStream&& src) noexcept
    : gio::InputStream (std::move (src)),
      PollableInputStream (std::move (src)),
      FileDescriptorBased (std::move (src))
  {
  }

  auto
  UnixInputStream::operator= (UnixInputStream&& src) noexcept -> UnixInputStream&
  {
    gio::InputStream::operator= (std::move (src));
    PollableInputStream::operator= (std::move (src));
    FileDescriptorBased::operator= (std::move (src));
    return *this;
  }

  UnixInputStream::~UnixInputStream () noexcept {}

  UnixInputStream::CppClassType UnixInputStream::unixinputstream_class_;

  auto
  UnixInputStream::get_type () -> GType
  {
    return unixinputstream_class_.init ().get_type ();
  }

  auto
  UnixInputStream::get_base_type () -> GType
  {
    return g_unix_input_stream_get_type ();
  }

  UnixInputStream::UnixInputStream (int fd, bool close_fd)
    : glib::ObjectBase (nullptr),
      gio::InputStream (glib::ConstructParams (unixinputstream_class_.init (),
                                               "fd",
                                               fd,
                                               "close_fd",
                                               static_cast<int> (close_fd),
                                               nullptr))
  {
  }

  auto
  UnixInputStream::create (int fd, bool close_fd) -> glib::RefPtr<UnixInputStream>
  {
    return glib::make_refptr_for_instance<UnixInputStream> (
        new UnixInputStream (fd, close_fd));
  }

  void
  UnixInputStream::set_close_fd (bool close_fd)
  {
    g_unix_input_stream_set_close_fd (gobj (), static_cast<int> (close_fd));
  }

  auto
  UnixInputStream::get_close_fd () const -> bool
  {
    return g_unix_input_stream_get_close_fd (
        const_cast<GUnixInputStream*> (gobj ()));
  }

  auto
  UnixInputStream::get_fd () const -> int
  {
    return g_unix_input_stream_get_fd (const_cast<GUnixInputStream*> (gobj ()));
  }

  auto
  UnixInputStream::property_fd () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "fd");
  }

  auto
  UnixInputStream::property_close_fd () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "close-fd");
  }

  auto
  UnixInputStream::property_close_fd () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "close-fd");
  }

} // namespace gio

#endif
