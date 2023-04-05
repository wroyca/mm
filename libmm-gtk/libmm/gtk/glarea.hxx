// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_GLAREA_H
#define _GTKMM_GLAREA_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#include <libmm/gdk/glcontext.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGLArea = struct _GtkGLArea;
using GtkGLAreaClass = struct _GtkGLAreaClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT GLArea_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT GLArea : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class GLArea_Class;
    static CppClassType glarea_class_;

  protected:
    explicit GLArea (const glib::ConstructParams& construct_params);
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
    get_context () -> glib::RefPtr<gdk::GLContext>;

    auto
    get_context () const -> glib::RefPtr<const gdk::GLContext>;

    auto
    make_current () -> void;

    auto
    queue_render () -> void;

    auto
    attach_buffers () -> void;

    auto
    has_error () const -> bool;

    auto
    throw_if_error () const -> void;

    auto
    set_error (const glib::Error& error) -> void;

    auto
    unset_error () -> void;

    auto
    get_has_depth_buffer () const -> bool;

    auto
    set_has_depth_buffer (bool has_depth_buffer = true) -> void;

    auto
    get_has_stencil_buffer () const -> bool;

    auto
    set_has_stencil_buffer (bool has_stencil_buffer = true) -> void;

    auto
    get_auto_render () const -> bool;

    auto
    set_auto_render (bool auto_render = true) -> void;

    auto
    get_required_version (int& major, int& minor) const -> void;

    auto
    set_required_version (int major, int minor) -> void;

    auto
    get_use_es () const -> bool;

    auto
    set_use_es (bool use_es = true) -> void;

    auto
    property_auto_render () -> glib::PropertyProxy<bool>;

    auto
    property_auto_render () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_context () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::GLContext>>;

    auto
    property_has_depth_buffer () -> glib::PropertyProxy<bool>;

    auto
    property_has_depth_buffer () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_has_stencil_buffer () -> glib::PropertyProxy<bool>;

    auto
    property_has_stencil_buffer () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_es () -> glib::PropertyProxy<bool>;

    auto
    property_use_es () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_create_context ()
        -> glib::SignalProxy<glib::RefPtr<gdk::GLContext> ()>;

    auto
    signal_render ()
        -> glib::SignalProxy<bool (const glib::RefPtr<gdk::GLContext>&)>;

    auto
    signal_resize () -> glib::SignalProxy<void (int, int)>;

  public:
  public:
  protected:
    virtual auto
    on_create_context () -> glib::RefPtr<gdk::GLContext>;

    virtual auto
    on_render (const glib::RefPtr<gdk::GLContext>& context) -> bool;

    virtual auto
    on_resize (int width, int height) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkGLArea* object, bool take_copy = false) -> gtk::GLArea*;
} // namespace glib

#endif
