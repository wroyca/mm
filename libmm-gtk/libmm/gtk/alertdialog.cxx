// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/alertdialog.hxx>
#include <libmm/gtk/alertdialog_p.hxx>

#include <libmm/gio/slot_async.hxx>
#include <libmm/gtk/window.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkAlertDialog* object, bool take_copy) -> glib::RefPtr<gtk::AlertDialog>
  {
    return glib::make_refptr_for_instance<gtk::AlertDialog> (
        dynamic_cast<gtk::AlertDialog*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  AlertDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = gtk_alert_dialog_get_type ();
    }

    return *this;
  }

  auto
  AlertDialog_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new AlertDialog ((GtkAlertDialog*) object);
  }

  auto
  AlertDialog::gobj_copy () -> GtkAlertDialog*
  {
    reference ();
    return gobj ();
  }

  AlertDialog::AlertDialog (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  AlertDialog::AlertDialog (GtkAlertDialog* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  AlertDialog::AlertDialog (AlertDialog&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  AlertDialog::operator= (AlertDialog&& src) noexcept -> AlertDialog&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (alertdialog_class_.init ()))
  {
  }

  AlertDialog::AlertDialog (const glib::ustring& message)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (alertdialog_class_.init (),
                                           "message",
                                           message.c_str (),
                                           nullptr))
  {
  }

  auto
  AlertDialog::create () -> glib::RefPtr<AlertDialog>
  {
    return glib::make_refptr_for_instance<AlertDialog> (new AlertDialog ());
  }

  auto
  AlertDialog::create (const glib::ustring& message) -> glib::RefPtr<AlertDialog>
  {
    return glib::make_refptr_for_instance<AlertDialog> (
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
  AlertDialog::get_message () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_alert_dialog_get_message (const_cast<GtkAlertDialog*> (gobj ())));
  }

  auto
  AlertDialog::set_message (const glib::ustring& message) -> void
  {
    gtk_alert_dialog_set_message (gobj (), message.c_str ());
  }

  auto
  AlertDialog::get_detail () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_alert_dialog_get_detail (const_cast<GtkAlertDialog*> (gobj ())));
  }

  auto
  AlertDialog::set_detail (const glib::ustring& detail) -> void
  {
    gtk_alert_dialog_set_detail (gobj (), detail.c_str ());
  }

  auto
  AlertDialog::get_buttons () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gtk_alert_dialog_get_buttons (const_cast<GtkAlertDialog*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  auto
  AlertDialog::set_buttons (const std::vector<glib::ustring>& labels) const -> void
  {
    gtk_alert_dialog_set_buttons (
        const_cast<GtkAlertDialog*> (gobj ()),
        glib::ArrayHandler<glib::ustring>::vector_to_array (labels).data ());
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
                       const gio::SlotAsyncReady& slot,
                       const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_alert_dialog_choose (
        const_cast<GtkAlertDialog*> (gobj ()),
        (parent).gobj (),
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  AlertDialog::choose (const gio::SlotAsyncReady& slot,
                       const glib::RefPtr<gio::Cancellable>& cancellable) const -> void
  {
    auto slot_copy = new gio::SlotAsyncReady (slot);

    gtk_alert_dialog_choose (
        const_cast<GtkAlertDialog*> (gobj ()),
        nullptr,
        const_cast<GCancellable*> (glib::unwrap (cancellable)),
        &gio::SignalProxy_async_callback,
        slot_copy);
  }

  auto
  AlertDialog::choose_finish (
      const glib::RefPtr<gio::AsyncResult>& result) const -> int
  {
    GError* gerror = nullptr;
    auto retvalue = gtk_alert_dialog_choose_finish (
        const_cast<GtkAlertDialog*> (gobj ()),
        glib::unwrap (result),
        &(gerror));
    if (gerror)
      ::glib::Error::throw_exception (gerror);
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
  AlertDialog::property_modal () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "modal");
  }

  auto
  AlertDialog::property_modal () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "modal");
  }

  auto
  AlertDialog::property_message () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "message");
  }

  auto
  AlertDialog::property_message () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "message");
  }

  auto
  AlertDialog::property_detail () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "detail");
  }

  auto
  AlertDialog::property_detail () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "detail");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          std::vector<glib::ustring>>::value,
      "Type std::vector<glib::ustring> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  AlertDialog::property_buttons () -> glib::PropertyProxy<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy<std::vector<glib::ustring>> (this, "buttons");
  }

  auto
  AlertDialog::property_buttons () const -> glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>>
  {
    return glib::PropertyProxy_ReadOnly<std::vector<glib::ustring>> (this,
                                                                     "buttons");
  }

  auto
  AlertDialog::property_cancel_button () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "cancel-button");
  }

  auto
  AlertDialog::property_cancel_button () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "cancel-button");
  }

  auto
  AlertDialog::property_default_button () -> glib::PropertyProxy<int>
  {
    return glib::PropertyProxy<int> (this, "default-button");
  }

  auto
  AlertDialog::property_default_button () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return glib::PropertyProxy_ReadOnly<int> (this, "default-button");
  }

} // namespace gtk
