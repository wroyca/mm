// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACTIONBAR_H
#define _GTKMM_ACTIONBAR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActionBar = struct _GtkActionBar;
using GtkActionBarClass = struct _GtkActionBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ActionBar_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ActionBar : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class ActionBar_Class;
    static CppClassType actionbar_class_;

  protected:
    explicit ActionBar (const glib::ConstructParams& construct_params);
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

    auto
    pack_start (gtk::Widget& child) -> void;

    auto
    pack_end (gtk::Widget& child) -> void;

    auto
    remove (gtk::Widget& child) -> void;

    auto
    get_center_widget () -> Widget*;

    auto
    get_center_widget () const -> const Widget*;

    auto
    set_center_widget (Widget& center_widget) -> void;

    auto
    unset_center_widget () -> void;

    auto
    set_revealed (bool revealed = true) -> void;

    auto
    get_revealed () const -> bool;

    auto
    property_revealed () -> glib::PropertyProxy<bool>;

    auto
    property_revealed () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkActionBar* object, bool take_copy = false) -> gtk::ActionBar*;
} // namespace glib

#endif
