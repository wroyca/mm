// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/fontchooserdialog.hxx>
#include <libmm-gtk/fontchooserdialog_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  FontChooserDialog::FontChooserDialog (const Glib::ustring& title)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (fontchooserdialog_class_.init (),
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
  wrap (GtkFontChooserDialog* object, const bool take_copy) -> Gtk::FontChooserDialog*
  {
    return dynamic_cast<Gtk::FontChooserDialog*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  FontChooserDialog_Class::init () -> const Class&
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
  FontChooserDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new FontChooserDialog ((GtkFontChooserDialog*) o);
  }

  FontChooserDialog::FontChooserDialog (
      const Glib::ConstructParams& construct_params)
    : Dialog (construct_params)
  {
  }

  FontChooserDialog::FontChooserDialog (GtkFontChooserDialog* castitem)
    : Dialog ((GtkDialog*) castitem)
  {
  }

  FontChooserDialog::FontChooserDialog (FontChooserDialog&& src) noexcept
    : Dialog (std::move (src)),
      FontChooser (std::move (src))
  {
  }

  auto
  FontChooserDialog::operator= (FontChooserDialog&& src) noexcept -> FontChooserDialog&
  {
    Dialog::operator= (std::move (src));
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
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (fontchooserdialog_class_.init ()))
  {
  }

  FontChooserDialog::FontChooserDialog (const Glib::ustring& title,
                                        Window& transient_for)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (fontchooserdialog_class_.init (),
                                     "title",
                                     title.c_str (),
                                     "transient_for",
                                     transient_for.gobj (),
                                     nullptr))
  {
  }

} // namespace Gtk
