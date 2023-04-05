// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTCONTROLLER_H
#define _GTKMM_SHORTCUTCONTROLLER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/enums.hxx>
#include <libmm/gtk/eventcontroller.hxx>
#include <libmm/gtk/shortcut.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutController = struct _GtkShortcutController;
using GtkShortcutControllerClass = struct _GtkShortcutControllerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutController_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutController : public EventController,
                                       public gio::ListModel,
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
    explicit ShortcutController (const glib::ConstructParams& construct_params);
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
    explicit ShortcutController (const glib::RefPtr<gio::ListModel>& model);

  public:
    static auto
    create () -> glib::RefPtr<ShortcutController>;

    static auto
    create (const glib::RefPtr<gio::ListModel>& model)
        -> glib::RefPtr<ShortcutController>;

    auto
    set_mnemonics_modifiers (gdk::ModifierType modifiers) -> void;

    auto
    get_mnemonics_modifiers () const -> gdk::ModifierType;

    auto
    set_scope (ShortcutScope scope) -> void;

#ifndef GTKMM_DISABLE_DEPRECATED

    auto
    set_scope () const -> ShortcutScope;
#endif

    auto
    get_scope () const -> ShortcutScope;

    auto
    add_shortcut (const glib::RefPtr<Shortcut>& shortcut) -> void;

    auto
    remove_shortcut (const glib::RefPtr<const Shortcut>& shortcut) -> void;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_mnemonic_modifiers () -> glib::PropertyProxy<gdk::ModifierType>;

    auto
    property_mnemonic_modifiers () const
        -> glib::PropertyProxy_ReadOnly<gdk::ModifierType>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

    auto
    property_scope () -> glib::PropertyProxy<ShortcutScope>;

    auto
    property_scope () const -> glib::PropertyProxy_ReadOnly<ShortcutScope>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutController* object, bool take_copy = false) -> glib::RefPtr<gtk::ShortcutController>;
} // namespace glib

#endif
