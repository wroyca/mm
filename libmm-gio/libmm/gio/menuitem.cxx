// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/menuitem.hxx>
#include <libmm/gio/menuitem_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  MenuItem::MenuItem (const Glib::ustring& label,
                      const Glib::ustring& detailed_action)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (menuitem_class_.init ()))
  {
    if (!label.empty ())
      set_label (label);

    if (!detailed_action.empty ())
      set_detailed_action (detailed_action);
  }

  MenuItem::MenuItem (const Glib::ustring& label,
                      const Glib::RefPtr<MenuModel>& submenu)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (menuitem_class_.init ()))
  {
    if (!label.empty ())
      set_label (label);

    set_submenu (submenu);
  }

  MenuItem::MenuItem (const Glib::RefPtr<MenuModel>& submenu)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (menuitem_class_.init ()))
  {
    set_submenu (submenu);
  }

  auto
  MenuItem::set_action (const Glib::ustring& action) -> void
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

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GMenuItem* object, const bool take_copy) -> RefPtr<Gio::MenuItem>
  {
    return Glib::make_refptr_for_instance<Gio::MenuItem> (
        dynamic_cast<Gio::MenuItem*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  MenuItem_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MenuItem ((GMenuItem*) object);
  }

  auto
  MenuItem::gobj_copy () -> GMenuItem*
  {
    reference ();
    return gobj ();
  }

  MenuItem::MenuItem (const Glib::ConstructParams& construct_params)
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
  MenuItem::create (const Glib::ustring& label,
                    const Glib::ustring& detailed_action) -> Glib::RefPtr<MenuItem>
  {
    return Glib::make_refptr_for_instance<MenuItem> (
        new MenuItem (label, detailed_action));
  }

  auto
  MenuItem::create (const Glib::ustring& label,
                    const Glib::RefPtr<MenuModel>& submenu) -> Glib::RefPtr<MenuItem>
  {
    return Glib::make_refptr_for_instance<MenuItem> (
        new MenuItem (label, submenu));
  }

  auto
  MenuItem::create (const Glib::RefPtr<MenuModel>& submenu) -> Glib::RefPtr<MenuItem>
  {
    return Glib::make_refptr_for_instance<MenuItem> (new MenuItem (submenu));
  }

  auto
  MenuItem::set_attribute_value (const Glib::ustring& attribute,
                                 const Glib::VariantBase& value) -> void
  {
    g_menu_item_set_attribute_value (gobj (),
                                     attribute.c_str (),
                                     const_cast<GVariant*> (value.gobj ()));
  }

  auto
  MenuItem::get_link (const Glib::ustring& link) -> Glib::RefPtr<MenuModel>
  {
    return Glib::wrap (g_menu_item_get_link (gobj (), link.c_str ()));
  }

  auto
  MenuItem::get_link (const Glib::ustring& link) const -> Glib::RefPtr<const MenuModel>
  {
    return const_cast<MenuItem*> (this)->get_link (link);
  }

  auto
  MenuItem::set_link (const Glib::ustring& link,
                      const Glib::RefPtr<MenuModel>& model) -> void
  {
    g_menu_item_set_link (gobj (), link.c_str (), Glib::unwrap (model));
  }

  auto
  MenuItem::set_label (const Glib::ustring& label) -> void
  {
    g_menu_item_set_label (gobj (), label.c_str ());
  }

  auto
  MenuItem::set_submenu (const Glib::RefPtr<MenuModel>& submenu) -> void
  {
    g_menu_item_set_submenu (gobj (), Glib::unwrap (submenu));
  }

  auto
  MenuItem::set_section (const Glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_item_set_section (gobj (), Glib::unwrap (section));
  }

  auto
  MenuItem::get_attribute_value (const Glib::ustring& attribute,
                                 const Glib::VariantType& expected_type) const -> Glib::VariantBase
  {
    return Glib::wrap (
        g_menu_item_get_attribute_value (const_cast<GMenuItem*> (gobj ()),
                                         attribute.c_str (),
                                         expected_type.gobj ()),
        false);
  }

  auto
  MenuItem::get_attribute_value (const Glib::ustring& attribute) const -> Glib::VariantBase
  {
    return Glib::wrap (
        g_menu_item_get_attribute_value (const_cast<GMenuItem*> (gobj ()),
                                         attribute.c_str (),
                                         nullptr),
        false);
  }

  auto
  MenuItem::set_action_and_target (const Glib::ustring& action,
                                   const Glib::VariantBase& target_value) -> void
  {
    g_menu_item_set_action_and_target_value (
        gobj (),
        action.c_str (),
        const_cast<GVariant*> (target_value.gobj ()));
  }

  auto
  MenuItem::set_detailed_action (const Glib::ustring& detailed_action) -> void
  {
    g_menu_item_set_detailed_action (gobj (), detailed_action.c_str ());
  }

  auto
  MenuItem::set_icon (const Glib::RefPtr<Icon>& icon) -> void
  {
    g_menu_item_set_icon (gobj (), Glib::unwrap (icon));
  }

} // namespace Gio
