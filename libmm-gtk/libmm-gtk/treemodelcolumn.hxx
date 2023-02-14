#ifndef _GTKMM_TREEMODELCOLUMN_H
#define _GTKMM_TREEMODELCOLUMN_H

#include <glib-object.h>
#include <libmm-glib/value.hxx>
#include <libmm-gtk/mm-gtkconfig.hxx>
#include <vector>

namespace Gtk
{

  class GTKMM_API TreeModelColumnBase;

  class TreeModelColumnRecord
  {
  public:
    GTKMM_API
    TreeModelColumnRecord ();
    GTKMM_API virtual ~TreeModelColumnRecord () noexcept;

    GTKMM_API void
    add (TreeModelColumnBase& column);

    GTKMM_API auto
    size () const -> unsigned int;
    GTKMM_API auto
    types () const -> const GType*;

  private:
    std::vector<GType> column_types_;

    GTKMM_API
    TreeModelColumnRecord (const TreeModelColumnRecord&);
    GTKMM_API auto
    operator= (const TreeModelColumnRecord&) -> TreeModelColumnRecord&;
  };

  class GTKMM_API TreeModelColumnBase
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

    friend class Gtk::TreeModelColumnRecord;
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
    typedef Glib::Value<T> ValueType;

    TreeModelColumn ()
      : TreeModelColumnBase (ValueType::value_type ())
    {
    }
  };

} // namespace Gtk

#endif
