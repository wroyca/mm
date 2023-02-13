


#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treedragsource.hxx>
#include <libmm-gtk/treedragsource_p.hxx>


/* Copyright 1998-2002 The gtkmm Development Team
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

#include <libmm-gtk/treepath.hxx>
#include <gtk/gtk.h>

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GtkTreeDragSource* object, const bool take_copy) -> RefPtr<Gtk::TreeDragSource>
{
  return Glib::make_refptr_for_instance<Gtk::TreeDragSource>( Glib::wrap_auto_interface<Gtk::TreeDragSource> ((GObject*)object, take_copy) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

auto TreeDragSource_Class::init() -> const Interface_Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &TreeDragSource_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_tree_drag_source_get_type();
  }

  return *this;
}

auto TreeDragSource_Class::iface_init_function (void *g_iface, void *) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->row_draggable = &row_draggable_vfunc_callback;
  klass->drag_data_get = &drag_data_get_vfunc_callback;
  klass->drag_data_delete = &drag_data_delete_vfunc_callback;

}

auto TreeDragSource_Class::row_draggable_vfunc_callback(GtkTreeDragSource* self, GtkTreePath* path) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->row_draggable_vfunc(
          TreePath(path, true)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->row_draggable)
    return (*base->row_draggable)(self, path);

  using RType = gboolean;
  return RType();
}
auto TreeDragSource_Class::drag_data_get_vfunc_callback(GtkTreeDragSource* self, GtkTreePath* path) -> GdkContentProvider*
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return unwrap_copy(obj->drag_data_get_vfunc(
          TreePath(path, true)
));
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->drag_data_get)
    return (*base->drag_data_get)(self, path);

  using RType = GdkContentProvider*;
  return RType();
}
auto TreeDragSource_Class::drag_data_delete_vfunc_callback(GtkTreeDragSource* self, GtkTreePath* path) -> gboolean
{
  const auto obj_base = Glib::ObjectBase::_get_current_wrapper((GObject*)self);

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->drag_data_delete_vfunc(
          TreePath(path, true)
        );
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  const BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->drag_data_delete)
    return (*base->drag_data_delete)(self, path);

  using RType = gboolean;
  return RType();
}


auto TreeDragSource_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new TreeDragSource((GtkTreeDragSource*)object);
}


/* The implementation: */

TreeDragSource::TreeDragSource()
: Interface(treedragsource_class_.init())
{}

TreeDragSource::TreeDragSource(GtkTreeDragSource* castitem)
: Interface((GObject*)castitem)
{}

TreeDragSource::TreeDragSource(const Glib::Interface_Class& interface_class)
: Interface(interface_class)
{
}

TreeDragSource::TreeDragSource(TreeDragSource&& src) noexcept
: Interface(std::move(src))
{}

auto TreeDragSource::operator=(TreeDragSource&& src) noexcept -> TreeDragSource&
{
  Interface::operator=(std::move(src));
  return *this;
}

TreeDragSource::~TreeDragSource() noexcept = default;

// static
auto TreeDragSource::add_interface (
  const GType gtype_implementer) -> void
{
  treedragsource_class_.init().add_interface(gtype_implementer);
}

TreeDragSource::CppClassType TreeDragSource::treedragsource_class_; // initialize static member

auto TreeDragSource::get_type() -> GType
{
  return treedragsource_class_.init().get_type();
}


auto TreeDragSource::get_base_type() -> GType
{
  return gtk_tree_drag_source_get_type();
}


auto TreeDragSource::row_draggable(const TreeModel::Path& path) const -> bool
{
  return gtk_tree_drag_source_row_draggable(const_cast<GtkTreeDragSource*>(gobj()), const_cast<GtkTreePath*>(path.gobj()));
}

auto TreeDragSource::drag_data_get(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>
{
  return Glib::wrap(gtk_tree_drag_source_drag_data_get(const_cast<GtkTreeDragSource*>(gobj()), const_cast<GtkTreePath*>(path.gobj())));
}

auto TreeDragSource::drag_data_delete(const TreeModel::Path& path) -> bool
{
  return gtk_tree_drag_source_drag_data_delete(gobj(), const_cast<GtkTreePath*>(path.gobj()));
}


auto TreeDragSource::row_draggable_vfunc(const TreeModel::Path& path) const -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->row_draggable)
  {
    const bool retval((*base->row_draggable)(const_cast<GtkTreeDragSource*>(gobj()),const_cast<GtkTreePath*>(path.gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
auto TreeDragSource::drag_data_get_vfunc(const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->drag_data_get)
  {
    Glib::RefPtr<Gdk::ContentProvider> retval(Glib::wrap((*base->drag_data_get)(const_cast<GtkTreeDragSource*>(gobj()),const_cast<GtkTreePath*>(path.gobj()))));
    return retval;
  }

  using RType = Glib::RefPtr<Gdk::ContentProvider>;
  return {};
}
auto TreeDragSource::drag_data_delete_vfunc(const TreeModel::Path& path) -> bool
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent(                             // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), get_type()) // Get the interface.
)  );

  if(base && base->drag_data_delete)
  {
    const bool retval((*base->drag_data_delete)(gobj(),const_cast<GtkTreePath*>(path.gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}


} // namespace Gtk

