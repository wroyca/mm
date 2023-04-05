// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/applicationwindow.hxx>
#include <libmm/gtk/applicationwindow_p.hxx>

#include <libmm/gtk/applicationwindow.hxx>
#include <libmm/gtk/shortcutswindow.hxx>

namespace gtk
{
  ApplicationWindow::ApplicationWindow (
      const glib::RefPtr<Application>& application)
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (applicationwindow_class_.init ()))
  {
    if (application)
      application->add_window (*this);
  }

  auto
  ApplicationWindow::unset_help_overlay () -> void
  {
    gtk_application_window_set_help_overlay (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkApplicationWindow* object, bool take_copy) -> gtk::ApplicationWindow*
  {
    return dynamic_cast<gtk::ApplicationWindow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ApplicationWindow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ApplicationWindow_Class::class_init_function;

      register_derived_type (gtk_application_window_get_type ());

      gio::ActionGroup::add_interface (get_type ());
      gio::ActionMap::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ApplicationWindow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ApplicationWindow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new ApplicationWindow ((GtkApplicationWindow*) (o));
  }

  ApplicationWindow::ApplicationWindow (
      const glib::ConstructParams& construct_params)
    : gtk::Window (construct_params)
  {
  }

  ApplicationWindow::ApplicationWindow (GtkApplicationWindow* castitem)
    : gtk::Window ((GtkWindow*) (castitem))
  {
  }

  ApplicationWindow::ApplicationWindow (ApplicationWindow&& src) noexcept
    : gtk::Window (std::move (src)),
      gio::ActionGroup (std::move (src)),
      gio::ActionMap (std::move (src))
  {
  }

  auto
  ApplicationWindow::operator= (ApplicationWindow&& src) noexcept -> ApplicationWindow&
  {
    gtk::Window::operator= (std::move (src));
    gio::ActionGroup::operator= (std::move (src));
    gio::ActionMap::operator= (std::move (src));
    return *this;
  }

  ApplicationWindow::~ApplicationWindow () noexcept
  {
    destroy_ ();
  }

  ApplicationWindow::CppClassType ApplicationWindow::applicationwindow_class_;

  auto
  ApplicationWindow::get_type () -> GType
  {
    return applicationwindow_class_.init ().get_type ();
  }

  auto
  ApplicationWindow::get_base_type () -> GType
  {
    return gtk_application_window_get_type ();
  }

  ApplicationWindow::ApplicationWindow ()
    : glib::ObjectBase (nullptr),
      gtk::Window (glib::ConstructParams (applicationwindow_class_.init ()))
  {
  }

  auto
  ApplicationWindow::set_show_menubar (bool show_menubar) -> void
  {
    gtk_application_window_set_show_menubar (gobj (),
                                             static_cast<int> (show_menubar));
  }

  auto
  ApplicationWindow::get_show_menubar () const -> bool
  {
    return gtk_application_window_get_show_menubar (
        const_cast<GtkApplicationWindow*> (gobj ()));
  }

  auto
  ApplicationWindow::get_id () const -> guint
  {
    return gtk_application_window_get_id (
        const_cast<GtkApplicationWindow*> (gobj ()));
  }

  auto
  ApplicationWindow::set_help_overlay (ShortcutsWindow& help_overlay) -> void
  {
    gtk_application_window_set_help_overlay (gobj (), (help_overlay).gobj ());
  }

  auto
  ApplicationWindow::get_help_overlay () -> ShortcutsWindow*
  {
    return glib::wrap (gtk_application_window_get_help_overlay (gobj ()));
  }

  auto
  ApplicationWindow::get_help_overlay () const -> const ShortcutsWindow*
  {
    return const_cast<ApplicationWindow*> (this)->get_help_overlay ();
  }

  auto
  ApplicationWindow::property_show_menubar () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "show-menubar");
  }

  auto
  ApplicationWindow::property_show_menubar () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "show-menubar");
  }

} // namespace gtk
