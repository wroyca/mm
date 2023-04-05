// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPCONTROLLERMOTION_H
#define _GTKMM_DROPCONTROLLERMOTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/drop.hxx>
#include <libmm/gtk/eventcontroller.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkDropControllerMotion = struct _GtkDropControllerMotion;
using GtkDropControllerMotionClass = struct _GtkDropControllerMotionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DropControllerMotion_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DropControllerMotion : public EventController
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
        const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<DropControllerMotion>;

    auto
    contains_pointer () const -> bool;

    auto
    is_pointer () const -> bool;

    auto
    get_drop () -> glib::RefPtr<gdk::Drop>;

    auto
    get_drop () const -> glib::RefPtr<const gdk::Drop>;

    auto
    signal_enter () -> glib::SignalProxy<void (double, double)>;

    auto
    signal_leave () -> glib::SignalProxy<void ()>;

    auto
    signal_motion () -> glib::SignalProxy<void (double, double)>;

    auto
    property_contains_pointer () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_drop () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Drop>>;

    auto
    property_is_pointer () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDropControllerMotion* object, bool take_copy = false) -> glib::RefPtr<gtk::DropControllerMotion>;
} // namespace glib

#endif
