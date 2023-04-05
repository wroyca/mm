// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filelauncher.hxx>
#include <libmm/gtk/filelauncher_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFileLauncher* object, bool take_copy) -> glib::RefPtr<gtk::FileLauncher>
  {
    return glib::make_refptr_for_instance<gtk::FileLauncher> (
        dynamic_cast<gtk::FileLauncher*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FileLauncher_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_file_launcher_get_type ();
    }

    return *this;
  }

  auto
  FileLauncher_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileLauncher ((GtkFileLauncher*) object);
  }

  auto
  FileLauncher::gobj_copy () -> GtkFileLauncher*
  {
    reference ();
    return gobj ();
  }

  FileLauncher::FileLauncher (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FileLauncher::FileLauncher (GtkFileLauncher* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FileLauncher::FileLauncher (FileLauncher&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  FileLauncher::operator= (FileLauncher&& src) noexcept -> FileLauncher&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  FileLauncher::~FileLauncher () noexcept {}

  FileLauncher::CppClassType FileLauncher::filelauncher_class_;

  auto
  FileLauncher::get_type () -> GType
  {
    return filelauncher_class_.init ().get_type ();
  }

  auto
  FileLauncher::get_base_type () -> GType
  {
    return gtk_file_launcher_get_type ();
  }

  FileLauncher::FileLauncher (const glib::RefPtr<gio::File>& file)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          filelauncher_class_.init (),
          "file",
          const_cast<GFile*> (glib::unwrap<gio::File> (file)),
          nullptr))
  {
  }

  auto
  FileLauncher::create (const glib::RefPtr<gio::File>& file) -> glib::RefPtr<FileLauncher>
  {
    return glib::make_refptr_for_instance<FileLauncher> (
        new FileLauncher (file));
  }

  auto
  FileLauncher::get_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_file_launcher_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileLauncher::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<FileLauncher*> (this)->get_file ();
  }

  auto
  FileLauncher::set_file (const glib::RefPtr<gio::File>& file) -> void
  {
    gtk_file_launcher_set_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  FileLauncher::launch (Window& parent,
                        const gio::SlotAsyncReady& slot,
                        const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_launcher_launch (
        const_cast<GtkFileLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::launch (const gio::SlotAsyncReady& slot,
                        const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_launcher_launch (
        const_cast<GtkFileLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::launch_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_launcher_launch_finish (
        const_cast<GtkFileLauncher*> (gobj ()),
        glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileLauncher::open_containing_folder (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_launcher_open_containing_folder (
        const_cast<GtkFileLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::open_containing_folder (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_launcher_open_containing_folder (
        const_cast<GtkFileLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::open_containing_folder_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_launcher_open_containing_folder_finish (
        const_cast<GtkFileLauncher*> (gobj ()),
        glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileLauncher::property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "file");
  }

  auto
  FileLauncher::property_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (this, "file");
  }

} // namespace gtk
