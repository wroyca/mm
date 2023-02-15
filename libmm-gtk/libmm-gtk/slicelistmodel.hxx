// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SLICELISTMODEL_H
#define _GTKMM_SLICELISTMODEL_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API SliceListModel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API SliceListModel : public Glib::Object,
                                   public Gio::ListModel
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
    explicit SliceListModel (const Glib::ConstructParams& construct_params);
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
    explicit SliceListModel (const Glib::RefPtr<Gio::ListModel>& model,
                             guint offset,
                             guint size);

  public:
    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model, guint offset, guint size)
        -> Glib::RefPtr<SliceListModel>;

    auto
    set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_offset (guint offset) -> void;

    auto
    get_offset () const -> guint;

    auto
    set_size (guint size) -> void;

    auto
    get_size () const -> guint;

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
    property_offset () -> Glib::PropertyProxy<guint>;

    auto
    property_offset () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_size () -> Glib::PropertyProxy<guint>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<guint>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkSliceListModel* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SliceListModel>;
} // namespace Glib

#endif
