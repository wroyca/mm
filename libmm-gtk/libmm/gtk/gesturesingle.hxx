// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GESTURESINGLE_H
#define _GTKMM_GESTURESINGLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/gesture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureSingle = struct _GtkGestureSingle;
using GtkGestureSingleClass = struct _GtkGestureSingleClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GestureSingle_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GestureSingle : public Gesture
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = GestureSingle;
    using CppClassType = GestureSingle_Class;
    using BaseObjectType = GtkGestureSingle;
    using BaseClassType = GtkGestureSingleClass;

    GestureSingle (const GestureSingle&) = delete;
    auto
    operator= (const GestureSingle&) -> GestureSingle& = delete;

  private:
    friend class GestureSingle_Class;
    static CppClassType gesturesingle_class_;

  protected:
    explicit GestureSingle (const glib::ConstructParams& construct_params);
    explicit GestureSingle (GtkGestureSingle* castitem);

#endif

  public:
    GestureSingle (GestureSingle&& src) noexcept;
    auto
    operator= (GestureSingle&& src) noexcept -> GestureSingle&;

    ~GestureSingle () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGestureSingle*
    {
      return reinterpret_cast<GtkGestureSingle*> (gobject_);
    }

    auto
    gobj () const -> const GtkGestureSingle*
    {
      return reinterpret_cast<GtkGestureSingle*> (gobject_);
    }

    auto
    gobj_copy () -> GtkGestureSingle*;

  private:
  protected:
    GestureSingle ();

  public:
    auto
    get_touch_only () const -> bool;

    auto
    set_touch_only (bool touch_only = true) -> void;

    auto
    get_exclusive () const -> bool;

    auto
    set_exclusive (bool exclusive = true) const -> void;

    auto
    get_button () const -> unsigned int;

    auto
    set_button (unsigned int button = 0) -> void;

    auto
    get_current_button () const -> unsigned int;

    auto
    get_current_sequence () -> gdk::EventSequence*;

    auto
    get_current_sequence () const -> const gdk::EventSequence*;

    auto
    property_touch_only () -> glib::PropertyProxy<bool>;

    auto
    property_touch_only () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_exclusive () -> glib::PropertyProxy<bool>;

    auto
    property_exclusive () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_button () -> glib::PropertyProxy<unsigned int>;

    auto
    property_button () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGestureSingle* object, bool take_copy = false) -> glib::RefPtr<gtk::GestureSingle>;
} // namespace glib

#endif
