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
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT SelectionFilterModel_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT SelectionFilterModel : public Glib::Object,
                                         public Gio::ListModel
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
        const Glib::ConstructParams& construct_params);
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
    explicit SelectionFilterModel (const Glib::RefPtr<SelectionModel>& model);

  public:
    static auto
    create (const Glib::RefPtr<SelectionModel>& model)
        -> Glib::RefPtr<SelectionFilterModel>;

    auto
    set_model (const Glib::RefPtr<SelectionModel>& model) -> void;

    auto
    get_model () -> Glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> Glib::RefPtr<const SelectionModel>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSelectionFilterModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SelectionFilterModel>;
} // namespace Glib

#endif
