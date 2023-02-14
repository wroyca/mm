
#ifndef _GTKMM_LOCKBUTTON_H
#define _GTKMM_LOCKBUTTON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/permission.hxx>
#include <libmm-gtk/button.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLockButton = struct _GtkLockButton;
using GtkLockButtonClass = struct _GtkLockButtonClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API LockButton_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API LockButton : public Button
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef LockButton CppObjectType;
    typedef LockButton_Class CppClassType;
    typedef GtkLockButton BaseObjectType;
    typedef GtkLockButtonClass BaseClassType;
#endif

    LockButton (LockButton&& src) noexcept;
    auto
    operator= (LockButton&& src) noexcept -> LockButton&;

    LockButton (const LockButton&) = delete;
    auto
    operator= (const LockButton&) -> LockButton& = delete;

    ~LockButton () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class LockButton_Class;
    static CppClassType lockbutton_class_;

  protected:
    explicit LockButton (const Glib::ConstructParams& construct_params);
    explicit LockButton (GtkLockButton* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLockButton*
    {
      return reinterpret_cast<GtkLockButton*> (gobject_);
    }

    auto
    gobj () const -> const GtkLockButton*
    {
      return reinterpret_cast<GtkLockButton*> (gobject_);
    }

  private:
  public:
    LockButton ();

    explicit LockButton (const Glib::RefPtr<const Gio::Permission>& permission);

    auto
    get_permission () -> Glib::RefPtr<Gio::Permission>;

    auto
    get_permission () const -> Glib::RefPtr<const Gio::Permission>;

    void
    set_permission (const Glib::RefPtr<const Gio::Permission>& permission);

    void
    unset_permission ();

    auto
    property_permission ()
        -> Glib::PropertyProxy<Glib::RefPtr<Gio::Permission>>;

    auto
    property_permission () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Permission>>;

    auto
    property_text_lock () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text_lock () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_text_unlock () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text_unlock () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tooltip_lock () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip_lock () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tooltip_unlock () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip_unlock () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tooltip_not_authorized () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip_not_authorized () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkLockButton* object, bool take_copy = false) -> Gtk::LockButton*;
} // namespace Glib

#endif
