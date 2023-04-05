// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_APPLICATION_H
#define _LIBADWAITAMM_APPLICATION_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/adw/stylemanager.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwApplication = struct _AdwApplication;
using AdwApplicationClass = struct _AdwApplicationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT Application_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT Application : public gtk::Application
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
    explicit Application (const glib::ConstructParams& construct_params);
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
    custom_class_init () -> const glib::Class&;

  protected:
    Application (const glib::ustring& application_id,
                 gio::Application::Flags flags);

  public:
    static auto
    create (const glib::ustring& application_id, gio::Application::Flags flags)
        -> glib::RefPtr<Application>;

    auto
    get_style_manager () const -> glib::RefPtr<StyleManager>;

    auto
    property_style_manager () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<StyleManager>>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwApplication* object, bool take_copy = false) -> glib::RefPtr<adw::Application>;
}

#endif
