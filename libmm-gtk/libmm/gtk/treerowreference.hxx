// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEROWREFERENCE_H
#define _GTKMM_TREEROWREFERENCE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/treemodel.hxx>
  #include <libmm/gtk/treepath.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreeRowReference GtkTreeRowReference;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreeRowReference
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

    auto
    swap (TreeRowReference& other) noexcept -> void;

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

  inline auto
  swap (TreeRowReference& lhs, TreeRowReference& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreeRowReference* object, bool take_copy = false) -> Gtk::TreeRowReference;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TreeRowReference>
    : public Glib::Value_Boxed<Gtk::TreeRowReference>
  {
  };
  #endif

} // namespace Glib

#endif

#endif
