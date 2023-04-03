// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONTENTFORMATS_H
#define _GDKMM_CONTENTFORMATS_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>
#include <libmm/glib/refptr.hxx>
#include <libmm/glib/ustring.hxx>
#include <libmm/glib/value.hxx>
#include <vector>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT ContentFormats final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ContentFormats;
    using BaseObjectType = GdkContentFormats;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkContentFormats*;

    auto
    gobj () const -> const GdkContentFormats*;

    auto
    gobj_copy () const -> GdkContentFormats*;

    ContentFormats () = delete;

    ContentFormats (const ContentFormats&) = delete;
    auto
    operator= (const ContentFormats&) -> ContentFormats& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (const std::vector<Glib::ustring>& mime_types = {})
        -> Glib::RefPtr<ContentFormats>;

    static auto
    create (const Glib::ustring& mime_type) -> Glib::RefPtr<ContentFormats>;

    static auto
    create (GType type) -> Glib::RefPtr<ContentFormats>;

    static auto
    parse (const Glib::ustring& string) -> Glib::RefPtr<ContentFormats>;

    auto
    to_string () const -> Glib::ustring;

    auto
    get_gtypes () const -> std::vector<GType>;

    auto
    get_mime_types () const -> std::vector<Glib::ustring>;

    auto
    contain_gtype (GType type) const -> bool;

    auto
    contain_mime_type (const Glib::ustring& mime_type) const -> bool;

    auto
    join (const Glib::RefPtr<const ContentFormats>& second) const
        -> Glib::RefPtr<ContentFormats>;

    auto
    match (const Glib::RefPtr<const ContentFormats>& second) const -> bool;

    auto
    match_gtype (const Glib::RefPtr<const ContentFormats>& second) const
        -> GType;

    auto
    match_mime_type (const Glib::RefPtr<const ContentFormats>& second) const
        -> Glib::ustring;
  };

} // namespace Gdk

namespace Glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<Glib::RefPtr<Gdk::ContentFormats>>
    : public ValueBase_Boxed
  {
  public:
    typedef Glib::RefPtr<Gdk::ContentFormats> CppType;
    typedef GdkContentFormats* CType;

    static auto
    value_type () -> GType;

    auto
    set (const CppType& data) -> void;
    auto
    get () const -> CppType;
  };

} // namespace Glib

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkContentFormats* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentFormats>;

} // namespace Glib

#endif
