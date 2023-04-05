// SPDX-License-Identifier: LGPL-2.0-or-later

#include <libmm/pango/cairofontmapimpl.hxx>
#include <utility>

namespace pango
{
  CairoFontMapImpl::CairoFontMapImpl (PangoFontMap* castitem)
    : ObjectBase (nullptr),
      FontMap (castitem)
  {
  }

  CairoFontMapImpl::CairoFontMapImpl (CairoFontMapImpl&& src) noexcept
    : CairoFontMap (std::move (src)),
      FontMap (std::move (src))
  {
  }

  auto
  CairoFontMapImpl::operator= (CairoFontMapImpl&& src) noexcept -> CairoFontMapImpl&
  {
    CairoFontMap::operator= (std::move (src));
    FontMap::operator= (std::move (src));
    return *this;
  }

  CairoFontMapImpl::~CairoFontMapImpl () noexcept = default;
} // namespace pango
