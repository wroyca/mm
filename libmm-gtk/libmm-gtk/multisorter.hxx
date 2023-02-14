
#ifndef _GTKMM_MULTISORTER_H
#define _GTKMM_MULTISORTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MultiSorter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API MultiSorter : public Sorter,
                                public Gio::ListModel,
                                public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MultiSorter;
    using CppClassType = MultiSorter_Class;
    using BaseObjectType = GtkMultiSorter;
    using BaseClassType = GtkMultiSorterClass;

    MultiSorter (const MultiSorter&) = delete;
    auto
    operator= (const MultiSorter&) -> MultiSorter& = delete;

  private:
    friend class MultiSorter_Class;
    static CppClassType multisorter_class_;

  protected:
    explicit MultiSorter (const Glib::ConstructParams& construct_params);
    explicit MultiSorter (GtkMultiSorter* castitem);

#endif

  public:
    MultiSorter (MultiSorter&& src) noexcept;
    auto
    operator= (MultiSorter&& src) noexcept -> MultiSorter&;

    ~MultiSorter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMultiSorter*
    {
      return reinterpret_cast<GtkMultiSorter*> (gobject_);
    }

    auto
    gobj () const -> const GtkMultiSorter*
    {
      return reinterpret_cast<GtkMultiSorter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMultiSorter*;

  private:
  protected:
    MultiSorter ();

  public:
    static auto
    create () -> Glib::RefPtr<MultiSorter>;

    void
    append (const Glib::RefPtr<Sorter>& sorter);

    void
    remove (guint position);

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkMultiSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiSorter>;
} // namespace Glib

#endif
