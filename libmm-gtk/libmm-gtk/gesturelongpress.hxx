// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURELONGPRESS_H
#define _GTKMM_GESTURELONGPRESS_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/gesturesingle.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureLongPress = struct _GtkGestureLongPress;
using GtkGestureLongPressClass = struct _GtkGestureLongPressClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT GestureLongPress_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GestureLongPress : public GestureSingle
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureLongPress;
    using CppClassType = GestureLongPress_Class;
    using BaseObjectType = GtkGestureLongPress;
    using BaseClassType = GtkGestureLongPressClass;

    GestureLongPress (const GestureLongPress&) = delete;
    auto
    operator= (const GestureLongPress&) -> GestureLongPress& = delete;

  private:
    friend class GestureLongPress_Class;
    static CppClassType gesturelongpress_class_;

  protected:
    explicit GestureLongPress (const Glib::ConstructParams& construct_params);
    explicit GestureLongPress (GtkGestureLongPress* castitem);

#endif

  public:
    GestureLongPress (GestureLongPress&& src) noexcept;
    auto
    operator= (GestureLongPress&& src) noexcept -> GestureLongPress&;

    ~GestureLongPress () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureLongPress*
    {
      return reinterpret_cast<GtkGestureLongPress*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureLongPress*
    {
      return reinterpret_cast<GtkGestureLongPress*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureLongPress*;

  private:
  protected:
    GestureLongPress ();

  public:
    static auto
    create () -> Glib::RefPtr<GestureLongPress>;

    auto
    set_delay_factor (double delay_factor) -> void;

    auto
    get_delay_factor () const -> double;

    auto
    signal_pressed () -> Glib::SignalProxy<void (double, double)>;

    auto
    signal_cancelled () -> Glib::SignalProxy<void ()>;

    auto
    property_delay_factor () -> Glib::PropertyProxy<double>;

    auto
    property_delay_factor () const -> Glib::PropertyProxy_ReadOnly<double>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureLongPress* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureLongPress>;
} // namespace Glib

#endif
