

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/shortcutsgroup.hxx>
#include <libmm-gtk/shortcutsgroup_p.hxx>

#include <gtk/gtk.h>

namespace Gtk
{
  auto
  ShortcutsGroup::unset_view () -> void
  {
    property_view ().reset_value ();
  }
} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkShortcutsGroup* object, const bool take_copy) -> Gtk::ShortcutsGroup*
  {
    return dynamic_cast<Gtk::ShortcutsGroup*> (
        wrap_auto ((GObject*) object, take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ShortcutsGroup_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ShortcutsGroup_Class::class_init_function;

      register_derived_type (gtk_shortcuts_group_get_type ());
    }

    return *this;
  }

  auto
  ShortcutsGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ShortcutsGroup_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new ShortcutsGroup ((GtkShortcutsGroup*) o));
  }

  ShortcutsGroup::ShortcutsGroup (const Glib::ConstructParams& construct_params)
    : Box (construct_params)
  {
  }

  ShortcutsGroup::ShortcutsGroup (GtkShortcutsGroup* castitem)
    : Box ((GtkBox*) castitem)
  {
  }

  ShortcutsGroup::ShortcutsGroup (ShortcutsGroup&& src) noexcept
    : Box (std::move (src))
  {
  }

  auto
  ShortcutsGroup::operator= (ShortcutsGroup&& src) noexcept -> ShortcutsGroup&
  {
    Box::operator= (std::move (src));
    return *this;
  }

  ShortcutsGroup::~ShortcutsGroup () noexcept
  {
    destroy_ ();
  }

  ShortcutsGroup::CppClassType ShortcutsGroup::shortcutsgroup_class_;

  auto
  ShortcutsGroup::get_type () -> GType
  {
    return shortcutsgroup_class_.init ().get_type ();
  }

  auto
  ShortcutsGroup::get_base_type () -> GType
  {
    return gtk_shortcuts_group_get_type ();
  }

  ShortcutsGroup::ShortcutsGroup ()
    : ObjectBase (nullptr),
      Box (Glib::ConstructParams (shortcutsgroup_class_.init ()))
  {
  }

  auto
  ShortcutsGroup::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  ShortcutsGroup::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "title"};
  }

  auto
  ShortcutsGroup::property_view () -> Glib::PropertyProxy<Glib::ustring>
  {
    return {this, "view"};
  }

  auto
  ShortcutsGroup::property_view () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "view"};
  }

} // namespace Gtk
