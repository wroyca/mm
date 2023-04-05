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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DropDown_Class;
}
#endif

namespace gtk
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
    explicit DropDown (const glib::ConstructParams& construct_params);
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
        const glib::RefPtr<gio::ListModel>& model = {},
        const glib::RefPtr<Expression<glib::ustring>>& expression = {});

    explicit DropDown (const std::vector<glib::ustring>& strings);

    auto
    set_model (const glib::RefPtr<gio::ListModel>& model) -> void;

    auto
    get_model () -> glib::RefPtr<gio::ListModel>;

    auto
    get_model () const -> glib::RefPtr<const gio::ListModel>;

    auto
    set_selected (guint position) -> void;

    auto
    get_selected () const -> guint;

    auto
    get_selected_item () -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_selected_item () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    set_factory (const glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_factory () -> glib::RefPtr<ListItemFactory>;

    auto
    get_factory () const -> glib::RefPtr<const ListItemFactory>;

    auto
    set_list_factory (const glib::RefPtr<ListItemFactory>& factory) -> void;

    auto
    get_list_factory () -> glib::RefPtr<ListItemFactory>;

    auto
    get_list_factory () const -> glib::RefPtr<const ListItemFactory>;

    auto
    set_expression (const glib::RefPtr<Expression<glib::ustring>>& expression)
        -> void;

    auto
    get_expression () -> glib::RefPtr<Expression<glib::ustring>>;

    auto
    get_expression () const -> glib::RefPtr<const Expression<glib::ustring>>;

    auto
    set_enable_search (bool enable_search = true) -> void;

    auto
    get_enable_search () const -> bool;

    auto
    set_show_arrow (bool show_arrow = true) -> void;

    auto
    set_show_arrow () const -> bool;

    auto
    property_factory () -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>;

    auto
    property_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>;

    auto
    property_list_factory ()
        -> glib::PropertyProxy<glib::RefPtr<ListItemFactory>>;

    auto
    property_list_factory () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ListItemFactory>>;

    auto
    property_model () -> glib::PropertyProxy<glib::RefPtr<gio::ListModel>>;

    auto
    property_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::ListModel>>;

    auto
    property_selected () -> glib::PropertyProxy<guint>;

    auto
    property_selected () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selected_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_enable_search () -> glib::PropertyProxy<bool>;

    auto
    property_enable_search () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_expression ()
        -> glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>>;

    auto
    property_expression () const -> glib::PropertyProxy_ReadOnly<
        glib::RefPtr<Expression<glib::ustring>>>;

    auto
    property_show_arrow () -> glib::PropertyProxy<bool>;

    auto
    property_show_arrow () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDropDown* object, bool take_copy = false) -> gtk::DropDown*;
} // namespace glib

#endif
