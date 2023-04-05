// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_TOPLEVEL_H
#define _GDKMM_TOPLEVEL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/surface.hxx>
#include <libmm/gdk/texture.hxx>
#include <libmm/gdk/toplevellayout.hxx>
#include <libmm/gdk/toplevelsize.hxx>
#include <libmm/glib/interface.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkToplevelInterface GdkToplevelInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkToplevel = struct _GdkToplevel;
using GdkToplevelClass = struct _GdkToplevelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Toplevel_Class;
}
#endif

namespace gdk
{

  enum class SurfaceEdge
  {
    NORTH_WEST,
    NORTH,
    NORTH_EAST,
    WEST,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::SurfaceEdge>
    : public glib::Value_Enum<gdk::SurfaceEdge>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  enum class FullscreenMode
  {
    ON_CURRENT_MONITOR,
    ON_ALL_MONITORS
  };

} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::FullscreenMode>
    : public glib::Value_Enum<gdk::FullscreenMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Toplevel : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Toplevel;
    using CppClassType = Toplevel_Class;
    using BaseObjectType = GdkToplevel;
    using BaseClassType = GdkToplevelInterface;

    Toplevel (const Toplevel&) = delete;
    auto
    operator= (const Toplevel&) -> Toplevel& = delete;

  private:
    friend class Toplevel_Class;
    static CppClassType toplevel_class_;

#endif
  protected:
    Toplevel ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Toplevel (const glib::Interface_Class& interface_class);

  public:
    explicit Toplevel (GdkToplevel* castitem);

  protected:
#endif

  public:
    Toplevel (Toplevel&& src) noexcept;
    auto
    operator= (Toplevel&& src) noexcept -> Toplevel&;

    ~Toplevel () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkToplevel*
    {
      return reinterpret_cast<GdkToplevel*> (gobject_);
    }

    auto
    gobj () const -> const GdkToplevel*
    {
      return reinterpret_cast<GdkToplevel*> (gobject_);
    }

  private:
  public:
    enum class State
    {
      MINIMIZED = 1 << 0,
      MAXIMIZED = 1 << 1,
      STICKY = 1 << 2,
      FULLSCREEN = 1 << 3,
      ABOVE = 1 << 4,
      BELOW = 1 << 5,
      FOCUSED = 1 << 6,
      TILED = 1 << 7,
      TOP_TILED = 1 << 8,
      TOP_RESIZABLE = 1 << 9,
      RIGHT_TILED = 1 << 10,
      RIGHT_RESIZABLE = 1 << 11,
      BOTTOM_TILED = 1 << 12,
      BOTTOM_RESIZABLE = 1 << 13,
      LEFT_TILED = 1 << 14,
      LEFT_RESIZABLE = 1 << 15
    };

    auto
    present (const glib::RefPtr<ToplevelLayout>& layout) -> void;

    auto
    minimize () -> bool;

    auto
    lower () -> bool;

    auto
    focus (guint32 timestamp) -> void;

    auto
    get_state () const -> State;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_startup_id (const glib::ustring& startup_id) -> void;

    auto
    set_transient_for (const glib::RefPtr<Surface>& parent) -> void;

    auto
    set_modal (bool modal = true) -> void;

    auto
    set_icon_list (const std::vector<glib::RefPtr<Texture>>& surfaces) -> void;

    auto
    show_window_menu (const glib::RefPtr<Event>& event) -> bool;

    auto
    set_decorated (bool decorated = true) -> void;

    auto
    set_deletable (bool deletable = true) -> void;

    auto
    supports_edge_constraints () const -> bool;

    auto
    inhibit_system_shortcuts (const glib::RefPtr<Event>& event) -> void;

    auto
    restore_system_shortcuts () -> void;

    auto
    begin_resize (SurfaceEdge edge,
                  const glib::RefPtr<Device>& device,
                  int button,
                  double x,
                  double y,
                  guint32 timestamp) -> void;

    auto
    begin_move (const glib::RefPtr<Device>& device,
                int button,
                double x,
                double y,
                guint32 timestamp) -> void;

    auto
    signal_compute_size () -> glib::SignalProxy<void (ToplevelSize&)>;

    auto
    property_state () const -> glib::PropertyProxy_ReadOnly<State>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_startup_id () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_startup_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_transient_for () -> glib::PropertyProxy<glib::RefPtr<Surface>>;

    auto
    property_transient_for () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decorated () -> glib::PropertyProxy<bool>;

    auto
    property_decorated () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_deletable () -> glib::PropertyProxy<bool>;

    auto
    property_deletable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fullscreen_mode () -> glib::PropertyProxy<FullscreenMode>;

    auto
    property_fullscreen_mode () const
        -> glib::PropertyProxy_ReadOnly<FullscreenMode>;

    auto
    property_shortcuts_inhibited () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace gdk
{

  inline auto
  operator| (Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  {
    return static_cast<Toplevel::State> (static_cast<unsigned> (lhs) |
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  {
    return static_cast<Toplevel::State> (static_cast<unsigned> (lhs) &
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Toplevel::State lhs, Toplevel::State rhs) -> Toplevel::State
  {
    return static_cast<Toplevel::State> (static_cast<unsigned> (lhs) ^
                                         static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Toplevel::State flags) -> Toplevel::State
  {
    return static_cast<Toplevel::State> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  {
    return (lhs = static_cast<Toplevel::State> (static_cast<unsigned> (lhs) |
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  {
    return (lhs = static_cast<Toplevel::State> (static_cast<unsigned> (lhs) &
                                                static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Toplevel::State& lhs, Toplevel::State rhs) -> Toplevel::State&
  {
    return (lhs = static_cast<Toplevel::State> (static_cast<unsigned> (lhs) ^
                                                static_cast<unsigned> (rhs)));
  }
} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Toplevel::State>
    : public glib::Value_Flags<gdk::Toplevel::State>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkToplevel* object, bool take_copy = false) -> glib::RefPtr<gdk::Toplevel>;

} // namespace glib

#endif
