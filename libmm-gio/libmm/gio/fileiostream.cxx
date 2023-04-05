// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileiostream.hxx>
#include <libmm/gio/fileiostream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  auto
  FileIOStream::query_info (const glib::RefPtr<Cancellable>& cancellable,
                            const std::string& attributes) -> glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_file_io_stream_query_info (gobj (),
                                                 g_strdup (attributes.c_str ()),
                                                 glib::unwrap (cancellable),
                                                 &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileIOStream::query_info (const std::string& attributes) -> glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_file_io_stream_query_info (gobj (),
                                                 g_strdup (attributes.c_str ()),
                                                 nullptr,
                                                 &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileIOStream::query_info_async (const SlotAsyncReady& slot,
                                  const glib::RefPtr<Cancellable>& cancellable,
                                  const std::string& attributes,
                                  const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_io_stream_query_info_async (gobj (),
                                       attributes.c_str (),
                                       io_priority,
                                       glib::unwrap (cancellable),
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

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GFileIOStream* object, const bool take_copy) -> RefPtr<gio::FileIOStream>
  {
    return glib::make_refptr_for_instance<gio::FileIOStream> (
        dynamic_cast<gio::FileIOStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  FileIOStream_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileIOStream ((GFileIOStream*) object);
  }

  auto
  FileIOStream::gobj_copy () -> GFileIOStream*
  {
    reference ();
    return gobj ();
  }

  FileIOStream::FileIOStream (const glib::ConstructParams& construct_params)
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
  FileIOStream::query_info_finish (const glib::RefPtr<AsyncResult>& result) -> glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_file_io_stream_query_info_finish (gobj (),
                                                        glib::unwrap (result),
                                                        &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileIOStream::get_etag () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        g_file_io_stream_get_etag (const_cast<GFileIOStream*> (gobj ())));
  }

} // namespace gio
