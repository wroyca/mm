// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/filedialog.hxx>
#include <libmm/gtk/filedialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFileDialog* object, bool take_copy) -> glib::RefPtr<gtk::FileDialog>
  {
    return glib::make_refptr_for_instance<gtk::FileDialog> (
        dynamic_cast<gtk::FileDialog*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FileDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_file_dialog_get_type ();
    }

    return *this;
  }

  auto
  FileDialog_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileDialog ((GtkFileDialog*) object);
  }

  auto
  FileDialog::gobj_copy () -> GtkFileDialog*
  {
    reference ();
    return gobj ();
  }

  FileDialog::FileDialog (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  FileDialog::FileDialog (GtkFileDialog* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  FileDialog::FileDialog (FileDialog&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  FileDialog::operator= (FileDialog&& src) noexcept -> FileDialog&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (filedialog_class_.init ()))
  {
  }

  auto
  FileDialog::create () -> glib::RefPtr<FileDialog>
  {
    return glib::make_refptr_for_instance<FileDialog> (new FileDialog ());
  }

  auto
  FileDialog::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_dialog_get_title (const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_title (const glib::ustring& title) -> void
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
  FileDialog::get_filters () -> glib::RefPtr<gio::ListModel>
  {
    auto retvalue = glib::wrap (gtk_file_dialog_get_filters (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_filters () const -> glib::RefPtr<const gio::ListModel>
  {
    return const_cast<FileDialog*> (this)->get_filters ();
  }

  auto
  FileDialog::set_filters (const glib::RefPtr<gio::ListModel>& filters) -> void
  {
    gtk_file_dialog_set_filters (gobj (), glib::unwrap (filters));
  }

  auto
  FileDialog::get_default_filter () -> glib::RefPtr<FileFilter>
  {
    auto retvalue = glib::wrap (gtk_file_dialog_get_default_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_default_filter () const -> glib::RefPtr<const FileFilter>
  {
    return const_cast<FileDialog*> (this)->get_default_filter ();
  }

  auto
  FileDialog::set_default_filter (const glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_dialog_set_default_filter (
        gobj (),
        const_cast<GtkFileFilter*> (glib::unwrap (filter)));
  }

  auto
  FileDialog::get_initial_folder () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_file_dialog_get_initial_folder (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_initial_folder () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<FileDialog*> (this)->get_initial_folder ();
  }

  auto
  FileDialog::set_initial_folder (const glib::RefPtr<gio::File>& folder) -> void
  {
    gtk_file_dialog_set_initial_folder (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (folder)));
  }

  auto
  FileDialog::get_initial_name () const -> std::string
  {
    return glib::convert_const_gchar_ptr_to_stdstring (
        gtk_file_dialog_get_initial_name (
            const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_initial_name (const std::string& name) -> void
  {
    gtk_file_dialog_set_initial_name (gobj (), name.c_str ());
  }

  auto
  FileDialog::get_initial_file () -> glib::RefPtr<gio::File>
  {
    auto retvalue = glib::wrap (gtk_file_dialog_get_initial_file (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileDialog::get_initial_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<FileDialog*> (this)->get_initial_file ();
  }

  auto
  FileDialog::set_initial_file (const glib::RefPtr<gio::File>& file) -> void
  {
    gtk_file_dialog_set_initial_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)));
  }

  auto
  FileDialog::get_accept_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_dialog_get_accept_label (
            const_cast<GtkFileDialog*> (gobj ())));
  }

  auto
  FileDialog::set_accept_label (const glib::ustring& accept_label) -> void
  {
    gtk_file_dialog_set_accept_label (gobj (), accept_label.c_str ());
  }

  auto
  FileDialog::open (Window& parent,
                    const gio::SlotAsyncReady& slot,
                    const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_open (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open (const gio::SlotAsyncReady& slot,
                    const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_open (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_finish (const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gtk_file_dialog_open_finish (const_cast<GtkFileDialog*> (gobj ()),
                                     glib::unwrap (result),
                                     &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::select_folder (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_folder (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_folder (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_folder (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_folder_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_file_dialog_select_folder_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::save (Window& parent,
                    const gio::SlotAsyncReady& slot,
                    const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_save (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::save (const gio::SlotAsyncReady& slot,
                    const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_save (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::save_finish (const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<gio::File>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (
        gtk_file_dialog_save_finish (const_cast<GtkFileDialog*> (gobj ()),
                                     glib::unwrap (result),
                                     &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::open_multiple (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_open_multiple (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_multiple (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_open_multiple (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::open_multiple_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<gio::ListModel>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_file_dialog_open_multiple_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::select_multiple_folders (
      Window& parent,
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_multiple_folders (
        const_cast<GtkFileDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_multiple_folders (
      const gio::SlotAsyncReady& slot,
      const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_file_dialog_select_multiple_folders (
        const_cast<GtkFileDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  FileDialog::select_multiple_folders_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> glib::RefPtr<gio::ListModel>
  {
    GError* gerror = nullptr;
    auto retvalue = glib::wrap (gtk_file_dialog_select_multiple_folders_finish (
        const_cast<GtkFileDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror)));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileDialog::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  FileDialog::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  FileDialog::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  FileDialog::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileDialog::property_filters () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::ListModel>> (this, "filters");
  }

  auto
  FileDialog::property_filters () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (
        this,
        "filters");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FileFilter>>::value,
      "Type glib::RefPtr<FileFilter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileDialog::property_default_filter () -> glib::PropertyProxy<glib::RefPtr<FileFilter>>
  {
    return glib::PropertyProxy<glib::RefPtr<FileFilter>> (this,
                                                          "default-filter");
  }

  auto
  FileDialog::property_default_filter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>> (
        this,
        "default-filter");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileDialog::property_initial_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this, "initial-file");
  }

  auto
  FileDialog::property_initial_file () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (
        this,
        "initial-file");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::File>>::value,
      "Type glib::RefPtr<gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileDialog::property_initial_folder () -> glib::PropertyProxy<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::File>> (this,
                                                         "initial-folder");
  }

  auto
  FileDialog::property_initial_folder () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>> (
        this,
        "initial-folder");
  }

  auto
  FileDialog::property_initial_name () -> glib::PropertyProxy<std::string>
  {
    return glib::PropertyProxy<std::string> (this, "initial-name");
  }

  auto
  FileDialog::property_initial_name () const -> glib::PropertyProxy_ReadOnly<std::string>
  {
    return glib::PropertyProxy_ReadOnly<std::string> (this, "initial-name");
  }

  auto
  FileDialog::property_accept_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "accept-label");
  }

  auto
  FileDialog::property_accept_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "accept-label");
  }

} // namespace gtk
