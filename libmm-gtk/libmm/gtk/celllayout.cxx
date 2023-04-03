// SPDX-License-Identifier: LGPL-2.1-or-later

#undef GTK_DISABLE_DEPRECATED
#define GDK_DISABLE_DEPRECATION_WARNINGS 1

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/mm-glib.hxx>

  #include <libmm/gtk/celllayout.hxx>
  #include <libmm/gtk/celllayout_p.hxx>

  #include <libmm/glib/vectorutils.hxx>

  #include <gtk/gtk.h>
  #include <libmm/gtk/cellarea.hxx>

static auto
SignalProxy_CellData_gtk_callback (GtkCellLayout*,
                                   GtkCellRenderer*,
                                   GtkTreeModel* tree_model,
                                   GtkTreeIter* iter,
                                   gpointer data) -> void
{
  auto the_slot = static_cast<Gtk::CellLayout::SlotCellData*> (data);

  try
  {
    (*the_slot) (Gtk::TreeModel::const_iterator (tree_model, iter));
  }
  catch (...)
  {
    Glib::exception_handlers_invoke ();
  }
}

static auto
SignalProxy_CellData_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<Gtk::CellLayout::SlotCellData*> (data);
}

namespace Gtk
{

  auto
  CellLayout::add_attribute (const Glib::PropertyProxy_Base& property,
                             const TreeModelColumnBase& column) -> void
  {
    gtk_cell_layout_add_attribute (
        gobj (),
        (GtkCellRenderer*) property.get_object ()->gobj (),
        property.get_name (),
        column.index ());
  }

  auto
  CellLayout::add_attribute (CellRenderer& cell,
                             const Glib::ustring& attribute,
                             const TreeModelColumnBase& column) -> void
  {
    gtk_cell_layout_add_attribute (gobj (),
                                   (GtkCellRenderer*) cell.gobj (),
                                   attribute.c_str (),
                                   column.index ());
  }

  auto
  CellLayout::set_cell_data_func (CellRenderer& cell, const SlotCellData& slot) -> void
  {
    auto slot_copy = new SlotCellData (slot);

    gtk_cell_layout_set_cell_data_func (
        gobj (),
        cell.gobj (),
        &SignalProxy_CellData_gtk_callback,
        slot_copy,
        &SignalProxy_CellData_gtk_callback_destroy);
  }

  auto
  CellLayout::get_first_cell () -> CellRenderer*
  {
    auto vecCellRenderers = get_cells ();
    if (!vecCellRenderers.empty ())
      return vecCellRenderers[0];
    else
      return nullptr;
  }

  auto
  CellLayout::get_first_cell () const -> const CellRenderer*
  {
    return const_cast<CellLayout*> (this)->get_first_cell ();
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkCellLayout* object, bool take_copy) -> Glib::RefPtr<Gtk::CellLayout>
  {
    return Glib::make_refptr_for_instance<Gtk::CellLayout> (
        dynamic_cast<Gtk::CellLayout*> (
            Glib::wrap_auto_interface<Gtk::CellLayout> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  CellLayout_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CellLayout_Class::iface_init_function;

      gtype_ = gtk_cell_layout_get_type ();
    }

    return *this;
  }

  auto
  CellLayout_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->pack_start = &pack_start_vfunc_callback;
    klass->pack_end = &pack_end_vfunc_callback;
    klass->clear = &clear_vfunc_callback;
    klass->add_attribute = &add_attribute_vfunc_callback;
    klass->clear_attributes = &clear_attributes_vfunc_callback;
    klass->reorder = &reorder_vfunc_callback;
  }

