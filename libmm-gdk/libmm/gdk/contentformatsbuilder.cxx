// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/contentformatsbuilder.hxx>
#include <libmm/gdk/contentformatsbuilder_p.hxx>

namespace
{
}

namespace glib
{

  auto
  wrap (GdkContentFormatsBuilder* object, bool take_copy) -> glib::RefPtr<gdk::ContentFormatsBuilder>
  {
    if (take_copy && object)
      gdk_content_formats_builder_ref (object);

    return glib::make_refptr_for_instance<gdk::ContentFormatsBuilder> (
        reinterpret_cast<gdk::ContentFormatsBuilder*> (object));
  }

} // namespace glib

namespace gdk
{

  auto
  ContentFormatsBuilder::reference () const -> void
  {
    gdk_content_formats_builder_ref (
        reinterpret_cast<GdkContentFormatsBuilder*> (
            const_cast<ContentFormatsBuilder*> (this)));
  }

  auto
  ContentFormatsBuilder::unreference () const -> void
  {
    gdk_content_formats_builder_unref (
        reinterpret_cast<GdkContentFormatsBuilder*> (
            const_cast<ContentFormatsBuilder*> (this)));
  }

  auto
  ContentFormatsBuilder::gobj () -> GdkContentFormatsBuilder*
  {
    return reinterpret_cast<GdkContentFormatsBuilder*> (this);
  }

  auto
  ContentFormatsBuilder::gobj () const -> const GdkContentFormatsBuilder*
  {
    return reinterpret_cast<const GdkContentFormatsBuilder*> (this);
  }

  auto
  ContentFormatsBuilder::gobj_copy () const -> GdkContentFormatsBuilder*
  {
    const auto gobject = reinterpret_cast<GdkContentFormatsBuilder*> (
        const_cast<ContentFormatsBuilder*> (this));
    gdk_content_formats_builder_ref (gobject);
    return gobject;
  }

  auto
  ContentFormatsBuilder::create () -> glib::RefPtr<ContentFormatsBuilder>
  {
    return glib::wrap (gdk_content_formats_builder_new ());
  }

  auto
  ContentFormatsBuilder::add_formats (
      const glib::RefPtr<const ContentFormats>& formats) -> void
  {
    gdk_content_formats_builder_add_formats (gobj (), glib::unwrap (formats));
  }

  auto
  ContentFormatsBuilder::add_mime_type (const glib::ustring& mime_type) -> void
  {
    gdk_content_formats_builder_add_mime_type (gobj (), mime_type.c_str ());
  }

  auto
  ContentFormatsBuilder::add_gtype (GType gtype) -> void
  {
    gdk_content_formats_builder_add_gtype (gobj (), gtype);
  }

  auto
  ContentFormatsBuilder::to_formats () -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_formats_builder_to_formats (gobj ()));
  }

} // namespace gdk
