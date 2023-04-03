// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DISPLAYMANAGER_H
#define _GDKMM_DISPLAYMANAGER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gdk/display.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDisplayManager = struct _GdkDisplayManager;
using GdkDisplayManagerClass = struct _GdkDisplayManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT DisplayManager_Class;
}
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT DisplayManager : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DisplayManager;
    using CppClassType = DisplayManager_Class;
    using BaseObjectType = GdkDisplayManager;
    using BaseClassType = GdkDisplayManagerClass;

    DisplayManager (const DisplayManager&) = delete;
    auto
    operator= (const DisplayManager&) -> DisplayManager& = delete;

  private:
    friend class DisplayManager_Class;
    static CppClassType displaymanager_class_;

  protected:
    explicit DisplayManager (const Glib::ConstructParams& construct_params);
    explicit DisplayManager (GdkDisplayManager* castitem);

#endif

  public:
    DisplayManager (DisplayManager&& src) noexcept;
    auto
    operator= (DisplayManager&& src) noexcept -> DisplayManager&;

    ~DisplayManager () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDisplayManager*
    {
      return reinterpret_cast<GdkDisplayManager*> (gobject_);
    }

    auto
    gobj () const -> const GdkDisplayManager*
    {
      return reinterpret_cast<GdkDisplayManager*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDisplayManager*;

  private:
  protected:
  public:
    static auto
    get () -> Glib::RefPtr<DisplayManager>;

    auto
    get_default_display () -> Glib::RefPtr<Display>;

    auto
    get_default_display () const -> Glib::RefPtr<const Display>;

    auto
    set_default_display (const Glib::RefPtr<Display>& display) -> void;

    auto
    list_displays () -> std::vector<Glib::RefPtr<Display>>;

    auto
    open_display (const Glib::ustring& name) -> Glib::RefPtr<Display>;

    auto
    property_default_display () -> Glib::PropertyProxy<Glib::RefPtr<Display>>;

    auto
    property_default_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    signal_display_opened ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Display>&)>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDisplayManager* object, bool take_copy = false) -> Glib::RefPtr<Gdk::DisplayManager>;
} // namespace Glib

#endif
