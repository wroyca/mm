// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEEXPANDER_H
#define _GTKMM_TREEEXPANDER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/treelistrow.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TreeExpander_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeExpander : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef TreeExpander CppObjectType;
    typedef TreeExpander_Class CppClassType;
    typedef GtkTreeExpander BaseObjectType;
    typedef GtkTreeExpanderClass BaseClassType;
#endif

    TreeExpander (TreeExpander&& src) noexcept;
    auto
    operator= (TreeExpander&& src) noexcept -> TreeExpander&;

    TreeExpander (const TreeExpander&) = delete;
    auto
    operator= (const TreeExpander&) -> TreeExpander& = delete;

    ~TreeExpander () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class TreeExpander_Class;
    static CppClassType treeexpander_class_;

  protected:
    explicit TreeExpander (const glib::ConstructParams& construct_params);
    explicit TreeExpander (GtkTreeExpander* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeExpander*
    {
      return reinterpret_cast<GtkTreeExpander*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeExpander*
    {
      return reinterpret_cast<GtkTreeExpander*> (gobject_);
    }

  private:
  public:
    TreeExpander ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    set_child (Widget& widget) -> void;

    auto
    unset_child () -> void;

    auto
    get_item () -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_item () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    get_list_row () -> glib::RefPtr<TreeListRow>;

    auto
    get_list_row () const -> glib::RefPtr<const TreeListRow>;

    auto
    set_list_row (const glib::RefPtr<TreeListRow>& list_row) -> void;

    auto
    unset_list_row () -> void;

    auto
    get_indent_for_depth () const -> bool;

    auto
    set_indent_for_depth (bool indent_for_depth = true) -> void;

    auto
    get_indent_for_icon () const -> bool;

    auto
    set_indent_for_icon (bool indent_for_icon = true) -> void;

    auto
    get_hide_expander () const -> bool;

    auto
    set_hide_expander (bool hide_expander = true) -> void;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_hide_expander () -> glib::PropertyProxy<bool>;

    auto
    property_hide_expander () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indent_for_depth () -> glib::PropertyProxy<bool>;

    auto
    property_indent_for_depth () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indent_for_icon () -> glib::PropertyProxy<bool>;

    auto
    property_indent_for_icon () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_list_row () -> glib::PropertyProxy<glib::RefPtr<TreeListRow>>;

    auto
    property_list_row () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TreeListRow>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeExpander* object, bool take_copy = false) -> gtk::TreeExpander*;
} // namespace glib

#endif
