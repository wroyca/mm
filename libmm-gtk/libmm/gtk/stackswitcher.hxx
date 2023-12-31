// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STACKSWITCHER_H
#define _GTKMM_STACKSWITCHER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/stack.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackSwitcher = struct _GtkStackSwitcher;
using GtkStackSwitcherClass = struct _GtkStackSwitcherClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StackSwitcher_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StackSwitcher : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef StackSwitcher CppObjectType;
    typedef StackSwitcher_Class CppClassType;
    typedef GtkStackSwitcher BaseObjectType;
    typedef GtkStackSwitcherClass BaseClassType;
#endif

    StackSwitcher (StackSwitcher&& src) noexcept;
    auto
    operator= (StackSwitcher&& src) noexcept -> StackSwitcher&;

    StackSwitcher (const StackSwitcher&) = delete;
    auto
    operator= (const StackSwitcher&) -> StackSwitcher& = delete;

    ~StackSwitcher () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class StackSwitcher_Class;
    static CppClassType stackswitcher_class_;

  protected:
    explicit StackSwitcher (const glib::ConstructParams& construct_params);
    explicit StackSwitcher (GtkStackSwitcher* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStackSwitcher*
    {
      return reinterpret_cast<GtkStackSwitcher*> (gobject_);
    }

    auto
    gobj () const -> const GtkStackSwitcher*
    {
      return reinterpret_cast<GtkStackSwitcher*> (gobject_);
    }

  private:
  public:
    StackSwitcher ();

    auto
    set_stack (Stack& stack) -> void;

    auto
    unset_stack () -> void;

    auto
    get_stack () -> Stack*;

    auto
    get_stack () const -> const Stack*;

    auto
    property_stack () -> glib::PropertyProxy<Stack*>;

    auto
    property_stack () const -> glib::PropertyProxy_ReadOnly<Stack*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStackSwitcher* object, bool take_copy = false) -> gtk::StackSwitcher*;
} // namespace glib

#endif
