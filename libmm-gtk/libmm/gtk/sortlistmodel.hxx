// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SORTLISTMODEL_H
#define _GTKMM_SORTLISTMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SortListModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SortListModel : public glib::Object,
                                  public gio::ListModel
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
    explicit SortListModel (const glib::ConstructParams& construct_params);
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
    explicit SortListModel (const glib::RefPtr<gio::ListModel>& model,
                            const glib::RefPtr<Sorter>& sorter);

  public:
    static auto
    create (const glib::RefPtr<gio::ListModel>& model,
            const glib::RefPtr<Sorter>& sorter) -> glib::RefPtr<SortListModel>;

    auto
    set_sorter (const glib::RefPtr<Sorter>& sorter) -> void;

    auto
    get_sorter () -> glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> glib::RefPtr<const Sorter>;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_incremental (bool incremental = true) -> void;

    auto
    get_incremental () const -> bool;

    auto
    get_pending () const -> guint;

    auto
    property_incremental () -> glib::PropertyProxy<bool>;

    auto
    property_incremental () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_pending () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_sorter () -> glib::PropertyProxy<glib::RefPtr<Sorter>>;

    auto
    property_sorter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSortListModel* object, bool take_copy = false) -> glib::RefPtr<gtk::SortListModel>;
} // namespace glib

#endif
