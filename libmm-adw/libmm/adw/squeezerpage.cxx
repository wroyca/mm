// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/squeezerpage.hxx>
#include <libmm/adw/squeezerpage_p.hxx>

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
  wrap (AdwSqueezerPage* object, bool take_copy) -> glib::RefPtr<adw::SqueezerPage>
  {
    return glib::make_refptr_for_instance<adw::SqueezerPage> (
        dynamic_cast<adw::SqueezerPage*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  SqueezerPage_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_page_get_type ();
    }

    return *this;
  }

  auto
  SqueezerPage_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SqueezerPage ((AdwSqueezerPage*) object);
  }

  auto
  SqueezerPage::gobj_copy () -> AdwSqueezerPage*
  {
    reference ();
    return gobj ();
  }

  SqueezerPage::SqueezerPage (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SqueezerPage::SqueezerPage (AdwSqueezerPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SqueezerPage::SqueezerPage (SqueezerPage&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  SqueezerPage::operator= (SqueezerPage&& src) noexcept -> SqueezerPage&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  SqueezerPage::~SqueezerPage () noexcept {}

  SqueezerPage::CppClassType SqueezerPage::squeezerpage_class_;

  auto
  SqueezerPage::get_type () -> GType
  {
    return squeezerpage_class_.init ().get_type ();
  }

  auto
  SqueezerPage::get_base_type () -> GType
  {
    return adw_squeezer_page_get_type ();
  }

  SqueezerPage::SqueezerPage ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (squeezerpage_class_.init ()))
  {
  }

  auto
  SqueezerPage::create () -> glib::RefPtr<SqueezerPage>
  {
    return glib::make_refptr_for_instance<SqueezerPage> (new SqueezerPage ());
  }

  auto
  SqueezerPage::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_squeezer_page_get_child (const_cast<AdwSqueezerPage*> (gobj ())));
  }

  auto
  SqueezerPage::get_enabled () const -> bool
  {
    return adw_squeezer_page_get_enabled (
        const_cast<AdwSqueezerPage*> (gobj ()));
  }

  auto
  SqueezerPage::set_enabled (bool enabled) -> void
  {
    adw_squeezer_page_set_enabled (gobj (), static_cast<int> (enabled));
  }

  auto
  SqueezerPage::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return glib::PropertyProxy_ReadOnly<gtk::Widget*> (this, "child");
  }

  auto
  SqueezerPage::property_enabled () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "enabled");
  }

  auto
  SqueezerPage::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "enabled");
  }

} // namespace adw
