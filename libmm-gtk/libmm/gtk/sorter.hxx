// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SORTER_H
#define _GTKMM_SORTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSorter = struct _GtkSorter;
using GtkSorterClass = struct _GtkSorterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Sorter_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Sorter : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Sorter;
    using CppClassType = Sorter_Class;
    using BaseObjectType = GtkSorter;
    using BaseClassType = GtkSorterClass;

    Sorter (const Sorter&) = delete;
    auto
    operator= (const Sorter&) -> Sorter& = delete;

  private:
    friend class Sorter_Class;
    static CppClassType sorter_class_;

  protected:
    explicit Sorter (const glib::ConstructParams& construct_params);
    explicit Sorter (GtkSorter* castitem);

#endif

  public:
    Sorter (Sorter&& src) noexcept;
    auto
    operator= (Sorter&& src) noexcept -> Sorter&;

    ~Sorter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSorter*
    {
      return reinterpret_cast<GtkSorter*> (gobject_);
    }

    auto
    gobj () const -> const GtkSorter*
    {
      return reinterpret_cast<GtkSorter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSorter*;

  private:
  protected:
    Sorter ();

  public:
    enum class Order
    {
      PARTIAL,
      NONE,
      TOTAL
    };

    enum class Change
    {
      DIFFERENT,
      INVERTED,
      LESS_STRICT,
      MORE_STRICT
    };

    auto
    compare (gpointer item1, gpointer item2) -> Ordering;

    auto
    get_order () const -> Order;

    auto
    changed (Change change) -> void;

    auto
    signal_changed () -> glib::SignalProxy<void (Change)>;

  protected:
    virtual auto
    compare_vfunc (gpointer item1, gpointer item2) -> Ordering;

    virtual auto
    get_order_vfunc () -> Order;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Sorter::Order>
    : public glib::Value_Enum<gtk::Sorter::Order>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Sorter::Change>
    : public glib::Value_Enum<gtk::Sorter::Change>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSorter* object, bool take_copy = false) -> glib::RefPtr<gtk::Sorter>;
} // namespace glib

#endif
