


#include <libmm-glib/mm-glib.hpp>

#include <libmm-gtk/appchooserbutton.hpp>
#include <libmm-gtk/appchooserbutton_p.hpp>


/* Copyright 2011 The gtkmm Development Team
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


const Glib::SignalProxyInfo AppChooserButton_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


auto AppChooserButton_signal_custom_item_activated_callback (
  GtkAppChooserButton *self, const gchar *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::ustring&)>;

  const auto obj = dynamic_cast<AppChooserButton*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo AppChooserButton_signal_custom_item_activated_info =
{
  "custom-item-activated",
  (GCallback) &AppChooserButton_signal_custom_item_activated_callback,
  (GCallback) &AppChooserButton_signal_custom_item_activated_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkAppChooserButton* object, const bool take_copy) -> Gtk::AppChooserButton*
{
  return dynamic_cast<Gtk::AppChooserButton *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto AppChooserButton_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppChooserButton_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_app_chooser_button_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  AppChooser::add_interface(get_type());

  }

  return *this;
}


auto AppChooserButton_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AppChooserButton_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new AppChooserButton((GtkAppChooserButton*)o));

}


/* The implementation: */

AppChooserButton::AppChooserButton(const Glib::ConstructParams& construct_params)
:
  Widget(construct_params)
{
  }

AppChooserButton::AppChooserButton(GtkAppChooserButton* castitem)
:
  Widget((GtkWidget*)castitem)
{
  }


AppChooserButton::AppChooserButton(AppChooserButton&& src) noexcept
: Widget(std::move(src))
  , AppChooser(std::move(src))
{}

auto AppChooserButton::operator=(AppChooserButton&& src) noexcept -> AppChooserButton&
{
  Widget::operator=(std::move(src));
  AppChooser::operator=(std::move(src));
  return *this;
}

AppChooserButton::~AppChooserButton() noexcept
{
  destroy_();
}

AppChooserButton::CppClassType AppChooserButton::appchooserbutton_class_; // initialize static member

auto AppChooserButton::get_type() -> GType
{
  return appchooserbutton_class_.init().get_type();
}


auto AppChooserButton::get_base_type() -> GType
{
  return gtk_app_chooser_button_get_type();
}


AppChooserButton::AppChooserButton(const Glib::ustring& content_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(appchooserbutton_class_.init(), "content_type", content_type.c_str(), nullptr))
{


}

auto AppChooserButton::append_separator () -> void
{
  gtk_app_chooser_button_append_separator(gobj());
}

auto AppChooserButton::append_custom_item (
  const Glib::ustring &name, const Glib::ustring &label,
  const Glib::RefPtr <Gio::Icon> &icon) -> void
{
  gtk_app_chooser_button_append_custom_item(gobj(), name.c_str(), label.c_str(), Glib::unwrap<Gio::Icon>(icon));
}

auto AppChooserButton::set_active_custom_item (const Glib::ustring &name) -> void
{
  gtk_app_chooser_button_set_active_custom_item(gobj(), name.c_str());
}

auto AppChooserButton::set_show_dialog_item (
  const bool setting) -> void
{
  gtk_app_chooser_button_set_show_dialog_item(gobj(), setting);
}

auto AppChooserButton::get_show_dialog_item() const -> bool
{
  return gtk_app_chooser_button_get_show_dialog_item(const_cast<GtkAppChooserButton*>(gobj()));
}

auto AppChooserButton::set_heading (const Glib::ustring &heading) -> void
{
  gtk_app_chooser_button_set_heading(gobj(), heading.c_str());
}

auto AppChooserButton::get_heading() const -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_app_chooser_button_get_heading(const_cast<GtkAppChooserButton*>(gobj())));
}

auto AppChooserButton::set_show_default_item (
  const bool setting) -> void
{
  gtk_app_chooser_button_set_show_default_item(gobj(), setting);
}

auto AppChooserButton::get_show_default_item() const -> bool
{
  return gtk_app_chooser_button_get_show_default_item(const_cast<GtkAppChooserButton*>(gobj()));
}

auto AppChooserButton::set_modal (
  const bool modal) -> void
{
  gtk_app_chooser_button_set_modal(gobj(), modal);
}

auto AppChooserButton::get_modal() const -> bool
{
  return gtk_app_chooser_button_get_modal(const_cast<GtkAppChooserButton*>(gobj()));
}


auto AppChooserButton::signal_changed() -> Glib::SignalProxy<void()>
{
  return {this, &AppChooserButton_signal_changed_info};
}


auto AppChooserButton::signal_custom_item_activated(const Glib::ustring& custom_item_name) -> Glib::SignalProxyDetailed<void(const Glib::ustring&)>
{
  return Glib::SignalProxyDetailed<void(const Glib::ustring&)>(this, &AppChooserButton_signal_custom_item_activated_info, custom_item_name);
}


auto AppChooserButton::property_show_dialog_item() -> Glib::PropertyProxy< bool >
{
  return {this, "show-dialog-item"};
}

auto AppChooserButton::property_show_dialog_item() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-dialog-item"};
}

auto AppChooserButton::property_heading() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "heading"};
}

auto AppChooserButton::property_heading() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "heading"};
}

auto AppChooserButton::property_show_default_item() -> Glib::PropertyProxy< bool >
{
  return {this, "show-default-item"};
}

auto AppChooserButton::property_show_default_item() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-default-item"};
}

auto AppChooserButton::property_modal() -> Glib::PropertyProxy< bool >
{
  return {this, "modal"};
}

auto AppChooserButton::property_modal() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "modal"};
}


} // namespace Gtk


