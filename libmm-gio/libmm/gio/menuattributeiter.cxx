// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/menuattributeiter.hxx>
#include <libmm/gio/menuattributeiter_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  auto
  MenuAttributeIter::get_next (Glib::ustring& out_name,
                               Glib::VariantBase& value) -> bool
  {
    const char* g_out_name = nullptr;
    GVariant* g_value = nullptr;

    const bool result =
        g_menu_attribute_iter_get_next (gobj (), &g_out_name, &g_value);

    out_name = g_out_name;
    value.init (g_value);

    return result;
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GMenuAttributeIter* object, const bool take_copy) -> RefPtr<Gio::MenuAttributeIter>
  {
    return Glib::make_refptr_for_instance<Gio::MenuAttributeIter> (
        dynamic_cast<Gio::MenuAttributeIter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  MenuAttributeIter_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MenuAttributeIter_Class::class_init_function;

      register_derived_type (g_menu_attribute_iter_get_type ());
    }

    return *this;
  }

  auto
  MenuAttributeIter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  MenuAttributeIter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new MenuAttributeIter ((GMenuAttributeIter*) object);
  }

  auto
  MenuAttributeIter::gobj_copy () -> GMenuAttributeIter*
  {
    reference ();
    return gobj ();
  }

  MenuAttributeIter::MenuAttributeIter (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  MenuAttributeIter::MenuAttributeIter (GMenuAttributeIter* castitem)
    : Object ((GObject*) castitem)
  {
  }

  MenuAttributeIter::MenuAttributeIter (MenuAttributeIter&& src) noexcept
    : Object (std::move (src))
  {
  }

  auto
  MenuAttributeIter::operator= (MenuAttributeIter&& src) noexcept -> MenuAttributeIter&
  {
    Object::operator= (std::move (src));
    return *this;
  }

  MenuAttributeIter::~MenuAttributeIter () noexcept = default;

  MenuAttributeIter::CppClassType MenuAttributeIter::menuattributeiter_class_;

  auto
  MenuAttributeIter::get_type () -> GType
  {
    return menuattributeiter_class_.init ().get_type ();
  }

  auto
  MenuAttributeIter::get_base_type () -> GType
  {
    return g_menu_attribute_iter_get_type ();
  }

  MenuAttributeIter::MenuAttributeIter ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (menuattributeiter_class_.init ()))
  {
  }

  auto
  MenuAttributeIter::get_name () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        g_menu_attribute_iter_get_name (
            const_cast<GMenuAttributeIter*> (gobj ())));
  }

  auto
  MenuAttributeIter::get_value () const -> Glib::VariantBase
  {
    return Glib::wrap (g_menu_attribute_iter_get_value (
                           const_cast<GMenuAttributeIter*> (gobj ())),
                       false);
  }

  auto
  MenuAttributeIter::next () -> bool
  {
    return g_menu_attribute_iter_next (gobj ());
  }

} // namespace Gio
