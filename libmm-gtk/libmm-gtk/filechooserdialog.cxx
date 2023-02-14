// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/filechooserdialog.hxx>
#include <libmm-gtk/filechooserdialog_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  FileChooserDialog::FileChooserDialog (Window& parent,
                                        const Glib::ustring& title,
                                        const Action action,
                                        const bool use_header_bar)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (filechooserdialog_class_.init (),
                                     "title",
                                     title.c_str (),
                                     "action",
                                     action,
                                     "use-header-bar",
                                     use_header_bar,
                                     nullptr))
  {
    set_transient_for (parent);
  }

  FileChooserDialog::FileChooserDialog (const Glib::ustring& title,
                                        const Action action,
                                        const bool use_header_bar)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (filechooserdialog_class_.init (),
                                     "title",
                                     title.c_str (),
                                     "action",
                                     action,
                                     "use-header-bar",
                                     use_header_bar,
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
  wrap (GtkFileChooserDialog* object, const bool take_copy) -> Gtk::FileChooserDialog*
  {
    return dynamic_cast<Gtk::FileChooserDialog*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileChooserDialog_Class::init () -> const Class&
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
  FileChooserDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new FileChooserDialog ((GtkFileChooserDialog*) o);
  }

  FileChooserDialog::FileChooserDialog (
      const Glib::ConstructParams& construct_params)
    : Dialog (construct_params)
  {
  }

  FileChooserDialog::FileChooserDialog (GtkFileChooserDialog* castitem)
    : Dialog ((GtkDialog*) castitem)
  {
  }

  FileChooserDialog::FileChooserDialog (FileChooserDialog&& src) noexcept
    : Dialog (std::move (src)),
      FileChooser (std::move (src))
  {
  }

  auto
  FileChooserDialog::operator= (FileChooserDialog&& src) noexcept -> FileChooserDialog&
  {
    Dialog::operator= (std::move (src));
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

} // namespace Gtk
