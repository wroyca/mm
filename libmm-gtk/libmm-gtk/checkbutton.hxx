
#ifndef _GTKMM_CHECKBUTTON_H
#define _GTKMM_CHECKBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/actionable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCheckButton = struct _GtkCheckButton;
using GtkCheckButtonClass = struct _GtkCheckButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CheckButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CheckButton : public Widget,
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
    friend GTKMM_API class CheckButton_Class;
    static CppClassType checkbutton_class_;

  protected:
    explicit CheckButton (const Glib::ConstructParams& construct_params);
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

    explicit CheckButton (const Glib::ustring& label, bool mnemonic = false);

    void
    set_inconsistent (bool inconsistent = true);

    auto
    get_inconsistent () const -> bool;

    void
    set_active (bool setting = true);

    auto
    get_active () const -> bool;

    void
    set_label (const Glib::ustring& label);

    auto
    get_label () const -> Glib::ustring;

    void
    set_use_underline (bool setting = true);

    auto
    get_use_underline () const -> bool;

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    void
    set_group (CheckButton& group);
    void
    unset_group ();

    auto
    signal_toggled () -> Glib::SignalProxy<void ()>;

    auto
    property_active () -> Glib::PropertyProxy<bool>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_group () -> Glib::PropertyProxy_WriteOnly<CheckButton*>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_inconsistent () -> Glib::PropertyProxy<bool>;

    auto
    property_inconsistent () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
    virtual void
    on_toggled ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCheckButton* object, bool take_copy = false) -> Gtk::CheckButton*;
} // namespace Glib

#endif
