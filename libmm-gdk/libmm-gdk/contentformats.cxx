// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/contentformats_p.hxx>

#include <gdk/gdk.h>

#include <libmm-glib/vectorutils.hxx>

namespace Gdk
{

  auto
  ContentFormats::create (const std::vector<Glib::ustring>& mime_types) -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_formats_new (
        Glib::ArrayHandler<Glib::ustring>::vector_to_array (mime_types).data (),
        mime_types.size ()));
  }

  auto
  ContentFormats::create (const Glib::ustring& mime_type) -> Glib::RefPtr<ContentFormats>
  {
    const char* c_mime_type = mime_type.c_str ();
    return Glib::wrap (gdk_content_formats_new (&c_mime_type, 1));
  }

  auto
  ContentFormats::get_gtypes () const -> std::vector<GType>
  {
    gsize n_gtypes = 0;
    const GType* gtype_array = gdk_content_formats_get_gtypes (gobj (),
                                                               &n_gtypes);
    return Glib::ArrayHandler<GType>::array_to_vector (gtype_array,
                                                       n_gtypes,
                                                       Glib::OWNERSHIP_NONE);
  }

  auto
  ContentFormats::get_mime_types () const -> std::vector<Glib::ustring>
  {
    gsize n_mime_types = 0;
    const char* const* mime_type_array =
        gdk_content_formats_get_mime_types (gobj (), &n_mime_types);
    return Glib::ArrayHandler<Glib::ustring>::array_to_vector (
        mime_type_array,
        n_mime_types,
        Glib::OWNERSHIP_NONE);
  }

  auto
  ContentFormats::join (const Glib::RefPtr<const ContentFormats>& second) const -> Glib::RefPtr<ContentFormats>
  {
    reference ();
    return Glib::wrap (
        gdk_content_formats_union (const_cast<GdkContentFormats*> (gobj ()),
                                   Glib::unwrap (second)));
  }

} // namespace Gdk

namespace Glib
{

  auto
  Value<RefPtr<Gdk::ContentFormats>>::value_type () -> GType
  {
    return gdk_content_formats_get_type ();
  }

  auto
  Value<RefPtr<Gdk::ContentFormats>>::set (const CppType& data) -> void
  {
    set_boxed (Glib::unwrap (data));
  }

  auto
  Value<RefPtr<Gdk::ContentFormats>>::get () const -> Value<RefPtr<Gdk::ContentFormats>>::CppType
  {
    return Glib::wrap (static_cast<CType> (get_boxed ()), true);
  }

} // namespace Glib

namespace
{
}

namespace Glib
{

  auto
  wrap (GdkContentFormats* object, bool take_copy) -> Glib::RefPtr<Gdk::ContentFormats>
  {
    if (take_copy && object)
      gdk_content_formats_ref (object);

    return Glib::make_refptr_for_instance<Gdk::ContentFormats> (
        reinterpret_cast<Gdk::ContentFormats*> (object));
  }

} // namespace Glib

namespace Gdk
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
  ContentFormats::create (GType type) -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_formats_new_for_gtype (type));
  }

  auto
  ContentFormats::parse (const Glib::ustring& string) -> Glib::RefPtr<ContentFormats>
  {
    return Glib::wrap (gdk_content_formats_parse (string.c_str ()));
  }

  auto
  ContentFormats::to_string () const -> Glib::ustring
  {
    return Glib::convert_return_gchar_ptr_to_ustring (
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
  ContentFormats::contain_mime_type (const Glib::ustring& mime_type) const -> bool
  {
    return gdk_content_formats_contain_mime_type (
        const_cast<GdkContentFormats*> (gobj ()),
        mime_type.c_str ());
  }

  auto
  ContentFormats::match (const Glib::RefPtr<const ContentFormats>& second) const -> bool
  {
    return gdk_content_formats_match (const_cast<GdkContentFormats*> (gobj ()),
                                      Glib::unwrap (second));
  }

  auto
  ContentFormats::match_gtype (
      const Glib::RefPtr<const ContentFormats>& second) const -> GType
  {
    return gdk_content_formats_match_gtype (
        const_cast<GdkContentFormats*> (gobj ()),
        Glib::unwrap (second));
  }

  auto
  ContentFormats::match_mime_type (
      const Glib::RefPtr<const ContentFormats>& second) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        gdk_content_formats_match_mime_type (
            const_cast<GdkContentFormats*> (gobj ()),
            Glib::unwrap (second)));
  }

} // namespace Gdk
