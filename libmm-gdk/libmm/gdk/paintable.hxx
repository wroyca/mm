// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PAINTABLE_H
#define _GDKMM_PAINTABLE_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GdkPaintableInterface GdkPaintableInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPaintable = struct _GdkPaintable;
using GdkPaintableClass = struct _GdkPaintableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Paintable_Class;
}
#endif

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Snapshot;

  class LIBMM_GDK_SYMEXPORT Paintable : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Paintable;
    using CppClassType = Paintable_Class;
    using BaseObjectType = GdkPaintable;
    using BaseClassType = GdkPaintableInterface;

    Paintable (const Paintable&) = delete;
    auto
    operator= (const Paintable&) -> Paintable& = delete;

  private:
    friend class Paintable_Class;
    static CppClassType paintable_class_;

#endif
  protected:
    Paintable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Paintable (const glib::Interface_Class& interface_class);

  public:
    explicit Paintable (GdkPaintable* castitem);

  protected:
#endif

  public:
    Paintable (Paintable&& src) noexcept;
    auto
    operator= (Paintable&& src) noexcept -> Paintable&;

    ~Paintable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPaintable*
    {
      return reinterpret_cast<GdkPaintable*> (gobject_);
    }

    auto
    gobj () const -> const GdkPaintable*
    {
      return reinterpret_cast<GdkPaintable*> (gobject_);
    }

  private:
  public:
    enum class Flags
    {
      STATIC_SIZE = 1 << 0,
      STATIC_CONTENTS = 1 << 1
    };

    auto
    snapshot (const glib::RefPtr<gdk::Snapshot>& snapshot,
              double width,
              double height) -> void;

    auto
    get_current_image () const -> glib::RefPtr<const Paintable>;

    auto
    get_flags () const -> Flags;

    auto
    get_intrinsic_width () const -> int;

    auto
    get_intrinsic_height () const -> int;

    auto
    get_intrinsic_aspect_ratio () const -> double;

    auto
    compute_concrete_size (double specified_width,
                           double specified_height,
                           double default_width,
                           double default_height,
                           double& concrete_width,
                           double& concrete_height) const -> void;

    auto
    invalidate_contents () -> void;

    auto
    invalidate_size () -> void;

    auto
    signal_invalidate_contents () -> glib::SignalProxy<void ()>;

    auto
    signal_invalidate_size () -> glib::SignalProxy<void ()>;

  protected:
    virtual auto
    snapshot_vfunc (const glib::RefPtr<gdk::Snapshot>& snapshot,
                    double width,
                    double height) -> void;

    virtual auto
    get_current_image_vfunc () const -> glib::RefPtr<Paintable>;

    virtual auto
    get_flags_vfunc () const -> Flags;

    virtual auto
    get_intrinsic_width_vfunc () const -> int;

    virtual auto
    get_intrinsic_height_vfunc () const -> int;

    virtual auto
    get_intrinsic_aspect_ratio_vfunc () const -> double;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace gdk
{

  inline auto
  operator| (Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  {
    return static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  {
    return static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Paintable::Flags lhs, Paintable::Flags rhs) -> Paintable::Flags
  {
    return static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Paintable::Flags flags) -> Paintable::Flags
  {
    return static_cast<Paintable::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  {
    return (lhs = static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  {
    return (lhs = static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Paintable::Flags& lhs, Paintable::Flags rhs) -> Paintable::Flags&
  {
    return (lhs = static_cast<Paintable::Flags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }
} // namespace gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GDK_SYMEXPORT Value<gdk::Paintable::Flags>
    : public glib::Value_Flags<gdk::Paintable::Flags>
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
  wrap (GdkPaintable* object, bool take_copy = false) -> glib::RefPtr<gdk::Paintable>;

} // namespace glib

#endif
