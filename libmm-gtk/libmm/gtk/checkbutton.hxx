// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CHECKBUTTON_H
#define _GTKMM_CHECKBUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/actionable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCheckButton = struct _GtkCheckButton;
using GtkCheckButtonClass = struct _GtkCheckButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CheckButton_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CheckButton : public Widget,
                                public Actionable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CheckButton CppObjectType;
    typedef CheckButton_Class CppClassType;
    typedef GtkCheckButton BaseObjectType;
    typedef GtkCheckButtonClass BaseClassType;
#endif

    CheckButton (CheckButton&& src) noexcept;
    auto
    operator= (CheckButton&& src) noexcept -> CheckButton&;

    CheckButton (const CheckButton&) = delete;
    auto
    operator= (const CheckButton&) -> CheckButton& = delete;

    ~CheckButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class CheckButton_Class;
    static CppClassType checkbutton_class_;

  protected:
    explicit CheckButton (const glib::ConstructParams& construct_params);
    explicit CheckButton (GtkCheckButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCheckButton*
    {
      return reinterpret_cast<GtkCheckButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkCheckButton*
    {
      return reinterpret_cast<GtkCheckButton*> (gobject_);
    }

  private:
  public:
    CheckButton ();

    explicit CheckButton (const glib::ustring& label, bool mnemonic = false);

    auto
    set_inconsistent (bool inconsistent = true) -> void;

    auto
    get_inconsistent () const -> bool;

    auto
    set_active (bool setting = true) -> void;

    auto
    get_active () const -> bool;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    get_label () const -> glib::ustring;

    auto
    set_use_underline (bool setting = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    set_group (CheckButton& group) -> void;
    auto
    unset_group () -> void;

    auto
    signal_toggled () -> glib::SignalProxy<void ()>;

    auto
    property_active () -> glib::PropertyProxy<bool>;

    auto
    property_active () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_group () -> glib::PropertyProxy_WriteOnly<CheckButton*>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_inconsistent () -> glib::PropertyProxy<bool>;

    auto
    property_inconsistent () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual auto
    on_toggled () -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCheckButton* object, bool take_copy = false) -> gtk::CheckButton*;
} // namespace glib

#endif
