// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTITEM_H
#define _GTKMM_LISTITEM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListItem = struct _GtkListItem;
using GtkListItemClass = struct _GtkListItemClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ListItem_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ListItem : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ListItem;
    using CppClassType = ListItem_Class;
    using BaseObjectType = GtkListItem;
    using BaseClassType = GtkListItemClass;

    ListItem (const ListItem&) = delete;
    auto
    operator= (const ListItem&) -> ListItem& = delete;

  private:
    friend class ListItem_Class;
    static CppClassType listitem_class_;

  protected:
    explicit ListItem (const glib::ConstructParams& construct_params);
    explicit ListItem (GtkListItem* castitem);

#endif

  public:
    ListItem (ListItem&& src) noexcept;
    auto
    operator= (ListItem&& src) noexcept -> ListItem&;

    ~ListItem () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListItem*
    {
      return reinterpret_cast<GtkListItem*> (gobject_);
    }

    auto
    gobj () const -> const GtkListItem*
    {
      return reinterpret_cast<GtkListItem*> (gobject_);
    }

    auto
    gobj_copy () -> GtkListItem*;

  private:
  public:
    auto
    get_item () -> glib::RefPtr<glib::ObjectBase>;

    auto
    get_item () const -> glib::RefPtr<const glib::ObjectBase>;

    auto
    get_position () const -> guint;

    auto
    get_selected () const -> bool;

    auto
    get_selectable () const -> bool;

    auto
    set_selectable (bool selectable = true) -> void;

    auto
    get_activatable () const -> bool;

    auto
    set_activatable (bool activatable = true) -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_activatable () -> glib::PropertyProxy<bool>;

    auto
    property_activatable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_item () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::ObjectBase>>;

    auto
    property_position () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selectable () -> glib::PropertyProxy<bool>;

    auto
    property_selectable () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkListItem* object, bool take_copy = false) -> glib::RefPtr<gtk::ListItem>;
} // namespace glib

#endif
