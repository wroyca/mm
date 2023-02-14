

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/listmodel.hxx>
#include <libmm-gio/listmodel_p.hxx>

#include <gio/gio.h>

namespace Gio
{

}

namespace
{

  auto
  ListModel_signal_items_changed_callback (GListModel* self,
                                           const guint p0,
                                           const guint p1,
                                           const guint p2,
                                           void* data) -> void
  {
    using namespace Gio;
    using SlotType = sigc::slot<void (guint, guint, guint)>;

    const auto obj = dynamic_cast<ListModel*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  const Glib::SignalProxyInfo ListModel_signal_items_changed_info = {
      "items-changed",
      (GCallback) &ListModel_signal_items_changed_callback,
      (GCallback) &ListModel_signal_items_changed_callback};

} // namespace

namespace Glib
{

  auto
  wrap (GListModel* object, const bool take_copy) -> RefPtr<Gio::ListModel>
  {
    return Glib::make_refptr_for_instance<Gio::ListModel> (
        Glib::wrap_auto_interface<Gio::ListModel> ((GObject*) object,
                                                   take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  ListModel_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListModel_Class::iface_init_function;

      gtype_ = g_list_model_get_type ();
    }

    return *this;
  }

  auto
  ListModel_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->get_item_type = &get_item_type_vfunc_callback;
    klass->get_n_items = &get_n_items_vfunc_callback;
    klass->get_item = &get_item_vfunc_callback;
  }

  auto
  ListModel_Class::get_item_type_vfunc_callback (GListModel* self) -> GType
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
          return obj->get_item_type_vfunc ();
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

    if (base && base->get_item_type)
      return (*base->get_item_type) (self);

    using RType = GType;
    return RType ();
  }

  auto
  ListModel_Class::get_n_items_vfunc_callback (GListModel* self) -> guint
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
          return obj->get_n_items_vfunc ();
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

    if (base && base->get_n_items)
      return (*base->get_n_items) (self);

    using RType = guint;
    return RType ();
  }

  auto
  ListModel_Class::get_item_vfunc_callback (GListModel* self,
                                            const guint position) -> gpointer
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
          return obj->get_item_vfunc (position);
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

    if (base && base->get_item)
      return (*base->get_item) (self, position);

    using RType = gpointer;
    return RType ();
  }

  auto
  ListModel_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ListModel ((GListModel*) object);
  }

  ListModel::ListModel ()
    : Interface (listmodel_class_.init ())
  {
  }

  ListModel::ListModel (GListModel* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ListModel::ListModel (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ListModel::ListModel (ListModel&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ListModel::operator= (ListModel&& src) noexcept -> ListModel&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ListModel::~ListModel () noexcept = default;

  auto
  ListModel::add_interface (const GType gtype_implementer) -> void
  {
    listmodel_class_.init ().add_interface (gtype_implementer);
  }

  ListModel::CppClassType ListModel::listmodel_class_;

  auto
  ListModel::get_type () -> GType
  {
    return listmodel_class_.init ().get_type ();
  }

  auto
  ListModel::get_base_type () -> GType
  {
    return g_list_model_get_type ();
  }

  auto
  ListModel::items_changed (const guint position,
                            const guint removed,
                            const guint added) -> void
  {
    g_list_model_items_changed (gobj (), position, removed, added);
  }

  auto
  ListModel::get_item_type () const -> GType
  {
    return g_list_model_get_item_type (const_cast<GListModel*> (gobj ()));
  }

  auto
  ListModel::get_n_items () const -> guint
  {
    return g_list_model_get_n_items (const_cast<GListModel*> (gobj ()));
  }

  auto
  ListModel::get_object (const guint position) -> Glib::RefPtr<ObjectBase>
  {
    return Glib::make_refptr_for_instance<ObjectBase> (
        Glib::wrap_auto (g_list_model_get_object (gobj (), position)));
  }

  auto
  ListModel::get_object (const guint position) const -> Glib::RefPtr<const ObjectBase>
  {
    return const_cast<ListModel*> (this)->get_object (position);
  }

  auto
  ListModel::signal_items_changed () -> Glib::SignalProxy<void (guint, guint, guint)>
  {
    return {this, &ListModel_signal_items_changed_info};
  }

  auto
  ListModel::get_item_type_vfunc () -> GType
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_item_type)
    {
      const GType retval ((*base->get_item_type) (gobj ()));
      return retval;
    }

    using RType = GType;
    return RType ();
  }

  auto
  ListModel::get_n_items_vfunc () -> guint
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_n_items)
    {
      const guint retval ((*base->get_n_items) (gobj ()));
      return retval;
    }

    using RType = guint;
    return RType ();
  }

  auto
  ListModel::get_item_vfunc (const guint position) -> gpointer
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->get_item)
    {
      const gpointer retval ((*base->get_item) (gobj (), position));
      return retval;
    }

    using RType = gpointer;
    return RType ();
  }

} // namespace Gio
