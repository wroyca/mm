

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gdk/timecoord.hxx>
#include <libmm-gdk/timecoord_p.hxx>

#include <gdk/gdk.h>
#include <utility>

namespace
{

  inline auto
  time_coord_copy (const GdkTimeCoord* gobject) -> GdkTimeCoord*
  {
    if (!gobject)
      return nullptr;

    GdkTimeCoord* new_obj = g_new (GdkTimeCoord, 1);
    *new_obj = *gobject;
    return new_obj;
  }

} // namespace

namespace Gdk
{

  TimeCoord::TimeCoord (GdkTimeCoord* gobject, const bool make_a_copy)
    : gobject_ (make_a_copy && gobject ? time_coord_copy (gobject) : gobject)
  {
  }

  TimeCoord::TimeCoord (const TimeCoord& other)
    : gobject_ (time_coord_copy (other.gobject_))
  {
  }

  auto
  TimeCoord::operator= (const TimeCoord& other) -> TimeCoord&
  {
    TimeCoord temp (other);
    std::swap (gobject_, temp.gobject_);
    return *this;
  }

  TimeCoord::TimeCoord (TimeCoord&& other) noexcept
    : gobject_ (std::move (other.gobject_))
  {
    other.gobject_ = nullptr;
  }

  auto
  TimeCoord::operator= (TimeCoord&& other) noexcept -> TimeCoord&
  {
    TimeCoord temp (std::move (other));
    std::swap (gobject_, temp.gobject_);
    return *this;
  }

  TimeCoord::~TimeCoord () noexcept
  {
    g_free (gobject_);
  }

  auto
  TimeCoord::get_value_at_axis (const guint index) const -> double
  {
    if (gobject_)
    {
      return gobject_->axes[index];
    }
    return 0;
  }

} // namespace Gdk

namespace
{
}

namespace Gdk
{

  auto
  TimeCoord::get_time () const -> guint32
  {
    return gobj ()->time;
  }

} // namespace Gdk
