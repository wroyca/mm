// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LAYOUTMANAGER_H
#define _GTKMM_LAYOUTMANAGER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLayoutManager = struct _GtkLayoutManager;
using GtkLayoutManagerClass = struct _GtkLayoutManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT LayoutManager_Class;
}
#endif

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT LayoutChild;
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT LayoutManager : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = LayoutManager;
    using CppClassType = LayoutManager_Class;
    using BaseObjectType = GtkLayoutManager;
    using BaseClassType = GtkLayoutManagerClass;

    LayoutManager (const LayoutManager&) = delete;
    auto
    operator= (const LayoutManager&) -> LayoutManager& = delete;

  private:
    friend class LayoutManager_Class;
    static CppClassType layoutmanager_class_;

  protected:
    explicit LayoutManager (const Glib::ConstructParams& construct_params);
    explicit LayoutManager (GtkLayoutManager* castitem);

#endif

  public:
    LayoutManager (LayoutManager&& src) noexcept;
    auto
    operator= (LayoutManager&& src) noexcept -> LayoutManager&;

    ~LayoutManager () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLayoutManager*
    {
      return reinterpret_cast<GtkLayoutManager*> (gobject_);
    }

    auto
    gobj () const -> const GtkLayoutManager*
    {
      return reinterpret_cast<GtkLayoutManager*> (gobject_);
    }

    auto
    gobj_copy () -> GtkLayoutManager*;

  private:
  protected:
    LayoutManager ();

  public:
    auto
    measure (Widget& widget,
             Orientation orientation,
             int for_size,
             int& minimum,
             int& natural,
             int& minimum_baseline,
             int& natural_baseline) const -> void;

    auto
    allocate (Widget& widget, int width, int height, int baseline) -> void;

    auto
    get_request_mode () const -> SizeRequestMode;

    auto
    get_widget () -> Widget*;

    auto
    get_widget () const -> const Widget*;

    auto
    layout_changed () -> void;

    auto
    get_layout_child (Widget& child) -> Glib::RefPtr<LayoutChild>;

    auto
    get_layout_child (Widget& child) const -> Glib::RefPtr<const LayoutChild>;

  protected:
    virtual auto
    get_request_mode_vfunc (const Widget& widget) const -> SizeRequestMode;

    virtual auto
    measure_vfunc (const Widget& widget,
                   Orientation orientation,
                   int for_size,
                   int& minimum,
                   int& natural,
                   int& minimum_baseline,
                   int& natural_baseline) const -> void;

    virtual auto
    allocate_vfunc (const Widget& widget, int width, int height, int baseline)
        -> void;

    virtual auto
    create_layout_child_vfunc (const Widget& widget, const Widget& for_child)
        -> Glib::RefPtr<LayoutChild>;

    virtual auto
    root_vfunc () -> void;

    virtual auto
    unroot_vfunc () -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkLayoutManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::LayoutManager>;
} // namespace Glib

#endif
