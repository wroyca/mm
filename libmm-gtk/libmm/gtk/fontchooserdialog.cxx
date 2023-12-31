// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/fontchooserdialog.hxx>
  #include <libmm/gtk/fontchooserdialog_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

  FontChooserDialog::FontChooserDialog (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (fontchooserdialog_class_.init (),
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
  wrap (GtkFontChooserDialog* object, bool take_copy) -> gtk::FontChooserDialog*
  {
    return dynamic_cast<gtk::FontChooserDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  FontChooserDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &FontChooserDialog_Class::class_init_function;

      register_derived_type (gtk_font_chooser_dialog_get_type ());

      FontChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  FontChooserDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  FontChooserDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new FontChooserDialog ((GtkFontChooserDialog*) (o));
  }

  FontChooserDialog::FontChooserDialog (
      const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  FontChooserDialog::FontChooserDialog (GtkFontChooserDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  FontChooserDialog::FontChooserDialog (FontChooserDialog&& src) noexcept
    : gtk::Dialog (std::move (src)),
      FontChooser (std::move (src))
  {
  }

  auto
  FontChooserDialog::operator= (FontChooserDialog&& src) noexcept -> FontChooserDialog&
  {
    gtk::Dialog::operator= (std::move (src));
    FontChooser::operator= (std::move (src));
    return *this;
  }

  FontChooserDialog::~FontChooserDialog () noexcept
  {
    destroy_ ();
  }

  FontChooserDialog::CppClassType FontChooserDialog::fontchooserdialog_class_;

  auto
  FontChooserDialog::get_type () -> GType
  {
    return fontchooserdialog_class_.init ().get_type ();
  }

  auto
  FontChooserDialog::get_base_type () -> GType
  {
    return gtk_font_chooser_dialog_get_type ();
  }

  FontChooserDialog::FontChooserDialog ()
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (fontchooserdialog_class_.init ()))
  {
  }

  FontChooserDialog::FontChooserDialog (const glib::ustring& title,
                                        Window& transient_for)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (fontchooserdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          "transient_for",
                                          (transient_for).gobj (),
                                          nullptr))
  {
  }

} // namespace gtk

#endif
