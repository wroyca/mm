// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREELISTROW_H
#define _GTKMM_TREELISTROW_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT TreeListRow_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeListRow : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeListRow;
    using CppClassType = TreeListRow_Class;
    using BaseObjectType = GtkTreeListRow;
    using BaseClassType = GtkTreeListRowClass;

    TreeListRow (const TreeListRow&) = delete;
    auto
    operator= (const TreeListRow&) -> TreeListRow& = delete;

  private:
    friend class TreeListRow_Class;
    static CppClassType treelistrow_class_;

  protected:
    explicit TreeListRow (const Glib::ConstructParams& construct_params);
    explicit TreeListRow (GtkTreeListRow* castitem);

#endif

  public:
    TreeListRow (TreeListRow&& src) noexcept;
    auto
    operator= (TreeListRow&& src) noexcept -> TreeListRow&;

    ~TreeListRow () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeListRow*
    {
      return reinterpret_cast<GtkTreeListRow*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeListRow*
    {
      return reinterpret_cast<GtkTreeListRow*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeListRow*;

  private:
  public:
    auto
    get_item () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_item () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    set_expanded (bool expanded = true) -> void;

    auto
    get_expanded () const -> bool;

    auto
    is_expandable () const -> bool;

    auto
    get_position () const -> guint;

    auto
    get_depth () const -> guint;

    auto
    get_children () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_children () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    get_parent () -> Glib::RefPtr<TreeListRow>;

    auto
    get_parent () const -> Glib::RefPtr<const TreeListRow>;

    auto
    get_child_row (guint position) -> Glib::RefPtr<TreeListRow>;

    auto
    get_child_row (guint position) const -> Glib::RefPtr<const TreeListRow>;

    auto
    property_children () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_depth () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_expandable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expanded () -> Glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeListRow* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeListRow>;
} // namespace Glib

#endif
