// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/contentformats_p.hxx>

#include <gdk/gdk.h>

#include <libmm/glib/vectorutils.hxx>

namespace gdk
{

  auto
  ContentFormats::create (const std::vector<glib::ustring>& mime_types) -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_formats_new (
        glib::ArrayHandler<glib::ustring>::vector_to_array (mime_types).data (),
        mime_types.size ()));
  }

  auto
  ContentFormats::create (const glib::ustring& mime_type) -> glib::RefPtr<ContentFormats>
  {
    const char* c_mime_type = mime_type.c_str ();
    return glib::wrap (gdk_content_formats_new (&c_mime_type, 1));
  }

  auto
  ContentFormats::get_gtypes () const -> std::vector<GType>
  {
    gsize n_gtypes = 0;
    const GType* gtype_array = gdk_content_formats_get_gtypes (gobj (),
                                                               &n_gtypes);
    return glib::ArrayHandler<GType>::array_to_vector (gtype_array,
                                                       n_gtypes,
                                                       glib::OWNERSHIP_NONE);
  }

  auto
  ContentFormats::get_mime_types () const -> std::vector<glib::ustring>
  {
    gsize n_mime_types = 0;
    const char* const* mime_type_array =
        gdk_content_formats_get_mime_types (gobj (), &n_mime_types);
    return glib::ArrayHandler<glib::ustring>::array_to_vector (
        mime_type_array,
        n_mime_types,
        glib::OWNERSHIP_NONE);
  }

  auto
  ContentFormats::join (const glib::RefPtr<const ContentFormats>& second) const -> glib::RefPtr<ContentFormats>
  {
    reference ();
    return glib::wrap (
        gdk_content_formats_union (const_cast<GdkContentFormats*> (gobj ()),
                                   glib::unwrap (second)));
  }

} // namespace gdk

namespace glib
{

  auto
  Value<RefPtr<gdk::ContentFormats>>::value_type () -> GType
  {
    return gdk_content_formats_get_type ();
  }

  auto
  Value<RefPtr<gdk::ContentFormats>>::set (const CppType& data) -> void
  {
    set_boxed (glib::unwrap (data));
  }

  auto
  Value<RefPtr<gdk::ContentFormats>>::get () const -> Value<RefPtr<gdk::ContentFormats>>::CppType
  {
    return glib::wrap (static_cast<CType> (get_boxed ()), true);
  }

} // namespace glib

namespace
{
}

namespace glib
{

  auto
  wrap (GdkContentFormats* object, bool take_copy) -> glib::RefPtr<gdk::ContentFormats>
  {
    if (take_copy && object)
      gdk_content_formats_ref (object);

    return glib::make_refptr_for_instance<gdk::ContentFormats> (
        reinterpret_cast<gdk::ContentFormats*> (object));
  }

} // namespace glib

namespace gdk
{

  auto
  ContentFormats::reference () const -> void
  {
    gdk_content_formats_ref (reinterpret_cast<GdkContentFormats*> (
        const_cast<ContentFormats*> (this)));
  }

  auto
  ContentFormats::unreference () const -> void
  {
    gdk_content_formats_unref (reinterpret_cast<GdkContentFormats*> (
        const_cast<ContentFormats*> (this)));
  }

  auto
  ContentFormats::gobj () -> GdkContentFormats*
  {
    return reinterpret_cast<GdkContentFormats*> (this);
  }

  auto
  ContentFormats::gobj () const -> const GdkContentFormats*
  {
    return reinterpret_cast<const GdkContentFormats*> (this);
  }

  auto
  ContentFormats::gobj_copy () const -> GdkContentFormats*
  {
    const auto gobject = reinterpret_cast<GdkContentFormats*> (
        const_cast<ContentFormats*> (this));
    gdk_content_formats_ref (gobject);
    return gobject;
  }

  auto
  ContentFormats::create (GType type) -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_formats_new_for_gtype (type));
  }

  auto
  ContentFormats::parse (const glib::ustring& string) -> glib::RefPtr<ContentFormats>
  {
    return glib::wrap (gdk_content_formats_parse (string.c_str ()));
  }

  auto
  ContentFormats::to_string () const -> glib::ustring
  {
    return glib::convert_return_gchar_ptr_to_ustring (
        gdk_content_formats_to_string (
            const_cast<GdkContentFormats*> (gobj ())));
  }

  auto
  ContentFormats::contain_gtype (GType type) const -> bool
  {
    return gdk_content_formats_contain_gtype (
        const_cast<GdkContentFormats*> (gobj ()),
        type);
  }

  auto
  ContentFormats::contain_mime_type (const glib::ustring& mime_type) const -> bool
  {
    return gdk_content_formats_contain_mime_type (
        const_cast<GdkContentFormats*> (gobj ()),
        mime_type.c_str ());
  }

  auto
  ContentFormats::match (const glib::RefPtr<const ContentFormats>& second) const -> bool
  {
    return gdk_content_formats_match (const_cast<GdkContentFormats*> (gobj ()),
                                      glib::unwrap (second));
  }

  auto
  ContentFormats::match_gtype (
      const glib::RefPtr<const ContentFormats>& second) const -> GType
  {
    return gdk_content_formats_match_gtype (
        const_cast<GdkContentFormats*> (gobj ()),
        glib::unwrap (second));
  }

  auto
  ContentFormats::match_mime_type (
      const glib::RefPtr<const ContentFormats>& second) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gdk_content_formats_match_mime_type (
            const_cast<GdkContentFormats*> (gobj ()),
            glib::unwrap (second)));
  }

} // namespace gdk
