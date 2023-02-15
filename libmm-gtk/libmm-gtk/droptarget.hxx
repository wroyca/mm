// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPTARGET_H
#define _GTKMM_DROPTARGET_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentformats.hxx>
#include <libmm-gdk/drop.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropTarget = struct _GtkDropTarget;
using GtkDropTargetClass = struct _GtkDropTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API DropTarget_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API DropTarget : public EventController
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
    explicit DropTarget (const Glib::ConstructParams& construct_params);
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
    create (GType type, Gdk::DragAction actions) -> Glib::RefPtr<DropTarget>;

    auto
    set_gtypes (const std::vector<GType>& types) -> void;

    auto
    get_gtypes () const -> std::vector<GType>;

    auto
    get_formats () -> Glib::RefPtr<Gdk::ContentFormats>;

    auto
    get_formats () const -> Glib::RefPtr<const Gdk::ContentFormats>;

    auto
    set_actions (Gdk::DragAction actions) -> void;

    auto
    get_actions () const -> Gdk::DragAction;

    auto
    set_preload (bool preload = true) -> void;

    auto
    get_preload () const -> bool;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_drop () -> Glib::RefPtr<Gdk::Drop>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    get_drop () const -> Glib::RefPtr<const Gdk::Drop>;
#endif

    auto
    get_current_drop () -> Glib::RefPtr<Gdk::Drop>;

    auto
    get_current_drop () const -> Glib::RefPtr<const Gdk::Drop>;

    auto
    get_value () const -> Glib::ValueBase;

    auto
    reject () -> void;

    auto
    property_actions () -> Glib::PropertyProxy<Gdk::DragAction>;

    auto
    property_actions () const -> Glib::PropertyProxy_ReadOnly<Gdk::DragAction>;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_drop () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Drop>>;

#endif

    auto
    property_current_drop () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Drop>>;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::ContentFormats>>;

    auto
    property_preload () -> Glib::PropertyProxy<bool>;

    auto
    property_preload () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<GValue*>;

    auto
    signal_accept ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<Gdk::Drop>&)>;

    auto
    signal_enter () -> Glib::SignalProxy<Gdk::DragAction (double, double)>;

    auto
    signal_motion () -> Glib::SignalProxy<Gdk::DragAction (double, double)>;

    auto
    signal_leave () -> Glib::SignalProxy<void ()>;

    auto
    signal_drop ()
        -> Glib::SignalProxy<bool (const Glib::ValueBase&, double, double)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkDropTarget* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DropTarget>;
} // namespace Glib

#endif
