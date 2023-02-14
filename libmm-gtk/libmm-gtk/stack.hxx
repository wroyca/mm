// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STACK_H
#define _GTKMM_STACK_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/selectionmodel.hxx>
#include <libmm-gtk/stackpage.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStack = struct _GtkStack;
using GtkStackClass = struct _GtkStackClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Stack_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Stack : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Stack CppObjectType;
    typedef Stack_Class CppClassType;
    typedef GtkStack BaseObjectType;
    typedef GtkStackClass BaseClassType;
#endif

    Stack (Stack&& src) noexcept;
    auto
    operator= (Stack&& src) noexcept -> Stack&;

    Stack (const Stack&) = delete;
    auto
    operator= (const Stack&) -> Stack& = delete;

    ~Stack () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Stack_Class;
    static CppClassType stack_class_;

  protected:
    explicit Stack (const Glib::ConstructParams& construct_params);
    explicit Stack (GtkStack* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStack*
    {
      return reinterpret_cast<GtkStack*> (gobject_);
    }

    auto
    gobj () const -> const GtkStack*
    {
      return reinterpret_cast<GtkStack*> (gobject_);
    }

  private:
  public:
    Stack ();

    auto
    add (Widget& child) -> Glib::RefPtr<StackPage>;

    auto
    add (Widget& child, const Glib::ustring& name) -> Glib::RefPtr<StackPage>;

    auto
    add (Widget& child, const Glib::ustring& name, const Glib::ustring& title)
        -> Glib::RefPtr<StackPage>;

    void
    remove (Widget& child);

    auto
    get_page (Widget& child) -> Glib::RefPtr<StackPage>;

    auto
    get_page (const Widget& child) const -> Glib::RefPtr<const StackPage>;

    void
    set_visible_child (Widget& child);

    auto
    get_visible_child () -> Widget*;

    auto
    get_visible_child () const -> const Widget*;

    void
    set_visible_child (const Glib::ustring& name);

    void
    set_visible_child (const Glib::ustring& name,
                       StackTransitionType transition);

    auto
    get_visible_child_name () const -> Glib::ustring;

    void
    set_hhomogeneous (bool hhomogeneous = true);

    auto
    get_hhomogeneous () const -> bool;

    void
    set_vhomogeneous (bool vhomogeneous = true);

    auto
    get_vhomogeneous () const -> bool;

    void
    set_transition_duration (guint duration);

    auto
    get_transition_duration () const -> guint;

    void
    set_transition_type (StackTransitionType transition);

    auto
    get_transition_type () const -> StackTransitionType;

    auto
    get_transition_running () const -> bool;

    auto
    get_child_by_name (const Glib::ustring& name) -> Widget*;

    auto
    get_child_by_name (const Glib::ustring& name) const -> const Widget*;

    void
    set_interpolate_size (bool interpolate_size);

    auto
    get_interpolate_size () const -> bool;

    auto
    get_pages () -> Glib::RefPtr<SelectionModel>;

    auto
    get_pages () const -> Glib::RefPtr<const SelectionModel>;

    auto
    property_hhomogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_hhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_duration () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_transition_duration () const
        -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_transition_running () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> Glib::PropertyProxy<StackTransitionType>;

    auto
    property_transition_type () const
        -> Glib::PropertyProxy_ReadOnly<StackTransitionType>;

    auto
    property_vhomogeneous () -> Glib::PropertyProxy<bool>;

    auto
    property_vhomogeneous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_visible_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_visible_child_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_visible_child_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_interpolate_size () -> Glib::PropertyProxy<bool>;

    auto
    property_interpolate_size () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkStack* object, bool take_copy = false) -> Gtk::Stack*;
} // namespace Glib

#endif
