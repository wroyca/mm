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
  wrap (AdwSqueezerPage* object, bool take_copy) -> glib::RefPtr<adw::squeezer_page>
  {
    return glib::make_refptr_for_instance<adw::squeezer_page> (
        dynamic_cast<adw::squeezer_page*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  squeezer_page_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      gtype_ = adw_squeezer_page_get_type ();
    }

    return *this;
  }

  auto
  squeezer_page_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new squeezer_page ((AdwSqueezerPage*) object);
  }

  auto
  squeezer_page::gobj_copy () -> AdwSqueezerPage*
  {
    reference ();
    return gobj ();
  }

  squeezer_page::squeezer_page (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  squeezer_page::squeezer_page (AdwSqueezerPage* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  squeezer_page::squeezer_page (squeezer_page&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  squeezer_page::operator= (squeezer_page&& src) noexcept -> squeezer_page&
  {
    glib::Object::operator= (std::move (src));
    return *this;
  }

  squeezer_page::~squeezer_page () noexcept {}

  squeezer_page::CppClassType squeezer_page::squeezerpage_class_;

  auto
  squeezer_page::get_type () -> GType
  {
    return squeezerpage_class_.init ().get_type ();
  }

  auto
  squeezer_page::get_base_type () -> GType
  {
    return adw_squeezer_page_get_type ();
  }

  squeezer_page::squeezer_page ()
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (squeezerpage_class_.init ()))
  {
  }

  auto
  squeezer_page::create () -> glib::RefPtr<squeezer_page>
  {
    return glib::make_refptr_for_instance<squeezer_page> (new squeezer_page ());
  }

  auto
  squeezer_page::get_child () const -> gtk::Widget*
  {
    return glib::wrap (
        adw_squeezer_page_get_child (const_cast<AdwSqueezerPage*> (gobj ())));
  }

  auto
  squeezer_page::get_enabled () const -> bool
  {
    return adw_squeezer_page_get_enabled (
        const_cast<AdwSqueezerPage*> (gobj ()));
  }

  auto
  squeezer_page::set_enabled (bool enabled) -> void
  {
    adw_squeezer_page_set_enabled (gobj (), static_cast<int> (enabled));
  }

  auto
  squeezer_page::property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "child"};
  }

  auto
  squeezer_page::property_enabled () -> glib::PropertyProxy<bool>
  {
    return {this, "enabled"};
  }

  auto
  squeezer_page::property_enabled () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "enabled"};
  }

} // namespace adw
