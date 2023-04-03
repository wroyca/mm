// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/selectionmodel.hxx>
#include <libmm/gtk/selectionmodel_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  SelectionModel_signal_selection_changed_callback (GtkSelectionModel* self,
                                                    guint p0,
                                                    guint p1,
                                                    void* data) -> void
  {
    using namespace Gtk;
    using SlotType = sigc::slot<void (guint, guint)>;

    auto obj = dynamic_cast<SelectionModel*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo
      SelectionModel_signal_selection_changed_info = {
          "selection-changed",
          (GCallback) &SelectionModel_signal_selection_changed_callback,
          (GCallback) &SelectionModel_signal_selection_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GtkSelectionModel* object, bool take_copy) -> Glib::RefPtr<Gtk::SelectionModel>
  {
    return Glib::make_refptr_for_instance<Gtk::SelectionModel> (
        dynamic_cast<Gtk::SelectionModel*> (
            Glib::wrap_auto_interface<Gtk::SelectionModel> ((GObject*) (object),
                                                            take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SelectionModel_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SelectionModel_Class::iface_init_function;

      gtype_ = gtk_selection_model_get_type ();
    }

    return *this;
  }

  auto
  SelectionModel_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->is_selected = &is_selected_vfunc_callback;
    klass->get_selection_in_range = &get_selection_in_range_vfunc_callback;
    klass->select_item = &select_item_vfunc_callback;
    klass->unselect_item = &unselect_item_vfunc_callback;
    klass->select_range = &select_range_vfunc_callback;
    klass->unselect_range = &unselect_range_vfunc_callback;
    klass->select_all = &select_all_vfunc_callback;
    klass->unselect_all = &unselect_all_vfunc_callback;
    klass->set_selection = &set_selection_vfunc_callback;
  }

  auto
  SelectionModel_Class::is_selected_vfunc_callback (GtkSelectionModel* self,
                                                    guint position) -> gboolean
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
          return static_cast<int> (obj->is_selected_vfunc (position));
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

    if (base && base->is_selected)
      return (*base->is_selected) (self, position);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::get_selection_in_range_vfunc_callback (
      GtkSelectionModel* self,
      guint position,
      guint n_items) -> GtkBitset*
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
          return Glib::unwrap_copy (std::const_pointer_cast<Bitset> (
              obj->get_selection_vfunc (position, n_items)));
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

    if (base && base->get_selection_in_range)
      return (*base->get_selection_in_range) (self, position, n_items);

    using RType = GtkBitset*;
    return RType ();
  }

  auto
  SelectionModel_Class::select_item_vfunc_callback (GtkSelectionModel* self,
                                                    guint position,
                                                    gboolean unselect_rest) -> gboolean
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
          return static_cast<int> (
              obj->select_item_vfunc (position, unselect_rest));
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

    if (base && base->select_item)
      return (*base->select_item) (self, position, unselect_rest);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::unselect_item_vfunc_callback (GtkSelectionModel* self,
                                                      guint position) -> gboolean
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
          return static_cast<int> (obj->unselect_item_vfunc (position));
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

    if (base && base->unselect_item)
      return (*base->unselect_item) (self, position);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::select_range_vfunc_callback (GtkSelectionModel* self,
                                                     guint position,
                                                     guint n_items,
                                                     gboolean unselect_rest) -> gboolean
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
          return static_cast<int> (
              obj->select_range_vfunc (position, n_items, unselect_rest));
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

    if (base && base->select_range)
      return (*base->select_range) (self, position, n_items, unselect_rest);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::unselect_range_vfunc_callback (GtkSelectionModel* self,
                                                       guint position,
                                                       guint n_items) -> gboolean
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
          return static_cast<int> (
              obj->unselect_range_vfunc (position, n_items));
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

    if (base && base->unselect_range)
      return (*base->unselect_range) (self, position, n_items);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::select_all_vfunc_callback (GtkSelectionModel* self) -> gboolean
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
          return static_cast<int> (obj->select_all_vfunc ());
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

    if (base && base->select_all)
      return (*base->select_all) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::unselect_all_vfunc_callback (GtkSelectionModel* self) -> gboolean
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
          return static_cast<int> (obj->unselect_all_vfunc ());
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

    if (base && base->unselect_all)
      return (*base->unselect_all) (self);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::set_selection_vfunc_callback (GtkSelectionModel* self,
                                                      GtkBitset* selected,
                                                      GtkBitset* mask) -> gboolean
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
          return static_cast<int> (
              obj->set_selection_vfunc (Glib::wrap (selected, true),
                                        Glib::wrap (mask, true)));
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

    if (base && base->set_selection)
      return (*base->set_selection) (self, selected, mask);

    using RType = gboolean;
    return RType ();
  }

  auto
  SelectionModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SelectionModel ((GtkSelectionModel*) (object));
  }

  SelectionModel::SelectionModel ()
    : Glib::Interface (selectionmodel_class_.init ())
  {
  }

  SelectionModel::SelectionModel (GtkSelectionModel* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  SelectionModel::SelectionModel (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  SelectionModel::SelectionModel (SelectionModel&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  SelectionModel::operator= (SelectionModel&& src) noexcept -> SelectionModel&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  SelectionModel::~SelectionModel () noexcept {}

  auto
  SelectionModel::add_interface (GType gtype_implementer) -> void
  {
    selectionmodel_class_.init ().add_interface (gtype_implementer);
  }

  SelectionModel::CppClassType SelectionModel::selectionmodel_class_;

  auto
  SelectionModel::get_type () -> GType
  {
    return selectionmodel_class_.init ().get_type ();
  }

  auto
  SelectionModel::get_base_type () -> GType
  {
    return gtk_selection_model_get_type ();
  }

  auto
  SelectionModel::is_selected (guint position) const -> bool
  {
    return gtk_selection_model_is_selected (
        const_cast<GtkSelectionModel*> (gobj ()),
        position);
  }

  auto
  SelectionModel::get_selection () const -> Glib::RefPtr<const Bitset>
  {
    return Glib::wrap (gtk_selection_model_get_selection (
        const_cast<GtkSelectionModel*> (gobj ())));
  }

  auto
  SelectionModel::get_selection (guint position, guint n_items) const -> Glib::RefPtr<const Bitset>
  {
    return Glib::wrap (gtk_selection_model_get_selection_in_range (
        const_cast<GtkSelectionModel*> (gobj ()),
        position,
        n_items));
  }

  auto
  SelectionModel::select_item (guint position, bool unselect_rest) -> bool
  {
    return gtk_selection_model_select_item (gobj (),
                                            position,
                                            static_cast<int> (unselect_rest));
  }

  auto
  SelectionModel::unselect_item (guint position) -> bool
  {
    return gtk_selection_model_unselect_item (gobj (), position);
  }

  auto
  SelectionModel::select_range (guint position,
                                guint n_items,
                                bool unselect_rest) -> bool
  {
    return gtk_selection_model_select_range (gobj (),
                                             position,
                                             n_items,
                                             static_cast<int> (unselect_rest));
  }

  auto
  SelectionModel::unselect_range (guint position, guint n_items) -> bool
  {
    return gtk_selection_model_unselect_range (gobj (), position, n_items);
  }

  auto
  SelectionModel::select_all () -> bool
  {
    return gtk_selection_model_select_all (gobj ());
  }

  auto
  SelectionModel::unselect_all () -> bool
  {
    return gtk_selection_model_unselect_all (gobj ());
  }

  auto
  SelectionModel::set_selection (const Glib::RefPtr<const Bitset>& selected,
                                 const Glib::RefPtr<const Bitset>& mask) -> bool
  {
    return gtk_selection_model_set_selection (
        gobj (),
        const_cast<GtkBitset*> (Glib::unwrap (selected)),
        const_cast<GtkBitset*> (Glib::unwrap (mask)));
  }

  auto
  SelectionModel::selection_changed (guint position, guint n_items) -> void
  {
    gtk_selection_model_selection_changed (gobj (), position, n_items);
  }

  auto
  SelectionModel::signal_selection_changed () -> Glib::SignalProxy<void (guint, guint)>
  {
    return Glib::SignalProxy<void (guint, guint)> (
        this,
        &SelectionModel_signal_selection_changed_info);
  }

  auto
  Gtk::SelectionModel::is_selected_vfunc (guint position) const -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->is_selected)
    {
      bool retval (
          (*base->is_selected) (const_cast<GtkSelectionModel*> (gobj ()),
                                position));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::get_selection_vfunc (guint position, guint n_items) -> Glib::RefPtr<const Bitset>
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->get_selection_in_range)
    {
      Glib::RefPtr<const Bitset> retval (Glib::wrap (
          (*base->get_selection_in_range) (gobj (), position, n_items)));
      return retval;
    }

    using RType = Glib::RefPtr<const Bitset>;
    return RType ();
  }

  auto
  Gtk::SelectionModel::select_item_vfunc (guint position, bool unselect_rest) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->select_item)
    {
      bool retval ((*base->select_item) (gobj (),
                                         position,
                                         static_cast<int> (unselect_rest)));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::unselect_item_vfunc (guint position) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->unselect_item)
    {
      bool retval ((*base->unselect_item) (gobj (), position));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::select_range_vfunc (guint position,
                                           guint n_items,
                                           bool unselect_rest) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->select_range)
    {
      bool retval ((*base->select_range) (gobj (),
                                          position,
                                          n_items,
                                          static_cast<int> (unselect_rest)));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::unselect_range_vfunc (guint position, guint n_items) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->unselect_range)
    {
      bool retval ((*base->unselect_range) (gobj (), position, n_items));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::select_all_vfunc () -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->select_all)
    {
      bool retval ((*base->select_all) (gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::unselect_all_vfunc () -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->unselect_all)
    {
      bool retval ((*base->unselect_all) (gobj ()));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

  auto
  Gtk::SelectionModel::set_selection_vfunc (
      const Glib::RefPtr<const Bitset>& selected,
      const Glib::RefPtr<const Bitset>& mask) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   CppObjectType::get_type ())));

    if (base && base->set_selection)
    {
      bool retval ((*base->set_selection) (
          gobj (),
          const_cast<GtkBitset*> (Glib::unwrap (selected)),
          const_cast<GtkBitset*> (Glib::unwrap (mask))));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gtk