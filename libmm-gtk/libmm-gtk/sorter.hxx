
#ifndef _GTKMM_SORTER_H
#define _GTKMM_SORTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSorter = struct _GtkSorter;
using GtkSorterClass = struct _GtkSorterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Sorter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Sorter : public Glib::Object
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
    explicit Sorter (const Glib::ConstructParams& construct_params);
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

    void
    changed (Change change);

    auto
    signal_changed () -> Glib::SignalProxy<void (Change)>;

  protected:
    virtual auto
    compare_vfunc (gpointer item1, gpointer item2) -> Ordering;

    virtual auto
    get_order_vfunc () -> Order;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Sorter::Order>
    : public Glib::Value_Enum<Gtk::Sorter::Order>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Sorter::Change>
    : public Glib::Value_Enum<Gtk::Sorter::Change>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Sorter>;
} // namespace Glib

#endif
