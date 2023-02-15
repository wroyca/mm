// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_URILAUNCHER_H
#define _GTKMM_URILAUNCHER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API UriLauncher_Class;
}
#endif

namespace Gtk
{
  class Window;

  class GTKMM_API UriLauncher : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UriLauncher;
    using CppClassType = UriLauncher_Class;
    using BaseObjectType = GtkUriLauncher;
    using BaseClassType = GtkUriLauncherClass;

    UriLauncher (const UriLauncher&) = delete;
    auto
    operator= (const UriLauncher&) -> UriLauncher& = delete;

  private:
    friend class UriLauncher_Class;
    static CppClassType urilauncher_class_;

  protected:
    explicit UriLauncher (const Glib::ConstructParams& construct_params);
    explicit UriLauncher (GtkUriLauncher* castitem);

#endif

  public:
    UriLauncher (UriLauncher&& src) noexcept;
    auto
    operator= (UriLauncher&& src) noexcept -> UriLauncher&;

    ~UriLauncher () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkUriLauncher*
    {
      return reinterpret_cast<GtkUriLauncher*> (gobject_);
    }

    auto
    gobj () const -> const GtkUriLauncher*
    {
      return reinterpret_cast<GtkUriLauncher*> (gobject_);
    }

    auto
    gobj_copy () -> GtkUriLauncher*;

  private:
  protected:
    explicit UriLauncher (const Glib::ustring& uri);

  public:
    static auto
    create (const Glib::ustring& uri = {}) -> Glib::RefPtr<UriLauncher>;

    auto
    get_uri () const -> Glib::ustring;

    auto
    set_uri (const Glib::ustring& uri) -> void;

    auto
    launch (Window& parent,
            const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch (const Gio::SlotAsyncReady& slot,
            const Glib::RefPtr<Gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch_finish (const Glib::RefPtr<Gio::AsyncResult>& result) const -> bool;

    auto
    property_uri () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_uri () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkUriLauncher* object, bool take_copy = false) -> Glib::RefPtr<Gtk::UriLauncher>;
} // namespace Glib

#endif
