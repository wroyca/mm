// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SINGLESELECTION_H
#define _GTKMM_SINGLESELECTION_H

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
  class LIBMM_GTK_SYMEXPORT SingleSelection_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SingleSelection : public glib::Object,
                                    public gio::ListModel,
                                    public SelectionModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SingleSelection;
    using CppClassType = SingleSelection_Class;
    using BaseObjectType = GtkSingleSelection;
    using BaseClassType = GtkSingleSelectionClass;

    SingleSelection (const SingleSelection&) = delete;
    auto
    operator= (const SingleSelection&) -> SingleSelection& = delete;

  private:
    friend class SingleSelection_Class;
    static CppClassType singleselection_class_;

  protected:
    explicit SingleSelection (const glib::ConstructParams& construct_params);
    explicit SingleSelection (GtkSingleSelection* castitem);

#endif

  public:
    SingleSelection (SingleSelection&& src) noexcept;
    auto
    operator= (SingleSelection&& src) noexcept -> SingleSelection&;

    ~SingleSelection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSingleSelection*
    {
      return reinterpret_cast<GtkSingleSelection*> (gobject_);
    }

    auto
    gobj () const -> const GtkSingleSelection*
    {
      return reinterpret_cast<GtkSingleSelection*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSingleSelection*;

  private:
  protected:
    SingleSelection ();
    explicit SingleSelection (const glib::RefPtr<gio::ListModel>& model);

  public:
    static auto
    create () -> glib::RefPtr<SingleSelection>;

    static auto
    create (const glib::RefPtr<gio::ListModel>& model)
        -> glib::RefPtr<SingleSelection>;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    get_selected () const -> guint;

    auto
    set_selected (guint position) -> void;

    auto
    get_selected_item () -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_selected_item () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    get_autoselect () const -> bool;

    auto
    set_autoselect (bool autoselect = true) -> void;

    auto
    get_can_unselect () const -> bool;

    auto
    set_can_unselect (bool can_unselect = true) -> void;

    auto
    property_autoselect () -> glib::PropertyProxy<bool>;

    auto
    property_autoselect () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_unselect () -> glib::PropertyProxy<bool>;

    auto
    property_can_unselect () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () -> glib::PropertyProxy<guint>;

    auto
    property_selected () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selected_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

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
  wrap (GtkSingleSelection* object, bool take_copy = false) -> glib::RefPtr<gtk::SingleSelection>;
} // namespace glib

#endif
