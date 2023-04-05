// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SELECTIONFILTERMODEL_H
#define _GTKMM_SELECTIONFILTERMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SelectionFilterModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SelectionFilterModel : public glib::Object,
                                         public gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SelectionFilterModel;
    using CppClassType = SelectionFilterModel_Class;
    using BaseObjectType = GtkSelectionFilterModel;
    using BaseClassType = GtkSelectionFilterModelClass;

    SelectionFilterModel (const SelectionFilterModel&) = delete;
    auto
    operator= (const SelectionFilterModel&) -> SelectionFilterModel& = delete;

  private:
    friend class SelectionFilterModel_Class;
    static CppClassType selectionfiltermodel_class_;

  protected:
    explicit SelectionFilterModel (
        const glib::ConstructParams& construct_params);
    explicit SelectionFilterModel (GtkSelectionFilterModel* castitem);

#endif

  public:
    SelectionFilterModel (SelectionFilterModel&& src) noexcept;
    auto
    operator= (SelectionFilterModel&& src) noexcept -> SelectionFilterModel&;

    ~SelectionFilterModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSelectionFilterModel*
    {
      return reinterpret_cast<GtkSelectionFilterModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkSelectionFilterModel*
    {
      return reinterpret_cast<GtkSelectionFilterModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSelectionFilterModel*;

  private:
  protected:
    explicit SelectionFilterModel (const glib::RefPtr<SelectionModel>& model);

  public:
    static auto
    create (const glib::RefPtr<SelectionModel>& model)
        -> glib::RefPtr<SelectionFilterModel>;

    auto
    set_model (const glib::RefPtr<SelectionModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> glib::RefPtr<const SelectionModel>;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSelectionFilterModel* object, bool take_copy = false) -> glib::RefPtr<gtk::SelectionFilterModel>;
} // namespace glib

#endif
