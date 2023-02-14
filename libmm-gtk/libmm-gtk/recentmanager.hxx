// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_RECENTMANAGER_H
#define _GTKMM_RECENTMANAGER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-glib/object.hxx>
#include <libmm-gtk/recentinfo.hxx>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRecentManager = struct _GtkRecentManager;
using GtkRecentManagerClass = struct _GtkRecentManagerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API RecentManager_Class;
}
#endif

namespace Gtk
{

  class RecentManagerError : public Glib::Error
  {
  public:
    enum Code
    {
      NOT_FOUND,
      INVALID_URI,
      INVALID_ENCODING,
      NOT_REGISTERED,
      READ,
      WRITE,
      UNKNOWN
    };

    GTKMM_API
    RecentManagerError (Code error_code, const Glib::ustring& error_message);
    GTKMM_API explicit RecentManagerError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static void
    throw_func (GError* gobject);

    friend GTKMM_API void
    wrap_init ();

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::RecentManagerError::Code>
    : public Glib::Value_Enum<Gtk::RecentManagerError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API RecentManager : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = RecentManager;
    using CppClassType = RecentManager_Class;
    using BaseObjectType = GtkRecentManager;
    using BaseClassType = GtkRecentManagerClass;

    RecentManager (const RecentManager&) = delete;
    auto
    operator= (const RecentManager&) -> RecentManager& = delete;

  private:
    friend class RecentManager_Class;
    static CppClassType recentmanager_class_;

  protected:
    explicit RecentManager (const Glib::ConstructParams& construct_params);
    explicit RecentManager (GtkRecentManager* castitem);

#endif

  public:
    RecentManager (RecentManager&& src) noexcept;
    auto
    operator= (RecentManager&& src) noexcept -> RecentManager&;

    ~RecentManager () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkRecentManager*
    {
      return reinterpret_cast<GtkRecentManager*> (gobject_);
    }

    auto
    gobj () const -> const GtkRecentManager*
    {
      return reinterpret_cast<GtkRecentManager*> (gobject_);
    }

    auto
    gobj_copy () -> GtkRecentManager*;

  private:
  protected:
    RecentManager ();

  public:
    static auto
    create () -> Glib::RefPtr<RecentManager>;

    static auto
    get_default () -> Glib::RefPtr<RecentManager>;

    class Data
    {
    public:
      Glib::ustring display_name;
      Glib::ustring description;

      Glib::ustring mime_type;

      Glib::ustring app_name;
      Glib::ustring app_exec;

      std::vector<Glib::ustring> groups;

      bool is_private;
    };

    auto
    add_item (const Glib::ustring& uri) -> bool;

    auto
    add_item (const Glib::ustring& uri, const Data& recent_data) -> bool;

    auto
    remove_item (const Glib::ustring& uri) -> bool;

    auto
    lookup_item (const Glib::ustring& uri) -> Glib::RefPtr<RecentInfo>;

    auto
    lookup_item (const Glib::ustring& uri) const
        -> Glib::RefPtr<const RecentInfo>;

    auto
    has_item (const Glib::ustring& uri) const -> bool;

    auto
    move_item (const Glib::ustring& uri, const Glib::ustring& new_uri) -> bool;

    auto
    get_items () const -> std::vector<Glib::RefPtr<RecentInfo>>;

    auto
    purge_items () -> int;

    auto
    signal_changed () -> Glib::SignalProxy<void ()>;

    auto
    property_filename () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual void
    on_changed ();
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkRecentManager* object, bool take_copy = false) -> Glib::RefPtr<Gtk::RecentManager>;
} // namespace Glib

#endif
