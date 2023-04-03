// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/layoutchild.hxx>
#include <libmm/gtk/layoutchild_p.hxx>

#include <gtk/gtk.h>
#include <libmm/gtk/layoutmanager.hxx>
#include <libmm/gtk/widget.hxx>

namespace
{
}

namespace Glib
{

  auto
  wrap (GtkLayoutChild* object, bool take_copy) -> Glib::RefPtr<Gtk::LayoutChild>
  {
    return Glib::make_refptr_for_instance<Gtk::LayoutChild> (
        dynamic_cast<Gtk::LayoutChild*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gtk
{

  auto
  LayoutChild_Class::init () -> const Glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LayoutChild_Class::class_init_function;

      register_derived_type (gtk_layout_child_get_type ());
    }

    return *this;
  }

  auto
  LayoutChild_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  LayoutChild_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new LayoutChild ((GtkLayoutChild*) object);
  }

  auto
  LayoutChild::gobj_copy () -> GtkLayoutChild*
  {
    reference ();
    return gobj ();
  }

  LayoutChild::LayoutChild (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  LayoutChild::LayoutChild (GtkLayoutChild* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  LayoutChild::LayoutChild (LayoutChild&& src) noexcept
    : Glib::Object (std::move (src))
  {
  }

  auto
  LayoutChild::operator= (LayoutChild&& src) noexcept -> LayoutChild&
  {
    Glib::Object::operator= (std::move (src));
    return *this;
  }

  LayoutChild::~LayoutChild () noexcept {}

  LayoutChild::CppClassType LayoutChild::layoutchild_class_;

  auto
  LayoutChild::get_type () -> GType
  {
    return layoutchild_class_.init ().get_type ();
  }

  auto
  LayoutChild::get_base_type () -> GType
  {
    return gtk_layout_child_get_type ();
  }

  LayoutChild::LayoutChild ()
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (layoutchild_class_.init ()))
  {
  }

  auto
  LayoutChild::get_layout_manager () -> Glib::RefPtr<LayoutManager>
  {
    auto retvalue = Glib::wrap (gtk_layout_child_get_layout_manager (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  LayoutChild::get_layout_manager () const -> Glib::RefPtr<const LayoutManager>
  {
    return const_cast<LayoutChild*> (this)->get_layout_manager ();
  }

  auto
  LayoutChild::get_child_widget () -> Widget*
  {
    return Glib::wrap (gtk_layout_child_get_child_widget (gobj ()));
  }

  auto
  LayoutChild::get_child_widget () const -> const Widget*
  {
    return const_cast<LayoutChild*> (this)->get_child_widget ();
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<LayoutManager>>::value,
      "Type Glib::RefPtr<LayoutManager> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  LayoutChild::property_layout_manager () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<LayoutManager>>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<LayoutManager>> (
        this,
        "layout-manager");
  }

  auto
  LayoutChild::property_child_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Widget*> (this, "child-widget");
  }

} // namespace Gtk