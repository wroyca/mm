// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPLITBUTTON_H
#define _LIBADWAITAMM_SPLITBUTTON_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT SplitButton_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT SplitButton : public Gtk::Widget,
                      public Gtk::Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef SplitButton CppObjectType;
    typedef SplitButton_Class CppClassType;
    typedef AdwSplitButton BaseObjectType;
    typedef AdwSplitButtonClass BaseClassType;
#endif

    SplitButton (SplitButton&& src) noexcept;
    auto
    operator= (SplitButton&& src) noexcept -> SplitButton&;

    SplitButton (const SplitButton&) = delete;
    auto
    operator= (const SplitButton&) -> SplitButton& = delete;

    ~SplitButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class SplitButton_Class;
    static CppClassType splitbutton_class_;

  protected:
    explicit SplitButton (const Glib::ConstructParams& construct_params);
    explicit SplitButton (AdwSplitButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwSplitButton*
    {
      return reinterpret_cast<AdwSplitButton*> (gobject_);
    }

    auto
    gobj () const -> const AdwSplitButton*
    {
      return reinterpret_cast<AdwSplitButton*> (gobject_);
    }

  private:
  public:
    SplitButton ();

    auto
    get_child () const -> Gtk::Widget*;

    auto
    get_direction () const -> Gtk::ArrowType;

    auto
    get_dropdown_tooltip () const -> Glib::ustring;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_label () const -> Glib::ustring;

    auto
    get_menu_model () const -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_popover () const -> Gtk::Popover*;

    auto
    get_use_underline () const -> bool;

    auto
    popdown () -> void;

    auto
    popup () -> void;

    auto
    set_child (Gtk::Widget* child) -> void;

    auto
    set_direction (Gtk::ArrowType direction) -> void;

    auto
    set_dropdown_tooltip (const Glib::ustring& dropdown_tooltip) -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_label (const Glib::ustring& label) -> void;

    auto
    set_menu_model (const Glib::RefPtr<Gio::MenuModel>& menu_model) -> void;

    auto
    set_popover (Gtk::Popover* popover) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_direction () -> Glib::PropertyProxy<Gtk::ArrowType>;

    auto
    property_direction () const -> Glib::PropertyProxy_ReadOnly<Gtk::ArrowType>;

    auto
    property_dropdown_tooltip () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_dropdown_tooltip () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_menu_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_popover () -> Glib::PropertyProxy<Gtk::Popover*>;

    auto
    property_popover () const -> Glib::PropertyProxy_ReadOnly<Gtk::Popover*>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> Glib::SignalProxy<void ()>;

    auto
    signal_clicked () -> Glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwSplitButton* object, bool take_copy = false) -> Adw::SplitButton*;
}

#endif
