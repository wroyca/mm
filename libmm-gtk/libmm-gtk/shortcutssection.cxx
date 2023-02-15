// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutssection.hxx>
#include <libmm-gtk/shortcutssection_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutsSection* object, bool take_copy) -> Gtk::ShortcutsSection*
  {
    return dynamic_cast<Gtk::ShortcutsSection*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutsSection_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutsSection_Class::class_init_function;

      register_derived_type (gtk_shortcuts_section_get_type ());
    }

    return *this;
  }

  auto
  ShortcutsSection_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutsSection_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ShortcutsSection ((GtkShortcutsSection*) (o)));
  }

  ShortcutsSection::ShortcutsSection (
      const Glib::ConstructParams& construct_params)
    : Box (construct_params)
  {
  }

  ShortcutsSection::ShortcutsSection (GtkShortcutsSection* castitem)
    : Box ((GtkBox*) (castitem))
  {
  }

  ShortcutsSection::ShortcutsSection (ShortcutsSection&& src) noexcept
    : Box (std::move (src))
  {
  }

  auto
  ShortcutsSection::operator= (ShortcutsSection&& src) noexcept -> ShortcutsSection&
  {
    Box::operator= (std::move (src));
    return *this;
  }

  ShortcutsSection::~ShortcutsSection () noexcept
  {
    destroy_ ();
  }

  ShortcutsSection::CppClassType ShortcutsSection::shortcutssection_class_;

  auto
  ShortcutsSection::get_type () -> GType
  {
    return shortcutssection_class_.init ().get_type ();
  }

  auto
  ShortcutsSection::get_base_type () -> GType
  {
    return gtk_shortcuts_section_get_type ();
  }

  ShortcutsSection::ShortcutsSection ()
    : Glib::ObjectBase (nullptr),
      Box (Glib::ConstructParams (shortcutssection_class_.init ()))
  {
  }

  auto
  ShortcutsSection::property_section_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "section-name");
  }

  auto
  ShortcutsSection::property_section_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "section-name");
  }

  auto
  ShortcutsSection::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ShortcutsSection::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ShortcutsSection::property_max_height () -> Glib::PropertyProxy<unsigned int>
  {
    return Glib::PropertyProxy<unsigned int> (this, "max-height");
  }

  auto
  ShortcutsSection::property_max_height () const -> Glib::PropertyProxy_ReadOnly<unsigned int>
  {
    return Glib::PropertyProxy_ReadOnly<unsigned int> (this, "max-height");
  }

} // namespace Gtk
