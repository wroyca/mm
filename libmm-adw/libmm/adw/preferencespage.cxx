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
  wrap (AdwPreferencesPage* object, bool take_copy) -> adw::PreferencesPage*
  {
    return dynamic_cast<adw::PreferencesPage*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  PreferencesPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &PreferencesPage_Class::class_init_function;

      register_derived_type (adw_preferences_page_get_type ());
    }

    return *this;
  }

  auto
  PreferencesPage_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  PreferencesPage_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new PreferencesPage ((AdwPreferencesPage*) (o)));
  }

  PreferencesPage::PreferencesPage (
      const glib::ConstructParams& construct_params)
    : gtk::Widget (construct_params)
  {
  }

  PreferencesPage::PreferencesPage (AdwPreferencesPage* castitem)
    : gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PreferencesPage::PreferencesPage (PreferencesPage&& src) noexcept
    : gtk::Widget (std::move (src))
  {
  }

  auto
  PreferencesPage::operator= (PreferencesPage&& src) noexcept -> PreferencesPage&
  {
    gtk::Widget::operator= (std::move (src));
    return *this;
  }

  PreferencesPage::~PreferencesPage () noexcept
  {
    destroy_ ();
  }

  PreferencesPage::CppClassType PreferencesPage::preferencespage_class_;

  auto
  PreferencesPage::get_type () -> GType
  {
    return preferencespage_class_.init ().get_type ();
  }

  auto
  PreferencesPage::get_base_type () -> GType
  {
    return adw_preferences_page_get_type ();
  }

  PreferencesPage::PreferencesPage ()
    : glib::ObjectBase (nullptr),
      gtk::Widget (glib::ConstructParams (preferencespage_class_.init ()))
  {
  }

  auto
  PreferencesPage::add (PreferencesGroup* group) -> void
  {
    adw_preferences_page_add (gobj (),
                              (AdwPreferencesGroup*) glib::unwrap (group));
  }

  auto
  PreferencesPage::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_icon_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  PreferencesPage::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  PreferencesPage::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_title (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  PreferencesPage::get_use_underline () const -> bool
  {
    return adw_preferences_page_get_use_underline (
        const_cast<AdwPreferencesPage*> (gobj ()));
  }

  auto
  PreferencesPage::remove (PreferencesGroup* group) -> void
  {
    adw_preferences_page_remove (gobj (),
                                 (AdwPreferencesGroup*) glib::unwrap (group));
  }

  auto
  PreferencesPage::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_preferences_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  PreferencesPage::set_name (const glib::ustring& name) -> void
  {
    adw_preferences_page_set_name (gobj (), name.c_str ());
  }

  auto
  PreferencesPage::set_title (const glib::ustring& title) -> void
  {
    adw_preferences_page_set_title (gobj (), title.c_str ());
  }

  auto
  PreferencesPage::set_use_underline (bool use_underline) -> void
  {
    adw_preferences_page_set_use_underline (gobj (),
                                            static_cast<int> (use_underline));
  }

  auto
  PreferencesPage::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  PreferencesPage::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  PreferencesPage::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  PreferencesPage::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  PreferencesPage::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  PreferencesPage::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  PreferencesPage::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  PreferencesPage::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

} // namespace adw
