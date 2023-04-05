// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NOSELECTION_H
#define _GTKMM_NOSELECTION_H

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
  class LIBMM_GTK_SYMEXPORT NoSelection_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT NoSelection : public glib::Object,
                                public gio::ListModel,
                                public SelectionModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NoSelection;
    using CppClassType = NoSelection_Class;
    using BaseObjectType = GtkNoSelection;
    using BaseClassType = GtkNoSelectionClass;

    NoSelection (const NoSelection&) = delete;
    auto
    operator= (const NoSelection&) -> NoSelection& = delete;

  private:
    friend class NoSelection_Class;
    static CppClassType noselection_class_;

  protected:
    explicit NoSelection (const glib::ConstructParams& construct_params);
    explicit NoSelection (GtkNoSelection* castitem);

#endif

  public:
    NoSelection (NoSelection&& src) noexcept;
    auto
    operator= (NoSelection&& src) noexcept -> NoSelection&;

    ~NoSelection () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNoSelection*
    {
      return reinterpret_cast<GtkNoSelection*> (gobject_);
    }

    auto
    gobj () const -> const GtkNoSelection*
    {
      return reinterpret_cast<GtkNoSelection*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNoSelection*;

  private:
  protected:
    NoSelection ();
    explicit NoSelection (const glib::RefPtr<gio::ListModel>& model);

  public:
    static auto
    create () -> glib::RefPtr<NoSelection>;

    static auto
    create (const glib::RefPtr<gio::ListModel>& model)
        -> glib::RefPtr<NoSelection>;

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
  wrap (GtkNoSelection* object, bool take_copy = false) -> glib::RefPtr<gtk::NoSelection>;
} // namespace glib

#endif
