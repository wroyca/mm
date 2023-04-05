// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/root.hxx>
#include <libmm/gtk/root_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gdk/display.hxx>
#include <libmm/gdk/surface.hxx>
#include <libmm/gtk/widget.hxx>

namespace gtk
{
  auto
  Root::unset_focus () -> void
  {
    gtk_root_set_focus (gobj (), nullptr);
  }

} // namespace gtk

namespace
{
}

namespace glib
{

  auto
  wrap (GtkRoot* object, bool take_copy) -> glib::RefPtr<gtk::Root>
  {
    return glib::make_refptr_for_instance<gtk::Root> (dynamic_cast<gtk::Root*> (
        glib::wrap_auto_interface<gtk::Root> ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  Root_Class::init () -> const glib::Interface_Class&
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
  Root_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new Root ((GtkRoot*) (object));
  }

  Root::Root ()
    : glib::Interface (root_class_.init ())
  {
  }

  Root::Root (GtkRoot* castitem)
    : glib::Interface ((GObject*) (castitem))
  {
  }

  Root::Root (const glib::Interface_Class& interface_class)
    : glib::Interface (interface_class)
  {
  }

  Root::Root (Root&& src) noexcept
    : glib::Interface (std::move (src))
  {
  }

  auto
  Root::operator= (Root&& src) noexcept -> Root&
  {
    glib::Interface::operator= (std::move (src));
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
  Root::get_display () -> glib::RefPtr<gdk::Display>
  {
    auto retvalue = glib::wrap (gtk_root_get_display (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  Root::get_display () const -> glib::RefPtr<const gdk::Display>
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
    return glib::wrap (gtk_root_get_focus (gobj ()));
  }

  auto
  Root::get_focus () const -> const Widget*
  {
    return const_cast<Root*> (this)->get_focus ();
  }

} // namespace gtk
