// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#include <libmm/gtk/mm-gtkconfig.hxx>
#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/treesortable.hxx>
  #include <libmm/gtk/treesortable_p.hxx>

static auto
SignalProxy_Compare_gtk_callback (GtkTreeModel* model,
                                  GtkTreeIter* lhs,
                                  GtkTreeIter* rhs,
                                  void* data) -> int
{
  auto the_slot = static_cast<gtk::TreeSortable::SlotCompare*> (data);

  try
  {
    return (*the_slot) (gtk::TreeModel::const_iterator (model, lhs),
                        gtk::TreeModel::const_iterator (model, rhs));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }

  return 0;
}

static auto
SignalProxy_Compare_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::TreeSortable::SlotCompare*> (data);
}

namespace gtk
{

  auto
  TreeSortable::set_sort_func (int sort_column_id, const SlotCompare& slot) -> void
  {
    auto slot_copy = new SlotCompare (slot);

    gtk_tree_sortable_set_sort_func (gobj (),
                                     sort_column_id,
                                     &SignalProxy_Compare_gtk_callback,
                                     slot_copy,
                                     &SignalProxy_Compare_gtk_callback_destroy);
  }

  auto
  TreeSortable::set_sort_func (const gtk::TreeModelColumnBase& sort_column,
                               const SlotCompare& slot) -> void
  {
    set_sort_func (sort_column.index (), slot);
  }

  auto
  TreeSortable::set_default_sort_func (const SlotCompare& slot) -> void
  {
    auto slot_copy = new SlotCompare (slot);

    gtk_tree_sortable_set_default_sort_func (
        gobj (),
        &SignalProxy_Compare_gtk_callback,
        slot_copy,
        &SignalProxy_Compare_gtk_callback_destroy);
  }

  auto
  TreeSortable::unset_default_sort_func () -> void
  {
    gtk_tree_sortable_set_default_sort_func (gobj (),
                                             nullptr,
                                             nullptr,
                                             nullptr);
  }

} // namespace gtk

namespace
{

  static const glib::SignalProxyInfo
      TreeSortable_signal_sort_column_changed_info = {
          "sort_column_changed",
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback,
          (GCallback) &glib::SignalProxyNormal::slot0_void_callback};

}

namespace glib
{

  auto
  wrap (GtkTreeSortable* object, bool take_copy) -> glib::RefPtr<gtk::TreeSortable>
  {
    return glib::make_refptr_for_instance<gtk::TreeSortable> (
        dynamic_cast<gtk::TreeSortable*> (
            glib::wrap_auto_interface<gtk::TreeSortable> ((GObject*) (object),
                                                          take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  TreeSortable_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &TreeSortable_Class::iface_init_function;

      gtype_ = gtk_tree_sortable_get_type ();
    }

    return *this;
  }

  auto
  TreeSortable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_sort_column_id = &get_sort_column_id_vfunc_callback;
    klass->set_sort_column_id = &set_sort_column_id_vfunc_callback;
    klass->set_sort_func = &set_sort_func_vfunc_callback;
    klass->set_default_sort_func = &set_default_sort_func_vfunc_callback;
    klass->has_default_sort_func = &has_default_sort_func_vfunc_callback;
    klass->sort_column_changed = &sort_column_changed_vfunc_callback;

    klass->sort_column_changed = &sort_column_changed_callback;
  }

  auto
  TreeSortable_Class::get_sort_column_id_vfunc_callback (GtkTreeSortable* self,
                                                         int* sort_column_id,
                                                         GtkSortType* order) -> gboolean
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
              obj->get_sort_column_id_vfunc (sort_column_id,
                                             ((SortType*) (order))));
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

    if (base && base->get_sort_column_id)
      return (*base->get_sort_column_id) (self, sort_column_id, order);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeSortable_Class::set_sort_column_id_vfunc_callback (GtkTreeSortable* self,
                                                         int sort_column_id,
                                                         GtkSortType order) -> void
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
          obj->set_sort_column_id_vfunc (sort_column_id,
                                         static_cast<SortType> (order));
          return;
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

