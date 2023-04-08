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
  wrap (AdwPreferencesGroup* object, bool take_copy) -> adw::preferences_group*
  {
    return dynamic_cast<adw::preferences_group*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  preferences_group_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &preferences_group_class::class_init_function;

      register_derived_type (adw_preferences_group_get_type ());
    }

    return *this;
  }

  auto
  preferences_group_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  preferences_group_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new preferences_group ((AdwPreferencesGroup*) (o)));
  }

  preferences_group::preferences_group (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  preferences_group::preferences_group (AdwPreferencesGroup* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  preferences_group::preferences_group (preferences_group&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  preferences_group::operator= (preferences_group&& src) noexcept -> preferences_group&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  preferences_group::~preferences_group () noexcept
  {
    destroy_ ();
  }

  preferences_group::CppClassType preferences_group::preferencesgroup_class_;

  auto
  preferences_group::get_type () -> GType
  {
    return preferencesgroup_class_.init ().get_type ();
  }

  auto
  preferences_group::get_base_type () -> GType
  {
    return adw_preferences_group_get_type ();
  }

  preferences_group::preferences_group ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (preferencesgroup_class_.init ()))
  {
  }

  auto
  preferences_group::add (gtk::Widget* child) -> void
  {
    adw_preferences_group_add (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  preferences_group::get_description () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_description (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  preferences_group::get_header_suffix () const -> gtk::Widget*
  {
    return glib::wrap (adw_preferences_group_get_header_suffix (
        const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  preferences_group::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_group_get_title (
            const_cast<AdwPreferencesGroup*> (gobj ())));
  }

  auto
  preferences_group::remove (gtk::Widget* child) -> void
  {
    adw_preferences_group_remove (gobj (), (GtkWidget*) glib::unwrap (child));
  }

  auto
  preferences_group::set_description (const glib::ustring& description) -> void
  {
    adw_preferences_group_set_description (gobj (), description.c_str ());
  }

  auto
  preferences_group::set_header_suffix (gtk::Widget* suffix) -> void
  {
    adw_preferences_group_set_header_suffix (
        gobj (),
        (GtkWidget*) glib::unwrap (suffix));
  }

  auto
  preferences_group::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_group_set_title (gobj (), title.c_str ());
  }

  auto
  preferences_group::property_description () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  preferences_group::property_description () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "description"};
  }

  auto
  preferences_group::property_header_suffix () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "header-suffix"};
  }

  auto
  preferences_group::property_header_suffix () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "header-suffix"};
  }

  auto
  preferences_group::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  preferences_group::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

} // namespace adw
