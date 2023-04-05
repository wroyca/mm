// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREELISTROW_H
#define _GTKMM_TREELISTROW_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TreeListRow_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeListRow : public glib::Object
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
    explicit TreeListRow (const glib::ConstructParams& construct_params);
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
    get_item () -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_item () const -> glib::RefPtr<const glib::ObjectBase>;

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
    get_children () -> glib::RefPtr<gio::ListModel>;

    auto
    get_children () const -> glib::RefPtr<const gio::ListModel>;

    auto
    get_parent () -> glib::RefPtr<TreeListRow>;

    auto
    get_parent () const -> glib::RefPtr<const TreeListRow>;

    auto
    get_child_row (guint position) -> glib::RefPtr<TreeListRow>;

    auto
    get_child_row (guint position) const -> glib::RefPtr<const TreeListRow>;

    auto
    property_children () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_depth () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_expandable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expanded () -> glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeListRow* object, bool take_copy = false) -> glib::RefPtr<gtk::TreeListRow>;
} // namespace glib

#endif
