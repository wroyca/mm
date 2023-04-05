// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPTARGETASYNC_H
#define _GTKMM_DROPTARGETASYNC_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/drop.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTargetAsync = struct _GtkDropTargetAsync;
using GtkDropTargetAsyncClass = struct _GtkDropTargetAsyncClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DropTargetAsync_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DropTargetAsync : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DropTargetAsync;
    using CppClassType = DropTargetAsync_Class;
    using BaseObjectType = GtkDropTargetAsync;
    using BaseClassType = GtkDropTargetAsyncClass;

    DropTargetAsync (const DropTargetAsync&) = delete;
    auto
    operator= (const DropTargetAsync&) -> DropTargetAsync& = delete;

  private:
    friend class DropTargetAsync_Class;
    static CppClassType droptargetasync_class_;

  protected:
    explicit DropTargetAsync (const glib::ConstructParams& construct_params);
    explicit DropTargetAsync (GtkDropTargetAsync* castitem);

#endif

  public:
    DropTargetAsync (DropTargetAsync&& src) noexcept;
    auto
    operator= (DropTargetAsync&& src) noexcept -> DropTargetAsync&;

    ~DropTargetAsync () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDropTargetAsync*
    {
      return reinterpret_cast<GtkDropTargetAsync*> (gobject_);
    }

    auto
    gobj () const -> const GtkDropTargetAsync*
    {
      return reinterpret_cast<GtkDropTargetAsync*> (gobject_);
    }

    auto
    gobj_copy () -> GtkDropTargetAsync*;

  private:
  public:
    static auto
    create (const glib::RefPtr<const gdk::ContentFormats>& formats,
            gdk::DragAction actions = static_cast<gdk::DragAction> (0))
        -> glib::RefPtr<DropTargetAsync>;
    static auto
    create (gdk::DragAction actions = static_cast<gdk::DragAction> (0))
        -> glib::RefPtr<DropTargetAsync>;

    auto
    set_formats (const glib::RefPtr<const gdk::ContentFormats>& formats)
        -> void;

    auto
    get_formats () -> glib::RefPtr<gdk::ContentFormats>;

    auto
    get_formats () const -> glib::RefPtr<const gdk::ContentFormats>;

    auto
    set_actions (gdk::DragAction actions) -> void;

    auto
    get_actions () const -> gdk::DragAction;

    auto
    reject_drop (const glib::RefPtr<gdk::Drop>& drop) -> void;

    auto
    property_actions () -> glib::PropertyProxy<gdk::DragAction>;

    auto
    property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>;

    auto
    property_formats ()
        -> glib::PropertyProxy<glib::RefPtr<gdk::ContentFormats>>;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>>;

    auto
    signal_accept ()
        -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)>;

    auto
    signal_drag_enter () -> glib::SignalProxy<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto
    signal_drag_motion () -> glib::SignalProxy<
        gdk::DragAction (const glib::RefPtr<gdk::Drop>&, double, double)>;

    auto
    signal_drag_leave ()
        -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drop>&)>;

    auto
    signal_drop () -> glib::SignalProxy<
        bool (const glib::RefPtr<gdk::Drop>&, double, double)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDropTargetAsync* object, bool take_copy = false) -> glib::RefPtr<gtk::DropTargetAsync>;
} // namespace glib

#endif
