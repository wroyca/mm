// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/preferencesgroup.hxx>
#include <libmm/adw/preferencesgroup_p.hxx>

#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwPreferencesGroup* object, bool take_copy) -> adw::PreferencesGroup*
  {
    return dynamic_cast<adw::PreferencesGroup*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  PreferencesGroup_Class::init () -> const glib::Class&
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
  PreferencesGroup_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PreferencesGroup ((AdwPreferencesGroup*) (o)));
  }

  PreferencesGroup::PreferencesGroup (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  PreferencesGroup::PreferencesGroup (AdwPreferencesGroup* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PreferencesGroup::PreferencesGroup (PreferencesGroup&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  PreferencesGroup::operator= (PreferencesGroup&& src) noexcept -> PreferencesGroup&
  {
    gtk::Widget::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (preferencesgroup_class_.init ()))
  {
  }

  auto
  PreferencesGroup::add (gtk::Widget* child) -> void
  {
    adw_preferences_group_add (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  PreferencesGroup::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_description (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::get_header_suffix () const -> gtk::Widget*
  {
    return glib::wrap (adw_preferences_group_get_header_suffix (
        const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_title (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  PreferencesGroup::remove (gtk::Widget* child) -> void
  {
    adw_preferences_group_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  PreferencesGroup::set_description (const glib::ustring& description) -> void
  {
    adw_preferences_group_set_description (gobj (), description.c_str ());
  }

  auto
  PreferencesGroup::set_header_suffix (gtk::Widget* suffix) -> void
  {
    adw_preferences_group_set_header_suffix (
        gobj (),
        (GtkWidget*) glib::unwrap (suffix));
  }

  auto
  PreferencesGroup::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_group_set_title (gobj (), title.c_str ());
  }

  auto
  PreferencesGroup::property_description () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  PreferencesGroup::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  PreferencesGroup::property_header_suffix () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "header-suffix"};
  }

  auto
  PreferencesGroup::property_header_suffix () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "header-suffix"};
  }

  auto
  PreferencesGroup::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  PreferencesGroup::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

} // namespace adw
