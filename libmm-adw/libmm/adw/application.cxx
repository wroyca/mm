// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/application.hxx>
#include <libmm/adw/application_p.hxx>

#include <adwaita.h>
#include <libmm/adw/init.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

  auto
  Application::custom_class_init () -> const glib::Class&
  {
    adw::init ();
    return application_class_.init ();
  }

  Application::Application (const glib::ustring& application_id,
                            gio::Application::Flags flags)
    : glib::ObjectBase (nullptr),
      gtk::Application (
          glib::ConstructParams (custom_class_init (),
                                 "application_id",
                                 application_id.c_str (),
                                 "flags",
                                 static_cast<GApplicationFlags> (flags),
                                 nullptr))
  {
  }

  Application::~Application () {}

} // namespace adw

namespace
{
}

namespace glib
{

  auto
  wrap (AdwApplication* object, bool take_copy) -> glib::RefPtr<adw::Application>
  {
    return glib::make_refptr_for_instance<adw::Application> (
        dynamic_cast<adw::Application*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  Application_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Application_Class::class_init_function;

      register_derived_type (adw_application_get_type ());
    }

    return *this;
  }

  auto
  Application_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  Application_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Application ((AdwApplication*) object);
  }

  auto
  Application::gobj_copy () -> AdwApplication*
  {
    reference ();
    return gobj ();
  }

  Application::Application (const glib::ConstructParams& construct_params)
    : gtk::Application (construct_params)
  {
  }

  Application::Application (AdwApplication* castitem)
    : gtk::Application ((GtkApplication*) (castitem))
  {
  }

  Application::Application (Application&& src) noexcept
    : gtk::Application (std::move (src))
  {
  }

  auto
  Application::operator= (Application&& src) noexcept -> Application&
  {
    gtk::Application::operator= (std::move (src));
    return *this;
  }

  Application::CppClassType Application::application_class_;

  auto
  Application::get_type () -> GType
  {
    return application_class_.init ().get_type ();
  }

  auto
  Application::get_base_type () -> GType
  {
    return adw_application_get_type ();
  }

  auto
  Application::create (const glib::ustring& application_id,
                       gio::Application::Flags flags) -> glib::RefPtr<Application>
  {
    return glib::make_refptr_for_instance<Application> (
        new Application (application_id, flags));
  }

  auto
  Application::get_style_manager () const -> glib::RefPtr<StyleManager>
  {
    auto retvalue = glib::wrap (adw_application_get_style_manager (
        const_cast<AdwApplication*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Application::property_style_manager () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<StyleManager>>
  {
    return {this, "style-manager"};
  }

} // namespace adw
