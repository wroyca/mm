// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FRAME_H
#define _GTKMM_FRAME_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFrame = struct _GtkFrame;
using GtkFrameClass = struct _GtkFrameClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Frame_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Frame : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Frame CppObjectType;
    typedef Frame_Class CppClassType;
    typedef GtkFrame BaseObjectType;
    typedef GtkFrameClass BaseClassType;
#endif

    Frame (Frame&& src) noexcept;
    auto
    operator= (Frame&& src) noexcept -> Frame&;

    Frame (const Frame&) = delete;
    auto
    operator= (const Frame&) -> Frame& = delete;

    ~Frame () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Frame_Class;
    static CppClassType frame_class_;

  protected:
    explicit Frame (const Glib::ConstructParams& construct_params);
    explicit Frame (GtkFrame* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFrame*
    {
      return reinterpret_cast<GtkFrame*> (gobject_);
    }

    auto
    gobj () const -> const GtkFrame*
    {
      return reinterpret_cast<GtkFrame*> (gobject_);
    }

  private:
  public:
    Frame ();
    explicit Frame (const Glib::ustring& label);

    auto
    set_label (const Glib::ustring& label) -> void;
    auto
    unset_label () -> void;

    auto
    get_label () const -> Glib::ustring;

    auto
    set_label_widget (Widget& label_widget) -> void;

    auto
    get_label_widget () -> Widget*;

    auto
    get_label_widget () const -> const Widget*;

    auto
    set_label_align (float xalign = 0.0) -> void;

    auto
    set_label_align (Align xalign) -> void;

    auto
    get_label_align () const -> float;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_label_xalign () -> Glib::PropertyProxy<double>;

    auto
    property_label_xalign () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_label_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_label_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  protected:
    virtual auto
    compute_child_allocation_vfunc (Allocation& allocation) -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkFrame* object, bool take_copy = false) -> Gtk::Frame*;
} // namespace Glib

#endif
