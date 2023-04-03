// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREZOOM_H
#define _GTKMM_GESTUREZOOM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/gesture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureZoom = struct _GtkGestureZoom;
using GtkGestureZoomClass = struct _GtkGestureZoomClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT GestureZoom_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GestureZoom : public Gesture
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureZoom;
    using CppClassType = GestureZoom_Class;
    using BaseObjectType = GtkGestureZoom;
    using BaseClassType = GtkGestureZoomClass;

    GestureZoom (const GestureZoom&) = delete;
    auto
    operator= (const GestureZoom&) -> GestureZoom& = delete;

  private:
    friend class GestureZoom_Class;
    static CppClassType gesturezoom_class_;

  protected:
    explicit GestureZoom (const Glib::ConstructParams& construct_params);
    explicit GestureZoom (GtkGestureZoom* castitem);

#endif

  public:
    GestureZoom (GestureZoom&& src) noexcept;
    auto
    operator= (GestureZoom&& src) noexcept -> GestureZoom&;

    ~GestureZoom () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureZoom*
    {
      return reinterpret_cast<GtkGestureZoom*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureZoom*
    {
      return reinterpret_cast<GtkGestureZoom*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureZoom*;

  private:
  protected:
    GestureZoom ();

  public:
    static auto
    create () -> Glib::RefPtr<GestureZoom>;

    auto
    get_scale_delta () const -> double;

    auto
    signal_scale_changed () -> Glib::SignalProxy<void (double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureZoom* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureZoom>;
} // namespace Glib

#endif
