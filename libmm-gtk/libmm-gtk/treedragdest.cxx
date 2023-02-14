

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/treedragdest.hxx>
#include <libmm-gtk/treedragdest_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gtk/treepath.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkTreeDragDest* object, const bool take_copy) -> RefPtr<Gtk::TreeDragDest>
  {
    return Glib::make_refptr_for_instance<Gtk::TreeDragDest> (
        Glib::wrap_auto_interface<Gtk::TreeDragDest> ((GObject*) object,
                                                      take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  TreeDragDest_Class::init () -> const Interface_Class&
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->drag_data_received_vfunc (
              TreePath (dest, true),
              *reinterpret_cast<const Glib::ValueBase*> (value));
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
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->row_drop_possible_vfunc (
              TreePath (dest_path, true),
              *reinterpret_cast<const Glib::ValueBase*> (value));
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

    if (base && base->row_drop_possible)
      return (*base->row_drop_possible) (self, dest_path, value);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeDragDest_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TreeDragDest ((GtkTreeDragDest*) object);
  }

  TreeDragDest::TreeDragDest ()
    : Interface (treedragdest_class_.init ())
  {
  }

  TreeDragDest::TreeDragDest (GtkTreeDragDest* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  TreeDragDest::TreeDragDest (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  TreeDragDest::TreeDragDest (TreeDragDest&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  TreeDragDest::operator= (TreeDragDest&& src) noexcept -> TreeDragDest&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  TreeDragDest::~TreeDragDest () noexcept = default;

  auto
  TreeDragDest::add_interface (const GType gtype_implementer) -> void
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
                                    const Glib::ValueBase& value) -> bool
  {
    return gtk_tree_drag_dest_drag_data_received (
        gobj (),
        const_cast<GtkTreePath*> (dest.gobj ()),
        value.gobj ());
  }

  auto
  TreeDragDest::row_drop_possible (const TreeModel::Path& dest_path,
                                   const Glib::ValueBase& value) const -> bool
  {
    return gtk_tree_drag_dest_row_drop_possible (
        const_cast<GtkTreeDragDest*> (gobj ()),
        const_cast<GtkTreePath*> (dest_path.gobj ()),
        value.gobj ());
  }

  auto
  TreeDragDest::drag_data_received_vfunc (const TreeModel::Path& dest,
                                          const Glib::ValueBase& value) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->drag_data_received)
    {
      const bool retval (
          (*base->drag_data_received) (gobj (),
                                       const_cast<GtkTreePath*> (dest.gobj ()),
                                       value.gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  TreeDragDest::row_drop_possible_vfunc (const TreeModel::Path& dest,
                                         const Glib::ValueBase& value) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->row_drop_possible)
    {
      const bool retval (
          (*base->row_drop_possible) (const_cast<GtkTreeDragDest*> (gobj ()),
                                      const_cast<GtkTreePath*> (dest.gobj ()),
                                      value.gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk
