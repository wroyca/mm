

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutswindow.hxx>
#include <libmm-gtk/shortcutswindow_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
  auto
  ShortcutsWindow::unset_view_name () -> void
  {
    property_view_name ().reset_value ();
  }
} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutsWindow* object, const bool take_copy) -> Gtk::ShortcutsWindow*
  {
    return dynamic_cast<Gtk::ShortcutsWindow*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutsWindow_Class::init () -> const Class&
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
  ShortcutsWindow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new ShortcutsWindow ((GtkShortcutsWindow*) o);
  }

  ShortcutsWindow::ShortcutsWindow (
      const Glib::ConstructParams& construct_params)
    : Window (construct_params)
  {
  }

  ShortcutsWindow::ShortcutsWindow (GtkShortcutsWindow* castitem)
    : Window ((GtkWindow*) castitem)
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
    : ObjectBase (nullptr),
      Window (Glib::ConstructParams (shortcutswindow_class_.init ()))
  {
  }

  auto
  ShortcutsWindow::property_section_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "section-name"};
  }

  auto
  ShortcutsWindow::property_section_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "section-name"};
  }

  auto
  ShortcutsWindow::property_view_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "view-name"};
  }

  auto
  ShortcutsWindow::property_view_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "view-name"};
  }

} // namespace Gtk
