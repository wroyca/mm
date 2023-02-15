// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_WINDOW_H
#define _LIBADWAITAMM_WINDOW_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwWindow = struct _AdwWindow;
using AdwWindowClass = struct _AdwWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class Window_Class;
}
#endif

namespace Adw
{

  class Window : public Gtk::Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Window CppObjectType;
    typedef Window_Class CppClassType;
    typedef AdwWindow BaseObjectType;
    typedef AdwWindowClass BaseClassType;
#endif

    Window (Window&& src) noexcept;
    auto
    operator= (Window&& src) noexcept -> Window&;

    Window (const Window&) = delete;
    auto
    operator= (const Window&) -> Window& = delete;

    ~Window () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class Window_Class;
    static CppClassType window_class_;

  protected:
    explicit Window (const Glib::ConstructParams& construct_params);
    explicit Window (AdwWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwWindow*
    {
      return reinterpret_cast<AdwWindow*> (gobject_);
    }

    auto
    gobj () const -> const AdwWindow*
    {
      return reinterpret_cast<AdwWindow*> (gobject_);
    }

  private:
  public:
    Window ();

    auto
    get_content () const -> Gtk::Widget*;

    auto
    set_content (Gtk::Widget* content) -> void;

    auto
    property_content () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_content () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwWindow* object, bool take_copy = false) -> Adw::Window*;
}

#endif
