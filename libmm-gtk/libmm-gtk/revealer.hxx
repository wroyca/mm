
#ifndef _GTKMM_REVEALER_H
#define _GTKMM_REVEALER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRevealer = struct _GtkRevealer;
using GtkRevealerClass = struct _GtkRevealerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Revealer_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Revealer : public Widget
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
    friend GTKMM_API class Revealer_Class;
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

    void
    set_reveal_child (bool reveal_child = true);

    auto
    get_child_revealed () const -> bool;

    auto
    get_transition_duration () const -> guint;

    void
    set_transition_duration (guint duration);

    auto
    get_transition_type () const -> RevealerTransitionType;

    void
    set_transition_type (RevealerTransitionType transition);

    void
    set_child (Widget& child);
    void
    unset_child ();

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

  GTKMM_API
  auto
  wrap (GtkRevealer* object, bool take_copy = false) -> Gtk::Revealer*;
} // namespace Glib

#endif
