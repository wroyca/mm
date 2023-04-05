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
  wrap (AdwSwipeable* object, bool take_copy) -> glib::RefPtr<adw::Swipeable>
  {
    return glib::make_refptr_for_instance<adw::Swipeable> (
        dynamic_cast<adw::Swipeable*> (
            glib::wrap_auto_interface<adw::Swipeable> ((GObject*) (object),
                                                       take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  Swipeable_Class::init () -> const glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Swipeable_Class::iface_init_function;

      gtype_ = adw_swipeable_get_type ();
    }

    return *this;
  }

  auto
  Swipeable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Swipeable_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Swipeable ((AdwSwipeable*) (object));
  }

  Swipeable::Swipeable ()
    : glib::Interface (swipeable_class_.init ())
  {
  }

  Swipeable::Swipeable (AdwSwipeable* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Swipeable::Swipeable (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Swipeable::Swipeable (Swipeable&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Swipeable::operator= (Swipeable&& src) noexcept -> Swipeable&
  {
    glib::Interface::operator= (std::move (src));
    return *this;
  }

  Swipeable::~Swipeable () noexcept {}

  auto
  Swipeable::add_interface (GType gtype_implementer) -> void
  {
    swipeable_class_.init ().add_interface (gtype_implementer);
  }

  Swipeable::CppClassType Swipeable::swipeable_class_;

  auto
  Swipeable::get_type () -> GType
  {
    return swipeable_class_.init ().get_type ();
  }

  auto
  Swipeable::get_base_type () -> GType
  {
    return adw_swipeable_get_type ();
  }

  auto
  Swipeable::get_cancel_progress () const -> double
  {
    return adw_swipeable_get_cancel_progress (
        const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  Swipeable::get_distance () const -> double
  {
    return adw_swipeable_get_distance (const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  Swipeable::get_progress () const -> double
  {
    return adw_swipeable_get_progress (const_cast<AdwSwipeable*> (gobj ()));
  }

  auto
  Swipeable::get_swipe_area (NavigationDirection navigation_direction,
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
