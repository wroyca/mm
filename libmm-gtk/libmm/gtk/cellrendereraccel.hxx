// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERACCEL_H
#define _GTKMM_CELLRENDERERACCEL_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/accelkey.hxx>
  #include <libmm/gtk/cellrenderertext.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererAccel = struct _GtkCellRendererAccel;
using GtkCellRendererAccelClass = struct _GtkCellRendererAccelClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT CellRendererAccel_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT CellRendererAccel : public CellRendererText
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
    friend LIBMM_GTK_SYMEXPORT class CellRendererAccel_Class;
    static CppClassType cellrendereraccel_class_;

  protected:
    explicit CellRendererAccel (const glib::ConstructParams& construct_params);
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
    signal_accel_edited () -> glib::SignalProxy<
        void (const glib::ustring&, guint, gdk::ModifierType, guint)>;

    auto
    signal_accel_cleared () -> glib::SignalProxy<void (const glib::ustring&)>;

    auto
    property_accel_key () -> glib::PropertyProxy<guint>;

    auto
    property_accel_key () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_accel_mods () -> glib::PropertyProxy<gdk::ModifierType>;

    auto
    property_accel_mods () const
        -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>;

    auto
    property_keycode () -> glib::PropertyProxy<guint>;

    auto
    property_keycode () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_accel_mode () -> glib::PropertyProxy<Mode>;

    auto
    property_accel_mode () const -> glib::PropertyProxy_ReadOnly<Mode>;

    auto
    _property_renderable () -> glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::CellRendererAccel::Mode>
    : public glib::Value_Enum<gtk::CellRendererAccel::Mode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
  #endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCellRendererAccel* object, bool take_copy = false) -> gtk::CellRendererAccel*;
} // namespace glib

#endif

#endif
