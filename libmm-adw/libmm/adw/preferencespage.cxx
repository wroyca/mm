// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/preferencespage.hxx>
#include <libmm/adw/preferencespage_p.hxx>

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
  wrap (AdwPreferencesPage* object, bool take_copy) -> adw::preferences_page*
  {
    return dynamic_cast<adw::preferences_page*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  preferences_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &preferences_page_class::class_init_function;

      register_derived_type (adw_preferences_page_get_type ());
    }

    return *this;
  }

  auto
  preferences_page_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  preferences_page_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new preferences_page ((AdwPreferencesPage*) (o)));
  }

  preferences_page::preferences_page (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  preferences_page::preferences_page (AdwPreferencesPage* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  preferences_page::preferences_page (preferences_page&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  preferences_page::operator= (preferences_page&& src) noexcept -> preferences_page&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  preferences_page::~preferences_page () noexcept
  {
    destroy_ ();
  }

  preferences_page::CppClassType preferences_page::preferencespage_class_;

  auto
  preferences_page::get_type () -> GType
  {
    return preferencespage_class_.init ().get_type ();
  }

  auto
  preferences_page::get_base_type () -> GType
  {
    return adw_preferences_page_get_type ();
  }

  preferences_page::preferences_page ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (preferencespage_class_.init ()))
  {
  }

  auto
  preferences_page::add (preferences_group* group) -> void
  {
    adw_preferences_page_add (gobj (),
                              (AdwPreferencesGroup*) glib::unwrap (group));
  }

  auto
  preferences_page::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_icon_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  preferences_page::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  preferences_page::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_title (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  preferences_page::get_use_underline () const -> bool
  {
    return adw_preferences_page_get_use_underline (
        const_cast<AdwPreferencesPage*> (gobj ()));
  }

  auto
  preferences_page::remove (preferences_group* group) -> void
  {
    adw_preferences_page_remove (gobj (),
                                 (AdwPreferencesGroup*) glib::unwrap (group));
  }

  auto
  preferences_page::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_preferences_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  preferences_page::set_name (const glib::ustring& name) -> void
  {
    adw_preferences_page_set_name (gobj (), name.c_str ());
  }

  auto
  preferences_page::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_page_set_title (gobj (), title.c_str ());
  }

  auto
  preferences_page::set_use_underline (bool use_underline) -> void
  {
    adw_preferences_page_set_use_underline (gobj (),
                                            static_cast<int> (use_underline));
  }

  auto
  preferences_page::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  preferences_page::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  preferences_page::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  preferences_page::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  preferences_page::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  preferences_page::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  preferences_page::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  preferences_page::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
