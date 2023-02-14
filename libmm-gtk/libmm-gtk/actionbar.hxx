
#ifndef _GTKMM_ACTIONBAR_H
#define _GTKMM_ACTIONBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActionBar = struct _GtkActionBar;
using GtkActionBarClass = struct _GtkActionBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ActionBar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ActionBar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ActionBar CppObjectType;
    typedef ActionBar_Class CppClassType;
    typedef GtkActionBar BaseObjectType;
    typedef GtkActionBarClass BaseClassType;
#endif

    ActionBar (ActionBar&& src) noexcept;
    auto
    operator= (ActionBar&& src) noexcept -> ActionBar&;

    ActionBar (const ActionBar&) = delete;
    auto
    operator= (const ActionBar&) -> ActionBar& = delete;

    ~ActionBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ActionBar_Class;
    static CppClassType actionbar_class_;

  protected:
    explicit ActionBar (const Glib::ConstructParams& construct_params);
    explicit ActionBar (GtkActionBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkActionBar*
    {
      return reinterpret_cast<GtkActionBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkActionBar*
    {
      return reinterpret_cast<GtkActionBar*> (gobject_);
    }

  private:
  public:
    ActionBar ();

    void
    pack_start (Gtk::Widget& child);

    void
    pack_end (Gtk::Widget& child);

    void
    remove (Gtk::Widget& child);

    auto
    get_center_widget () -> Widget*;

    auto
    get_center_widget () const -> const Widget*;

    void
    set_center_widget (Widget& center_widget);

    void
    unset_center_widget ();

    void
    set_revealed (bool revealed = true);

    auto
    get_revealed () const -> bool;

    auto
    property_revealed () -> Glib::PropertyProxy<bool>;

    auto
    property_revealed () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkActionBar* object, bool take_copy = false) -> Gtk::ActionBar*;
} // namespace Glib

#endif
