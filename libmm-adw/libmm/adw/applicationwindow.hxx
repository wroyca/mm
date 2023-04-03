// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATIONWINDOW_H
#define _LIBADWAITAMM_APPLICATIONWINDOW_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwApplicationWindow = struct _AdwApplicationWindow;
using AdwApplicationWindowClass = struct _AdwApplicationWindowClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ApplicationWindow_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ApplicationWindow : public Gtk::ApplicationWindow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ApplicationWindow CppObjectType;
    typedef ApplicationWindow_Class CppClassType;
    typedef AdwApplicationWindow BaseObjectType;
    typedef AdwApplicationWindowClass BaseClassType;
#endif

    ApplicationWindow (ApplicationWindow&& src) noexcept;
    auto
    operator= (ApplicationWindow&& src) noexcept -> ApplicationWindow&;

    ApplicationWindow (const ApplicationWindow&) = delete;
    auto
    operator= (const ApplicationWindow&) -> ApplicationWindow& = delete;

    ~ApplicationWindow () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ApplicationWindow_Class;
    static CppClassType applicationwindow_class_;

  protected:
    explicit ApplicationWindow (const Glib::ConstructParams& construct_params);
    explicit ApplicationWindow (AdwApplicationWindow* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwApplicationWindow*
    {
      return reinterpret_cast<AdwApplicationWindow*> (gobject_);
    }

    auto
    gobj () const -> const AdwApplicationWindow*
    {
      return reinterpret_cast<AdwApplicationWindow*> (gobject_);
    }

  private:
  protected:
    ApplicationWindow ();

  public:
    explicit ApplicationWindow (
        const Glib::RefPtr<Gtk::Application>& application);

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
  wrap (AdwApplicationWindow* object, bool take_copy = false) -> Adw::ApplicationWindow*;
}

#endif
