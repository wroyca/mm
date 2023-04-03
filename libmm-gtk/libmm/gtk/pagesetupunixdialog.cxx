// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/pagesetupunixdialog.hxx>
#include <libmm/gtk/pagesetupunixdialog_p.hxx>

#include <gtk/gtkunixprint.hxx>

namespace Gtk
{

  PageSetupUnixDialog::PageSetupUnixDialog (Gtk::Window& parent,
                                            const Glib::ustring& title)
    : Glib::ObjectBase (nullptr),
      Gtk::Dialog (Glib::ConstructParams (pagesetupunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    set_transient_for (parent);
  }

  PageSetupUnixDialog::PageSetupUnixDialog (const Glib::ustring& title)
    : Glib::ObjectBase (nullptr),
      Gtk::Dialog (Glib::ConstructParams (pagesetupunixdialog_class_.init (),
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
  wrap (GtkPageSetupUnixDialog* object, bool take_copy) -> Gtk::PageSetupUnixDialog*
  {
    return dynamic_cast<Gtk::PageSetupUnixDialog*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PageSetupUnixDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PageSetupUnixDialog_Class::class_init_function;

      register_derived_type (gtk_page_setup_unix_dialog_get_type ());
    }

    return *this;
  }

  auto
  PageSetupUnixDialog_Class::class_init_function (void* g_class,
                                                  void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PageSetupUnixDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new PageSetupUnixDialog ((GtkPageSetupUnixDialog*) (o));
  }

  PageSetupUnixDialog::PageSetupUnixDialog (
      const Glib::ConstructParams& construct_params)
    : Gtk::Dialog (construct_params)
  {
  }

  PageSetupUnixDialog::PageSetupUnixDialog (GtkPageSetupUnixDialog* castitem)
    : Gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  PageSetupUnixDialog::PageSetupUnixDialog (PageSetupUnixDialog&& src) noexcept
    : Gtk::Dialog (std::move (src))
  {
  }

  auto
  PageSetupUnixDialog::operator= (PageSetupUnixDialog&& src) noexcept -> PageSetupUnixDialog&
  {
    Gtk::Dialog::operator= (std::move (src));
    return *this;
  }

  PageSetupUnixDialog::~PageSetupUnixDialog () noexcept
  {
    destroy_ ();
  }

  PageSetupUnixDialog::CppClassType
      PageSetupUnixDialog::pagesetupunixdialog_class_;

  auto
  PageSetupUnixDialog::get_type () -> GType
  {
    return pagesetupunixdialog_class_.init ().get_type ();
  }

  auto
  PageSetupUnixDialog::get_base_type () -> GType
  {
    return gtk_page_setup_unix_dialog_get_type ();
  }

  auto
  PageSetupUnixDialog::set_page_setup (
      const Glib::RefPtr<PageSetup>& page_setup) -> void
  {
    gtk_page_setup_unix_dialog_set_page_setup (gobj (),
                                               Glib::unwrap (page_setup));
  }

  auto
  PageSetupUnixDialog::get_page_setup () -> Glib::RefPtr<PageSetup>
  {
    auto retvalue =
        Glib::wrap (gtk_page_setup_unix_dialog_get_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PageSetupUnixDialog::get_page_setup () const -> Glib::RefPtr<const PageSetup>
  {
    return const_cast<PageSetupUnixDialog*> (this)->get_page_setup ();
  }

  auto
  PageSetupUnixDialog::set_print_settings (
      const Glib::RefPtr<PrintSettings>& print_settings) -> void
  {
    gtk_page_setup_unix_dialog_set_print_settings (
        gobj (),
        Glib::unwrap (print_settings));
  }

  auto
  PageSetupUnixDialog::get_print_settings () -> Glib::RefPtr<PrintSettings>
  {
    auto retvalue =
        Glib::wrap (gtk_page_setup_unix_dialog_get_print_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PageSetupUnixDialog::get_print_settings () const -> Glib::RefPtr<const PrintSettings>
  {
    return const_cast<PageSetupUnixDialog*> (this)->get_print_settings ();
  }

} // namespace Gtk
