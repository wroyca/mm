// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/fileoutputstream.hxx>
#include <libmm-gio/fileoutputstream_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/slot_async.hxx>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>
#include <libmm-glib/mm-glib.hxx>

namespace Gio
{

  auto
  FileOutputStream::query_info (const Glib::RefPtr<Cancellable>& cancellable,
                                const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_output_stream_query_info (gobj (),
                                         g_strdup (attributes.c_str ()),
                                         Glib::unwrap (cancellable),
                                         &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileOutputStream::query_info (const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_output_stream_query_info (gobj (),
                                         g_strdup (attributes.c_str ()),
                                         nullptr,
                                         &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileOutputStream::query_info_async (
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      const std::string& attributes,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_output_stream_query_info_async (gobj (),
                                           attributes.c_str (),
                                           io_priority,
                                           Glib::unwrap (cancellable),
                                           &SignalProxy_async_callback,
                                           slot_copy);
  }

  auto
  FileOutputStream::query_info_async (const SlotAsyncReady& slot,
                                      const std::string& attributes,
                                      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_output_stream_query_info_async (gobj (),
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
  wrap (GFileOutputStream* object, const bool take_copy) -> RefPtr<Gio::FileOutputStream>
  {
    return Glib::make_refptr_for_instance<Gio::FileOutputStream> (
        dynamic_cast<Gio::FileOutputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileOutputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileOutputStream_Class::class_init_function;

      register_derived_type (g_file_output_stream_get_type ());

      Seekable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileOutputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileOutputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileOutputStream ((GFileOutputStream*) object);
  }

  auto
  FileOutputStream::gobj_copy () -> GFileOutputStream*
  {
    reference ();
    return gobj ();
  }

  FileOutputStream::FileOutputStream (
      const Glib::ConstructParams& construct_params)
    : OutputStream (construct_params)
  {
  }

  FileOutputStream::FileOutputStream (GFileOutputStream* castitem)
    : OutputStream ((GOutputStream*) castitem)
  {
  }

  FileOutputStream::FileOutputStream (FileOutputStream&& src) noexcept
    : OutputStream (std::move (src)),
      Seekable (std::move (src))
  {
  }

  auto
  FileOutputStream::operator= (FileOutputStream&& src) noexcept -> FileOutputStream&
  {
    OutputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    return *this;
  }

  FileOutputStream::~FileOutputStream () noexcept = default;

  FileOutputStream::CppClassType FileOutputStream::fileoutputstream_class_;

  auto
  FileOutputStream::get_type () -> GType
  {
    return fileoutputstream_class_.init ().get_type ();
  }

  auto
  FileOutputStream::get_base_type () -> GType
  {
    return g_file_output_stream_get_type ();
  }

  auto
  FileOutputStream::query_info_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_output_stream_query_info_finish (gobj (),
                                                Glib::unwrap (result),
                                                &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileOutputStream::get_etag () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        g_file_output_stream_get_etag (
            const_cast<GFileOutputStream*> (gobj ())));
  }

} // namespace Gio
