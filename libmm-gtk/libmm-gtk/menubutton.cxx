// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/menubutton.hxx>
#include <libmm-gtk/menubutton_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  SignalProxy_MenuButton_create_popup_callback (GtkMenuButton*,
                                                const gpointer user_data) -> void
  {
    const auto the_slot =
        static_cast<Gtk::MenuButton::SlotCreatePopup*> (user_data);

    try
    {
      (*the_slot) ();
    }
    catch (...)
    {
      Glib::exception_handlers_invoke ();
    }
    return;
  }

} // namespace

namespace Gtk
{

  auto
  MenuButton::unset_popover () -> void
  {
    gtk_menu_button_set_popover (gobj (), nullptr);
  }

  auto
  MenuButton::unset_menu_model () -> void
  {
    gtk_menu_button_set_menu_model (gobj (), nullptr);
  }

  auto
  MenuButton::set_create_popup_func (const SlotCreatePopup& slot) -> void
  {
    const auto slot_copy = new SlotCreatePopup (slot);

    gtk_menu_button_set_create_popup_func (
        gobj (),
        &SignalProxy_MenuButton_create_popup_callback,
        slot_copy,
        &Glib::destroy_notify_delete<SlotCreatePopup>);
  }

  auto
  MenuButton::unset_create_popup_func () -> void
  {
    gtk_menu_button_set_create_popup_func (gobj (), nullptr, nullptr, nullptr);
  }

  auto
  MenuButton::unset_child () -> void
  {
    gtk_menu_button_set_child (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkMenuButton* object, const bool take_copy) -> Gtk::MenuButton*
  {
    return dynamic_cast<Gtk::MenuButton*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MenuButton_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuButton_Class::class_init_function;

      register_derived_type (gtk_menu_button_get_type ());
    }

    return *this;
  }

