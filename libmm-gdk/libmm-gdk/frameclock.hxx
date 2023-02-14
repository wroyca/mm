
#ifndef _GDKMM_FRAMECLOCK_H
#define _GDKMM_FRAMECLOCK_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/frametimings.hxx>
#include <libmm-glib/object.hxx>

extern "C" typedef struct _GdkFrameClock GdkFrameClock;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkFrameClock = struct _GdkFrameClock;
using GdkFrameClockClass = struct _GdkFrameClockClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API FrameClock_Class;
}
#endif

namespace Gdk
{

  class GDKMM_API FrameClock : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FrameClock;
    using CppClassType = FrameClock_Class;
    using BaseObjectType = GdkFrameClock;
    using BaseClassType = GdkFrameClockClass;

    FrameClock (const FrameClock&) = delete;
    auto
    operator= (const FrameClock&) -> FrameClock& = delete;

  private:
    friend class FrameClock_Class;
    static CppClassType frameclock_class_;

  protected:
    explicit FrameClock (const Glib::ConstructParams& construct_params);
    explicit FrameClock (GdkFrameClock* castitem);

#endif

  public:
    FrameClock (FrameClock&& src) noexcept;
    auto
    operator= (FrameClock&& src) noexcept -> FrameClock&;

    ~FrameClock () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkFrameClock*
    {
      return reinterpret_cast<GdkFrameClock*> (gobject_);
    }

    auto
    gobj () const -> const GdkFrameClock*
    {
      return reinterpret_cast<GdkFrameClock*> (gobject_);
    }

    auto
    gobj_copy () -> GdkFrameClock*;

  private:
  public:
    enum class Phase
    {
      NONE = 0x0,
      FLUSH_EVENTS = 1 << 0,
      BEFORE_PAINT = 1 << 1,
      UPDATE = 1 << 2,
      LAYOUT = 1 << 3,
      PAINT = 1 << 4,
      RESUME_EVENTS = 1 << 5,
      AFTER_PAINT = 1 << 6
    };

    auto
    get_frame_time () const -> gint64;

    void
    request_phase (Phase phase);

    void
    begin_updating ();

    void
    end_updating ();

    auto
    get_frame_counter () const -> gint64;

    auto
    get_history_start () const -> gint64;

    auto
    get_timings (gint64 frame_counter) -> Glib::RefPtr<FrameTimings>;

    auto
    get_timings (gint64 frame_counter) const
        -> Glib::RefPtr<const FrameTimings>;

    auto
    get_current_timings () -> Glib::RefPtr<FrameTimings>;

    auto
    get_current_timings () const -> Glib::RefPtr<const FrameTimings>;

    void
    get_refresh_info (gint64 base_time,
                      gint64& refresh_interval_return,
                      gint64& presentation_time_return) const;

    auto
    get_fps () const -> double;

    auto
    signal_update () -> Glib::SignalProxy<void ()>;

    auto
    signal_layout () -> Glib::SignalProxy<void ()>;

    auto
    signal_paint () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Gdk
{

  inline auto
  operator| (FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  {
    return static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) |
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  {
    return static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) &
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (FrameClock::Phase lhs, FrameClock::Phase rhs) -> FrameClock::Phase
  {
    return static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) ^
                                           static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(FrameClock::Phase flags) -> FrameClock::Phase
  {
    return static_cast<FrameClock::Phase> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  {
    return (lhs = static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) |
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  {
    return (lhs = static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) &
                                                  static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (FrameClock::Phase& lhs, FrameClock::Phase rhs) -> FrameClock::Phase&
  {
    return (lhs = static_cast<FrameClock::Phase> (static_cast<unsigned> (lhs) ^
                                                  static_cast<unsigned> (rhs)));
  }
} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GDKMM_API Value<Gdk::FrameClock::Phase>
    : public Glib::Value_Flags<Gdk::FrameClock::Phase>
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
  wrap (GdkFrameClock* object, bool take_copy = false) -> Glib::RefPtr<Gdk::FrameClock>;
} // namespace Glib

#endif
