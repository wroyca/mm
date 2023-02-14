
#ifndef _GTKMM_ROOT_H
#define _GTKMM_ROOT_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

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
namespace Gtk
{
  class GTKMM_API Root_Class;
}
#endif

namespace Gdk
{
  class GTKMM_API Display;
  class GTKMM_API Surface;
} // namespace Gdk

namespace Gtk
{
  class GTKMM_API Widget;

  class GTKMM_API Root : public Glib::Interface
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

    explicit Root (const Glib::Interface_Class& interface_class);

  public:
    explicit Root (GtkRoot* castitem);

  protected:
#endif

  public:
    Root (Root&& src) noexcept;
    auto
    operator= (Root&& src) noexcept -> Root&;

    ~Root () noexcept override;

    static void
    add_interface (GType gtype_implementer);

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
    get_display () -> Glib::RefPtr<Gdk::Display>;

    auto
    get_display () const -> Glib::RefPtr<const Gdk::Display>;

    void
    set_focus (Widget& focus);

    void
    unset_focus ();

    auto
    get_focus () -> Widget*;

    auto
    get_focus () const -> const Widget*;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkRoot* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Root>;

} // namespace Glib

#endif
