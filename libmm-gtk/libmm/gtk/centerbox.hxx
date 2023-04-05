// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CENTERBOX_H
#define _GTKMM_CENTERBOX_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCenterBox = struct _GtkCenterBox;
using GtkCenterBoxClass = struct _GtkCenterBoxClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CenterBox_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CenterBox : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class CenterBox_Class;
    static CppClassType centerbox_class_;

  protected:
    explicit CenterBox (const glib::ConstructParams& construct_params);
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

    auto
    set_start_widget (Widget& child) -> void;

    auto
    get_start_widget () -> Widget*;

    auto
    get_start_widget () const -> const Widget*;

    auto
    unset_start_widget () -> void;

    auto
    set_center_widget (Widget& child) -> void;

    auto
    get_center_widget () -> Widget*;

    auto
    get_center_widget () const -> const Widget*;

    auto
    unset_center_widget () -> void;

    auto
    set_end_widget (Widget& child) -> void;

    auto
    get_end_widget () -> Widget*;

    auto
    get_end_widget () const -> const Widget*;

    auto
    unset_end_widget () -> void;

    auto
    set_baseline_position (BaselinePosition position) -> void;

    auto
    get_baseline_position () -> BaselinePosition;

    auto
    property_start_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_start_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_center_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_center_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_end_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_end_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_baseline_position () -> glib::PropertyProxy<BaselinePosition>;

    auto
    property_baseline_position () const
        -> glib::PropertyProxy_ReadOnly<BaselinePosition>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCenterBox* object, bool take_copy = false) -> gtk::CenterBox*;
} // namespace glib

#endif
