// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LEVELBAR_H
#define _GTKMM_LEVELBAR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLevelBar = struct _GtkLevelBar;
using GtkLevelBarClass = struct _GtkLevelBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT LevelBar_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT LevelBar : public Widget,
                             public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef LevelBar CppObjectType;
    typedef LevelBar_Class CppClassType;
    typedef GtkLevelBar BaseObjectType;
    typedef GtkLevelBarClass BaseClassType;
#endif

    LevelBar (LevelBar&& src) noexcept;
    auto
    operator= (LevelBar&& src) noexcept -> LevelBar&;

    LevelBar (const LevelBar&) = delete;
    auto
    operator= (const LevelBar&) -> LevelBar& = delete;

    ~LevelBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class LevelBar_Class;
    static CppClassType levelbar_class_;

  protected:
    explicit LevelBar (const glib::ConstructParams& construct_params);
    explicit LevelBar (GtkLevelBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkLevelBar*
    {
      return reinterpret_cast<GtkLevelBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkLevelBar*
    {
      return reinterpret_cast<GtkLevelBar*> (gobject_);
    }

  private:
  public:
    enum class Mode
    {
      CONTINUOUS,
      DISCRETE
    };

    LevelBar ();

    auto
    set_mode (Mode mode) -> void;

    auto
    get_mode () const -> Mode;

    auto
    set_value (double value) -> void;

    auto
    get_value () const -> double;

    auto
    set_min_value (double value) -> void;

    auto
    get_min_value () const -> double;

    auto
    set_max_value (double value) -> void;

    auto
    get_max_value () const -> double;

    auto
    set_inverted (bool inverted = true) -> void;

    auto
    get_inverted () const -> bool;

    auto
    add_offset_value (const glib::ustring& name, double value) -> void;

    auto
    remove_offset_value (const glib::ustring& name) -> void;

    auto
    get_offset_value (const glib::ustring& name, double& value) const -> bool;

    auto
    signal_offset_changed (const glib::ustring& offset_name = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

    auto
    property_value () -> glib::PropertyProxy<double>;

    auto
    property_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_min_value () -> glib::PropertyProxy<double>;

    auto
    property_min_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_max_value () -> glib::PropertyProxy<double>;

    auto
    property_max_value () const -> glib::PropertyProxy_ReadOnly<double>;

    auto
    property_mode () -> glib::PropertyProxy<Mode>;

    auto
    property_mode () const -> glib::PropertyProxy_ReadOnly<Mode>;

    auto
    property_inverted () -> glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::LevelBar::Mode>
    : public glib::Value_Enum<gtk::LevelBar::Mode>
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
  wrap (GtkLevelBar* object, bool take_copy = false) -> gtk::LevelBar*;
} // namespace glib

#endif
