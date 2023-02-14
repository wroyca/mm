
#ifndef _GTKMM_LISTITEM_H
#define _GTKMM_LISTITEM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListItem = struct _GtkListItem;
using GtkListItemClass = struct _GtkListItemClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ListItem_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ListItem : public Glib::Object
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
    explicit ListItem (const Glib::ConstructParams& construct_params);
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
    get_item () -> Glib::RefPtr<Glib::ObjectBase>;

    auto
    get_item () const -> Glib::RefPtr<const Glib::ObjectBase>;

    auto
    get_position () const -> guint;

    auto
    get_selected () const -> bool;

    auto
    get_selectable () const -> bool;

    void
    set_selectable (bool selectable = true);

    auto
    get_activatable () const -> bool;

    void
    set_activatable (bool activatable = true);

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_item () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::ObjectBase>>;

    auto
    property_position () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_selectable () -> Glib::PropertyProxy<bool>;

    auto
    property_selectable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkListItem* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ListItem>;
} // namespace Glib

#endif
