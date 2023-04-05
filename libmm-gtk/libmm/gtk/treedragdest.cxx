// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treedragdest.hxx>
  #include <libmm/gtk/treedragdest_p.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/treepath.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkTreeDragDest* object, bool take_copy) -> glib::RefPtr<gtk::TreeDragDest>
  {
    return glib::make_refptr_for_instance<gtk::TreeDragDest> (
        dynamic_cast<gtk::TreeDragDest*> (
            glib::wrap_auto_interface<gtk::TreeDragDest> ((GObject*) (object),
                                                          take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeDragDest_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeDragDest_Class::iface_init_function;

      gtype_ = gtk_tree_drag_dest_get_type ();
    }

    return *this;
  }

  auto
  TreeDragDest_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->drag_data_received = &drag_data_received_vfunc_callback;
    klass->row_drop_possible = &row_drop_possible_vfunc_callback;
  }

  auto
  TreeDragDest_Class::drag_data_received_vfunc_callback (GtkTreeDragDest* self,
                                                         GtkTreePath* dest,
                                                         const GValue* value) -> gboolean
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
          return static_cast<int> (obj->drag_data_received_vfunc (
              gtk::TreePath (dest, true),
              *reinterpret_cast<const glib::ValueBase*> (value)));
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

    if (base && base->drag_data_received)
      return (*base->drag_data_received) (self, dest, value);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragDest_Class::row_drop_possible_vfunc_callback (GtkTreeDragDest* self,
                                                        GtkTreePath* dest_path,
                                                        const GValue* value) -> gboolean
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
          return static_cast<int> (obj->row_drop_possible_vfunc (
              gtk::TreePath (dest_path, true),
              *reinterpret_cast<const glib::ValueBase*> (value)));
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

    if (base && base->row_drop_possible)
      return (*base->row_drop_possible) (self, dest_path, value);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragDest_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeDragDest ((GtkTreeDragDest*) (object));
  }

  TreeDragDest::TreeDragDest ()
    : glib::Interface (treedragdest_class_.init ())
  {
  }

  TreeDragDest::TreeDragDest (GtkTreeDragDest* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  TreeDragDest::TreeDragDest (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  TreeDragDest::TreeDragDest (TreeDragDest&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  TreeDragDest::operator= (TreeDragDest&& src) noexcept -> TreeDragDest&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  TreeDragDest::~TreeDragDest () noexcept {}

  auto
  TreeDragDest::add_interface (GType gtype_implementer) -> void
  {
    treedragdest_class_.init ().add_interface (gtype_implementer);
  }

  TreeDragDest::CppClassType TreeDragDest::treedragdest_class_;

  auto
  TreeDragDest::get_type () -> GType
  {
    return treedragdest_class_.init ().get_type ();
  }

  auto
  TreeDragDest::get_base_type () -> GType
  {
    return gtk_tree_drag_dest_get_type ();
  }

  auto
  TreeDragDest::drag_data_received (const TreeModel::Path& dest,
                                    const glib::ValueBase& value) -> bool
  {
    return gtk_tree_drag_dest_drag_data_received (
        gobj (),
        const_cast<GtkTreePath*> ((dest).gobj ()),
        (value).gobj ());
  }

  auto
  TreeDragDest::row_drop_possible (const TreeModel::Path& dest_path,
                                   const glib::ValueBase& value) const -> bool
  {
    return gtk_tree_drag_dest_row_drop_possible (
        const_cast<GtkTreeDragDest*> (gobj ()),
        const_cast<GtkTreePath*> ((dest_path).gobj ()),
        (value).gobj ());
  }

  auto
  gtk::TreeDragDest::drag_data_received_vfunc (const TreeModel::Path& dest,
                                               const glib::ValueBase& value) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->drag_data_received)
    {
      bool retval ((*base->drag_data_received) (
          gobj (),
          const_cast<GtkTreePath*> ((dest).gobj ()),
          (value).gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::TreeDragDest::row_drop_possible_vfunc (
      const TreeModel::Path& dest,
      const glib::ValueBase& value) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->row_drop_possible)
    {
      bool retval (
          (*base->row_drop_possible) (const_cast<GtkTreeDragDest*> (gobj ()),
                                      const_cast<GtkTreePath*> ((dest).gobj ()),
                                      (value).gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace gtk

#endif
