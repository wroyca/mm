// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DRAGICON_H
#define _GTKMM_DRAGICON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/drag.hxx>
#include <libmm/gdk/paintable.hxx>
#include <libmm/glib/value.hxx>
#include <libmm/gtk/native.hxx>
#include <libmm/gtk/root.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DragIcon_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DragIcon : public Widget,
                             public Native,
                             public Root
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef DragIcon CppObjectType;
    typedef DragIcon_Class CppClassType;
    typedef GtkDragIcon BaseObjectType;
    typedef GtkDragIconClass BaseClassType;
#endif

    DragIcon (DragIcon&& src) noexcept;
    auto
    operator= (DragIcon&& src) noexcept -> DragIcon&;

    DragIcon (const DragIcon&) = delete;
    auto
    operator= (const DragIcon&) -> DragIcon& = delete;

    ~DragIcon () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class DragIcon_Class;
    static CppClassType dragicon_class_;

  protected:
    explicit DragIcon (const glib::ConstructParams& construct_params);
    explicit DragIcon (GtkDragIcon* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDragIcon*
    {
      return reinterpret_cast<GtkDragIcon*> (gobject_);
    }

    auto
    gobj () const -> const GtkDragIcon*
    {
      return reinterpret_cast<GtkDragIcon*> (gobject_);
    }

  private:
  public:
    static auto
    get_for_drag (const glib::RefPtr<gdk::Drag>& drag) -> DragIcon*;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    static auto
    set_from_paintable (const glib::RefPtr<gdk::Drag>& drag,
                        const glib::RefPtr<gdk::Paintable>& paintable,
                        int hot_x,
                        int hot_y) -> void;

    static auto
    create_widget_for_value (const glib::ValueBase& value) -> Widget*;

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
  wrap (GtkDragIcon* object, bool take_copy = false) -> gtk::DragIcon*;
} // namespace glib

#endif
