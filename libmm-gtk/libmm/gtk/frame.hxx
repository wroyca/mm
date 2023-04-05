// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FRAME_H
#define _GTKMM_FRAME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFrame = struct _GtkFrame;
using GtkFrameClass = struct _GtkFrameClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Frame_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Frame : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class Frame_Class;
    static CppClassType frame_class_;

  protected:
    explicit Frame (const glib::ConstructParams& construct_params);
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
    explicit Frame (const glib::ustring& label);

    auto
    set_label (const glib::ustring& label) -> void;
    auto
    unset_label () -> void;

    auto
    get_label () const -> glib::ustring;

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
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_label_xalign () -> glib::PropertyProxy<double>;

    auto
    property_label_xalign () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_label_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_label_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  protected:
    virtual auto
    compute_child_allocation_vfunc (Allocation& allocation) -> void;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFrame* object, bool take_copy = false) -> gtk::Frame*;
} // namespace glib

#endif
