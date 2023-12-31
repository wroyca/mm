// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_WINDOWGROUP_H
#define _GTKMM_WINDOWGROUP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <vector>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkWindowGroup = struct _GtkWindowGroup;
using GtkWindowGroupClass = struct _GtkWindowGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT WindowGroup_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Window;

  class LIBMM_GTK_SYMEXPORT WindowGroup : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = WindowGroup;
    using CppClassType = WindowGroup_Class;
    using BaseObjectType = GtkWindowGroup;
    using BaseClassType = GtkWindowGroupClass;

    WindowGroup (const WindowGroup&) = delete;
    auto
    operator= (const WindowGroup&) -> WindowGroup& = delete;

  private:
    friend class WindowGroup_Class;
    static CppClassType windowgroup_class_;

  protected:
    explicit WindowGroup (const glib::ConstructParams& construct_params);
    explicit WindowGroup (GtkWindowGroup* castitem);

#endif

  public:
    WindowGroup (WindowGroup&& src) noexcept;
    auto
    operator= (WindowGroup&& src) noexcept -> WindowGroup&;

    ~WindowGroup () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWindowGroup*
    {
      return reinterpret_cast<GtkWindowGroup*> (gobject_);
    }

    auto
    gobj () const -> const GtkWindowGroup*
    {
      return reinterpret_cast<GtkWindowGroup*> (gobject_);
    }

    auto
    gobj_copy () -> GtkWindowGroup*;

  private:
  protected:
    WindowGroup ();

  public:
    static auto
    create () -> glib::RefPtr<WindowGroup>;

    auto
    add_window (Window& window) -> void;

    auto
    remove_window (Window& window) -> void;

    auto
    list_windows () -> std::vector<Window*>;

    auto
    list_windows () const -> std::vector<const Window*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkWindowGroup* object, bool take_copy = false) -> glib::RefPtr<gtk::WindowGroup>;
} // namespace glib

#endif
