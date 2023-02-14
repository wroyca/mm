
#ifndef _GDKMM_TOPLEVELLAYOUT_H
#define _GDKMM_TOPLEVELLAYOUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/monitor.hxx>
#include <libmm-glib/refptr.hxx>

namespace Gdk
{

  class GDKMM_API ToplevelLayout final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ToplevelLayout;
    using BaseObjectType = GdkToplevelLayout;
#endif

    void
    reference () const;

    void
    unreference () const;

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
    void
    operator delete (void*, std::size_t);

  private:
  public:
    static auto
    create () -> Glib::RefPtr<ToplevelLayout>;

    auto
    copy () const -> Glib::RefPtr<ToplevelLayout>;

    auto
    equal (const Glib::RefPtr<const ToplevelLayout>& other) const -> bool;

    void
    set_maximized (bool maximized = true);

    void
    set_fullscreen (bool fullscreen = true,
                    const Glib::RefPtr<Monitor>& monitor = {});

    auto
    get_maximized (bool& maximized) const -> bool;

    auto
    get_fullscreen (bool& fullscreen) const -> bool;

    auto
    get_fullscreen_monitor () -> Glib::RefPtr<Monitor>;

    auto
    get_fullscreen_monitor () const -> Glib::RefPtr<const Monitor>;

    void
    set_resizable (bool resizable = true);

    auto
    get_resizable () const -> bool;
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkToplevelLayout* object, bool take_copy = false) -> Glib::RefPtr<Gdk::ToplevelLayout>;

} // namespace Glib

#endif
