// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/menubutton.hxx>
#include <libmm-gtk/menubutton_p.hxx>

#include <gtk/gtk.h>

namespace
{

  auto
  SignalProxy_MenuButton_create_popup_callback (GtkMenuButton*,
                                                gpointer user_data) -> void
  {
    auto the_slot = static_cast<Gtk::MenuButton::SlotCreatePopup*> (user_data);

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
    auto slot_copy = new SlotCreatePopup (slot);

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
  wrap (GtkMenuButton* object, bool take_copy) -> Gtk::MenuButton*
  {
    return dynamic_cast<Gtk::MenuButton*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  MenuButton_Class::init () -> const Glib::Class&
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
    return manage (new MenuButton ((GtkMenuButton*) (o)));
  }

  MenuButton::MenuButton (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  MenuButton::MenuButton (GtkMenuButton* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  MenuButton::MenuButton (MenuButton&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  MenuButton::operator= (MenuButton&& src) noexcept -> MenuButton&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (menubutton_class_.init ()))
  {
  }

  auto
  MenuButton::set_popover (Popover& popover) -> void
  {
    gtk_menu_button_set_popover (gobj (), (popover).Gtk::Widget::gobj ());
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
  MenuButton::set_always_show_arrow (bool always_show_arrow) -> void
  {
    gtk_menu_button_set_always_show_arrow (
        gobj (),
        static_cast<int> (always_show_arrow));
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
  MenuButton::set_use_underline (bool use_underline) -> void
  {
    gtk_menu_button_set_use_underline (gobj (),
                                       static_cast<int> (use_underline));
  }

  auto
  MenuButton::get_use_underline () const -> bool
  {
    return gtk_menu_button_get_use_underline (
        const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::set_has_frame (bool has_frame) -> void
  {
    gtk_menu_button_set_has_frame (gobj (), static_cast<int> (has_frame));
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
  MenuButton::set_primary (bool primary) -> void
  {
    gtk_menu_button_set_primary (gobj (), static_cast<int> (primary));
  }

  auto
  MenuButton::get_primary () const -> bool
  {
    return gtk_menu_button_get_primary (const_cast<GtkMenuButton*> (gobj ()));
  }

  auto
  MenuButton::set_child (Widget& child) -> void
  {
    gtk_menu_button_set_child (gobj (), (child).gobj ());
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
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  MenuButton::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "menu-model");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ArrowType>::value,
      "Type ArrowType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MenuButton::property_direction () -> Glib::PropertyProxy<ArrowType>
  {
    return Glib::PropertyProxy<ArrowType> (this, "direction");
  }

  auto
  MenuButton::property_direction () const -> Glib::PropertyProxy_ReadOnly<ArrowType>
  {
    return Glib::PropertyProxy_ReadOnly<ArrowType> (this, "direction");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Popover*>::value,
      "Type Popover* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  MenuButton::property_popover () -> Glib::PropertyProxy<Popover*>
  {
    return Glib::PropertyProxy<Popover*> (this, "popover");
  }

  auto
  MenuButton::property_popover () const -> Glib::PropertyProxy_ReadOnly<Popover*>
  {
    return Glib::PropertyProxy_ReadOnly<Popover*> (this, "popover");
  }

  auto
  MenuButton::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  MenuButton::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  MenuButton::property_always_show_arrow () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "always-show-arrow");
  }

  auto
  MenuButton::property_always_show_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "always-show-arrow");
  }

  auto
  MenuButton::property_label () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "label");
  }

  auto
  MenuButton::property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "label");
  }

  auto
  MenuButton::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  MenuButton::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  MenuButton::property_has_frame () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "has-frame");
  }

  auto
  MenuButton::property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "has-frame");
  }

  auto
  MenuButton::property_primary () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "primary");
  }

  auto
  MenuButton::property_primary () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "primary");
  }

  auto
  MenuButton::property_child () -> Glib::PropertyProxy<Widget*>
  {
    return Glib::PropertyProxy<Widget*> (this, "child");
  }

  auto
  MenuButton::property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child");
  }

} // namespace Gtk
