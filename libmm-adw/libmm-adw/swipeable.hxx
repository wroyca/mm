// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPEABLE_H
#define _LIBADWAITAMM_SWIPEABLE_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>
#include <libmm-adw/navigationdirection.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwSwipeable = struct _AdwSwipeable;
using AdwSwipeableClass = struct _AdwSwipeableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class Swipeable_Class;
}
#endif

namespace Adw
{

  class Swipeable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Swipeable;
    using CppClassType = Swipeable_Class;
    using BaseObjectType = AdwSwipeable;
    using BaseClassType = AdwSwipeableInterface;

    Swipeable (const Swipeable&) = delete;
    auto
    operator= (const Swipeable&) -> Swipeable& = delete;

  private:
    friend class Swipeable_Class;
    static CppClassType swipeable_class_;

#endif
  protected:
    Swipeable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Swipeable (const Glib::Interface_Class& interface_class);

  public:
    explicit Swipeable (AdwSwipeable* castitem);

  protected:
#endif

  public:
    Swipeable (Swipeable&& src) noexcept;
    auto
    operator= (Swipeable&& src) noexcept -> Swipeable&;

    ~Swipeable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSwipeable*
    {
      return reinterpret_cast<AdwSwipeable*> (gobject_);
    }

    auto
    gobj () const -> const AdwSwipeable*
    {
      return reinterpret_cast<AdwSwipeable*> (gobject_);
    }

  private:
  public:
    auto
    get_cancel_progress () const -> double;

    auto
    get_distance () const -> double;

    auto
    get_progress () const -> double;

    auto
    get_snap_points () const -> std::vector<double>
    {
      int snap_points;
      double* p = adw_swipeable_get_snap_points (
          const_cast<AdwSwipeable*> (gobj ()),
          &snap_points);
      if (p)
        return Glib::ArrayHandler<double>::array_to_vector (
            p,
            (size_t) snap_points,
            Glib::OWNERSHIP_DEEP);
      else
        return {};
    }

    auto
    get_swipe_area (NavigationDirection navigation_direction,
                    bool is_drag,
                    Gdk::Rectangle& rect) const -> void;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwSwipeable* object, bool take_copy = false) -> Glib::RefPtr<Adw::Swipeable>;

}

#endif
