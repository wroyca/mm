// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TOPLEVELLAYOUT_H
#define _GDKMM_TOPLEVELLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/monitor.hxx>
#include <libmm/glib/refptr.hxx>

namespace gdk
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
    create () -> glib::RefPtr<ToplevelLayout>;

    auto
    copy () const -> glib::RefPtr<ToplevelLayout>;

    auto
    equal (const glib::RefPtr<const ToplevelLayout>& other) const -> bool;

    auto
    set_maximized (bool maximized = true) -> void;

    auto
    set_fullscreen (bool fullscreen = true,
                    const glib::RefPtr<Monitor>& monitor = {}) -> void;

    auto
    get_maximized (bool& maximized) const -> bool;

    auto
    get_fullscreen (bool& fullscreen) const -> bool;

    auto
    get_fullscreen_monitor () -> glib::RefPtr<Monitor>;

    auto
    get_fullscreen_monitor () const -> glib::RefPtr<const Monitor>;

    auto
    set_resizable (bool resizable = true) -> void;

    auto
    get_resizable () const -> bool;
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkToplevelLayout* object, bool take_copy = false) -> glib::RefPtr<gdk::ToplevelLayout>;

} // namespace glib

#endif
