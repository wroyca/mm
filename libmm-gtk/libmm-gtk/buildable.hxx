// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUILDABLE_H
#define _GTKMM_BUILDABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkBuildableIface GtkBuildableIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuildable = struct _GtkBuildable;
using GtkBuildableClass = struct _GtkBuildableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Buildable_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Buildable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Buildable;
    using CppClassType = Buildable_Class;
    using BaseObjectType = GtkBuildable;
    using BaseClassType = GtkBuildableIface;

    Buildable (const Buildable&) = delete;
    auto
    operator= (const Buildable&) -> Buildable& = delete;

  private:
    friend class Buildable_Class;
    static CppClassType buildable_class_;

#endif
  protected:
    Buildable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Buildable (const Glib::Interface_Class& interface_class);

  public:
    explicit Buildable (GtkBuildable* castitem);

  protected:
#endif

  public:
    Buildable (Buildable&& src) noexcept;
    auto
    operator= (Buildable&& src) noexcept -> Buildable&;

    ~Buildable () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBuildable*
    {
      return reinterpret_cast<GtkBuildable*> (gobject_);
    }

    auto
    gobj () const -> const GtkBuildable*
    {
      return reinterpret_cast<GtkBuildable*> (gobject_);
    }

  private:
  public:
    auto
    get_buildable_id () const -> Glib::ustring;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkBuildable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Buildable>;

} // namespace Glib

#endif
