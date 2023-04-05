// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/printunixdialog.hxx>
#include <libmm/gtk/printunixdialog_p.hxx>

#include <gtk/gtkunixprint.h>
#include <libmm/gtk/label.hxx>

namespace gtk
{

  PrintUnixDialog::PrintUnixDialog (gtk::Window& parent,
                                    const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (printunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
    set_transient_for (parent);
  }

  PrintUnixDialog::PrintUnixDialog (const glib::ustring& title)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (printunixdialog_class_.init (),
                                          "title",
                                          title.c_str (),
                                          nullptr))
  {
  }

  auto
  PrintUnixDialog::add_custom_tab (const Widget& child,
                                   const glib::ustring& tab_label) -> void
  {
    auto label = gtk::manage (new gtk::Label (tab_label));
    add_custom_tab (child, *label);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPrintUnixDialog* object, bool take_copy) -> gtk::PrintUnixDialog*
  {
    return dynamic_cast<gtk::PrintUnixDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  PrintUnixDialog_Class::init () -> const glib::Class&
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
  PrintUnixDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new PrintUnixDialog ((GtkPrintUnixDialog*) (o));
  }

  PrintUnixDialog::PrintUnixDialog (
      const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  PrintUnixDialog::PrintUnixDialog (GtkPrintUnixDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  PrintUnixDialog::PrintUnixDialog (PrintUnixDialog&& src) noexcept
    : gtk::Dialog (std::move (src))
  {
  }

  auto
  PrintUnixDialog::operator= (PrintUnixDialog&& src) noexcept -> PrintUnixDialog&
  {
    gtk::Dialog::operator= (std::move (src));
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
  PrintUnixDialog::set_page_setup (const glib::RefPtr<PageSetup>& page_setup) -> void
  {
    gtk_print_unix_dialog_set_page_setup (gobj (), glib::unwrap (page_setup));
  }

  auto
  PrintUnixDialog::get_page_setup () -> glib::RefPtr<PageSetup>
  {
    auto retvalue = glib::wrap (gtk_print_unix_dialog_get_page_setup (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_page_setup () const -> glib::RefPtr<const PageSetup>
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
  PrintUnixDialog::set_settings (const glib::RefPtr<PrintSettings>& settings) -> void
  {
    gtk_print_unix_dialog_set_settings (gobj (), glib::unwrap (settings));
  }

  auto
  PrintUnixDialog::get_settings () -> glib::RefPtr<PrintSettings>
  {
    auto retvalue = glib::wrap (gtk_print_unix_dialog_get_settings (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_settings () const -> glib::RefPtr<const PrintSettings>
  {
    return const_cast<PrintUnixDialog*> (this)->get_settings ();
  }

  auto
  PrintUnixDialog::get_selected_printer () -> glib::RefPtr<Printer>
  {
    auto retvalue =
        glib::wrap (gtk_print_unix_dialog_get_selected_printer (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PrintUnixDialog::get_selected_printer () const -> glib::RefPtr<const Printer>
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PageSetup>>::value,
      "Type glib::RefPtr<PageSetup> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintUnixDialog::property_page_setup () -> glib::PropertyProxy<glib::RefPtr<PageSetup>>
  {
    return glib::PropertyProxy<glib::RefPtr<PageSetup>> (this, "page-setup");
  }

  auto
  PrintUnixDialog::property_page_setup () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PageSetup>> (this,
                                                                  "page-setup");
  }

  auto
  PrintUnixDialog::property_current_page () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "current-page");
  }

  auto
  PrintUnixDialog::property_current_page () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "current-page");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<PrintSettings>>::value,
      "Type glib::RefPtr<PrintSettings> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintUnixDialog::property_print_settings () -> glib::PropertyProxy<glib::RefPtr<PrintSettings>>
  {
    return glib::PropertyProxy<glib::RefPtr<PrintSettings>> (this,
                                                             "print-settings");
  }

  auto
  PrintUnixDialog::property_print_settings () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<PrintSettings>> (
        this,
        "print-settings");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<Printer>>::value,
      "Type glib::RefPtr<Printer> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PrintUnixDialog::property_selected_printer () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Printer>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<Printer>> (
        this,
        "selected-printer");
  }

  auto
  PrintUnixDialog::property_manual_capabilities () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "manual-capabilities");
  }

  auto
  PrintUnixDialog::property_manual_capabilities () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "manual-capabilities");
  }

  auto
  PrintUnixDialog::property_support_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "support-selection");
  }

  auto
  PrintUnixDialog::property_support_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "support-selection");
  }

  auto
  PrintUnixDialog::property_has_selection () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "has-selection");
  }

  auto
  PrintUnixDialog::property_has_selection () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "has-selection");
  }

  auto
  PrintUnixDialog::property_embed_page_setup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "embed-page-setup");
  }

  auto
  PrintUnixDialog::property_embed_page_setup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "embed-page-setup");
  }

} // namespace gtk
