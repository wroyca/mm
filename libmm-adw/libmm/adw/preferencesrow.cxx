// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/preferencesrow.hxx>
#include <libmm/adw/preferencesrow_p.hxx>

#include <adwaita.h>
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
  wrap (AdwPreferencesRow* object, bool take_copy) -> adw::PreferencesRow*
  {
    return dynamic_cast<adw::PreferencesRow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  PreferencesRow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PreferencesRow_Class::class_init_function;

      register_derived_type (adw_preferences_row_get_type ());
    }

    return *this;
  }

  auto
  PreferencesRow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PreferencesRow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PreferencesRow ((AdwPreferencesRow*) (o)));
  }

  PreferencesRow::PreferencesRow (const glib::ConstructParams& construct_params)
    : gtk::ListBoxRow (construct_params)
  {
  }

  PreferencesRow::PreferencesRow (AdwPreferencesRow* castitem)
    : gtk::ListBoxRow ((GtkListBoxRow*) (castitem))
  {
  }

  PreferencesRow::PreferencesRow (PreferencesRow&& src) noexcept
    : gtk::ListBoxRow (std::move (src))
  {
  }

  auto
  PreferencesRow::operator= (PreferencesRow&& src) noexcept -> PreferencesRow&
  {
    gtk::ListBoxRow::operator= (std::move (src));
    return *this;
  }

  PreferencesRow::~PreferencesRow () noexcept
  {
    destroy_ ();
  }

  PreferencesRow::CppClassType PreferencesRow::preferencesrow_class_;

  auto
  PreferencesRow::get_type () -> GType
  {
    return preferencesrow_class_.init ().get_type ();
  }

  auto
  PreferencesRow::get_base_type () -> GType
  {
    return adw_preferences_row_get_type ();
  }

  PreferencesRow::PreferencesRow ()
    : glib::ObjectBase (nullptr),
      gtk::ListBoxRow (glib::ConstructParams (preferencesrow_class_.init ()))
  {
  }

  auto
  PreferencesRow::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_row_get_title (
            const_cast<AdwPreferencesRow*> (gobj ())));
  }

  auto
  PreferencesRow::get_title_selectable () const -> bool
  {
    return adw_preferences_row_get_title_selectable (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  PreferencesRow::get_use_markup () const -> bool
  {
    return adw_preferences_row_get_use_markup (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  PreferencesRow::get_use_underline () const -> bool
  {
    return adw_preferences_row_get_use_underline (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  PreferencesRow::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_row_set_title (gobj (), title.c_str ());
  }

  auto
  PreferencesRow::set_title_selectable (bool title_selectable) -> void
  {
    adw_preferences_row_set_title_selectable (
        gobj (),
        static_cast<int> (title_selectable));
  }

  auto
  PreferencesRow::set_use_markup (bool use_markup) -> void
  {
    adw_preferences_row_set_use_markup (gobj (), static_cast<int> (use_markup));
  }

  auto
  PreferencesRow::set_use_underline (bool use_underline) -> void
  {
    adw_preferences_row_set_use_underline (gobj (),
                                           static_cast<int> (use_underline));
  }

  auto
  PreferencesRow::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  PreferencesRow::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  PreferencesRow::property_title_selectable () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "title-selectable");
  }

  auto
  PreferencesRow::property_title_selectable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "title-selectable");
  }

  auto
  PreferencesRow::property_use_markup () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-markup");
  }

  auto
  PreferencesRow::property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-markup");
  }

  auto
  PreferencesRow::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  PreferencesRow::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace adw
