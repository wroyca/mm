// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/preferencesrow.hxx>
#include <libmm/adw/preferencesrow_p.hxx>

#include <adwaita.h>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwPreferencesRow* object, bool take_copy) -> Adw::PreferencesRow*
  {
    return dynamic_cast<Adw::PreferencesRow*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  PreferencesRow_Class::init () -> const Glib::Class&
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
  PreferencesRow_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PreferencesRow ((AdwPreferencesRow*) (o)));
  }

  PreferencesRow::PreferencesRow (const Glib::ConstructParams& construct_params)
    : Gtk::ListBoxRow (construct_params)
  {
  }

  PreferencesRow::PreferencesRow (AdwPreferencesRow* castitem)
    : Gtk::ListBoxRow ((GtkListBoxRow*) (castitem))
  {
  }

  PreferencesRow::PreferencesRow (PreferencesRow&& src) noexcept
    : Gtk::ListBoxRow (std::move (src))
  {
  }

  auto
  PreferencesRow::operator= (PreferencesRow&& src) noexcept -> PreferencesRow&
  {
    Gtk::ListBoxRow::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::ListBoxRow (Glib::ConstructParams (preferencesrow_class_.init ()))
  {
  }

  auto
  PreferencesRow::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  PreferencesRow::set_title (const Glib::ustring& title) -> void
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
  PreferencesRow::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  PreferencesRow::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  PreferencesRow::property_title_selectable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "title-selectable");
  }

  auto
  PreferencesRow::property_title_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "title-selectable");
  }

  auto
  PreferencesRow::property_use_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-markup");
  }

  auto
  PreferencesRow::property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-markup");
  }

  auto
  PreferencesRow::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  PreferencesRow::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace Adw
