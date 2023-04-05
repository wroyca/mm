// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/sizegroup.hxx>
#include <libmm/gtk/sizegroup_p.hxx>

#include <gtk/gtk.h>

#include <libmm/glib/vectorutils.hxx>

#include <gtk/gtk.h>

using Mode = gtk::SizeGroup::Mode;

namespace gtk
{

  SizeGroup::SizeGroup (Mode mode)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (sizegroup_class_.init (),
                                           "mode",
                                           (GtkSizeGroupMode) mode,
                                           nullptr))
  {
  }

} // namespace gtk

namespace
{
}

auto
glib::Value<gtk::SizeGroup::Mode>::value_type () -> GType
{
  return gtk_size_group_mode_get_type ();
}

namespace glib
{

  auto
  wrap (GtkSizeGroup* object, bool take_copy) -> glib::RefPtr<gtk::SizeGroup>
  {
    return glib::make_refptr_for_instance<gtk::SizeGroup> (
        dynamic_cast<gtk::SizeGroup*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  SizeGroup_Class::init () -> const glib::Class&
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
  SizeGroup_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SizeGroup ((GtkSizeGroup*) object);
  }

  auto
  SizeGroup::gobj_copy () -> GtkSizeGroup*
  {
    reference ();
    return gobj ();
  }

  SizeGroup::SizeGroup (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  SizeGroup::SizeGroup (GtkSizeGroup* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  SizeGroup::SizeGroup (SizeGroup&& src) noexcept
    : glib::Object (std::move (src)),
      Buildable (std::move (src))
  {
  }

  auto
  SizeGroup::operator= (SizeGroup&& src) noexcept -> SizeGroup&
  {
    glib::Object::operator= (std::move (src));
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
  SizeGroup::create (Mode mode) -> glib::RefPtr<SizeGroup>
  {
    return glib::make_refptr_for_instance<SizeGroup> (new SizeGroup (mode));
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
    return glib::SListHandler<Widget*>::slist_to_vector (
        gtk_size_group_get_widgets (gobj ()),
        glib::OWNERSHIP_NONE);
  }

  auto
  SizeGroup::get_widgets () const -> std::vector<const Widget*>
  {
    return glib::SListHandler<const Widget*>::slist_to_vector (
        gtk_size_group_get_widgets (const_cast<GtkSizeGroup*> (gobj ())),
        glib::OWNERSHIP_NONE);
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<Mode>::value,
      "Type Mode cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  SizeGroup::property_mode () -> glib::PropertyProxy<Mode>
  {
    return glib::PropertyProxy<Mode> (this, "mode");
  }

  auto
  SizeGroup::property_mode () const -> glib::PropertyProxy_ReadOnly<Mode>
  {
    return glib::PropertyProxy_ReadOnly<Mode> (this, "mode");
  }

} // namespace gtk
