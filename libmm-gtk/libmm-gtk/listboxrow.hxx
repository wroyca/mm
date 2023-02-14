
#ifndef _GTKMM_LISTBOXROW_H
#define _GTKMM_LISTBOXROW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/actionable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBoxRow = struct _GtkListBoxRow;
using GtkListBoxRowClass = struct _GtkListBoxRowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ListBoxRow_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ListBoxRow : public Widget,
                               public Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ListBoxRow CppObjectType;
    typedef ListBoxRow_Class CppClassType;
    typedef GtkListBoxRow BaseObjectType;
    typedef GtkListBoxRowClass BaseClassType;
#endif

    ListBoxRow (ListBoxRow&& src) noexcept;
    auto
    operator= (ListBoxRow&& src) noexcept -> ListBoxRow&;

    ListBoxRow (const ListBoxRow&) = delete;
    auto
    operator= (const ListBoxRow&) -> ListBoxRow& = delete;

    ~ListBoxRow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ListBoxRow_Class;
    static CppClassType listboxrow_class_;

  protected:
    explicit ListBoxRow (const Glib::ConstructParams& construct_params);
    explicit ListBoxRow (GtkListBoxRow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListBoxRow*
    {
      return reinterpret_cast<GtkListBoxRow*> (gobject_);
    }

    auto
    gobj () const -> const GtkListBoxRow*
    {
      return reinterpret_cast<GtkListBoxRow*> (gobject_);
    }

  private:
  public:
    ListBoxRow ();

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    void
    set_header (Widget& header);

    void
    unset_header ();

    auto
    get_header () -> Widget*;

    auto
    get_header () const -> const Widget*;

    auto
    get_index () const -> int;

    void
    changed ();

    auto
    is_selected () const -> bool;

    void
    set_selectable (bool selectable = true);

    auto
    get_selectable () const -> bool;

    void
    set_activatable (bool activatable = true);

    auto
    get_activatable () const -> bool;

    auto
    property_selectable () -> Glib::PropertyProxy<bool>;

    auto
    property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkListBoxRow* object, bool take_copy = false) -> Gtk::ListBoxRow*;
} // namespace Glib

#endif
