// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTVIEW_H
#define _GTKMM_LISTVIEW_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/listbase.hxx>
#include <libmm-gtk/listitemfactory.hxx>
#include <libmm-gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListView = struct _GtkListView;
using GtkListViewClass = struct _GtkListViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ListView_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ListView : public ListBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ListView CppObjectType;
    typedef ListView_Class CppClassType;
    typedef GtkListView BaseObjectType;
    typedef GtkListViewClass BaseClassType;
#endif

    ListView (ListView&& src) noexcept;
    auto
    operator= (ListView&& src) noexcept -> ListView&;

    ListView (const ListView&) = delete;
    auto
    operator= (const ListView&) -> ListView& = delete;

    ~ListView () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ListView_Class;
    static CppClassType listview_class_;

  protected:
    explicit ListView (const Glib::ConstructParams& construct_params);
    explicit ListView (GtkListView* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListView*
    {
      return reinterpret_cast<GtkListView*> (gobject_);
    }

    auto
    gobj () const -> const GtkListView*
    {
      return reinterpret_cast<GtkListView*> (gobject_);
    }

  private:
  public:
    explicit ListView (const Glib::RefPtr<SelectionModel>& model = {},
                       const Glib::RefPtr<ListItemFactory>& factory = {});

    auto
    get_model () -> Glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> Glib::RefPtr<const SelectionModel>;

    auto
    set_model (const Glib::RefPtr<SelectionModel>& model) -> void;

    auto
    set_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> Glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> Glib::RefPtr<const ListItemFactory>;

    auto
    set_show_separators (bool show_separators = true) -> void;

    auto
    get_show_separators () const -> bool;

    auto
    set_single_click_activate (bool single_click_activate = true) -> void;

    auto
    get_single_click_activate () const -> bool;

    auto
    set_enable_rubberband (bool enable_rubberband = true) -> void;

    auto
    get_enable_rubberband () const -> bool;

    auto
    property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<SelectionModel>>;

    auto
    property_show_separators () -> Glib::PropertyProxy<bool>;

    auto
    property_show_separators () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_single_click_activate () -> Glib::PropertyProxy<bool>;

    auto
    property_single_click_activate () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_rubberband () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_rubberband () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> Glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkListView* object, bool take_copy = false) -> Gtk::ListView*;
} // namespace Glib

#endif
