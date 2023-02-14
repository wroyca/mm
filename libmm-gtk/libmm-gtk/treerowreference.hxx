// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEROWREFERENCE_H
#define _GTKMM_TREEROWREFERENCE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/treemodel.hxx>
#include <libmm-gtk/treepath.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreeRowReference GtkTreeRowReference;
}
#endif

namespace Gtk
{

  class GTKMM_API TreeRowReference
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreeRowReference;
    using BaseObjectType = GtkTreeRowReference;
#endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    TreeRowReference ();

    explicit TreeRowReference (GtkTreeRowReference* gobject,
                               bool make_a_copy = true);

    TreeRowReference (const TreeRowReference& other);
    auto
    operator= (const TreeRowReference& other) -> TreeRowReference&;

    TreeRowReference (TreeRowReference&& other) noexcept;
    auto
    operator= (TreeRowReference&& other) noexcept -> TreeRowReference&;

    ~TreeRowReference () noexcept;

    void
    swap (TreeRowReference& other) noexcept;

    auto
    gobj () -> GtkTreeRowReference*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GtkTreeRowReference*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GtkTreeRowReference*;

  protected:
    GtkTreeRowReference* gobject_;

  private:
  public:
    TreeRowReference (const Glib::RefPtr<TreeModel>& model,
                      const TreeModel::Path& path);

    explicit operator bool () const;

    auto
    get_path () const -> TreeModel::Path;

    auto
    get_model () -> Glib::RefPtr<TreeModel>;

    auto
    get_model () const -> Glib::RefPtr<const TreeModel>;

    auto
    is_valid () const -> bool;
  };

} // namespace Gtk

namespace Gtk
{

  inline void
  swap (TreeRowReference& lhs, TreeRowReference& rhs) noexcept
  {
    lhs.swap (rhs);
  }

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkTreeRowReference* object, bool take_copy = false) -> Gtk::TreeRowReference;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class GTKMM_API Value<Gtk::TreeRowReference>
    : public Glib::Value_Boxed<Gtk::TreeRowReference>
  {
  };
#endif

} // namespace Glib

#endif
