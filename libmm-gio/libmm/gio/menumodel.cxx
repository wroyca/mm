// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gio/menumodel_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/menuattributeiter.hxx>
#include <libmm/gio/menulinkiter.hxx>

using Attribute = gio::MenuModel::Attribute;
using Link = gio::MenuModel::Link;

namespace gio
{

  static const char* const _attribute_strings[] = {
      G_MENU_ATTRIBUTE_ACTION,
      G_MENU_ATTRIBUTE_LABEL,
      G_MENU_ATTRIBUTE_TARGET,
      G_MENU_ATTRIBUTE_ACTION_NAMESPACE,
      G_MENU_ATTRIBUTE_ICON};

  auto
  giomm_get_menu_attribute (MenuModel::Attribute attribute) -> const char*
  {
    return _attribute_strings[static_cast<int> (attribute)];
  }

  static const char* const _link_strings[] = {G_MENU_LINK_SECTION,
                                              G_MENU_LINK_SUBMENU};

  auto
  giomm_get_menu_link (MenuModel::Link link) -> const char*
  {
    return _link_strings[static_cast<int> (link)];
  }

} // namespace gio

namespace
{

  auto
  MenuModel_signal_items_changed_callback (GMenuModel* self,
                                           const gint p0,
                                           const gint p1,
                                           const gint p2,
                                           void* data) -> void
  {
    using namespace gio;
    using SlotType = sigc::slot<void (int, int, int)>;

    const auto obj = dynamic_cast<MenuModel*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (p0, p1, p2);
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  const glib::SignalProxyInfo MenuModel_signal_items_changed_info = {
      "items-changed",
      (GCallback) &MenuModel_signal_items_changed_callback,
      (GCallback) &MenuModel_signal_items_changed_callback};

} // namespace

namespace glib
{

  auto
  wrap (GMenuModel* object, const bool take_copy) -> RefPtr<gio::MenuModel>
  {
    return glib::make_refptr_for_instance<gio::MenuModel> (
        dynamic_cast<gio::MenuModel*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  MenuModel_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuModel_Class::class_init_function;

      register_derived_type (g_menu_model_get_type ());
    }

    return *this;
  }

  auto
  MenuModel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuModel_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MenuModel ((GMenuModel*) object);
  }

  auto
  MenuModel::gobj_copy () -> GMenuModel*
  {
    reference ();
    return gobj ();
  }

  MenuModel::MenuModel (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  MenuModel::MenuModel (GMenuModel* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MenuModel::MenuModel (MenuModel&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  MenuModel::operator= (MenuModel&& src) noexcept -> MenuModel&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  MenuModel::~MenuModel () noexcept = default;

  MenuModel::CppClassType MenuModel::menumodel_class_;

  auto
  MenuModel::get_type () -> GType
  {
    return menumodel_class_.init ().get_type ();
  }

  auto
  MenuModel::get_base_type () -> GType
  {
    return g_menu_model_get_type ();
  }

  MenuModel::MenuModel ()
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (menumodel_class_.init ()))
  {
  }

  auto
  MenuModel::get_item_attribute (const int item_index,
                                 const Attribute attribute,
                                 const glib::VariantType& expected_type) const -> glib::VariantBase
  {
    return glib::wrap (g_menu_model_get_item_attribute_value (
                           const_cast<GMenuModel*> (gobj ()),
                           item_index,
                           giomm_get_menu_attribute (attribute),
                           expected_type.gobj ()),
                       false);
  }

  auto
  MenuModel::get_item_link (const int item_index, const Link link) -> glib::RefPtr<MenuModel>
  {
    return glib::wrap (g_menu_model_get_item_link (gobj (),
                                                   item_index,
                                                   giomm_get_menu_link (link)));
  }

  auto
  MenuModel::get_item_link (const int item_index, const Link link) const -> glib::RefPtr<const MenuModel>
  {
    return const_cast<MenuModel*> (this)->get_item_link (item_index, link);
  }

  auto
  MenuModel::is_mutable () const -> bool
  {
    return g_menu_model_is_mutable (const_cast<GMenuModel*> (gobj ()));
  }

  auto
  MenuModel::get_n_items () const -> int
  {
    return g_menu_model_get_n_items (const_cast<GMenuModel*> (gobj ()));
  }

  auto
  MenuModel::iterate_item_attributes (const int item_index) -> glib::RefPtr<MenuAttributeIter>
  {
    return glib::wrap (
        g_menu_model_iterate_item_attributes (gobj (), item_index));
  }

  auto
  MenuModel::iterate_item_attributes (const int item_index) const -> glib::RefPtr<const MenuAttributeIter>
  {
    return const_cast<MenuModel*> (this)->iterate_item_attributes (item_index);
  }

  auto
  MenuModel::iterate_item_links (const int item_index) -> glib::RefPtr<MenuLinkIter>
  {
    return glib::wrap (g_menu_model_iterate_item_links (gobj (), item_index));
  }

  auto
  MenuModel::iterate_item_links (const int item_index) const -> glib::RefPtr<const MenuLinkIter>
  {
    return const_cast<MenuModel*> (this)->iterate_item_links (item_index);
  }

  auto
  MenuModel::items_changed (const int position,
                            const int removed,
                            const int added) -> void
  {
    g_menu_model_items_changed (gobj (), position, removed, added);
  }

  auto
  MenuModel::signal_items_changed () -> glib::SignalProxy<void (int, int, int)>
  {
    return {this, &MenuModel_signal_items_changed_info};
  }

} // namespace gio
