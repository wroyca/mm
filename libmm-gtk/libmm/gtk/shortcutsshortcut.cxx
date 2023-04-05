// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutsshortcut.hxx>
#include <libmm/gtk/shortcutsshortcut_p.hxx>

#include <gtk/gtk.h>

namespace gtk
{
}

namespace
{
}

auto
glib::Value<gtk::ShortcutType>::value_type () -> GType
{
  return gtk_shortcut_type_get_type ();
}

namespace glib
{

  auto
  wrap (GtkShortcutsShortcut* object, bool take_copy) -> gtk::ShortcutsShortcut*
  {
    return dynamic_cast<gtk::ShortcutsShortcut*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutsShortcut_Class::init () -> const glib::Class&
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
  ShortcutsShortcut_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ShortcutsShortcut ((GtkShortcutsShortcut*) (o)));
  }

  ShortcutsShortcut::ShortcutsShortcut (
      const glib::ConstructParams& construct_params)
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
    : glib::ObjectBase (nullptr),
      Widget (glib::ConstructParams (shortcutsshortcut_class_.init ()))
  {
  }

  auto
  ShortcutsShortcut::property_accelerator () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "accelerator");
  }

  auto
  ShortcutsShortcut::property_accelerator () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "accelerator");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<gio::Icon>>::value,
      "Type glib::RefPtr<gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutsShortcut::property_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy<glib::RefPtr<gio::Icon>> (this, "icon");
  }

  auto
  ShortcutsShortcut::property_icon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>> (this, "icon");
  }

  auto
  ShortcutsShortcut::property_icon_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "icon-set");
  }

  auto
  ShortcutsShortcut::property_icon_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "icon-set");
  }

  auto
  ShortcutsShortcut::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  ShortcutsShortcut::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  ShortcutsShortcut::property_subtitle () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "subtitle");
  }

  auto
  ShortcutsShortcut::property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "subtitle");
  }

  auto
  ShortcutsShortcut::property_subtitle_set () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "subtitle-set");
  }

  auto
  ShortcutsShortcut::property_subtitle_set () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "subtitle-set");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<TextDirection>::value,
      "Type TextDirection cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutsShortcut::property_direction () -> glib::PropertyProxy<TextDirection>
  {
    return glib::PropertyProxy<TextDirection> (this, "direction");
  }

  auto
  ShortcutsShortcut::property_direction () const -> glib::PropertyProxy_ReadOnly<TextDirection>
  {
    return glib::PropertyProxy_ReadOnly<TextDirection> (this, "direction");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<ShortcutType>::value,
      "Type ShortcutType cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ShortcutsShortcut::property_shortcut_type () -> glib::PropertyProxy<ShortcutType>
  {
    return glib::PropertyProxy<ShortcutType> (this, "shortcut-type");
  }

  auto
  ShortcutsShortcut::property_shortcut_type () const -> glib::PropertyProxy_ReadOnly<ShortcutType>
  {
    return glib::PropertyProxy_ReadOnly<ShortcutType> (this, "shortcut-type");
  }

  auto
  ShortcutsShortcut::property_action_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "action-name");
  }

  auto
  ShortcutsShortcut::property_action_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "action-name");
  }

} // namespace gtk
