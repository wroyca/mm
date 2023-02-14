
#ifndef _GTKMM_BUILDERCSCOPE_H
#define _GTKMM_BUILDERCSCOPE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <libmm-gtk/builderscope.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkBuilderCScope = struct _GtkBuilderCScope;
using GtkBuilderCScopeClass = struct _GtkBuilderCScopeClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API BuilderCScope_Class;
}
#endif

namespace Gtk
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  class GTKMM_API BuilderCScope : public Glib::Object,
                                  public BuilderScope
  {
  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BuilderCScope;
    using CppClassType = BuilderCScope_Class;
    using BaseObjectType = GtkBuilderCScope;
    using BaseClassType = GtkBuilderCScopeClass;

    BuilderCScope (const BuilderCScope&) = delete;
    auto
    operator= (const BuilderCScope&) -> BuilderCScope& = delete;

  private:
    friend class BuilderCScope_Class;
    static CppClassType buildercscope_class_;

  protected:
    explicit BuilderCScope (const Glib::ConstructParams& construct_params);
    explicit BuilderCScope (GtkBuilderCScope* castitem);

  #endif

  public:
    BuilderCScope (BuilderCScope&& src) noexcept;
    auto
    operator= (BuilderCScope&& src) noexcept -> BuilderCScope&;

    ~BuilderCScope () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkBuilderCScope*
    {
      return reinterpret_cast<GtkBuilderCScope*> (gobject_);
    }

    auto
    gobj () const -> const GtkBuilderCScope*
    {
      return reinterpret_cast<GtkBuilderCScope*> (gobject_);
    }

    auto
    gobj_copy () -> GtkBuilderCScope*;

  private:
  protected:
    BuilderCScope ();

  public:
    static auto
    create () -> Glib::RefPtr<BuilderCScope>;

  public:
  public:
  protected:
  };
#endif

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkBuilderCScope* object, bool take_copy = false) -> Glib::RefPtr<Gtk::BuilderCScope>;
} // namespace Glib

#endif
