// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileiostream.hxx>
#include <libmm-gio/fileiostream_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{

  auto
  FileIOStream::query_info (const Glib::RefPtr<Cancellable>& cancellable,
                            const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_file_io_stream_query_info (gobj (),
                                                 g_strdup (attributes.c_str ()),
                                                 Glib::unwrap (cancellable),
                                                 &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileIOStream::query_info (const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_file_io_stream_query_info (gobj (),
                                                 g_strdup (attributes.c_str ()),
                                                 nullptr,
                                                 &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileIOStream::query_info_async (const SlotAsyncReady& slot,
                                  const Glib::RefPtr<Cancellable>& cancellable,
                                  const std::string& attributes,
                                  const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_io_stream_query_info_async (gobj (),
                                       attributes.c_str (),
                                       io_priority,
                                       Glib::unwrap (cancellable),
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

  auto
  FileIOStream::query_info_async (const SlotAsyncReady& slot,
                                  const std::string& attributes,
                                  const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_io_stream_query_info_async (gobj (),
                                       attributes.c_str (),
                                       io_priority,
                                       nullptr,
                                       &SignalProxy_async_callback,
                                       slot_copy);
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GFileIOStream* object, const bool take_copy) -> RefPtr<Gio::FileIOStream>
  {
    return Glib::make_refptr_for_instance<Gio::FileIOStream> (
        dynamic_cast<Gio::FileIOStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileIOStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileIOStream_Class::class_init_function;

      register_derived_type (g_file_io_stream_get_type ());

      Seekable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileIOStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileIOStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileIOStream ((GFileIOStream*) object);
  }

  auto
  FileIOStream::gobj_copy () -> GFileIOStream*
  {
    reference ();
    return gobj ();
  }

  FileIOStream::FileIOStream (const Glib::ConstructParams& construct_params)
    : IOStream (construct_params)
  {
  }

  FileIOStream::FileIOStream (GFileIOStream* castitem)
    : IOStream ((GIOStream*) castitem)
  {
  }

  FileIOStream::FileIOStream (FileIOStream&& src) noexcept
    : IOStream (std::move (src)),
      Seekable (std::move (src))
  {
  }

  auto
  FileIOStream::operator= (FileIOStream&& src) noexcept -> FileIOStream&
  {
    IOStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    return *this;
  }

  FileIOStream::~FileIOStream () noexcept = default;

  FileIOStream::CppClassType FileIOStream::fileiostream_class_;

  auto
  FileIOStream::get_type () -> GType
  {
    return fileiostream_class_.init ().get_type ();
  }

  auto
  FileIOStream::get_base_type () -> GType
  {
    return g_file_io_stream_get_type ();
  }

  auto
  FileIOStream::query_info_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        Glib::wrap (g_file_io_stream_query_info_finish (gobj (),
                                                        Glib::unwrap (result),
                                                        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileIOStream::get_etag () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_file_io_stream_get_etag (const_cast<GFileIOStream*> (gobj ())));
  }

} // namespace Gio
