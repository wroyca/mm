// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUT_H
#define _GTKMM_SHORTCUT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/shortcutaction.hxx>
#include <libmm/gtk/shortcuttrigger.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Shortcut_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Shortcut : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Shortcut;
    using CppClassType = Shortcut_Class;
    using BaseObjectType = GtkShortcut;
    using BaseClassType = GtkShortcutClass;

    Shortcut (const Shortcut&) = delete;
    auto
    operator= (const Shortcut&) -> Shortcut& = delete;

  private:
    friend class Shortcut_Class;
    static CppClassType shortcut_class_;

  protected:
    explicit Shortcut (const Glib::ConstructParams& construct_params);
    explicit Shortcut (GtkShortcut* castitem);

#endif

  public:
    Shortcut (Shortcut&& src) noexcept;
    auto
    operator= (Shortcut&& src) noexcept -> Shortcut&;

    ~Shortcut () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcut*
    {
      return reinterpret_cast<GtkShortcut*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcut*
    {
      return reinterpret_cast<GtkShortcut*> (gobject_);
    }

    auto
    gobj_copy () -> GtkShortcut*;

  private:
  protected:
    explicit Shortcut (const Glib::RefPtr<const ShortcutTrigger>& trigger,
                       const Glib::RefPtr<const ShortcutAction>& action);

  public:
    static auto
    create (const Glib::RefPtr<const ShortcutTrigger>& trigger,
            const Glib::RefPtr<const ShortcutAction>& action)
        -> Glib::RefPtr<Shortcut>;

    auto
    get_trigger () const -> Glib::RefPtr<ShortcutTrigger>;

    auto
    set_trigger (const Glib::RefPtr<const ShortcutTrigger>& trigger) -> void;

    auto
    get_action () const -> Glib::RefPtr<ShortcutAction>;

    auto
    set_trigger (const Glib::RefPtr<const ShortcutAction>& action) -> void;

    auto
    get_arguments () const -> Glib::VariantBase;

    auto
    set_arguments (const Glib::VariantBase& args) const -> void;

    auto
    property_trigger () -> Glib::PropertyProxy<Glib::RefPtr<ShortcutTrigger>>;

    auto
    property_trigger () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutTrigger>>;

    auto
    property_action () -> Glib::PropertyProxy<Glib::RefPtr<ShortcutAction>>;

    auto
    property_action () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ShortcutAction>>;

    auto
    property_arguments () -> Glib::PropertyProxy<Glib::VariantBase>;

    auto
    property_arguments () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcut* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Shortcut>;
} // namespace Glib

#endif
