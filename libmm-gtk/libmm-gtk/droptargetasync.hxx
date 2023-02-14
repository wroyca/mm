// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPTARGETASYNC_H
#define _GTKMM_DROPTARGETASYNC_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/drop.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTargetAsync = struct _GtkDropTargetAsync;
using GtkDropTargetAsyncClass = struct _GtkDropTargetAsyncClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API DropTargetAsync_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API DropTargetAsync : public EventController
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
    explicit DropTargetAsync (const Glib::ConstructParams& construct_params);
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
    create (const Glib::RefPtr<const Gdk::ContentFormats>& formats,
            Gdk::DragAction actions = static_cast<Gdk::DragAction> (0))
        -> Glib::RefPtr<DropTargetAsync>;
    static auto
    create (Gdk::DragAction actions = static_cast<Gdk::DragAction> (0))
        -> Glib::RefPtr<DropTargetAsync>;

    void
    set_formats (const Glib::RefPtr<const Gdk::ContentFormats>& formats);

    auto
    get_formats () -> Glib::RefPtr<Gdk::ContentFormats>;

    auto
    get_formats () const -> Glib::RefPtr<const Gdk::ContentFormats>;

    void
    set_actions (Gdk::DragAction actions);

    auto
    get_actions () const -> Gdk::DragAction;

    void
    reject_drop (const Glib::RefPtr<Gdk::Drop>& drop);

    auto
    property_actions () -> Glib::PropertyProxy<Gdk::DragAction>;

    auto
    property_actions () const -> Glib::PropertyProxy_ReadOnly<Gdk::DragAction>;

    auto
    property_formats ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::ContentFormats>>;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::ContentFormats>>;

    auto
    signal_accept ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<Gdk::Drop>&)>;

    auto
    signal_drag_enter () -> Glib::SignalProxy<
        Gdk::DragAction (const Glib::RefPtr<Gdk::Drop>&, double, double)>;

    auto
    signal_drag_motion () -> Glib::SignalProxy<
        Gdk::DragAction (const Glib::RefPtr<Gdk::Drop>&, double, double)>;

    auto
    signal_drag_leave ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Drop>&)>;

    auto
    signal_drop () -> Glib::SignalProxy<
        bool (const Glib::RefPtr<Gdk::Drop>&, double, double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkDropTargetAsync* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DropTargetAsync>;
} // namespace Glib

#endif
