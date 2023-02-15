// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/filechooserwidget.hxx>
  #include <libmm-gtk/filechooserwidget_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkFileChooserWidget* object, bool take_copy) -> Gtk::FileChooserWidget*
  {
    return dynamic_cast<Gtk::FileChooserWidget*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FileChooserWidget_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FileChooserWidget_Class::class_init_function;

      register_derived_type (gtk_file_chooser_widget_get_type ());

      FileChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FileChooserWidget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FileChooserWidget_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new FileChooserWidget ((GtkFileChooserWidget*) (o)));
  }

  FileChooserWidget::FileChooserWidget (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  FileChooserWidget::FileChooserWidget (GtkFileChooserWidget* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  FileChooserWidget::FileChooserWidget (FileChooserWidget&& src) noexcept
    : Gtk::Widget (std::move (src)),
      FileChooser (std::move (src))
  {
  }

  auto
  FileChooserWidget::operator= (FileChooserWidget&& src) noexcept -> FileChooserWidget&
  {
    Gtk::Widget::operator= (std::move (src));
    FileChooser::operator= (std::move (src));
    return *this;
  }

  FileChooserWidget::~FileChooserWidget () noexcept
  {
    destroy_ ();
  }

  FileChooserWidget::CppClassType FileChooserWidget::filechooserwidget_class_;

  auto
  FileChooserWidget::get_type () -> GType
  {
    return filechooserwidget_class_.init ().get_type ();
  }

  auto
  FileChooserWidget::get_base_type () -> GType
  {
    return gtk_file_chooser_widget_get_type ();
  }

  FileChooserWidget::FileChooserWidget ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (filechooserwidget_class_.init ()))
  {
  }

  FileChooserWidget::FileChooserWidget (Action action)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (
          Glib::ConstructParams (filechooserwidget_class_.init (),
                                 "action",
                                 static_cast<GtkFileChooserAction> (action),
                                 nullptr))
  {
  }

} // namespace Gtk

#endif
