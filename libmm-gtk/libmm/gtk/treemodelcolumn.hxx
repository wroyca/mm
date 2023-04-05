// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TREEMODELCOLUMN_H
#define _GTKMM_TREEMODELCOLUMN_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <glib-object.h>
  #include <libmm/glib/value.hxx>
  #include <libmm/gtk/mm-gtkconfig.hxx>
  #include <vector>

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT TreeModelColumnBase;

  class TreeModelColumnRecord
  {
  public:
    LIBMM_GTK_SYMEXPORT
    TreeModelColumnRecord ();
    LIBMM_GTK_SYMEXPORT virtual ~TreeModelColumnRecord () noexcept;

    LIBMM_GTK_SYMEXPORT auto
    add (TreeModelColumnBase& column) -> void;

    LIBMM_GTK_SYMEXPORT auto
    size () const -> unsigned int;
    LIBMM_GTK_SYMEXPORT auto
    types () const -> const GType*;

  private:
    std::vector<GType> column_types_;

    LIBMM_GTK_SYMEXPORT
    TreeModelColumnRecord (const TreeModelColumnRecord&);
    LIBMM_GTK_SYMEXPORT auto
    operator= (const TreeModelColumnRecord&) -> TreeModelColumnRecord&;
  };

  class LIBMM_GTK_SYMEXPORT TreeModelColumnBase
  {
  public:
    auto
    type () const -> GType
    {
      return type_;
    }

    auto
    index () const -> int
    {
      return index_;
    }

  protected:
    explicit TreeModelColumnBase (GType g_type);

  private:
    GType type_;
    int index_;

    friend class gtk::TreeModelColumnRecord;
  };

  inline auto
  operator== (const TreeModelColumnBase& lhs, const TreeModelColumnBase& rhs) -> bool
  {
    return (lhs.index () == rhs.index ());
  }

  inline auto
  operator!= (const TreeModelColumnBase& lhs, const TreeModelColumnBase& rhs) -> bool
  {
    return (lhs.index () != rhs.index ());
  }

  template <class T>
  class TreeModelColumn : public TreeModelColumnBase
  {
  public:
    typedef T ElementType;
    typedef glib::Value<T> ValueType;

    TreeModelColumn ()
      : TreeModelColumnBase (ValueType::value_type ())
    {
    }
  };

} // namespace gtk

#endif

#endif
