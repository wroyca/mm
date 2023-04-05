// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutswindow.hxx>
#include <libmm/gtk/shortcutswindow_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{
  auto
  ShortcutsWindow::unset_view_name () -> void
  {
    property_view_name ().reset_value ();
  }
} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcutsWindow* object, bool take_copy) -> gtk::ShortcutsWindow*
  {
    return dynamic_cast<gtk::ShortcutsWindow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutsWindow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutsWindow_Class::class_init_function;

      register_derived_type (gtk_shortcuts_window_get_type ());
    }

    return *this;
  }

  auto
  ShortcutsWindow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutsWindow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new ShortcutsWindow ((GtkShortcutsWindow*) (o));
  }

  ShortcutsWindow::ShortcutsWindow (
      const glib::ConstructParams& construct_params)
    : Window (construct_params)
  {
  }

  ShortcutsWindow::ShortcutsWindow (GtkShortcutsWindow* castitem)
    : Window ((GtkWindow*) (castitem))
  {
  }

  ShortcutsWindow::ShortcutsWindow (ShortcutsWindow&& src) noexcept
    : Window (std::move (src))
  {
  }

  auto
  ShortcutsWindow::operator= (ShortcutsWindow&& src) noexcept -> ShortcutsWindow&
  {
    Window::operator= (std::move (src));
    return *this;
  }

  ShortcutsWindow::~ShortcutsWindow () noexcept
  {
    destroy_ ();
  }

  ShortcutsWindow::CppClassType ShortcutsWindow::shortcutswindow_class_;

  auto
  ShortcutsWindow::get_type () -> GType
  {
    return shortcutswindow_class_.init ().get_type ();
  }

  auto
  ShortcutsWindow::get_base_type () -> GType
  {
    return gtk_shortcuts_window_get_type ();
  }

  ShortcutsWindow::ShortcutsWindow ()
    : glib::ObjectBase (nullptr),
      Window (glib::ConstructParams (shortcutswindow_class_.init ()))
  {
  }

  auto
  ShortcutsWindow::property_section_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "section-name");
  }

  auto
  ShortcutsWindow::property_section_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "section-name");
  }

  auto
  ShortcutsWindow::property_view_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "view-name");
  }

  auto
  ShortcutsWindow::property_view_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "view-name");
  }

} // namespace gtk
