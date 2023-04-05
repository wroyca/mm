// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MULTISELECTION_H
#define _GTKMM_MULTISELECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT MultiSelection_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MultiSelection : public glib::Object,
                                   public gio::ListModel,
                                   public SelectionModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MultiSelection;
    using CppClassType = MultiSelection_Class;
    using BaseObjectType = GtkMultiSelection;
    using BaseClassType = GtkMultiSelectionClass;

    MultiSelection (const MultiSelection&) = delete;
    auto
    operator= (const MultiSelection&) -> MultiSelection& = delete;

  private:
    friend class MultiSelection_Class;
    static CppClassType multiselection_class_;

  protected:
    explicit MultiSelection (const glib::ConstructParams& construct_params);
    explicit MultiSelection (GtkMultiSelection* castitem);

#endif

  public:
    MultiSelection (MultiSelection&& src) noexcept;
    auto
    operator= (MultiSelection&& src) noexcept -> MultiSelection&;

    ~MultiSelection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMultiSelection*
    {
      return reinterpret_cast<GtkMultiSelection*> (gobject_);
    }

    auto
    gobj () const -> const GtkMultiSelection*
    {
      return reinterpret_cast<GtkMultiSelection*> (gobject_);
    }

    auto
    gobj_copy () -> GtkMultiSelection*;

  private:
  protected:
    MultiSelection ();
    explicit MultiSelection (const glib::RefPtr<gio::ListModel>& model);

  public:
    static auto
    create () -> glib::RefPtr<MultiSelection>;

    static auto
    create (const glib::RefPtr<gio::ListModel>& model)
        -> glib::RefPtr<MultiSelection>;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

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
  wrap (GtkMultiSelection* object, bool take_copy = false) -> glib::RefPtr<gtk::MultiSelection>;
} // namespace glib

#endif
