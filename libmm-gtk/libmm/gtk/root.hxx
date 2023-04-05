// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ROOT_H
#define _GTKMM_ROOT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkRootInterface GtkRootInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRoot = struct _GtkRoot;
using GtkRootClass = struct _GtkRootClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Root_Class;
}
#endif

namespace gdk
{
  class LIBMM_GTK_SYMEXPORT Display;
  class LIBMM_GTK_SYMEXPORT Surface;
} // namespace gdk

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT Root : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Root;
    using CppClassType = Root_Class;
    using BaseObjectType = GtkRoot;
    using BaseClassType = GtkRootInterface;

    Root (const Root&) = delete;
    auto
    operator= (const Root&) -> Root& = delete;

  private:
    friend class Root_Class;
    static CppClassType root_class_;

#endif
  protected:
    Root ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Root (const glib::Interface_Class& interface_class);

  public:
    explicit Root (GtkRoot* castitem);

  protected:
#endif

  public:
    Root (Root&& src) noexcept;
    auto
    operator= (Root&& src) noexcept -> Root&;

    ~Root () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkRoot*
    {
      return reinterpret_cast<GtkRoot*> (gobject_);
    }

    auto
    gobj () const -> const GtkRoot*
    {
      return reinterpret_cast<GtkRoot*> (gobject_);
    }

  private:
  public:
    auto
    get_display () -> glib::RefPtr<gdk::Display>;

    auto
    get_display () const -> glib::RefPtr<const gdk::Display>;

    auto
    set_focus (Widget& focus) -> void;

    auto
    unset_focus () -> void;

    auto
    get_focus () -> Widget*;

    auto
    get_focus () const -> const Widget*;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkRoot* object, bool take_copy = false) -> glib::RefPtr<gtk::Root>;

} // namespace glib

#endif
