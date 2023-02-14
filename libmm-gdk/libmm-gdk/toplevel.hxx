
#ifndef _GDKMM_TOPLEVEL_H
#define _GDKMM_TOPLEVEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/surface.hxx>
#include <libmm-gdk/texture.hxx>
#include <libmm-gdk/toplevellayout.hxx>
#include <libmm-gdk/toplevelsize.hxx>
#include <libmm-glib/interface.hxx>
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
namespace Gdk
{
  class GDKMM_API Toplevel_Class;
}
#endif

namespace Gdk
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

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::SurfaceEdge>
    : public Glib::Value_Enum<Gdk::SurfaceEdge>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  enum class FullscreenMode
  {
    ON_CURRENT_MONITOR,
    ON_ALL_MONITORS
  };

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::FullscreenMode>
    : public Glib::Value_Enum<Gdk::FullscreenMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gdk
{

  class GDKMM_API Toplevel : public Glib::Interface
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

    explicit Toplevel (const Glib::Interface_Class& interface_class);

  public:
    explicit Toplevel (GdkToplevel* castitem);

  protected:
#endif

  public:
    Toplevel (Toplevel&& src) noexcept;
    auto
    operator= (Toplevel&& src) noexcept -> Toplevel&;

    ~Toplevel () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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

    void
    present (const Glib::RefPtr<ToplevelLayout>& layout);

    auto
    minimize () -> bool;

    auto
    lower () -> bool;

    void
    focus (guint32 timestamp);

    auto
    get_state () const -> State;

    void
    set_title (const Glib::ustring& title);

    void
    set_startup_id (const Glib::ustring& startup_id);

    void
    set_transient_for (const Glib::RefPtr<Surface>& parent);

    void
    set_modal (bool modal = true);

    void
    set_icon_list (const std::vector<Glib::RefPtr<Texture>>& surfaces);

    auto
    show_window_menu (const Glib::RefPtr<Event>& event) -> bool;

    void
    set_decorated (bool decorated = true);

    void
    set_deletable (bool deletable = true);

    auto
    supports_edge_constraints () const -> bool;

    void
    inhibit_system_shortcuts (const Glib::RefPtr<Event>& event);

    void
    restore_system_shortcuts ();

    void
    begin_resize (SurfaceEdge edge,
                  const Glib::RefPtr<Device>& device,
                  int button,
                  double x,
                  double y,
                  guint32 timestamp);

    void
    begin_move (const Glib::RefPtr<Device>& device,
                int button,
                double x,
                double y,
                guint32 timestamp);

    auto
    signal_compute_size () -> Glib::SignalProxy<void (ToplevelSize&)>;

    auto
    property_state () const -> Glib::PropertyProxy_ReadOnly<State>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_startup_id () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_startup_id () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_transient_for () -> Glib::PropertyProxy<Glib::RefPtr<Surface>>;

    auto
    property_transient_for () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decorated () -> Glib::PropertyProxy<bool>;

    auto
    property_decorated () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_deletable () -> Glib::PropertyProxy<bool>;

    auto
    property_deletable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fullscreen_mode () -> Glib::PropertyProxy<FullscreenMode>;

    auto
    property_fullscreen_mode () const
        -> Glib::PropertyProxy_ReadOnly<FullscreenMode>;

    auto
    property_shortcuts_inhibited () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Gdk
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
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::Toplevel::State>
    : public Glib::Value_Flags<Gdk::Toplevel::State>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkToplevel* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Toplevel>;

} // namespace Glib

#endif
