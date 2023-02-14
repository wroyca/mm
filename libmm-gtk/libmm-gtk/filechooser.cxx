// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filechooser.hxx>
#include <libmm-gtk/filechooser_p.hxx>

#include <gtk/gtk.h>
#include <libmm-glib/vectorutils.hxx>

using Action = Gtk::FileChooser::Action;

namespace Gtk
{
  auto
  FileChooser::add_choice (const Glib::ustring& id, const Glib::ustring& label) -> void
  {
    gtk_file_chooser_add_choice (gobj (),
                                 id.c_str (),
                                 label.c_str (),
                                 nullptr,
                                 nullptr);
  }

} // namespace Gtk

namespace
{
}

Gtk::FileChooserError::FileChooserError (const Code error_code,
                                         const Glib::ustring& error_message)
  : Error (GTK_FILE_CHOOSER_ERROR, error_code, error_message)
{
}

Gtk::FileChooserError::FileChooserError (GError* gobject)
  : Error (gobject)
{
}

auto
Gtk::FileChooserError::code () const -> Code
{
  return static_cast<Code> (Error::code ());
}

auto
Gtk::FileChooserError::throw_func (GError* gobject) -> void
{
  throw FileChooserError (gobject);
}

auto
Glib::Value<Gtk::FileChooserError::Code>::value_type () -> GType
{
  return gtk_file_chooser_error_get_type ();
}

