// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BOX_H
#define _GTKMM_BOX_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBox = struct _GtkBox;
using GtkBoxClass = struct _GtkBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Box_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Box : public Widget,
                        public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Box CppObjectType;
    typedef Box_Class CppClassType;
    typedef GtkBox BaseObjectType;
    typedef GtkBoxClass BaseClassType;
#endif

    Box (Box&& src) noexcept;
    auto
    operator= (Box&& src) noexcept -> Box&;

    Box (const Box&) = delete;
    auto
    operator= (const Box&) -> Box& = delete;

    ~Box () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Box_Class;
    static CppClassType box_class_;

  protected:
    explicit Box (const Glib::ConstructParams& construct_params);
    explicit Box (GtkBox* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBox*
    {
      return reinterpret_cast<GtkBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkBox*
    {
      return reinterpret_cast<GtkBox*> (gobject_);
    }

  private:
  public:
    explicit Box (Orientation orientation = Orientation::HORIZONTAL,
                  int spacing = 0);

    auto
    set_homogeneous (bool homogeneous = true) -> void;

    auto
    get_homogeneous () const -> bool;

    auto
    set_spacing (int spacing) -> void;

    auto
    get_spacing () const -> int;

    auto
    set_baseline_position (BaselinePosition position) -> void;

    auto
    get_baseline_position () const -> BaselinePosition;

    auto
    append (Gtk::Widget& child) -> void;

    auto
    prepend (Gtk::Widget& child) -> void;

    auto
    remove (Gtk::Widget& child) -> void;

    auto
    insert_child_after (Widget& child, const Widget& sibling) -> void;

    auto
    insert_child_at_start (Widget& child) -> void;

    auto
    reorder_child_after (Widget& child, const Widget& sibling) -> void;

    auto
    reorder_child_at_start (Widget& child) -> void;

    auto
    property_spacing () -> Glib::PropertyProxy<int>;

    auto
    property_spacing () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_homogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_homogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_baseline_position () -> Glib::PropertyProxy<BaselinePosition>;

    auto
    property_baseline_position () const
        -> Glib::PropertyProxy_ReadOnly<BaselinePosition>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkBox* object, bool take_copy = false) -> Gtk::Box*;
} // namespace Glib

#endif
