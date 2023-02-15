// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-adw/squeezerpage.hxx>
#include <libmm-adw/squeezerpage_p.hxx>

#include <adwaita.h>
#include <libmm-glib/mm-glib.hxx>
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
  wrap (AdwSqueezerPage* object, bool take_copy) -> Glib::RefPtr<Adw::SqueezerPage>
  {
    return Glib::make_refptr_for_instance<Adw::SqueezerPage> (
        dynamic_cast<Adw::SqueezerPage*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  SqueezerPage_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_page_get_type ();
    }

    return *this;
  }

  auto
  SqueezerPage_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SqueezerPage ((AdwSqueezerPage*) object);
  }

  auto
  SqueezerPage::gobj_copy () -> AdwSqueezerPage*
  {
    reference ();
    return gobj ();
  }

  SqueezerPage::SqueezerPage (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  SqueezerPage::SqueezerPage (AdwSqueezerPage* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  SqueezerPage::SqueezerPage (SqueezerPage&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  SqueezerPage::operator= (SqueezerPage&& src) noexcept -> SqueezerPage&
  {
    Glib::Object::operator= (std::move (src));
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
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (squeezerpage_class_.init ()))
  {
  }

  auto
  SqueezerPage::create () -> Glib::RefPtr<SqueezerPage>
  {
    return Glib::make_refptr_for_instance<SqueezerPage> (new SqueezerPage ());
  }

  auto
  SqueezerPage::get_child () const -> Gtk::Widget*
  {
    return Glib::wrap (
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
  SqueezerPage::property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "child");
  }

  auto
  SqueezerPage::property_enabled () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "enabled");
  }

  auto
  SqueezerPage::property_enabled () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "enabled");
  }

} // namespace Adw
