// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gtk/constrainttarget.hxx>
#include <libmm-gtk/constrainttarget_p.hxx>

#include <gtk/gtk.h>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkConstraintTarget* object, const bool take_copy) -> RefPtr<Gtk::ConstraintTarget>
  {
    return Glib::make_refptr_for_instance<Gtk::ConstraintTarget> (
        Glib::wrap_auto_interface<Gtk::ConstraintTarget> ((GObject*) object,
                                                          take_copy));
  }

} // namespace Glib

namespace Gtk
{

  auto
  ConstraintTarget_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ConstraintTarget_Class::iface_init_function;

      gtype_ = gtk_constraint_target_get_type ();
    }

    return *this;
  }

  auto
  ConstraintTarget_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  ConstraintTarget_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ConstraintTarget ((GtkConstraintTarget*) object);
  }

  ConstraintTarget::ConstraintTarget ()
    : Interface (constrainttarget_class_.init ())
  {
  }

  ConstraintTarget::ConstraintTarget (GtkConstraintTarget* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  ConstraintTarget::ConstraintTarget (
      const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  ConstraintTarget::ConstraintTarget (ConstraintTarget&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  ConstraintTarget::operator= (ConstraintTarget&& src) noexcept -> ConstraintTarget&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  ConstraintTarget::~ConstraintTarget () noexcept = default;

  auto
  ConstraintTarget::add_interface (const GType gtype_implementer) -> void
  {
    constrainttarget_class_.init ().add_interface (gtype_implementer);
  }

  ConstraintTarget::CppClassType ConstraintTarget::constrainttarget_class_;

  auto
  ConstraintTarget::get_type () -> GType
  {
    return constrainttarget_class_.init ().get_type ();
  }

  auto
  ConstraintTarget::get_base_type () -> GType
  {
    return gtk_constraint_target_get_type ();
  }

} // namespace Gtk
