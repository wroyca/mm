// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PASSWORDENTRY_H
#define _GTKMM_PASSWORDENTRY_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/editable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPasswordEntry = struct _GtkPasswordEntry;
using GtkPasswordEntryClass = struct _GtkPasswordEntryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API PasswordEntry_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API PasswordEntry : public Widget,
                                  public Editable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PasswordEntry CppObjectType;
    typedef PasswordEntry_Class CppClassType;
    typedef GtkPasswordEntry BaseObjectType;
    typedef GtkPasswordEntryClass BaseClassType;
#endif

    PasswordEntry (PasswordEntry&& src) noexcept;
    auto
    operator= (PasswordEntry&& src) noexcept -> PasswordEntry&;

    PasswordEntry (const PasswordEntry&) = delete;
    auto
    operator= (const PasswordEntry&) -> PasswordEntry& = delete;

    ~PasswordEntry () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class PasswordEntry_Class;
    static CppClassType passwordentry_class_;

  protected:
    explicit PasswordEntry (const Glib::ConstructParams& construct_params);
    explicit PasswordEntry (GtkPasswordEntry* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPasswordEntry*
    {
      return reinterpret_cast<GtkPasswordEntry*> (gobject_);
    }

    auto
    gobj () const -> const GtkPasswordEntry*
    {
      return reinterpret_cast<GtkPasswordEntry*> (gobject_);
    }

  private:
  public:
    PasswordEntry ();

    void
    set_show_peek_icon (bool show_peek_icon = true);

    auto
    get_show_peek_icon () const -> bool;

    void
    set_extra_menu (const Glib::RefPtr<Gio::MenuModel>& model);

    auto
    get_extra_menu () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_extra_menu () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    property_placeholder_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_placeholder_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_activates_default () -> Glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_peek_icon () -> Glib::PropertyProxy<bool>;

    auto
    property_show_peek_icon () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkPasswordEntry* object, bool take_copy = false) -> Gtk::PasswordEntry*;
} // namespace Glib

#endif
