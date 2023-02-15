// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/preferencespage.hxx>
#include <libmm-adw/preferencespage_p.hxx>

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
  wrap (AdwPreferencesPage* object, bool take_copy) -> Adw::PreferencesPage*
  {
    return dynamic_cast<Adw::PreferencesPage*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  PreferencesPage_Class::init () -> const Glib::Class&
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
  PreferencesPage_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return manage (new PreferencesPage ((AdwPreferencesPage*) (o)));
  }

  PreferencesPage::PreferencesPage (
      const Glib::ConstructParams& construct_params)
    : Gtk::Widget (construct_params)
  {
  }

  PreferencesPage::PreferencesPage (AdwPreferencesPage* castitem)
    : Gtk::Widget ((GtkWidget*) (castitem))
  {
  }

  PreferencesPage::PreferencesPage (PreferencesPage&& src) noexcept
    : Gtk::Widget (std::move (src))
  {
  }

  auto
  PreferencesPage::operator= (PreferencesPage&& src) noexcept -> PreferencesPage&
  {
    Gtk::Widget::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Gtk::Widget (Glib::ConstructParams (preferencespage_class_.init ()))
  {
  }

  auto
  PreferencesPage::add (PreferencesGroup* group) -> void
  {
    adw_preferences_page_add (gobj (),
                              (AdwPreferencesGroup*) Glib::unwrap (group));
  }

  auto
  PreferencesPage::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_icon_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  PreferencesPage::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_preferences_page_get_name (
            const_cast<AdwPreferencesPage*> (gobj ())));
  }

  auto
  PreferencesPage::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
                                 (AdwPreferencesGroup*) Glib::unwrap (group));
  }

  auto
  PreferencesPage::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_preferences_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  PreferencesPage::set_name (const Glib::ustring& name) -> void
  {
    adw_preferences_page_set_name (gobj (), name.c_str ());
  }

  auto
  PreferencesPage::set_title (const Glib::ustring& title) -> void
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
  PreferencesPage::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  PreferencesPage::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  PreferencesPage::property_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "name");
  }

  auto
  PreferencesPage::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  PreferencesPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  PreferencesPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  PreferencesPage::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  PreferencesPage::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

} // namespace Adw
