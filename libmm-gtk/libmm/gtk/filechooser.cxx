// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/filechooser.hxx>
  #include <libmm/gtk/filechooser_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/glib/vectorutils.hxx>

using Action = gtk::FileChooser::Action;

namespace gtk
{
  auto
  FileChooser::add_choice (const glib::ustring& id, const glib::ustring& label) -> void
  {
    gtk_file_chooser_add_choice (gobj (),
                                 id.c_str (),
                                 label.c_str (),
                                 nullptr,
                                 nullptr);
  }

} // namespace gtk

namespace
{
}

gtk::FileChooserError::FileChooserError (gtk::FileChooserError::Code error_code,
                                         const glib::ustring& error_message)
  : glib::Error (GTK_FILE_CHOOSER_ERROR, error_code, error_message)
{
}

gtk::FileChooserError::FileChooserError (GError* gobject)
  : glib::Error (gobject)
{
}

auto
gtk::FileChooserError::code () const -> gtk::FileChooserError::Code
{
  return static_cast<Code> (glib::Error::code ());
}

auto
gtk::FileChooserError::throw_func (GError* gobject) -> void
{
  throw gtk::FileChooserError (gobject);
}

auto
glib::Value<gtk::FileChooserError::Code>::value_type () -> GType
{
  return gtk_file_chooser_error_get_type ();
}

auto
glib::Value<gtk::FileChooser::Action>::value_type () -> GType
{
  return gtk_file_chooser_action_get_type ();
}

namespace glib
{

