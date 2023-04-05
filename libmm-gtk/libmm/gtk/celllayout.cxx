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
  auto the_slot = static_cast<gtk::CellLayout::SlotCellData*> (data);

  try
  {
    (*the_slot) (gtk::TreeModel::const_iterator (tree_model, iter));
  }
  catch (...)
  {
    glib::exception_handlers_invoke ();
  }
}

static auto
SignalProxy_CellData_gtk_callback_destroy (void* data) -> void
{
  delete static_cast<gtk::CellLayout::SlotCellData*> (data);
}

namespace gtk
{

  auto
  CellLayout::add_attribute (const glib::PropertyProxy_Base& property,
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
                             const glib::ustring& attribute,
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

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkCellLayout* object, bool take_copy) -> glib::RefPtr<gtk::CellLayout>
  {
    return glib::make_refptr_for_instance<gtk::CellLayout> (
        dynamic_cast<gtk::CellLayout*> (
            glib::wrap_auto_interface<gtk::CellLayout> ((GObject*) (object),
                                                        take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  CellLayout_Class::init () -> const glib::Interface_Class&
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
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->pack_start_vfunc (glib::wrap (cell), expand);
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

    if (base && base->pack_start)
      (*base->pack_start) (self, cell, expand);
  }

  auto
  CellLayout_Class::pack_end_vfunc_callback (GtkCellLayout* self,
                                             GtkCellRenderer* cell,
                                             gboolean expand) -> void
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
          obj->pack_end_vfunc (glib::wrap (cell), expand);
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

    if (base && base->pack_end)
      (*base->pack_end) (self, cell, expand);
  }

  auto
  CellLayout_Class::clear_vfunc_callback (GtkCellLayout* self) -> void
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
          obj->clear_vfunc ();
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

    if (base && base->clear)
      (*base->clear) (self);
  }

  auto
  CellLayout_Class::add_attribute_vfunc_callback (GtkCellLayout* self,
                                                  GtkCellRenderer* cell,
                                                  const gchar* attribute,
                                                  gint column) -> void
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
          obj->add_attribute_vfunc (
              glib::wrap (cell),
              glib::convert_const_gchar_ptr_to_ustring (attribute),
              column);
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

    if (base && base->add_attribute)
      (*base->add_attribute) (self, cell, attribute, column);
  }

  auto
  CellLayout_Class::clear_attributes_vfunc_callback (GtkCellLayout* self,
                                                     GtkCellRenderer* cell) -> void
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
          obj->clear_attributes_vfunc (glib::wrap (cell));
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

    if (base && base->clear_attributes)
      (*base->clear_attributes) (self, cell);
  }

  auto
  CellLayout_Class::reorder_vfunc_callback (GtkCellLayout* self,
                                            GtkCellRenderer* cell,
                                            gint position) -> void
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
          obj->reorder_vfunc (glib::wrap (cell), position);
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

    if (base && base->reorder)
      (*base->reorder) (self, cell, position);
  }

  auto
  CellLayout_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CellLayout ((GtkCellLayout*) (object));
  }

  CellLayout::CellLayout ()
    : glib::Interface (celllayout_class_.init ())
  {
  }

  CellLayout::CellLayout (GtkCellLayout* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  CellLayout::CellLayout (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  CellLayout::CellLayout (CellLayout&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  CellLayout::operator= (CellLayout&& src) noexcept -> CellLayout&
  {
    glib::Interface::operator= (std::move (src));
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
    return glib::ListHandler<CellRenderer*>::list_to_vector (
        gtk_cell_layout_get_cells (gobj ()),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  CellLayout::get_cells () const -> std::vector<const CellRenderer*>
  {
    return glib::ListHandler<const CellRenderer*>::list_to_vector (
        gtk_cell_layout_get_cells (const_cast<GtkCellLayout*> (gobj ())),
        glib::OWNERSHIP_SHALLOW);
  }

  auto
  CellLayout::clear () -> void
  {
    gtk_cell_layout_clear (gobj ());
  }

  auto
  CellLayout::add_attribute (CellRenderer& cell,
                             const glib::ustring& attribute,
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
  CellLayout::get_area () -> glib::RefPtr<CellArea>
  {
    auto retvalue = glib::wrap (gtk_cell_layout_get_area (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  CellLayout::get_area () const -> glib::RefPtr<const CellArea>
  {
    return const_cast<CellLayout*> (this)->get_area ();
  }

  auto
  gtk::CellLayout::pack_start_vfunc (CellRenderer* cell, bool expand) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->pack_start)
    {
      (*base->pack_start) (gobj (),
                           (GtkCellRenderer*) glib::unwrap (cell),
                           static_cast<int> (expand));
    }
  }

  auto
  gtk::CellLayout::pack_end_vfunc (CellRenderer* cell, bool expand) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->pack_end)
    {
      (*base->pack_end) (gobj (),
                         (GtkCellRenderer*) glib::unwrap (cell),
                         static_cast<int> (expand));
    }
  }

  auto
  gtk::CellLayout::clear_vfunc () -> void
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
  gtk::CellLayout::add_attribute_vfunc (CellRenderer* cell,
                                        const glib::ustring& attribute,
                                        int column) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->add_attribute)
    {
      (*base->add_attribute) (gobj (),
                              (GtkCellRenderer*) glib::unwrap (cell),
                              attribute.c_str (),
                              column);
    }
  }

  auto
  gtk::CellLayout::clear_attributes_vfunc (CellRenderer* cell) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->clear_attributes)
    {
      (*base->clear_attributes) (gobj (),
                                 (GtkCellRenderer*) glib::unwrap (cell));
    }
  }

  auto
  gtk::CellLayout::reorder_vfunc (CellRenderer* cell, int position) -> void
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->reorder)
    {
      (*base->reorder) (gobj (),
                        (GtkCellRenderer*) glib::unwrap (cell),
                        position);
    }
  }

} // namespace gtk

#endif
