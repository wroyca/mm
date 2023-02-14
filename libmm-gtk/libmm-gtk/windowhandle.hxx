
#ifndef _GTKMM_WINDOWHANDLE_H
#define _GTKMM_WINDOWHANDLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API WindowHandle_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API WindowHandle : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef WindowHandle CppObjectType;
    typedef WindowHandle_Class CppClassType;
    typedef GtkWindowHandle BaseObjectType;
    typedef GtkWindowHandleClass BaseClassType;
#endif

    WindowHandle (WindowHandle&& src) noexcept;
    auto
    operator= (WindowHandle&& src) noexcept -> WindowHandle&;

    WindowHandle (const WindowHandle&) = delete;
    auto
    operator= (const WindowHandle&) -> WindowHandle& = delete;

    ~WindowHandle () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class WindowHandle_Class;
    static CppClassType windowhandle_class_;

  protected:
    explicit WindowHandle (const Glib::ConstructParams& construct_params);
    explicit WindowHandle (GtkWindowHandle* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkWindowHandle*
    {
      return reinterpret_cast<GtkWindowHandle*> (gobject_);
    }

    auto
    gobj () const -> const GtkWindowHandle*
    {
      return reinterpret_cast<GtkWindowHandle*> (gobject_);
    }

  private:
  public:
    WindowHandle ();

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkWindowHandle* object, bool take_copy = false) -> Gtk::WindowHandle*;
} // namespace Glib

#endif
