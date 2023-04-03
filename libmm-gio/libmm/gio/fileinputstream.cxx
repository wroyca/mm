// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileinputstream.hxx>
#include <libmm/gio/fileinputstream_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace Gio
{

  auto
  FileInputStream::query_info (const Glib::RefPtr<Cancellable>& cancellable,
                               const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_input_stream_query_info (gobj (),
                                        g_strdup (attributes.c_str ()),
                                        Glib::unwrap (cancellable),
                                        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileInputStream::query_info (const std::string& attributes) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_input_stream_query_info (gobj (),
                                        g_strdup (attributes.c_str ()),
                                        nullptr,
                                        &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);

    return retvalue;
  }

  auto
  FileInputStream::query_info_async (
      const SlotAsyncReady& slot,
      const Glib::RefPtr<Cancellable>& cancellable,
      const std::string& attributes,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_input_stream_query_info_async (gobj (),
                                          attributes.c_str (),
                                          io_priority,
                                          Glib::unwrap (cancellable),
                                          &SignalProxy_async_callback,
                                          slot_copy);
  }

  auto
  FileInputStream::query_info_async (const SlotAsyncReady& slot,
                                     const std::string& attributes,
                                     const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_input_stream_query_info_async (gobj (),
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
  wrap (GFileInputStream* object, const bool take_copy) -> RefPtr<Gio::FileInputStream>
  {
    return Glib::make_refptr_for_instance<Gio::FileInputStream> (
        dynamic_cast<Gio::FileInputStream*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  FileInputStream_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileInputStream_Class::class_init_function;

      register_derived_type (g_file_input_stream_get_type ());

      Seekable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileInputStream_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileInputStream_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileInputStream ((GFileInputStream*) object);
  }

  auto
  FileInputStream::gobj_copy () -> GFileInputStream*
  {
    reference ();
    return gobj ();
  }

  FileInputStream::FileInputStream (
      const Glib::ConstructParams& construct_params)
    : InputStream (construct_params)
  {
  }

  FileInputStream::FileInputStream (GFileInputStream* castitem)
    : InputStream ((GInputStream*) castitem)
  {
  }

  FileInputStream::FileInputStream (FileInputStream&& src) noexcept
    : InputStream (std::move (src)),
      Seekable (std::move (src))
  {
  }

  auto
  FileInputStream::operator= (FileInputStream&& src) noexcept -> FileInputStream&
  {
    InputStream::operator= (std::move (src));
    Seekable::operator= (std::move (src));
    return *this;
  }

  FileInputStream::~FileInputStream () noexcept = default;

  FileInputStream::CppClassType FileInputStream::fileinputstream_class_;

  auto
  FileInputStream::get_type () -> GType
  {
    return fileinputstream_class_.init ().get_type ();
  }

  auto
  FileInputStream::get_base_type () -> GType
  {
    return g_file_input_stream_get_type ();
  }

  auto
  FileInputStream::query_info_finish (const Glib::RefPtr<AsyncResult>& result) -> Glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        g_file_input_stream_query_info_finish (gobj (),
                                               Glib::unwrap (result),
                                               &gerror));
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace Gio
