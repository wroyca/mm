// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/filechoosernative.hxx>
  #include <libmm/gtk/filechoosernative_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/window.hxx>

namespace Gtk
{

  FileChooserNative::FileChooserNative (const Glib::ustring& title,
                                        Window& parent,
                                        FileChooser::Action action,
                                        const Glib::ustring& accept_label,
                                        const Glib::ustring& cancel_label)
    : Glib::ObjectBase (nullptr),
      NativeDialog (
          Glib::ConstructParams (filechoosernative_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "transient-for",
                                 parent.gobj (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "accept_label",
                                 Glib::c_str_or_nullptr (accept_label),
                                 "cancel_label",
                                 Glib::c_str_or_nullptr (cancel_label),
                                 nullptr))
  {
  }

  FileChooserNative::FileChooserNative (const Glib::ustring& title,
                                        FileChooser::Action action,
                                        const Glib::ustring& accept_label,
                                        const Glib::ustring& cancel_label)
    : Glib::ObjectBase (nullptr),
      NativeDialog (
          Glib::ConstructParams (filechoosernative_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "accept_label",
                                 Glib::c_str_or_nullptr (accept_label),
                                 "cancel_label",
                                 Glib::c_str_or_nullptr (cancel_label),
                                 nullptr))
  {
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFileChooserNative* object, bool take_copy) -> Glib::RefPtr<Gtk::FileChooserNative>
  {
    return Glib::make_refptr_for_instance<Gtk::FileChooserNative> (
        dynamic_cast<Gtk::FileChooserNative*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileChooserNative_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileChooserNative_Class::class_init_function;

      gtype_ = gtk_file_chooser_native_get_type ();
    }

    return *this;
  }

  auto
  FileChooserNative_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileChooserNative_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new FileChooserNative ((GtkFileChooserNative*) object);
  }

  auto
  FileChooserNative::gobj_copy () -> GtkFileChooserNative*
  {
    reference ();
    return gobj ();
  }

  FileChooserNative::FileChooserNative (
      const Glib::ConstructParams& construct_params)
    : NativeDialog (construct_params)
  {
  }

  FileChooserNative::FileChooserNative (GtkFileChooserNative* castitem)
    : NativeDialog ((GtkNativeDialog*) (castitem))
  {
  }

  FileChooserNative::FileChooserNative (FileChooserNative&& src) noexcept
    : NativeDialog (std::move (src)),
      FileChooser (std::move (src))
  {
  }

  auto
  FileChooserNative::operator= (FileChooserNative&& src) noexcept -> FileChooserNative&
  {
    NativeDialog::operator= (std::move (src));
    FileChooser::operator= (std::move (src));
    return *this;
  }

  FileChooserNative::~FileChooserNative () noexcept {}

  FileChooserNative::CppClassType FileChooserNative::filechoosernative_class_;

  auto
  FileChooserNative::get_type () -> GType
  {
    return filechoosernative_class_.init ().get_type ();
  }

  auto
  FileChooserNative::get_base_type () -> GType
  {
    return gtk_file_chooser_native_get_type ();
  }

  FileChooserNative::FileChooserNative ()
    : Glib::ObjectBase (nullptr),
      NativeDialog (Glib::ConstructParams (filechoosernative_class_.init ()))
  {
  }

  auto
  FileChooserNative::create (const Glib::ustring& title,
                             Window& parent,
                             FileChooser::Action action,
                             const Glib::ustring& accept_label,
                             const Glib::ustring& cancel_label) -> Glib::RefPtr<FileChooserNative>
  {
    return Glib::make_refptr_for_instance<FileChooserNative> (
        new FileChooserNative (title,
                               parent,
                               action,
                               accept_label,
                               cancel_label));
  }

  auto
  FileChooserNative::create (const Glib::ustring& title,
                             FileChooser::Action action,
                             const Glib::ustring& accept_label,
                             const Glib::ustring& cancel_label) -> Glib::RefPtr<FileChooserNative>
  {
    return Glib::make_refptr_for_instance<FileChooserNative> (
        new FileChooserNative (title, action, accept_label, cancel_label));
  }

  auto
  FileChooserNative::get_accept_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_native_get_accept_label (
            const_cast<GtkFileChooserNative*> (gobj ())));
  }

  auto
  FileChooserNative::set_accept_label (const Glib::ustring& accept_label) -> void
  {
    gtk_file_chooser_native_set_accept_label (
        gobj (),
        accept_label.empty () ? nullptr : accept_label.c_str ());
  }

  auto
  FileChooserNative::get_cancel_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_native_get_cancel_label (
            const_cast<GtkFileChooserNative*> (gobj ())));
  }

  auto
  FileChooserNative::set_cancel_label (const Glib::ustring& cancel_label) -> void
  {
    gtk_file_chooser_native_set_cancel_label (
        gobj (),
        cancel_label.empty () ? nullptr : cancel_label.c_str ());
  }

  auto
  FileChooserNative::property_accept_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "accept-label");
  }

  auto
  FileChooserNative::property_accept_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "accept-label");
  }

  auto
  FileChooserNative::property_cancel_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "cancel-label");
  }

  auto
  FileChooserNative::property_cancel_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "cancel-label");
  }

} // namespace Gtk

#endif
