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
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT DisplayManager_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT DisplayManager : public glib::Object
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
    explicit DisplayManager (const glib::ConstructParams& construct_params);
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
    get () -> glib::RefPtr<DisplayManager>;

    auto
    get_default_display () -> glib::RefPtr<Display>;

    auto
    get_default_display () const -> glib::RefPtr<const Display>;

    auto
    set_default_display (const glib::RefPtr<Display>& display) -> void;

    auto
    list_displays () -> std::vector<glib::RefPtr<Display>>;

    auto
    open_display (const glib::ustring& name) -> glib::RefPtr<Display>;

    auto
    property_default_display () -> glib::PropertyProxy<glib::RefPtr<Display>>;

    auto
    property_default_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    signal_display_opened ()
        -> glib::SignalProxy<void (const glib::RefPtr<Display>&)>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDisplayManager* object, bool take_copy = false) -> glib::RefPtr<gdk::DisplayManager>;
} // namespace glib

#endif
