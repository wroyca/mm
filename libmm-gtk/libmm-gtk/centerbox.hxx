// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CENTERBOX_H
#define _GTKMM_CENTERBOX_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCenterBox = struct _GtkCenterBox;
using GtkCenterBoxClass = struct _GtkCenterBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CenterBox_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CenterBox : public Widget,
                              public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CenterBox CppObjectType;
    typedef CenterBox_Class CppClassType;
    typedef GtkCenterBox BaseObjectType;
    typedef GtkCenterBoxClass BaseClassType;
#endif

    CenterBox (CenterBox&& src) noexcept;
    auto
    operator= (CenterBox&& src) noexcept -> CenterBox&;

    CenterBox (const CenterBox&) = delete;
    auto
    operator= (const CenterBox&) -> CenterBox& = delete;

    ~CenterBox () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class CenterBox_Class;
    static CppClassType centerbox_class_;

  protected:
    explicit CenterBox (const Glib::ConstructParams& construct_params);
    explicit CenterBox (GtkCenterBox* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCenterBox*
    {
      return reinterpret_cast<GtkCenterBox*> (gobject_);
    }

    auto
    gobj () const -> const GtkCenterBox*
    {
      return reinterpret_cast<GtkCenterBox*> (gobject_);
    }

  private:
  public:
    CenterBox ();

    void
    set_start_widget (Widget& child);

    auto
    get_start_widget () -> Widget*;

    auto
    get_start_widget () const -> const Widget*;

    void
    unset_start_widget ();

    void
    set_center_widget (Widget& child);

    auto
    get_center_widget () -> Widget*;

    auto
    get_center_widget () const -> const Widget*;

    void
    unset_center_widget ();

    void
    set_end_widget (Widget& child);

    auto
    get_end_widget () -> Widget*;

    auto
    get_end_widget () const -> const Widget*;

    void
    unset_end_widget ();

    void
    set_baseline_position (BaselinePosition position);

    auto
    get_baseline_position () -> BaselinePosition;

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

  GTKMM_API
  auto
  wrap (GtkCenterBox* object, bool take_copy = false) -> Gtk::CenterBox*;
} // namespace Glib

#endif
