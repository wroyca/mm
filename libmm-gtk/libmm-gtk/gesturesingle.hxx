
#ifndef _GTKMM_GESTURESINGLE_H
#define _GTKMM_GESTURESINGLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/gesture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGestureSingle = struct _GtkGestureSingle;
using GtkGestureSingleClass = struct _GtkGestureSingleClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GestureSingle_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API GestureSingle : public Gesture
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
    explicit GestureSingle (const Glib::ConstructParams& construct_params);
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

    void
    set_touch_only (bool touch_only = true);

    auto
    get_exclusive () const -> bool;

    void
    set_exclusive (bool exclusive = true) const;

    auto
    get_button () const -> unsigned int;

    void
    set_button (unsigned int button = 0);

    auto
    get_current_button () const -> unsigned int;

    auto
    get_current_sequence () -> Gdk::EventSequence*;

    auto
    get_current_sequence () const -> const Gdk::EventSequence*;

    auto
    property_touch_only () -> Glib::PropertyProxy<bool>;

    auto
    property_touch_only () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_exclusive () -> Glib::PropertyProxy<bool>;

    auto
    property_exclusive () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_button () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_button () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkGestureSingle* object, bool take_copy = false) -> Glib::RefPtr<Gtk::GestureSingle>;
} // namespace Glib

#endif
