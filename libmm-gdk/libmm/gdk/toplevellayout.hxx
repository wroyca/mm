// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TOPLEVELLAYOUT_H
#define _GDKMM_TOPLEVELLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/monitor.hxx>
#include <libmm/glib/refptr.hxx>

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT ToplevelLayout final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ToplevelLayout;
    using BaseObjectType = GdkToplevelLayout;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GdkToplevelLayout*;

    auto
    gobj () const -> const GdkToplevelLayout*;

    auto
    gobj_copy () const -> GdkToplevelLayout*;

    ToplevelLayout () = delete;

    ToplevelLayout (const ToplevelLayout&) = delete;
    auto
    operator= (const ToplevelLayout&) -> ToplevelLayout& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create () -> Glib::RefPtr<ToplevelLayout>;

    auto
    copy () const -> Glib::RefPtr<ToplevelLayout>;

    auto
    equal (const Glib::RefPtr<const ToplevelLayout>& other) const -> bool;

    auto
    set_maximized (bool maximized = true) -> void;

    auto
    set_fullscreen (bool fullscreen = true,
                    const Glib::RefPtr<Monitor>& monitor = {}) -> void;

    auto
    get_maximized (bool& maximized) const -> bool;

    auto
    get_fullscreen (bool& fullscreen) const -> bool;

    auto
    get_fullscreen_monitor () -> Glib::RefPtr<Monitor>;

    auto
    get_fullscreen_monitor () const -> Glib::RefPtr<const Monitor>;

    auto
    set_resizable (bool resizable = true) -> void;

    auto
    get_resizable () const -> bool;
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkToplevelLayout* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ToplevelLayout>;

} // namespace Glib

#endif
