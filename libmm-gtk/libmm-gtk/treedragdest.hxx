// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEDRAGDEST_H
#define _GTKMM_TREEDRAGDEST_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/value.hxx>
#include <libmm-gtk/treemodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreeDragDestIface GtkTreeDragDestIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkTreeDragDest = struct _GtkTreeDragDest;
using GtkTreeDragDestClass = struct _GtkTreeDragDestClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API TreeDragDest_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeDragDest : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TreeDragDest;
    using CppClassType = TreeDragDest_Class;
    using BaseObjectType = GtkTreeDragDest;
    using BaseClassType = GtkTreeDragDestIface;

    TreeDragDest (const TreeDragDest&) = delete;
    auto
    operator= (const TreeDragDest&) -> TreeDragDest& = delete;

  private:
    friend class TreeDragDest_Class;
    static CppClassType treedragdest_class_;

#endif
  protected:
    TreeDragDest ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit TreeDragDest (const Glib::Interface_Class& interface_class);

  public:
    explicit TreeDragDest (GtkTreeDragDest* castitem);

  protected:
#endif

  public:
    TreeDragDest (TreeDragDest&& src) noexcept;
    auto
    operator= (TreeDragDest&& src) noexcept -> TreeDragDest&;

    ~TreeDragDest () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkTreeDragDest*
    {
      return reinterpret_cast<GtkTreeDragDest*> (gobject_);
    }

    auto
    gobj () const -> const GtkTreeDragDest*
    {
      return reinterpret_cast<GtkTreeDragDest*> (gobject_);
    }

  private:
  public:
    auto
    drag_data_received (const TreeModel::Path& dest,
                        const Glib::ValueBase& value) -> bool;

    auto
    row_drop_possible (const TreeModel::Path& dest_path,
                       const Glib::ValueBase& value) const -> bool;

  protected:
    virtual auto
    drag_data_received_vfunc (const TreeModel::Path& dest,
                              const Glib::ValueBase& value) -> bool;

    virtual auto
    row_drop_possible_vfunc (const TreeModel::Path& dest,
                             const Glib::ValueBase& value) const -> bool;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeDragDest* object, bool take_copy = false) -> Glib::RefPtr<Gtk::TreeDragDest>;

} // namespace Glib

#endif
