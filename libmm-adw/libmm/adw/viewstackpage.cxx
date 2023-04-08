// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewstackpage.hxx>
#include <libmm/adw/viewstackpage_p.hxx>

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
  wrap (AdwViewStackPage* object, bool take_copy) -> glib::RefPtr<adw::view_stack_page>
  {
    return glib::make_refptr_for_instance<adw::view_stack_page> (
        dynamic_cast<adw::view_stack_page*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  view_stack_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_page_get_type ();
    }

    return *this;
  }

  auto
  view_stack_page_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new view_stack_page ((AdwViewStackPage*) object);
  }

  auto
  view_stack_page::gobj_copy () -> AdwViewStackPage*
  {
    reference ();
    return gobj ();
  }

  view_stack_page::view_stack_page (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  view_stack_page::view_stack_page (AdwViewStackPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  view_stack_page::view_stack_page (view_stack_page&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  view_stack_page::operator= (view_stack_page&& src) noexcept -> view_stack_page&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  view_stack_page::~view_stack_page () noexcept {}

  view_stack_page::CppClassType view_stack_page::viewstackpage_class_;

  auto
  view_stack_page::get_type () -> GType
  {
    return viewstackpage_class_.init ().get_type ();
  }

  auto
  view_stack_page::get_base_type () -> GType
  {
    return adw_view_stack_page_get_type ();
  }

  view_stack_page::view_stack_page ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (viewstackpage_class_.init ()))
  {
  }

  auto
  view_stack_page::create () -> glib::RefPtr<view_stack_page>
  {
    return glib::make_refptr_for_instance<view_stack_page> (new view_stack_page ());
  }

  auto
  view_stack_page::get_badge_number () const -> guint
  {
    return adw_view_stack_page_get_badge_number (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  view_stack_page::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_view_stack_page_get_child (
        const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  view_stack_page::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_icon_name (
            const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  view_stack_page::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_name (const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  view_stack_page::get_needs_attention () const -> bool
  {
    return adw_view_stack_page_get_needs_attention (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  view_stack_page::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_title (
            const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  view_stack_page::get_use_underline () const -> bool
  {
    return adw_view_stack_page_get_use_underline (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  view_stack_page::get_visible () const -> bool
  {
    return adw_view_stack_page_get_visible (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  view_stack_page::set_badge_number (guint badge_number) -> void
  {
    adw_view_stack_page_set_badge_number (gobj (), badge_number);
  }

  auto
  view_stack_page::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_view_stack_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  view_stack_page::set_name (const glib::ustring& name) -> void
  {
    adw_view_stack_page_set_name (gobj (), name.c_str ());
  }

  auto
  view_stack_page::set_needs_attention (bool needs_attention) -> void
  {
    adw_view_stack_page_set_needs_attention (
        gobj (),
        static_cast<int> (needs_attention));
  }

  auto
  view_stack_page::set_title (const glib::ustring& title) -> void
  {
    adw_view_stack_page_set_title (gobj (), title.c_str ());
  }

  auto
  view_stack_page::set_use_underline (bool use_underline) -> void
  {
    adw_view_stack_page_set_use_underline (gobj (),
                                           static_cast<int> (use_underline));
  }

  auto
  view_stack_page::set_visible (bool visible) -> void
  {
    adw_view_stack_page_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  view_stack_page::property_badge_number () -> glib::PropertyProxy<guint>
  {
    return {this, "badge-number"};
  }

  auto
  view_stack_page::property_badge_number () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return {this, "badge-number"};
  }

  auto
  view_stack_page::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  view_stack_page::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  view_stack_page::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "icon-name"};
  }

  auto
  view_stack_page::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  view_stack_page::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "name"};
  }

  auto
  view_stack_page::property_needs_attention () -> glib::PropertyProxy<bool>
  {
    return {this, "needs-attention"};
  }

  auto
  view_stack_page::property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "needs-attention"};
  }

  auto
  view_stack_page::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  view_stack_page::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "title"};
  }

  auto
  view_stack_page::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return {this, "use-underline"};
  }

  auto
  view_stack_page::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-underline"};
  }

  auto
  view_stack_page::property_visible () -> glib::PropertyProxy<bool>
  {
    return {this, "visible"};
  }

  auto
  view_stack_page::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "visible"};
  }

} // namespace adw
