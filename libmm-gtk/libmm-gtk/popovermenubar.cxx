// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/popovermenubar.hxx>
#include <libmm-gtk/popovermenubar_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkPopoverMenuBar* object, bool take_copy) -> Gtk::PopoverMenuBar*
  {
    return dynamic_cast<Gtk::PopoverMenuBar*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  PopoverMenuBar_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PopoverMenuBar_Class::class_init_function;

      register_derived_type (gtk_popover_menu_bar_get_type ());
    }

    return *this;
  }

  auto
  PopoverMenuBar_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PopoverMenuBar_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PopoverMenuBar ((GtkPopoverMenuBar*) (o)));
  }

  PopoverMenuBar::PopoverMenuBar (const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  PopoverMenuBar::PopoverMenuBar (GtkPopoverMenuBar* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PopoverMenuBar::PopoverMenuBar (PopoverMenuBar&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  PopoverMenuBar::operator= (PopoverMenuBar&& src) noexcept -> PopoverMenuBar&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  PopoverMenuBar::~PopoverMenuBar () noexcept
  {
    destroy_ ();
  }

  PopoverMenuBar::CppClassType PopoverMenuBar::popovermenubar_class_;

  auto
  PopoverMenuBar::get_type () -> GType
  {
    return popovermenubar_class_.init ().get_type ();
  }

  auto
  PopoverMenuBar::get_base_type () -> GType
  {
    return gtk_popover_menu_bar_get_type ();
  }

  PopoverMenuBar::PopoverMenuBar (
      const Glib::RefPtr<Gio::MenuModel>& menu_model)
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (popovermenubar_class_.init (),
                                          "menu_model",
                                          Glib::unwrap (menu_model),
                                          nullptr))
  {
  }

  auto
  PopoverMenuBar::set_menu_model (const Glib::RefPtr<Gio::MenuModel>& model) -> void
  {
    gtk_popover_menu_bar_set_menu_model (gobj (), Glib::unwrap (model));
  }

  auto
  PopoverMenuBar::get_menu_model () -> Glib::RefPtr<Gio::MenuModel>
  {
    auto retvalue = Glib::wrap (gtk_popover_menu_bar_get_menu_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PopoverMenuBar::get_menu_model () const -> Glib::RefPtr<const Gio::MenuModel>
  {
    return const_cast<PopoverMenuBar*> (this)->get_menu_model ();
  }

  auto
  PopoverMenuBar::add_child (Widget& child, const Glib::ustring& id) -> bool
  {
    return gtk_popover_menu_bar_add_child (gobj (),
                                           (child).gobj (),
                                           id.c_str ());
  }

  auto
  PopoverMenuBar::remove_child (Widget& child) -> bool
  {
    return gtk_popover_menu_bar_remove_child (gobj (), (child).gobj ());
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::MenuModel>>::value,
      "Type Glib::RefPtr<Gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  PopoverMenuBar::property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  PopoverMenuBar::property_menu_model () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>> (
        this,
        "menu-model");
  }

} // namespace Gtk
