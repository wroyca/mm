// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/infobar.hxx>
  #include <libmm/gtk/infobar_p.hxx>

  #include <gtk/gtk.h>

namespace gtk
{

}

namespace
{

  static auto
  InfoBar_signal_response_callback (GtkInfoBar* self, gint p0, void* data) -> void
  {
    using namespace gtk;
    using SlotType = sigc::slot<void (int)>;

    auto obj = dynamic_cast<InfoBar*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo InfoBar_signal_response_info = {
      "response",
      (GCallback) &InfoBar_signal_response_callback,
      (GCallback) &InfoBar_signal_response_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkInfoBar* object, bool take_copy) -> gtk::InfoBar*
  {
    return dynamic_cast<gtk::InfoBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  InfoBar_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &InfoBar_Class::class_init_function;

      register_derived_type (gtk_info_bar_get_type ());
    }

    return *this;
  }

  auto
  InfoBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  InfoBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new InfoBar ((GtkInfoBar*) (o)));
  }

  InfoBar::InfoBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  InfoBar::InfoBar (GtkInfoBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  InfoBar::InfoBar (InfoBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  InfoBar::operator= (InfoBar&& src) noexcept -> InfoBar&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  InfoBar::~InfoBar () noexcept
  {
    destroy_ ();
  }

  InfoBar::CppClassType InfoBar::infobar_class_;

  auto
  InfoBar::get_type () -> GType
  {
    return infobar_class_.init ().get_type ();
  }

  auto
  InfoBar::get_base_type () -> GType
  {
    return gtk_info_bar_get_type ();
  }

  InfoBar::InfoBar ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (infobar_class_.init ()))
  {
  }

  auto
  InfoBar::add_action_widget (Widget& child, int response_id) -> void
  {
    gtk_info_bar_add_action_widget (gobj (), (child).gobj (), response_id);
  }

  auto
  InfoBar::remove_action_widget (Widget& widget) -> void
  {
    gtk_info_bar_remove_action_widget (gobj (), (widget).gobj ());
  }

  auto
  InfoBar::add_button (const glib::ustring& button_text, int response_id) -> Button*
  {
    return glib::wrap (
        (GtkButton*) (gtk_info_bar_add_button (gobj (),
                                               button_text.c_str (),
                                               response_id)));
  }

  auto
  InfoBar::add_child (Widget& widget) -> void
  {
    gtk_info_bar_add_child (gobj (), (widget).gobj ());
  }

  auto
  InfoBar::remove_child (Widget& widget) -> void
  {
    gtk_info_bar_remove_child (gobj (), (widget).gobj ());
  }

  auto
  InfoBar::set_response_sensitive (int response_id, bool setting) -> void
  {
    gtk_info_bar_set_response_sensitive (gobj (),
                                         response_id,
                                         static_cast<int> (setting));
  }

  auto
  InfoBar::set_default_response (int response_id) -> void
  {
    gtk_info_bar_set_default_response (gobj (), response_id);
  }

  auto
  InfoBar::response (int response_id) -> void
  {
    gtk_info_bar_response (gobj (), response_id);
  }

  auto
  InfoBar::set_message_type (MessageType message_type) -> void
  {
    gtk_info_bar_set_message_type (gobj (),
                                   static_cast<GtkMessageType> (message_type));
  }

  auto
  InfoBar::get_message_type () const -> MessageType
  {
    return static_cast<MessageType> (
        gtk_info_bar_get_message_type (const_cast<GtkInfoBar*> (gobj ())));
  }

  auto
  InfoBar::set_show_close_button (bool setting) -> void
  {
    gtk_info_bar_set_show_close_button (gobj (), static_cast<int> (setting));
  }

  auto
  InfoBar::get_show_close_button () const -> bool
  {
    return gtk_info_bar_get_show_close_button (
        const_cast<GtkInfoBar*> (gobj ()));
  }

  auto
  InfoBar::set_revealed (bool revealed) -> void
  {
    gtk_info_bar_set_revealed (gobj (), static_cast<int> (revealed));
  }

  auto
  InfoBar::get_revealed () const -> bool
  {
    return gtk_info_bar_get_revealed (const_cast<GtkInfoBar*> (gobj ()));
  }

  auto
  InfoBar::signal_response () -> glib::SignalProxy<void (int)>
  {
    return glib::SignalProxy<void (int)> (this, &InfoBar_signal_response_info);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<MessageType>::value,
      "Type MessageType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  InfoBar::property_message_type () -> glib::PropertyProxy<MessageType>
  {
    return glib::PropertyProxy<MessageType> (this, "message-type");
  }

  auto
  InfoBar::property_message_type () const -> glib::PropertyProxy_ReadOnly<MessageType>
  {
    return glib::PropertyProxy_ReadOnly<MessageType> (this, "message-type");
  }

  auto
  InfoBar::property_show_close_button () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-close-button");
  }

  auto
  InfoBar::property_show_close_button () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-close-button");
  }

  auto
  InfoBar::property_revealed () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "revealed");
  }

  auto
  InfoBar::property_revealed () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "revealed");
  }

} // namespace gtk

#endif
