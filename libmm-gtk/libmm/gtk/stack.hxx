// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STACK_H
#define _GTKMM_STACK_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/selectionmodel.hxx>
#include <libmm/gtk/stackpage.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStack = struct _GtkStack;
using GtkStackClass = struct _GtkStackClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Stack_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Stack : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class Stack_Class;
    static CppClassType stack_class_;

  protected:
    explicit Stack (const glib::ConstructParams& construct_params);
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
    add (Widget& child) -> glib::RefPtr<StackPage>;

    auto
    add (Widget& child, const glib::ustring& name) -> glib::RefPtr<StackPage>;

    auto
    add (Widget& child, const glib::ustring& name, const glib::ustring& title)
        -> glib::RefPtr<StackPage>;

    auto
    remove (Widget& child) -> void;

    auto
    get_page (Widget& child) -> glib::RefPtr<StackPage>;

    auto
    get_page (const Widget& child) const -> glib::RefPtr<const StackPage>;

    auto
    set_visible_child (Widget& child) -> void;

    auto
    get_visible_child () -> Widget*;

    auto
    get_visible_child () const -> const Widget*;

    auto
    set_visible_child (const glib::ustring& name) -> void;

    auto
    set_visible_child (const glib::ustring& name,
                       StackTransitionType transition) -> void;

    auto
    get_visible_child_name () const -> glib::ustring;

    auto
    set_hhomogeneous (bool hhomogeneous = true) -> void;

    auto
    get_hhomogeneous () const -> bool;

    auto
    set_vhomogeneous (bool vhomogeneous = true) -> void;

    auto
    get_vhomogeneous () const -> bool;

    auto
    set_transition_duration (guint duration) -> void;

    auto
    get_transition_duration () const -> guint;

    auto
    set_transition_type (StackTransitionType transition) -> void;

    auto
    get_transition_type () const -> StackTransitionType;

    auto
    get_transition_running () const -> bool;

    auto
    get_child_by_name (const glib::ustring& name) -> Widget*;

    auto
    get_child_by_name (const glib::ustring& name) const -> const Widget*;

    auto
    set_interpolate_size (bool interpolate_size) -> void;

    auto
    get_interpolate_size () const -> bool;

    auto
    get_pages () -> glib::RefPtr<SelectionModel>;

    auto
    get_pages () const -> glib::RefPtr<const SelectionModel>;

    auto
    property_hhomogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_hhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_duration () -> glib::PropertyProxy<unsigned int>;

    auto
    property_transition_duration () const
        -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_transition_running () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transition_type () -> glib::PropertyProxy<StackTransitionType>;

    auto
    property_transition_type () const
        -> glib::PropertyProxy_ReadOnly<StackTransitionType>;

    auto
    property_vhomogeneous () -> glib::PropertyProxy<bool>;

    auto
    property_vhomogeneous () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_visible_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_visible_child_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_visible_child_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_interpolate_size () -> glib::PropertyProxy<bool>;

    auto
    property_interpolate_size () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_pages () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStack* object, bool take_copy = false) -> gtk::Stack*;
} // namespace glib

#endif