    if (base && base->set_sort_column_id)
      (*base->set_sort_column_id) (self, sort_column_id, order);
  }

  auto
  TreeSortable_Class::set_sort_func_vfunc_callback (GtkTreeSortable* self,
                                                    int sort_column_id,
                                                    GtkTreeIterCompareFunc func,
                                                    gpointer data,
                                                    GDestroyNotify destroy) -> void
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
          obj->set_sort_func_vfunc (sort_column_id, func, data, destroy);
          return;
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

    if (base && base->set_sort_func)
      (*base->set_sort_func) (self, sort_column_id, func, data, destroy);
  }

  auto
  TreeSortable_Class::set_default_sort_func_vfunc_callback (
      GtkTreeSortable* self,
      GtkTreeIterCompareFunc func,
      gpointer data,
      GDestroyNotify destroy) -> void
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
          obj->set_default_sort_func_vfunc (func, data, destroy);
          return;
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

    if (base && base->set_default_sort_func)
      (*base->set_default_sort_func) (self, func, data, destroy);
  }

  auto
  TreeSortable_Class::has_default_sort_func_vfunc_callback (
      GtkTreeSortable* self) -> gboolean
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
          return static_cast<int> (obj->has_default_sort_func_vfunc ());
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

    if (base && base->has_default_sort_func)
      return (*base->has_default_sort_func) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  TreeSortable_Class::sort_column_changed_vfunc_callback (GtkTreeSortable* self) -> void
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
          obj->sort_column_changed_vfunc ();
          return;
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

    if (base && base->sort_column_changed)
      (*base->sort_column_changed) (self);
  }

  auto
  TreeSortable_Class::sort_column_changed_callback (GtkTreeSortable* self) -> void
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
          obj->on_sort_column_changed ();
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->sort_column_changed)
      (*base->sort_column_changed) (self);
  }

  auto
  TreeSortable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new TreeSortable ((GtkTreeSortable*) (object));
  }

  TreeSortable::TreeSortable ()
    : glib::Interface (treesortable_class_.init ())
  {
  }

  TreeSortable::TreeSortable (GtkTreeSortable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  TreeSortable::TreeSortable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  TreeSortable::TreeSortable (TreeSortable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  TreeSortable::operator= (TreeSortable&& src) noexcept -> TreeSortable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  TreeSortable::~TreeSortable () noexcept {}

  auto
  TreeSortable::add_interface (GType gtype_implementer) -> void
  {
    treesortable_class_.init ().add_interface (gtype_implementer);
  }

  TreeSortable::CppClassType TreeSortable::treesortable_class_;

  auto
  TreeSortable::get_type () -> GType
  {
    return treesortable_class_.init ().get_type ();
  }

  auto
  TreeSortable::get_base_type () -> GType
  {
    return gtk_tree_sortable_get_type ();
  }

  auto
  TreeSortable::get_sort_column_id (int& sort_column_id, SortType& order) const -> bool
  {
    return gtk_tree_sortable_get_sort_column_id (
        const_cast<GtkTreeSortable*> (gobj ()),
        &(sort_column_id),
        ((GtkSortType*) &(order)));
  }

  auto
  TreeSortable::set_sort_column (const TreeModelColumnBase& sort_column_id,
                                 SortType order) -> void
  {
    gtk_tree_sortable_set_sort_column_id (gobj (),
                                          (sort_column_id).index (),
                                          static_cast<GtkSortType> (order));
  }

  auto
  TreeSortable::set_sort_column (int sort_column_id, SortType order) -> void
  {
    gtk_tree_sortable_set_sort_column_id (gobj (),
                                          sort_column_id,
                                          static_cast<GtkSortType> (order));
  }

  auto
  TreeSortable::has_default_sort_func () const -> bool
  {
    return gtk_tree_sortable_has_default_sort_func (
        const_cast<GtkTreeSortable*> (gobj ()));
  }

  auto
  TreeSortable::sort_column_changed () -> void
  {
    gtk_tree_sortable_sort_column_changed (gobj ());
  }

  auto
  TreeSortable::signal_sort_column_changed () -> glib::SignalProxy<void ()>
  {
    return glib::SignalProxy<void ()> (
        this,
        &TreeSortable_signal_sort_column_changed_info);
  }

  auto
  gtk::TreeSortable::on_sort_column_changed () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->sort_column_changed)
      (*base->sort_column_changed) (gobj ());
  }

  auto
  gtk::TreeSortable::get_sort_column_id_vfunc (int* sort_column_id,
                                               SortType* order) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_sort_column_id)
    {
      bool retval (
          (*base->get_sort_column_id) (const_cast<GtkTreeSortable*> (gobj ()),
                                       sort_column_id,
                                       ((GtkSortType*) (order))));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::TreeSortable::set_sort_column_id_vfunc (int sort_column_id,
                                               SortType order) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_sort_column_id)
    {
      (*base->set_sort_column_id) (gobj (),
                                   sort_column_id,
                                   static_cast<GtkSortType> (order));
    }
  }

  auto
  gtk::TreeSortable::set_sort_func_vfunc (int sort_column_id,
                                          GtkTreeIterCompareFunc func,
                                          void* data,
                                          GDestroyNotify destroy) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_sort_func)
    {
      (*base->set_sort_func) (gobj (), sort_column_id, func, data, destroy);
    }
  }

  auto
  gtk::TreeSortable::set_default_sort_func_vfunc (GtkTreeIterCompareFunc func,
                                                  void* data,
                                                  GDestroyNotify destroy) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_default_sort_func)
    {
      (*base->set_default_sort_func) (gobj (), func, data, destroy);
    }
  }

  auto
  gtk::TreeSortable::has_default_sort_func_vfunc () const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->has_default_sort_func)
    {
      bool retval ((*base->has_default_sort_func) (
          const_cast<GtkTreeSortable*> (gobj ())));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  gtk::TreeSortable::sort_column_changed_vfunc () const -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->sort_column_changed)
    {
      (*base->sort_column_changed) (const_cast<GtkTreeSortable*> (gobj ()));
    }
  }

} // namespace gtk

#endif
