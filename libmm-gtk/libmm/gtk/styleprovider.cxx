// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/styleprovider.hxx>
#include <libmm/gtk/styleprovider_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkStyleProvider* object, bool take_copy) -> Glib::RefPtr<Gtk::StyleProvider>
  {
    return Glib::make_refptr_for_instance<Gtk::StyleProvider> (
        dynamic_cast<Gtk::StyleProvider*> (
            Glib::wrap_auto_interface<Gtk::StyleProvider> ((GObject*) (object),
                                                           take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  StyleProvider_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &StyleProvider_Class::iface_init_function;

      gtype_ = gtk_style_provider_get_type ();
    }

    return *this;
  }

  auto
  StyleProvider_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  StyleProvider_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new StyleProvider ((GtkStyleProvider*) (object));
  }

  StyleProvider::StyleProvider ()
    : Glib::Interface (styleprovider_class_.init ())
  {
  }

  StyleProvider::StyleProvider (GtkStyleProvider* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  StyleProvider::StyleProvider (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  StyleProvider::StyleProvider (StyleProvider&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  StyleProvider::operator= (StyleProvider&& src) noexcept -> StyleProvider&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  StyleProvider::~StyleProvider () noexcept {}

  auto
  StyleProvider::add_interface (GType gtype_implementer) -> void
  {
    styleprovider_class_.init ().add_interface (gtype_implementer);
  }

  StyleProvider::CppClassType StyleProvider::styleprovider_class_;

  auto
  StyleProvider::get_type () -> GType
  {
    return styleprovider_class_.init ().get_type ();
  }

  auto
  StyleProvider::get_base_type () -> GType
  {
    return gtk_style_provider_get_type ();
  }

  auto
  StyleProvider::add_provider_for_display (
      const Glib::RefPtr<Gdk::Display>& display,
      const Glib::RefPtr<StyleProvider>& provider,
      guint priority) -> void
  {
    gtk_style_context_add_provider_for_display (Glib::unwrap (display),
                                                Glib::unwrap (provider),
                                                priority);
  }

  auto
  StyleProvider::remove_provider_for_display (
      const Glib::RefPtr<Gdk::Display>& display,
      const Glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider_for_display (Glib::unwrap (display),
                                                   Glib::unwrap (provider));
  }

} // namespace Gtk
