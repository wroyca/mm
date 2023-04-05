// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_TOGGLEBUTTON_H
#define _GTKMM_TOGGLEBUTTON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/button.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkToggleButton = struct _GtkToggleButton;
using GtkToggleButtonClass = struct _GtkToggleButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ToggleButton_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ToggleButton : public Button
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ToggleButton CppObjectType;
    typedef ToggleButton_Class CppClassType;
    typedef GtkToggleButton BaseObjectType;
    typedef GtkToggleButtonClass BaseClassType;
#endif

    ToggleButton (ToggleButton&& src) noexcept;
    auto
    operator= (ToggleButton&& src) noexcept -> ToggleButton&;

    ToggleButton (const ToggleButton&) = delete;
    auto
    operator= (const ToggleButton&) -> ToggleButton& = delete;

    ~ToggleButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ToggleButton_Class;
    static CppClassType togglebutton_class_;

  protected:
    explicit ToggleButton (const glib::ConstructParams& construct_params);
    explicit ToggleButton (GtkToggleButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkToggleButton*
    {
      return reinterpret_cast<GtkToggleButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkToggleButton*
    {
      return reinterpret_cast<GtkToggleButton*> (gobject_);
    }

  private:
  public:
    ToggleButton ();

    explicit ToggleButton (const glib::ustring& label, bool mnemonic = false);

    auto
    set_active (bool is_active = true) -> void;

    auto
    get_active () const -> bool;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    toggled () -> void;
#endif

    auto
    set_group (ToggleButton& group) -> void;
    auto
    unset_group () -> void;

    auto
    signal_toggled () -> glib::SignalProxy<void ()>;

    auto
    property_active () -> glib::PropertyProxy<bool>;

    auto
    property_active () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_group () -> glib::PropertyProxy_WriteOnly<ToggleButton*>;

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
  wrap (GtkToggleButton* object, bool take_copy = false) -> gtk::ToggleButton*;
} // namespace glib

#endif
