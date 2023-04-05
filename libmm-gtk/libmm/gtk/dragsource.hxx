// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAGSOURCE_H
#define _GTKMM_DRAGSOURCE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/contentprovider.hxx>
#include <libmm/gdk/drag.hxx>
#include <libmm/gdk/enums.hxx>
#include <libmm/gdk/paintable.hxx>
#include <libmm/gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDragSource = struct _GtkDragSource;
using GtkDragSourceClass = struct _GtkDragSourceClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DragSource_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DragSource : public GestureSingle
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
    explicit DragSource (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<DragSource>;

    auto
    set_content (const glib::RefPtr<gdk::ContentProvider>& content) -> void;

    auto
    get_content () -> glib::RefPtr<gdk::ContentProvider>;

    auto
    get_content () const -> glib::RefPtr<const gdk::ContentProvider>;

    auto
    set_actions (gdk::DragAction actions) -> void;

    auto
    get_actions () const -> gdk::DragAction;

    auto
    set_icon (const glib::RefPtr<const gdk::Paintable>& paintable,
              int hot_x,
              int hot_y) -> void;

    auto
    drag_cancel () -> void;

    auto
    get_drag () -> glib::RefPtr<gdk::Drag>;

    auto
    get_drag () const -> glib::RefPtr<const gdk::Drag>;

    auto
    property_content ()
        -> glib::PropertyProxy<glib::RefPtr<gdk::ContentProvider>>;

    auto
    property_content () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::ContentProvider>>;

    auto
    property_actions () -> glib::PropertyProxy<gdk::DragAction>;

    auto
    property_actions () const -> glib::PropertyProxy_ReadOnly<gdk::DragAction>;

    auto
    signal_prepare ()
        -> glib::SignalProxy<glib::RefPtr<gdk::ContentProvider> (double,
                                                                 double)>;

    auto
    signal_drag_begin ()
        -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&)>;

    auto
    signal_drag_end ()
        -> glib::SignalProxy<void (const glib::RefPtr<gdk::Drag>&, bool)>;

    auto
    signal_drag_cancel ()
        -> glib::SignalProxy<bool (const glib::RefPtr<gdk::Drag>&,
                                   gdk::DragCancelReason)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDragSource* object, bool take_copy = false) -> glib::RefPtr<gtk::DragSource>;
} // namespace glib

#endif
