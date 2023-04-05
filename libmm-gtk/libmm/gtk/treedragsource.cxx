// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treedragsource.hxx>
  #include <libmm/gtk/treedragsource_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/treepath.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeDragSource* object, bool take_copy) -> glib::RefPtr<gtk::TreeDragSource>
  {
    return glib::make_refptr_for_instance<gtk::TreeDragSource> (
        dynamic_cast<gtk::TreeDragSource*> (
            glib::wrap_auto_interface<gtk::TreeDragSource> ((GObject*) (object),
                                                            take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeDragSource_Class::init () -> const glib::Interface_Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (
              obj->row_draggable_vfunc (gtk::TreePath (path, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return glib::unwrap_copy (
              obj->drag_data_get_vfunc (gtk::TreePath (path, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return static_cast<int> (
              obj->drag_data_delete_vfunc (gtk::TreePath (path, true)));
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_delete)
      return (*base->drag_data_delete) (self, path);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragSource_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeDragSource ((GtkTreeDragSource*) (object));
  }

  TreeDragSource::TreeDragSource ()
    : glib::Interface (treedragsource_class_.init ())
  {
  }

  TreeDragSource::TreeDragSource (GtkTreeDragSource* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  TreeDragSource::TreeDragSource (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  TreeDragSource::TreeDragSource (TreeDragSource&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  TreeDragSource::operator= (TreeDragSource&& src) noexcept -> TreeDragSource&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  TreeDragSource::~TreeDragSource () noexcept {}

  auto
  TreeDragSource::add_interface (GType gtype_implementer) -> void
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
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  TreeDragSource::drag_data_get (const TreeModel::Path& path) const -> glib::RefPtr<gdk::ContentProvider>
  {
    return glib::wrap (gtk_tree_drag_source_drag_data_get (
        const_cast<GtkTreeDragSource*> (gobj ()),
        const_cast<GtkTreePath*> ((path).gobj ())));
  }

  auto
  TreeDragSource::drag_data_delete (const TreeModel::Path& path) -> bool
  {
    return gtk_tree_drag_source_drag_data_delete (
        gobj (),
        const_cast<GtkTreePath*> ((path).gobj ()));
  }

  auto
  gtk::TreeDragSource::row_draggable_vfunc (const TreeModel::Path& path) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->row_draggable)
    {
      bool retval (
          (*base->row_draggable) (const_cast<GtkTreeDragSource*> (gobj ()),
                                  const_cast<GtkTreePath*> ((path).gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::TreeDragSource::drag_data_get_vfunc (const TreeModel::Path& path) const -> glib::RefPtr<gdk::ContentProvider>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_get)
    {
      glib::RefPtr<gdk::ContentProvider> retval (glib::wrap (
          (*base->drag_data_get) (const_cast<GtkTreeDragSource*> (gobj ()),
                                  const_cast<GtkTreePath*> ((path).gobj ()))));
      return retval;
    }

    using RType = glib::RefPtr<gdk::ContentProvider>;
    return RType ();
  }

  auto
  gtk::TreeDragSource::drag_data_delete_vfunc (const TreeModel::Path& path) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_delete)
    {
      bool retval ((*base->drag_data_delete) (
          gobj (),
          const_cast<GtkTreePath*> ((path).gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace gtk

#endif
