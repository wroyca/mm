// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREDRAG_H
#define _GTKMM_GESTUREDRAG_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureDrag = struct _GtkGestureDrag;
using GtkGestureDragClass = struct _GtkGestureDragClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT GestureDrag_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GestureDrag : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureDrag;
    using CppClassType = GestureDrag_Class;
    using BaseObjectType = GtkGestureDrag;
    using BaseClassType = GtkGestureDragClass;

    GestureDrag (const GestureDrag&) = delete;
    auto
    operator= (const GestureDrag&) -> GestureDrag& = delete;

  private:
    friend class GestureDrag_Class;
    static CppClassType gesturedrag_class_;

  protected:
    explicit GestureDrag (const Glib::ConstructParams& construct_params);
    explicit GestureDrag (GtkGestureDrag* castitem);

#endif

  public:
    GestureDrag (GestureDrag&& src) noexcept;
    auto
    operator= (GestureDrag&& src) noexcept -> GestureDrag&;

    ~GestureDrag () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureDrag*
    {
      return reinterpret_cast<GtkGestureDrag*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureDrag*
    {
      return reinterpret_cast<GtkGestureDrag*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureDrag*;

  private:
  protected:
    GestureDrag ();

  public:
    static auto
    create () -> Glib::RefPtr<GestureDrag>;

    auto
    get_start_point (double& x, double& y) const -> bool;

    auto
    get_offset (double& x, double& y) const -> bool;

    auto
    signal_drag_begin () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_drag_update () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_drag_end () -> Glib::SignalProxy<void (double, double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureDrag* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureDrag>;
} // namespace Glib

#endif
