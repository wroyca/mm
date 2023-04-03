// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FLOWBOXCHILD_H
#define _GTKMM_FLOWBOXCHILD_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFlowBoxChild = struct _GtkFlowBoxChild;
using GtkFlowBoxChildClass = struct _GtkFlowBoxChildClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT FlowBoxChild_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT FlowBoxChild : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef FlowBoxChild CppObjectType;
    typedef FlowBoxChild_Class CppClassType;
    typedef GtkFlowBoxChild BaseObjectType;
    typedef GtkFlowBoxChildClass BaseClassType;
#endif

    FlowBoxChild (FlowBoxChild&& src) noexcept;
    auto
    operator= (FlowBoxChild&& src) noexcept -> FlowBoxChild&;

    FlowBoxChild (const FlowBoxChild&) = delete;
    auto
    operator= (const FlowBoxChild&) -> FlowBoxChild& = delete;

    ~FlowBoxChild () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class FlowBoxChild_Class;
    static CppClassType flowboxchild_class_;

  protected:
    explicit FlowBoxChild (const Glib::ConstructParams& construct_params);
    explicit FlowBoxChild (GtkFlowBoxChild* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFlowBoxChild*
    {
      return reinterpret_cast<GtkFlowBoxChild*> (gobject_);
    }

    auto
    gobj () const -> const GtkFlowBoxChild*
    {
      return reinterpret_cast<GtkFlowBoxChild*> (gobject_);
    }

  private:
  public:
    FlowBoxChild ();

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    get_index () const -> int;

    auto
    is_selected () const -> bool;

    auto
    changed () -> void;

    auto
    signal_activate () -> Glib::SignalProxy<void ()>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual auto
    on_activate () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFlowBoxChild* object, bool take_copy = false) -> Gtk::FlowBoxChild*;
} // namespace Glib

#endif
