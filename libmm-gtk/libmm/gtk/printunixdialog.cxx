// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printunixdialog.hxx>
#include <libmm/gtk/printunixdialog_p.hxx>

#include <gtk/gtkunixprint.hxx>
#include <libmm/gtk/label.hxx>

namespace Gtk
{

  PrintUnixDialog::PrintUnixDialog (Gtk::Window& parent,
                                    const Glib::ustring& title)
    : Glib::ObjectBase (nullptr),
      Gtk::Dialog (Glib::ConstructParams (printunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    set_transient_for (parent);
  }

  PrintUnixDialog::PrintUnixDialog (const Glib::ustring& title)
    : Glib::ObjectBase (nullptr),
      Gtk::Dialog (Glib::ConstructParams (printunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
  }

  auto
  PrintUnixDialog::add_custom_tab (const Widget& child,
                                   const Glib::ustring& tab_label) -> void
  {
    auto label = Gtk::manage (new Gtk::Label (tab_label));
    add_custom_tab (child, *label);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPrintUnixDialog* object, bool take_copy) -> Gtk::PrintUnixDialog*
  {
    return dynamic_cast<Gtk::PrintUnixDialog*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PrintUnixDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PrintUnixDialog_Class::class_init_function;

      register_derived_type (gtk_print_unix_dialog_get_type ());
    }

    return *this;
  }

  auto
  PrintUnixDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PrintUnixDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new PrintUnixDialog ((GtkPrintUnixDialog*) (o));
  }

  PrintUnixDialog::PrintUnixDialog (
      const Glib::ConstructParams& construct_params)
    : Gtk::Dialog (construct_params)
  {
  }

  PrintUnixDialog::PrintUnixDialog (GtkPrintUnixDialog* castitem)
    : Gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  PrintUnixDialog::PrintUnixDialog (PrintUnixDialog&& src) noexcept
    : Gtk::Dialog (std::move (src))
  {
  }

  auto
  PrintUnixDialog::operator= (PrintUnixDialog&& src) noexcept -> PrintUnixDialog&
  {
    Gtk::Dialog::operator= (std::move (src));
    return *this;
  }

  PrintUnixDialog::~PrintUnixDialog () noexcept
  {
    destroy_ ();
  }

  PrintUnixDialog::CppClassType PrintUnixDialog::printunixdialog_class_;

  auto
  PrintUnixDialog::get_type () -> GType
  {
    return printunixdialog_class_.init ().get_type ();
  }

  auto
  PrintUnixDialog::get_base_type () -> GType
  {
    return gtk_print_unix_dialog_get_type ();
  }

  auto
  PrintUnixDialog::set_page_setup (const Glib::RefPtr<PageSetup>& page_setup) -> void
  {
    gtk_print_unix_dialog_set_page_setup (gobj (), Glib::unwrap (page_setup));
  }

