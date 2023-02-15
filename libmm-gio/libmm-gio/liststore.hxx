// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_LISTSTORE_H
#define _GIOMM_LISTSTORE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <limits>
#include <type_traits>
#include <utility>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT ListStoreBase_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT ListStoreBase : public Glib::Object,
                                  public ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ListStoreBase;
    using CppClassType = ListStoreBase_Class;
    using BaseObjectType = GListStore;
    using BaseClassType = GListStoreClass;

    ListStoreBase (const ListStoreBase&) = delete;
    auto
    operator= (const ListStoreBase&) -> ListStoreBase& = delete;

  private:
    friend class ListStoreBase_Class;
    static CppClassType liststorebase_class_;

  protected:
    explicit ListStoreBase (const Glib::ConstructParams& construct_params);
    explicit ListStoreBase (GListStore* castitem);

#endif

  public:
    ListStoreBase (ListStoreBase&& src) noexcept;
    auto
    operator= (ListStoreBase&& src) noexcept -> ListStoreBase&;

    ~ListStoreBase () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GListStore*
    {
      return reinterpret_cast<GListStore*> (gobject_);
    }

    auto
    gobj () const -> const GListStore*
    {
      return reinterpret_cast<GListStore*> (gobject_);
    }

    auto
    gobj_copy () -> GListStore*;

  private:
  protected:
    explicit ListStoreBase (GType item_type);

  public:
    static auto
    create (GType item_type) -> Glib::RefPtr<ListStoreBase>;

    auto
    insert (guint position, const Glib::RefPtr<Glib::ObjectBase>& item) -> void;

    using SlotCompare =
        sigc::slot<int (const Glib::RefPtr<const Glib::ObjectBase>&,
                        const Glib::RefPtr<const Glib::ObjectBase>&)>;

    auto
    insert_sorted (const Glib::RefPtr<Glib::ObjectBase>& item,
                   const SlotCompare& slot) -> guint;

    auto
    sort (const SlotCompare& slot) -> void;

    auto
    append (const Glib::RefPtr<Glib::ObjectBase>& item) -> void;

    auto
    remove (guint position) -> void;

    auto
    remove_all () -> void;

    auto
    splice (guint position,
            guint n_removals,
            const std::vector<Glib::RefPtr<Glib::ObjectBase>>& additions)
        -> void;

    auto
    find (const Glib::RefPtr<const Glib::ObjectBase>& item) const
        -> std::pair<bool, unsigned int>;

    using SlotEqual =
        sigc::slot<bool (const Glib::RefPtr<const Glib::ObjectBase>&,
                         const Glib::RefPtr<const Glib::ObjectBase>&)>;

    auto
    find (const Glib::RefPtr<const Glib::ObjectBase>& item,
          const SlotEqual& slot) const -> std::pair<bool, unsigned int>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

  template <typename T_item>
  class ListStore : public ListStoreBase
  {
    static_assert (
        std::is_base_of<Glib::ObjectBase, T_item>::value,
        "T_item must be Glib::ObjectBase or derived from Glib::ObjectBase.");

  protected:
    ListStore ();

  public:
    static auto
    create () -> Glib::RefPtr<ListStore>;

    auto
    get_item (guint position) -> Glib::RefPtr<T_item>;

    auto
    get_item (guint position) const -> Glib::RefPtr<const T_item>;

    auto
    insert (guint position, const Glib::RefPtr<T_item>& item) -> void;

    using SlotCompare = sigc::slot<int (const Glib::RefPtr<const T_item>&,
                                        const Glib::RefPtr<const T_item>&)>;

    auto
    insert_sorted (const Glib::RefPtr<T_item>& item, const SlotCompare& slot)
        -> guint;

    auto
    sort (const SlotCompare& slot) -> void;

    auto
    append (const Glib::RefPtr<T_item>& item) -> void;

    auto
    splice (guint position,
            guint n_removals,
            const std::vector<Glib::RefPtr<T_item>>& additions) -> void;

    auto
    find (const Glib::RefPtr<const T_item>& item) const
        -> std::pair<bool, unsigned int>;

    using SlotEqual = sigc::slot<bool (const Glib::RefPtr<const T_item>&,
                                       const Glib::RefPtr<const T_item>&)>;

    auto
    find (const Glib::RefPtr<const T_item>& item, const SlotEqual& slot) const
        -> std::pair<bool, unsigned int>;

  private:
    static auto
    compare_data_func (gconstpointer a, gconstpointer b, gpointer user_data)
        -> int;

    static auto
    equal_func_full (gconstpointer a, gconstpointer b, gpointer user_data)
        -> gboolean;
  };

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <typename T_item>
  ListStore<T_item>::ListStore ()
    : ListStoreBase (T_item::get_base_type ())
  {
  }

  template <typename T_item>
  auto
  ListStore<T_item>::create () -> Glib::RefPtr<ListStore<T_item>>
  {
    return Glib::make_refptr_for_instance<ListStore<T_item>> (
        new ListStore<T_item> ());
  }

  template <typename T_item>
  auto
  ListStore<T_item>::get_item (guint position) -> Glib::RefPtr<T_item>
  {
    return std::dynamic_pointer_cast<T_item> (ListModel::get_object (position));
  }

  template <typename T_item>
  auto
  ListStore<T_item>::get_item (guint position) const -> Glib::RefPtr<const T_item>
  {
    return const_cast<ListStore<T_item>*> (this)->get_item (position);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::insert (guint position, const Glib::RefPtr<T_item>& item) -> void
  {
    ListStoreBase::insert (position, item);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::insert_sorted (const Glib::RefPtr<T_item>& item,
                                    const SlotCompare& slot) -> guint
  {
    auto slot_copy = const_cast<SlotCompare*> (&slot);

    return g_list_store_insert_sorted (gobj (),
                                       item->gobj (),
                                       &compare_data_func,
                                       slot_copy);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::sort (const SlotCompare& slot) -> void
  {
    auto slot_copy = const_cast<SlotCompare*> (&slot);

    g_list_store_sort (gobj (), &compare_data_func, slot_copy);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::append (const Glib::RefPtr<T_item>& item) -> void
  {
    ListStoreBase::append (item);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::splice (guint position,
                             guint n_removals,
                             const std::vector<Glib::RefPtr<T_item>>& additions) -> void
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

  template <typename T_item>
  auto
  ListStore<T_item>::find (const Glib::RefPtr<const T_item>& item) const -> std::pair<bool, unsigned int>
  {
    return ListStoreBase::find (item);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::find (const Glib::RefPtr<const T_item>& item,
                           const SlotEqual& slot) const -> std::pair<bool, unsigned int>
  {
    auto slot_ptr = const_cast<SlotEqual*> (&slot);

    unsigned int position = std::numeric_limits<unsigned int>::max ();
    bool result = g_list_store_find_with_equal_func_full (
        const_cast<GListStore*> (gobj ()),
        const_cast<typename T_item::BaseObjectType*> (item->gobj ()),
        &equal_func_full,
        slot_ptr,
        &position);
    return {result, position};
  }

  template <typename T_item>
  auto
  ListStore<T_item>::compare_data_func (gconstpointer a,
                                        gconstpointer b,
                                        gpointer user_data) -> int
  {
    auto slot = static_cast<SlotCompare*> (user_data);

    const Glib::RefPtr<const T_item> item_a =
        std::dynamic_pointer_cast<T_item> (
            Glib::wrap (static_cast<typename T_item::BaseObjectType*> (
                            const_cast<gpointer> (a)),
                        true));
    const Glib::RefPtr<const T_item> item_b =
        std::dynamic_pointer_cast<T_item> (
            Glib::wrap (static_cast<typename T_item::BaseObjectType*> (
                            const_cast<gpointer> (b)),
                        true));

    return (*slot) (item_a, item_b);
  }

  template <typename T_item>
  auto
  ListStore<T_item>::equal_func_full (gconstpointer a,
                                      gconstpointer b,
                                      gpointer user_data) -> gboolean
  {
    auto slot = static_cast<SlotEqual*> (user_data);

    const Glib::RefPtr<const T_item> item_a =
        std::dynamic_pointer_cast<T_item> (
            Glib::wrap (static_cast<typename T_item::BaseObjectType*> (
                            const_cast<gpointer> (a)),
                        true));
    const Glib::RefPtr<const T_item> item_b =
        std::dynamic_pointer_cast<T_item> (
            Glib::wrap (static_cast<typename T_item::BaseObjectType*> (
                            const_cast<gpointer> (b)),
                        true));

    return (*slot) (item_a, item_b);
  }

#endif

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GListStore* object, bool take_copy = false) -> Glib::RefPtr<Gio::ListStoreBase>;
} // namespace Glib

#endif
