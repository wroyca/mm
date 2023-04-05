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
  wrap (AdwViewStackPage* object, bool take_copy) -> glib::RefPtr<adw::ViewStackPage>
  {
    return glib::make_refptr_for_instance<adw::ViewStackPage> (
        dynamic_cast<adw::ViewStackPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  ViewStackPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_page_get_type ();
    }

    return *this;
  }

  auto
  ViewStackPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ViewStackPage ((AdwViewStackPage*) object);
  }

  auto
  ViewStackPage::gobj_copy () -> AdwViewStackPage*
  {
    reference ();
    return gobj ();
  }

  ViewStackPage::ViewStackPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  ViewStackPage::ViewStackPage (AdwViewStackPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  ViewStackPage::ViewStackPage (ViewStackPage&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  ViewStackPage::operator= (ViewStackPage&& src) noexcept -> ViewStackPage&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  ViewStackPage::~ViewStackPage () noexcept {}

  ViewStackPage::CppClassType ViewStackPage::viewstackpage_class_;

  auto
  ViewStackPage::get_type () -> GType
  {
    return viewstackpage_class_.init ().get_type ();
  }

  auto
  ViewStackPage::get_base_type () -> GType
  {
    return adw_view_stack_page_get_type ();
  }

  ViewStackPage::ViewStackPage ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (viewstackpage_class_.init ()))
  {
  }

  auto
  ViewStackPage::create () -> glib::RefPtr<ViewStackPage>
  {
    return glib::make_refptr_for_instance<ViewStackPage> (new ViewStackPage ());
  }

  auto
  ViewStackPage::get_badge_number () const -> guint
  {
    return adw_view_stack_page_get_badge_number (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::get_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_view_stack_page_get_child (
        const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_icon_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_icon_name (
            const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_name () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_name (const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_needs_attention () const -> bool
  {
    return adw_view_stack_page_get_needs_attention (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::get_title () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_title (
            const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_use_underline () const -> bool
  {
    return adw_view_stack_page_get_use_underline (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::get_visible () const -> bool
  {
    return adw_view_stack_page_get_visible (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::set_badge_number (guint badge_number) -> void
  {
    adw_view_stack_page_set_badge_number (gobj (), badge_number);
  }

  auto
  ViewStackPage::set_icon_name (const glib::ustring& icon_name) -> void
  {
    adw_view_stack_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ViewStackPage::set_name (const glib::ustring& name) -> void
  {
    adw_view_stack_page_set_name (gobj (), name.c_str ());
  }

  auto
  ViewStackPage::set_needs_attention (bool needs_attention) -> void
  {
    adw_view_stack_page_set_needs_attention (
        gobj (),
        static_cast<int> (needs_attention));
  }

  auto
  ViewStackPage::set_title (const glib::ustring& title) -> void
  {
    adw_view_stack_page_set_title (gobj (), title.c_str ());
  }

  auto
  ViewStackPage::set_use_underline (bool use_underline) -> void
  {
    adw_view_stack_page_set_use_underline (gobj (),
                                           static_cast<int> (use_underline));
  }

  auto
  ViewStackPage::set_visible (bool visible) -> void
  {
    adw_view_stack_page_set_visible (gobj (), static_cast<int> (visible));
  }

  auto
  ViewStackPage::property_badge_number () -> glib::PropertyProxy<guint>
  {
    return glib::PropertyProxy<guint> (this, "badge-number");
  }

  auto
  ViewStackPage::property_badge_number () const -> glib::PropertyProxy_ReadOnly<guint>
  {
    return glib::PropertyProxy_ReadOnly<guint> (this, "badge-number");
  }

  auto
  ViewStackPage::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  ViewStackPage::property_icon_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "icon-name");
  }

  auto
  ViewStackPage::property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "icon-name");
  }

  auto
  ViewStackPage::property_name () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "name");
  }

  auto
  ViewStackPage::property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "name");
  }

  auto
  ViewStackPage::property_needs_attention () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "needs-attention");
  }

  auto
  ViewStackPage::property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "needs-attention");
  }

  auto
  ViewStackPage::property_title () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "title");
  }

  auto
  ViewStackPage::property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "title");
  }

  auto
  ViewStackPage::property_use_underline () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  ViewStackPage::property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  ViewStackPage::property_visible () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  ViewStackPage::property_visible () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

} // namespace adw