  auto
  wrap (GtkFileChooser* object, bool take_copy) -> glib::RefPtr<gtk::FileChooser>
  {
    return glib::make_refptr_for_instance<gtk::FileChooser> (
        dynamic_cast<gtk::FileChooser*> (
            glib::wrap_auto_interface<gtk::FileChooser> ((GObject*) (object),
                                                         take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FileChooser_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileChooser_Class::iface_init_function;

      gtype_ = gtk_file_chooser_get_type ();
    }

    return *this;
  }

  auto
  FileChooser_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  FileChooser_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new FileChooser ((GtkFileChooser*) (object));
  }

  FileChooser::FileChooser ()
    : glib::Interface (filechooser_class_.init ())
  {
  }

  FileChooser::FileChooser (GtkFileChooser* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  FileChooser::FileChooser (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  FileChooser::FileChooser (FileChooser&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  FileChooser::operator= (FileChooser&& src) noexcept -> FileChooser&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  FileChooser::~FileChooser () noexcept {}

  auto
  FileChooser::add_interface (GType gtype_implementer) -> void
  {
    filechooser_class_.init ().add_interface (gtype_implementer);
  }

  FileChooser::CppClassType FileChooser::filechooser_class_;

  auto
  FileChooser::get_type () -> GType
  {
    return filechooser_class_.init ().get_type ();
  }

  auto
  FileChooser::get_base_type () -> GType
  {
    return gtk_file_chooser_get_type ();
  }

  auto
  FileChooser::set_action (Action action) -> void
  {
    gtk_file_chooser_set_action (gobj (),
                                 static_cast<GtkFileChooserAction> (action));
  }

  auto
  FileChooser::get_action () const -> Action
  {
    return static_cast<Action> (
        gtk_file_chooser_get_action (const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_select_multiple (bool select_multiple) -> void
  {
    gtk_file_chooser_set_select_multiple (gobj (),
                                          static_cast<int> (select_multiple));
  }

  auto
  FileChooser::get_select_multiple () const -> bool
  {
    return gtk_file_chooser_get_select_multiple (
        const_cast<GtkFileChooser*> (gobj ()));
  }

  auto
  FileChooser::set_create_folders (bool create_folders) -> void
  {
    gtk_file_chooser_set_create_folders (gobj (),
                                         static_cast<int> (create_folders));
  }

  auto
  FileChooser::get_create_folders () const -> bool
  {
    return gtk_file_chooser_get_create_folders (
        const_cast<GtkFileChooser*> (gobj ()));
  }

  auto
  FileChooser::set_current_name (const glib::ustring& name) -> void
  {
    gtk_file_chooser_set_current_name (gobj (), name.c_str ());
  }

  auto
  FileChooser::get_current_name () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gtk_file_chooser_get_current_name (
            const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_file (const glib::RefPtr<const gio::File>& file) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_chooser_set_file (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_files () -> glib::RefPtr<gio::ListModel>
  {
    return glib::wrap (gtk_file_chooser_get_files (gobj ()));
  }

  auto
  FileChooser::get_files () const -> glib::RefPtr<const gio::ListModel>
  {
    return glib::wrap (
        gtk_file_chooser_get_files (const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_current_folder (const glib::RefPtr<const gio::File>& file) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_chooser_set_current_folder (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (file)),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_current_folder () -> glib::RefPtr<gio::File>
  {
    return glib::wrap (gtk_file_chooser_get_current_folder (gobj ()));
  }

  auto
  FileChooser::get_current_folder () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<FileChooser*> (this)->get_current_folder ();
  }

  auto
  FileChooser::get_file () -> glib::RefPtr<gio::File>
  {
    return glib::wrap (gtk_file_chooser_get_file (gobj ()));
  }

  auto
  FileChooser::get_file () const -> glib::RefPtr<const gio::File>
  {
    return const_cast<FileChooser*> (this)->get_file ();
  }

  auto
  FileChooser::add_filter (const glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_add_filter (
        gobj (),
        const_cast<GtkFileFilter*> (glib::unwrap (filter)));
  }

  auto
  FileChooser::remove_filter (const glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_remove_filter (
        gobj (),
        const_cast<GtkFileFilter*> (glib::unwrap (filter)));
  }

  auto
  FileChooser::get_filters () const -> glib::RefPtr<const gio::ListModel>
  {
    return glib::wrap (
        gtk_file_chooser_get_filters (const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_filter (const glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_set_filter (
        gobj (),
        const_cast<GtkFileFilter*> (glib::unwrap (filter)));
  }

  auto
  FileChooser::get_filter () -> glib::RefPtr<FileFilter>
  {
    auto retvalue = glib::wrap (gtk_file_chooser_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileChooser::get_filter () const -> glib::RefPtr<const FileFilter>
  {
    return const_cast<FileChooser*> (this)->get_filter ();
  }

  auto
  FileChooser::add_shortcut_folder (const glib::RefPtr<gio::File>& folder) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_chooser_add_shortcut_folder (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (folder)),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::remove_shortcut_folder (const glib::RefPtr<gio::File>& folder) -> bool
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_file_chooser_remove_shortcut_folder (
        gobj (),
        const_cast<GFile*> (glib::unwrap<gio::File> (folder)),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_shortcut_folders () const -> glib::RefPtr<const gio::ListModel>
  {
    return glib::wrap (gtk_file_chooser_get_shortcut_folders (
        const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::add_choice (const glib::ustring& id,
                           const glib::ustring& label,
                           const std::vector<glib::ustring>& options,
                           const std::vector<glib::ustring>& option_labels) -> void
  {
    gtk_file_chooser_add_choice (
        gobj (),
        id.c_str (),
        label.c_str (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (options).data (),
        glib::ArrayHandler<glib::ustring>::vector_to_array (option_labels)
            .data ());
  }

  auto
  FileChooser::remove_choice (const glib::ustring& id) -> void
  {
    gtk_file_chooser_remove_choice (gobj (), id.c_str ());
  }

  auto
  FileChooser::set_choice (const glib::ustring& id, const glib::ustring& option) -> void
  {
    gtk_file_chooser_set_choice (gobj (), id.c_str (), option.c_str ());
  }

  auto
  FileChooser::get_choice (const glib::ustring& id) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_get_choice (const_cast<GtkFileChooser*> (gobj ()),
                                     id.c_str ()));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Action>::value,
      "Type Action cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileChooser::property_action () -> glib::PropertyProxy<Action>
  {
    return glib::PropertyProxy<Action> (this, "action");
  }

  auto
  FileChooser::property_action () const -> glib::PropertyProxy_ReadOnly<Action>
  {
    return glib::PropertyProxy_ReadOnly<Action> (this, "action");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FileFilter>>::value,
      "Type glib::RefPtr<FileFilter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileChooser::property_filter () -> glib::PropertyProxy<glib::RefPtr<FileFilter>>
  {
    return glib::PropertyProxy<glib::RefPtr<FileFilter>> (this, "filter");
  }

  auto
  FileChooser::property_filter () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<FileFilter>> (this,
                                                                   "filter");
  }

  auto
  FileChooser::property_select_multiple () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "select-multiple");
  }

  auto
  FileChooser::property_select_multiple () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "select-multiple");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileChooser::property_filters () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (
        this,
        "filters");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::ListModel>>::value,
      "Type glib::RefPtr<gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  FileChooser::property_shortcut_folders () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>> (
        this,
        "shortcut-folders");
  }

  auto
  FileChooser::property_create_folders () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "create-folders");
  }

  auto
  FileChooser::property_create_folders () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "create-folders");
  }

} // namespace gtk

#endif
