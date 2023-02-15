// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATION_H
#define _LIBADWAITAMM_APPLICATION_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-adw/stylemanager.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwApplication = struct _AdwApplication;
using AdwApplicationClass = struct _AdwApplicationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class Application_Class;
}
#endif

namespace Adw
{

  class Application : public Gtk::Application
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Application;
    using CppClassType = Application_Class;
    using BaseObjectType = AdwApplication;
    using BaseClassType = AdwApplicationClass;

    Application (const Application&) = delete;
    auto
    operator= (const Application&) -> Application& = delete;

  private:
    friend class Application_Class;
    static CppClassType application_class_;

  protected:
    explicit Application (const Glib::ConstructParams& construct_params);
    explicit Application (AdwApplication* castitem);

#endif

  public:
    Application (Application&& src) noexcept;
    auto
    operator= (Application&& src) noexcept -> Application&;

    ~Application () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwApplication*
    {
      return reinterpret_cast<AdwApplication*> (gobject_);
    }

    auto
    gobj () const -> const AdwApplication*
    {
      return reinterpret_cast<AdwApplication*> (gobject_);
    }

    auto
    gobj_copy () -> AdwApplication*;

  private:
  private:
    auto
    custom_class_init () -> const Glib::Class&;

  protected:
    Application (const Glib::ustring& application_id,
                 Gio::Application::Flags flags);

  public:
    static auto
    create (const Glib::ustring& application_id, Gio::Application::Flags flags)
        -> Glib::RefPtr<Application>;

    auto
    get_style_manager () const -> Glib::RefPtr<StyleManager>;

    auto
    property_style_manager () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<StyleManager>>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwApplication* object, bool take_copy = false) -> Glib::RefPtr<Adw::Application>;
}

#endif
