// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TOPLEVELSIZE_H
#define _GDKMM_TOPLEVELSIZE_H

#include <libmm-gdk/mm-gdkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk/gdk.h>

namespace Gdk
{

  class GDKMM_API ToplevelSize
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ToplevelSize;
    using BaseObjectType = GdkToplevelSize;
#endif

  private:
  public:
    explicit ToplevelSize (GdkToplevelSize* gobject);

    ToplevelSize (const ToplevelSize& other) = delete;
    auto
    operator= (const ToplevelSize& other) -> ToplevelSize& = delete;

    ToplevelSize (ToplevelSize&& other) noexcept;
    auto
    operator= (ToplevelSize&& other) noexcept -> ToplevelSize&;

    ~ToplevelSize () noexcept;

    explicit operator bool () const;

    auto
    gobj () -> GdkToplevelSize*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GdkToplevelSize*
    {
      return gobject_;
    }

    auto
    get_bounds (int& bounds_width, int& bounds_height) const -> void;

    auto
    set_size (int width, int height) -> void;

    auto
    set_min_size (int min_width, int min_height) -> void;

    auto
    set_shadow_width (int left, int right, int top, int bottom) -> void;

  protected:
    GdkToplevelSize* gobject_;
  };

} // namespace Gdk

#endif
