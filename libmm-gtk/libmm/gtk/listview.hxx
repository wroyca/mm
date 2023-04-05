// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTVIEW_H
#define _GTKMM_LISTVIEW_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/listbase.hxx>
#include <libmm/gtk/listitemfactory.hxx>
#include <libmm/gtk/selectionmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListView = struct _GtkListView;
using GtkListViewClass = struct _GtkListViewClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ListView_Class;
}
#endif

namespace gtk
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
    explicit ListView (const glib::ConstructParams& construct_params);
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
    explicit ListView (const glib::RefPtr<SelectionModel>& model = {},
                       const glib::RefPtr<ListItemFactory>& factory = {});

    auto
    get_model () -> glib::RefPtr<SelectionModel>;

    auto
    get_model () const -> glib::RefPtr<const SelectionModel>;

    auto
    set_model (const glib::RefPtr<SelectionModel>& model) -> void;

    auto
    set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> glib::RefPtr<const ListItemFactory>;

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
    property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<SelectionModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<SelectionModel>>;

    auto
    property_show_separators () -> glib::PropertyProxy<bool>;

    auto
    property_show_separators () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_single_click_activate () -> glib::PropertyProxy<bool>;

    auto
    property_single_click_activate () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_enable_rubberband () -> glib::PropertyProxy<bool>;

    auto
    property_enable_rubberband () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> glib::SignalProxy<void (guint)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkListView* object, bool take_copy = false) -> gtk::ListView*;
} // namespace glib

#endif
