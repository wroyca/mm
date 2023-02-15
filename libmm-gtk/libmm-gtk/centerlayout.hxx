// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CENTERLAYOUT_H
#define _GTKMM_CENTERLAYOUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/layoutmanager.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CenterLayout_Class;
}
#endif

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT CenterLayout : public LayoutManager
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CenterLayout;
    using CppClassType = CenterLayout_Class;
    using BaseObjectType = GtkCenterLayout;
    using BaseClassType = GtkCenterLayoutClass;

    CenterLayout (const CenterLayout&) = delete;
    auto
    operator= (const CenterLayout&) -> CenterLayout& = delete;

  private:
    friend class CenterLayout_Class;
    static CppClassType centerlayout_class_;

  protected:
    explicit CenterLayout (const Glib::ConstructParams& construct_params);
    explicit CenterLayout (GtkCenterLayout* castitem);

#endif

  public:
    CenterLayout (CenterLayout&& src) noexcept;
    auto
    operator= (CenterLayout&& src) noexcept -> CenterLayout&;

    ~CenterLayout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCenterLayout*
    {
      return reinterpret_cast<GtkCenterLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkCenterLayout*
    {
      return reinterpret_cast<GtkCenterLayout*> (gobject_);
    }

    auto
    gobj_copy () -> GtkCenterLayout*;

  private:
  protected:
    CenterLayout ();

  public:
    static auto
    create () -> Glib::RefPtr<CenterLayout>;

    auto
    set_orientation (Orientation orientation) -> void;

    auto
    get_orientation () const -> Orientation;

    auto
    set_baseline_position (BaselinePosition baseline_position) -> void;

    auto
    get_baseline_position () const -> BaselinePosition;

    auto
    set_start_widget (Widget* widget) -> void;

    auto
    get_start_widget () -> Widget*;

    auto
    get_start_widget () const -> const Widget*;

    auto
    set_center_widget (Widget* widget) -> void;

    auto
    get_center_widget () -> Widget*;

    auto
    get_center_widget () const -> const Widget*;

    auto
    set_end_widget (Widget* widget) -> void;

    auto
    get_end_widget () -> Widget*;

    auto
    get_end_widget () const -> const Widget*;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCenterLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CenterLayout>;
} // namespace Glib

#endif
