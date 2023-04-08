// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/preferenceswindow.hxx>
#include <libmm/adw/preferenceswindow_p.hxx>

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
  wrap (AdwPreferencesWindow* object, bool take_copy) -> adw::preferences_window*
  {
    return dynamic_cast<adw::preferences_window*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  preferences_window_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &preferences_window_class::class_init_function;

      register_derived_type (adw_preferences_window_get_type ());
    }

    return *this;
  }

  auto
  preferences_window_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  preferences_window_class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new preferences_window ((AdwPreferencesWindow*) (o));
  }

  preferences_window::preferences_window (
      const glib::ConstructParams& construct_params)
    : adw::window (construct_params)
  {
  }

  preferences_window::preferences_window (AdwPreferencesWindow* castitem)
    : adw::window ((AdwWindow*) (castitem))
  {
  }

  preferences_window::preferences_window (preferences_window&& src) noexcept
    : adw::window (std::move (src))
  {
  }

  auto
  preferences_window::operator= (preferences_window&& src) noexcept -> preferences_window&
  {
    adw::window::operator= (std::move (src));
    return *this;
  }

  preferences_window::~preferences_window () noexcept
  {
    destroy_ ();
  }

  preferences_window::CppClassType preferences_window::preferenceswindow_class_;

  auto
  preferences_window::get_type () -> GType
  {
    return preferenceswindow_class_.init ().get_type ();
  }

  auto
  preferences_window::get_base_type () -> GType
  {
    return adw_preferences_window_get_type ();
  }

  preferences_window::preferences_window ()
    : glib::ObjectBase (nullptr),
      adw::window (glib::ConstructParams (preferenceswindow_class_.init ()))
  {
  }

  auto
  preferences_window::add (preferences_page* page) -> void
  {
    adw_preferences_window_add (gobj (),
                                (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  preferences_window::add_toast (toast* toast) -> void
  {
    adw_preferences_window_add_toast (gobj (),
                                      (AdwToast*) glib::unwrap (toast));
  }

  auto
  preferences_window::close_subpage () -> void
  {
    adw_preferences_window_close_subpage (gobj ());
  }

  auto
  preferences_window::get_can_navigate_back () const -> bool
  {
    return adw_preferences_window_get_can_navigate_back (
        const_cast<AdwPreferencesWindow*> (gobj ()));
  }

  auto
  preferences_window::get_search_enabled () const -> bool
  {
    return adw_preferences_window_get_search_enabled (
        const_cast<AdwPreferencesWindow*> (gobj ()));
  }

  auto
  preferences_window::get_visible_page () const -> preferences_page*
  {
    return glib::wrap (adw_preferences_window_get_visible_page (
        const_cast<AdwPreferencesWindow*> (gobj ())));
  }

  auto
  preferences_window::get_visible_page_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_window_get_visible_page_name (
            const_cast<AdwPreferencesWindow*> (gobj ())));
  }

  auto
  preferences_window::present_subpage (gtk::Widget* subpage) -> void
  {
    adw_preferences_window_present_subpage (
        gobj (),
        (GtkWidget*) glib::unwrap (subpage));
  }

  auto
  preferences_window::remove (preferences_page* page) -> void
  {
    adw_preferences_window_remove (gobj (),
                                   (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  preferences_window::set_can_navigate_back (bool can_navigate_back) -> void
  {
    adw_preferences_window_set_can_navigate_back (
        gobj (),
        static_cast<int> (can_navigate_back));
  }

  auto
  preferences_window::set_search_enabled (bool search_enabled) -> void
  {
    adw_preferences_window_set_search_enabled (
        gobj (),
        static_cast<int> (search_enabled));
  }

  auto
  preferences_window::set_visible_page (preferences_page* page) -> void
  {
    adw_preferences_window_set_visible_page (
        gobj (),
        (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  preferences_window::set_visible_page_name (const glib::ustring& name) -> void
  {
    adw_preferences_window_set_visible_page_name (gobj (), name.c_str ());
  }

  auto
  preferences_window::property_can_navigate_back () -> glib::PropertyProxy<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  preferences_window::property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "can-navigate-back"};
  }

  auto
  preferences_window::property_search_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "search-enabled"};
  }

  auto
  preferences_window::property_search_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "search-enabled"};
  }

  auto
  preferences_window::property_visible_page () -> glib::PropertyProxy<preferences_page*>
  {
    return {this, "visible-page"};
  }

  auto
  preferences_window::property_visible_page () const -> glib::PropertyProxy_ReadOnly<preferences_page*>
  {
    return {this, "visible-page"};
  }

  auto
  preferences_window::property_visible_page_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "visible-page-name"};
  }

  auto
  preferences_window::property_visible_page_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "visible-page-name"};
  }

} // namespace adw
