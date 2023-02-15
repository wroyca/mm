// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MULTISELECTION_H
#define _GTKMM_MULTISELECTION_H

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
  class LIBMM_GTK_SYMEXPORT MultiSelection_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT MultiSelection : public Glib::Object,
                                   public Gio::ListModel,
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
    explicit MultiSelection (const Glib::ConstructParams& construct_params);
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
    explicit MultiSelection (const Glib::RefPtr<Gio::ListModel>& model);

  public:
    static auto
    create () -> Glib::RefPtr<MultiSelection>;

    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model)
        -> Glib::RefPtr<MultiSelection>;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void;

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
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMultiSelection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::MultiSelection>;
} // namespace Glib

#endif
