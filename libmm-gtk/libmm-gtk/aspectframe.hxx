// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ASPECTFRAME_H
#define _GTKMM_ASPECTFRAME_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAspectFrame = struct _GtkAspectFrame;
using GtkAspectFrameClass = struct _GtkAspectFrameClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AspectFrame_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API AspectFrame : public Widget
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
    friend GTKMM_API class AspectFrame_Class;
    static CppClassType aspectframe_class_;

  protected:
    explicit AspectFrame (const Glib::ConstructParams& construct_params);
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
    explicit AspectFrame (Align xalign = Gtk::Align::CENTER,
                          Align yalign = Gtk::Align::CENTER,
                          float ratio = 1.0,
                          bool obey_child = false);

    explicit AspectFrame (float xalign,
                          float yalign,
                          float ratio = 1.0,
                          bool obey_child = false);

    void
    set_xalign (Align xalign);

    void
    set_xalign (float xalign);

    auto
    get_xalign () const -> float;

    void
    set_yalign (Align yalign);

    void
    set_yalign (float yalign);

    auto
    get_yalign () const -> float;

    void
    set_ratio (float ratio);

    auto
    get_ratio () const -> float;

    void
    set_obey_child (bool obey_child = true);

    auto
    get_obey_child () const -> bool;

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_xalign () -> Glib::PropertyProxy<float>;

    auto
    property_xalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_yalign () -> Glib::PropertyProxy<float>;

    auto
    property_yalign () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_ratio () -> Glib::PropertyProxy<float>;

    auto
    property_ratio () const -> Glib::PropertyProxy_ReadOnly<float>;

    auto
    property_obey_child () -> Glib::PropertyProxy<bool>;

    auto
    property_obey_child () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkAspectFrame* object, bool take_copy = false) -> Gtk::AspectFrame*;
} // namespace Glib

#endif
