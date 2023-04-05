// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/liststore.hxx>
#include <libmm/gio/liststore_p.hxx>

#include <gio/gio.h>
#include <memory>

namespace
{
  extern "C"
  {
    auto
    ListStoreBase_CompareDataFunc (const gconstpointer a,
                                   const gconstpointer b,
                                   const gpointer user_data) -> int
    {
      const auto slot =
          static_cast<gio::ListStoreBase::SlotCompare*> (user_data);

      const glib::RefPtr<const glib::ObjectBase> item_a = glib::wrap (
          static_cast<glib::Object::BaseObjectType*> (const_cast<gpointer> (a)),
          true);
      const glib::RefPtr<const glib::ObjectBase> item_b = glib::wrap (
          static_cast<glib::Object::BaseObjectType*> (const_cast<gpointer> (b)),
          true);

      return (*slot) (item_a, item_b);
    }

    auto
    ListStoreBase_EqualFuncFull (const gconstpointer a,
                                 const gconstpointer b,
                                 const gpointer user_data) -> gboolean
    {
      const auto slot = static_cast<gio::ListStoreBase::SlotEqual*> (user_data);

      const glib::RefPtr<const glib::ObjectBase> item_a = glib::wrap (
          static_cast<glib::Object::BaseObjectType*> (const_cast<gpointer> (a)),
          true);
      const glib::RefPtr<const glib::ObjectBase> item_b = glib::wrap (
          static_cast<glib::Object::BaseObjectType*> (const_cast<gpointer> (b)),
          true);

      return (*slot) (item_a, item_b);
    }
  }
} // namespace

namespace gio
{
  auto
  ListStoreBase::splice (const guint position,
                         const guint n_removals,
                         const std::vector<glib::RefPtr<ObjectBase>>& additions) -> void
  {
    const std::size_t n_additions = additions.size ();
    std::unique_ptr<gpointer[]> g_additions{new gpointer[n_additions]};
    for (std::size_t i = 0; i < n_additions; i++)
    {
      g_additions[i] = additions[i]->gobj ();
    }
    g_list_store_splice (gobj (),
                         position,
                         n_removals,
                         g_additions.get (),
                         n_additions);
  }

  auto
  ListStoreBase::find (const glib::RefPtr<const ObjectBase>& item) const -> std::pair<bool, unsigned int>
  {
    unsigned int position = std::numeric_limits<unsigned int>::max ();
    bool result = g_list_store_find (const_cast<GListStore*> (gobj ()),
                                     const_cast<GObject*> (item->gobj ()),
                                     &position);
    return {result, position};
  }

  auto
  ListStoreBase::find (const glib::RefPtr<const ObjectBase>& item,
                       const SlotEqual& slot) const -> std::pair<bool, unsigned int>
  {
    const auto slot_ptr = const_cast<SlotEqual*> (&slot);

    unsigned int position = std::numeric_limits<unsigned int>::max ();
    bool result = g_list_store_find_with_equal_func_full (
        const_cast<GListStore*> (gobj ()),
        const_cast<GObject*> (item->gobj ()),
        &ListStoreBase_EqualFuncFull,
        slot_ptr,
        &position);
    return {result, position};
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GListStore* object, const bool take_copy) -> RefPtr<gio::ListStoreBase>
  {
    return glib::make_refptr_for_instance<gio::ListStoreBase> (
        dynamic_cast<gio::ListStoreBase*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  ListStoreBase_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ListStoreBase_Class::class_init_function;

      gtype_ = g_list_store_get_type ();
    }

    return *this;
  }

  auto
  ListStoreBase_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ListStoreBase_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ListStoreBase ((GListStore*) object);
  }

  auto
  ListStoreBase::gobj_copy () -> GListStore*
  {
    reference ();
    return gobj ();
  }

  ListStoreBase::ListStoreBase (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ListStoreBase::ListStoreBase (GListStore* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ListStoreBase::ListStoreBase (ListStoreBase&& src) noexcept
    : Object (std::move (src)),
      ListModel (std::move (src))
  {
  }

  auto
  ListStoreBase::operator= (ListStoreBase&& src) noexcept -> ListStoreBase&
  {
    Object::operator= (std::move (src));
    ListModel::operator= (std::move (src));
    return *this;
  }

  ListStoreBase::~ListStoreBase () noexcept = default;

  ListStoreBase::CppClassType ListStoreBase::liststorebase_class_;

  auto
  ListStoreBase::get_type () -> GType
  {
    return liststorebase_class_.init ().get_type ();
  }

  auto
  ListStoreBase::get_base_type () -> GType
  {
    return g_list_store_get_type ();
  }

  ListStoreBase::ListStoreBase (const GType item_type)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (liststorebase_class_.init (),
                                     "item_type",
                                     item_type,
                                     nullptr))
  {
  }

  auto
  ListStoreBase::create (const GType item_type) -> glib::RefPtr<ListStoreBase>
  {
    return glib::make_refptr_for_instance<ListStoreBase> (
        new ListStoreBase (item_type));
  }

  auto
  ListStoreBase::insert (const guint position,
                         const glib::RefPtr<ObjectBase>& item) -> void
  {
    g_list_store_insert (gobj (), position, item->gobj ());
  }

  auto
  ListStoreBase::insert_sorted (const glib::RefPtr<ObjectBase>& item,
                                const SlotCompare& slot) -> guint
  {
    const auto slot_copy = const_cast<SlotCompare*> (&slot);

    return g_list_store_insert_sorted (gobj (),
                                       item->gobj (),
                                       &ListStoreBase_CompareDataFunc,
                                       slot_copy);
  }

  auto
  ListStoreBase::sort (const SlotCompare& slot) -> void
  {
    const auto slot_copy = const_cast<SlotCompare*> (&slot);

    g_list_store_sort (gobj (), &ListStoreBase_CompareDataFunc, slot_copy);
  }

  auto
  ListStoreBase::append (const glib::RefPtr<ObjectBase>& item) -> void
  {
    g_list_store_append (gobj (), item->gobj ());
  }

  auto
  ListStoreBase::remove (const guint position) -> void
  {
    g_list_store_remove (gobj (), position);
  }

  auto
  ListStoreBase::remove_all () -> void
  {
    g_list_store_remove_all (gobj ());
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
      "Type GType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ListStoreBase::property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>
  {
    return {this, "item-type"};
  }

  auto
  ListStoreBase::property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return {this, "n-items"};
  }

} // namespace gio
