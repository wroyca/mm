// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GLAREA_H
#define _GTKMM_GLAREA_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#include <libmm-gdk/glcontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGLArea = struct _GtkGLArea;
using GtkGLAreaClass = struct _GtkGLAreaClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API GLArea_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API GLArea : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef GLArea CppObjectType;
    typedef GLArea_Class CppClassType;
    typedef GtkGLArea BaseObjectType;
    typedef GtkGLAreaClass BaseClassType;
#endif

    GLArea (GLArea&& src) noexcept;
    auto
    operator= (GLArea&& src) noexcept -> GLArea&;

    GLArea (const GLArea&) = delete;
    auto
    operator= (const GLArea&) -> GLArea& = delete;

    ~GLArea () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class GLArea_Class;
    static CppClassType glarea_class_;

  protected:
    explicit GLArea (const Glib::ConstructParams& construct_params);
    explicit GLArea (GtkGLArea* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkGLArea*
    {
      return reinterpret_cast<GtkGLArea*> (gobject_);
    }

    auto
    gobj () const -> const GtkGLArea*
    {
      return reinterpret_cast<GtkGLArea*> (gobject_);
    }

  private:
  public:
    GLArea ();

    auto
    get_context () -> Glib::RefPtr<Gdk::GLContext>;

    auto
    get_context () const -> Glib::RefPtr<const Gdk::GLContext>;

    void
    make_current ();

    void
    queue_render ();

    void
    attach_buffers ();

    auto
    has_error () const -> bool;

    void
    throw_if_error () const;

    void
    set_error (const Glib::Error& error);

    void
    unset_error ();

    auto
    get_has_depth_buffer () const -> bool;

    void
    set_has_depth_buffer (bool has_depth_buffer = true);

    auto
    get_has_stencil_buffer () const -> bool;

    void
    set_has_stencil_buffer (bool has_stencil_buffer = true);

    auto
    get_auto_render () const -> bool;

    void
    set_auto_render (bool auto_render = true);

    void
    get_required_version (int& major, int& minor) const;

    void
    set_required_version (int major, int minor);

    auto
    get_use_es () const -> bool;

    void
    set_use_es (bool use_es = true);

    auto
    property_auto_render () -> Glib::PropertyProxy<bool>;

    auto
    property_auto_render () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_context () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gdk::GLContext>>;

    auto
    property_has_depth_buffer () -> Glib::PropertyProxy<bool>;

    auto
    property_has_depth_buffer () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_stencil_buffer () -> Glib::PropertyProxy<bool>;

    auto
    property_has_stencil_buffer () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_es () -> Glib::PropertyProxy<bool>;

    auto
    property_use_es () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_create_context ()
        -> Glib::SignalProxy<Glib::RefPtr<Gdk::GLContext> ()>;

    auto
    signal_render ()
        -> Glib::SignalProxy<bool (const Glib::RefPtr<Gdk::GLContext>&)>;

    auto
    signal_resize () -> Glib::SignalProxy<void (int, int)>;

  public:
  public:
  protected:
    virtual auto
    on_create_context () -> Glib::RefPtr<Gdk::GLContext>;

    virtual auto
    on_render (const Glib::RefPtr<Gdk::GLContext>& context) -> bool;

    virtual void
    on_resize (int width, int height);
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkGLArea* object, bool take_copy = false) -> Gtk::GLArea*;
} // namespace Glib

#endif
