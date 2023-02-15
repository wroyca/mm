// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WINDOWCONTROLS_H
#define _GTKMM_WINDOWCONTROLS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT WindowControls_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT WindowControls : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef WindowControls CppObjectType;
    typedef WindowControls_Class CppClassType;
    typedef GtkWindowControls BaseObjectType;
    typedef GtkWindowControlsClass BaseClassType;
#endif

    WindowControls (WindowControls&& src) noexcept;
    auto
    operator= (WindowControls&& src) noexcept -> WindowControls&;

    WindowControls (const WindowControls&) = delete;
    auto
    operator= (const WindowControls&) -> WindowControls& = delete;

    ~WindowControls () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class WindowControls_Class;
    static CppClassType windowcontrols_class_;

  protected:
    explicit WindowControls (const Glib::ConstructParams& construct_params);
    explicit WindowControls (GtkWindowControls* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWindowControls*
    {
      return reinterpret_cast<GtkWindowControls*> (gobject_);
    }

    auto
    gobj () const -> const GtkWindowControls*
    {
      return reinterpret_cast<GtkWindowControls*> (gobject_);
    }

  private:
  public:
    explicit WindowControls (PackType side);

    auto
    set_side (PackType side) -> void;

    auto
    get_side () const -> PackType;

    auto
    set_decoration_layout (const Glib::ustring& layout) -> void;

    auto
    unset_decoration_layout () -> void;

    auto
    get_decoration_layout () const -> Glib::ustring;

    auto
    get_empty () const -> bool;

    auto
    property_side () -> Glib::PropertyProxy<PackType>;

    auto
    property_side () const -> Glib::PropertyProxy_ReadOnly<PackType>;

    auto
    property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_decoration_layout () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_empty () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkWindowControls* object, bool take_copy = false) -> Gtk::WindowControls*;
} // namespace Glib

#endif
