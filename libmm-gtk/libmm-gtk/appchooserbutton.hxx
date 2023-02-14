// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_APPCHOOSERBUTTON_H
#define _GTKMM_APPCHOOSERBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/appchooser.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooserButton = struct _GtkAppChooserButton;
using GtkAppChooserButtonClass = struct _GtkAppChooserButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AppChooserButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API AppChooserButton : public Widget,
                                     public AppChooser
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef AppChooserButton CppObjectType;
    typedef AppChooserButton_Class CppClassType;
    typedef GtkAppChooserButton BaseObjectType;
    typedef GtkAppChooserButtonClass BaseClassType;
#endif

    AppChooserButton (AppChooserButton&& src) noexcept;
    auto
    operator= (AppChooserButton&& src) noexcept -> AppChooserButton&;

    AppChooserButton (const AppChooserButton&) = delete;
    auto
    operator= (const AppChooserButton&) -> AppChooserButton& = delete;

    ~AppChooserButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class AppChooserButton_Class;
    static CppClassType appchooserbutton_class_;

  protected:
    explicit AppChooserButton (const Glib::ConstructParams& construct_params);
    explicit AppChooserButton (GtkAppChooserButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAppChooserButton*
    {
      return reinterpret_cast<GtkAppChooserButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooserButton*
    {
      return reinterpret_cast<GtkAppChooserButton*> (gobject_);
    }

  private:
  public:
    explicit AppChooserButton (const Glib::ustring& content_type);

    void
    append_separator ();

    void
    append_custom_item (const Glib::ustring& name,
                        const Glib::ustring& label,
                        const Glib::RefPtr<Gio::Icon>& icon);

    void
    set_active_custom_item (const Glib::ustring& name);

    void
    set_show_dialog_item (bool setting = true);

    auto
    get_show_dialog_item () const -> bool;

    void
    set_heading (const Glib::ustring& heading);

    auto
    get_heading () const -> Glib::ustring;

    void
    set_show_default_item (bool setting = true);

    auto
    get_show_default_item () const -> bool;

    void
    set_modal (bool modal = true);

    auto
    get_modal () const -> bool;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    signal_custom_item_activated (const Glib::ustring& custom_item_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    property_show_dialog_item () -> Glib::PropertyProxy<bool>;

    auto
    property_show_dialog_item () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_heading () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_show_default_item () -> Glib::PropertyProxy<bool>;

    auto
    property_show_default_item () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_modal () -> Glib::PropertyProxy<bool>;

    auto
    property_modal () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkAppChooserButton* object, bool take_copy = false) -> Gtk::AppChooserButton*;
} // namespace Glib

#endif
