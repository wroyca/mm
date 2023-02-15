// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGOMM_CAIROFONTMAP_H
#define _PANGOMM_CAIROFONTMAP_H

#include <libmm-pango/mm-pangoconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-cairo/enums.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-pango/fontmap.hxx>
#include <pango/pangocairo.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _PangoCairoFontMapIface PangoCairoFontMapIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoCairoFontMap = struct _PangoCairoFontMap;
using PangoCairoFontMapClass = struct _PangoCairoFontMapClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{
  class PANGOMM_API CairoFontMap_Class;
}
#endif

namespace Pango
{

  class PANGOMM_API CairoFontMap : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CairoFontMap;
    using CppClassType = CairoFontMap_Class;
    using BaseObjectType = PangoCairoFontMap;
    using BaseClassType = PangoCairoFontMapIface;

    CairoFontMap (const CairoFontMap&) = delete;
    auto
    operator= (const CairoFontMap&) -> CairoFontMap& = delete;

  private:
    friend class CairoFontMap_Class;
    static CppClassType cairofontmap_class_;

#endif
  protected:
    CairoFontMap ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit CairoFontMap (const Glib::Interface_Class& interface_class);

  public:
    explicit CairoFontMap (PangoCairoFontMap* castitem);

  protected:
#endif

  public:
    CairoFontMap (CairoFontMap&& src) noexcept;
    auto
    operator= (CairoFontMap&& src) noexcept -> CairoFontMap&;

    ~CairoFontMap () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> PangoCairoFontMap*
    {
      return reinterpret_cast<PangoCairoFontMap*> (gobject_);
    }

    auto
    gobj () const -> const PangoCairoFontMap*
    {
      return reinterpret_cast<PangoCairoFontMap*> (gobject_);
    }

  private:
  public:
    static auto
    get_default () -> Glib::RefPtr<FontMap>;

    auto
    set_default () -> void;

    auto
    get_font_type () const -> Cairo::FontType;

    auto
    set_resolution (double dpi) -> void;

    auto
    get_resolution () const -> double;

  public:
  public:
  protected:
  };

} // namespace Pango

namespace Glib
{

  PANGOMM_API
  auto
  wrap (PangoCairoFontMap* object, bool take_copy = false) -> Glib::RefPtr<Pango::CairoFontMap>;

} // namespace Glib

#endif
