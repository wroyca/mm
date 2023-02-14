// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DIRECTORYLIST_H
#define _GTKMM_DIRECTORYLIST_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/file.hxx>
#include <libmm-gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API DirectoryList_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API DirectoryList : public Glib::Object,
                                  public Gio::ListModel
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = DirectoryList;
    using CppClassType = DirectoryList_Class;
    using BaseObjectType = GtkDirectoryList;
    using BaseClassType = GtkDirectoryListClass;

    DirectoryList (const DirectoryList&) = delete;
    auto
    operator= (const DirectoryList&) -> DirectoryList& = delete;

  private:
    friend class DirectoryList_Class;
    static CppClassType directorylist_class_;

  protected:
    explicit DirectoryList (const Glib::ConstructParams& construct_params);
    explicit DirectoryList (GtkDirectoryList* castitem);

#endif

  public:
    DirectoryList (DirectoryList&& src) noexcept;
    auto
    operator= (DirectoryList&& src) noexcept -> DirectoryList&;

    ~DirectoryList () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkDirectoryList*
    {
      return reinterpret_cast<GtkDirectoryList*> (gobject_);
    }

    auto
    gobj () const -> const GtkDirectoryList*
    {
      return reinterpret_cast<GtkDirectoryList*> (gobject_);
    }

    auto
    gobj_copy () -> GtkDirectoryList*;

  private:
  protected:
    explicit DirectoryList (const std::string& attributes,
                            const Glib::RefPtr<Gio::File>& file = {});

  public:
    static auto
    create (const std::string& attributes,
            const Glib::RefPtr<Gio::File>& file = {})
        -> Glib::RefPtr<DirectoryList>;

    void
    set_file (const Glib::RefPtr<Gio::File>& file);

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    void
    set_attributes (const std::string& attributes);

    auto
    get_attributes () const -> std::string;

    void
    set_io_priority (int io_priority);

    auto
    get_io_priority () const -> int;

    auto
    is_loading () const -> bool;

    auto
    get_error () const -> Glib::Error;

    void
    set_monitored (bool monitored = true);

    auto
    get_monitored () const -> bool;

    auto
    property_attributes () -> Glib::PropertyProxy<std::string>;

    auto
    property_attributes () const -> Glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_error () const -> Glib::PropertyProxy_ReadOnly<Glib::Error>;

    auto
    property_file () -> Glib::PropertyProxy<Glib::RefPtr<Gio::File>>;

    auto
    property_file () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::File>>;

    auto
    property_io_priority () -> Glib::PropertyProxy<int>;

    auto
    property_io_priority () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_item_type () const -> Glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_loading () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_monitored () -> Glib::PropertyProxy<bool>;

    auto
    property_monitored () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_items () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkDirectoryList* object, bool take_copy = false) -> Glib::RefPtr<Gtk::DirectoryList>;
} // namespace Glib

#endif
