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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT application_window_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT application_window : public gtk::ApplicationWindow
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = application_window;
    using CppClassType = application_window_class;
    using BaseObjectType = AdwApplicationWindow;
    using BaseClassType = AdwApplicationWindowClass;
#endif

    application_window (application_window&& src) noexcept;
    auto
    operator= (application_window&& src) noexcept -> application_window&;

    application_window (const application_window&) = delete;
    auto
    operator= (const application_window&) -> application_window& = delete;

    ~application_window () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class application_window_class;
    static CppClassType applicationwindow_class_;

  protected:
    explicit application_window (const glib::ConstructParams& construct_params);
    explicit application_window (AdwApplicationWindow* castitem);

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
    application_window ();

  public:
    explicit application_window (
        const glib::RefPtr<gtk::Application>& application);

    auto
    get_content () const -> gtk::Widget*;

    auto
    set_content (gtk::Widget* content) -> void;

    auto
    property_content () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_content () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwApplicationWindow* object, bool take_copy = false) -> adw::application_window*;
}

#endif
