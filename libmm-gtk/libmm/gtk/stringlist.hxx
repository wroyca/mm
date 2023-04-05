// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGLIST_H
#define _GTKMM_STRINGLIST_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/buildable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StringList_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StringList : public glib::Object,
                               public gio::ListModel,
                               public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StringList;
    using CppClassType = StringList_Class;
    using BaseObjectType = GtkStringList;
    using BaseClassType = GtkStringListClass;

    StringList (const StringList&) = delete;
    auto
    operator= (const StringList&) -> StringList& = delete;

  private:
    friend class StringList_Class;
    static CppClassType stringlist_class_;

  protected:
    explicit StringList (const glib::ConstructParams& construct_params);
    explicit StringList (GtkStringList* castitem);

#endif

  public:
    StringList (StringList&& src) noexcept;
    auto
    operator= (StringList&& src) noexcept -> StringList&;

    ~StringList () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStringList*
    {
      return reinterpret_cast<GtkStringList*> (gobject_);
    }

    auto
    gobj () const -> const GtkStringList*
    {
      return reinterpret_cast<GtkStringList*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStringList*;

  private:
  protected:
    explicit StringList (const std::vector<glib::ustring>& strings);

  public:
    static auto
    create (const std::vector<glib::ustring>& strings = {})
        -> glib::RefPtr<StringList>;

    auto
    append (const glib::ustring& string) -> void;

    auto
    remove (guint position) -> void;

    auto
    splice (guint position,
            guint n_removals,
            const std::vector<glib::ustring>& additions) -> void;

    auto
    get_string (guint position) const -> glib::ustring;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStringList* object, bool take_copy = false) -> glib::RefPtr<gtk::StringList>;
} // namespace glib

#endif
