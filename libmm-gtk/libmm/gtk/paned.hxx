// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PANED_H
#define _GTKMM_PANED_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPaned = struct _GtkPaned;
using GtkPanedClass = struct _GtkPanedClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Paned_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Paned : public Widget,
                          public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Paned CppObjectType;
    typedef Paned_Class CppClassType;
    typedef GtkPaned BaseObjectType;
    typedef GtkPanedClass BaseClassType;
#endif

    Paned (Paned&& src) noexcept;
    auto
    operator= (Paned&& src) noexcept -> Paned&;

    Paned (const Paned&) = delete;
    auto
    operator= (const Paned&) -> Paned& = delete;

    ~Paned () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Paned_Class;
    static CppClassType paned_class_;

  protected:
    explicit Paned (const glib::ConstructParams& construct_params);
    explicit Paned (GtkPaned* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPaned*
    {
      return reinterpret_cast<GtkPaned*> (gobject_);
    }

    auto
    gobj () const -> const GtkPaned*
    {
      return reinterpret_cast<GtkPaned*> (gobject_);
    }

  private:
  public:
    explicit Paned (Orientation orientation = Orientation::HORIZONTAL);

    auto
    set_start_child (Widget& child) -> void;

    auto
    get_start_child () -> Widget*;

    auto
    get_start_child () const -> const Widget*;

    auto
    set_resize_start_child (bool resize = true) -> void;

    auto
    get_resize_start_child () const -> bool;

    auto
    set_shrink_start_child (bool resize = true) -> void;

    auto
    get_shrink_start_child () const -> bool;

    auto
    set_end_child (Widget& child) -> void;

    auto
    get_end_child () -> Widget*;

    auto
    get_end_child () const -> const Widget*;

    auto
    set_resize_end_child (bool resize = true) -> void;

    auto
    get_resize_end_child () const -> bool;

    auto
    set_shrink_end_child (bool resize = true) -> void;

    auto
    get_shrink_end_child () const -> bool;

    auto
    get_position () const -> int;

    auto
    set_position (int position) -> void;

    auto
    set_wide_handle (bool wide = true) -> void;

    auto
    get_wide_handle () const -> bool;

    auto
    property_position () -> glib::PropertyProxy<int>;

    auto
    property_position () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_position_set () -> glib::PropertyProxy<bool>;

    auto
    property_position_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_min_position () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_position () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_wide_handle () -> glib::PropertyProxy<bool>;

    auto
    property_wide_handle () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resize_start_child () -> glib::PropertyProxy<bool>;

    auto
    property_resize_start_child () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_resize_end_child () -> glib::PropertyProxy<bool>;

    auto
    property_resize_end_child () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_shrink_start_child () -> glib::PropertyProxy<bool>;

    auto
    property_shrink_start_child () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_shrink_end_child () -> glib::PropertyProxy<bool>;

    auto
    property_shrink_end_child () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_start_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_start_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_end_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_end_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPaned* object, bool take_copy = false) -> gtk::Paned*;
} // namespace glib

#endif
