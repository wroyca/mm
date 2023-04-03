// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DROPDOWN_H
#define _GTKMM_DROPDOWN_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/listitemfactory.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT DropDown_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT DropDown : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef DropDown CppObjectType;
    typedef DropDown_Class CppClassType;
    typedef GtkDropDown BaseObjectType;
    typedef GtkDropDownClass BaseClassType;
#endif

    DropDown (DropDown&& src) noexcept;
    auto
    operator= (DropDown&& src) noexcept -> DropDown&;

    DropDown (const DropDown&) = delete;
    auto
    operator= (const DropDown&) -> DropDown& = delete;

    ~DropDown () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class DropDown_Class;
    static CppClassType dropdown_class_;

  protected:
    explicit DropDown (const Glib::ConstructParams& construct_params);
    explicit DropDown (GtkDropDown* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDropDown*
    {
      return reinterpret_cast<GtkDropDown*> (gobject_);
    }

    auto
    gobj () const -> const GtkDropDown*
    {
      return reinterpret_cast<GtkDropDown*> (gobject_);
    }

  private:
  public:
    explicit DropDown (
        const Glib::RefPtr<Gio::ListModel>& model = {},
        const Glib::RefPtr<Expression<Glib::ustring>>& expression = {});

    explicit DropDown (const std::vector<Glib::ustring>& strings);

    auto
    set_model (const Glib::RefPtr<Gio::ListModel>& model) -> void;

    auto
    get_model () -> Glib::RefPtr<Gio::ListModel>;

    auto
    get_model () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    set_selected (guint position) -> void;

    auto
    get_selected () const -> guint;

    auto
    get_selected_item () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_selected_item () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    set_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> Glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> Glib::RefPtr<const ListItemFactory>;

    auto
    set_list_factory (const Glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_list_factory () -> Glib::RefPtr<ListItemFactory>;

    auto
    get_list_factory () const -> Glib::RefPtr<const ListItemFactory>;

    auto
    set_expression (const Glib::RefPtr<Expression<Glib::ustring>>& expression)
        -> void;

    auto
    get_expression () -> Glib::RefPtr<Expression<Glib::ustring>>;

    auto
    get_expression () const -> Glib::RefPtr<const Expression<Glib::ustring>>;

    auto
    set_enable_search (bool enable_search = true) -> void;

    auto
    get_enable_search () const -> bool;

    auto
    set_show_arrow (bool show_arrow = true) -> void;

    auto
    set_show_arrow () const -> bool;

    auto
    property_factory () -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>;

    auto
    property_list_factory ()
        -> Glib::PropertyProxy<Glib::RefPtr<ListItemFactory>>;

    auto
    property_list_factory () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ListItemFactory>>;

    auto
    property_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::ListModel>>;

    auto
    property_selected () -> Glib::PropertyProxy<guint>;

    auto
    property_selected () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selected_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_enable_search () -> Glib::PropertyProxy<bool>;

    auto
    property_enable_search () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expression ()
        -> Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_expression () const -> Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_show_arrow () -> Glib::PropertyProxy<bool>;

    auto
    property_show_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDropDown* object, bool take_copy = false) -> Gtk::DropDown*;
} // namespace Glib

#endif
