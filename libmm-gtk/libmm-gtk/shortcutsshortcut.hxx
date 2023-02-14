
#ifndef _GTKMM_SHORTCUTSSHORTCUT_H
#define _GTKMM_SHORTCUTSSHORTCUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/icon.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsShortcut = struct _GtkShortcutsShortcut;
using GtkShortcutsShortcutClass = struct _GtkShortcutsShortcutClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutsShortcut_Class;
}
#endif

namespace Gtk
{

  enum class ShortcutType
  {
    ACCELERATOR,
    GESTURE_PINCH,
    GESTURE_STRETCH,
    GESTURE_ROTATE_CLOCKWISE,
    GESTURE_ROTATE_COUNTERCLOCKWISE,
    GESTURE_TWO_FINGER_SWIPE_LEFT,
    GESTURE_TWO_FINGER_SWIPE_RIGHT,
    GESTURE,
    GESTURE_SWIPE_LEFT,
    GESTURE_SWIPE_RIGHT
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::ShortcutType>
    : public Glib::Value_Enum<Gtk::ShortcutType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API ShortcutsShortcut : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ShortcutsShortcut CppObjectType;
    typedef ShortcutsShortcut_Class CppClassType;
    typedef GtkShortcutsShortcut BaseObjectType;
    typedef GtkShortcutsShortcutClass BaseClassType;
#endif

    ShortcutsShortcut (ShortcutsShortcut&& src) noexcept;
    auto
    operator= (ShortcutsShortcut&& src) noexcept -> ShortcutsShortcut&;

    ShortcutsShortcut (const ShortcutsShortcut&) = delete;
    auto
    operator= (const ShortcutsShortcut&) -> ShortcutsShortcut& = delete;

    ~ShortcutsShortcut () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ShortcutsShortcut_Class;
    static CppClassType shortcutsshortcut_class_;

  protected:
    explicit ShortcutsShortcut (const Glib::ConstructParams& construct_params);
    explicit ShortcutsShortcut (GtkShortcutsShortcut* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutsShortcut*
    {
      return reinterpret_cast<GtkShortcutsShortcut*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutsShortcut*
    {
      return reinterpret_cast<GtkShortcutsShortcut*> (gobject_);
    }

  private:
  public:
    ShortcutsShortcut ();

    auto
    property_accelerator () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_accelerator () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_icon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_icon_set () -> Glib::PropertyProxy<bool>;

    auto
    property_icon_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_subtitle () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_subtitle () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_subtitle_set () -> Glib::PropertyProxy<bool>;

    auto
    property_subtitle_set () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_direction () -> Glib::PropertyProxy<TextDirection>;

    auto
    property_direction () const -> Glib::PropertyProxy_ReadOnly<TextDirection>;

    auto
    property_shortcut_type () -> Glib::PropertyProxy<ShortcutType>;

    auto
    property_shortcut_type () const
        -> Glib::PropertyProxy_ReadOnly<ShortcutType>;

    auto
    property_action_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_action_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkShortcutsShortcut* object, bool take_copy = false) -> Gtk::ShortcutsShortcut*;
} // namespace Glib

#endif
