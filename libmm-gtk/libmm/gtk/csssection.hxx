// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CSSSECTION_H
#define _GTKMM_CSSSECTION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/file.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/gtk/csslocation.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkCssSection GtkCssSection;
#endif

namespace gtk
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
    create (const glib::RefPtr<gio::File>& file,
            const CssLocation& start,
            const CssLocation& end) -> glib::RefPtr<CssSection>;

    auto
    to_string () const -> glib::ustring;

    auto
    get_parent () -> glib::RefPtr<CssSection>;

    auto
    get_parent () const -> glib::RefPtr<const CssSection>;

    auto
    get_file () -> glib::RefPtr<gio::File>;

    auto
    get_file () const -> glib::RefPtr<const gio::File>;

    auto
    get_start_location () const -> CssLocation;

    auto
    get_end_location () const -> CssLocation;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkCssSection* object, bool take_copy = false) -> glib::RefPtr<gtk::CssSection>;

} // namespace glib

#endif
