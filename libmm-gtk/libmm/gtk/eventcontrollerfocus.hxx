// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLERFOCUS_H
#define _GTKMM_EVENTCONTROLLERFOCUS_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerFocus = struct _GtkEventControllerFocus;
using GtkEventControllerFocusClass = struct _GtkEventControllerFocusClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EventControllerFocus_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT EventControllerFocus : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventControllerFocus;
    using CppClassType = EventControllerFocus_Class;
    using BaseObjectType = GtkEventControllerFocus;
    using BaseClassType = GtkEventControllerFocusClass;

    EventControllerFocus (const EventControllerFocus&) = delete;
    auto
    operator= (const EventControllerFocus&) -> EventControllerFocus& = delete;

  private:
    friend class EventControllerFocus_Class;
    static CppClassType eventcontrollerfocus_class_;

  protected:
    explicit EventControllerFocus (
        const glib::ConstructParams& construct_params);
    explicit EventControllerFocus (GtkEventControllerFocus* castitem);

#endif

  public:
    EventControllerFocus (EventControllerFocus&& src) noexcept;
    auto
    operator= (EventControllerFocus&& src) noexcept -> EventControllerFocus&;

    ~EventControllerFocus () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventControllerFocus*
    {
      return reinterpret_cast<GtkEventControllerFocus*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventControllerFocus*
    {
      return reinterpret_cast<GtkEventControllerFocus*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventControllerFocus*;

  private:
  protected:
    EventControllerFocus ();

  public:
    static auto
    create () -> glib::RefPtr<EventControllerFocus>;

    auto
    contains_focus () const -> bool;

    auto
    is_focus () const -> bool;

    auto
    signal_enter () -> glib::SignalProxy<void ()>;

    auto
    signal_leave () -> glib::SignalProxy<void ()>;

    auto
    property_is_focus () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_contains_focus () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEventControllerFocus* object, bool take_copy = false) -> glib::RefPtr<gtk::EventControllerFocus>;
} // namespace glib

#endif
