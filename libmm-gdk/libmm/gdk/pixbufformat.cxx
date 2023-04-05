// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/pixbufformat.hxx>
#include <libmm/gdk/pixbufformat_p.hxx>

#include <gdk-pixbuf/gdk-pixbuf.h>

namespace gdk
{

  PixbufFormat::PixbufFormat ()
    : gobject_ (nullptr)
  {
  }

} // namespace gdk

namespace
{
}

namespace glib
{

  auto
  wrap (GdkPixbufFormat* object, bool take_copy) -> gdk::PixbufFormat
  {
    return gdk::PixbufFormat (object, take_copy);
  }

} // namespace glib

namespace gdk
{

  auto
  PixbufFormat::get_type () -> GType
  {
    return gdk_pixbuf_format_get_type ();
  }

  PixbufFormat::PixbufFormat (const PixbufFormat& other)
    : gobject_ ((other.gobject_) ? gdk_pixbuf_format_copy (other.gobject_) :
                                   nullptr)
  {
  }

  PixbufFormat::PixbufFormat (PixbufFormat&& other) noexcept
    : gobject_ (other.gobject_)
  {
    other.gobject_ = nullptr;
  }

  auto
  PixbufFormat::operator= (PixbufFormat&& other) noexcept -> PixbufFormat&
  {
    PixbufFormat temp (std::move (other));
    swap (temp);
    return *this;
  }

  PixbufFormat::PixbufFormat (GdkPixbufFormat* gobject, bool make_a_copy)
    : gobject_ ((make_a_copy && gobject) ? gdk_pixbuf_format_copy (gobject) :
                                           gobject)
  {
  }

  auto
  PixbufFormat::operator= (const PixbufFormat& other) -> PixbufFormat&
  {
    PixbufFormat temp (other);
    swap (temp);
    return *this;
  }

  PixbufFormat::~PixbufFormat () noexcept
  {
    if (gobject_)
      gdk_pixbuf_format_free (gobject_);
  }

  auto
  PixbufFormat::swap (PixbufFormat& other) noexcept -> void
  {
    std::swap (gobject_, other.gobject_);
  }

  auto
  PixbufFormat::gobj_copy () const -> GdkPixbufFormat*
  {
    return gdk_pixbuf_format_copy (gobject_);
  }

  auto
  PixbufFormat::get_name () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gdk_pixbuf_format_get_name (const_cast<GdkPixbufFormat*> (gobj ())));
  }

  auto
  PixbufFormat::get_description () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gdk_pixbuf_format_get_description (
            const_cast<GdkPixbufFormat*> (gobj ())));
  }

  auto
  PixbufFormat::get_mime_types () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gdk_pixbuf_format_get_mime_types (
            const_cast<GdkPixbufFormat*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  PixbufFormat::get_extensions () const -> std::vector<glib::ustring>
  {
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        gdk_pixbuf_format_get_extensions (
            const_cast<GdkPixbufFormat*> (gobj ())),
        glib::OWNERSHIP_DEEP);
  }

  auto
  PixbufFormat::is_save_option_supported (const glib::ustring& option_key) const -> bool
  {
    return gdk_pixbuf_format_is_save_option_supported (
        const_cast<GdkPixbufFormat*> (gobj ()),
        option_key.c_str ());
  }

  auto
  PixbufFormat::is_writable () const -> bool
  {
    return gdk_pixbuf_format_is_writable (
        const_cast<GdkPixbufFormat*> (gobj ()));
  }

  auto
  PixbufFormat::is_scalable () const -> bool
  {
    return gdk_pixbuf_format_is_scalable (
        const_cast<GdkPixbufFormat*> (gobj ()));
  }

  auto
  PixbufFormat::is_disabled () const -> bool
  {
    return gdk_pixbuf_format_is_disabled (
        const_cast<GdkPixbufFormat*> (gobj ()));
  }

  auto
  PixbufFormat::set_disabled (bool disabled) -> void
  {
    gdk_pixbuf_format_set_disabled (gobj (), static_cast<int> (disabled));
  }

  auto
  PixbufFormat::get_license () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gdk_pixbuf_format_get_license (const_cast<GdkPixbufFormat*> (gobj ())));
  }

} // namespace gdk
