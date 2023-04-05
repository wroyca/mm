// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/styleprovider.hxx>
#include <libmm/gtk/styleprovider_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace glib
{

  auto
  wrap (GtkStyleProvider* object, bool take_copy) -> glib::RefPtr<gtk::StyleProvider>
  {
    return glib::make_refptr_for_instance<gtk::StyleProvider> (
        dynamic_cast<gtk::StyleProvider*> (
            glib::wrap_auto_interface<gtk::StyleProvider> ((GObject*) (object),
                                                           take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  StyleProvider_Class::init () -> const glib::Interface_Class&
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
  StyleProvider_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new StyleProvider ((GtkStyleProvider*) (object));
  }

  StyleProvider::StyleProvider ()
    : glib::Interface (styleprovider_class_.init ())
  {
  }

  StyleProvider::StyleProvider (GtkStyleProvider* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  StyleProvider::StyleProvider (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  StyleProvider::StyleProvider (StyleProvider&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  StyleProvider::operator= (StyleProvider&& src) noexcept -> StyleProvider&
  {
    glib::Interface::operator= (std::move (src));
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
      const glib::RefPtr<gdk::Display>& display,
      const glib::RefPtr<StyleProvider>& provider,
      guint priority) -> void
  {
    gtk_style_context_add_provider_for_display (glib::unwrap (display),
                                                glib::unwrap (provider),
                                                priority);
  }

  auto
  StyleProvider::remove_provider_for_display (
      const glib::RefPtr<gdk::Display>& display,
      const glib::RefPtr<StyleProvider>& provider) -> void
  {
    gtk_style_context_remove_provider_for_display (glib::unwrap (display),
                                                   glib::unwrap (provider));
  }

} // namespace gtk
