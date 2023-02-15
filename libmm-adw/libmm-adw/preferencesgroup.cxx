// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/preferencesgroup.hxx>
#include <libmm-adw/preferencesgroup_p.hxx>

#include <libmm-gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwPreferencesGroup* object, bool take_copy) -> Adw::PreferencesGroup*
  {
    return dynamic_cast<Adw::PreferencesGroup*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  PreferencesGroup_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PreferencesGroup_Class::class_init_function;

      register_derived_type (adw_preferences_group_get_type ());
    }

    return *this;
  }

  auto
  PreferencesGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PreferencesGroup_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PreferencesGroup ((AdwPreferencesGroup*) (o)));
  }

  PreferencesGroup::PreferencesGroup (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  PreferencesGroup::PreferencesGroup (AdwPreferencesGroup* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PreferencesGroup::PreferencesGroup (PreferencesGroup&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  PreferencesGroup::operator= (PreferencesGroup&& src) noexcept -> PreferencesGroup&
  {
    Gtk::Widget::operator= (std::move (src));
    return *this;
  }

  PreferencesGroup::~PreferencesGroup () noexcept
  {
    destroy_ ();
  }

  PreferencesGroup::CppClassType PreferencesGroup::preferencesgroup_class_;

  auto
  PreferencesGroup::get_type () -> GType
  {
    return preferencesgroup_class_.init ().get_type ();
  }

  auto
  PreferencesGroup::get_base_type () -> GType
  {
    return adw_preferences_group_get_type ();
  }

  PreferencesGroup::PreferencesGroup ()
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (preferencesgroup_class_.init ()))
  {
  }

  auto
  PreferencesGroup::add (Gtk::Widget* child) -> void
  {
    adw_preferences_group_add (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  PreferencesGroup::get_description () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_description (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::get_header_suffix () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_preferences_group_get_header_suffix (
        const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_title (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::remove (Gtk::Widget* child) -> void
  {
    adw_preferences_group_remove (gobj (), (GtkWidget*) Glib::unwrap (child));
  }

  auto
  PreferencesGroup::set_description (const Glib::ustring& description) -> void
  {
    adw_preferences_group_set_description (gobj (), description.c_str ());
  }

  auto
  PreferencesGroup::set_header_suffix (Gtk::Widget* suffix) -> void
  {
    adw_preferences_group_set_header_suffix (
        gobj (),
        (GtkWidget*) Glib::unwrap (suffix));
  }

  auto
  PreferencesGroup::set_title (const Glib::ustring& title) -> void
  {
    adw_preferences_group_set_title (gobj (), title.c_str ());
  }

  auto
  PreferencesGroup::property_description () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "description");
  }

  auto
  PreferencesGroup::property_description () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "description");
  }

  auto
  PreferencesGroup::property_header_suffix () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "header-suffix");
  }

  auto
  PreferencesGroup::property_header_suffix () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "header-suffix");
  }

  auto
  PreferencesGroup::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  PreferencesGroup::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

} // namespace Adw
