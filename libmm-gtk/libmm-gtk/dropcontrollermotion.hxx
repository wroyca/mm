
#ifndef _GTKMM_DROPCONTROLLERMOTION_H
#define _GTKMM_DROPCONTROLLERMOTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/drop.hxx>
#include <libmm-gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropControllerMotion = struct _GtkDropControllerMotion;
using GtkDropControllerMotionClass = struct _GtkDropControllerMotionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API DropControllerMotion_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API DropControllerMotion : public EventController
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DropControllerMotion;
    using CppClassType = DropControllerMotion_Class;
    using BaseObjectType = GtkDropControllerMotion;
    using BaseClassType = GtkDropControllerMotionClass;

    DropControllerMotion (const DropControllerMotion&) = delete;
    auto
    operator= (const DropControllerMotion&) -> DropControllerMotion& = delete;

  private:
    friend class DropControllerMotion_Class;
    static CppClassType dropcontrollermotion_class_;

  protected:
    explicit DropControllerMotion (
        const Glib::ConstructParams& construct_params);
    explicit DropControllerMotion (GtkDropControllerMotion* castitem);

#endif

  public:
    DropControllerMotion (DropControllerMotion&& src) noexcept;
    auto
    operator= (DropControllerMotion&& src) noexcept -> DropControllerMotion&;

    ~DropControllerMotion () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDropControllerMotion*
    {
      return reinterpret_cast<GtkDropControllerMotion*> (gobject_);
    }

    auto
    gobj () const -> const GtkDropControllerMotion*
    {
      return reinterpret_cast<GtkDropControllerMotion*> (gobject_);
    }

    auto
    gobj_copy () -> GtkDropControllerMotion*;

  private:
  protected:
    DropControllerMotion ();

  public:
    static auto
    create () -> Glib::RefPtr<DropControllerMotion>;

    auto
    contains_pointer () const -> bool;

    auto
    is_pointer () const -> bool;

    auto
    get_drop () -> Glib::RefPtr<Gdk::Drop>;

    auto
    get_drop () const -> Glib::RefPtr<const Gdk::Drop>;

    auto
    signal_enter () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_leave () -> Glib::SignalProxy<void ()>;

    auto
    signal_motion () -> Glib::SignalProxy<void (double, double)>;

    auto
    property_contains_pointer () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_drop () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::Drop>>;

    auto
    property_is_pointer () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkDropControllerMotion* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DropControllerMotion>;
} // namespace Glib

#endif
