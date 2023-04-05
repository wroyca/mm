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
  wrap (AdwPreferencesWindow* object, bool take_copy) -> adw::PreferencesWindow*
  {
    return dynamic_cast<adw::PreferencesWindow*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  PreferencesWindow_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PreferencesWindow_Class::class_init_function;

      register_derived_type (adw_preferences_window_get_type ());
    }

    return *this;
  }

  auto
  PreferencesWindow_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PreferencesWindow_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new PreferencesWindow ((AdwPreferencesWindow*) (o));
  }

  PreferencesWindow::PreferencesWindow (
      const glib::ConstructParams& construct_params)
    : adw::Window (construct_params)
  {
  }

  PreferencesWindow::PreferencesWindow (AdwPreferencesWindow* castitem)
    : adw::Window ((AdwWindow*) (castitem))
  {
  }

  PreferencesWindow::PreferencesWindow (PreferencesWindow&& src) noexcept
    : adw::Window (std::move (src))
  {
  }

  auto
  PreferencesWindow::operator= (PreferencesWindow&& src) noexcept -> PreferencesWindow&
  {
    adw::Window::operator= (std::move (src));
    return *this;
  }

  PreferencesWindow::~PreferencesWindow () noexcept
  {
    destroy_ ();
  }

  PreferencesWindow::CppClassType PreferencesWindow::preferenceswindow_class_;

  auto
  PreferencesWindow::get_type () -> GType
  {
    return preferenceswindow_class_.init ().get_type ();
  }

  auto
  PreferencesWindow::get_base_type () -> GType
  {
    return adw_preferences_window_get_type ();
  }

  PreferencesWindow::PreferencesWindow ()
    : glib::ObjectBase (nullptr),
      adw::Window (glib::ConstructParams (preferenceswindow_class_.init ()))
  {
  }

  auto
  PreferencesWindow::add (PreferencesPage* page) -> void
  {
    adw_preferences_window_add (gobj (),
                                (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  PreferencesWindow::add_toast (Toast* toast) -> void
  {
    adw_preferences_window_add_toast (gobj (),
                                      (AdwToast*) glib::unwrap (toast));
  }

  auto
  PreferencesWindow::close_subpage () -> void
  {
    adw_preferences_window_close_subpage (gobj ());
  }

  auto
  PreferencesWindow::get_can_navigate_back () const -> bool
  {
    return adw_preferences_window_get_can_navigate_back (
        const_cast<AdwPreferencesWindow*> (gobj ()));
  }

  auto
  PreferencesWindow::get_search_enabled () const -> bool
  {
    return adw_preferences_window_get_search_enabled (
        const_cast<AdwPreferencesWindow*> (gobj ()));
  }

  auto
  PreferencesWindow::get_visible_page () const -> PreferencesPage*
  {
    return glib::wrap (adw_preferences_window_get_visible_page (
        const_cast<AdwPreferencesWindow*> (gobj ())));
  }

  auto
  PreferencesWindow::get_visible_page_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_window_get_visible_page_name (
            const_cast<AdwPreferencesWindow*> (gobj ())));
  }

  auto
  PreferencesWindow::present_subpage (gtk::Widget* subpage) -> void
  {
    adw_preferences_window_present_subpage (
        gobj (),
        (GtkWidget*) glib::unwrap (subpage));
  }

  auto
  PreferencesWindow::remove (PreferencesPage* page) -> void
  {
    adw_preferences_window_remove (gobj (),
                                   (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  PreferencesWindow::set_can_navigate_back (bool can_navigate_back) -> void
  {
    adw_preferences_window_set_can_navigate_back (
        gobj (),
        static_cast<int> (can_navigate_back));
  }

  auto
  PreferencesWindow::set_search_enabled (bool search_enabled) -> void
  {
    adw_preferences_window_set_search_enabled (
        gobj (),
        static_cast<int> (search_enabled));
  }

  auto
  PreferencesWindow::set_visible_page (PreferencesPage* page) -> void
  {
    adw_preferences_window_set_visible_page (
        gobj (),
        (AdwPreferencesPage*) glib::unwrap (page));
  }

  auto
  PreferencesWindow::set_visible_page_name (const glib::ustring& name) -> void
  {
    adw_preferences_window_set_visible_page_name (gobj (), name.c_str ());
  }

  auto
  PreferencesWindow::property_can_navigate_back () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "can-navigate-back");
  }

  auto
  PreferencesWindow::property_can_navigate_back () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "can-navigate-back");
  }

  auto
  PreferencesWindow::property_search_enabled () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "search-enabled");
  }

  auto
  PreferencesWindow::property_search_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "search-enabled");
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<PreferencesPage*>::value,
      "Type PreferencesPage* cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  PreferencesWindow::property_visible_page () -> glib::PropertyProxy<PreferencesPage*>
  {
    return glib::PropertyProxy<PreferencesPage*> (this, "visible-page");
  }

  auto
  PreferencesWindow::property_visible_page () const -> glib::PropertyProxy_ReadOnly<PreferencesPage*>
  {
    return glib::PropertyProxy_ReadOnly<PreferencesPage*> (this,
                                                           "visible-page");
  }

  auto
  PreferencesWindow::property_visible_page_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "visible-page-name");
  }

  auto
  PreferencesWindow::property_visible_page_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this,
                                                        "visible-page-name");
  }

} // namespace adw
