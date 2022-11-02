// SPDX-License-Identifier: GPL-3.0-or-later
//

#include <mm/adw/application.hpp>

#include <mm/adw/private/application_p.hpp>
#include <mm/gtk/private/application_p.hpp>

namespace Adw
{
  Application::Application(const Glib::ustring &application_id, Gio::Application::Flags flags)
  {
    // gtk_init() is called by the 'startup' default signal handler when g_application_run() is called.
    // It's also called in adw_init, to make it possible for users of gtkmm to create
    // a window and other widgets before calling run(). (This is not recommended.)
    // See https://bugzilla.gnome.org/show_bug.cgi?id=639925
    adw_init();
  }

  auto Application::create(const Glib::ustring &application_id, Gio::Application::Flags flags) -> Glib::RefPtr<Application>
  {
    return Glib::RefPtr<Application>(new Application(application_id, flags));
  }

  auto Application_Class::init() -> const Class&
  {
    if (!gtype_) // create the GType if necessary
    {
      // Glib::Class has to know the class init function to clone custom types.
      class_init_func_ = &Application_Class::class_init_function;

      // Create the wrapper type, with the same class/instance size as the base type.
      register_derived_type(adw_application_get_type());
    }
    return *this;
  }

  auto Application_Class::class_init_function(void *g_class, void *class_data) -> void
  {
    const auto klass = static_cast<BaseClassType *>(g_class);
    CppClassParent::class_init_function(klass, class_data);
  }
} // namespace Adw
