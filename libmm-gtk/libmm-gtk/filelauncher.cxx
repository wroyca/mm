// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filelauncher.hxx>
#include <libmm-gtk/filelauncher_p.hxx>

#include <libmm-gio/slot_async.hxx>
#include <libmm-gtk/window.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFileLauncher* object, bool take_copy) -> Glib::RefPtr<Gtk::FileLauncher>
  {
    return Glib::make_refptr_for_instance<Gtk::FileLauncher> (
        dynamic_cast<Gtk::FileLauncher*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileLauncher_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_file_launcher_get_type ();
    }

    return *this;
  }

  auto
  FileLauncher_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileLauncher ((GtkFileLauncher*) object);
  }

  auto
  FileLauncher::gobj_copy () -> GtkFileLauncher*
  {
    reference ();
    return gobj ();
  }

  FileLauncher::FileLauncher (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FileLauncher::FileLauncher (GtkFileLauncher* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FileLauncher::FileLauncher (FileLauncher&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  FileLauncher::operator= (FileLauncher&& src) noexcept -> FileLauncher&
  {
    Glib::Object::operator= (std::move (src));
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

  FileLauncher::FileLauncher (const Glib::RefPtr<Gio::File>& file)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (
          filelauncher_class_.init (),
          "file",
          const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
          nullptr))
  {
  }

  auto
  FileLauncher::create (const Glib::RefPtr<Gio::File>& file) -> Glib::RefPtr<FileLauncher>
  {
    return Glib::make_refptr_for_instance<FileLauncher> (
        new FileLauncher (file));
  }

  auto
  FileLauncher::get_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_file_launcher_get_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileLauncher::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<FileLauncher*> (this)->get_file ();
  }

  auto
  FileLauncher::set_file (const Glib::RefPtr<Gio::File>& file) -> void
  {
    gtk_file_launcher_set_file (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
  }

  auto
  FileLauncher::launch (Window& parent,
                        const Gio::SlotAsyncReady& slot,
                        const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_launcher_launch (
        const_cast<GtkFileLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::launch (const Gio::SlotAsyncReady& slot,
                        const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_launcher_launch (
        const_cast<GtkFileLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::launch_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_launcher_launch_finish (
        const_cast<GtkFileLauncher*> (gobj ()),
        Glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileLauncher::open_containing_folder (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_launcher_open_containing_folder (
        const_cast<GtkFileLauncher*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::open_containing_folder (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_launcher_open_containing_folder (
        const_cast<GtkFileLauncher*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileLauncher::open_containing_folder_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_launcher_open_containing_folder_finish (
        const_cast<GtkFileLauncher*> (gobj ()),
        Glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileLauncher::property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this, "file");
  }

  auto
  FileLauncher::property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (this, "file");
  }

} // namespace Gtk
