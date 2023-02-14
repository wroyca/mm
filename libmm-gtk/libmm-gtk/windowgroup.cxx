

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/windowgroup.hxx>
#include <libmm-gtk/windowgroup_p.hxx>

#include <libmm-glib/vectorutils.hxx>
#include <libmm-gtk/window.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkWindowGroup* object, const bool take_copy) -> RefPtr<Gtk::WindowGroup>
  {
    return Glib::make_refptr_for_instance<Gtk::WindowGroup> (
        dynamic_cast<Gtk::WindowGroup*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  WindowGroup_Class::init () -> const Class&
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
  WindowGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new WindowGroup ((GtkWindowGroup*) object);
  }

  auto
  WindowGroup::gobj_copy () -> GtkWindowGroup*
  {
    reference ();
    return gobj ();
  }

  WindowGroup::WindowGroup (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  WindowGroup::WindowGroup (GtkWindowGroup* castitem)
    : Object ((GObject*) castitem)
  {
  }

  WindowGroup::WindowGroup (WindowGroup&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  WindowGroup::operator= (WindowGroup&& src) noexcept -> WindowGroup&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  WindowGroup::~WindowGroup () noexcept = default;

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
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (windowgroup_class_.init ()))
  {
  }

  auto
  WindowGroup::create () -> Glib::RefPtr<WindowGroup>
  {
    return Glib::make_refptr_for_instance<WindowGroup> (new WindowGroup ());
  }

  auto
  WindowGroup::add_window (Window& window) -> void
  {
    gtk_window_group_add_window (gobj (), window.gobj ());
  }

  auto
  WindowGroup::remove_window (Window& window) -> void
  {
    gtk_window_group_remove_window (gobj (), window.gobj ());
  }

  auto
  WindowGroup::list_windows () -> std::vector<Window*>
  {
    return Glib::ListHandler<Window*>::list_to_vector (
        gtk_window_group_list_windows (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  WindowGroup::list_windows () const -> std::vector<const Window*>
  {
    return Glib::ListHandler<const Window*>::list_to_vector (
        gtk_window_group_list_windows (const_cast<GtkWindowGroup*> (gobj ())),
        Glib::OWNERSHIP_SHALLOW);
  }

} // namespace Gtk
