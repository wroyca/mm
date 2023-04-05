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

namespace glib
{

  auto
  wrap (GtkLayoutChild* object, bool take_copy) -> glib::RefPtr<gtk::LayoutChild>
  {
    return glib::make_refptr_for_instance<gtk::LayoutChild> (
        dynamic_cast<gtk::LayoutChild*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gtk
{

  auto
  LayoutChild_Class::init () -> const glib::Class&
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
  LayoutChild_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new LayoutChild ((GtkLayoutChild*) object);
  }

  auto
  LayoutChild::gobj_copy () -> GtkLayoutChild*
  {
    reference ();
    return gobj ();
  }

  LayoutChild::LayoutChild (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  LayoutChild::LayoutChild (GtkLayoutChild* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  LayoutChild::LayoutChild (LayoutChild&& src) noexcept
    : glib::Object (std::move (src))
  {
  }

  auto
  LayoutChild::operator= (LayoutChild&& src) noexcept -> LayoutChild&
  {
    glib::Object::operator= (std::move (src));
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
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (layoutchild_class_.init ()))
  {
  }

  auto
  LayoutChild::get_layout_manager () -> glib::RefPtr<LayoutManager>
  {
    auto retvalue = glib::wrap (gtk_layout_child_get_layout_manager (gobj ()));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  auto
  LayoutChild::get_layout_manager () const -> glib::RefPtr<const LayoutManager>
  {
    return const_cast<LayoutChild*> (this)->get_layout_manager ();
  }

  auto
  LayoutChild::get_child_widget () -> Widget*
  {
    return glib::wrap (gtk_layout_child_get_child_widget (gobj ()));
  }

  auto
  LayoutChild::get_child_widget () const -> const Widget*
  {
    return const_cast<LayoutChild*> (this)->get_child_widget ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<LayoutManager>>::value,
      "Type glib::RefPtr<LayoutManager> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  LayoutChild::property_layout_manager () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>>
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<LayoutManager>> (
        this,
        "layout-manager");
  }

  auto
  LayoutChild::property_child_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>
  {
    return glib::PropertyProxy_ReadOnly<Widget*> (this, "child-widget");
  }

} // namespace gtk
