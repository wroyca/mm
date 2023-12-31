// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVERMENU_H
#define _GTKMM_POPOVERMENU_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/popover.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPopoverMenu = struct _GtkPopoverMenu;
using GtkPopoverMenuClass = struct _GtkPopoverMenuClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PopoverMenu_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PopoverMenu : public Popover
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PopoverMenu CppObjectType;
    typedef PopoverMenu_Class CppClassType;
    typedef GtkPopoverMenu BaseObjectType;
    typedef GtkPopoverMenuClass BaseClassType;
#endif

    PopoverMenu (PopoverMenu&& src) noexcept;
    auto
    operator= (PopoverMenu&& src) noexcept -> PopoverMenu&;

    PopoverMenu (const PopoverMenu&) = delete;
    auto
    operator= (const PopoverMenu&) -> PopoverMenu& = delete;

    ~PopoverMenu () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class PopoverMenu_Class;
    static CppClassType popovermenu_class_;

  protected:
    explicit PopoverMenu (const glib::ConstructParams& construct_params);
    explicit PopoverMenu (GtkPopoverMenu* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPopoverMenu*
    {
      return reinterpret_cast<GtkPopoverMenu*> (gobject_);
    }

    auto
    gobj () const -> const GtkPopoverMenu*
    {
      return reinterpret_cast<GtkPopoverMenu*> (gobject_);
    }

  private:
  public:
    enum class Flags
    {
      NESTED = 1 << 0
    };

    explicit PopoverMenu (const glib::RefPtr<gio::MenuModel>& model = {},
                          Flags flags = static_cast<Flags> (0));

    auto
    set_menu_model (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_menu_model () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_menu_model () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    add_child (Widget& child, const glib::ustring& id) -> bool;

    auto
    remove_child (Widget& child) -> bool;

    auto
    property_visible_submenu () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_visible_submenu () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_menu_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace gtk
{

  inline auto
  operator| (PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  {
    return static_cast<PopoverMenu::Flags> (static_cast<unsigned> (lhs) |
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  {
    return static_cast<PopoverMenu::Flags> (static_cast<unsigned> (lhs) &
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (PopoverMenu::Flags lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags
  {
    return static_cast<PopoverMenu::Flags> (static_cast<unsigned> (lhs) ^
                                            static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(PopoverMenu::Flags flags) -> PopoverMenu::Flags
  {
    return static_cast<PopoverMenu::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  {
    return (lhs = static_cast<PopoverMenu::Flags> (
                static_cast<unsigned> (lhs) | static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  {
    return (lhs = static_cast<PopoverMenu::Flags> (
                static_cast<unsigned> (lhs) & static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (PopoverMenu::Flags& lhs, PopoverMenu::Flags rhs) -> PopoverMenu::Flags&
  {
    return (lhs = static_cast<PopoverMenu::Flags> (
                static_cast<unsigned> (lhs) ^ static_cast<unsigned> (rhs)));
  }
} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PopoverMenu::Flags>
    : public glib::Value_Flags<gtk::PopoverMenu::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPopoverMenu* object, bool take_copy = false) -> gtk::PopoverMenu*;
} // namespace glib

#endif
