// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CELLRENDERERTOGGLE_H
#define _GTKMM_CELLRENDERERTOGGLE_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm-glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm-gtk/cellrenderer.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRendererToggle = struct _GtkCellRendererToggle;
using GtkCellRendererToggleClass = struct _GtkCellRendererToggleClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API CellRendererToggle_Class;
}
  #endif

namespace Gtk
{

  class GTKMM_API CellRendererToggle : public CellRenderer
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef CellRendererToggle CppObjectType;
    typedef CellRendererToggle_Class CppClassType;
    typedef GtkCellRendererToggle BaseObjectType;
    typedef GtkCellRendererToggleClass BaseClassType;
  #endif

    CellRendererToggle (CellRendererToggle&& src) noexcept;
    auto
    operator= (CellRendererToggle&& src) noexcept -> CellRendererToggle&;

    CellRendererToggle (const CellRendererToggle&) = delete;
    auto
    operator= (const CellRendererToggle&) -> CellRendererToggle& = delete;

    ~CellRendererToggle () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class CellRendererToggle_Class;
    static CppClassType cellrenderertoggle_class_;

  protected:
    explicit CellRendererToggle (const Glib::ConstructParams& construct_params);
    explicit CellRendererToggle (GtkCellRendererToggle* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkCellRendererToggle*
    {
      return reinterpret_cast<GtkCellRendererToggle*> (gobject_);
    }

    auto
    gobj () const -> const GtkCellRendererToggle*
    {
      return reinterpret_cast<GtkCellRendererToggle*> (gobject_);
    }

  private:
  public:
    CellRendererToggle ();

    auto
    get_radio () const -> bool;

    auto
    set_radio (bool radio = true) -> void;

    auto
    get_active () const -> bool;

    auto
    set_active (bool setting = true) -> void;

    auto
    get_activatable () const -> bool;

    auto
    set_activatable (bool setting = true) -> void;

    auto
    signal_toggled () -> Glib::SignalProxy<void (const Glib::ustring&)>;

    auto
    property_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_activatable () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_active () -> Glib::PropertyProxy<bool>;

    auto
    property_active () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_inconsistent () -> Glib::PropertyProxy<bool>;

    auto
    property_inconsistent () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_radio () -> Glib::PropertyProxy<bool>;

    auto
    property_radio () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    _property_renderable () -> Glib::PropertyProxy_Base override;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkCellRendererToggle* object, bool take_copy = false) -> Gtk::CellRendererToggle*;
} // namespace Glib

#endif

#endif
