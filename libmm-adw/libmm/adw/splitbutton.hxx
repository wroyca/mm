// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_SPLITBUTTON_H
#define _LIBADWAITAMM_SPLITBUTTON_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT split_button_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT split_button : public gtk::Widget,
                      public gtk::Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = split_button;
    using CppClassType = split_button_class;
    using BaseObjectType = AdwSplitButton;
    using BaseClassType = AdwSplitButtonClass;
#endif

    split_button (split_button&& src) noexcept;
    auto
    operator= (split_button&& src) noexcept -> split_button&;

    split_button (const split_button&) = delete;
    auto
    operator= (const split_button&) -> split_button& = delete;

    ~split_button () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class split_button_class;
    static CppClassType splitbutton_class_;

  protected:
    explicit split_button (const glib::ConstructParams& construct_params);
    explicit split_button (AdwSplitButton* castitem);

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
    split_button ();

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_direction () const -> gtk::ArrowType;

    auto
    get_dropdown_tooltip () const -> glib::ustring;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_label () const -> glib::ustring;

    auto
    get_menu_model () const -> glib::RefPtr<gio::MenuModel>;

    auto
    get_popover () const -> gtk::Popover*;

    auto
    get_use_underline () const -> bool;

    auto
    popdown () -> void;

    auto
    popup () -> void;

    auto
    set_child (gtk::Widget* child) -> void;

    auto
    set_direction (gtk::ArrowType direction) -> void;

    auto
    set_dropdown_tooltip (const glib::ustring& dropdown_tooltip) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    set_menu_model (const glib::RefPtr<gio::MenuModel>& menu_model) -> void;

    auto
    set_popover (gtk::Popover* popover) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_direction () -> glib::PropertyProxy<gtk::ArrowType>;

    auto
    property_direction () const -> glib::PropertyProxy_ReadOnly<gtk::ArrowType>;

    auto
    property_dropdown_tooltip () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_dropdown_tooltip () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_menu_model () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_menu_model () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

    auto
    property_popover () -> glib::PropertyProxy<gtk::Popover*>;

    auto
    property_popover () const -> glib::PropertyProxy_ReadOnly<gtk::Popover*>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_activate () -> glib::SignalProxy<void ()>;

    auto
    signal_clicked () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwSplitButton* object, bool take_copy = false) -> adw::split_button*;
}

#endif
