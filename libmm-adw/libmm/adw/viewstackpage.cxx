// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/viewstackpage.hxx>
#include <libmm/adw/viewstackpage_p.hxx>

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
  wrap (AdwViewStackPage* object, bool take_copy) -> Glib::RefPtr<Adw::ViewStackPage>
  {
    return Glib::make_refptr_for_instance<Adw::ViewStackPage> (
        dynamic_cast<Adw::ViewStackPage*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  ViewStackPage_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_view_stack_page_get_type ();
    }

    return *this;
  }

  auto
  ViewStackPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ViewStackPage ((AdwViewStackPage*) object);
  }

  auto
  ViewStackPage::gobj_copy () -> AdwViewStackPage*
  {
    reference ();
    return gobj ();
  }

  ViewStackPage::ViewStackPage (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  ViewStackPage::ViewStackPage (AdwViewStackPage* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  ViewStackPage::ViewStackPage (ViewStackPage&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  ViewStackPage::operator= (ViewStackPage&& src) noexcept -> ViewStackPage&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (viewstackpage_class_.init ()))
  {
  }

  auto
  ViewStackPage::create () -> Glib::RefPtr<ViewStackPage>
  {
    return Glib::make_refptr_for_instance<ViewStackPage> (new ViewStackPage ());
  }

  auto
  ViewStackPage::get_badge_number () const -> guint
  {
    return adw_view_stack_page_get_badge_number (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_view_stack_page_get_child (
        const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_icon_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_icon_name (
            const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_view_stack_page_get_name (const_cast<AdwViewStackPage*> (gobj ())));
  }

  auto
  ViewStackPage::get_needs_attention () const -> bool
  {
    return adw_view_stack_page_get_needs_attention (
        const_cast<AdwViewStackPage*> (gobj ()));
  }

  auto
  ViewStackPage::get_title () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  ViewStackPage::set_icon_name (const Glib::ustring& icon_name) -> void
  {
    adw_view_stack_page_set_icon_name (gobj (), icon_name.c_str ());
  }

  auto
  ViewStackPage::set_name (const Glib::ustring& name) -> void
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
  ViewStackPage::set_title (const Glib::ustring& title) -> void
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
  ViewStackPage::property_badge_number () -> Glib::PropertyProxy<guint>
  {
    return Glib::PropertyProxy<guint> (this, "badge-number");
  }

  auto
  ViewStackPage::property_badge_number () const -> Glib::PropertyProxy_ReadOnly<guint>
  {
    return Glib::PropertyProxy_ReadOnly<guint> (this, "badge-number");
  }

  auto
  ViewStackPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  ViewStackPage::property_icon_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "icon-name");
  }

  auto
  ViewStackPage::property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "icon-name");
  }

  auto
  ViewStackPage::property_name () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "name");
  }

  auto
  ViewStackPage::property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "name");
  }

  auto
  ViewStackPage::property_needs_attention () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "needs-attention");
  }

  auto
  ViewStackPage::property_needs_attention () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "needs-attention");
  }

  auto
  ViewStackPage::property_title () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "title");
  }

  auto
  ViewStackPage::property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "title");
  }

  auto
  ViewStackPage::property_use_underline () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "use-underline");
  }

  auto
  ViewStackPage::property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "use-underline");
  }

  auto
  ViewStackPage::property_visible () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "visible");
  }

  auto
  ViewStackPage::property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "visible");
  }

} // namespace Adw
