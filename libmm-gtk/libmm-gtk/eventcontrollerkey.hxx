
#ifndef _GTKMM_EVENTCONTROLLERKEY_H
#define _GTKMM_EVENTCONTROLLERKEY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkEventControllerKey = struct _GtkEventControllerKey;
using GtkEventControllerKeyClass = struct _GtkEventControllerKeyClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API EventControllerKey_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Widget;

  class GTKMM_API EventControllerKey : public EventController
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
    explicit EventControllerKey (const Glib::ConstructParams& construct_params);
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
    create () -> Glib::RefPtr<EventControllerKey>;

    auto
    forward (Widget& widget) -> bool;

    auto
    get_group () const -> guint;

    auto
    signal_key_pressed ()
        -> Glib::SignalProxy<bool (guint, guint, Gdk::ModifierType)>;

    auto
    signal_key_released ()
        -> Glib::SignalProxy<void (guint, guint, Gdk::ModifierType)>;

    auto
    signal_modifiers () -> Glib::SignalProxy<bool (Gdk::ModifierType)>;

    auto
    signal_im_update () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkEventControllerKey* object, bool take_copy = false) -> Glib::RefPtr<Gtk::EventControllerKey>;
} // namespace Glib

#endif
