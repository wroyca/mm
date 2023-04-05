// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/colorchooserdialog.hxx>
  #include <libmm/gtk/colorchooserdialog_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  ColorChooserDialog::ColorChooserDialog (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (colorchooserdialog_class_.init (),
                                          "title",
                                          title.c_str (),
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
  wrap (GtkColorChooserDialog* object, bool take_copy) -> gtk::ColorChooserDialog*
  {
    return dynamic_cast<gtk::ColorChooserDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ColorChooserDialog_Class::init () -> const glib::Class&
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
  ColorChooserDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new ColorChooserDialog ((GtkColorChooserDialog*) (o));
  }

  ColorChooserDialog::ColorChooserDialog (
      const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  ColorChooserDialog::ColorChooserDialog (GtkColorChooserDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  ColorChooserDialog::ColorChooserDialog (ColorChooserDialog&& src) noexcept
    : gtk::Dialog (std::move (src))
  {
  }

  auto
  ColorChooserDialog::operator= (ColorChooserDialog&& src) noexcept -> ColorChooserDialog&
  {
    gtk::Dialog::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (colorchooserdialog_class_.init ()))
  {
  }

  ColorChooserDialog::ColorChooserDialog (const glib::ustring& title,
                                          Window& transient_for)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (colorchooserdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "transient_for",
                                          (transient_for).gobj (),
                                          nullptr))
  {
  }

  auto
  ColorChooserDialog::property_show_editor () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-editor");
  }

  auto
  ColorChooserDialog::property_show_editor () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-editor");
  }

} // namespace gtk

#endif
