// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SWIPETRACKER_P_H
#define _LIBADWAITAMM_SWIPETRACKER_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT swipe_tracker_class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = swipe_tracker;
    using BaseObjectType = AdwSwipeTracker;
    using CppClassParent = glib::Object_Class;

    friend class swipe_tracker;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
