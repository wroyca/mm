// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BORDER_H
#define _GTKMM_BORDER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkBorder GtkBorder;
}
#endif

namespace Gtk
{

  class GTKMM_API Border
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Border;
    using BaseObjectType = GtkBorder;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    Border ();

    explicit Border (GtkBorder* gobject, bool make_a_copy = true);

    Border (const Border& other);
    auto
    operator= (const Border& other) -> Border&;

    Border (Border&& other) noexcept;
    auto
    operator= (Border&& other) noexcept -> Border&;

    ~Border () noexcept;

    auto
    swap (Border& other) noexcept -> void;

    auto
    gobj () -> GtkBorder*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GtkBorder*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GtkBorder*;

  protected:
    GtkBorder* gobject_;

  private:
  public:
    auto
    get_left () const -> int;

    auto
    set_left (const int& value) -> void;

    auto
    get_right () const -> int;

    auto
    set_right (const int& value) -> void;

    auto
    get_top () const -> int;

    auto
    set_top (const int& value) -> void;

    auto
    get_bottom () const -> int;

    auto
    set_bottom (const int& value) -> void;
  };

} // namespace Gtk

namespace Gtk
{

  inline auto
  swap (Border& lhs, Border& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkBorder* object, bool take_copy = false) -> Gtk::Border;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GTKMM_API Value<Gtk::Border> : public Glib::Value_Boxed<Gtk::Border>
  {
  };
#endif

} // namespace Glib

#endif
