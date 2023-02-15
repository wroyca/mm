// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTMAP_H
#define _PANGOMM_FONTMAP_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-pango/font.hxx>
#include <libmm-pango/fontfamily.hxx>
#include <libmm-pango/fontset.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontMap = struct _PangoFontMap;
using PangoFontMapClass = struct _PangoFontMapClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class LIBMM_PANGO_SYMEXPORT FontMap_Class;
}
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT Context;

  class LIBMM_PANGO_SYMEXPORT FontMap : public Glib::Object,
                              public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FontMap;
    using CppClassType = FontMap_Class;
    using BaseObjectType = PangoFontMap;
    using BaseClassType = PangoFontMapClass;

    FontMap (const FontMap&) = delete;
    auto
    operator= (const FontMap&) -> FontMap& = delete;

  private:
    friend class FontMap_Class;
    static CppClassType fontmap_class_;

  protected:
    explicit FontMap (const Glib::ConstructParams& construct_params);
    explicit FontMap (PangoFontMap* castitem);

#endif

  public:
    FontMap (FontMap&& src) noexcept;
    auto
    operator= (FontMap&& src) noexcept -> FontMap&;

    ~FontMap () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoFontMap*
    {
      return reinterpret_cast<PangoFontMap*> (gobject_);
    }

    auto
    gobj () const -> const PangoFontMap*
    {
      return reinterpret_cast<PangoFontMap*> (gobject_);
    }

    auto
    gobj_copy () -> PangoFontMap*;

  private:
  public:
    auto
    load_font (const Glib::RefPtr<Context>& context,
               const FontDescription& desc) const -> Glib::RefPtr<Font>;

    auto
    load_fontset (const Glib::RefPtr<Context>& context,
                  const FontDescription& desc,
                  const Language& language) const -> Glib::RefPtr<Fontset>;

    auto
    create_context () -> Glib::RefPtr<Context>;

    auto
    list_families () const -> std::vector<Glib::RefPtr<FontFamily>>;

    auto
    get_serial () const -> guint;

    auto
    get_family (const Glib::ustring& name) -> Glib::RefPtr<FontFamily>;

    auto
    get_family (const Glib::ustring& name) const
        -> Glib::RefPtr<const FontFamily>;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoFontMap* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontMap>;
} // namespace Glib

#endif
