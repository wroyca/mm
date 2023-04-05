// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/popovermenu.hxx>
#include <libmm/gtk/popovermenu_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{

  PopoverMenu::PopoverMenu (const glib::RefPtr<gio::MenuModel>& model,
                            Flags flags)
    : PopoverMenu ((GtkPopoverMenu*) gtk_popover_menu_new_from_model_full (
          glib::unwrap (model),
          static_cast<GtkPopoverMenuFlags> (flags)))
  {
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::PopoverMenu::Flags>::value_type () -> GType
{
  return gtk_popover_menu_flags_get_type ();
}

namespace glib
{

  auto
  wrap (GtkPopoverMenu* object, bool take_copy) -> gtk::PopoverMenu*
  {
    return dynamic_cast<gtk::PopoverMenu*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  PopoverMenu_Class::init () -> const glib::Class&
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
  PopoverMenu_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PopoverMenu ((GtkPopoverMenu*) (o)));
  }

  PopoverMenu::PopoverMenu (const glib::ConstructParams& construct_params)
    : gtk::Popover (construct_params)
  {
  }

  PopoverMenu::PopoverMenu (GtkPopoverMenu* castitem)
    : gtk::Popover ((GtkPopover*) (castitem))
  {
  }

  PopoverMenu::PopoverMenu (PopoverMenu&& src) noexcept
    : gtk::Popover (std::move (src))
  {
  }

  auto
  PopoverMenu::operator= (PopoverMenu&& src) noexcept -> PopoverMenu&
  {
    gtk::Popover::operator= (std::move (src));
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
  PopoverMenu::set_menu_model (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_popover_menu_set_menu_model (gobj (), glib::unwrap (model));
  }

  auto
  PopoverMenu::get_menu_model () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_popover_menu_get_menu_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PopoverMenu::get_menu_model () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<PopoverMenu*> (this)->get_menu_model ();
  }

  auto
  PopoverMenu::add_child (Widget& child, const glib::ustring& id) -> bool
  {
    return gtk_popover_menu_add_child (gobj (), (child).gobj (), id.c_str ());
  }

  auto
  PopoverMenu::remove_child (Widget& child) -> bool
  {
    return gtk_popover_menu_remove_child (gobj (), (child).gobj ());
  }

  auto
  PopoverMenu::property_visible_submenu () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "visible-submenu");
  }

  auto
  PopoverMenu::property_visible_submenu () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "visible-submenu");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PopoverMenu::property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  PopoverMenu::property_menu_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "menu-model");
  }

} // namespace gtk