  auto
  CellLayout_Class::pack_start_vfunc_callback (GtkCellLayout* self,
                                               GtkCellRenderer* cell,
                                               gboolean expand) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->pack_start_vfunc (Glib::wrap (cell), expand);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->pack_start)
      (*base->pack_start) (self, cell, expand);
  }

  auto
  CellLayout_Class::pack_end_vfunc_callback (GtkCellLayout* self,
                                             GtkCellRenderer* cell,
                                             gboolean expand) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->pack_end_vfunc (Glib::wrap (cell), expand);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->pack_end)
      (*base->pack_end) (self, cell, expand);
  }

  auto
  CellLayout_Class::clear_vfunc_callback (GtkCellLayout* self) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->clear_vfunc ();
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->clear)
      (*base->clear) (self);
  }

  auto
  CellLayout_Class::add_attribute_vfunc_callback (GtkCellLayout* self,
                                                  GtkCellRenderer* cell,
                                                  const gchar* attribute,
                                                  gint column) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->add_attribute_vfunc (
              Glib::wrap (cell),
              Glib::convert_const_gchar_ptr_to_ustring (attribute),
              column);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->add_attribute)
      (*base->add_attribute) (self, cell, attribute, column);
  }

  auto
  CellLayout_Class::clear_attributes_vfunc_callback (GtkCellLayout* self,
                                                     GtkCellRenderer* cell) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->clear_attributes_vfunc (Glib::wrap (cell));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->clear_attributes)
      (*base->clear_attributes) (self, cell);
  }

  auto
  CellLayout_Class::reorder_vfunc_callback (GtkCellLayout* self,
                                            GtkCellRenderer* cell,
                                            gint position) -> void
  {
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->reorder_vfunc (Glib::wrap (cell), position);
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->reorder)
      (*base->reorder) (self, cell, position);
  }

  auto
  CellLayout_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new CellLayout ((GtkCellLayout*) (object));
  }

  CellLayout::CellLayout ()
    : Glib::Interface (celllayout_class_.init ())
  {
  }

  CellLayout::CellLayout (GtkCellLayout* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  CellLayout::CellLayout (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  CellLayout::CellLayout (CellLayout&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  CellLayout::operator= (CellLayout&& src) noexcept -> CellLayout&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  CellLayout::~CellLayout () noexcept {}

  auto
  CellLayout::add_interface (GType gtype_implementer) -> void
  {
    celllayout_class_.init ().add_interface (gtype_implementer);
  }

  CellLayout::CppClassType CellLayout::celllayout_class_;

  auto
  CellLayout::get_type () -> GType
  {
    return celllayout_class_.init ().get_type ();
  }

  auto
  CellLayout::get_base_type () -> GType
  {
    return gtk_cell_layout_get_type ();
  }

  auto
  CellLayout::pack_start (CellRenderer& cell, bool expand) -> void
  {
    gtk_cell_layout_pack_start (gobj (),
                                (cell).gobj (),
                                static_cast<int> (expand));
  }

  auto
  CellLayout::pack_end (CellRenderer& cell, bool expand) -> void
  {
    gtk_cell_layout_pack_end (gobj (),
                              (cell).gobj (),
                              static_cast<int> (expand));
  }

  auto
  CellLayout::get_cells () -> std::vector<CellRenderer*>
  {
    return Glib::ListHandler<CellRenderer*>::list_to_vector (
        gtk_cell_layout_get_cells (gobj ()),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  CellLayout::get_cells () const -> std::vector<const CellRenderer*>
  {
    return Glib::ListHandler<const CellRenderer*>::list_to_vector (
        gtk_cell_layout_get_cells (const_cast<GtkCellLayout*> (gobj ())),
        Glib::OWNERSHIP_SHALLOW);
  }

  auto
  CellLayout::clear () -> void
  {
    gtk_cell_layout_clear (gobj ());
  }

  auto
  CellLayout::add_attribute (CellRenderer& cell,
                             const Glib::ustring& attribute,
                             int column) -> void
  {
    gtk_cell_layout_add_attribute (gobj (),
                                   (cell).gobj (),
                                   attribute.c_str (),
                                   column);
  }

  auto
  CellLayout::clear_attributes (CellRenderer& cell) -> void
  {
    gtk_cell_layout_clear_attributes (gobj (), (cell).gobj ());
  }

  auto
  CellLayout::reorder (CellRenderer& cell, int position) -> void
  {
    gtk_cell_layout_reorder (gobj (), (cell).gobj (), position);
  }

  auto
  CellLayout::get_area () -> Glib::RefPtr<CellArea>
  {
    auto retvalue = Glib::wrap (gtk_cell_layout_get_area (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CellLayout::get_area () const -> Glib::RefPtr<const CellArea>
  {
    return const_cast<CellLayout*> (this)->get_area ();
  }

  auto
  Gtk::CellLayout::pack_start_vfunc (CellRenderer* cell, bool expand) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->pack_start)
    {
      (*base->pack_start) (gobj (),
                           (GtkCellRenderer*) Glib::unwrap (cell),
                           static_cast<int> (expand));
    }
  }

  auto
  Gtk::CellLayout::pack_end_vfunc (CellRenderer* cell, bool expand) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->pack_end)
    {
      (*base->pack_end) (gobj (),
                         (GtkCellRenderer*) Glib::unwrap (cell),
                         static_cast<int> (expand));
    }
  }

  auto
  Gtk::CellLayout::clear_vfunc () -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->clear)
    {
      (*base->clear) (gobj ());
    }
  }

  auto
  Gtk::CellLayout::add_attribute_vfunc (CellRenderer* cell,
                                        const Glib::ustring& attribute,
                                        int column) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->add_attribute)
    {
      (*base->add_attribute) (gobj (),
                              (GtkCellRenderer*) Glib::unwrap (cell),
                              attribute.c_str (),
                              column);
    }
  }

  auto
  Gtk::CellLayout::clear_attributes_vfunc (CellRenderer* cell) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->clear_attributes)
    {
      (*base->clear_attributes) (gobj (),
                                 (GtkCellRenderer*) Glib::unwrap (cell));
    }
  }

  auto
  Gtk::CellLayout::reorder_vfunc (CellRenderer* cell, int position) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->reorder)
    {
      (*base->reorder) (gobj (),
                        (GtkCellRenderer*) Glib::unwrap (cell),
                        position);
    }
  }

} // namespace Gtk

#endif
