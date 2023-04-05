// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPTARGET_H
#define _GTKMM_DROPTARGET_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentformats.hxx>
#include <libmm/gdk/drop.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTarget = struct _GtkDropTarget;
using GtkDropTargetClass = struct _GtkDropTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DropTarget_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DropTarget : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DropTarget;
    using CppClassType = DropTarget_Class;
    using BaseObjectType = GtkDropTarget;
    using BaseClassType = GtkDropTargetClass;

    DropTarget (const DropTarget&) = delete;
    auto
    operator= (const DropTarget&) -> DropTarget& = delete;

  private:
    friend class DropTarget_Class;
    static CppClassType droptarget_class_;

  protected:
    explicit DropTarget (const glib::ConstructParams& construct_params);
    explicit DropTarget (GtkDropTarget* castitem);

#endif

  public:
    DropTarget (DropTarget&& src) noexcept;
    auto
    operator= (DropTarget&& src) noexcept -> DropTarget&;

    ~DropTarget () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDropTarget*
    {
      return reinterpret_cast<GtkDropTarget*> (gobject_);
    }

    auto
    gobj () const -> const GtkDropTarget*
    {
      return reinterpret_cast<GtkDropTarget*> (gobject_);
    }

    auto
    gobj_copy () -> GtkDropTarget*;

  private:
  public:
    static auto
    create (GType type, gdk::DragAction actions) -> glib::RefPtr<DropTarget>;

    auto
    set_gtypes (const std::vector<GType>& types) -> void;

    auto
    get_gtypes () const -> std::vector<GType>;

    auto
    get_formats () -> glib::RefPtr<gdk::ContentFormats>;

    auto
    get_formats () const -> glib::RefPtr<const gdk::ContentFormats>;

    auto
    set_actions (gdk::DragAction actions) -> void;

    auto
    get_actions () const -> gdk::DragAction;

    auto
    set_preload (bool preload = true) -> void;

    auto
    get_preload () const -> bool;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_drop () -> glib::RefPtr<gdk::Drop>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_drop () const -> glib::RefPtr<const gdk::Drop>;
#endif

    auto
    get_current_drop () -> glib::RefPtr<gdk::Drop>;

    auto
    get_current_drop () const -> glib::RefPtr<const gdk::Drop>;

    auto
    get_value () const -> glib::ValueBase;

    auto
    reject () -> void;

    auto
    property_actions () -> glib::PropertyProxy<gdk::DragAction>;

    auto
    property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_drop () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>;

#endif

    auto
    property_current_drop () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentFormats>>;

    auto
    property_preload () -> glib::PropertyProxy<bool>;

    auto
    property_preload () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<GValue*>;

    auto
    signal_accept ()
        -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drop>&)>;

    auto
    signal_enter () -> glib::SignalProxy<gdk::DragAction (double, double)>;

    auto
    signal_motion () -> glib::SignalProxy<gdk::DragAction (double, double)>;

    auto
    signal_leave () -> glib::SignalProxy<void ()>;

    auto
    signal_drop ()
        -> glib::SignalProxy<bool (const glib::ValueBase&, double, double)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDropTarget* object, bool take_copy = false) -> glib::RefPtr<gtk::DropTarget>;
} // namespace glib

#endif
