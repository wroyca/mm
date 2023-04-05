// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_URILAUNCHER_H
#define _GTKMM_URILAUNCHER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/gio/cancellable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT UriLauncher_Class;
}
#endif

namespace gtk
{
  class Window;

  class LIBMM_GTK_SYMEXPORT UriLauncher : public glib::Object
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
    explicit UriLauncher (const glib::ConstructParams& construct_params);
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
    explicit UriLauncher (const glib::ustring& uri);

  public:
    static auto
    create (const glib::ustring& uri = {}) -> glib::RefPtr<UriLauncher>;

    auto
    get_uri () const -> glib::ustring;

    auto
    set_uri (const glib::ustring& uri) -> void;

    auto
    launch (Window& parent,
            const gio::SlotAsyncReady& slot,
            const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch (const gio::SlotAsyncReady& slot,
            const glib::RefPtr<gio::Cancellable>& cancellable = {}) const
        -> void;

    auto
    launch_finish (const glib::RefPtr<gio::AsyncResult>& result) const -> bool;

    auto
    property_uri () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_uri () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkUriLauncher* object, bool take_copy = false) -> glib::RefPtr<gtk::UriLauncher>;
} // namespace glib

#endif
