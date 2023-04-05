// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CONTENTFORMATSBUILDER_H
#define _GDKMM_CONTENTFORMATSBUILDER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentformats.hxx>

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT ContentFormatsBuilder final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ContentFormatsBuilder;
    using BaseObjectType = GdkContentFormatsBuilder;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkContentFormatsBuilder*;

    auto
    gobj () const -> const GdkContentFormatsBuilder*;

    auto
    gobj_copy () const -> GdkContentFormatsBuilder*;

    ContentFormatsBuilder () = delete;

    ContentFormatsBuilder (const ContentFormatsBuilder&) = delete;
    auto
    operator= (const ContentFormatsBuilder&) -> ContentFormatsBuilder& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create () -> glib::RefPtr<ContentFormatsBuilder>;

    auto
    add_formats (const glib::RefPtr<const ContentFormats>& formats) -> void;

    auto
    add_mime_type (const glib::ustring& mime_type) -> void;

    auto
    add_gtype (GType gtype) -> void;

    auto
    to_formats () -> glib::RefPtr<ContentFormats>;
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkContentFormatsBuilder* object, bool take_copy = false) -> glib::RefPtr<gdk::ContentFormatsBuilder>;

} // namespace glib

#endif
