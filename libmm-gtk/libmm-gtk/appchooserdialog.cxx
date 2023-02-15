// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/mm-glib.hxx>

  #include <libmm-gtk/appchooserdialog.hxx>
  #include <libmm-gtk/appchooserdialog_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

  AppChooserDialog::AppChooserDialog (const Glib::ustring& content_type)
    : Glib::ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (appchooserdialog_class_.init (),
                                     "content_type",
                                     content_type.c_str (),
                                     nullptr))
  {
  }

  AppChooserDialog::AppChooserDialog (const Glib::ustring& content_type,
                                      Gtk::Window& parent)
    : Glib::ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (appchooserdialog_class_.init (),
                                     "content_type",
                                     content_type.c_str (),
                                     nullptr))
  {
    set_transient_for (parent);
  }

  AppChooserDialog::AppChooserDialog (const Glib::RefPtr<Gio::File>& file)
    : Glib::ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (appchooserdialog_class_.init (),
                                     "gfile",
                                     Glib::unwrap (file),
                                     nullptr))
  {
  }

  AppChooserDialog::AppChooserDialog (const Glib::RefPtr<Gio::File>& file,
                                      Gtk::Window& parent)
    : Glib::ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (appchooserdialog_class_.init (),
                                     "gfile",
                                     Glib::unwrap (file),
                                     nullptr))
  {
    set_transient_for (parent);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkAppChooserDialog* object, bool take_copy) -> Gtk::AppChooserDialog*
  {
    return dynamic_cast<Gtk::AppChooserDialog*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AppChooserDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppChooserDialog_Class::class_init_function;

      register_derived_type (gtk_app_chooser_dialog_get_type ());

      AppChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  AppChooserDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AppChooserDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new AppChooserDialog ((GtkAppChooserDialog*) (o));
  }

  AppChooserDialog::AppChooserDialog (
      const Glib::ConstructParams& construct_params)
    : Dialog (construct_params)
  {
  }

  AppChooserDialog::AppChooserDialog (GtkAppChooserDialog* castitem)
    : Dialog ((GtkDialog*) (castitem))
  {
  }

  AppChooserDialog::AppChooserDialog (AppChooserDialog&& src) noexcept
    : Dialog (std::move (src)),
      AppChooser (std::move (src))
  {
  }

  auto
  AppChooserDialog::operator= (AppChooserDialog&& src) noexcept -> AppChooserDialog&
  {
    Dialog::operator= (std::move (src));
    AppChooser::operator= (std::move (src));
    return *this;
  }

  AppChooserDialog::~AppChooserDialog () noexcept
  {
    destroy_ ();
  }

  AppChooserDialog::CppClassType AppChooserDialog::appchooserdialog_class_;

  auto
  AppChooserDialog::get_type () -> GType
  {
    return appchooserdialog_class_.init ().get_type ();
  }

  auto
  AppChooserDialog::get_base_type () -> GType
  {
    return gtk_app_chooser_dialog_get_type ();
  }

  auto
  AppChooserDialog::get_widget () -> Widget*
  {
    return Glib::wrap (gtk_app_chooser_dialog_get_widget (gobj ()));
  }

  auto
  AppChooserDialog::get_widget () const -> const Widget*
  {
    return const_cast<AppChooserDialog*> (this)->get_widget ();
  }

  auto
  AppChooserDialog::set_heading (const Glib::ustring& heading) -> void
  {
    gtk_app_chooser_dialog_set_heading (gobj (), heading.c_str ());
  }

  auto
  AppChooserDialog::get_heading () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_app_chooser_dialog_get_heading (
            const_cast<GtkAppChooserDialog*> (gobj ())));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::File>>::value,
      "Type Glib::RefPtr<Gio::File> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AppChooserDialog::property_gfile () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>> (this,
                                                                  "gfile");
  }

  auto
  AppChooserDialog::property_heading () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "heading");
  }

  auto
  AppChooserDialog::property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "heading");
  }

} // namespace Gtk

#endif
