// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/swipeable.hxx>
#include <libmm/adw/swipeable_p.hxx>

#include <adwaita.h>
#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (AdwSwipeable* object, bool take_copy) -> glib::RefPtr<adw::swipeable>
  {
    return glib::make_refptr_for_instance<adw::swipeable> (
        dynamic_cast<adw::swipeable*> (
            glib::wrap_auto_interface<adw::swipeable> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  swipeable_class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &swipeable_class::iface_init_function;

      gtype_ = adw_swipeable_get_type ();
    }

    return *this;
  }

  auto
  swipeable_class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  swipeable_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new swipeable ((AdwSwipeable*) (object));
  }

  swipeable::swipeable ()
    : glib::Interface (swipeable_class_.init ())
  {
  }

  swipeable::swipeable (AdwSwipeable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  swipeable::swipeable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  swipeable::swipeable (swipeable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  swipeable::operator= (swipeable&& src) noexcept -> swipeable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  swipeable::~swipeable () noexcept {}

  auto
  swipeable::add_interface (GType gtype_implementer) -> void
  {
    swipeable_class_.init ().add_interface (gtype_implementer);
  }

  swipeable::CppClassType swipeable::swipeable_class_;

  auto
  swipeable::get_type () -> GType
  {
    return swipeable_class_.init ().get_type ();
  }

  auto
  swipeable::get_base_type () -> GType
  {
    return adw_swipeable_get_type ();
  }

  auto
  swipeable::get_cancel_progress () const -> double
  {
    return adw_swipeable_get_cancel_progress (
        const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  swipeable::get_distance () const -> double
  {
    return adw_swipeable_get_distance (const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  swipeable::get_progress () const -> double
  {
    return adw_swipeable_get_progress (const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  swipeable::get_swipe_area (NavigationDirection navigation_direction,
                             bool is_drag,
                             gdk::Rectangle& rect) const -> void
  {
    adw_swipeable_get_swipe_area (
        const_cast<AdwSwipeable*> (gobj ()),
        static_cast<AdwNavigationDirection> (navigation_direction),
        static_cast<int> (is_drag),
        (rect).gobj ());
  }

} // namespace adw
