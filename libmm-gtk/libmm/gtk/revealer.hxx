// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_REVEALER_H
#define _GTKMM_REVEALER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRevealer = struct _GtkRevealer;
using GtkRevealerClass = struct _GtkRevealerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Revealer_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Revealer : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Revealer CppObjectType;
    typedef Revealer_Class CppClassType;
    typedef GtkRevealer BaseObjectType;
    typedef GtkRevealerClass BaseClassType;
#endif

    Revealer (Revealer&& src) noexcept;
    auto
    operator= (Revealer&& src) noexcept -> Revealer&;

    Revealer (const Revealer&) = delete;
    auto
    operator= (const Revealer&) -> Revealer& = delete;

    ~Revealer () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Revealer_Class;
    static CppClassType revealer_class_;

  protected:
    explicit Revealer (const Glib::ConstructParams& construct_params);
    explicit Revealer (GtkRevealer* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkRevealer*
    {
      return reinterpret_cast<GtkRevealer*> (gobject_);
    }

    auto
    gobj () const -> const GtkRevealer*
    {
      return reinterpret_cast<GtkRevealer*> (gobject_);
    }

  private:
  public:
    Revealer ();

    auto
    get_reveal_child () const -> bool;

    auto
    set_reveal_child (bool reveal_child = true) -> void;

    auto
    get_child_revealed () const -> bool;

    auto
    get_transition_duration () const -> guint;

    auto
    set_transition_duration (guint duration) -> void;

    auto
    get_transition_type () const -> RevealerTransitionType;

    auto
    set_transition_type (RevealerTransitionType transition) -> void;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_transition_type () -> Glib::PropertyProxy<RevealerTransitionType>;

    auto
    property_transition_type () const
        -> Glib::PropertyProxy_ReadOnly<RevealerTransitionType>;

    auto
    property_transition_duration () -> Glib::PropertyProxy<guint>;

    auto
    property_transition_duration () const
        -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_reveal_child () -> Glib::PropertyProxy<bool>;

    auto
    property_reveal_child () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child_revealed () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkRevealer* object, bool take_copy = false) -> Gtk::Revealer*;
} // namespace Glib

#endif
