// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/colorchooserdialog.hxx>
#include <libmm-gtk/colorchooserdialog_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  ColorChooserDialog::ColorChooserDialog (const Glib::ustring& title)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (colorchooserdialog_class_.init (),
                                     "title",
                                     title.c_str (),
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
  wrap (GtkColorChooserDialog* object, const bool take_copy) -> Gtk::ColorChooserDialog*
  {
    return dynamic_cast<Gtk::ColorChooserDialog*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ColorChooserDialog_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ColorChooserDialog_Class::class_init_function;

      register_derived_type (gtk_color_chooser_dialog_get_type ());
    }

    return *this;
  }

  auto
  ColorChooserDialog_Class::class_init_function (void* g_class,
                                                 void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ColorChooserDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new ColorChooserDialog ((GtkColorChooserDialog*) o);
  }

  ColorChooserDialog::ColorChooserDialog (
      const Glib::ConstructParams& construct_params)
    : Dialog (construct_params)
  {
  }

  ColorChooserDialog::ColorChooserDialog (GtkColorChooserDialog* castitem)
    : Dialog ((GtkDialog*) castitem)
  {
  }

  ColorChooserDialog::ColorChooserDialog (ColorChooserDialog&& src) noexcept
    : Dialog (std::move (src))
  {
  }

  auto
  ColorChooserDialog::operator= (ColorChooserDialog&& src) noexcept -> ColorChooserDialog&
  {
    Dialog::operator= (std::move (src));
    return *this;
  }

  ColorChooserDialog::~ColorChooserDialog () noexcept
  {
    destroy_ ();
  }

  ColorChooserDialog::CppClassType
      ColorChooserDialog::colorchooserdialog_class_;

  auto
  ColorChooserDialog::get_type () -> GType
  {
    return colorchooserdialog_class_.init ().get_type ();
  }

  auto
  ColorChooserDialog::get_base_type () -> GType
  {
    return gtk_color_chooser_dialog_get_type ();
  }

  ColorChooserDialog::ColorChooserDialog ()
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (colorchooserdialog_class_.init ()))
  {
  }

  ColorChooserDialog::ColorChooserDialog (const Glib::ustring& title,
                                          Window& transient_for)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (colorchooserdialog_class_.init (),
                                     "title",
                                     title.c_str (),
                                     "transient_for",
                                     transient_for.gobj (),
                                     nullptr))
  {
  }

  auto
  ColorChooserDialog::property_show_editor () -> Glib::PropertyProxy<bool>
  {
    return {this, "show-editor"};
  }

  auto
  ColorChooserDialog::property_show_editor () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "show-editor"};
  }

} // namespace Gtk
