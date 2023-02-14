// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERACCEL_H
#define _GTKMM_CELLRENDERERACCEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/accelkey.hxx>
#include <libmm-gtk/cellrenderertext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererAccel = struct _GtkCellRendererAccel;
using GtkCellRendererAccelClass = struct _GtkCellRendererAccelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellRendererAccel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API CellRendererAccel : public CellRendererText
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererAccel CppObjectType;
    typedef CellRendererAccel_Class CppClassType;
    typedef GtkCellRendererAccel BaseObjectType;
    typedef GtkCellRendererAccelClass BaseClassType;
#endif

    CellRendererAccel (CellRendererAccel&& src) noexcept;
    auto
    operator= (CellRendererAccel&& src) noexcept -> CellRendererAccel&;

    CellRendererAccel (const CellRendererAccel&) = delete;
    auto
    operator= (const CellRendererAccel&) -> CellRendererAccel& = delete;

    ~CellRendererAccel () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class CellRendererAccel_Class;
    static CppClassType cellrendereraccel_class_;

  protected:
    explicit CellRendererAccel (const Glib::ConstructParams& construct_params);
    explicit CellRendererAccel (GtkCellRendererAccel* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkCellRendererAccel*
    {
      return reinterpret_cast<GtkCellRendererAccel*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererAccel*
    {
      return reinterpret_cast<GtkCellRendererAccel*> (gobject_);
    }

  private:
  public:
    enum class Mode
    {
      GTK,
      OTHER
    };

    CellRendererAccel ();

    auto
    signal_accel_edited () -> Glib::SignalProxy<
        void (const Glib::ustring&, guint, Gdk::ModifierType, guint)>;

    auto
    signal_accel_cleared () -> Glib::SignalProxy<void (const Glib::ustring&)>;

    auto
    property_accel_key () -> Glib::PropertyProxy<guint>;

    auto
    property_accel_key () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_accel_mods () -> Glib::PropertyProxy<Gdk::ModifierType>;

    auto
    property_accel_mods () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>;

    auto
    property_keycode () -> Glib::PropertyProxy<guint>;

    auto
    property_keycode () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_accel_mode () -> Glib::PropertyProxy<Mode>;

    auto
    property_accel_mode () const -> Glib::PropertyProxy_ReadOnly<Mode>;

    auto
    _property_renderable () -> Glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::CellRendererAccel::Mode>
    : public Glib::Value_Enum<Gtk::CellRendererAccel::Mode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkCellRendererAccel* object, bool take_copy = false) -> Gtk::CellRendererAccel*;
} // namespace Glib

#endif
