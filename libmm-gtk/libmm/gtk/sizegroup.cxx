// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/sizegroup.hxx>
#include <libmm/gtk/sizegroup_p.hxx>

#include <gtk/gtk.h>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

using Mode = Gtk::SizeGroup::Mode;

namespace Gtk
{

  SizeGroup::SizeGroup (Mode mode)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (sizegroup_class_.init (),
                                           "mode",
                                           (GtkSizeGroupMode) mode,
                                           nullptr))
  {
  }

} // namespace Gtk

namespace
{
}

auto
Glib::Value<Gtk::SizeGroup::Mode>::value_type () -> GType
{
  return gtk_size_group_mode_get_type ();
}

namespace Glib
{

  auto
  wrap (GtkSizeGroup* object, bool take_copy) -> Glib::RefPtr<Gtk::SizeGroup>
  {
    return Glib::make_refptr_for_instance<Gtk::SizeGroup> (
        dynamic_cast<Gtk::SizeGroup*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  SizeGroup_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SizeGroup_Class::class_init_function;

      register_derived_type (gtk_size_group_get_type ());

      Buildable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  SizeGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SizeGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SizeGroup ((GtkSizeGroup*) object);
  }

  auto
  SizeGroup::gobj_copy () -> GtkSizeGroup*
  {
    reference ();
    return gobj ();
  }

  SizeGroup::SizeGroup (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  SizeGroup::SizeGroup (GtkSizeGroup* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  SizeGroup::SizeGroup (SizeGroup&& src) noexcept
    : Glib::Object (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  SizeGroup::operator= (SizeGroup&& src) noexcept -> SizeGroup&
  {
    Glib::Object::operator= (std::move (src));
    Buildable::operator= (std::move (src));
    return *this;
  }

  SizeGroup::~SizeGroup () noexcept {}

  SizeGroup::CppClassType SizeGroup::sizegroup_class_;

  auto
  SizeGroup::get_type () -> GType
  {
    return sizegroup_class_.init ().get_type ();
  }

  auto
  SizeGroup::get_base_type () -> GType
  {
    return gtk_size_group_get_type ();
  }

  auto
  SizeGroup::create (Mode mode) -> Glib::RefPtr<SizeGroup>
  {
    return Glib::make_refptr_for_instance<SizeGroup> (new SizeGroup (mode));
  }

  auto
  SizeGroup::set_mode (Mode mode) -> void
  {
    gtk_size_group_set_mode (gobj (), static_cast<GtkSizeGroupMode> (mode));
  }

  auto
  SizeGroup::get_mode () const -> Mode
  {
    return static_cast<Mode> (
        gtk_size_group_get_mode (const_cast<GtkSizeGroup*> (gobj ())));
  }

  auto
  SizeGroup::add_widget (Widget& widget) -> void
  {
    gtk_size_group_add_widget (gobj (), (widget).gobj ());
  }

  auto
  SizeGroup::remove_widget (Widget& widget) -> void
  {
    gtk_size_group_remove_widget (gobj (), (widget).gobj ());
  }

  auto
  SizeGroup::get_widgets () -> std::vector<Widget*>
  {
    return Glib::SListHandler<Widget*>::slist_to_vector (
        gtk_size_group_get_widgets (gobj ()),
        Glib::OWNERSHIP_NONE);
  }

  auto
  SizeGroup::get_widgets () const -> std::vector<const Widget*>
  {
    return Glib::SListHandler<const Widget*>::slist_to_vector (
        gtk_size_group_get_widgets (const_cast<GtkSizeGroup*> (gobj ())),
        Glib::OWNERSHIP_NONE);
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
      "Type Mode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  SizeGroup::property_mode () -> Glib::PropertyProxy<Mode>
  {
    return Glib::PropertyProxy<Mode> (this, "mode");
  }

  auto
  SizeGroup::property_mode () const -> Glib::PropertyProxy_ReadOnly<Mode>
  {
    return Glib::PropertyProxy_ReadOnly<Mode> (this, "mode");
  }

} // namespace Gtk
