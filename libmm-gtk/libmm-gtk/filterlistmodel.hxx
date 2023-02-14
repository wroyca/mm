
#ifndef _GTKMM_FILTERLISTMODEL_H
#define _GTKMM_FILTERLISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API FilterListModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API FilterListModel : public Glib::Object,
                                    public Gio::ListModel
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
    explicit FilterListModel (const Glib::ConstructParams& construct_params);
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
    explicit FilterListModel (const Glib::RefPtr<Gio::ListModel>& model,
                              const Glib::RefPtr<Filter>& filter);

  public:
    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model,
            const Glib::RefPtr<Filter>& filter)
        -> Glib::RefPtr<FilterListModel>;

    void
    set_filter (const Glib::RefPtr<Filter>& filter);

    auto
    get_filter () -> Glib::RefPtr<Filter>;

    auto
    get_filter () const -> Glib::RefPtr<const Filter>;

    void
    set_model (const Glib::RefPtr<Gio::ListModel>& model);

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    void
    set_incremental (bool incremental = true);

    auto
    get_incremental () const -> bool;

    auto
    get_pending () const -> guint;

    auto
    property_filter () -> Glib::PropertyProxy<Glib::RefPtr<Filter>>;

    auto
    property_filter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Filter>>;

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

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFilterListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::FilterListModel>;
} // namespace Glib

#endif
