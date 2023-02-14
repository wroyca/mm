// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treedragsource.hxx>
#include <libmm-gtk/treedragsource_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/treepath.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeDragSource* object, const bool take_copy) -> RefPtr<Gtk::TreeDragSource>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeDragSource> (
        Glib::wrap_auto_interface<Gtk::TreeDragSource> ((GObject*) object,
                                                        take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeDragSource_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeDragSource_Class::iface_init_function;

      gtype_ = gtk_tree_drag_source_get_type ();
    }

    return *this;
  }

  auto
  TreeDragSource_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->row_draggable = &row_draggable_vfunc_callback;
    klass->drag_data_get = &drag_data_get_vfunc_callback;
    klass->drag_data_delete = &drag_data_delete_vfunc_callback;
  }

  auto
  TreeDragSource_Class::row_draggable_vfunc_callback (GtkTreeDragSource* self,
                                                      GtkTreePath* path) -> gboolean
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->row_draggable_vfunc (TreePath (path, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->row_draggable)
      return (*base->row_draggable) (self, path);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragSource_Class::drag_data_get_vfunc_callback (GtkTreeDragSource* self,
                                                      GtkTreePath* path) -> GdkContentProvider*
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return unwrap_copy (obj->drag_data_get_vfunc (TreePath (path, true)));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_get)
      return (*base->drag_data_get) (self, path);

    using RType = GdkContentProvider*;
    return RType ();
  }

  auto
  TreeDragSource_Class::drag_data_delete_vfunc_callback (
      GtkTreeDragSource* self,
      GtkTreePath* path) -> gboolean
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->drag_data_delete_vfunc (TreePath (path, true));
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_delete)
      return (*base->drag_data_delete) (self, path);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragSource_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeDragSource ((GtkTreeDragSource*) object);
  }

  TreeDragSource::TreeDragSource ()
    : Interface (treedragsource_class_.init ())
  {
  }

  TreeDragSource::TreeDragSource (GtkTreeDragSource* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  TreeDragSource::TreeDragSource (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  TreeDragSource::TreeDragSource (TreeDragSource&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  TreeDragSource::operator= (TreeDragSource&& src) noexcept -> TreeDragSource&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  TreeDragSource::~TreeDragSource () noexcept = default;

  auto
  TreeDragSource::add_interface (const GType gtype_implementer) -> void
  {
    treedragsource_class_.init ().add_interface (gtype_implementer);
  }

  TreeDragSource::CppClassType TreeDragSource::treedragsource_class_;

  auto
  TreeDragSource::get_type () -> GType
  {
    return treedragsource_class_.init ().get_type ();
  }

  auto
  TreeDragSource::get_base_type () -> GType
  {
    return gtk_tree_drag_source_get_type ();
  }

  auto
  TreeDragSource::row_draggable (const TreeModel::Path& path) const -> bool
  {
    return gtk_tree_drag_source_row_draggable (
        const_cast<GtkTreeDragSource*> (gobj ()),
        const_cast<GtkTreePath*> (path.gobj ()));
  }

  auto
  TreeDragSource::drag_data_get (const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>
  {
    return Glib::wrap (gtk_tree_drag_source_drag_data_get (
        const_cast<GtkTreeDragSource*> (gobj ()),
        const_cast<GtkTreePath*> (path.gobj ())));
  }

  auto
  TreeDragSource::drag_data_delete (const TreeModel::Path& path) -> bool
  {
    return gtk_tree_drag_source_drag_data_delete (
        gobj (),
        const_cast<GtkTreePath*> (path.gobj ()));
  }

  auto
  TreeDragSource::row_draggable_vfunc (const TreeModel::Path& path) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->row_draggable)
    {
      const bool retval (
          (*base->row_draggable) (const_cast<GtkTreeDragSource*> (gobj ()),
                                  const_cast<GtkTreePath*> (path.gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  TreeDragSource::drag_data_get_vfunc (const TreeModel::Path& path) const -> Glib::RefPtr<Gdk::ContentProvider>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->drag_data_get)
    {
      Glib::RefPtr<Gdk::ContentProvider> retval (Glib::wrap (
          (*base->drag_data_get) (const_cast<GtkTreeDragSource*> (gobj ()),
                                  const_cast<GtkTreePath*> (path.gobj ()))));
      return retval;
    }

    using RType = Glib::RefPtr<Gdk::ContentProvider>;
    return {};
  }

  auto
  TreeDragSource::drag_data_delete_vfunc (const TreeModel::Path& path) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->drag_data_delete)
    {
      const bool retval (
          (*base->drag_data_delete) (gobj (),
                                     const_cast<GtkTreePath*> (path.gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk
