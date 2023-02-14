
#ifndef _GDKMM_CONTENTFORMATSBUILDER_H
#define _GDKMM_CONTENTFORMATSBUILDER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentformats.hxx>

namespace Gdk
{

  class GDKMM_API ContentFormatsBuilder final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ContentFormatsBuilder;
    using BaseObjectType = GdkContentFormatsBuilder;
#endif

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

  private:
  public:
    static auto
    create () -> Glib::RefPtr<ContentFormatsBuilder>;

    void
    add_formats (const Glib::RefPtr<const ContentFormats>& formats);

    void
    add_mime_type (const Glib::ustring& mime_type);

    void
    add_gtype (GType gtype);

    auto
    to_formats () -> Glib::RefPtr<ContentFormats>;
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkContentFormatsBuilder* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ContentFormatsBuilder>;

} // namespace Glib

#endif
