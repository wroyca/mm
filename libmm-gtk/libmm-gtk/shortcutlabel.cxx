// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutlabel.hxx>
#include <libmm-gtk/shortcutlabel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutLabel* object, const bool take_copy) -> Gtk::ShortcutLabel*
  {
    return dynamic_cast<Gtk::ShortcutLabel*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutLabel_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutLabel_Class::class_init_function;

      register_derived_type (gtk_shortcut_label_get_type ());
    }

    return *this;
  }

  auto
  ShortcutLabel_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutLabel_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ShortcutLabel ((GtkShortcutLabel*) o));
  }

  ShortcutLabel::ShortcutLabel (const Glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  ShortcutLabel::ShortcutLabel (GtkShortcutLabel* castitem)
    : Widget ((GtkWidget*) castitem)
  {
  }

  ShortcutLabel::ShortcutLabel (ShortcutLabel&& src) noexcept
    : Widget (std::move (src))
  {
  }

  auto
  ShortcutLabel::operator= (ShortcutLabel&& src) noexcept -> ShortcutLabel&
  {
    Widget::operator= (std::move (src));
    return *this;
  }

  ShortcutLabel::~ShortcutLabel () noexcept
  {
    destroy_ ();
  }

  ShortcutLabel::CppClassType ShortcutLabel::shortcutlabel_class_;

  auto
  ShortcutLabel::get_type () -> GType
  {
    return shortcutlabel_class_.init ().get_type ();
  }

  auto
  ShortcutLabel::get_base_type () -> GType
  {
    return gtk_shortcut_label_get_type ();
  }

  ShortcutLabel::ShortcutLabel ()
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (shortcutlabel_class_.init ()))
  {
  }

  ShortcutLabel::ShortcutLabel (const Glib::ustring& accelerator)
    : ObjectBase (nullptr),
      Widget (Glib::ConstructParams (shortcutlabel_class_.init (),
                                     "accelerator",
                                     accelerator.c_str (),
                                     nullptr))
  {
  }

  auto
  ShortcutLabel::get_accelerator () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_shortcut_label_get_accelerator (
            const_cast<GtkShortcutLabel*> (gobj ())));
  }

  auto
  ShortcutLabel::set_accelerator (const Glib::ustring& accelerator) -> void
  {
    gtk_shortcut_label_set_accelerator (gobj (), accelerator.c_str ());
  }

  auto
  ShortcutLabel::get_disabled_text () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gtk_shortcut_label_get_disabled_text (
            const_cast<GtkShortcutLabel*> (gobj ())));
  }

  auto
  ShortcutLabel::set_disabled_text (const Glib::ustring& disabled_text) -> void
  {
    gtk_shortcut_label_set_disabled_text (gobj (), disabled_text.c_str ());
  }

  auto
  ShortcutLabel::property_accelerator () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "accelerator"};
  }

  auto
  ShortcutLabel::property_accelerator () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "accelerator"};
  }

  auto
  ShortcutLabel::property_disabled_text () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "disabled-text"};
  }

  auto
  ShortcutLabel::property_disabled_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "disabled-text"};
  }

} // namespace Gtk
