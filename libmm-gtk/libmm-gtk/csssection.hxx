// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CSSSECTION_H
#define _GTKMM_CSSSECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/file.hxx>
#include <libmm-glib/refptr.hxx>
#include <libmm-gtk/csslocation.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkCssSection GtkCssSection;
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT CssSection final
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = CssSection;
    using BaseObjectType = GtkCssSection;
#endif

    auto
    reference () const -> void;

    auto
    unreference () const -> void;

    auto
    gobj () -> GtkCssSection*;

    auto
    gobj () const -> const GtkCssSection*;

    auto
    gobj_copy () const -> GtkCssSection*;

    CssSection () = delete;

    CssSection (const CssSection&) = delete;
    auto
    operator= (const CssSection&) -> CssSection& = delete;

  protected:
    auto
    operator delete (void*, std::size_t) -> void;

  private:
  public:
    static auto
    create (const Glib::RefPtr<Gio::File>& file,
            const CssLocation& start,
            const CssLocation& end) -> Glib::RefPtr<CssSection>;

    auto
    to_string () const -> Glib::ustring;

    auto
    get_parent () -> Glib::RefPtr<CssSection>;

    auto
    get_parent () const -> Glib::RefPtr<const CssSection>;

    auto
    get_file () -> Glib::RefPtr<Gio::File>;

    auto
    get_file () const -> Glib::RefPtr<const Gio::File>;

    auto
    get_start_location () const -> CssLocation;

    auto
    get_end_location () const -> CssLocation;
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCssSection* object, bool take_copy = false) -> Glib::RefPtr<Gtk::CssSection>;

} // namespace Glib

#endif
