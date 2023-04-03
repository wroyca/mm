// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filedialog.hxx>
#include <libmm/gtk/filedialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFileDialog* object, bool take_copy) -> Glib::RefPtr<Gtk::FileDialog>
  {
    return Glib::make_refptr_for_instance<Gtk::FileDialog> (
        dynamic_cast<Gtk::FileDialog*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_file_dialog_get_type ();
    }

    return *this;
  }

  auto
  FileDialog_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileDialog ((GtkFileDialog*) object);
  }

  auto
  FileDialog::gobj_copy () -> GtkFileDialog*
  {
    reference ();
    return gobj ();
  }

  FileDialog::FileDialog (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  FileDialog::FileDialog (GtkFileDialog* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  FileDialog::FileDialog (FileDialog&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  FileDialog::operator= (FileDialog&& src) noexcept -> FileDialog&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  FileDialog::~FileDialog () noexcept {}

  FileDialog::CppClassType FileDialog::filedialog_class_;

  auto
  FileDialog::get_type () -> GType
  {
    return filedialog_class_.init ().get_type ();
  }

  auto
  FileDialog::get_base_type () -> GType
  {
    return gtk_file_dialog_get_type ();
  }

  FileDialog::FileDialog ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (filedialog_class_.init ()))
  {
  }

  auto
  FileDialog::create () -> Glib::RefPtr<FileDialog>
  {
    return Glib::make_refptr_for_instance<FileDialog> (new FileDialog ());
  }

  auto
  FileDialog::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_dialog_get_title (const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_title (const Glib::ustring& title) -> void
  {
    gtk_file_dialog_set_title (gobj (), title.c_str ());
  }

  auto
  FileDialog::get_modal () const -> bool
  {
    return gtk_file_dialog_get_modal (const_cast<GtkFileDialog*> (gobj ()));
  }

  auto
  FileDialog::set_modal (bool modal) -> void
  {
    gtk_file_dialog_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  FileDialog::get_filters () -> Glib::RefPtr<Gio::ListModel>
  {
    auto retvalue = Glib::wrap (gtk_file_dialog_get_filters (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_filters () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return const_cast<FileDialog*> (this)->get_filters ();
  }

  auto
  FileDialog::set_filters (const Glib::RefPtr<Gio::ListModel>& filters) -> void
  {
    gtk_file_dialog_set_filters (gobj (), Glib::unwrap (filters));
  }

  auto
  FileDialog::get_default_filter () -> Glib::RefPtr<FileFilter>
  {
    auto retvalue = Glib::wrap (gtk_file_dialog_get_default_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_default_filter () const -> Glib::RefPtr<const FileFilter>
  {
    return const_cast<FileDialog*> (this)->get_default_filter ();
  }

  auto
  FileDialog::set_default_filter (const Glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_dialog_set_default_filter (
        gobj (),
        const_cast<GtkFileFilter*> (Glib::unwrap (filter)));
  }

  auto
  FileDialog::get_initial_folder () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_file_dialog_get_initial_folder (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_initial_folder () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<FileDialog*> (this)->get_initial_folder ();
  }

  auto
  FileDialog::set_initial_folder (const Glib::RefPtr<Gio::File>& folder) -> void
  {
    gtk_file_dialog_set_initial_folder (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (folder)));
  }

  auto
  FileDialog::get_initial_name () const -> std::string
  {
    return Glib::convert_const_gchar_ptr_to_stdstring (
        gtk_file_dialog_get_initial_name (
            const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_initial_name (const std::string& name) -> void
  {
    gtk_file_dialog_set_initial_name (gobj (), name.c_str ());
  }

  auto
  FileDialog::get_initial_file () -> Glib::RefPtr<Gio::File>
  {
    auto retvalue = Glib::wrap (gtk_file_dialog_get_initial_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_initial_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<FileDialog*> (this)->get_initial_file ();
  }

  auto
  FileDialog::set_initial_file (const Glib::RefPtr<Gio::File>& file) -> void
  {
    gtk_file_dialog_set_initial_file (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)));
  }

  auto
  FileDialog::get_accept_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_dialog_get_accept_label (
            const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_accept_label (const Glib::ustring& accept_label) -> void
  {
    gtk_file_dialog_set_accept_label (gobj (), accept_label.c_str ());
  }

  auto
  FileDialog::open (Window& parent,
                    const Gio::SlotAsyncReady& slot,
                    const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_open (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open (const Gio::SlotAsyncReady& slot,
                    const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_open (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gtk_file_dialog_open_finish (const_cast<GtkFileDialog*> (gobj ()),
                                     Glib::unwrap (result),
                                     &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::select_folder (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_folder (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_folder (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_folder (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_folder_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_file_dialog_select_folder_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::save (Window& parent,
                    const Gio::SlotAsyncReady& slot,
                    const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_save (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::save (const Gio::SlotAsyncReady& slot,
                    const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_save (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::save_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (
        gtk_file_dialog_save_finish (const_cast<GtkFileDialog*> (gobj ()),
                                     Glib::unwrap (result),
                                     &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::open_multiple (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_open_multiple (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_multiple (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_open_multiple (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_multiple_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Gio::ListModel>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_file_dialog_open_multiple_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::select_multiple_folders (
      Window& parent,
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_multiple_folders (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_multiple_folders (
      const Gio::SlotAsyncReady& slot,
      const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_multiple_folders (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_multiple_folders_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> Glib::RefPtr<Gio::ListModel>
  {
    GError* gerror = nullptr;
    auto retvalue = Glib::wrap (gtk_file_dialog_select_multiple_folders_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  FileDialog::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  FileDialog::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  FileDialog::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileDialog::property_filters () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>> (this, "filters");
  }

  auto
  FileDialog::property_filters () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>> (
        this,
        "filters");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<FileFilter>>::value,
      "Type Glib::RefPtr<FileFilter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileDialog::property_default_filter () -> Glib::PropertyProxy<Glib::RefPtr<FileFilter>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<FileFilter>> (this,
                                                          "default-filter");
  }

  auto
  FileDialog::property_default_filter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileFilter>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileFilter>> (
        this,
        "default-filter");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileDialog::property_initial_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this, "initial-file");
  }

  auto
  FileDialog::property_initial_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (
        this,
        "initial-file");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileDialog::property_initial_folder () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::File>> (this,
                                                         "initial-folder");
  }

  auto
  FileDialog::property_initial_folder () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (
        this,
        "initial-folder");
  }

  auto
  FileDialog::property_initial_name () -> Glib::PropertyProxy<std::string>
  {
    return Glib::PropertyProxy<std::string> (this, "initial-name");
  }

  auto
  FileDialog::property_initial_name () const -> Glib::PropertyProxy_ReadOnly<std::string>
  {
    return Glib::PropertyProxy_ReadOnly<std::string> (this, "initial-name");
  }

  auto
  FileDialog::property_accept_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "accept-label");
  }

  auto
  FileDialog::property_accept_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "accept-label");
  }

} // namespace Gtk
