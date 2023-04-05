// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_PASSWORDENTRY_H
#define _GTKMM_PASSWORDENTRY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/menumodel.hxx>
#include <libmm/gtk/editable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPasswordEntry = struct _GtkPasswordEntry;
using GtkPasswordEntryClass = struct _GtkPasswordEntryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT PasswordEntry_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT PasswordEntry : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class PasswordEntry_Class;
    static CppClassType passwordentry_class_;

  protected:
    explicit PasswordEntry (const glib::ConstructParams& construct_params);
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

    auto
    set_show_peek_icon (bool show_peek_icon = true) -> void;

    auto
    get_show_peek_icon () const -> bool;

    auto
    set_extra_menu (const glib::RefPtr<gio::MenuModel>& model) -> void;

    auto
    get_extra_menu () -> glib::RefPtr<gio::MenuModel>;

    auto
    get_extra_menu () const -> glib::RefPtr<const gio::MenuModel>;

    auto
    property_placeholder_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_placeholder_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_activates_default () -> glib::PropertyProxy<bool>;

    auto
    property_activates_default () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_show_peek_icon () -> glib::PropertyProxy<bool>;

    auto
    property_show_peek_icon () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_extra_menu () -> glib::PropertyProxy<glib::RefPtr<gio::MenuModel>>;

    auto
    property_extra_menu () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPasswordEntry* object, bool take_copy = false) -> gtk::PasswordEntry*;
} // namespace glib

#endif
