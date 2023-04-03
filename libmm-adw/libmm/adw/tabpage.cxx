// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/tabpage.hxx>
#include <libmm/adw/tabpage_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
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
  wrap (AdwTabPage* object, bool take_copy) -> Glib::RefPtr<Adw::TabPage>
  {
    return Glib::make_refptr_for_instance<Adw::TabPage> (
        dynamic_cast<Adw::TabPage*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  TabPage_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_page_get_type ();
    }

    return *this;
  }

  auto
  TabPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new TabPage ((AdwTabPage*) object);
  }

  auto
  TabPage::gobj_copy () -> AdwTabPage*
  {
    reference ();
    return gobj ();
  }

  TabPage::TabPage (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  TabPage::TabPage (AdwTabPage* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  TabPage::TabPage (TabPage&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  TabPage::operator= (TabPage&& src) noexcept -> TabPage&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  TabPage::~TabPage () noexcept {}

  TabPage::CppClassType TabPage::tabpage_class_;

  auto
  TabPage::get_type () -> GType
  {
    return tabpage_class_.init ().get_type ();
  }

  auto
  TabPage::get_base_type () -> GType
  {
    return adw_tab_page_get_type ();
  }

  TabPage::TabPage ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (tabpage_class_.init ()))
  {
  }

  auto
  TabPage::create () -> Glib::RefPtr<TabPage>
  {
    return Glib::make_refptr_for_instance<TabPage> (new TabPage ());
  }

  auto
  TabPage::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
        adw_tab_page_get_child (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  TabPage::get_icon () const -> Glib::RefPtr<Gio::Icon>
  {
    auto retvalue =
        Glib::wrap (adw_tab_page_get_icon (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabPage::get_indicator_activatable () const -> bool
  {
    return adw_tab_page_get_indicator_activatable (
        const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  TabPage::get_indicator_icon () const -> Glib::RefPtr<Gio::Icon>
  {
    auto retvalue = Glib::wrap (
        adw_tab_page_get_indicator_icon (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabPage::get_indicator_tooltip () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_indicator_tooltip (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  TabPage::get_loading () const -> bool
  {
    return adw_tab_page_get_loading (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  TabPage::get_needs_attention () const -> bool
  {
    return adw_tab_page_get_needs_attention (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  TabPage::get_parent () const -> Glib::RefPtr<TabPage>
  {
    auto retvalue = Glib::wrap (
        adw_tab_page_get_parent (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  TabPage::get_pinned () const -> bool
  {
    return adw_tab_page_get_pinned (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  TabPage::get_selected () const -> bool
  {
    return adw_tab_page_get_selected (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  TabPage::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_title (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  TabPage::get_tooltip () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_tooltip (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  TabPage::set_icon (const Glib::RefPtr<Gio::Icon>& icon) -> void
  {
    adw_tab_page_set_icon (gobj (),
                           const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (icon)));
  }

  auto
  TabPage::set_indicator_activatable (bool activatable) -> void
  {
    adw_tab_page_set_indicator_activatable (gobj (),
                                            static_cast<int> (activatable));
  }

  auto
  TabPage::set_indicator_icon (const Glib::RefPtr<Gio::Icon>& indicator_icon) -> void
  {
    adw_tab_page_set_indicator_icon (
        gobj (),
        const_cast<GIcon*> (Glib::unwrap<Gio::Icon> (indicator_icon)));
  }

  auto
  TabPage::set_indicator_tooltip (const Glib::ustring& indicator_tooltip) -> void
  {
    adw_tab_page_set_indicator_tooltip (gobj (), indicator_tooltip.c_str ());
  }

  auto
  TabPage::set_loading (bool loading) -> void
  {
    adw_tab_page_set_loading (gobj (), static_cast<int> (loading));
  }

  auto
  TabPage::set_needs_attention (bool needs_attention) -> void
  {
    adw_tab_page_set_needs_attention (gobj (),
                                      static_cast<int> (needs_attention));
  }

  auto
  TabPage::set_title (const Glib::ustring& title) -> void
  {
    adw_tab_page_set_title (gobj (), title.c_str ());
  }

  auto
  TabPage::set_tooltip (const Glib::ustring& tooltip) -> void
  {
    adw_tab_page_set_tooltip (gobj (), tooltip.c_str ());
  }

  auto
  TabPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabPage::property_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (this, "icon");
  }

  auto
  TabPage::property_icon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (this, "icon");
  }

  auto
  TabPage::property_indicator_activatable () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "indicator-activatable");
  }

  auto
  TabPage::property_indicator_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "indicator-activatable");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Gio::Icon>>::value,
      "Type Glib::RefPtr<Gio::Icon> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabPage::property_indicator_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>> (this,
                                                         "indicator-icon");
  }

  auto
  TabPage::property_indicator_icon () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>> (
        this,
        "indicator-icon");
  }

  auto
  TabPage::property_indicator_tooltip () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "indicator-tooltip");
  }

  auto
  TabPage::property_indicator_tooltip () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "indicator-tooltip");
  }

  auto
  TabPage::property_loading () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "loading");
  }

  auto
  TabPage::property_loading () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "loading");
  }

  auto
  TabPage::property_needs_attention () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "needs-attention");
  }

  auto
  TabPage::property_needs_attention () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "needs-attention");
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<TabPage>>::value,
      "Type Glib::RefPtr<TabPage> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  TabPage::property_parent () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>> (this, "parent");
  }

  auto
  TabPage::property_pinned () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "pinned");
  }

  auto
  TabPage::property_selected () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "selected");
  }

  auto
  TabPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  TabPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  TabPage::property_tooltip () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "tooltip");
  }

  auto
  TabPage::property_tooltip () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "tooltip");
  }

} // namespace Adw
