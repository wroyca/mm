// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SINGLESELECTION_H
#define _GTKMM_SINGLESELECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API SingleSelection_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API SingleSelection : public Glib::Object,
                                    public Gio::ListModel,
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
    explicit SingleSelection (const Glib::ConstructParams& construct_params);
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
    explicit SingleSelection (const Glib::RefPtr<Gio::ListModel>& model);

  public:
    static auto
    create () -> Glib::RefPtr<SingleSelection>;

    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model)
        -> Glib::RefPtr<SingleSelection>;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    void
    set_model (const Glib::RefPtr<Gio::ListModel>& model);

    auto
    get_selected () const -> guint;

    void
    set_selected (guint position);

    auto
    get_selected_item () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_selected_item () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    get_autoselect () const -> bool;

    void
    set_autoselect (bool autoselect = true);

    auto
    get_can_unselect () const -> bool;

    void
    set_can_unselect (bool can_unselect = true);

    auto
    property_autoselect () -> Glib::PropertyProxy<bool>;

    auto
    property_autoselect () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_can_unselect () -> Glib::PropertyProxy<bool>;

    auto
    property_can_unselect () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () -> Glib::PropertyProxy<guint>;

    auto
    property_selected () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selected_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSingleSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::SingleSelection>;
} // namespace Glib

#endif
