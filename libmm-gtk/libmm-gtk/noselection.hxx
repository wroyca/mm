// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NOSELECTION_H
#define _GTKMM_NOSELECTION_H

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
  class GTKMM_API NoSelection_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API NoSelection : public Glib::Object,
                                public Gio::ListModel,
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
    explicit NoSelection (const Glib::ConstructParams& construct_params);
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
    explicit NoSelection (const Glib::RefPtr<Gio::ListModel>& model);

  public:
    static auto
    create () -> Glib::RefPtr<NoSelection>;

    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model)
        -> Glib::RefPtr<NoSelection>;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    void
    set_model (const Glib::RefPtr<Gio::ListModel>& model);

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
  wrap (GtkNoSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::NoSelection>;
} // namespace Glib

#endif
