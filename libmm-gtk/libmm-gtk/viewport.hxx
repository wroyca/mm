// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_VIEWPORT_H
#define _GTKMM_VIEWPORT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/scrollable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkViewport = struct _GtkViewport;
using GtkViewportClass = struct _GtkViewportClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Viewport_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Viewport : public Widget,
                             public Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Viewport CppObjectType;
    typedef Viewport_Class CppClassType;
    typedef GtkViewport BaseObjectType;
    typedef GtkViewportClass BaseClassType;
#endif

    Viewport (Viewport&& src) noexcept;
    auto
    operator= (Viewport&& src) noexcept -> Viewport&;

    Viewport (const Viewport&) = delete;
    auto
    operator= (const Viewport&) -> Viewport& = delete;

    ~Viewport () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Viewport_Class;
    static CppClassType viewport_class_;

  protected:
    explicit Viewport (const Glib::ConstructParams& construct_params);
    explicit Viewport (GtkViewport* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkViewport*
    {
      return reinterpret_cast<GtkViewport*> (gobject_);
    }

    auto
    gobj () const -> const GtkViewport*
    {
      return reinterpret_cast<GtkViewport*> (gobject_);
    }

  private:
  public:
    explicit Viewport (const Glib::RefPtr<Adjustment>& hadjustment,
                       const Glib::RefPtr<Adjustment>& vadjustment);

    void
    set_scroll_to_focus (bool scroll_to_focus = true);

    auto
    get_scroll_to_focus () const -> bool;

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_scroll_to_focus () -> Glib::PropertyProxy<bool>;

    auto
    property_scroll_to_focus () const -> Glib::PropertyProxy_ReadOnly<bool>;

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
  wrap (GtkViewport* object, bool take_copy = false) -> Gtk::Viewport*;
} // namespace Glib

#endif
