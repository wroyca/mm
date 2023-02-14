// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONSTRAINTTARGET_H
#define _GTKMM_CONSTRAINTTARGET_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkConstraintTargetInterface GtkConstraintTargetInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkConstraintTarget = struct _GtkConstraintTarget;
using GtkConstraintTargetClass = struct _GtkConstraintTargetClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ConstraintTarget_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ConstraintTarget : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ConstraintTarget;
    using CppClassType = ConstraintTarget_Class;
    using BaseObjectType = GtkConstraintTarget;
    using BaseClassType = GtkConstraintTargetInterface;

    ConstraintTarget (const ConstraintTarget&) = delete;
    auto
    operator= (const ConstraintTarget&) -> ConstraintTarget& = delete;

  private:
    friend class ConstraintTarget_Class;
    static CppClassType constrainttarget_class_;

#endif
  protected:
    ConstraintTarget ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit ConstraintTarget (const Glib::Interface_Class& interface_class);

  public:
    explicit ConstraintTarget (GtkConstraintTarget* castitem);

  protected:
#endif

  public:
    ConstraintTarget (ConstraintTarget&& src) noexcept;
    auto
    operator= (ConstraintTarget&& src) noexcept -> ConstraintTarget&;

    ~ConstraintTarget () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkConstraintTarget*
    {
      return reinterpret_cast<GtkConstraintTarget*> (gobject_);
    }

    auto
    gobj () const -> const GtkConstraintTarget*
    {
      return reinterpret_cast<GtkConstraintTarget*> (gobject_);
    }

  private:
  public:
  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkConstraintTarget* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintTarget>;

} // namespace Glib

#endif
