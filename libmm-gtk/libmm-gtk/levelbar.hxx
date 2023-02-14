// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LEVELBAR_H
#define _GTKMM_LEVELBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkLevelBar = struct _GtkLevelBar;
using GtkLevelBarClass = struct _GtkLevelBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API LevelBar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API LevelBar : public Widget,
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
    friend GTKMM_API class LevelBar_Class;
    static CppClassType levelbar_class_;

  protected:
    explicit LevelBar (const Glib::ConstructParams& construct_params);
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

    void
    set_mode (Mode mode);

    auto
    get_mode () const -> Mode;

    void
    set_value (double value);

    auto
    get_value () const -> double;

    void
    set_min_value (double value);

    auto
    get_min_value () const -> double;

    void
    set_max_value (double value);

    auto
    get_max_value () const -> double;

    void
    set_inverted (bool inverted = true);

    auto
    get_inverted () const -> bool;

    void
    add_offset_value (const Glib::ustring& name, double value);

    void
    remove_offset_value (const Glib::ustring& name);

    auto
    get_offset_value (const Glib::ustring& name, double& value) const -> bool;

    auto
    signal_offset_changed (const Glib::ustring& offset_name = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    auto
    property_value () -> Glib::PropertyProxy<double>;

    auto
    property_value () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_min_value () -> Glib::PropertyProxy<double>;

    auto
    property_min_value () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_max_value () -> Glib::PropertyProxy<double>;

    auto
    property_max_value () const -> Glib::PropertyProxy_ReadOnly<double>;

    auto
    property_mode () -> Glib::PropertyProxy<Mode>;

    auto
    property_mode () const -> Glib::PropertyProxy_ReadOnly<Mode>;

    auto
    property_inverted () -> Glib::PropertyProxy<bool>;

    auto
    property_inverted () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::LevelBar::Mode>
    : public Glib::Value_Enum<Gtk::LevelBar::Mode>
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
  wrap (GtkLevelBar* object, bool take_copy = false) -> Gtk::LevelBar*;
} // namespace Glib

#endif
