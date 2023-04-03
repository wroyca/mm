// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/application.hxx>
#include <libmm/adw/application_p.hxx>

#include <adwaita.h>
#include <libmm/adw/init.hxx>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

  auto
  Application::custom_class_init () -> const Glib::Class&
  {
    Adw::init ();
    return application_class_.init ();
  }

  Application::Application (const Glib::ustring& application_id,
                            Gio::Application::Flags flags)
    : Glib::ObjectBase (nullptr),
      Gtk::Application (
          Glib::ConstructParams (custom_class_init (),
                                 "application_id",
                                 application_id.c_str (),
                                 "flags",
                                 static_cast<GApplicationFlags> (flags),
                                 nullptr))
  {
  }

  Application::~Application () {}

} // namespace Adw

namespace
{
}

namespace Glib
{

  auto
  wrap (AdwApplication* object, bool take_copy) -> Glib::RefPtr<Adw::Application>
  {
    return Glib::make_refptr_for_instance<Adw::Application> (
        dynamic_cast<Adw::Application*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Adw
{

  auto
  Application_Class::init () -> const Glib::Class&
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
  Application_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Application ((AdwApplication*) object);
  }

  auto
  Application::gobj_copy () -> AdwApplication*
  {
    reference ();
    return gobj ();
  }

  Application::Application (const Glib::ConstructParams& construct_params)
    : Gtk::Application (construct_params)
  {
  }

  Application::Application (AdwApplication* castitem)
    : Gtk::Application ((GtkApplication*) (castitem))
  {
  }

  Application::Application (Application&& src) noexcept
    : Gtk::Application (std::move (src))
  {
  }

  auto
  Application::operator= (Application&& src) noexcept -> Application&
  {
    Gtk::Application::operator= (std::move (src));
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
  Application::create (const Glib::ustring& application_id,
                       Gio::Application::Flags flags) -> Glib::RefPtr<Application>
  {
    return Glib::make_refptr_for_instance<Application> (
        new Application (application_id, flags));
  }

  auto
  Application::get_style_manager () const -> Glib::RefPtr<StyleManager>
  {
    auto retvalue = Glib::wrap (adw_application_get_style_manager (
        const_cast<AdwApplication*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<StyleManager>>::value,
      "Type Glib::RefPtr<StyleManager> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  Application::property_style_manager () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<StyleManager>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<StyleManager>> (
        this,
        "style-manager");
  }

} // namespace Adw
