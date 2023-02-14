// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/popovermenu.hxx>
#include <libmm-gtk/popovermenu_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{

  PopoverMenu::PopoverMenu (const Glib::RefPtr<Gio::MenuModel>& model,
                            Flags flags)
    : PopoverMenu ((GtkPopoverMenu*) gtk_popover_menu_new_from_model_full (
          Glib::unwrap (model),
          static_cast<GtkPopoverMenuFlags> (flags)))
  {
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::PopoverMenu::Flags>::value_type () -> GType
{
  return gtk_popover_menu_flags_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkPopoverMenu* object, const bool take_copy) -> Gtk::PopoverMenu*
  {
    return dynamic_cast<Gtk::PopoverMenu*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PopoverMenu_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PopoverMenu_Class::class_init_function;

      register_derived_type (gtk_popover_menu_get_type ());
    }

    return *this;
  }

  auto
  PopoverMenu_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PopoverMenu_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PopoverMenu ((GtkPopoverMenu*) o));
  }

  PopoverMenu::PopoverMenu (const Glib::ConstructParams& construct_params)
    : Popover (construct_params)
  {
  }

  PopoverMenu::PopoverMenu (GtkPopoverMenu* castitem)
    : Popover ((GtkPopover*) castitem)
  {
  }

  PopoverMenu::PopoverMenu (PopoverMenu&& src) noexcept
    : Popover (std::move (src))
  {
  }

  auto
  PopoverMenu::operator= (PopoverMenu&& src) noexcept -> PopoverMenu&
  {
    Popover::operator= (std::move (src));
    return *this;
  }

  PopoverMenu::~PopoverMenu () noexcept
  {
    destroy_ ();
  }

  PopoverMenu::CppClassType PopoverMenu::popovermenu_class_;

  auto
  PopoverMenu::get_type () -> GType
  {
    return popovermenu_class_.init ().get_type ();
  }

  auto
  PopoverMenu::get_base_type () -> GType
  {
    return gtk_popover_menu_get_type ();
  }

  auto
  PopoverMenu::set_menu_model (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_popover_menu_set_menu_model (gobj (), Glib::unwrap (model));
  }

  auto
  PopoverMenu::get_menu_model () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_popover_menu_get_menu_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PopoverMenu::get_menu_model () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<PopoverMenu*> (this)->get_menu_model ();
  }

  auto
  PopoverMenu::add_child (Widget& child, const Glib::ustring& id) -> bool
  {
    return gtk_popover_menu_add_child (gobj (), child.gobj (), id.c_str ());
  }

  auto
  PopoverMenu::remove_child (Widget& child) -> bool
  {
    return gtk_popover_menu_remove_child (gobj (), child.gobj ());
  }

  auto
  PopoverMenu::property_visible_submenu () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "visible-submenu"};
  }

  auto
  PopoverMenu::property_visible_submenu () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "visible-submenu"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PopoverMenu::property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  auto
  PopoverMenu::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

} // namespace Gtk
