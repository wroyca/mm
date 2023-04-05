// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEDRAGSOURCE_H
#define _GTKMM_TREEDRAGSOURCE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gdk/contentprovider.hxx>
  #include <libmm/glib/interface.hxx>
  #include <libmm/gtk/treemodel.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreeDragSourceIface GtkTreeDragSourceIface;
}
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeDragSource = struct _GtkTreeDragSource;
using GtkTreeDragSourceClass = struct _GtkTreeDragSourceClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT TreeDragSource_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeDragSource : public glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeDragSource;
    using CppClassType = TreeDragSource_Class;
    using BaseObjectType = GtkTreeDragSource;
    using BaseClassType = GtkTreeDragSourceIface;

    TreeDragSource (const TreeDragSource&) = delete;
    auto
    operator= (const TreeDragSource&) -> TreeDragSource& = delete;

  private:
    friend class TreeDragSource_Class;
    static CppClassType treedragsource_class_;

  #endif
  protected:
    TreeDragSource ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeDragSource (const glib::Interface_Class& interface_class);

  public:
    explicit TreeDragSource (GtkTreeDragSource* castitem);

  protected:
  #endif

  public:
    TreeDragSource (TreeDragSource&& src) noexcept;
    auto
    operator= (TreeDragSource&& src) noexcept -> TreeDragSource&;

    ~TreeDragSource () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkTreeDragSource*
    {
      return reinterpret_cast<GtkTreeDragSource*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeDragSource*
    {
      return reinterpret_cast<GtkTreeDragSource*> (gobject_);
    }

  private:
  public:
    auto
    row_draggable (const TreeModel::Path& path) const -> bool;

    auto
    drag_data_get (const TreeModel::Path& path) const
        -> glib::RefPtr<gdk::ContentProvider>;

    auto
    drag_data_delete (const TreeModel::Path& path) -> bool;

  protected:
    virtual auto
    row_draggable_vfunc (const TreeModel::Path& path) const -> bool;

    virtual auto
    drag_data_get_vfunc (const TreeModel::Path& path) const
        -> glib::RefPtr<gdk::ContentProvider>;

    virtual auto
    drag_data_delete_vfunc (const TreeModel::Path& path) -> bool;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeDragSource* object, bool take_copy = false) -> glib::RefPtr<gtk::TreeDragSource>;

} // namespace glib

#endif

#endif
