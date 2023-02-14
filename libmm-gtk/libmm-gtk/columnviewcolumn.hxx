// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_COLUMNVIEWCOLUMN_H
#define _GTKMM_COLUMNVIEWCOLUMN_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/listitemfactory.hxx>
#include <libmm-gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkColumnViewColumn = struct _GtkColumnViewColumn;
using GtkColumnViewColumnClass = struct _GtkColumnViewColumnClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ColumnViewColumn_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API ColumnView;

  class GTKMM_API ColumnViewColumn : public Glib::Object
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
    explicit ColumnViewColumn (const Glib::ConstructParams& construct_params);
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
        const Glib::ustring& title,
        const Glib::RefPtr<ListItemFactory>& factory = {});

  public:
    static auto
    create (const Glib::ustring& title,
            const Glib::RefPtr<ListItemFactory>& factory = {})
        -> Glib::RefPtr<ColumnViewColumn>;

    auto
    get_column_view () -> ColumnView*;

    auto
    get_column_view () const -> const ColumnView*;

    void
    set_factory (const Glib::RefPtr<ListItemFactory>& factory);

    auto
    get_factory () -> Glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> Glib::RefPtr<const ListItemFactory>;

    void
    set_title (const Glib::ustring& title);

    auto
    get_title () const -> Glib::ustring;

    void
    set_sorter (const Glib::RefPtr<Sorter>& sorter);

    auto
    get_sorter () -> Glib::RefPtr<Sorter>;

    auto
    get_sorter () const -> Glib::RefPtr<const Sorter>;

    void
    set_visible (bool visible = true);

    auto
    get_visible () const -> bool;

    void
    set_header_menu (const Glib::RefPtr<Gio::MenuModel>& model);

    auto
    get_header_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_header_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    void
    set_fixed_width (int fixed_width);

    auto
    get_fixed_width () const -> int;

    void
    set_resizable (bool resizable = true);

    auto
    get_resizable () const -> bool;

    void
    set_expand (bool expand = true);

    auto
    get_expand () const -> bool;

    auto
    property_column_view () const -> Glib::PropertyProxy_ReadOnly<ColumnView*>;

    auto
    property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_sorter () -> Glib::PropertyProxy<Glib::RefPtr<Sorter>>;

    auto
    property_sorter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Sorter>>;

    auto
    property_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_header_menu ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_header_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_resizable () -> Glib::PropertyProxy<bool>;

    auto
    property_resizable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expand () -> Glib::PropertyProxy<bool>;

    auto
    property_expand () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_fixed_width () -> Glib::PropertyProxy<int>;

    auto
    property_fixed_width () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkColumnViewColumn* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ColumnViewColumn>;
} // namespace Glib

#endif