  auto
  MenuButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuButton_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new MenuButton ((GtkMenuButton*) o));
  }

  MenuButton::MenuButton (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  MenuButton::MenuButton (GtkMenuButton* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  MenuButton::MenuButton (MenuButton&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  MenuButton::operator= (MenuButton&& src) noexcept -> MenuButton&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  MenuButton::~MenuButton () noexcept
  {
    destroy_ ();
  }

  MenuButton::CppClassType MenuButton::menubutton_class_;

  auto
  MenuButton::get_type () -> GType
  {
    return menubutton_class_.init ().get_type ();
  }

  auto
  MenuButton::get_base_type () -> GType
  {
    return gtk_menu_button_get_type ();
  }

  MenuButton::MenuButton ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (menubutton_class_.init ()))
  {
  }

  auto
  MenuButton::set_popover (Popover& popover) -> void
  {
    gtk_menu_button_set_popover (gobj (), popover.Widget::gobj ());
  }

  auto
  MenuButton::get_popover () -> Popover*
  {
    return Glib::wrap (gtk_menu_button_get_popover (gobj ()));
  }

  auto
  MenuButton::get_popover () const -> const Popover*
  {
    return const_cast<MenuButton*> (this)->get_popover ();
  }

  auto
  MenuButton::set_direction (ArrowType direction) -> void
  {
    gtk_menu_button_set_direction (gobj (),
                                   static_cast<GtkArrowType> (direction));
  }

  auto
  MenuButton::get_direction () const -> ArrowType
  {
    return static_cast<ArrowType> (
        gtk_menu_button_get_direction (const_cast<GtkMenuButton*> (gobj ())));
  }

  auto
  MenuButton::set_menu_model (
      const Glib::RefPtr<const Gio::MenuModel>& menu_model) -> void
  {
    gtk_menu_button_set_menu_model (
        gobj (),
        const_cast<GMenuModel*> (Glib::unwrap (menu_model)));
  }

  auto
  MenuButton::get_menu_model () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_menu_button_get_menu_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  MenuButton::get_menu_model () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<MenuButton*> (this)->get_menu_model ();
  }

  auto
  MenuButton::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    gtk_menu_button_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  MenuButton::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_menu_button_get_icon_name (const_cast<GtkMenuButton*> (gobj ())));
  }

  auto
  MenuButton::set_always_show_arrow (const bool always_show_arrow) -> void
  {
    gtk_menu_button_set_always_show_arrow (gobj (), always_show_arrow);
  }

  auto
  MenuButton::get_always_show_arrow () const -> bool
  {
    return gtk_menu_button_get_always_show_arrow (
        const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::set_label (const Glib::ustring& label) -> void
  {
    gtk_menu_button_set_label (gobj (), label.c_str ());
  }

  auto
  MenuButton::get_label () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_menu_button_get_label (const_cast<GtkMenuButton*> (gobj ())));
  }

  auto
  MenuButton::set_use_underline (const bool use_underline) -> void
  {
    gtk_menu_button_set_use_underline (gobj (), use_underline);
  }

  auto
  MenuButton::get_use_underline () const -> bool
  {
    return gtk_menu_button_get_use_underline (
        const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::set_has_frame (const bool has_frame) -> void
  {
    gtk_menu_button_set_has_frame (gobj (), has_frame);
  }

  auto
  MenuButton::get_has_frame () const -> bool
  {
    return gtk_menu_button_get_has_frame (const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::popup () -> void
  {
    gtk_menu_button_popup (gobj ());
  }

  auto
  MenuButton::popdown () -> void
  {
    gtk_menu_button_popdown (gobj ());
  }

  auto
  MenuButton::set_primary (const bool primary) -> void
  {
    gtk_menu_button_set_primary (gobj (), primary);
  }

  auto
  MenuButton::get_primary () const -> bool
  {
    return gtk_menu_button_get_primary (const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::set_child (Widget& child) -> void
  {
    gtk_menu_button_set_child (gobj (), child.gobj ());
  }

  auto
  MenuButton::get_child () -> Widget*
  {
    return Glib::wrap (gtk_menu_button_get_child (gobj ()));
  }

  auto
  MenuButton::get_child () const -> const Widget*
  {
    return const_cast<MenuButton*> (this)->get_child ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MenuButton::property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  auto
  MenuButton::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return {this, "menu-model"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ArrowType>::value,
      "Type ArrowType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MenuButton::property_direction () -> Glib::PropertyProxy<ArrowType>
  {
    return {this, "direction"};
  }

  auto
  MenuButton::property_direction () const -> Glib::PropertyProxy_ReadOnly<ArrowType>
  {
    return {this, "direction"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Popover*>::value,
      "Type Popover* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MenuButton::property_popover () -> Glib::PropertyProxy<Popover*>
  {
    return {this, "popover"};
  }

  auto
  MenuButton::property_popover () const -> Glib::PropertyProxy_ReadOnly<Popover*>
  {
    return {this, "popover"};
  }

  auto
  MenuButton::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  MenuButton::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  MenuButton::property_always_show_arrow () -> Glib::PropertyProxy<bool>
  {
    return {this, "always-show-arrow"};
  }

  auto
  MenuButton::property_always_show_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "always-show-arrow"};
  }

  auto
  MenuButton::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "label"};
  }

  auto
  MenuButton::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "label"};
  }

  auto
  MenuButton::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  MenuButton::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

  auto
  MenuButton::property_has_frame () -> Glib::PropertyProxy<bool>
  {
    return {this, "has-frame"};
  }

  auto
  MenuButton::property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "has-frame"};
  }

  auto
  MenuButton::property_primary () -> Glib::PropertyProxy<bool>
  {
    return {this, "primary"};
  }

  auto
  MenuButton::property_primary () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "primary"};
  }

  auto
  MenuButton::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return {this, "child"};
  }

  auto
  MenuButton::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return {this, "child"};
  }

} // namespace Gtk
