// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/tabpage.hxx>
#include <libmm/adw/tabpage_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
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
  wrap (AdwTabPage* object, bool take_copy) -> glib::RefPtr<adw::tab_page>
  {
    return glib::make_refptr_for_instance<adw::tab_page> (
        dynamic_cast<adw::tab_page*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  tab_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_tab_page_get_type ();
    }

    return *this;
  }

  auto
  tab_page_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new tab_page ((AdwTabPage*) object);
  }

  auto
  tab_page::gobj_copy () -> AdwTabPage*
  {
    reference ();
    return gobj ();
  }

  tab_page::tab_page (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  tab_page::tab_page (AdwTabPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  tab_page::tab_page (tab_page&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  tab_page::operator= (tab_page&& src) noexcept -> tab_page&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  tab_page::~tab_page () noexcept {}

  tab_page::CppClassType tab_page::tabpage_class_;

  auto
  tab_page::get_type () -> GType
  {
    return tabpage_class_.init ().get_type ();
  }

  auto
  tab_page::get_base_type () -> GType
  {
    return adw_tab_page_get_type ();
  }

  tab_page::tab_page ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (tabpage_class_.init ()))
  {
  }

  auto
  tab_page::create () -> glib::RefPtr<tab_page>
  {
    return glib::make_refptr_for_instance<tab_page> (new tab_page ());
  }

  auto
  tab_page::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_tab_page_get_child (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  tab_page::get_icon () const -> glib::RefPtr<gio::Icon>
  {
    auto retvalue =
        glib::wrap (adw_tab_page_get_icon (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  tab_page::get_indicator_activatable () const -> bool
  {
    return adw_tab_page_get_indicator_activatable (
        const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  tab_page::get_indicator_icon () const -> glib::RefPtr<gio::Icon>
  {
    auto retvalue = glib::wrap (
        adw_tab_page_get_indicator_icon (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  tab_page::get_indicator_tooltip () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_indicator_tooltip (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  tab_page::get_loading () const -> bool
  {
    return adw_tab_page_get_loading (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  tab_page::get_needs_attention () const -> bool
  {
    return adw_tab_page_get_needs_attention (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  tab_page::get_parent () const -> glib::RefPtr<tab_page>
  {
    auto retvalue = glib::wrap (
        adw_tab_page_get_parent (const_cast<AdwTabPage*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  tab_page::get_pinned () const -> bool
  {
    return adw_tab_page_get_pinned (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  tab_page::get_selected () const -> bool
  {
    return adw_tab_page_get_selected (const_cast<AdwTabPage*> (gobj ()));
  }

  auto
  tab_page::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_title (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  tab_page::get_tooltip () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_tab_page_get_tooltip (const_cast<AdwTabPage*> (gobj ())));
  }

  auto
  tab_page::set_icon (const glib::RefPtr<gio::Icon>& icon) -> void
  {
    adw_tab_page_set_icon (gobj (),
                           const_cast<GIcon*> (glib::unwrap<gio::Icon> (icon)));
  }

  auto
  tab_page::set_indicator_activatable (bool activatable) -> void
  {
    adw_tab_page_set_indicator_activatable (gobj (),
                                            static_cast<int> (activatable));
  }

  auto
  tab_page::set_indicator_icon (const glib::RefPtr<gio::Icon>& indicator_icon) -> void
  {
    adw_tab_page_set_indicator_icon (
        gobj (),
        const_cast<GIcon*> (glib::unwrap<gio::Icon> (indicator_icon)));
  }

  auto
  tab_page::set_indicator_tooltip (const glib::ustring& indicator_tooltip) -> void
  {
    adw_tab_page_set_indicator_tooltip (gobj (), indicator_tooltip.c_str ());
  }

  auto
  tab_page::set_loading (bool loading) -> void
  {
    adw_tab_page_set_loading (gobj (), static_cast<int> (loading));
  }

  auto
  tab_page::set_needs_attention (bool needs_attention) -> void
  {
    adw_tab_page_set_needs_attention (gobj (),
                                      static_cast<int> (needs_attention));
  }

  auto
  tab_page::set_title (const glib::ustring& title) -> void
  {
    adw_tab_page_set_title (gobj (), title.c_str ());
  }

  auto
  tab_page::set_tooltip (const glib::ustring& tooltip) -> void
  {
    adw_tab_page_set_tooltip (gobj (), tooltip.c_str ());
  }

  auto
  tab_page::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  tab_page::property_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return {this, "icon"};
  }

  auto
  tab_page::property_icon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return {this, "icon"};
  }

  auto
  tab_page::property_indicator_activatable () -> glib::PropertyProxy<bool>
  {
    return {this, "indicator-activatable"};
  }

  auto
  tab_page::property_indicator_activatable () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "indicator-activatable"};
  }

  auto
  tab_page::property_indicator_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>
  {
    return {this, "indicator-icon"};
  }

  auto
  tab_page::property_indicator_icon () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>
  {
    return {this, "indicator-icon"};
  }

  auto
  tab_page::property_indicator_tooltip () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "indicator-tooltip"};
  }

  auto
  tab_page::property_indicator_tooltip () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "indicator-tooltip"};
  }

  auto
  tab_page::property_loading () -> glib::PropertyProxy<bool>
  {
    return {this, "loading"};
  }

  auto
  tab_page::property_loading () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "loading"};
  }

  auto
  tab_page::property_needs_attention () -> glib::PropertyProxy<bool>
  {
    return {this, "needs-attention"};
  }

  auto
  tab_page::property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "needs-attention"};
  }

  auto
  tab_page::property_parent () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<tab_page>>
  {
    return {this, "parent"};
  }

  auto
  tab_page::property_pinned () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "pinned"};
  }

  auto
  tab_page::property_selected () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "selected"};
  }

  auto
  tab_page::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  tab_page::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  tab_page::property_tooltip () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "tooltip"};
  }

  auto
  tab_page::property_tooltip () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "tooltip"};
  }

} // namespace adw
