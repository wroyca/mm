// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/messagedialog.hxx>
  #include <libmm/gtk/messagedialog_p.hxx>

  #include <gtk/gtk.h>

  #include <gtk/gtk.h>

namespace gtk
{

  MessageDialog::MessageDialog (const glib::ustring& message,
                                bool use_markup,
                                MessageType type,
                                ButtonsType buttons,
                                bool modal)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (messagedialog_class_.init (),
                                          "message_type",
                                          (GtkMessageType) type,
                                          "buttons",
                                          (GtkButtonsType) buttons,
                                          nullptr))
  {
    set_modal (modal);
    set_message (message, use_markup);
  }

  MessageDialog::MessageDialog (gtk::Window& parent,
                                const glib::ustring& message,
                                bool use_markup,
                                MessageType type,
                                ButtonsType buttons,
                                bool modal)
    : glib::ObjectBase (nullptr),
      gtk::Dialog (glib::ConstructParams (messagedialog_class_.init (),
                                          "message_type",
                                          (GtkMessageType) type,
                                          "buttons",
                                          (GtkButtonsType) buttons,
                                          nullptr))
  {
    set_modal (modal);
    set_transient_for (parent);
    set_message (message, use_markup);
  }

  auto
  MessageDialog::set_message (const glib::ustring& message, bool use_markup) -> void
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
  MessageDialog::set_secondary_text (const glib::ustring& text, bool use_markup) -> void
  {
    if (use_markup)
      gtk_message_dialog_format_secondary_markup (gobj (), "%s", text.c_str ());
    else
      gtk_message_dialog_format_secondary_text (gobj (), "%s", text.c_str ());
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::ButtonsType>::value_type () -> GType
{
  return gtk_buttons_type_get_type ();
}

namespace glib
{

  auto
  wrap (GtkMessageDialog* object, bool take_copy) -> gtk::MessageDialog*
  {
    return dynamic_cast<gtk::MessageDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  MessageDialog_Class::init () -> const glib::Class&
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
  MessageDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new MessageDialog ((GtkMessageDialog*) (o));
  }

  MessageDialog::MessageDialog (const glib::ConstructParams& construct_params)
    : gtk::Dialog (construct_params)
  {
  }

  MessageDialog::MessageDialog (GtkMessageDialog* castitem)
    : gtk::Dialog ((GtkDialog*) (castitem))
  {
  }

  MessageDialog::MessageDialog (MessageDialog&& src) noexcept
    : gtk::Dialog (std::move (src))
  {
  }

  auto
  MessageDialog::operator= (MessageDialog&& src) noexcept -> MessageDialog&
  {
    gtk::Dialog::operator= (std::move (src));
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
    return glib::wrap (
        (GtkBox*) (gtk_message_dialog_get_message_area (gobj ())));
  }

  auto
  MessageDialog::get_message_area () const -> const Box*
  {
    return const_cast<MessageDialog*> (this)->get_message_area ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<MessageType>::value,
      "Type MessageType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MessageDialog::property_message_type () -> glib::PropertyProxy<MessageType>
  {
    return glib::PropertyProxy<MessageType> (this, "message-type");
  }

  auto
  MessageDialog::property_message_type () const -> glib::PropertyProxy_ReadOnly<MessageType>
  {
    return glib::PropertyProxy_ReadOnly<MessageType> (this, "message-type");
  }

  auto
  MessageDialog::property_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "text");
  }

  auto
  MessageDialog::property_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "text");
  }

  auto
  MessageDialog::property_use_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-markup");
  }

  auto
  MessageDialog::property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-markup");
  }

  auto
  MessageDialog::property_secondary_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "secondary-text");
  }

  auto
  MessageDialog::property_secondary_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "secondary-text");
  }

  auto
  MessageDialog::property_secondary_use_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "secondary-use-markup");
  }

  auto
  MessageDialog::property_secondary_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "secondary-use-markup");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Box*>::value,
      "Type Box* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  MessageDialog::property_message_area () const -> glib::PropertyProxy_ReadOnly<Box*>
  {
    return glib::PropertyProxy_ReadOnly<Box*> (this, "message-area");
  }

} // namespace gtk

#endif