auto
Glib::Value<Gtk::FileChooser::Action>::value_type () -> GType
{
  return gtk_file_chooser_action_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkFileChooser* object, const bool take_copy) -> RefPtr<Gtk::FileChooser>
  {
    return Glib::make_refptr_for_instance<Gtk::FileChooser> (
        Glib::wrap_auto_interface<Gtk::FileChooser> ((GObject*) object,
                                                     take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileChooser_Class::init () -> const Interface_Class&
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
  FileChooser_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileChooser ((GtkFileChooser*) object);
  }

  FileChooser::FileChooser ()
    : Interface (filechooser_class_.init ())
  {
  }

  FileChooser::FileChooser (GtkFileChooser* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  FileChooser::FileChooser (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  FileChooser::FileChooser (FileChooser&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  FileChooser::operator= (FileChooser&& src) noexcept -> FileChooser&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  FileChooser::~FileChooser () noexcept = default;

  auto
  FileChooser::add_interface (const GType gtype_implementer) -> void
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
  FileChooser::set_select_multiple (const bool select_multiple) -> void
  {
    gtk_file_chooser_set_select_multiple (gobj (), select_multiple);
  }

  auto
  FileChooser::get_select_multiple () const -> bool
  {
    return gtk_file_chooser_get_select_multiple (
        const_cast<GtkFileChooser*> (gobj ()));
  }

  auto
  FileChooser::set_create_folders (const bool create_folders) -> void
  {
    gtk_file_chooser_set_create_folders (gobj (), create_folders);
  }

  auto
  FileChooser::get_create_folders () const -> bool
  {
    return gtk_file_chooser_get_create_folders (
        const_cast<GtkFileChooser*> (gobj ()));
  }

  auto
  FileChooser::set_current_name (const Glib::ustring& name) -> void
  {
    gtk_file_chooser_set_current_name (gobj (), name.c_str ());
  }

  auto
  FileChooser::get_current_name () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
        gtk_file_chooser_get_current_name (
            const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_file (const Glib::RefPtr<const Gio::File>& file) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_file_chooser_set_file (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_files () -> Glib::RefPtr<Gio::ListModel>
  {
    return Glib::wrap (gtk_file_chooser_get_files (gobj ()));
  }

  auto
  FileChooser::get_files () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return Glib::wrap (
        gtk_file_chooser_get_files (const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_current_folder (const Glib::RefPtr<const Gio::File>& file) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_file_chooser_set_current_folder (
        gobj (),
        const_cast<GFile*> (Glib::unwrap<Gio::File> (file)),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_current_folder () -> Glib::RefPtr<Gio::File>
  {
    return Glib::wrap (gtk_file_chooser_get_current_folder (gobj ()));
  }

  auto
  FileChooser::get_current_folder () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<FileChooser*> (this)->get_current_folder ();
  }

  auto
  FileChooser::get_file () -> Glib::RefPtr<Gio::File>
  {
    return Glib::wrap (gtk_file_chooser_get_file (gobj ()));
  }

  auto
  FileChooser::get_file () const -> Glib::RefPtr<const Gio::File>
  {
    return const_cast<FileChooser*> (this)->get_file ();
  }

  auto
  FileChooser::add_filter (const Glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_add_filter (gobj (), Glib::unwrap (filter));
  }

  auto
  FileChooser::remove_filter (const Glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_remove_filter (gobj (), Glib::unwrap (filter));
  }

  auto
  FileChooser::get_filters () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return Glib::wrap (
        gtk_file_chooser_get_filters (const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::set_filter (const Glib::RefPtr<FileFilter>& filter) -> void
  {
    gtk_file_chooser_set_filter (gobj (), Glib::unwrap (filter));
  }

  auto
  FileChooser::get_filter () -> Glib::RefPtr<FileFilter>
  {
    auto retvalue = Glib::wrap (gtk_file_chooser_get_filter (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  FileChooser::get_filter () const -> Glib::RefPtr<const FileFilter>
  {
    return const_cast<FileChooser*> (this)->get_filter ();
  }

  auto
  FileChooser::add_shortcut_folder (const Glib::RefPtr<Gio::File>& folder) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_file_chooser_add_shortcut_folder (
        gobj (),
        Glib::unwrap<Gio::File> (folder),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::remove_shortcut_folder (const Glib::RefPtr<Gio::File>& folder) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = gtk_file_chooser_remove_shortcut_folder (
        gobj (),
        Glib::unwrap<Gio::File> (folder),
        &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  FileChooser::get_shortcut_folders () const -> Glib::RefPtr<const Gio::ListModel>
  {
    return Glib::wrap (gtk_file_chooser_get_shortcut_folders (
        const_cast<GtkFileChooser*> (gobj ())));
  }

  auto
  FileChooser::add_choice (const Glib::ustring& id,
                           const Glib::ustring& label,
                           const std::vector<Glib::ustring>& options,
                           const std::vector<Glib::ustring>& option_labels) -> void
  {
    gtk_file_chooser_add_choice (
        gobj (),
        id.c_str (),
        label.c_str (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (options).data (),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (option_labels)
            .data ());
  }

  auto
  FileChooser::remove_choice (const Glib::ustring& id) -> void
  {
    gtk_file_chooser_remove_choice (gobj (), id.c_str ());
  }

  auto
  FileChooser::set_choice (const Glib::ustring& id, const Glib::ustring& option) -> void
  {
    gtk_file_chooser_set_choice (gobj (), id.c_str (), option.c_str ());
  }

  auto
  FileChooser::get_choice (const Glib::ustring& id) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_get_choice (const_cast<GtkFileChooser*> (gobj ()),
                                     id.c_str ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Action>::value,
      "Type Action cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileChooser::property_action () -> Glib::PropertyProxy<Action>
  {
    return {this, "action"};
  }

  auto
  FileChooser::property_action () const -> Glib::PropertyProxy_ReadOnly<Action>
  {
    return {this, "action"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<FileFilter>>::value,
      "Type Glib::RefPtr<FileFilter> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileChooser::property_filter () -> Glib::PropertyProxy<Glib::RefPtr<FileFilter>>
  {
    return {this, "filter"};
  }

  auto
  FileChooser::property_filter () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileFilter>>
  {
    return {this, "filter"};
  }

  auto
  FileChooser::property_select_multiple () -> Glib::PropertyProxy<bool>
  {
    return {this, "select-multiple"};
  }

  auto
  FileChooser::property_select_multiple () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "select-multiple"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileChooser::property_filters () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return {this, "filters"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::ListModel>>::value,
      "Type Glib::RefPtr<Gio::ListModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  FileChooser::property_shortcut_folders () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>
  {
    return {this, "shortcut-folders"};
  }

  auto
  FileChooser::property_create_folders () -> Glib::PropertyProxy<bool>
  {
    return {this, "create-folders"};
  }

  auto
  FileChooser::property_create_folders () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "create-folders"};
  }

} // namespace Gtk
