// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/shortcutlabel.hxx>
#include <libmm/gtk/shortcutlabel_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkShortcutLabel* object, bool take_copy) -> gtk::ShortcutLabel*
  {
    return dynamic_cast<gtk::ShortcutLabel*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  ShortcutLabel_Class::init () -> const glib::Class&
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
  ShortcutLabel_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new ShortcutLabel ((GtkShortcutLabel*) (o)));
  }

  ShortcutLabel::ShortcutLabel (const glib::ConstructParams& construct_params)
    : Widget (construct_params)
  {
  }

  ShortcutLabel::ShortcutLabel (GtkShortcutLabel* castitem)
    : Widget ((GtkWidget*) (castitem))
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
    : glib::ObjectBase (nullptr),
      Widget (glib::ConstructParams (shortcutlabel_class_.init ()))
  {
  }

  ShortcutLabel::ShortcutLabel (const glib::ustring& accelerator)
    : glib::ObjectBase (nullptr),
      Widget (glib::ConstructParams (shortcutlabel_class_.init (),
                                     "accelerator",
                                     accelerator.c_str (),
                                     nullptr))
  {
  }

  auto
  ShortcutLabel::get_accelerator () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_shortcut_label_get_accelerator (
            const_cast<GtkShortcutLabel*> (gobj ())));
  }

  auto
  ShortcutLabel::set_accelerator (const glib::ustring& accelerator) -> void
  {
    gtk_shortcut_label_set_accelerator (gobj (), accelerator.c_str ());
  }

  auto
  ShortcutLabel::get_disabled_text () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_shortcut_label_get_disabled_text (
            const_cast<GtkShortcutLabel*> (gobj ())));
  }

  auto
  ShortcutLabel::set_disabled_text (const glib::ustring& disabled_text) -> void
  {
    gtk_shortcut_label_set_disabled_text (gobj (), disabled_text.c_str ());
  }

  auto
  ShortcutLabel::property_accelerator () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "accelerator");
  }

  auto
  ShortcutLabel::property_accelerator () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "accelerator");
  }

  auto
  ShortcutLabel::property_disabled_text () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "disabled-text");
  }

  auto
  ShortcutLabel::property_disabled_text () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "disabled-text");
  }

} // namespace gtk
