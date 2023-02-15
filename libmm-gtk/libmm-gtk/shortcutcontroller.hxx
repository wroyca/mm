// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTCONTROLLER_H
#define _GTKMM_SHORTCUTCONTROLLER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/enums.hxx>
#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/enums.hxx>
#include <libmm-gtk/eventcontroller.hxx>
#include <libmm-gtk/shortcut.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutController = struct _GtkShortcutController;
using GtkShortcutControllerClass = struct _GtkShortcutControllerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutController_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ShortcutController : public EventController,
                                       public Gio::ListModel,
                                       public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ShortcutController;
    using CppClassType = ShortcutController_Class;
    using BaseObjectType = GtkShortcutController;
    using BaseClassType = GtkShortcutControllerClass;

    ShortcutController (const ShortcutController&) = delete;
    auto
    operator= (const ShortcutController&) -> ShortcutController& = delete;

  private:
    friend class ShortcutController_Class;
    static CppClassType shortcutcontroller_class_;

  protected:
    explicit ShortcutController (const Glib::ConstructParams& construct_params);
    explicit ShortcutController (GtkShortcutController* castitem);

#endif

  public:
    ShortcutController (ShortcutController&& src) noexcept;
    auto
    operator= (ShortcutController&& src) noexcept -> ShortcutController&;

    ~ShortcutController () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutController*
    {
      return reinterpret_cast<GtkShortcutController*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutController*
    {
      return reinterpret_cast<GtkShortcutController*> (gobject_);
    }

    auto
    gobj_copy () -> GtkShortcutController*;

  private:
  protected:
    ShortcutController ();
    explicit ShortcutController (const Glib::RefPtr<Gio::ListModel>& model);

  public:
    static auto
    create () -> Glib::RefPtr<ShortcutController>;

    static auto
    create (const Glib::RefPtr<Gio::ListModel>& model)
        -> Glib::RefPtr<ShortcutController>;

    auto
    set_mnemonics_modifiers (Gdk::ModifierType modifiers) -> void;

    auto
    get_mnemonics_modifiers () const -> Gdk::ModifierType;

    auto
    set_scope (ShortcutScope scope) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_scope () const -> ShortcutScope;
#endif

    auto
    get_scope () const -> ShortcutScope;

    auto
    add_shortcut (const Glib::RefPtr<Shortcut>& shortcut) -> void;

    auto
    remove_shortcut (const Glib::RefPtr<const Shortcut>& shortcut) -> void;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_mnemonic_modifiers () -> Glib::PropertyProxy<Gdk::ModifierType>;

    auto
    property_mnemonic_modifiers () const
        -> Glib::PropertyProxy_ReadOnly<Gdk::ModifierType>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_scope () -> Glib::PropertyProxy<ShortcutScope>;

    auto
    property_scope () const -> Glib::PropertyProxy_ReadOnly<ShortcutScope>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkShortcutController* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ShortcutController>;
} // namespace Glib

#endif
