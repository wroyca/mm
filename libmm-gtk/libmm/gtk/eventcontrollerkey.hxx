// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EVENTCONTROLLERKEY_H
#define _GTKMM_EVENTCONTROLLERKEY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerKey = struct _GtkEventControllerKey;
using GtkEventControllerKeyClass = struct _GtkEventControllerKeyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT EventControllerKey_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT EventControllerKey : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = EventControllerKey;
    using CppClassType = EventControllerKey_Class;
    using BaseObjectType = GtkEventControllerKey;
    using BaseClassType = GtkEventControllerKeyClass;

    EventControllerKey (const EventControllerKey&) = delete;
    auto
    operator= (const EventControllerKey&) -> EventControllerKey& = delete;

  private:
    friend class EventControllerKey_Class;
    static CppClassType eventcontrollerkey_class_;

  protected:
    explicit EventControllerKey (const glib::ConstructParams& construct_params);
    explicit EventControllerKey (GtkEventControllerKey* castitem);

#endif

  public:
    EventControllerKey (EventControllerKey&& src) noexcept;
    auto
    operator= (EventControllerKey&& src) noexcept -> EventControllerKey&;

    ~EventControllerKey () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkEventControllerKey*
    {
      return reinterpret_cast<GtkEventControllerKey*> (gobject_);
    }

    auto
    gobj () const -> const GtkEventControllerKey*
    {
      return reinterpret_cast<GtkEventControllerKey*> (gobject_);
    }

    auto
    gobj_copy () -> GtkEventControllerKey*;

  private:
  protected:
    EventControllerKey ();

  public:
    static auto
    create () -> glib::RefPtr<EventControllerKey>;

    auto
    forward (Widget& widget) -> bool;

    auto
    get_group () const -> guint;

    auto
    signal_key_pressed ()
        -> glib::SignalProxy<bool (guint, guint, gdk::ModifierType)>;

    auto
    signal_key_released ()
        -> glib::SignalProxy<void (guint, guint, gdk::ModifierType)>;

    auto
    signal_modifiers () -> glib::SignalProxy<bool (gdk::ModifierType)>;

    auto
    signal_im_update () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkEventControllerKey* object, bool take_copy = false) -> glib::RefPtr<gtk::EventControllerKey>;
} // namespace glib

#endif
