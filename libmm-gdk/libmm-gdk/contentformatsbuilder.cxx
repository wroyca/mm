

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/contentformatsbuilder.hxx>
#include <libmm-gdk/contentformatsbuilder_p.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkContentFormatsBuilder* object, const bool take_copy) -> RefPtr<Gdk::ContentFormatsBuilder>
  {
    if (take_copy && object)
      gdk_content_formats_builder_ref (object);

    return Glib::make_refptr_for_instance<Gdk::ContentFormatsBuilder> (
        reinterpret_cast<Gdk::ContentFormatsBuilder*> (object));
  }

} // namespace Glib

namespace Gdk
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
  ContentFormatsBuilder::create () -> Glib::RefPtr<ContentFormatsBuilder>
  {
    return Glib::wrap (gdk_content_formats_builder_new ());
  }

  auto
  ContentFormatsBuilder::add_formats (
      const Glib::RefPtr<const ContentFormats>& formats) -> void
  {
    gdk_content_formats_builder_add_formats (gobj (), Glib::unwrap (formats));
  }

  auto
  ContentFormatsBuilder::add_mime_type (const Glib::ustring& mime_type) -> void
  {
    gdk_content_formats_builder_add_mime_type (gobj (), mime_type.c_str ());
  }

  auto
  ContentFormatsBuilder::add_gtype (const GType gtype) -> void
  {
    gdk_content_formats_builder_add_gtype (gobj (), gtype);
  }

  auto
  ContentFormatsBuilder::to_formats () -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_formats_builder_to_formats (gobj ()));
  }

} // namespace Gdk
