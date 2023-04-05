// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/fileenumerator.hxx>
#include <libmm/gio/fileenumerator_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/file.hxx>
#include <libmm/gio/slot_async.hxx>
#include <libmm/glib/error.hxx>
#include <libmm/glib/exceptionhandler.hxx>

namespace gio
{

  auto
  FileEnumerator::next_files_async (
      const SlotAsyncReady& slot,
      const glib::RefPtr<Cancellable>& cancellable,
      const int num_files,
      const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_enumerator_next_files_async (gobj (),
                                        num_files,
                                        io_priority,
                                        glib::unwrap (cancellable),
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  FileEnumerator::next_files_async (const SlotAsyncReady& slot,
                                    const int num_files,
                                    const int io_priority) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_enumerator_next_files_async (gobj (),
                                        num_files,
                                        io_priority,
                                        nullptr,
                                        &SignalProxy_async_callback,
                                        slot_copy);
  }

  auto
  FileEnumerator::close_async (const int io_priority,
                               const glib::RefPtr<Cancellable>& cancellable,
                               const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_enumerator_close_async (gobj (),
                                   io_priority,
                                   glib::unwrap (cancellable),
                                   &SignalProxy_async_callback,
                                   slot_copy);
  }

  auto
  FileEnumerator::close_async (const int io_priority,
                               const SlotAsyncReady& slot) -> void
  {
    const auto slot_copy = new SlotAsyncReady (slot);

    g_file_enumerator_close_async (gobj (),
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
  wrap (GFileEnumerator* object, const bool take_copy) -> RefPtr<gio::FileEnumerator>
  {
    return glib::make_refptr_for_instance<gio::FileEnumerator> (
        dynamic_cast<gio::FileEnumerator*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  FileEnumerator_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileEnumerator_Class::class_init_function;

      register_derived_type (g_file_enumerator_get_type ());
    }

    return *this;
  }

  auto
  FileEnumerator_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileEnumerator_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileEnumerator ((GFileEnumerator*) object);
  }

  auto
  FileEnumerator::gobj_copy () -> GFileEnumerator*
  {
    reference ();
    return gobj ();
  }

  FileEnumerator::FileEnumerator (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  FileEnumerator::FileEnumerator (GFileEnumerator* castitem)
    : Object ((GObject*) castitem)
  {
  }

  FileEnumerator::FileEnumerator (FileEnumerator&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  FileEnumerator::operator= (FileEnumerator&& src) noexcept -> FileEnumerator&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  FileEnumerator::~FileEnumerator () noexcept = default;

  FileEnumerator::CppClassType FileEnumerator::fileenumerator_class_;

  auto
  FileEnumerator::get_type () -> GType
  {
    return fileenumerator_class_.init ().get_type ();
  }

  auto
  FileEnumerator::get_base_type () -> GType
  {
    return g_file_enumerator_get_type ();
  }

  auto
  FileEnumerator::next_file (const glib::RefPtr<Cancellable>& cancellable) -> glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_file_enumerator_next_file (gobj (),
                                                 glib::unwrap (cancellable),
                                                 &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::next_file () -> glib::RefPtr<FileInfo>
  {
    GError* gerror = nullptr;
    auto retvalue =
        glib::wrap (g_file_enumerator_next_file (gobj (), nullptr, &gerror));
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::close (const glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_file_enumerator_close (gobj (), glib::unwrap (cancellable), &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::close () -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_file_enumerator_close (gobj (), nullptr, &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::next_files_finish (const glib::RefPtr<AsyncResult>& result) -> std::vector<glib::RefPtr<FileInfo>>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::ListHandler<glib::RefPtr<FileInfo>>::list_to_vector (
        g_file_enumerator_next_files_finish (gobj (),
                                             glib::unwrap (result),
                                             &gerror),
        glib::OWNERSHIP_DEEP);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::close_finish (const glib::RefPtr<AsyncResult>& result) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_file_enumerator_close_finish (gobj (),
                                                          glib::unwrap (result),
                                                          &gerror);
    if (gerror)
      glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileEnumerator::is_closed () const -> bool
  {
    return g_file_enumerator_is_closed (const_cast<GFileEnumerator*> (gobj ()));
  }

  auto
  FileEnumerator::has_pending () const -> bool
  {
    return g_file_enumerator_has_pending (
        const_cast<GFileEnumerator*> (gobj ()));
  }

  auto
  FileEnumerator::set_pending (const bool pending) -> void
  {
    g_file_enumerator_set_pending (gobj (), pending);
  }

  auto
  FileEnumerator::get_container () -> glib::RefPtr<File>
  {
    auto retvalue = glib::wrap (g_file_enumerator_get_container (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileEnumerator::get_container () const -> glib::RefPtr<const File>
  {
    auto retvalue = glib::wrap (g_file_enumerator_get_container (
        const_cast<GFileEnumerator*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileEnumerator::get_child (const glib::RefPtr<FileInfo>& info) -> glib::RefPtr<File>
  {
    return glib::wrap (
        g_file_enumerator_get_child (gobj (), glib::unwrap (info)));
  }

  auto
  FileEnumerator::get_child (const glib::RefPtr<FileInfo>& info) const -> glib::RefPtr<const File>
  {
    return glib::wrap (
        g_file_enumerator_get_child (const_cast<GFileEnumerator*> (gobj ()),
                                     glib::unwrap (info)));
  }

} // namespace gio
