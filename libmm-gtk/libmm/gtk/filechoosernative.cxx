// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/filechoosernative.hxx>
  #include <libmm/gtk/filechoosernative_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/window.hxx>

namespace gtk
{

  FileChooserNative::FileChooserNative (const glib::ustring& title,
                                        Window& parent,
                                        FileChooser::Action action,
                                        const glib::ustring& accept_label,
                                        const glib::ustring& cancel_label)
    : glib::ObjectBase (nullptr),
      NativeDialog (
          glib::ConstructParams (filechoosernative_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "transient-for",
                                 parent.gobj (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "accept_label",
                                 glib::c_str_or_nullptr (accept_label),
                                 "cancel_label",
                                 glib::c_str_or_nullptr (cancel_label),
                                 nullptr))
  {
  }

  FileChooserNative::FileChooserNative (const glib::ustring& title,
                                        FileChooser::Action action,
                                        const glib::ustring& accept_label,
                                        const glib::ustring& cancel_label)
    : glib::ObjectBase (nullptr),
      NativeDialog (
          glib::ConstructParams (filechoosernative_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "accept_label",
                                 glib::c_str_or_nullptr (accept_label),
                                 "cancel_label",
                                 glib::c_str_or_nullptr (cancel_label),
                                 nullptr))
  {
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkFileChooserNative* object, bool take_copy) -> glib::RefPtr<gtk::FileChooserNative>
  {
    return glib::make_refptr_for_instance<gtk::FileChooserNative> (
        dynamic_cast<gtk::FileChooserNative*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  FileChooserNative_Class::init () -> const glib::Class&
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
  FileChooserNative_Class::wrap_new (GObject* object) -> glib::ObjectBase*
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
      const glib::ConstructParams& construct_params)
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
    : glib::ObjectBase (nullptr),
      NativeDialog (glib::ConstructParams (filechoosernative_class_.init ()))
  {
  }

  auto
  FileChooserNative::create (const glib::ustring& title,
                             Window& parent,
                             FileChooser::Action action,
                             const glib::ustring& accept_label,
                             const glib::ustring& cancel_label) -> glib::RefPtr<FileChooserNative>
  {
    return glib::make_refptr_for_instance<FileChooserNative> (
        new FileChooserNative (title,
                               parent,
                               action,
                               accept_label,
                               cancel_label));
  }

  auto
  FileChooserNative::create (const glib::ustring& title,
                             FileChooser::Action action,
                             const glib::ustring& accept_label,
                             const glib::ustring& cancel_label) -> glib::RefPtr<FileChooserNative>
  {
    return glib::make_refptr_for_instance<FileChooserNative> (
        new FileChooserNative (title, action, accept_label, cancel_label));
  }

  auto
  FileChooserNative::get_accept_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_native_get_accept_label (
            const_cast<GtkFileChooserNative*> (gobj ())));
  }

  auto
  FileChooserNative::set_accept_label (const glib::ustring& accept_label) -> void
  {
    gtk_file_chooser_native_set_accept_label (
        gobj (),
        accept_label.empty () ? nullptr : accept_label.c_str ());
  }

  auto
  FileChooserNative::get_cancel_label () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_file_chooser_native_get_cancel_label (
            const_cast<GtkFileChooserNative*> (gobj ())));
  }

  auto
  FileChooserNative::set_cancel_label (const glib::ustring& cancel_label) -> void
  {
    gtk_file_chooser_native_set_cancel_label (
        gobj (),
        cancel_label.empty () ? nullptr : cancel_label.c_str ());
  }

  auto
  FileChooserNative::property_accept_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "accept-label");
  }

  auto
  FileChooserNative::property_accept_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "accept-label");
  }

  auto
  FileChooserNative::property_cancel_label () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "cancel-label");
  }

  auto
  FileChooserNative::property_cancel_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "cancel-label");
  }

} // namespace gtk

#endif
