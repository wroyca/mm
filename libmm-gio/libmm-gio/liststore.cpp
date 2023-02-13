


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/liststore.hpp>
#include <mm/gio/private/liststore_p.hpp>


/* Copyright (C) 2016 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <memory>

namespace
{
extern "C"
{
auto ListStoreBase_CompareDataFunc(
  const gconstpointer a, const gconstpointer b, const gpointer user_data) -> int
{
  const auto slot = static_cast<Gio::ListStoreBase::SlotCompare*>(user_data);

  const Glib::RefPtr<const Glib::ObjectBase> item_a =
    Glib::wrap(static_cast<Glib::Object::BaseObjectType*>(const_cast<gpointer>(a)), true);
  const Glib::RefPtr<const Glib::ObjectBase> item_b =
    Glib::wrap(static_cast<Glib::Object::BaseObjectType*>(const_cast<gpointer>(b)), true);

  return (*slot)(item_a, item_b);
}

// gboolean is int
auto ListStoreBase_EqualFuncFull(
  const gconstpointer a, const gconstpointer b, const gpointer user_data) -> gboolean
{
  const auto slot = static_cast<Gio::ListStoreBase::SlotEqual*>(user_data);

  const Glib::RefPtr<const Glib::ObjectBase> item_a =
    Glib::wrap(static_cast<Glib::Object::BaseObjectType*>(const_cast<gpointer>(a)), true);
  const Glib::RefPtr<const Glib::ObjectBase> item_b =
    Glib::wrap(static_cast<Glib::Object::BaseObjectType*>(const_cast<gpointer>(b)), true);

  return (*slot)(item_a, item_b);
}
}
} // anonymous namespace

namespace Gio
{
auto ListStoreBase::splice (
  const guint position, const guint n_removals,
  const std::vector <Glib::RefPtr <ObjectBase>> &additions) -> void
{
  const std::size_t n_additions = additions.size();
  std::unique_ptr<gpointer[]> g_additions{new gpointer[n_additions]};
  for (std::size_t i = 0; i < n_additions; i++)
  {
    g_additions[i] = additions[i]->gobj();
  }
  g_list_store_splice(gobj(), position, n_removals, g_additions.get(), n_additions);
}

auto ListStoreBase::find(const Glib::RefPtr<const ObjectBase>& item) const -> std::pair<bool, unsigned int>
{
  unsigned int position = std::numeric_limits<unsigned int>::max();
  bool result = g_list_store_find(const_cast<GListStore*>(gobj()),
    const_cast<GObject*>(item->gobj()), &position);
  return {result, position};
}

auto ListStoreBase::find(
  const Glib::RefPtr<const ObjectBase>& item, const SlotEqual& slot) const -> std::pair<bool, unsigned int>
{
  // Use the original slot (not a copy).
  const auto slot_ptr = const_cast<SlotEqual*>(&slot);

  unsigned int position = std::numeric_limits<unsigned int>::max();
  bool result = g_list_store_find_with_equal_func_full(
    const_cast<GListStore*>(gobj()), const_cast<GObject*>(item->gobj()),
    &ListStoreBase_EqualFuncFull, slot_ptr, &position);
  return {result, position};
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

auto wrap(GListStore* object, const bool take_copy) -> RefPtr<Gio::ListStoreBase>
{
  return Glib::make_refptr_for_instance<Gio::ListStoreBase>( dynamic_cast<Gio::ListStoreBase*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto ListStoreBase_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListStoreBase_Class::class_init_function;

    // Do not derive a GType, or use a derived class:
    gtype_ = g_list_store_get_type();

  }

  return *this;
}


auto ListStoreBase_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto ListStoreBase_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new ListStoreBase((GListStore*)object);
}


/* The implementation: */

auto ListStoreBase::gobj_copy() -> GListStore*
{
  reference();
  return gobj();
}

ListStoreBase::ListStoreBase(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

ListStoreBase::ListStoreBase(GListStore* castitem)
: Object((GObject*)castitem)
{}


ListStoreBase::ListStoreBase(ListStoreBase&& src) noexcept
: Object(std::move(src))
  , ListModel(std::move(src))
{}

auto ListStoreBase::operator=(ListStoreBase&& src) noexcept -> ListStoreBase&
{
  Object::operator=(std::move(src));
  ListModel::operator=(std::move(src));
  return *this;
}


ListStoreBase::~ListStoreBase() noexcept = default;

ListStoreBase::CppClassType ListStoreBase::liststorebase_class_; // initialize static member

auto ListStoreBase::get_type() -> GType
{
  return liststorebase_class_.init().get_type();
}


auto ListStoreBase::get_base_type() -> GType
{
  return g_list_store_get_type();
}


ListStoreBase::ListStoreBase(const GType item_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(liststorebase_class_.init(), "item_type", item_type, nullptr))
{


}

auto ListStoreBase::create(
  const GType item_type) -> Glib::RefPtr<ListStoreBase>
{
  return Glib::make_refptr_for_instance<ListStoreBase>( new ListStoreBase(item_type) );
}

auto ListStoreBase::insert (
  const guint position, const Glib::RefPtr <ObjectBase> &item) -> void
{
  g_list_store_insert(gobj(), position, item->gobj());
}

auto ListStoreBase::insert_sorted(const Glib::RefPtr<ObjectBase>& item, const SlotCompare& slot) -> guint
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotCompare*>(&slot);

  return g_list_store_insert_sorted(gobj(), item->gobj(), &ListStoreBase_CompareDataFunc, slot_copy);
}

auto ListStoreBase::sort (const SlotCompare &slot) -> void
{
  // Use the original slot (not a copy).
  const auto slot_copy = const_cast<SlotCompare*>(&slot);

  g_list_store_sort(gobj(), &ListStoreBase_CompareDataFunc, slot_copy);
}

auto ListStoreBase::append (const Glib::RefPtr <ObjectBase> &item) -> void
{
  g_list_store_append(gobj(), item->gobj());
}

auto ListStoreBase::remove (
  const guint position) -> void
{
  g_list_store_remove(gobj(), position);
}

auto ListStoreBase::remove_all () -> void
{
  g_list_store_remove_all(gobj());
}


static_assert(Glib::Traits::ValueCompatibleWithWrapProperty<GType>::value,
  "Type GType cannot be used in _WRAP_PROPERTY. "
  "There is no suitable template specialization of Glib::Value<>.");

auto ListStoreBase::property_item_type() const -> Glib::PropertyProxy_ReadOnly< GType >
{
  return {this, "item-type"};
}

auto ListStoreBase::property_n_items() const -> Glib::PropertyProxy_ReadOnly< unsigned int >
{
  return {this, "n-items"};
}


} // namespace Gio


