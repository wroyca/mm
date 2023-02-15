// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BUILDERSCOPE_H
#define _GTKMM_BUILDERSCOPE_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkBuilderScopeInterface GtkBuilderScopeInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilderScope = struct _GtkBuilderScope;
using GtkBuilderScopeClass = struct _GtkBuilderScopeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT BuilderScope_Class;
}
#endif

namespace Gtk
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class LIBMM_GTK_SYMEXPORT BuilderScope : public Glib::Interface
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BuilderScope;
    using CppClassType = BuilderScope_Class;
    using BaseObjectType = GtkBuilderScope;
    using BaseClassType = GtkBuilderScopeInterface;

    BuilderScope (const BuilderScope&) = delete;
    auto
    operator= (const BuilderScope&) -> BuilderScope& = delete;

  private:
    friend class BuilderScope_Class;
    static CppClassType builderscope_class_;

  #endif
  protected:
    BuilderScope ();

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit BuilderScope (const Glib::Interface_Class& interface_class);

  public:
    explicit BuilderScope (GtkBuilderScope* castitem);

  protected:
  #endif

  public:
    BuilderScope (BuilderScope&& src) noexcept;
    auto
    operator= (BuilderScope&& src) noexcept -> BuilderScope&;

    ~BuilderScope () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkBuilderScope*
    {
      return reinterpret_cast<GtkBuilderScope*> (gobject_);
    }

    auto
    gobj () const -> const GtkBuilderScope*
    {
      return reinterpret_cast<GtkBuilderScope*> (gobject_);
    }

  private:
  protected:
  public:
  public:
  protected:
  };
#endif

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBuilderScope* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BuilderScope>;

} // namespace Glib

#endif
