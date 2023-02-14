
#ifndef _GTKMM_MENUBUTTON_H
#define _GTKMM_MENUBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/popover.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMenuButton = struct _GtkMenuButton;
using GtkMenuButtonClass = struct _GtkMenuButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API MenuButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API MenuButton : public Widget
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
    friend GTKMM_API class MenuButton_Class;
    static CppClassType menubutton_class_;

  protected:
    explicit MenuButton (const Glib::ConstructParams& construct_params);
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

    void
    set_popover (Popover& popover);

    void
    unset_popover ();

    auto
    get_popover () -> Popover*;

    auto
    get_popover () const -> const Popover*;

    void
    set_direction (ArrowType direction);

    auto
    get_direction () const -> ArrowType;

    void
    set_menu_model (const Glib::RefPtr<const Gio::MenuModel>& menu_model);

    void
    unset_menu_model ();

    auto
    get_menu_model () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_menu_model () const -> Glib::RefPtr<const Gio::MenuModel>;

    void
    set_icon_name (const Glib::ustring& icon_name);

    auto
    get_icon_name () const -> Glib::ustring;

    void
    set_always_show_arrow (bool always_show_arrow = true);

    auto
    get_always_show_arrow () const -> bool;

    void
    set_label (const Glib::ustring& label);

    auto
    get_label () const -> Glib::ustring;

    void
    set_use_underline (bool use_underline = true);

    auto
    get_use_underline () const -> bool;

    void
    set_has_frame (bool has_frame = true);

    auto
    get_has_frame () const -> bool;

    void
    popup ();

    void
    popdown ();

    using SlotCreatePopup = sigc::slot<void ()>;

    void
    set_create_popup_func (const SlotCreatePopup& slot);

    void
    unset_create_popup_func ();

    void
    set_primary (bool primary = true);

    auto
    get_primary () const -> bool;

    void
    set_child (Widget& child);

    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_menu_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_direction () -> Glib::PropertyProxy<ArrowType>;

    auto
    property_direction () const -> Glib::PropertyProxy_ReadOnly<ArrowType>;

    auto
    property_popover () -> Glib::PropertyProxy<Popover*>;

    auto
    property_popover () const -> Glib::PropertyProxy_ReadOnly<Popover*>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_always_show_arrow () -> Glib::PropertyProxy<bool>;

    auto
    property_always_show_arrow () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_primary () -> Glib::PropertyProxy<bool>;

    auto
    property_primary () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkMenuButton* object, bool take_copy = false) -> Gtk::MenuButton*;
} // namespace Glib

#endif