  auto
  PrintUnixDialog::get_page_setup () -> Glib::RefPtr<PageSetup>
  {
    auto retvalue = Glib::wrap (gtk_print_unix_dialog_get_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_page_setup () const -> Glib::RefPtr<const PageSetup>
  {
    return const_cast<PrintUnixDialog*> (this)->get_page_setup ();
  }

  auto
  PrintUnixDialog::set_current_page (int current_page) -> void
  {
    gtk_print_unix_dialog_set_current_page (gobj (), current_page);
  }

  auto
  PrintUnixDialog::get_current_page () const -> int
  {
    return gtk_print_unix_dialog_get_current_page (
        const_cast<GtkPrintUnixDialog*> (gobj ()));
  }

  auto
  PrintUnixDialog::set_settings (const Glib::RefPtr<PrintSettings>& settings) -> void
  {
    gtk_print_unix_dialog_set_settings (gobj (), Glib::unwrap (settings));
  }

  auto
  PrintUnixDialog::get_settings () -> Glib::RefPtr<PrintSettings>
  {
    auto retvalue = Glib::wrap (gtk_print_unix_dialog_get_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_settings () const -> Glib::RefPtr<const PrintSettings>
  {
    return const_cast<PrintUnixDialog*> (this)->get_settings ();
  }

  auto
  PrintUnixDialog::get_selected_printer () -> Glib::RefPtr<Printer>
  {
    auto retvalue =
        Glib::wrap (gtk_print_unix_dialog_get_selected_printer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_selected_printer () const -> Glib::RefPtr<const Printer>
  {
    return const_cast<PrintUnixDialog*> (this)->get_selected_printer ();
  }

  auto
  PrintUnixDialog::add_custom_tab (const Widget& child, const Widget& tab_label) -> void
  {
    gtk_print_unix_dialog_add_custom_tab (
        gobj (),
        const_cast<GtkWidget*> ((child).gobj ()),
        const_cast<GtkWidget*> ((tab_label).gobj ()));
  }

  auto
  PrintUnixDialog::set_manual_capabilities (PrintCapabilities capabilities) -> void
  {
    gtk_print_unix_dialog_set_manual_capabilities (
        gobj (),
        static_cast<GtkPrintCapabilities> (capabilities));
  }

  auto
  PrintUnixDialog::get_manual_capabilities () const -> PrintCapabilities
  {
    return static_cast<PrintCapabilities> (
        gtk_print_unix_dialog_get_manual_capabilities (
            const_cast<GtkPrintUnixDialog*> (gobj ())));
  }

  auto
  PrintUnixDialog::get_support_selection (bool support_selection) -> void
  {
    gtk_print_unix_dialog_set_support_selection (
        gobj (),
        static_cast<int> (support_selection));
  }

  auto
  PrintUnixDialog::get_support_selection () const -> bool
  {
    return gtk_print_unix_dialog_get_support_selection (
        const_cast<GtkPrintUnixDialog*> (gobj ()));
  }

  auto
  PrintUnixDialog::set_has_selection (bool has_selection) -> void
  {
    gtk_print_unix_dialog_set_has_selection (gobj (),
                                             static_cast<int> (has_selection));
  }

  auto
  PrintUnixDialog::get_has_selection () const -> bool
  {
    return gtk_print_unix_dialog_get_has_selection (
        const_cast<GtkPrintUnixDialog*> (gobj ()));
  }

  auto
  PrintUnixDialog::set_embed_page_setup (bool embed) -> void
  {
    gtk_print_unix_dialog_set_embed_page_setup (gobj (),
                                                static_cast<int> (embed));
  }

  auto
  PrintUnixDialog::get_embed_page_setup () const -> bool
  {
    return gtk_print_unix_dialog_get_embed_page_setup (
        const_cast<GtkPrintUnixDialog*> (gobj ()));
  }

  auto
  PrintUnixDialog::get_page_setup_set () const -> bool
  {
    return gtk_print_unix_dialog_get_page_setup_set (
        const_cast<GtkPrintUnixDialog*> (gobj ()));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<PageSetup>>::value,
      "Type Glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintUnixDialog::property_page_setup () -> Glib::PropertyProxy<Glib::RefPtr<PageSetup>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<PageSetup>> (this, "page-setup");
  }

  auto
  PrintUnixDialog::property_page_setup () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PageSetup>> (this,
                                                                  "page-setup");
  }

  auto
  PrintUnixDialog::property_current_page () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "current-page");
  }

  auto
  PrintUnixDialog::property_current_page () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "current-page");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<PrintSettings>>::value,
      "Type Glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintUnixDialog::property_print_settings () -> Glib::PropertyProxy<Glib::RefPtr<PrintSettings>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<PrintSettings>> (this,
                                                             "print-settings");
  }

  auto
  PrintUnixDialog::property_print_settings () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<PrintSettings>> (
        this,
        "print-settings");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Printer>>::value,
      "Type Glib::RefPtr<Printer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PrintUnixDialog::property_selected_printer () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Printer>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Printer>> (
        this,
        "selected-printer");
  }

  auto
  PrintUnixDialog::property_manual_capabilities () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "manual-capabilities");
  }

  auto
  PrintUnixDialog::property_manual_capabilities () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "manual-capabilities");
  }

  auto
  PrintUnixDialog::property_support_selection () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "support-selection");
  }

  auto
  PrintUnixDialog::property_support_selection () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "support-selection");
  }

  auto
  PrintUnixDialog::property_has_selection () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-selection");
  }

  auto
  PrintUnixDialog::property_has_selection () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-selection");
  }

  auto
  PrintUnixDialog::property_embed_page_setup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "embed-page-setup");
  }

  auto
  PrintUnixDialog::property_embed_page_setup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "embed-page-setup");
  }

} // namespace Gtk
