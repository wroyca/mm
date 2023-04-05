// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/menuitem.hxx>
#include <libmm/gio/menuitem_p.hxx>

#include <gio/gio.h>

namespace gio
{

  MenuItem::MenuItem (const glib::ustring& label,
                      const glib::ustring& detailed_action)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (menuitem_class_.init ()))
  {
    if (!label.empty ())
      set_label (label);

    if (!detailed_action.empty ())
      set_detailed_action (detailed_action);
  }

  MenuItem::MenuItem (const glib::ustring& label,
                      const glib::RefPtr<MenuModel>& submenu)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (menuitem_class_.init ()))
  {
    if (!label.empty ())
      set_label (label);

    set_submenu (submenu);
  }

  MenuItem::MenuItem (const glib::RefPtr<MenuModel>& submenu)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (menuitem_class_.init ()))
  {
    set_submenu (submenu);
  }

  auto
  MenuItem::set_action (const glib::ustring& action) -> void
  {
    g_menu_item_set_action_and_target_value (gobj (), action.c_str (), nullptr);
  }

  auto
  MenuItem::unset_target () -> void
  {
    const gchar* action_name = nullptr;
    g_menu_item_get_attribute (gobj (),
                               G_MENU_ATTRIBUTE_ACTION,
                               "&s",
                               &action_name);

    g_menu_item_set_action_and_target_value (gobj (), action_name, nullptr);
  }

  auto
  MenuItem::unset_action_and_target () -> void
  {
    g_menu_item_set_action_and_target_value (gobj (), nullptr, nullptr);
  }

  auto
  MenuItem::unset_icon () -> void
  {
    g_menu_item_set_icon (gobj (), nullptr);
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GMenuItem* object, const bool take_copy) -> RefPtr<gio::MenuItem>
  {
    return glib::make_refptr_for_instance<gio::MenuItem> (
        dynamic_cast<gio::MenuItem*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  MenuItem_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuItem_Class::class_init_function;

      register_derived_type (g_menu_item_get_type ());
    }

    return *this;
  }

  auto
  MenuItem_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuItem_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new MenuItem ((GMenuItem*) object);
  }

  auto
  MenuItem::gobj_copy () -> GMenuItem*
  {
    reference ();
    return gobj ();
  }

  MenuItem::MenuItem (const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  MenuItem::MenuItem (GMenuItem* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MenuItem::MenuItem (MenuItem&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  MenuItem::operator= (MenuItem&& src) noexcept -> MenuItem&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  MenuItem::~MenuItem () noexcept = default;

  MenuItem::CppClassType MenuItem::menuitem_class_;

  auto
  MenuItem::get_type () -> GType
  {
    return menuitem_class_.init ().get_type ();
  }

  auto
  MenuItem::get_base_type () -> GType
  {
    return g_menu_item_get_type ();
  }

  auto
  MenuItem::create (const glib::ustring& label,
                    const glib::ustring& detailed_action) -> glib::RefPtr<MenuItem>
  {
    return glib::make_refptr_for_instance<MenuItem> (
        new MenuItem (label, detailed_action));
  }

  auto
  MenuItem::create (const glib::ustring& label,
                    const glib::RefPtr<MenuModel>& submenu) -> glib::RefPtr<MenuItem>
  {
    return glib::make_refptr_for_instance<MenuItem> (
        new MenuItem (label, submenu));
  }

  auto
  MenuItem::create (const glib::RefPtr<MenuModel>& submenu) -> glib::RefPtr<MenuItem>
  {
    return glib::make_refptr_for_instance<MenuItem> (new MenuItem (submenu));
  }

  auto
  MenuItem::set_attribute_value (const glib::ustring& attribute,
                                 const glib::VariantBase& value) -> void
  {
    g_menu_item_set_attribute_value (gobj (),
                                     attribute.c_str (),
                                     const_cast<GVariant*> (value.gobj ()));
  }

  auto
  MenuItem::get_link (const glib::ustring& link) -> glib::RefPtr<MenuModel>
  {
    return glib::wrap (g_menu_item_get_link (gobj (), link.c_str ()));
  }

  auto
  MenuItem::get_link (const glib::ustring& link) const -> glib::RefPtr<const MenuModel>
  {
    return const_cast<MenuItem*> (this)->get_link (link);
  }

  auto
  MenuItem::set_link (const glib::ustring& link,
                      const glib::RefPtr<MenuModel>& model) -> void
  {
    g_menu_item_set_link (gobj (), link.c_str (), glib::unwrap (model));
  }

  auto
  MenuItem::set_label (const glib::ustring& label) -> void
  {
    g_menu_item_set_label (gobj (), label.c_str ());
  }

  auto
  MenuItem::set_submenu (const glib::RefPtr<MenuModel>& submenu) -> void
  {
    g_menu_item_set_submenu (gobj (), glib::unwrap (submenu));
  }

  auto
  MenuItem::set_section (const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_item_set_section (gobj (), glib::unwrap (section));
  }

  auto
  MenuItem::get_attribute_value (const glib::ustring& attribute,
                                 const glib::VariantType& expected_type) const -> glib::VariantBase
  {
    return glib::wrap (
        g_menu_item_get_attribute_value (const_cast<GMenuItem*> (gobj ()),
                                         attribute.c_str (),
                                         expected_type.gobj ()),
        false);
  }

  auto
  MenuItem::get_attribute_value (const glib::ustring& attribute) const -> glib::VariantBase
  {
    return glib::wrap (
        g_menu_item_get_attribute_value (const_cast<GMenuItem*> (gobj ()),
                                         attribute.c_str (),
                                         nullptr),
        false);
  }

  auto
  MenuItem::set_action_and_target (const glib::ustring& action,
                                   const glib::VariantBase& target_value) -> void
  {
    g_menu_item_set_action_and_target_value (
        gobj (),
        action.c_str (),
        const_cast<GVariant*> (target_value.gobj ()));
  }

  auto
  MenuItem::set_detailed_action (const glib::ustring& detailed_action) -> void
  {
    g_menu_item_set_detailed_action (gobj (), detailed_action.c_str ());
  }

  auto
  MenuItem::set_icon (const glib::RefPtr<Icon>& icon) -> void
  {
    g_menu_item_set_icon (gobj (), glib::unwrap (icon));
  }

} // namespace gio
