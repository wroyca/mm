// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SORTLISTMODEL_H
#define _GTKMM_SORTLISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API SortListModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API SortListModel : public Glib::Object,
                                  public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SortListModel;
    using CppClassType = SortListModel_Class;
    using BaseObjectType = GtkSortListModel;
    using BaseClassType = GtkSortListModelClass;

    SortListModel (const SortListModel&) = delete;
    auto
    operator= (const SortListModel&) -> SortListModel& = delete;

  private:
    friend class SortListModel_Class;
    static CppClassType sortlistmodel_class_;

  protected:
    explicit SortListModel (const Glib::ConstructParams& construct_params);
    explicit SortListModel (GtkSortListModel* castitem);

#endif

  public:
    SortListModel (SortListModel&& src) noexcept;
    auto
    operator= (SortListModel&& src) noexcept -> SortListModel&;

    ~SortListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSortListModel*
    {
      return reinterpret_cast<GtkSortListModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkSortListModel*
    {
      return reinterpret_cast<GtkSortListModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSortListModel*;

  private:
  protected:
    explicit SortListModel (const Glib::RefPtr<Gio::ListModel>& model,
                            const Glib::RefPtr<Sorter>& sorter);

  public:
    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model,
            const Glib::RefPtr<Sorter>& sorter) -> Glib::RefPtr<SortListModel>;

    auto
    set_sorter (const Glib::RefPtr<Sorter>& sorter) -> void;

    auto
    get_sorter () -> Glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> Glib::RefPtr<const Sorter>;

    auto
    set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_incremental (bool incremental = true) -> void;

    auto
    get_incremental () const -> bool;

    auto
    get_pending () const -> guint;

    auto
    property_incremental () -> Glib::PropertyProxy<bool>;

    auto
    property_incremental () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_pending () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_sorter () -> Glib::PropertyProxy<Glib::RefPtr<Sorter>>;

    auto
    property_sorter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkSortListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SortListModel>;
} // namespace Glib

#endif
