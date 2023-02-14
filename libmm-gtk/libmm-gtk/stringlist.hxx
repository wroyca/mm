// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGLIST_H
#define _GTKMM_STRINGLIST_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/buildable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API StringList_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API StringList : public Glib::Object,
                               public Gio::ListModel,
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
    explicit StringList (const Glib::ConstructParams& construct_params);
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
    StringList (const std::vector<Glib::ustring>& strings);

  public:
    static auto
    create (const std::vector<Glib::ustring>& strings)
        -> Glib::RefPtr<StringList>;

    void
    append (const Glib::ustring& string);

    void
    remove (guint position);

    void
    splice (guint position,
            guint n_removals,
            const std::vector<Glib::ustring>& additions);

    auto
    get_string (guint position) const -> Glib::ustring;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkStringList* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringList>;
} // namespace Glib

#endif
