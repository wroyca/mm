// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILTERLISTMODEL_H
#define _GTKMM_FILTERLISTMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT FilterListModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT FilterListModel : public glib::Object,
                                    public gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FilterListModel;
    using CppClassType = FilterListModel_Class;
    using BaseObjectType = GtkFilterListModel;
    using BaseClassType = GtkFilterListModelClass;

    FilterListModel (const FilterListModel&) = delete;
    auto
    operator= (const FilterListModel&) -> FilterListModel& = delete;

  private:
    friend class FilterListModel_Class;
    static CppClassType filterlistmodel_class_;

  protected:
    explicit FilterListModel (const glib::ConstructParams& construct_params);
    explicit FilterListModel (GtkFilterListModel* castitem);

#endif

  public:
    FilterListModel (FilterListModel&& src) noexcept;
    auto
    operator= (FilterListModel&& src) noexcept -> FilterListModel&;

    ~FilterListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFilterListModel*
    {
      return reinterpret_cast<GtkFilterListModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkFilterListModel*
    {
      return reinterpret_cast<GtkFilterListModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFilterListModel*;

  private:
  protected:
    explicit FilterListModel (const glib::RefPtr<gio::ListModel>& model,
                              const glib::RefPtr<Filter>& filter);

  public:
    static auto
    create (const glib::RefPtr<gio::ListModel>& model,
            const glib::RefPtr<Filter>& filter)
        -> glib::RefPtr<FilterListModel>;

    auto
    set_filter (const glib::RefPtr<Filter>& filter) -> void;

    auto
    get_filter () -> glib::RefPtr<Filter>;

    auto
    get_filter () const -> glib::RefPtr<const Filter>;

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
    property_filter () -> glib::PropertyProxy<glib::RefPtr<Filter>>;

    auto
    property_filter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Filter>>;

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

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkFilterListModel* object, bool take_copy = false) -> glib::RefPtr<gtk::FilterListModel>;
} // namespace glib

#endif
