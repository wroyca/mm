// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/menu.hxx>
#include <libmm/gio/menu_p.hxx>

#include <gio/gio.h>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GMenu* object, const bool take_copy) -> RefPtr<gio::Menu>
  {
    return glib::make_refptr_for_instance<gio::Menu> (
        dynamic_cast<gio::Menu*> (wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  Menu_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Menu_Class::class_init_function;

      register_derived_type (g_menu_get_type ());
    }

    return *this;
  }

  auto
  Menu_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Menu_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Menu ((GMenu*) object);
  }

  auto
  Menu::gobj_copy () -> GMenu*
  {
    reference ();
    return gobj ();
  }

  Menu::Menu (const glib::ConstructParams& construct_params)
    : MenuModel (construct_params)
  {
  }

  Menu::Menu (GMenu* castitem)
    : MenuModel ((GMenuModel*) castitem)
  {
  }

  Menu::Menu (Menu&& src) noexcept
    : MenuModel (std::move (src))
  {
  }

  auto
  Menu::operator= (Menu&& src) noexcept -> Menu&
  {
    MenuModel::operator= (std::move (src));
    return *this;
  }

  Menu::~Menu () noexcept = default;

  Menu::CppClassType Menu::menu_class_;

  auto
  Menu::get_type () -> GType
  {
    return menu_class_.init ().get_type ();
  }

  auto
  Menu::get_base_type () -> GType
  {
    return g_menu_get_type ();
  }

  Menu::Menu ()
    : ObjectBase (nullptr),
      MenuModel (glib::ConstructParams (menu_class_.init ()))
  {
  }

  auto
  Menu::create () -> glib::RefPtr<Menu>
  {
    return glib::make_refptr_for_instance<Menu> (new Menu ());
  }

  auto
  Menu::freeze () -> void
  {
    g_menu_freeze (gobj ());
  }

  auto
  Menu::insert_item (const int position,
                     const glib::RefPtr<const MenuItem>& item) -> void
  {
    g_menu_insert_item (gobj (),
                        position,
                        const_cast<GMenuItem*> (glib::unwrap (item)));
  }

  auto
  Menu::prepend_item (const glib::RefPtr<const MenuItem>& item) -> void
  {
    g_menu_prepend_item (gobj (), const_cast<GMenuItem*> (glib::unwrap (item)));
  }

  auto
  Menu::append_item (const glib::RefPtr<const MenuItem>& item) -> void
  {
    g_menu_append_item (gobj (), const_cast<GMenuItem*> (glib::unwrap (item)));
  }

  auto
  Menu::remove (const int position) -> void
  {
    g_menu_remove (gobj (), position);
  }

  auto
  Menu::remove_all () -> void
  {
    g_menu_remove_all (gobj ());
  }

  auto
  Menu::insert (const int position,
                const glib::ustring& label,
                const glib::ustring& detailed_action) -> void
  {
    g_menu_insert (
        gobj (),
        position,
        label.c_str (),
        detailed_action.empty () ? nullptr : detailed_action.c_str ());
  }

  auto
  Menu::insert (const int position, const glib::ustring& label) -> void
  {
    g_menu_insert (gobj (), position, label.c_str (), nullptr);
  }

  auto
  Menu::prepend (const glib::ustring& label,
                 const glib::ustring& detailed_action) -> void
  {
    g_menu_prepend (
        gobj (),
        label.c_str (),
        detailed_action.empty () ? nullptr : detailed_action.c_str ());
  }

  auto
  Menu::prepend (const glib::ustring& label) -> void
  {
    g_menu_prepend (gobj (), label.c_str (), nullptr);
  }

  auto
  Menu::append (const glib::ustring& label,
                const glib::ustring& detailed_action) -> void
  {
    g_menu_append (
        gobj (),
        label.c_str (),
        detailed_action.empty () ? nullptr : detailed_action.c_str ());
  }

  auto
  Menu::append (const glib::ustring& label) -> void
  {
    g_menu_append (gobj (), label.c_str (), nullptr);
  }

  auto
  Menu::insert_section (const int position,
                        const glib::ustring& label,
                        const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_insert_section (gobj (),
                           position,
                           label.empty () ? nullptr : label.c_str (),
                           glib::unwrap (section));
  }

  auto
  Menu::insert_section (const int position,
                        const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_insert_section (gobj (), position, nullptr, glib::unwrap (section));
  }

  auto
  Menu::prepend_section (const glib::ustring& label,
                         const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_prepend_section (gobj (),
                            label.empty () ? nullptr : label.c_str (),
                            glib::unwrap (section));
  }

  auto
  Menu::prepend_section (const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_prepend_section (gobj (), nullptr, glib::unwrap (section));
  }

  auto
  Menu::append_section (const glib::ustring& label,
                        const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_append_section (gobj (),
                           label.empty () ? nullptr : label.c_str (),
                           glib::unwrap (section));
  }

  auto
  Menu::append_section (const glib::RefPtr<MenuModel>& section) -> void
  {
    g_menu_append_section (gobj (), nullptr, glib::unwrap (section));
  }

  auto
  Menu::insert_submenu (const int position,
                        const glib::ustring& label,
                        const glib::RefPtr<MenuModel>& submenu) -> void
  {
    g_menu_insert_submenu (gobj (),
                           position,
                           label.c_str (),
                           glib::unwrap (submenu));
  }

  auto
  Menu::prepend_submenu (const glib::ustring& label,
                         const glib::RefPtr<MenuModel>& submenu) -> void
  {
    g_menu_prepend_submenu (gobj (), label.c_str (), glib::unwrap (submenu));
  }

  auto
  Menu::append_submenu (const glib::ustring& label,
                        const glib::RefPtr<MenuModel>& submenu) -> void
  {
    g_menu_append_submenu (gobj (), label.c_str (), glib::unwrap (submenu));
  }

} // namespace gio
