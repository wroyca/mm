// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_FONTFAMILY_H
#define _PANGOMM_FONTFAMILY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-pango/fontface.hxx>
#include <pango/pango.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFontFamily = struct _PangoFontFamily;
using PangoFontFamilyClass = struct _PangoFontFamilyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class LIBMM_PANGO_SYMEXPORT FontFamily_Class;
}
#endif

namespace Pango
{

  class LIBMM_PANGO_SYMEXPORT FontFamily : public Glib::Object,
                                 public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FontFamily;
    using CppClassType = FontFamily_Class;
    using BaseObjectType = PangoFontFamily;
    using BaseClassType = PangoFontFamilyClass;

    FontFamily (const FontFamily&) = delete;
    auto
    operator= (const FontFamily&) -> FontFamily& = delete;

  private:
    friend class FontFamily_Class;
    static CppClassType fontfamily_class_;

  protected:
    explicit FontFamily (const Glib::ConstructParams& construct_params);
    explicit FontFamily (PangoFontFamily* castitem);

#endif

  public:
    FontFamily (FontFamily&& src) noexcept;
    auto
    operator= (FontFamily&& src) noexcept -> FontFamily&;

    ~FontFamily () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoFontFamily*
    {
      return reinterpret_cast<PangoFontFamily*> (gobject_);
    }

    auto
    gobj () const -> const PangoFontFamily*
    {
      return reinterpret_cast<PangoFontFamily*> (gobject_);
    }

    auto
    gobj_copy () -> PangoFontFamily*;

  private:
  public:
    auto
    list_faces () const -> std::vector<Glib::RefPtr<FontFace>>;

    auto
    get_name () const -> Glib::ustring;

    auto
    is_monospace () const -> bool;

    auto
    is_variable () const -> bool;

    auto
    get_face (const Glib::ustring& name = {}) -> Glib::RefPtr<FontFace>;

    auto
    get_face (const Glib::ustring& name = {}) const
        -> Glib::RefPtr<const FontFace>;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  LIBMM_PANGO_SYMEXPORT
  auto
  wrap (PangoFontFamily* object, bool take_copy = false) -> Glib::RefPtr<Pango::FontFamily>;
} // namespace Glib

#endif
