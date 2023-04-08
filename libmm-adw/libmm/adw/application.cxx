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
  application::custom_class_init () -> const glib::Class&
  {
    adw::init ();
    return application_class_.init ();
  }

  application::application (const glib::ustring& application_id,
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

  application::~application () {}

} // namespace adw

namespace
{
}

namespace glib
{

  auto
  wrap (AdwApplication* object, bool take_copy) -> glib::RefPtr<adw::application>
  {
    return glib::make_refptr_for_instance<adw::application> (
        dynamic_cast<adw::application*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace adw
{

  auto
  application_class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &application_class::class_init_function;

      register_derived_type (adw_application_get_type ());
    }

    return *this;
  }

  auto
  application_class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  application_class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new application ((AdwApplication*) object);
  }

  auto
  application::gobj_copy () -> AdwApplication*
  {
    reference ();
    return gobj ();
  }

  application::application (const glib::ConstructParams& construct_params)
    : gtk::Application (construct_params)
  {
  }

  application::application (AdwApplication* castitem)
    : gtk::Application ((GtkApplication*) (castitem))
  {
  }

  application::application (application&& src) noexcept
    : gtk::Application (std::move (src))
  {
  }

  auto
  application::operator= (application&& src) noexcept -> application&
  {
    gtk::Application::operator= (std::move (src));
    return *this;
  }

  application::CppClassType application::application_class_;

  auto
  application::get_type () -> GType
  {
    return application_class_.init ().get_type ();
  }

  auto
  application::get_base_type () -> GType
  {
    return adw_application_get_type ();
  }

  auto
  application::create (const glib::ustring& application_id,
                       gio::Application::Flags flags) -> glib::RefPtr<application>
  {
    return glib::make_refptr_for_instance<application> (
        new application (application_id, flags));
  }

  auto
  application::get_style_manager () const -> glib::RefPtr<style_manager>
  {
    auto retvalue = glib::wrap (adw_application_get_style_manager (
        const_cast<AdwApplication*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  application::property_style_manager () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<style_manager>>
  {
    return {this, "style-manager"};
  }

} // namespace adw
