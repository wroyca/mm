// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_DIRECTORYLIST_H
#define _GTKMM_DIRECTORYLIST_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/file.hxx>
#include <libmm/gio/listmodel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT DirectoryList_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT DirectoryList : public glib::Object,
                                  public gio::ListModel
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
    explicit DirectoryList (const glib::ConstructParams& construct_params);
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
                            const glib::RefPtr<gio::File>& file = {});

  public:
    static auto
    create (const std::string& attributes,
            const glib::RefPtr<gio::File>& file = {})
        -> glib::RefPtr<DirectoryList>;

    auto
    set_file (const glib::RefPtr<gio::File>& file) -> void;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    set_attributes (const std::string& attributes) -> void;

    auto
    get_attributes () const -> std::string;

    auto
    set_io_priority (int io_priority) -> void;

    auto
    get_io_priority () const -> int;

    auto
    is_loading () const -> bool;

    auto
    get_error () const -> glib::Error;

    auto
    set_monitored (bool monitored = true) -> void;

    auto
    get_monitored () const -> bool;

    auto
    property_attributes () -> glib::PropertyProxy<std::string>;

    auto
    property_attributes () const -> glib::PropertyProxy_ReadOnly<std::string>;

    auto
    property_error () const -> glib::PropertyProxy_ReadOnly<glib::Error>;

    auto
    property_file () -> glib::PropertyProxy<glib::RefPtr<gio::File>>;

    auto
    property_file () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::File>>;

    auto
    property_io_priority () -> glib::PropertyProxy<int>;

    auto
    property_io_priority () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_item_type () const -> glib::PropertyProxy_ReadOnly<GType>;

    auto
    property_loading () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_monitored () -> glib::PropertyProxy<bool>;

    auto
    property_monitored () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_n_items () const -> glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkDirectoryList* object, bool take_copy = false) -> glib::RefPtr<gtk::DirectoryList>;
} // namespace glib

#endif
