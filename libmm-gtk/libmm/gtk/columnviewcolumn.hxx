// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEWCOLUMN_H
#define _GTKMM_COLUMNVIEWCOLUMN_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/listitemfactory.hxx>
#include <libmm/gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColumnViewColumn = struct _GtkColumnViewColumn;
using GtkColumnViewColumnClass = struct _GtkColumnViewColumnClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColumnViewColumn_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ColumnView;

  class LIBMM_GTK_SYMEXPORT ColumnViewColumn : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ColumnViewColumn;
    using CppClassType = ColumnViewColumn_Class;
    using BaseObjectType = GtkColumnViewColumn;
    using BaseClassType = GtkColumnViewColumnClass;

    ColumnViewColumn (const ColumnViewColumn&) = delete;
    auto
    operator= (const ColumnViewColumn&) -> ColumnViewColumn& = delete;

  private:
    friend class ColumnViewColumn_Class;
    static CppClassType columnviewcolumn_class_;

  protected:
    explicit ColumnViewColumn (const glib::ConstructParams& construct_params);
    explicit ColumnViewColumn (GtkColumnViewColumn* castitem);

#endif

  public:
    ColumnViewColumn (ColumnViewColumn&& src) noexcept;
    auto
    operator= (ColumnViewColumn&& src) noexcept -> ColumnViewColumn&;

    ~ColumnViewColumn () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkColumnViewColumn*
    {
      return reinterpret_cast<GtkColumnViewColumn*> (gobject_);
    }

    auto
    gobj () const -> const GtkColumnViewColumn*
    {
      return reinterpret_cast<GtkColumnViewColumn*> (gobject_);
    }

    auto
    gobj_copy () -> GtkColumnViewColumn*;

  private:
  protected:
    explicit ColumnViewColumn (
        const glib::ustring& title,
        const glib::RefPtr<ListItemFactory>& factory = {});

  public:
    static auto
    create (const glib::ustring& title,
            const glib::RefPtr<ListItemFactory>& factory = {})
        -> glib::RefPtr<ColumnViewColumn>;

    auto
    get_column_view () -> ColumnView*;

    auto
    get_column_view () const -> const ColumnView*;

    auto
    set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> glib::RefPtr<const ListItemFactory>;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_sorter (const glib::RefPtr<Sorter>& sorter) -> void;

    auto
    get_sorter () -> glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> glib::RefPtr<const Sorter>;

    auto
    set_visible (bool visible = true) -> void;

    auto
    get_visible () const -> bool;

    auto
    set_header_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_header_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_header_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    set_fixed_width (int fixed_width) -> void;

    auto
    get_fixed_width () const -> int;

    auto
    set_resizable (bool resizable = true) -> void;

    auto
    get_resizable () const -> bool;

    auto
    set_expand (bool expand = true) -> void;

    auto
    get_expand () const -> bool;

    auto
    set_id (const glib::ustring& id) -> void;

    auto
    get_id () const -> glib::ustring;

    auto
    property_column_view () const -> glib::PropertyProxy_ReadOnly<ColumnView*>;

    auto
    property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_sorter () -> glib::PropertyProxy<glib::RefPtr<Sorter>>;

    auto
    property_sorter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Sorter>>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_header_menu ()
        -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_header_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_resizable () -> glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expand () -> glib::PropertyProxy<bool>;

    auto
    property_expand () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fixed_width () -> glib::PropertyProxy<int>;

    auto
    property_fixed_width () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_id () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_id () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkColumnViewColumn* object, bool take_copy = false) -> glib::RefPtr<gtk::ColumnViewColumn>;
} // namespace glib

#endif
