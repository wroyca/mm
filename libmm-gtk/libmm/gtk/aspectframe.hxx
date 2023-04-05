// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASPECTFRAME_H
#define _GTKMM_ASPECTFRAME_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAspectFrame = struct _GtkAspectFrame;
using GtkAspectFrameClass = struct _GtkAspectFrameClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT AspectFrame_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT AspectFrame : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AspectFrame CppObjectType;
    typedef AspectFrame_Class CppClassType;
    typedef GtkAspectFrame BaseObjectType;
    typedef GtkAspectFrameClass BaseClassType;
#endif

    AspectFrame (AspectFrame&& src) noexcept;
    auto
    operator= (AspectFrame&& src) noexcept -> AspectFrame&;

    AspectFrame (const AspectFrame&) = delete;
    auto
    operator= (const AspectFrame&) -> AspectFrame& = delete;

    ~AspectFrame () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class AspectFrame_Class;
    static CppClassType aspectframe_class_;

  protected:
    explicit AspectFrame (const glib::ConstructParams& construct_params);
    explicit AspectFrame (GtkAspectFrame* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAspectFrame*
    {
      return reinterpret_cast<GtkAspectFrame*> (gobject_);
    }

    auto
    gobj () const -> const GtkAspectFrame*
    {
      return reinterpret_cast<GtkAspectFrame*> (gobject_);
    }

  private:
  public:
    explicit AspectFrame (Align xalign = gtk::Align::CENTER,
                          Align yalign = gtk::Align::CENTER,
                          float ratio = 1.0,
                          bool obey_child = false);

    explicit AspectFrame (float xalign,
                          float yalign,
                          float ratio = 1.0,
                          bool obey_child = false);

    auto
    set_xalign (Align xalign) -> void;

    auto
    set_xalign (float xalign) -> void;

    auto
    get_xalign () const -> float;

    auto
    set_yalign (Align yalign) -> void;

    auto
    set_yalign (float yalign) -> void;

    auto
    get_yalign () const -> float;

    auto
    set_ratio (float ratio) -> void;

    auto
    get_ratio () const -> float;

    auto
    set_obey_child (bool obey_child = true) -> void;

    auto
    get_obey_child () const -> bool;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_xalign () -> glib::PropertyProxy<float>;

    auto
    property_xalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> glib::PropertyProxy<float>;

    auto
    property_yalign () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_ratio () -> glib::PropertyProxy<float>;

    auto
    property_ratio () const -> glib::PropertyProxy_ReadOnly<float>;

    auto
    property_obey_child () -> glib::PropertyProxy<bool>;

    auto
    property_obey_child () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkAspectFrame* object, bool take_copy = false) -> gtk::AspectFrame*;
} // namespace glib

#endif
