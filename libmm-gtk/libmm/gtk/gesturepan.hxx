// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTUREPAN_H
#define _GTKMM_GESTUREPAN_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/gesturedrag.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGesturePan = struct _GtkGesturePan;
using GtkGesturePanClass = struct _GtkGesturePanClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT GesturePan_Class;
}
#endif

namespace Gtk
{

  enum class PanDirection
  {
    LEFT,
    RIGHT,
    UP,
    DOWN
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::PanDirection>
    : public Glib::Value_Enum<Gtk::PanDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT GesturePan : public GestureDrag
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GesturePan;
    using CppClassType = GesturePan_Class;
    using BaseObjectType = GtkGesturePan;
    using BaseClassType = GtkGesturePanClass;

    GesturePan (const GesturePan&) = delete;
    auto
    operator= (const GesturePan&) -> GesturePan& = delete;

  private:
    friend class GesturePan_Class;
    static CppClassType gesturepan_class_;

  protected:
    explicit GesturePan (const Glib::ConstructParams& construct_params);
    explicit GesturePan (GtkGesturePan* castitem);

#endif

  public:
    GesturePan (GesturePan&& src) noexcept;
    auto
    operator= (GesturePan&& src) noexcept -> GesturePan&;

    ~GesturePan () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGesturePan*
    {
      return reinterpret_cast<GtkGesturePan*> (gobject_);
    }

    auto
    gobj () const -> const GtkGesturePan*
    {
      return reinterpret_cast<GtkGesturePan*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGesturePan*;

  private:
  protected:
    GesturePan ();

    explicit GesturePan (Orientation orientation);

  public:
    static auto
    create (Orientation orientation) -> Glib::RefPtr<GesturePan>;

    auto
    get_orientation () const -> Orientation;

    auto
    set_orientation (Orientation orientation) -> void;

    auto
    signal_pan () -> Glib::SignalProxy<void (PanDirection, double)>;

    auto
    property_orientation () -> Glib::PropertyProxy<Orientation>;

    auto
    property_orientation () const -> Glib::PropertyProxy_ReadOnly<Orientation>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGesturePan* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GesturePan>;
} // namespace Glib

#endif
