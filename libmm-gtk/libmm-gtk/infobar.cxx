


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/infobar.hxx>
#include <libmm-gtk/infobar_p.hxx>


/*
 * Copyright 2009 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <gtk/gtk.h>

namespace Gtk
{

} // namespace Gtk


namespace
{


auto InfoBar_signal_response_callback (GtkInfoBar *self, const gint p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(int)>;

  const auto obj = dynamic_cast<InfoBar*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo InfoBar_signal_response_info =
{
  "response",
  (GCallback) &InfoBar_signal_response_callback,
  (GCallback) &InfoBar_signal_response_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkInfoBar* object, const bool take_copy) -> Gtk::InfoBar*
{
  return dynamic_cast<Gtk::InfoBar *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto InfoBar_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &InfoBar_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_info_bar_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto InfoBar_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto InfoBar_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new InfoBar((GtkInfoBar*)o));

}


/* The implementation: */

InfoBar::InfoBar(const Glib::ConstructParams& construct_params)
: Widget(construct_params)
{
  }

InfoBar::InfoBar(GtkInfoBar* castitem)
: Widget((GtkWidget*)castitem)
{
  }


InfoBar::InfoBar(InfoBar&& src) noexcept
: Widget(std::move(src))
{}

auto InfoBar::operator=(InfoBar&& src) noexcept -> InfoBar&
{
  Widget::operator=(std::move(src));
  return *this;
}

InfoBar::~InfoBar() noexcept
{
  destroy_();
}

InfoBar::CppClassType InfoBar::infobar_class_; // initialize static member

auto InfoBar::get_type() -> GType
{
  return infobar_class_.init().get_type();
}


auto InfoBar::get_base_type() -> GType
{
  return gtk_info_bar_get_type();
}


InfoBar::InfoBar()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Widget(Glib::ConstructParams(infobar_class_.init()))
{


}

auto InfoBar::add_action_widget (Widget &child, const int response_id) -> void
{
  gtk_info_bar_add_action_widget(gobj(), child.gobj(), response_id);
}

auto InfoBar::remove_action_widget (Widget &widget) -> void
{
  gtk_info_bar_remove_action_widget(gobj(), widget.gobj());
}

auto InfoBar::add_button(const Glib::ustring& button_text, const int response_id) -> Button*
{
  return Glib::wrap((GtkButton*)gtk_info_bar_add_button(gobj(), button_text.c_str(), response_id));
}

auto InfoBar::add_child (Widget &widget) -> void
{
  gtk_info_bar_add_child(gobj(), widget.gobj());
}

auto InfoBar::remove_child (Widget &widget) -> void
{
  gtk_info_bar_remove_child(gobj(), widget.gobj());
}

auto InfoBar::set_response_sensitive (
  const int response_id, const bool setting) -> void
{
  gtk_info_bar_set_response_sensitive(gobj(), response_id, setting);
}

auto InfoBar::set_default_response (
  const int response_id) -> void
{
  gtk_info_bar_set_default_response(gobj(), response_id);
}

auto InfoBar::response (
  const int response_id) -> void
{
  gtk_info_bar_response(gobj(), response_id);
}

auto InfoBar::set_message_type (MessageType message_type) -> void
{
  gtk_info_bar_set_message_type(gobj(), static_cast<GtkMessageType>(message_type));
}

auto InfoBar::get_message_type() const -> MessageType
{
  return static_cast<MessageType>(gtk_info_bar_get_message_type(const_cast<GtkInfoBar*>(gobj())));
}

auto InfoBar::set_show_close_button (
  const bool setting) -> void
{
  gtk_info_bar_set_show_close_button(gobj(), setting);
}

auto InfoBar::get_show_close_button() const -> bool
{
  return gtk_info_bar_get_show_close_button(const_cast<GtkInfoBar*>(gobj()));
}

auto InfoBar::set_revealed (
  const bool revealed) -> void
{
  gtk_info_bar_set_revealed(gobj(), revealed);
}

auto InfoBar::get_revealed() const -> bool
{
  return gtk_info_bar_get_revealed(const_cast<GtkInfoBar*>(gobj()));
}


auto InfoBar::signal_response() -> Glib::SignalProxy<void(int)>
{
  return {this, &InfoBar_signal_response_info};
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<MessageType>::value,
  "Type MessageType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto InfoBar::property_message_type() -> Glib::PropertyProxy< MessageType >
{
  return {this, "message-type"};
}

auto InfoBar::property_message_type() const -> Glib::PropertyProxy_ReadOnly< MessageType >
{
  return {this, "message-type"};
}

auto InfoBar::property_show_close_button() -> Glib::PropertyProxy< bool >
{
  return {this, "show-close-button"};
}

auto InfoBar::property_show_close_button() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-close-button"};
}

auto InfoBar::property_revealed() -> Glib::PropertyProxy< bool >
{
  return {this, "revealed"};
}

auto InfoBar::property_revealed() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "revealed"};
}


} // namespace Gtk

