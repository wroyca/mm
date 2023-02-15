// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAGSOURCE_H
#define _GTKMM_DRAGSOURCE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/contentprovider.hxx>
#include <libmm-gdk/drag.hxx>
#include <libmm-gdk/enums.hxx>
#include <libmm-gdk/paintable.hxx>
#include <libmm-gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDragSource = struct _GtkDragSource;
using GtkDragSourceClass = struct _GtkDragSourceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API DragSource_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API DragSource : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DragSource;
    using CppClassType = DragSource_Class;
    using BaseObjectType = GtkDragSource;
    using BaseClassType = GtkDragSourceClass;

    DragSource (const DragSource&) = delete;
    auto
    operator= (const DragSource&) -> DragSource& = delete;

  private:
    friend class DragSource_Class;
    static CppClassType dragsource_class_;

  protected:
    explicit DragSource (const Glib::ConstructParams& construct_params);
    explicit DragSource (GtkDragSource* castitem);

#endif

  public:
    DragSource (DragSource&& src) noexcept;
    auto
    operator= (DragSource&& src) noexcept -> DragSource&;

    ~DragSource () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDragSource*
    {
      return reinterpret_cast<GtkDragSource*> (gobject_);
    }

    auto
    gobj () const -> const GtkDragSource*
    {
      return reinterpret_cast<GtkDragSource*> (gobject_);
    }

    auto
    gobj_copy () -> GtkDragSource*;

  private:
  protected:
    DragSource ();

  public:
    static auto
    create () -> Glib::RefPtr<DragSource>;

    auto
    set_content (const Glib::RefPtr<Gdk::ContentProvider>& content) -> void;

    auto
    get_content () -> Glib::RefPtr<Gdk::ContentProvider>;

    auto
    get_content () const -> Glib::RefPtr<const Gdk::ContentProvider>;

    auto
    set_actions (Gdk::DragAction actions) -> void;

    auto
    get_actions () const -> Gdk::DragAction;

    auto
    set_icon (const Glib::RefPtr<const Gdk::Paintable>& paintable,
              int hot_x,
              int hot_y) -> void;

    auto
    drag_cancel () -> void;

    auto
    get_drag () -> Glib::RefPtr<Gdk::Drag>;

    auto
    get_drag () const -> Glib::RefPtr<const Gdk::Drag>;

    auto
    property_content ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gdk::ContentProvider>>;

    auto
    property_content () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::ContentProvider>>;

    auto
    property_actions () -> Glib::PropertyProxy<Gdk::DragAction>;

    auto
    property_actions () const -> Glib::PropertyProxy_ReadOnly<Gdk::DragAction>;

    auto
    signal_prepare ()
        -> Glib::SignalProxy<Glib::RefPtr<Gdk::ContentProvider> (double,
                                                                 double)>;

    auto
    signal_drag_begin ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Drag>&)>;

    auto
    signal_drag_end ()
        -> Glib::SignalProxy<void (const Glib::RefPtr<Gdk::Drag>&, bool)>;

    auto
    signal_drag_cancel ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<Gdk::Drag>&,
                                   Gdk::DragCancelReason)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkDragSource* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DragSource>;
} // namespace Glib

#endif
