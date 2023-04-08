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
  wrap (AdwPreferencesRow* object, bool take_copy) -> adw::preferences_row*
  {
    return dynamic_cast<adw::preferences_row*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  preferences_row_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &preferences_row_class::class_init_function;

      register_derived_type (adw_preferences_row_get_type ());
    }

    return *this;
  }

  auto
  preferences_row_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  preferences_row_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new preferences_row ((AdwPreferencesRow*) (o)));
  }

  preferences_row::preferences_row (const glib::ConstructParams& construct_params)
    : gtk::ListBoxRow (construct_params)
  {
  }

  preferences_row::preferences_row (AdwPreferencesRow* castitem)
    : gtk::ListBoxRow ((GtkListBoxRow*) (castitem))
  {
  }

  preferences_row::preferences_row (preferences_row&& src) noexcept
    : gtk::ListBoxRow (std::move (src))
  {
  }

  auto
  preferences_row::operator= (preferences_row&& src) noexcept -> preferences_row&
  {
    gtk::ListBoxRow::operator= (std::move (src));
    return *this;
  }

  preferences_row::~preferences_row () noexcept
  {
    destroy_ ();
  }

  preferences_row::CppClassType preferences_row::preferencesrow_class_;

  auto
  preferences_row::get_type () -> GType
  {
    return preferencesrow_class_.init ().get_type ();
  }

  auto
  preferences_row::get_base_type () -> GType
  {
    return adw_preferences_row_get_type ();
  }

  preferences_row::preferences_row ()
    : glib::ObjectBase (nullptr),
      gtk::ListBoxRow (glib::ConstructParams (preferencesrow_class_.init ()))
  {
  }

  auto
  preferences_row::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_row_get_title (
            const_cast<AdwPreferencesRow*> (gobj ())));
  }

  auto
  preferences_row::get_title_selectable () const -> bool
  {
    return adw_preferences_row_get_title_selectable (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  preferences_row::get_use_markup () const -> bool
  {
    return adw_preferences_row_get_use_markup (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  preferences_row::get_use_underline () const -> bool
  {
    return adw_preferences_row_get_use_underline (
        const_cast<AdwPreferencesRow*> (gobj ()));
  }

  auto
  preferences_row::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_row_set_title (gobj (), title.c_str ());
  }

  auto
  preferences_row::set_title_selectable (bool title_selectable) -> void
  {
    adw_preferences_row_set_title_selectable (
        gobj (),
        static_cast<int> (title_selectable));
  }

  auto
  preferences_row::set_use_markup (bool use_markup) -> void
  {
    adw_preferences_row_set_use_markup (gobj (), static_cast<int> (use_markup));
  }

  auto
  preferences_row::set_use_underline (bool use_underline) -> void
  {
    adw_preferences_row_set_use_underline (gobj (),
                                           static_cast<int> (use_underline));
  }

  auto
  preferences_row::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  preferences_row::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  preferences_row::property_title_selectable () -> glib::PropertyProxy<bool>
  {
    return {this, "title-selectable"};
  }

  auto
  preferences_row::property_title_selectable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "title-selectable"};
  }

  auto
  preferences_row::property_use_markup () -> glib::PropertyProxy<bool>
  {
    return {this, "use-markup"};
  }

  auto
  preferences_row::property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-markup"};
  }

  auto
  preferences_row::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  preferences_row::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
