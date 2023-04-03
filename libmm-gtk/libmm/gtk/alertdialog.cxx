// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/alertdialog.hxx>
#include <libmm/gtk/alertdialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkAlertDialog* object, bool take_copy) -> Glib::RefPtr<Gtk::AlertDialog>
  {
    return Glib::make_refptr_for_instance<Gtk::AlertDialog> (
        dynamic_cast<Gtk::AlertDialog*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AlertDialog_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_alert_dialog_get_type ();
    }

    return *this;
  }

  auto
  AlertDialog_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new AlertDialog ((GtkAlertDialog*) object);
  }

  auto
  AlertDialog::gobj_copy () -> GtkAlertDialog*
  {
    reference ();
    return gobj ();
  }

  AlertDialog::AlertDialog (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  AlertDialog::AlertDialog (GtkAlertDialog* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  AlertDialog::AlertDialog (AlertDialog&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  AlertDialog::operator= (AlertDialog&& src) noexcept -> AlertDialog&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  AlertDialog::~AlertDialog () noexcept {}

  AlertDialog::CppClassType AlertDialog::alertdialog_class_;

  auto
  AlertDialog::get_type () -> GType
  {
    return alertdialog_class_.init ().get_type ();
  }

  auto
  AlertDialog::get_base_type () -> GType
  {
    return gtk_alert_dialog_get_type ();
  }

  AlertDialog::AlertDialog ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (alertdialog_class_.init ()))
  {
  }

  AlertDialog::AlertDialog (const Glib::ustring& message)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (alertdialog_class_.init (),
                                           "message",
                                           message.c_str (),
                                           nullptr))
  {
  }

  auto
  AlertDialog::create () -> Glib::RefPtr<AlertDialog>
  {
    return Glib::make_refptr_for_instance<AlertDialog> (new AlertDialog ());
  }

  auto
  AlertDialog::create (const Glib::ustring& message) -> Glib::RefPtr<AlertDialog>
  {
    return Glib::make_refptr_for_instance<AlertDialog> (
        new AlertDialog (message));
  }

  auto
  AlertDialog::get_modal () const -> bool
  {
    return gtk_alert_dialog_get_modal (const_cast<GtkAlertDialog*> (gobj ()));
  }

  auto
  AlertDialog::set_modal (bool modal) -> void
  {
    gtk_alert_dialog_set_modal (gobj (), static_cast<int> (modal));
  }

  auto
  AlertDialog::get_message () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_alert_dialog_get_message (const_cast<GtkAlertDialog*> (gobj ())));
  }

  auto
  AlertDialog::set_message (const Glib::ustring& message) -> void
  {
    gtk_alert_dialog_set_message (gobj (), message.c_str ());
  }

  auto
  AlertDialog::get_detail () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_alert_dialog_get_detail (const_cast<GtkAlertDialog*> (gobj ())));
  }

  auto
  AlertDialog::set_detail (const Glib::ustring& detail) -> void
  {
    gtk_alert_dialog_set_detail (gobj (), detail.c_str ());
  }

  auto
  AlertDialog::get_buttons () const -> std::vector<Glib::ustring>
  {
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        gtk_alert_dialog_get_buttons (const_cast<GtkAlertDialog*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  auto
  AlertDialog::set_buttons (const std::vector<Glib::ustring>& labels) const -> void
  {
    gtk_alert_dialog_set_buttons (
        const_cast<GtkAlertDialog*> (gobj ()),
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (labels).data ());
  }

  auto
  AlertDialog::get_cancel_button () const -> int
  {
    return gtk_alert_dialog_get_cancel_button (
        const_cast<GtkAlertDialog*> (gobj ()));
  }

  auto
  AlertDialog::set_cancel_button (int button) -> void
  {
    gtk_alert_dialog_set_cancel_button (gobj (), button);
  }

  auto
  AlertDialog::get_default_button () const -> int
  {
    return gtk_alert_dialog_get_default_button (
        const_cast<GtkAlertDialog*> (gobj ()));
  }

  auto
  AlertDialog::set_default_button (int button) -> void
  {
    gtk_alert_dialog_set_default_button (gobj (), button);
  }

  auto
  AlertDialog::choose (Window& parent,
                       const Gio::SlotAsyncReady& slot,
                       const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_alert_dialog_choose (
        const_cast<GtkAlertDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  AlertDialog::choose (const Gio::SlotAsyncReady& slot,
                       const Glib::RefPtr<Gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new Gio::SlotAsyncReady (slot);

    gtk_alert_dialog_choose (
        const_cast<GtkAlertDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (Glib::unwrap (cancellable)),
        &Gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  AlertDialog::choose_finish (
      const Glib::RefPtr<Gio::AsyncResult>& result) const -> int
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_alert_dialog_choose_finish (
        const_cast<GtkAlertDialog*> (gobj ()),
        Glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  AlertDialog::show (Window& parent) -> void
  {
    gtk_alert_dialog_show (gobj (), (parent).gobj ());
  }

  auto
  AlertDialog::show () -> void
  {
    gtk_alert_dialog_show (gobj (), nullptr);
  }

  auto
  AlertDialog::property_modal () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  AlertDialog::property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  AlertDialog::property_message () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "message");
  }

  auto
  AlertDialog::property_message () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "message");
  }

  auto
  AlertDialog::property_detail () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "detail");
  }

  auto
  AlertDialog::property_detail () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "detail");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<Glib::ustring>>::value,
      "Type std::vector<Glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  AlertDialog::property_buttons () -> Glib::PropertyProxy<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy<std::vector<Glib::ustring>> (this, "buttons");
  }

  auto
  AlertDialog::property_buttons () const -> Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>>
  {
    return Glib::PropertyProxy_ReadOnly<std::vector<Glib::ustring>> (this,
                                                                     "buttons");
  }

  auto
  AlertDialog::property_cancel_button () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "cancel-button");
  }

  auto
  AlertDialog::property_cancel_button () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "cancel-button");
  }

  auto
  AlertDialog::property_default_button () -> Glib::PropertyProxy<int>
  {
    return Glib::PropertyProxy<int> (this, "default-button");
  }

  auto
  AlertDialog::property_default_button () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return Glib::PropertyProxy_ReadOnly<int> (this, "default-button");
  }

} // namespace Gtk
