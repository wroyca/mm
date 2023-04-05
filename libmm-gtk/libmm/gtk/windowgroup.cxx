// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/windowgroup.hxx>
#include <libmm/gtk/windowgroup_p.hxx>

#include <libmm/glib/vectorutils.hxx>
#include <libmm/gtk/window.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkWindowGroup* object, bool take_copy) -> glib::RefPtr<gtk::WindowGroup>
  {
    return glib::make_refptr_for_instance<gtk::WindowGroup> (
        dynamic_cast<gtk::WindowGroup*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  WindowGroup_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &WindowGroup_Class::class_init_function;

      register_derived_type (gtk_window_group_get_type ());
    }

    return *this;
  }

  auto
  WindowGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  WindowGroup_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new WindowGroup ((GtkWindowGroup*) object);
  }

  auto
  WindowGroup::gobj_copy () -> GtkWindowGroup*
  {
    reference ();
    return gobj ();
  }

  WindowGroup::WindowGroup (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  WindowGroup::WindowGroup (GtkWindowGroup* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  WindowGroup::WindowGroup (WindowGroup&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  WindowGroup::operator= (WindowGroup&& src) noexcept -> WindowGroup&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  WindowGroup::~WindowGroup () noexcept {}

  WindowGroup::CppClassType WindowGroup::windowgroup_class_;

  auto
  WindowGroup::get_type () -> GType
  {
    return windowgroup_class_.init ().get_type ();
  }

  auto
  WindowGroup::get_base_type () -> GType
  {
    return gtk_window_group_get_type ();
  }

  WindowGroup::WindowGroup ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (windowgroup_class_.init ()))
  {
  }

  auto
  WindowGroup::create () -> glib::RefPtr<WindowGroup>
  {
    return glib::make_refptr_for_instance<WindowGroup> (new WindowGroup ());
  }

  auto
  WindowGroup::add_window (Window& window) -> void
  {
    gtk_window_group_add_window (gobj (), (window).gobj ());
  }

  auto
  WindowGroup::remove_window (Window& window) -> void
  {
    gtk_window_group_remove_window (gobj (), (window).gobj ());
  }

  auto
  WindowGroup::list_windows () -> std::vector<Window*>
  {
    return glib::ListHandler<Window*>::list_to_vector (
        gtk_window_group_list_windows (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  WindowGroup::list_windows () const -> std::vector<const Window*>
  {
    return glib::ListHandler<const Window*>::list_to_vector (
        gtk_window_group_list_windows (const_cast<GtkWindowGroup*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

} // namespace gtk
