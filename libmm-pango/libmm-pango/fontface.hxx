// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTFACE_H
#define _PANGOMM_FONTFACE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-pango/fontdescription.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontFace = struct _PangoFontFace;
using PangoFontFaceClass = struct _PangoFontFaceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class LIBMM_PANGO_SYMEXPORT FontFace_Class;
}
#endif

namespace Pango
{
  class LIBMM_PANGO_SYMEXPORT FontFamily;

  class LIBMM_PANGO_SYMEXPORT FontFace : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FontFace;
    using CppClassType = FontFace_Class;
    using BaseObjectType = PangoFontFace;
    using BaseClassType = PangoFontFaceClass;

    FontFace (const FontFace&) = delete;
    auto
    operator= (const FontFace&) -> FontFace& = delete;

  private:
    friend class FontFace_Class;
    static CppClassType fontface_class_;

  protected:
    explicit FontFace (const Glib::ConstructParams& construct_params);
    explicit FontFace (PangoFontFace* castitem);

#endif

  public:
    FontFace (FontFace&& src) noexcept;
    auto
    operator= (FontFace&& src) noexcept -> FontFace&;

    ~FontFace () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoFontFace*
    {
      return reinterpret_cast<PangoFontFace*> (gobject_);
    }

    auto
    gobj () const -> const PangoFontFace*
    {
      return reinterpret_cast<PangoFontFace*> (gobject_);
    }

    auto
    gobj_copy () -> PangoFontFace*;

  private:
  public:
    auto
    describe () const -> FontDescription;

    auto
    get_name () const -> Glib::ustring;

    auto
    list_sizes () const -> std::vector<int>;

    auto
    is_synthesized () const -> bool;

    auto
    get_family () -> Glib::RefPtr<FontFamily>;

    auto
    get_family () const -> Glib::RefPtr<const FontFamily>;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoFontFace* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontFace>;
} // namespace Glib

#endif
