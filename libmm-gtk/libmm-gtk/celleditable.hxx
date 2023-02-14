
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
  class GTKMM_API CellEditable_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CellEditable : public Glib::Interface
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

    static void
    add_interface (GType gtype_implementer);

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
    void
    start_editing (const Glib::RefPtr<const Gdk::Event>& event);

    void
    editing_done ();

    void
    remove_widget ();

    auto
    signal_editing_done () -> Glib::SignalProxy<void ()>;

    auto
    signal_remove_widget () -> Glib::SignalProxy<void ()>;

    auto
    property_editing_canceled () -> Glib::PropertyProxy<bool>;

    auto
    property_editing_canceled () const -> Glib::PropertyProxy_ReadOnly<bool>;

  protected:
    virtual void
    start_editing_vfunc (const Glib::RefPtr<const Gdk::Event>& event);

  public:
  public:
  protected:
    virtual void
    on_editing_done ();

    virtual void
    on_remove_widget ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellEditable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CellEditable>;

} // namespace Glib

#endif
