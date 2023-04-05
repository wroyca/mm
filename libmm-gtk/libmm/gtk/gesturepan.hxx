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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GesturePan_Class;
}
#endif

namespace gtk
{

  enum class PanDirection
  {
    LEFT,
    RIGHT,
    UP,
    DOWN
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::PanDirection>
    : public glib::Value_Enum<gtk::PanDirection>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
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
    explicit GesturePan (const glib::ConstructParams& construct_params);
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
    create (Orientation orientation) -> glib::RefPtr<GesturePan>;

    auto
    get_orientation () const -> Orientation;

    auto
    set_orientation (Orientation orientation) -> void;

    auto
    signal_pan () -> glib::SignalProxy<void (PanDirection, double)>;

    auto
    property_orientation () -> glib::PropertyProxy<Orientation>;

    auto
    property_orientation () const -> glib::PropertyProxy_ReadOnly<Orientation>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGesturePan* object, bool take_copy = false) -> glib::RefPtr<gtk::GesturePan>;
} // namespace glib

#endif
