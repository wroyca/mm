// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _WIN32

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gio/unixoutputstream.hxx>
  #include <libmm/gio/unixoutputstream_p.hxx>

  #include <gio/gio.h>
  #include <gio/gunixoutputstream.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GUnixOutputStream* object, bool take_copy) -> glib::RefPtr<gio::UnixOutputStream>
  {
    return glib::make_refptr_for_instance<gio::UnixOutputStream> (
        dynamic_cast<gio::UnixOutputStream*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  UnixOutputStream_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &UnixOutputStream_Class::class_init_function;

      register_derived_type (g_unix_output_stream_get_type ());

      PollableOutputStream::add_interface (get_type ());
      FileDescriptorBased::add_interface (get_type ());
    }

    return *this;
  }

  void
  UnixOutputStream_Class::class_init_function (void* g_class, void* class_data)
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  UnixOutputStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new UnixOutputStream ((GUnixOutputStream*) object);
  }

  auto
  UnixOutputStream::gobj_copy () -> GUnixOutputStream*
  {
    reference ();
    return gobj ();
  }

  UnixOutputStream::UnixOutputStream (
      const glib::ConstructParams& construct_params)
    : gio::OutputStream (construct_params)
  {
  }

  UnixOutputStream::UnixOutputStream (GUnixOutputStream* castitem)
    : gio::OutputStream ((GOutputStream*) (castitem))
  {
  }

  UnixOutputStream::UnixOutputStream (UnixOutputStream&& src) noexcept
    : gio::OutputStream (std::move (src)),
      PollableOutputStream (std::move (src)),
      FileDescriptorBased (std::move (src))
  {
  }

  auto
  UnixOutputStream::operator= (UnixOutputStream&& src) noexcept -> UnixOutputStream&
  {
    gio::OutputStream::operator= (std::move (src));
    PollableOutputStream::operator= (std::move (src));
    FileDescriptorBased::operator= (std::move (src));
    return *this;
  }

  UnixOutputStream::~UnixOutputStream () noexcept {}

  UnixOutputStream::CppClassType UnixOutputStream::unixoutputstream_class_;

  auto
  UnixOutputStream::get_type () -> GType
  {
    return unixoutputstream_class_.init ().get_type ();
  }

  auto
  UnixOutputStream::get_base_type () -> GType
  {
    return g_unix_output_stream_get_type ();
  }

  UnixOutputStream::UnixOutputStream (int fd, bool close_fd)
    : glib::ObjectBase (nullptr),
      gio::OutputStream (glib::ConstructParams (unixoutputstream_class_.init (),
                                                "fd",
                                                fd,
                                                "close_fd",
                                                static_cast<int> (close_fd),
                                                nullptr))
  {
  }

  auto
  UnixOutputStream::create (int fd, bool close_fd) -> glib::RefPtr<UnixOutputStream>
  {
    return glib::make_refptr_for_instance<UnixOutputStream> (
        new UnixOutputStream (fd, close_fd));
  }

  void
  UnixOutputStream::set_close_fd (bool close_fd)
  {
    g_unix_output_stream_set_close_fd (gobj (), static_cast<int> (close_fd));
  }

  auto
  UnixOutputStream::get_close_fd () const -> bool
  {
    return g_unix_output_stream_get_close_fd (
        const_cast<GUnixOutputStream*> (gobj ()));
  }

  auto
  UnixOutputStream::get_fd () const -> int
  {
    return g_unix_output_stream_get_fd (
        const_cast<GUnixOutputStream*> (gobj ()));
  }

  auto
  UnixOutputStream::property_fd () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "fd");
  }

  auto
  UnixOutputStream::property_close_fd () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "close-fd");
  }

  auto
  UnixOutputStream::property_close_fd () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "close-fd");
  }

} // namespace gio

#endif
