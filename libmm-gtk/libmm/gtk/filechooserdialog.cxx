// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/filechooserdialog.hxx>
  #include <libmm/gtk/filechooserdialog_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  FileChooserDialog::FileChooserDialog (gtk::Window& parent,
                                        const glib::ustring& title,
                                        Action action,
                                        bool use_header_bar)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (
          glib::ConstructParams (filechooserdialog_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "use-header-bar",
                                 static_cast<int> (use_header_bar),
                                 nullptr))
  {
    set_transient_for (parent);
  }

  FileChooserDialog::FileChooserDialog (const glib::ustring& title,
                                        Action action,
                                        bool use_header_bar)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (
          glib::ConstructParams (filechooserdialog_class_.init (),
                                 "title",
                                 title.c_str (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 "use-header-bar",
                                 static_cast<int> (use_header_bar),
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
  wrap (GtkFileChooserDialog* object, bool take_copy) -> gtk::FileChooserDialog*
  {
    return dynamic_cast<gtk::FileChooserDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  FileChooserDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileChooserDialog_Class::class_init_function;

      register_derived_type (gtk_file_chooser_dialog_get_type ());

      FileChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileChooserDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileChooserDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new FileChooserDialog ((GtkFileChooserDialog*) (o));
  }

  FileChooserDialog::FileChooserDialog (
      const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  FileChooserDialog::FileChooserDialog (GtkFileChooserDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  FileChooserDialog::FileChooserDialog (FileChooserDialog&& src) noexcept
    : gtk::Dialog (std::move (src)),
      FileChooser (std::move (src))
  {
  }

  auto
  FileChooserDialog::operator= (FileChooserDialog&& src) noexcept -> FileChooserDialog&
  {
    gtk::Dialog::operator= (std::move (src));
    FileChooser::operator= (std::move (src));
    return *this;
  }

  FileChooserDialog::~FileChooserDialog () noexcept
  {
    destroy_ ();
  }

  FileChooserDialog::CppClassType FileChooserDialog::filechooserdialog_class_;

  auto
  FileChooserDialog::get_type () -> GType
  {
    return filechooserdialog_class_.init ().get_type ();
  }

  auto
  FileChooserDialog::get_base_type () -> GType
  {
    return gtk_file_chooser_dialog_get_type ();
  }

} // namespace gtk

#endif
