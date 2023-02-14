// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/messagedialog.hxx>
#include <libmm-gtk/messagedialog_p.hxx>

#include <gtk/gtk.h>

#include <gtk/gtk.h>

namespace Gtk
{

  MessageDialog::MessageDialog (const Glib::ustring& message,
                                const bool use_markup,
                                const MessageType type,
                                const ButtonsType buttons,
                                const bool modal)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (messagedialog_class_.init (),
                                     "message_type",
                                     type,
                                     "buttons",
                                     buttons,
                                     nullptr))
  {
    set_modal (modal);
    set_message (message, use_markup);
  }

  MessageDialog::MessageDialog (Window& parent,
                                const Glib::ustring& message,
                                const bool use_markup,
                                const MessageType type,
                                const ButtonsType buttons,
                                const bool modal)
    : ObjectBase (nullptr),
      Dialog (Glib::ConstructParams (messagedialog_class_.init (),
                                     "message_type",
                                     type,
                                     "buttons",
                                     buttons,
                                     nullptr))
  {
    set_modal (modal);
    set_transient_for (parent);
    set_message (message, use_markup);
  }

  auto
  MessageDialog::set_message (const Glib::ustring& message,
                              const bool use_markup) -> void
  {
    if (use_markup)
      gtk_message_dialog_set_markup (gobj (), message.c_str ());
    else
    {
      property_use_markup () = false;
      property_text () = message;
    }
  }

  auto
  MessageDialog::set_secondary_text (const Glib::ustring& text,
                                     const bool use_markup) -> void
  {
    if (use_markup)
      gtk_message_dialog_format_secondary_markup (gobj (), "%s", text.c_str ());
    else
      gtk_message_dialog_format_secondary_text (gobj (), "%s", text.c_str ());
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::ButtonsType>::value_type () -> GType
{
  return gtk_buttons_type_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkMessageDialog* object, const bool take_copy) -> Gtk::MessageDialog*
  {
    return dynamic_cast<Gtk::MessageDialog*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MessageDialog_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MessageDialog_Class::class_init_function;

      register_derived_type (gtk_message_dialog_get_type ());
    }

    return *this;
  }

  auto
  MessageDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MessageDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new MessageDialog ((GtkMessageDialog*) o);
  }

  MessageDialog::MessageDialog (const Glib::ConstructParams& construct_params)
    : Dialog (construct_params)
  {
  }

  MessageDialog::MessageDialog (GtkMessageDialog* castitem)
    : Dialog ((GtkDialog*) castitem)
  {
  }

  MessageDialog::MessageDialog (MessageDialog&& src) noexcept
    : Dialog (std::move (src))
  {
  }

  auto
  MessageDialog::operator= (MessageDialog&& src) noexcept -> MessageDialog&
  {
    Dialog::operator= (std::move (src));
    return *this;
  }

  MessageDialog::~MessageDialog () noexcept
  {
    destroy_ ();
  }

  MessageDialog::CppClassType MessageDialog::messagedialog_class_;

  auto
  MessageDialog::get_type () -> GType
  {
    return messagedialog_class_.init ().get_type ();
  }

  auto
  MessageDialog::get_base_type () -> GType
  {
    return gtk_message_dialog_get_type ();
  }

  auto
  MessageDialog::get_message_area () -> Box*
  {
    return Glib::wrap ((GtkBox*) gtk_message_dialog_get_message_area (gobj ()));
  }

  auto
  MessageDialog::get_message_area () const -> const Box*
  {
    return const_cast<MessageDialog*> (this)->get_message_area ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<MessageType>::value,
      "Type MessageType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MessageDialog::property_message_type () -> Glib::PropertyProxy<MessageType>
  {
    return {this, "message-type"};
  }

  auto
  MessageDialog::property_message_type () const -> Glib::PropertyProxy_ReadOnly<MessageType>
  {
    return {this, "message-type"};
  }

  auto
  MessageDialog::property_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "text"};
  }

  auto
  MessageDialog::property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "text"};
  }

  auto
  MessageDialog::property_use_markup () -> Glib::PropertyProxy<bool>
  {
    return {this, "use-markup"};
  }

  auto
  MessageDialog::property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-markup"};
  }

  auto
  MessageDialog::property_secondary_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "secondary-text"};
  }

  auto
  MessageDialog::property_secondary_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "secondary-text"};
  }

  auto
  MessageDialog::property_secondary_use_markup () -> Glib::PropertyProxy<bool>
  {
    return {this, "secondary-use-markup"};
  }

  auto
  MessageDialog::property_secondary_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "secondary-use-markup"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Box*>::value,
      "Type Box* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MessageDialog::property_message_area () const -> Glib::PropertyProxy_ReadOnly<Box*>
  {
    return {this, "message-area"};
  }

} // namespace Gtk
