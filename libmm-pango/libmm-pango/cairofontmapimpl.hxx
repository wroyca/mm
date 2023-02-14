// SPDX-License-Identifier: LGPL-2.0-or-later

#ifndef _PANGO_CAIROFONTMAPIMPL_H
#define _PANGO_CAIROFONTMAPIMPL_H

#include <libmm-pango/cairofontmap.hxx>
#include <libmm-pango/fontmap.hxx>
#include <libmm-pango/mm-pangoconfig.hxx>

namespace Pango
{

  class PANGOMM_API CairoFontMapImpl : public CairoFontMap,
                                       public FontMap
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  protected:
    explicit CairoFontMapImpl (PangoFontMap* castitem);
    friend class FontMap_Class;

    CairoFontMapImpl (const CairoFontMapImpl&) = delete;
    auto
    operator= (const CairoFontMapImpl&) -> CairoFontMapImpl& = delete;
#endif

  public:
    CairoFontMapImpl (CairoFontMapImpl&& src) noexcept;
    auto
    operator= (CairoFontMapImpl&& src) noexcept -> CairoFontMapImpl&;

    ~CairoFontMapImpl () noexcept override;
  };

} // namespace Pango

#endif
