// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACCESSIBLE_H
#define _GTKMM_ACCESSIBLE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>
#include <libmm-glib/value.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkAccessibleInterface GtkAccessibleInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAccessible = struct _GtkAccessible;
using GtkAccessibleClass = struct _GtkAccessibleClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Accessible_Class;
}
#endif

namespace Gtk
{
  class ATContext;

  class GTKMM_API Accessible : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Accessible;
    using CppClassType = Accessible_Class;
    using BaseObjectType = GtkAccessible;
    using BaseClassType = GtkAccessibleInterface;

    Accessible (const Accessible&) = delete;
    auto
    operator= (const Accessible&) -> Accessible& = delete;

  private:
    friend class Accessible_Class;
    static CppClassType accessible_class_;

#endif
  protected:
    Accessible ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Accessible (const Glib::Interface_Class& interface_class);

  public:
    explicit Accessible (GtkAccessible* castitem);

  protected:
#endif

  public:
    Accessible (Accessible&& src) noexcept;
    auto
    operator= (Accessible&& src) noexcept -> Accessible&;

    ~Accessible () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAccessible*
    {
      return reinterpret_cast<GtkAccessible*> (gobject_);
    }

    auto
    gobj () const -> const GtkAccessible*
    {
      return reinterpret_cast<GtkAccessible*> (gobject_);
    }

  private:
  public:
    enum class Role
    {
      ALERT,
      ALERT_DIALOG,
      BANNER,
      BUTTON,
      CAPTION,
      CELL,
      CHECKBOX,
      COLUMN_HEADER,
      COMBO_BOX,
      COMMAND,
      COMPOSITE,
      DIALOG,
      DOCUMENT,
      FEED,
      FORM,
      GENERIC,
      GRID,
      GRID_CELL,
      GROUP,
      HEADING,
      IMG,
      INPUT,
      LABEL,
      LANDMARK,
      LEGEND,
      LINK,
      LIST,
      LIST_BOX,
      LIST_ITEM,
      LOG,
      MAIN,
      MARQUEE,
      MATH,
      METER,
      MENU,
      MENU_BAR,
      MENU_ITEM,
      MENU_ITEM_CHECKBOX,
      MENU_ITEM_RADIO,
      NAVIGATION,
      NONE,
      NOTE,
      OPTION,
      PRESENTATION,
      PROGRESS_BAR,
      RADIO,
      RADIO_GROUP,
      RANGE,
      REGION,
      ROW,
      ROW_GROUP,
      ROW_HEADER,
      SCROLLBAR,
      SEARCH,
      SEARCH_BOX,
      SECTION,
      SECTION_HEAD,
      SELECT,
      SEPARATOR,
      SLIDER,
      SPIN_BUTTON,
      STATUS,
      STRUCTURE,
      SWITCH,
      TAB,
      TABLE,
      TAB_LIST,
      TAB_PANEL,
      TEXT_BOX,
      TIME,
      TIMER,
      TOOLBAR,
      TOOLTIP,
      TREE,
      TREE_GRID,
      TREE_ITEM,
      WIDGET,
      WINDOW
    };

    enum class State
    {
      BUSY,
      CHECKED,
      DISABLED,
      EXPANDED,
      HIDDEN,
      INVALID,
      PRESSED,
      SELECTED
    };

    enum class Property
    {
      AUTOCOMPLETE,
      DESCRIPTION,
      HAS_POPUP,
      KEY_SHORTCUTS,
      LABEL,
      LEVEL,
      MODAL,
      MULTI_LINE,
      MULTI_SELECTABLE,
      ORIENTATION,
      PLACEHOLDER,
      READ_ONLY,
      REQUIRED,
      ROLE_DESCRIPTION,
      SORT,
      VALUE_MAX,
      VALUE_MIN,
      VALUE_NOW,
      VALUE_TEXT
    };

    enum class Relation
    {
      ACTIVE_DESCENDANT,
      COL_COUNT,
      COL_INDEX,
      COL_INDEX_TEXT,
      COL_SPAN,
      CONTROLS,
      DESCRIBED_BY,
      DETAILS,
      ERROR_MESSAGE,
      FLOW_TO,
      LABELLED_BY,
      OWNS,
      POS_IN_SET,
      ROW_COUNT,
      ROW_INDEX,
      ROW_INDEX_TEXT,
      ROW_SPAN,
      SET_SIZE
    };

    enum class PlatformState
    {
      FOCUSABLE,
      FOCUSED,
      ACTIVE
    };

    auto
    get_at_context () -> Glib::RefPtr<ATContext>;

    auto
    get_at_context () const -> Glib::RefPtr<const ATContext>;

    auto
    get_platform_state (PlatformState state) const -> bool;

    auto
    get_accessible_parent () -> Glib::RefPtr<Accessible>;

    auto
    get_accessible_parent () const -> Glib::RefPtr<const Accessible>;

    auto
    get_first_accessible_child () -> Glib::RefPtr<Accessible>;

    auto
    get_first_accessible_child () const -> Glib::RefPtr<const Accessible>;

    auto
    get_next_accessible_sibling () -> Glib::RefPtr<Accessible>;

    auto
    get_next_accessible_sibling () const -> Glib::RefPtr<const Accessible>;

    auto
    get_bounds (int& x, int& y, int& width, int& height) const -> bool;

    auto
    get_accessible_role () const -> Role;

    auto
    update_state (State state, const Glib::ValueBase& value) -> void;

    auto
    update_property (Property property, const Glib::ValueBase& value) -> void;

    auto
    update_relation (Relation relation, const Glib::ValueBase& value) -> void;

    auto
    reset_state (State state) -> void;

    auto
    reset_property (Property property) -> void;

    auto
    reset_relation (Relation relation) -> void;

    auto
    property_accessible_role () -> Glib::PropertyProxy<Role>;

    auto
    property_accessible_role () const -> Glib::PropertyProxy_ReadOnly<Role>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Accessible::Role>
    : public Glib::Value_Enum<Gtk::Accessible::Role>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Accessible::State>
    : public Glib::Value_Enum<Gtk::Accessible::State>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Accessible::Property>
    : public Glib::Value_Enum<Gtk::Accessible::Property>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Accessible::Relation>
    : public Glib::Value_Enum<Gtk::Accessible::Relation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Accessible::PlatformState>
    : public Glib::Value_Enum<Gtk::Accessible::PlatformState>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  GTKMM_API auto
  wrap (GtkAccessible* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Accessible>;

} // namespace Glib

#endif
