// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STACKSIDEBAR_H
#define _GTKMM_STACKSIDEBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/stack.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackSidebar = struct _GtkStackSidebar;
using GtkStackSidebarClass = struct _GtkStackSidebarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT StackSidebar_Class;
}
#endif

namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Stack;

  class LIBMM_GTK_SYMEXPORT StackSidebar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef StackSidebar CppObjectType;
    typedef StackSidebar_Class CppClassType;
    typedef GtkStackSidebar BaseObjectType;
    typedef GtkStackSidebarClass BaseClassType;
#endif

    StackSidebar (StackSidebar&& src) noexcept;
    auto
    operator= (StackSidebar&& src) noexcept -> StackSidebar&;

    StackSidebar (const StackSidebar&) = delete;
    auto
    operator= (const StackSidebar&) -> StackSidebar& = delete;

    ~StackSidebar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class StackSidebar_Class;
    static CppClassType stacksidebar_class_;

  protected:
    explicit StackSidebar (const Glib::ConstructParams& construct_params);
    explicit StackSidebar (GtkStackSidebar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStackSidebar*
    {
      return reinterpret_cast<GtkStackSidebar*> (gobject_);
    }

    auto
    gobj () const -> const GtkStackSidebar*
    {
      return reinterpret_cast<GtkStackSidebar*> (gobject_);
    }

  private:
  public:
    StackSidebar ();

    auto
    set_stack (Stack& stack) -> void;

    auto
    unset_stack () -> void;

    auto
    get_stack () -> Stack*;

    auto
    get_stack () const -> const Stack*;

    auto
    property_stack () -> Glib::PropertyProxy<Stack*>;

    auto
    property_stack () const -> Glib::PropertyProxy_ReadOnly<Stack*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStackSidebar* object, bool take_copy = false) -> Gtk::StackSidebar*;
} // namespace Glib

#endif
