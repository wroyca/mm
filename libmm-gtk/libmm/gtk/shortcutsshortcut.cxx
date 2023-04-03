// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutsshortcut.hxx>
#include <libmm/gtk/shortcutsshortcut_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
}

namespace
{
}

auto
Glib::Value<Gtk::ShortcutType>::value_type () -> GType
{
  return gtk_shortcut_type_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkShortcutsShortcut* object, bool take_copy) -> Gtk::ShortcutsShortcut*
  {
    return dynamic_cast<Gtk::ShortcutsShortcut*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutsShortcut_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutsShortcut_Class::class_init_function;

      register_derived_type (gtk_shortcuts_shortcut_get_type ());
    }

    return *this;
  }

  auto
  ShortcutsShortcut_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutsShortcut_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ShortcutsShortcut ((GtkShortcutsShortcut*) (o)));
  }

  ShortcutsShortcut::ShortcutsShortcut (
      const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  ShortcutsShortcut::ShortcutsShortcut (GtkShortcutsShortcut* castitem)
    : Widget ((GtkWidget*) (castitem))
  {
  }

  ShortcutsShortcut::ShortcutsShortcut (ShortcutsShortcut&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  ShortcutsShortcut::operator= (ShortcutsShortcut&& src) noexcept -> ShortcutsShortcut&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  ShortcutsShortcut::~ShortcutsShortcut () noexcept
  {
    destroy_ ();
  }

  ShortcutsShortcut::CppClassType ShortcutsShortcut::shortcutsshortcut_class_;

  auto
  ShortcutsShortcut::get_type () -> GType
  {
    return shortcutsshortcut_class_.init ().get_type ();
  }

  auto
  ShortcutsShortcut::get_base_type () -> GType
  {
    return gtk_shortcuts_shortcut_get_type ();
  }

  ShortcutsShortcut::ShortcutsShortcut ()
    : Glib::ObjectBase (nullptr),
      Widget (Glib::ConstructParams (shortcutsshortcut_class_.init ()))
  {
  }

  auto
  ShortcutsShortcut::property_accelerator () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "accelerator");
  }

  auto
  ShortcutsShortcut::property_accelerator () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "accelerator");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutsShortcut::property_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (this, "icon");
  }

  auto
  ShortcutsShortcut::property_icon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (this, "icon");
  }

  auto
  ShortcutsShortcut::property_icon_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "icon-set");
  }

  auto
  ShortcutsShortcut::property_icon_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "icon-set");
  }

  auto
  ShortcutsShortcut::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ShortcutsShortcut::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ShortcutsShortcut::property_subtitle () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "subtitle");
  }

  auto
  ShortcutsShortcut::property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "subtitle");
  }

  auto
  ShortcutsShortcut::property_subtitle_set () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "subtitle-set");
  }

  auto
  ShortcutsShortcut::property_subtitle_set () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "subtitle-set");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
      "Type TextDirection cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutsShortcut::property_direction () -> Glib::PropertyProxy<TextDirection>
  {
    return Glib::PropertyProxy<TextDirection> (this, "direction");
  }

  auto
  ShortcutsShortcut::property_direction () const -> Glib::PropertyProxy_ReadOnly<TextDirection>
  {
    return Glib::PropertyProxy_ReadOnly<TextDirection> (this, "direction");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<ShortcutType>::value,
      "Type ShortcutType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ShortcutsShortcut::property_shortcut_type () -> Glib::PropertyProxy<ShortcutType>
  {
    return Glib::PropertyProxy<ShortcutType> (this, "shortcut-type");
  }

  auto
  ShortcutsShortcut::property_shortcut_type () const -> Glib::PropertyProxy_ReadOnly<ShortcutType>
  {
    return Glib::PropertyProxy_ReadOnly<ShortcutType> (this, "shortcut-type");
  }

  auto
  ShortcutsShortcut::property_action_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "action-name");
  }

  auto
  ShortcutsShortcut::property_action_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "action-name");
  }

} // namespace Gtk
