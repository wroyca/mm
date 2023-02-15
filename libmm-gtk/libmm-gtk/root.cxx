// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/root.hxx>
#include <libmm-gtk/root_p.hxx>

#include <gtk/gtk.h>
#include <libmm-gdk/display.hxx>
#include <libmm-gdk/surface.hxx>
#include <libmm-gtk/widget.hxx>

namespace Gtk
{
  auto
  Root::unset_focus () -> void
  {
    gtk_root_set_focus (gobj (), nullptr);
  }

} // namespace Gtk

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkRoot* object, bool take_copy) -> Glib::RefPtr<Gtk::Root>
  {
    return Glib::make_refptr_for_instance<Gtk::Root> (dynamic_cast<Gtk::Root*> (
        Glib::wrap_auto_interface<Gtk::Root> ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  Root_Class::init () -> const Glib::Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Root_Class::iface_init_function;

      gtype_ = gtk_root_get_type ();
    }

    return *this;
  }

  auto
  Root_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Root_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Root ((GtkRoot*) (object));
  }

  Root::Root ()
    : Glib::Interface (root_class_.init ())
  {
  }

  Root::Root (GtkRoot* castitem)
    : Glib::Interface ((GObject*) (castitem))
  {
  }

  Root::Root (const Glib::Interface_Class& interface_class)
    : Glib::Interface (interface_class)
  {
  }

  Root::Root (Root&& src) noexcept
    : Glib::Interface (std::move (src))
  {
  }

  auto
  Root::operator= (Root&& src) noexcept -> Root&
  {
    Glib::Interface::operator= (std::move (src));
    return *this;
  }

  Root::~Root () noexcept {}

  auto
  Root::add_interface (GType gtype_implementer) -> void
  {
    root_class_.init ().add_interface (gtype_implementer);
  }

  Root::CppClassType Root::root_class_;

  auto
  Root::get_type () -> GType
  {
    return root_class_.init ().get_type ();
  }

  auto
  Root::get_base_type () -> GType
  {
    return gtk_root_get_type ();
  }

  auto
  Root::get_display () -> Glib::RefPtr<Gdk::Display>
  {
    auto retvalue = Glib::wrap (gtk_root_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Root::get_display () const -> Glib::RefPtr<const Gdk::Display>
  {
    return const_cast<Root*> (this)->get_display ();
  }

  auto
  Root::set_focus (Widget& focus) -> void
  {
    gtk_root_set_focus (gobj (), (focus).gobj ());
  }

  auto
  Root::get_focus () -> Widget*
  {
    return Glib::wrap (gtk_root_get_focus (gobj ()));
  }

  auto
  Root::get_focus () const -> const Widget*
  {
    return const_cast<Root*> (this)->get_focus ();
  }

} // namespace Gtk
