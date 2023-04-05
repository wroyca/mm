// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSSHORTCUT_H
#define _GTKMM_SHORTCUTSSHORTCUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/icon.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsShortcut = struct _GtkShortcutsShortcut;
using GtkShortcutsShortcutClass = struct _GtkShortcutsShortcutClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutsShortcut_Class;
}
#endif

namespace gtk
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

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ShortcutType>
    : public glib::Value_Enum<gtk::ShortcutType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsShortcut : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class ShortcutsShortcut_Class;
    static CppClassType shortcutsshortcut_class_;

  protected:
    explicit ShortcutsShortcut (const glib::ConstructParams& construct_params);
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
    property_accelerator () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_accelerator () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_icon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_icon_set () -> glib::PropertyProxy<bool>;

    auto
    property_icon_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_subtitle () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_subtitle () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_subtitle_set () -> glib::PropertyProxy<bool>;

    auto
    property_subtitle_set () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_direction () -> glib::PropertyProxy<TextDirection>;

    auto
    property_direction () const -> glib::PropertyProxy_ReadOnly<TextDirection>;

    auto
    property_shortcut_type () -> glib::PropertyProxy<ShortcutType>;

    auto
    property_shortcut_type () const
        -> glib::PropertyProxy_ReadOnly<ShortcutType>;

    auto
    property_action_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_action_name () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutsShortcut* object, bool take_copy = false) -> gtk::ShortcutsShortcut*;
} // namespace glib

#endif
