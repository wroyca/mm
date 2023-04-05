// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/popovermenubar.hxx>
#include <libmm/gtk/popovermenubar_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkPopoverMenuBar* object, bool take_copy) -> gtk::PopoverMenuBar*
  {
    return dynamic_cast<gtk::PopoverMenuBar*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  PopoverMenuBar_Class::init () -> const glib::Class&
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
  PopoverMenuBar_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PopoverMenuBar ((GtkPopoverMenuBar*) (o)));
  }

  PopoverMenuBar::PopoverMenuBar (const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  PopoverMenuBar::PopoverMenuBar (GtkPopoverMenuBar* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PopoverMenuBar::PopoverMenuBar (PopoverMenuBar&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  PopoverMenuBar::operator= (PopoverMenuBar&& src) noexcept -> PopoverMenuBar&
  {
    gtk::Widget::operator= (std::move (src));
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
      const glib::RefPtr<gio::MenuModel>& menu_model)
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (popovermenubar_class_.init (),
                                          "menu_model",
                                          glib::unwrap (menu_model),
                                          nullptr))
  {
  }

  auto
  PopoverMenuBar::set_menu_model (const glib::RefPtr<gio::MenuModel>& model) -> void
  {
    gtk_popover_menu_bar_set_menu_model (gobj (), glib::unwrap (model));
  }

  auto
  PopoverMenuBar::get_menu_model () -> glib::RefPtr<gio::MenuModel>
  {
    auto retvalue = glib::wrap (gtk_popover_menu_bar_get_menu_model (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  PopoverMenuBar::get_menu_model () const -> glib::RefPtr<const gio::MenuModel>
  {
    return const_cast<PopoverMenuBar*> (this)->get_menu_model ();
  }

  auto
  PopoverMenuBar::add_child (Widget& child, const glib::ustring& id) -> bool
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
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::MenuModel>>::value,
      "Type glib::RefPtr<gio::MenuModel> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PopoverMenuBar::property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::MenuModel>> (this,
                                                              "menu-model");
  }

  auto
  PopoverMenuBar::property_menu_model () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>> (
        this,
        "menu-model");
  }

} // namespace gtk
