// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ALERTDIALOG_H
#define _GTKMM_ALERTDIALOG_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/object.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT AlertDialog_Class;
}
#endif

namespace Gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT AlertDialog : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AlertDialog;
    using CppClassType = AlertDialog_Class;
    using BaseObjectType = GtkAlertDialog;
    using BaseClassType = GtkAlertDialogClass;

    AlertDialog (const AlertDialog&) = delete;
    auto
    operator= (const AlertDialog&) -> AlertDialog& = delete;

  private:
    friend class AlertDialog_Class;
    static CppClassType alertdialog_class_;

  protected:
    explicit AlertDialog (const Glib::ConstructParams& construct_params);
    explicit AlertDialog (GtkAlertDialog* castitem);

#endif

  public:
    AlertDialog (AlertDialog&& src) noexcept;
    auto
    operator= (AlertDialog&& src) noexcept -> AlertDialog&;

    ~AlertDialog () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAlertDialog*
    {
      return reinterpret_cast<GtkAlertDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkAlertDialog*
    {
      return reinterpret_cast<GtkAlertDialog*> (gobject_);
    }

    auto
    gobj_copy () -> GtkAlertDialog*;

  private:
  protected:
    AlertDialog ();

    explicit AlertDialog (const Glib::ustring& message);

  public:
    static auto
    create () -> Glib::RefPtr<AlertDialog>;

    static auto
    create (const Glib::ustring& message) -> Glib::RefPtr<AlertDialog>;

    auto
    get_modal () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_message () const -> Glib::ustring;

    auto
    set_message (const Glib::ustring& message) -> void;

    auto
    get_detail () const -> Glib::ustring;

    auto
    set_detail (const Glib::ustring& detail) -> void;

    auto
    get_buttons () const -> std::vector<Glib::ustring>;

    auto
    set_buttons (const std::vector<Glib::ustring>& labels) const -> void;

    auto
    get_cancel_button () const -> int;

    auto
    set_cancel_button (int button) -> void;

    auto
    get_default_button () const -> int;

    auto
    set_default_button (int button) -> void;

    auto
    choose (Window& parent,
            const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose (const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    choose_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const -> int;

    auto
    show (Window& parent) -> void;

    auto
    show () -> void;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_message () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_message () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_detail () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_detail () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_buttons () -> Glib::PropertyProxy<std::vector<Glib::ustring>>;

    auto
    property_buttons () const
        -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>;

    auto
    property_cancel_button () -> Glib::PropertyProxy<int>;

    auto
    property_cancel_button () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_default_button () -> Glib::PropertyProxy<int>;

    auto
    property_default_button () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAlertDialog* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AlertDialog>;
} // namespace Glib

#endif
