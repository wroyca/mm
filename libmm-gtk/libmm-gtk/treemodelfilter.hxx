// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEMODELFILTER_H
#define _GTKMM_TREEMODELFILTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/treedragsource.hxx>
#include <libmm-gtk/treeiter.hxx>
#include <libmm-gtk/treemodel.hxx>

#include <libmm-gtk/treepath.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeModelFilter = struct _GtkTreeModelFilter;
using GtkTreeModelFilterClass = struct _GtkTreeModelFilterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeModelFilter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeModelFilter : public Glib::Object,
                                    public TreeModel,
                                    public TreeDragSource
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeModelFilter;
    using CppClassType = TreeModelFilter_Class;
    using BaseObjectType = GtkTreeModelFilter;
    using BaseClassType = GtkTreeModelFilterClass;

    TreeModelFilter (const TreeModelFilter&) = delete;
    auto
    operator= (const TreeModelFilter&) -> TreeModelFilter& = delete;

  private:
    friend class TreeModelFilter_Class;
    static CppClassType treemodelfilter_class_;

  protected:
    explicit TreeModelFilter (const Glib::ConstructParams& construct_params);
    explicit TreeModelFilter (GtkTreeModelFilter* castitem);

#endif

  public:
    TreeModelFilter (TreeModelFilter&& src) noexcept;
    auto
    operator= (TreeModelFilter&& src) noexcept -> TreeModelFilter&;

    ~TreeModelFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeModelFilter*
    {
      return reinterpret_cast<GtkTreeModelFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeModelFilter*
    {
      return reinterpret_cast<GtkTreeModelFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkTreeModelFilter*;

  private:
  protected:
    explicit TreeModelFilter (const Glib::RefPtr<TreeModel>& child_model);
    explicit TreeModelFilter (const Glib::RefPtr<TreeModel>& child_model,
                              const TreeModel::Path& virtual_root);

  public:
    static auto
    create (const Glib::RefPtr<TreeModel>& child_model)
        -> Glib::RefPtr<TreeModelFilter>;

    static auto
    create (const Glib::RefPtr<TreeModel>& child_model,
            const TreeModel::Path& virtual_root)
        -> Glib::RefPtr<TreeModelFilter>;

    typedef sigc::slot<bool (const TreeModel::const_iterator&)> SlotVisible;

    void
    set_visible_func (const SlotVisible& slot);

    typedef sigc::slot<
        void (const Gtk::TreeModel::iterator&, Glib::ValueBase&, int)>
        SlotModify;

    void
    set_modify_func (const TreeModelColumnRecord& columns,
                     const SlotModify& slot);

    void
    set_visible_column (const TreeModelColumnBase& column);

    void
    set_visible_column (int column);

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    auto
    convert_child_iter_to_iter (const iterator& child_iter) -> iterator;

    auto
    convert_child_iter_to_iter (const const_iterator& child_iter) const
        -> const_iterator;

    auto
    convert_iter_to_child_iter (const iterator& filter_iter) -> iterator;

    auto
    convert_iter_to_child_iter (const const_iterator& filter_iter) const
        -> const_iterator;

    auto
    convert_child_path_to_path (const Path& child_path) const -> Path;

    auto
    convert_path_to_child_path (const Path& filter_path) const -> Path;

    void
    refilter ();

    void
    clear_cache ();

    auto
    property_child_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TreeModel>>;

    auto
    property_virtual_root () const
        -> Glib::PropertyProxy_ReadOnly<TreeModel::Path>;

  protected:
    void
    set_value_impl (const iterator& row,
                    int column,
                    const Glib::ValueBase& value) override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeModelFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeModelFilter>;
} // namespace Glib

#endif
