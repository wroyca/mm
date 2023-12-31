// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MENUBUTTON_H
#define _GTKMM_MENUBUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/popover.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMenuButton = struct _GtkMenuButton;
using GtkMenuButtonClass = struct _GtkMenuButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT MenuButton_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT MenuButton : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef MenuButton CppObjectType;
    typedef MenuButton_Class CppClassType;
    typedef GtkMenuButton BaseObjectType;
    typedef GtkMenuButtonClass BaseClassType;
#endif

    MenuButton (MenuButton&& src) noexcept;
    auto
    operator= (MenuButton&& src) noexcept -> MenuButton&;

    MenuButton (const MenuButton&) = delete;
    auto
    operator= (const MenuButton&) -> MenuButton& = delete;

    ~MenuButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class MenuButton_Class;
    static CppClassType menubutton_class_;

  protected:
    explicit MenuButton (const glib::ConstructParams& construct_params);
    explicit MenuButton (GtkMenuButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkMenuButton*
    {
      return reinterpret_cast<GtkMenuButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkMenuButton*
    {
      return reinterpret_cast<GtkMenuButton*> (gobject_);
    }

  private:
  public:
    MenuButton ();

    auto
    set_popover (Popover& popover) -> void;

    auto
    unset_popover () -> void;

    auto
    get_popover () -> Popover*;

    auto
    get_popover () const -> const Popover*;

    auto
    set_direction (ArrowType direction) -> void;

    auto
    get_direction () const -> ArrowType;

    auto
    set_menu_model (const glib::RefPtr<const gio::MenuModel>& menu_model)
        -> void;

    auto
    unset_menu_model () -> void;

    auto
    get_menu_model () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_menu_model () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    set_always_show_arrow (bool always_show_arrow = true) -> void;

    auto
    get_always_show_arrow () const -> bool;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    get_label () const -> glib::ustring;

    auto
    set_use_underline (bool use_underline = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_has_frame (bool has_frame = true) -> void;

    auto
    get_has_frame () const -> bool;

    auto
    popup () -> void;

    auto
    popdown () -> void;

    using SlotCreatePopup = sigc::slot<void ()>;

    auto
    set_create_popup_func (const SlotCreatePopup& slot) -> void;

    auto
    unset_create_popup_func () -> void;

    auto
    set_primary (bool primary = true) -> void;

    auto
    get_primary () const -> bool;

    auto
    set_child (Widget& child) -> void;

    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_menu_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_direction () -> glib::PropertyProxy<ArrowType>;

    auto
    property_direction () const -> glib::PropertyProxy_ReadOnly<ArrowType>;

    auto
    property_popover () -> glib::PropertyProxy<Popover*>;

    auto
    property_popover () const -> glib::PropertyProxy_ReadOnly<Popover*>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_always_show_arrow () -> glib::PropertyProxy<bool>;

    auto
    property_always_show_arrow () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_frame () -> glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary () -> glib::PropertyProxy<bool>;

    auto
    property_primary () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMenuButton* object, bool take_copy = false) -> gtk::MenuButton*;
} // namespace glib

#endif
