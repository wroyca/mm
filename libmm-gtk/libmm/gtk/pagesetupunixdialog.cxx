// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/pagesetupunixdialog.hxx>
#include <libmm/gtk/pagesetupunixdialog_p.hxx>

#include <gtk/gtkunixprint.h>

namespace gtk
{

  PageSetupUnixDialog::PageSetupUnixDialog (gtk::Window& parent,
                                            const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (pagesetupunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    set_transient_for (parent);
  }

  PageSetupUnixDialog::PageSetupUnixDialog (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (pagesetupunixdialog_class_.init (),
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
  wrap (GtkPageSetupUnixDialog* object, bool take_copy) -> gtk::PageSetupUnixDialog*
  {
    return dynamic_cast<gtk::PageSetupUnixDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  PageSetupUnixDialog_Class::init () -> const glib::Class&
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
  PageSetupUnixDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new PageSetupUnixDialog ((GtkPageSetupUnixDialog*) (o));
  }

  PageSetupUnixDialog::PageSetupUnixDialog (
      const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  PageSetupUnixDialog::PageSetupUnixDialog (GtkPageSetupUnixDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  PageSetupUnixDialog::PageSetupUnixDialog (PageSetupUnixDialog&& src) noexcept
    : gtk::Dialog (std::move (src))
  {
  }

  auto
  PageSetupUnixDialog::operator= (PageSetupUnixDialog&& src) noexcept -> PageSetupUnixDialog&
  {
    gtk::Dialog::operator= (std::move (src));
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
      const glib::RefPtr<PageSetup>& page_setup) -> void
  {
    gtk_page_setup_unix_dialog_set_page_setup (gobj (),
                                               glib::unwrap (page_setup));
  }

  auto
  PageSetupUnixDialog::get_page_setup () -> glib::RefPtr<PageSetup>
  {
    auto retvalue =
        glib::wrap (gtk_page_setup_unix_dialog_get_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PageSetupUnixDialog::get_page_setup () const -> glib::RefPtr<const PageSetup>
  {
    return const_cast<PageSetupUnixDialog*> (this)->get_page_setup ();
  }

  auto
  PageSetupUnixDialog::set_print_settings (
      const glib::RefPtr<PrintSettings>& print_settings) -> void
  {
    gtk_page_setup_unix_dialog_set_print_settings (
        gobj (),
        glib::unwrap (print_settings));
  }

  auto
  PageSetupUnixDialog::get_print_settings () -> glib::RefPtr<PrintSettings>
  {
    auto retvalue =
        glib::wrap (gtk_page_setup_unix_dialog_get_print_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PageSetupUnixDialog::get_print_settings () const -> glib::RefPtr<const PrintSettings>
  {
    return const_cast<PageSetupUnixDialog*> (this)->get_print_settings ();
  }

} // namespace gtk
