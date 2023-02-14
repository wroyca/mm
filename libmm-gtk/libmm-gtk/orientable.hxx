// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ORIENTABLE_H
#define _GTKMM_ORIENTABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>
#include <libmm-gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkOrientableIface GtkOrientableIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkOrientable = struct _GtkOrientable;
using GtkOrientableClass = struct _GtkOrientableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Orientable_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Orientable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Orientable;
    using CppClassType = Orientable_Class;
    using BaseObjectType = GtkOrientable;
    using BaseClassType = GtkOrientableIface;

    Orientable (const Orientable&) = delete;
    auto
    operator= (const Orientable&) -> Orientable& = delete;

  private:
    friend class Orientable_Class;
    static CppClassType orientable_class_;

#endif
  protected:
    Orientable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Orientable (const Glib::Interface_Class& interface_class);

  public:
    explicit Orientable (GtkOrientable* castitem);

  protected:
#endif

  public:
    Orientable (Orientable&& src) noexcept;
    auto
    operator= (Orientable&& src) noexcept -> Orientable&;

    ~Orientable () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkOrientable*
    {
      return reinterpret_cast<GtkOrientable*> (gobject_);
    }

    auto
    gobj () const -> const GtkOrientable*
    {
      return reinterpret_cast<GtkOrientable*> (gobject_);
    }

  private:
  public:
    void
    set_orientation (Orientation orientation);

    auto
    get_orientation () const -> Orientation;

    auto
    property_orientation () -> Glib::PropertyProxy<Orientation>;

    auto
    property_orientation () const -> Glib::PropertyProxy_ReadOnly<Orientation>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkOrientable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Orientable>;

} // namespace Glib

#endif
