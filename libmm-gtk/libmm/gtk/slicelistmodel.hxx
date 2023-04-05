// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SLICELISTMODEL_H
#define _GTKMM_SLICELISTMODEL_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SliceListModel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SliceListModel : public glib::Object,
                                   public gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SliceListModel;
    using CppClassType = SliceListModel_Class;
    using BaseObjectType = GtkSliceListModel;
    using BaseClassType = GtkSliceListModelClass;

    SliceListModel (const SliceListModel&) = delete;
    auto
    operator= (const SliceListModel&) -> SliceListModel& = delete;

  private:
    friend class SliceListModel_Class;
    static CppClassType slicelistmodel_class_;

  protected:
    explicit SliceListModel (const glib::ConstructParams& construct_params);
    explicit SliceListModel (GtkSliceListModel* castitem);

#endif

  public:
    SliceListModel (SliceListModel&& src) noexcept;
    auto
    operator= (SliceListModel&& src) noexcept -> SliceListModel&;

    ~SliceListModel () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSliceListModel*
    {
      return reinterpret_cast<GtkSliceListModel*> (gobject_);
    }

    auto
    gobj () const -> const GtkSliceListModel*
    {
      return reinterpret_cast<GtkSliceListModel*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSliceListModel*;

  private:
  protected:
    explicit SliceListModel (const glib::RefPtr<gio::ListModel>& model,
                             guint offset,
                             guint size);

  public:
    static auto
    create (const glib::RefPtr<gio::ListModel>& model, guint offset, guint size)
        -> glib::RefPtr<SliceListModel>;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_offset (guint offset) -> void;

    auto
    get_offset () const -> guint;

    auto
    set_size (guint size) -> void;

    auto
    get_size () const -> guint;

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
    property_offset () -> glib::PropertyProxy<guint>;

    auto
    property_offset () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_size () -> glib::PropertyProxy<guint>;

    auto
    property_size () const -> glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSliceListModel* object, bool take_copy = false) -> glib::RefPtr<gtk::SliceListModel>;
} // namespace glib

#endif
