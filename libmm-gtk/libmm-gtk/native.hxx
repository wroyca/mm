// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NATIVE_H
#define _GTKMM_NATIVE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkNativeInterface GtkNativeInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNative = struct _GtkNative;
using GtkNativeClass = struct _GtkNativeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Native_Class;
}
#endif

namespace Gdk
{
  class LIBMM_GTK_SYMEXPORT Surface;
}

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT Native : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Native;
    using CppClassType = Native_Class;
    using BaseObjectType = GtkNative;
    using BaseClassType = GtkNativeInterface;

    Native (const Native&) = delete;
    auto
    operator= (const Native&) -> Native& = delete;

  private:
    friend class Native_Class;
    static CppClassType native_class_;

#endif
  protected:
    Native ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Native (const Glib::Interface_Class& interface_class);

  public:
    explicit Native (GtkNative* castitem);

  protected:
#endif

  public:
    Native (Native&& src) noexcept;
    auto
    operator= (Native&& src) noexcept -> Native&;

    ~Native () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNative*
    {
      return reinterpret_cast<GtkNative*> (gobject_);
    }

    auto
    gobj () const -> const GtkNative*
    {
      return reinterpret_cast<GtkNative*> (gobject_);
    }

  private:
  public:
    auto
    realize () -> void;

    auto
    unrealize () -> void;

    static auto
    get_for_surface (const Glib::RefPtr<const Gdk::Surface>& surface)
        -> Native*;

    auto
    get_surface () -> Glib::RefPtr<Gdk::Surface>;

    auto
    get_surface () const -> Glib::RefPtr<const Gdk::Surface>;

    auto
    get_surface_transform (double& x, double& y) -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNative* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Native>;

} // namespace Glib

#endif
