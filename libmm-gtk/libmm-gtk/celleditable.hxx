// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLEDITABLE_H
#define _GTKMM_CELLEDITABLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/event.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkCellEditableIface GtkCellEditableIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellEditable = struct _GtkCellEditable;
using GtkCellEditableClass = struct _GtkCellEditableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT CellEditable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CellEditable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CellEditable;
    using CppClassType = CellEditable_Class;
    using BaseObjectType = GtkCellEditable;
    using BaseClassType = GtkCellEditableIface;

    CellEditable (const CellEditable&) = delete;
    auto
    operator= (const CellEditable&) -> CellEditable& = delete;

  private:
    friend class CellEditable_Class;
    static CppClassType celleditable_class_;

#endif
  protected:
    CellEditable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit CellEditable (const Glib::Interface_Class& interface_class);

  public:
    explicit CellEditable (GtkCellEditable* castitem);

  protected:
#endif

  public:
    CellEditable (CellEditable&& src) noexcept;
    auto
    operator= (CellEditable&& src) noexcept -> CellEditable&;

    ~CellEditable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCellEditable*
    {
      return reinterpret_cast<GtkCellEditable*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellEditable*
    {
      return reinterpret_cast<GtkCellEditable*> (gobject_);
    }

  private:
  public:
#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    start_editing (const Glib::RefPtr<const Gdk::Event>& event) -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    editing_done () -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    remove_widget () -> void;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    signal_editing_done () -> Glib::SignalProxy<void ()>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    signal_remove_widget () -> Glib::SignalProxy<void ()>;
#endif

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    property_editing_canceled () -> Glib::PropertyProxy<bool>;

    auto
    property_editing_canceled () const -> Glib::PropertyProxy_ReadOnly<bool>;

#endif

  protected:
    virtual auto
    start_editing_vfunc (const Glib::RefPtr<const Gdk::Event>& event) -> void;

  public:
  public:
  protected:
    virtual auto
    on_editing_done () -> void;

    virtual auto
    on_remove_widget () -> void;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellEditable>;

} // namespace Glib

#endif
