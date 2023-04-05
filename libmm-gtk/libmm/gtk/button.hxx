// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUTTON_H
#define _GTKMM_BUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/actionable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkButton = struct _GtkButton;
using GtkButtonClass = struct _GtkButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Button_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Button : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class Button_Class;
    static CppClassType button_class_;

  protected:
    explicit Button (const glib::ConstructParams& construct_params);
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

    explicit Button (const glib::ustring& label, bool mnemonic = false);

    auto
    set_has_frame (bool has_frame = true) -> void;

    auto
    get_has_frame () const -> bool;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    get_label () const -> glib::ustring;

    auto
    set_use_underline (bool use_underline = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    set_image_from_icon_name (const glib::ustring& icon_name,
                              IconSize size = IconSize::INHERIT,
                              bool use_fallback = false) -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    signal_clicked () -> glib::SignalProxy<void ()>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_has_frame () -> glib::PropertyProxy<bool>;

    auto
    property_has_frame () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual auto
    on_clicked () -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkButton* object, bool take_copy = false) -> gtk::Button*;
} // namespace glib

#endif
