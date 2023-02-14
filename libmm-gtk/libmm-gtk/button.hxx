// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUTTON_H
#define _GTKMM_BUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/actionable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkButton = struct _GtkButton;
using GtkButtonClass = struct _GtkButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Button_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Button : public Widget,
                           public Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Button CppObjectType;
    typedef Button_Class CppClassType;
    typedef GtkButton BaseObjectType;
    typedef GtkButtonClass BaseClassType;
#endif

    Button (Button&& src) noexcept;
    auto
    operator= (Button&& src) noexcept -> Button&;

    Button (const Button&) = delete;
    auto
    operator= (const Button&) -> Button& = delete;

    ~Button () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Button_Class;
    static CppClassType button_class_;

  protected:
    explicit Button (const Glib::ConstructParams& construct_params);
    explicit Button (GtkButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkButton*
    {
      return reinterpret_cast<GtkButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkButton*
    {
      return reinterpret_cast<GtkButton*> (gobject_);
    }

  private:
  public:
    Button ();

    explicit Button (const Glib::ustring& label, bool mnemonic = false);

    void
    set_has_frame (bool has_frame = true);

    auto
    get_has_frame () const -> bool;

    void
    set_label (const Glib::ustring& label);

    auto
    get_label () const -> Glib::ustring;

    void
    set_use_underline (bool use_underline = true);

    auto
    get_use_underline () const -> bool;

    void
    set_icon_name (const Glib::ustring& icon_name);

    auto
    get_icon_name () const -> Glib::ustring;

    void
    set_image_from_icon_name (const Glib::ustring& icon_name,
                              IconSize size = IconSize::INHERIT,
                              bool use_fallback = false);

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    signal_clicked () -> Glib::SignalProxy<void ()>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_has_frame () -> Glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual void
    on_clicked ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkButton* object, bool take_copy = false) -> Gtk::Button*;
} // namespace Glib

#endif
