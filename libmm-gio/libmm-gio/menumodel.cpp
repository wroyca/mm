


#include <mm/glib/mm-glib.hpp>

#include <mm/gio/menumodel.hpp>
#include <mm/gio/private/menumodel_p.hpp>


/* Copyright (C) 2012 The giomm Development Team
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
#include <mm/gio/menuattributeiter.hpp>
#include <mm/gio/menulinkiter.hpp>

using Attribute = Gio::MenuModel::Attribute;
using Link = Gio::MenuModel::Link;

namespace Gio
{

// Make sure the order here is the same order as in Gio::MenuModel::Attribute.
static const char* const _attribute_strings[] = { G_MENU_ATTRIBUTE_ACTION, G_MENU_ATTRIBUTE_LABEL,
  G_MENU_ATTRIBUTE_TARGET, G_MENU_ATTRIBUTE_ACTION_NAMESPACE, G_MENU_ATTRIBUTE_ICON };

auto
giomm_get_menu_attribute(MenuModel::Attribute attribute) -> const char*
{
  return _attribute_strings[static_cast<int>(attribute)];
}

// Make sure the order here is the same order as in Gio::MenuModel::Link.
static const char* const _link_strings[] = { G_MENU_LINK_SECTION, G_MENU_LINK_SUBMENU };

auto
giomm_get_menu_link(MenuModel::Link link) -> const char*
{
  return _link_strings[static_cast<int>(link)];
}

} // namespace Gio

namespace
{


auto MenuModel_signal_items_changed_callback (
  GMenuModel *self, const gint p0, const gint p1, const gint p2, void *data) -> void
{
  using namespace Gio;
  using SlotType = sigc::slot<void(int, int, int)>;

  const auto obj = dynamic_cast<MenuModel*>(Glib::ObjectBase::_get_current_wrapper((GObject*) self));
  // Do not try to call a signal on a disassociated wrapper.
  if(obj)
  {
    try
    {
      if(const auto slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(p0
, p1
, p2
);
    }
    catch(...)
    {
       Glib::exception_handlers_invoke();
    }
  }
}

const Glib::SignalProxyInfo MenuModel_signal_items_changed_info =
{
  "items-changed",
  (GCallback) &MenuModel_signal_items_changed_callback,
  (GCallback) &MenuModel_signal_items_changed_callback
};


} // anonymous namespace


namespace Glib
{

auto wrap(GMenuModel* object, const bool take_copy) -> RefPtr<Gio::MenuModel>
{
  return Glib::make_refptr_for_instance<Gio::MenuModel>( dynamic_cast<Gio::MenuModel*> (wrap_auto((GObject*)object, take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

auto MenuModel_Class::init() -> const Class&
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MenuModel_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_menu_model_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


auto MenuModel_Class::class_init_function (void *g_class, void *class_data) -> void
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


auto MenuModel_Class::wrap_new(GObject* object) -> Glib::ObjectBase*
{
  return new MenuModel((GMenuModel*)object);
}


/* The implementation: */

auto MenuModel::gobj_copy() -> GMenuModel*
{
  reference();
  return gobj();
}

MenuModel::MenuModel(const Glib::ConstructParams& construct_params)
: Object(construct_params)
{

}

MenuModel::MenuModel(GMenuModel* castitem)
: Object((GObject*)castitem)
{}


MenuModel::MenuModel(MenuModel&& src) noexcept
: Object(std::move(src))
{}

auto MenuModel::operator=(MenuModel&& src) noexcept -> MenuModel&
{
  Object::operator=(std::move(src));
  return *this;
}


MenuModel::~MenuModel() noexcept = default;

MenuModel::CppClassType MenuModel::menumodel_class_; // initialize static member

auto MenuModel::get_type() -> GType
{
  return menumodel_class_.init().get_type();
}


auto MenuModel::get_base_type() -> GType
{
  return g_menu_model_get_type();
}


MenuModel::MenuModel()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
ObjectBase(nullptr),
Object(Glib::ConstructParams(menumodel_class_.init()))
{


}

auto MenuModel::get_item_attribute(
  const int item_index, const Attribute attribute, const Glib::VariantType& expected_type) const -> Glib::VariantBase
{
  return Glib::wrap(g_menu_model_get_item_attribute_value(const_cast<GMenuModel*>(gobj()), item_index, giomm_get_menu_attribute(attribute), expected_type.gobj()), false);
}

auto MenuModel::get_item_link(
  const int item_index, const Link link) -> Glib::RefPtr<MenuModel>
{
  return Glib::wrap(g_menu_model_get_item_link(gobj(), item_index, giomm_get_menu_link(link)));
}

auto MenuModel::get_item_link(
  const int item_index, const Link link) const -> Glib::RefPtr<const MenuModel>
{
  return const_cast<MenuModel*>(this)->get_item_link(item_index, link);
}

auto MenuModel::is_mutable() const -> bool
{
  return g_menu_model_is_mutable(const_cast<GMenuModel*>(gobj()));
}

auto MenuModel::get_n_items() const -> int
{
  return g_menu_model_get_n_items(const_cast<GMenuModel*>(gobj()));
}

auto MenuModel::iterate_item_attributes(
  const int item_index) -> Glib::RefPtr<MenuAttributeIter>
{
  return Glib::wrap(g_menu_model_iterate_item_attributes(gobj(), item_index));
}

auto MenuModel::iterate_item_attributes(
  const int item_index) const -> Glib::RefPtr<const MenuAttributeIter>
{
  return const_cast<MenuModel*>(this)->iterate_item_attributes(item_index);
}

auto MenuModel::iterate_item_links(
  const int item_index) -> Glib::RefPtr<MenuLinkIter>
{
  return Glib::wrap(g_menu_model_iterate_item_links(gobj(), item_index));
}

auto MenuModel::iterate_item_links(
  const int item_index) const -> Glib::RefPtr<const MenuLinkIter>
{
  return const_cast<MenuModel*>(this)->iterate_item_links(item_index);
}

auto MenuModel::items_changed (
  const int position, const int removed, const int added) -> void
{
  g_menu_model_items_changed(gobj(), position, removed, added);
}


auto MenuModel::signal_items_changed() -> Glib::SignalProxy<void(int, int, int)>
{
  return {this, &MenuModel_signal_items_changed_info};
}


} // namespace Gio


