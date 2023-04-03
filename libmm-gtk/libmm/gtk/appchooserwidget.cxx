// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/appchooserwidget.hxx>
  #include <libmm/gtk/appchooserwidget_p.hxx>

  #include <gtk/gtk.h>

namespace Gtk
{

}

namespace
{

  static auto
  AppChooserWidget_signal_application_selected_callback (
      GtkAppChooserWidget* self,
      GAppInfo* p0,
      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Gio::AppInfo>&)>;

    auto obj = dynamic_cast<AppChooserWidget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      AppChooserWidget_signal_application_selected_info = {
          "application-selected",
          (GCallback) &AppChooserWidget_signal_application_selected_callback,
          (GCallback) &AppChooserWidget_signal_application_selected_callback};

  static auto
  AppChooserWidget_signal_application_activated_callback (
      GtkAppChooserWidget* self,
      GAppInfo* p0,
      void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (const Glib::RefPtr<Gio::AppInfo>&)>;

    auto obj = dynamic_cast<AppChooserWidget*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (Glib::wrap (p0, true));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      AppChooserWidget_signal_application_activated_info = {
          "application-activated",
          (GCallback) &AppChooserWidget_signal_application_activated_callback,
          (GCallback) &AppChooserWidget_signal_application_activated_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkAppChooserWidget* object, bool take_copy) -> Gtk::AppChooserWidget*
  {
    return dynamic_cast<Gtk::AppChooserWidget*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  AppChooserWidget_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &AppChooserWidget_Class::class_init_function;

      register_derived_type (gtk_app_chooser_widget_get_type ());

      AppChooser::add_interface (get_type ());
    }

    return *this;
  }

  auto
  AppChooserWidget_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  AppChooserWidget_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new AppChooserWidget ((GtkAppChooserWidget*) (o)));
  }

  AppChooserWidget::AppChooserWidget (
      const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  AppChooserWidget::AppChooserWidget (GtkAppChooserWidget* castitem)
    : Widget ((GtkWidget*) (castitem))
  {
  }

  AppChooserWidget::AppChooserWidget (AppChooserWidget&& src) noexcept
    : Widget (std::move (src)),
      AppChooser (std::move (src))
  {
  }

  auto
  AppChooserWidget::operator= (AppChooserWidget&& src) noexcept -> AppChooserWidget&
  {
    Widget::operator= (std::move (src));
    AppChooser::operator= (std::move (src));
    return *this;
  }

  AppChooserWidget::~AppChooserWidget () noexcept
  {
    destroy_ ();
  }

  AppChooserWidget::CppClassType AppChooserWidget::appchooserwidget_class_;

  auto
  AppChooserWidget::get_type () -> GType
  {
    return appchooserwidget_class_.init ().get_type ();
  }

  auto
  AppChooserWidget::get_base_type () -> GType
  {
    return gtk_app_chooser_widget_get_type ();
  }

  AppChooserWidget::AppChooserWidget (const Glib::ustring& content_type)
    : Glib::ObjectBase (nullptr),
      Widget (Glib::ConstructParams (appchooserwidget_class_.init (),
                                     "content_type",
                                     content_type.c_str (),
                                     nullptr))
  {
  }

  auto
  AppChooserWidget::set_show_default (bool setting) -> void
  {
    gtk_app_chooser_widget_set_show_default (gobj (),
                                             static_cast<int> (setting));
  }

  auto
  AppChooserWidget::get_show_default () -> bool
  {
    return gtk_app_chooser_widget_get_show_default (gobj ());
  }

  auto
  AppChooserWidget::set_show_recommended (bool setting) -> void
  {
    gtk_app_chooser_widget_set_show_recommended (gobj (),
                                                 static_cast<int> (setting));
  }

  auto
  AppChooserWidget::get_show_recommended () const -> bool
  {
    return gtk_app_chooser_widget_get_show_recommended (
        const_cast<GtkAppChooserWidget*> (gobj ()));
  }

  auto
  AppChooserWidget::set_show_fallback (bool setting) -> void
  {
    gtk_app_chooser_widget_set_show_fallback (gobj (),
                                              static_cast<int> (setting));
  }

  auto
  AppChooserWidget::get_show_fallback () const -> bool
  {
    return gtk_app_chooser_widget_get_show_fallback (
        const_cast<GtkAppChooserWidget*> (gobj ()));
  }

  auto
  AppChooserWidget::set_show_other (bool setting) -> void
  {
    gtk_app_chooser_widget_set_show_other (gobj (), static_cast<int> (setting));
  }

  auto
  AppChooserWidget::get_show_other () const -> bool
  {
    return gtk_app_chooser_widget_get_show_other (
        const_cast<GtkAppChooserWidget*> (gobj ()));
  }

  auto
  AppChooserWidget::set_show_all (bool setting) -> void
  {
    gtk_app_chooser_widget_set_show_all (gobj (), static_cast<int> (setting));
  }

  auto
  AppChooserWidget::get_show_all () const -> bool
  {
    return gtk_app_chooser_widget_get_show_all (
        const_cast<GtkAppChooserWidget*> (gobj ()));
  }

  auto
  AppChooserWidget::set_default_text (const Glib::ustring& text) -> void
  {
    gtk_app_chooser_widget_set_default_text (gobj (), text.c_str ());
  }

  auto
  AppChooserWidget::get_default_text () -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_app_chooser_widget_get_default_text (gobj ()));
  }

  auto
  AppChooserWidget::signal_application_selected () -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)> (
        this,
        &AppChooserWidget_signal_application_selected_info);
  }

  auto
  AppChooserWidget::signal_application_activated () -> Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)>
  {
    return Glib::SignalProxy<void (const Glib::RefPtr<Gio::AppInfo>&)> (
        this,
        &AppChooserWidget_signal_application_activated_info);
  }

  auto
  AppChooserWidget::property_show_default () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-default");
  }

  auto
  AppChooserWidget::property_show_default () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-default");
  }

  auto
  AppChooserWidget::property_show_recommended () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-recommended");
  }

  auto
  AppChooserWidget::property_show_recommended () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-recommended");
  }

  auto
  AppChooserWidget::property_show_fallback () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-fallback");
  }

  auto
  AppChooserWidget::property_show_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-fallback");
  }

  auto
  AppChooserWidget::property_show_other () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-other");
  }

  auto
  AppChooserWidget::property_show_other () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-other");
  }

  auto
  AppChooserWidget::property_show_all () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "show-all");
  }

  auto
  AppChooserWidget::property_show_all () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "show-all");
  }

  auto
  AppChooserWidget::property_default_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "default-text");
  }

  auto
  AppChooserWidget::property_default_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "default-text");
  }

} // namespace Gtk

#endif
