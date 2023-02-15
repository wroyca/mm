// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEPATH_H
#define _GTKMM_TREEPATH_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gdk/contentprovider.hxx>
  #include <libmm-gtk/treemodel.hxx>

  #ifdef GLIBMM_HAVE_SUN_REVERSE_ITERATOR
    #include <cstddef>
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkTreePath GtkTreePath;
}
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT TreePath
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = TreePath;
    using BaseObjectType = GtkTreePath;
  #endif

    static auto
    get_type () -> GType G_GNUC_CONST;

    TreePath ();

    TreePath (const TreePath& other);
    auto
    operator= (const TreePath& other) -> TreePath&;

    TreePath (TreePath&& other) noexcept;
    auto
    operator= (TreePath&& other) noexcept -> TreePath&;

    ~TreePath () noexcept;

    auto
    swap (TreePath& other) noexcept -> void;

    auto
    gobj () -> GtkTreePath*
    {
      return gobject_;
    }

    auto
    gobj () const -> const GtkTreePath*
    {
      return gobject_;
    }

    auto
    gobj_copy () const -> GtkTreePath*;

  protected:
    GtkTreePath* gobject_;

  private:
  public:
    typedef unsigned int size_type;
    typedef int difference_type;

    typedef int value_type;
    typedef int& reference;
    typedef const int& const_reference;

    typedef int* iterator;
    typedef const int* const_iterator;

  #ifndef GLIBMM_HAVE_SUN_REVERSE_ITERATOR

    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  #else

    typedef std::reverse_iterator<iterator,
                                  std::random_access_iterator_tag,
                                  int,
                                  int&,
                                  int*,
                                  std::ptrdiff_t>
        reverse_iterator;

    typedef std::reverse_iterator<const_iterator,
                                  std::random_access_iterator_tag,
                                  int,
                                  const int&,
                                  const int*,
                                  std::ptrdiff_t>
        const_reverse_iterator;

  #endif

    explicit TreePath (GtkTreePath* gobject, bool make_a_copy = true);
    explicit TreePath (size_type n, value_type value = 0);
    explicit TreePath (const Glib::ustring& path);
    explicit TreePath (const TreeModel::iterator& iter);

    template <class In>
    inline TreePath (In pbegin, In pend);

    auto
    clear () -> void;

    auto
    operator= (const TreeModel::iterator& iter) -> TreePath&;

    explicit operator bool () const;

    template <class In>
    inline auto
    assign (In pbegin, In pend) -> void;
    template <class In>
    auto
    append (In pbegin, In pend) -> void;

    auto
    push_back (int index) -> void;

    auto
    push_front (int index) -> void;

    auto
    size () const -> size_type;
    auto
    empty () const -> bool;

    auto
    operator[] (size_type i) -> reference;
    auto
    operator[] (size_type i) const -> const_reference;

    auto
    begin () -> iterator;
    auto
    end () -> iterator;
    auto
    begin () const -> const_iterator;
    auto
    end () const -> const_iterator;

    auto
    rbegin () -> reverse_iterator
    {
      return reverse_iterator (end ());
    }

    auto
    rend () -> reverse_iterator
    {
      return reverse_iterator (begin ());
    }

    auto
    rbegin () const -> const_reverse_iterator
    {
      return const_reverse_iterator (end ());
    }

    auto
    rend () const -> const_reverse_iterator
    {
      return const_reverse_iterator (begin ());
    }

    auto
    front () -> reference
    {
      return *begin ();
    }

    auto
    front () const -> const_reference
    {
      return *begin ();
    }

    auto
    back () -> reference
    {
      return *rbegin ();
    }

    auto
    back () const -> const_reference
    {
      return *rbegin ();
    }

    auto
    next () -> void;

    auto
    prev () -> bool;

    auto
    up () -> bool;

    auto
    down () -> void;

    auto
    is_ancestor (const TreePath& descendant) const -> bool;

    auto
    is_descendant (const TreePath& ancestor) const -> bool;

    auto
    to_string () const -> Glib::ustring;

    static auto
    get_row_drag_data (const Glib::ValueBase& value,
                       Glib::RefPtr<const TreeModel>& model,
                       TreePath& path) -> bool;

    static auto
    get_row_drag_data (const Glib::ValueBase& value, TreePath& path) -> bool;

    auto
    create_row_drag_content (const Glib::RefPtr<const TreeModel>& model) const
        -> Glib::RefPtr<Gdk::ContentProvider>;
  };

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  template <class In>
  auto
  TreePath::append (In pbegin, In pend) -> void
  {
    for (; pbegin != pend; ++pbegin)
      this->push_back (*pbegin);
  }

  template <class In>
  inline TreePath::TreePath (In pbegin, In pend)
  {
    this->append (pbegin, pend);
  }

  template <class In>
  inline auto
  TreePath::assign (In pbegin, In pend) -> void
  {
    TreePath temp (pbegin, pend);
    this->swap (temp);
  }

  struct TreePathTraits
  {
    typedef TreePath CppType;
    typedef const GtkTreePath* CType;
    typedef GtkTreePath* CTypeNonConst;

    static auto
    to_c_type (const CppType& item) -> CType
    {
      return item.gobj ();
    }

    static auto
    to_c_type (CType item) -> CType
    {
      return item;
    }

    static auto
    to_cpp_type (CType item) -> CppType
    {
      return CppType (const_cast<CTypeNonConst> (item));
    }

    G_GNUC_BEGIN_IGNORE_DEPRECATIONS
    static auto
    release_c_type (CType item) -> void
    {
      gtk_tree_path_free (const_cast<CTypeNonConst> (item));
    }

    G_GNUC_END_IGNORE_DEPRECATIONS
  };

  #endif

} // namespace Gtk

namespace Gtk
{
  LIBMM_GTK_SYMEXPORT auto
  operator== (const TreePath& lhs, const TreePath& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator!= (const TreePath& lhs, const TreePath& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator<(const TreePath& lhs, const TreePath& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator> (const TreePath& lhs, const TreePath& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator<= (const TreePath& lhs, const TreePath& rhs) -> bool;

  LIBMM_GTK_SYMEXPORT auto
  operator>= (const TreePath& lhs, const TreePath& rhs) -> bool;

} // namespace Gtk

namespace Gtk
{

  inline auto
  swap (TreePath& lhs, TreePath& rhs) noexcept -> void
  {
    lhs.swap (rhs);
  }

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkTreePath* object, bool take_copy = false) -> Gtk::TreePath;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::TreePath> : public Glib::Value_Boxed<Gtk::TreePath>
  {
  };
  #endif

} // namespace Glib

#endif

#endif
