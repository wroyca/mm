


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/appchooserwidget.hxx>
#include <libmm-gtk/appchooserwidget_p.hxx>


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


auto AppChooserWidget_signal_application_selected_callback (
  GtkAppChooserWidget *self, GAppInfo *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::AppInfo>&)>;

  const auto obj = dynamic_cast<AppChooserWidget*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo AppChooserWidget_signal_application_selected_info =
{
  "application-selected",
  (GCallback) &AppChooserWidget_signal_application_selected_callback,
  (GCallback) &AppChooserWidget_signal_application_selected_callback
};


auto AppChooserWidget_signal_application_activated_callback (
  GtkAppChooserWidget *self, GAppInfo *p0, void *data) -> void
{
  using namespace Gtk;
  using SlotType = sigc::slot<void(const Glib::RefPtr<Gio::AppInfo>&)>;

  const auto obj = dynamic_cast<AppChooserWidget*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo AppChooserWidget_signal_application_activated_info =
{
  "application-activated",
  (GCallback) &AppChooserWidget_signal_application_activated_callback,
  (GCallback) &AppChooserWidget_signal_application_activated_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GtkAppChooserWidget* object, const bool take_copy) -> Gtk::AppChooserWidget*
{
  return dynamic_cast<Gtk::AppChooserWidget *> (wrap_auto((GObject*)object, take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

auto AppChooserWidget_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppChooserWidget_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_app_chooser_widget_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  AppChooser::add_interface(get_type());

  }

  return *this;
}


auto AppChooserWidget_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto AppChooserWidget_Class::wrap_new(GObject* o) -> Glib::ObjectBase*
{
  return manage(new AppChooserWidget((GtkAppChooserWidget*)o));

}


/* The implementation: */

AppChooserWidget::AppChooserWidget(const Glib::ConstructParams& construct_params)
:
  Widget(construct_params)
{
  }

AppChooserWidget::AppChooserWidget(GtkAppChooserWidget* castitem)
:
  Widget((GtkWidget*)castitem)
{
  }


AppChooserWidget::AppChooserWidget(AppChooserWidget&& src) noexcept
: Widget(std::move(src))
  , AppChooser(std::move(src))
{}

auto AppChooserWidget::operator=(AppChooserWidget&& src) noexcept -> AppChooserWidget&
{
  Widget::operator=(std::move(src));
  AppChooser::operator=(std::move(src));
  return *this;
}

AppChooserWidget::~AppChooserWidget() noexcept
{
  destroy_();
}

AppChooserWidget::CppClassType AppChooserWidget::appchooserwidget_class_; // initialize static member

auto AppChooserWidget::get_type() -> GType
{
  return appchooserwidget_class_.init().get_type();
}


auto AppChooserWidget::get_base_type() -> GType
{
  return gtk_app_chooser_widget_get_type();
}


AppChooserWidget::AppChooserWidget(const Glib::ustring& content_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
  Widget(Glib::ConstructParams(appchooserwidget_class_.init(), "content_type", content_type.c_str(), nullptr))
{


}

auto AppChooserWidget::set_show_default (
  const bool setting) -> void
{
  gtk_app_chooser_widget_set_show_default(gobj(), setting);
}

auto AppChooserWidget::get_show_default() -> bool
{
  return gtk_app_chooser_widget_get_show_default(gobj());
}

auto AppChooserWidget::set_show_recommended (
  const bool setting) -> void
{
  gtk_app_chooser_widget_set_show_recommended(gobj(), setting);
}

auto AppChooserWidget::get_show_recommended() const -> bool
{
  return gtk_app_chooser_widget_get_show_recommended(const_cast<GtkAppChooserWidget*>(gobj()));
}

auto AppChooserWidget::set_show_fallback (
  const bool setting) -> void
{
  gtk_app_chooser_widget_set_show_fallback(gobj(), setting);
}

auto AppChooserWidget::get_show_fallback() const -> bool
{
  return gtk_app_chooser_widget_get_show_fallback(const_cast<GtkAppChooserWidget*>(gobj()));
}

auto AppChooserWidget::set_show_other (
  const bool setting) -> void
{
  gtk_app_chooser_widget_set_show_other(gobj(), setting);
}

auto AppChooserWidget::get_show_other() const -> bool
{
  return gtk_app_chooser_widget_get_show_other(const_cast<GtkAppChooserWidget*>(gobj()));
}

auto AppChooserWidget::set_show_all (
  const bool setting) -> void
{
  gtk_app_chooser_widget_set_show_all(gobj(), setting);
}

auto AppChooserWidget::get_show_all() const -> bool
{
  return gtk_app_chooser_widget_get_show_all(const_cast<GtkAppChooserWidget*>(gobj()));
}

auto AppChooserWidget::set_default_text (const Glib::ustring &text) -> void
{
  gtk_app_chooser_widget_set_default_text(gobj(), text.c_str());
}

auto AppChooserWidget::get_default_text() -> Glib::ustring
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_app_chooser_widget_get_default_text(gobj()));
}


auto AppChooserWidget::signal_application_selected() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::AppInfo>&)>
{
  return {this, &AppChooserWidget_signal_application_selected_info};
}


auto AppChooserWidget::signal_application_activated() -> Glib::SignalProxy<void(const Glib::RefPtr<Gio::AppInfo>&)>
{
  return {this, &AppChooserWidget_signal_application_activated_info};
}


auto AppChooserWidget::property_show_default() -> Glib::PropertyProxy< bool >
{
  return {this, "show-default"};
}

auto AppChooserWidget::property_show_default() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-default"};
}

auto AppChooserWidget::property_show_recommended() -> Glib::PropertyProxy< bool >
{
  return {this, "show-recommended"};
}

auto AppChooserWidget::property_show_recommended() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-recommended"};
}

auto AppChooserWidget::property_show_fallback() -> Glib::PropertyProxy< bool >
{
  return {this, "show-fallback"};
}

auto AppChooserWidget::property_show_fallback() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-fallback"};
}

auto AppChooserWidget::property_show_other() -> Glib::PropertyProxy< bool >
{
  return {this, "show-other"};
}

auto AppChooserWidget::property_show_other() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-other"};
}

auto AppChooserWidget::property_show_all() -> Glib::PropertyProxy< bool >
{
  return {this, "show-all"};
}

auto AppChooserWidget::property_show_all() const -> Glib::PropertyProxy_ReadOnly< bool >
{
  return {this, "show-all"};
}

auto AppChooserWidget::property_default_text() -> Glib::PropertyProxy< Glib::ustring >
{
  return {this, "default-text"};
}

auto AppChooserWidget::property_default_text() const -> Glib::PropertyProxy_ReadOnly< Glib::ustring >
{
  return {this, "default-text"};
}


} // namespace Gtk


