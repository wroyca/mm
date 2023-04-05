// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/simplepermission.hxx>
#include <libmm/gio/simplepermission_p.hxx>

#include <gio/gio.h>

namespace gio
{
}

namespace
{
}

namespace glib
{

  auto
  wrap (GSimplePermission* object, const bool take_copy) -> RefPtr<gio::SimplePermission>
  {
    return glib::make_refptr_for_instance<gio::SimplePermission> (
        dynamic_cast<gio::SimplePermission*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  SimplePermission_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SimplePermission_Class::class_init_function;

      register_derived_type (g_simple_permission_get_type ());
    }

    return *this;
  }

  auto
  SimplePermission_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SimplePermission_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new SimplePermission ((GSimplePermission*) object);
  }

  auto
  SimplePermission::gobj_copy () -> GSimplePermission*
  {
    reference ();
    return gobj ();
  }

  SimplePermission::SimplePermission (
      const glib::ConstructParams& construct_params)
    : Permission (construct_params)
  {
  }

  SimplePermission::SimplePermission (GSimplePermission* castitem)
    : Permission ((GPermission*) castitem)
  {
  }

  SimplePermission::SimplePermission (SimplePermission&& src) noexcept
    : Permission (std::move (src))
  {
  }

  auto
  SimplePermission::operator= (SimplePermission&& src) noexcept -> SimplePermission&
  {
    Permission::operator= (std::move (src));
    return *this;
  }

  SimplePermission::~SimplePermission () noexcept = default;

  SimplePermission::CppClassType SimplePermission::simplepermission_class_;

  auto
  SimplePermission::get_type () -> GType
  {
    return simplepermission_class_.init ().get_type ();
  }

  auto
  SimplePermission::get_base_type () -> GType
  {
    return g_simple_permission_get_type ();
  }

  SimplePermission::SimplePermission (const bool allowed)
    : ObjectBase (nullptr),
      Permission (glib::ConstructParams (simplepermission_class_.init (),
                                         "allowed",
                                         allowed,
                                         nullptr))
  {
  }

  auto
  SimplePermission::create (const bool allowed) -> glib::RefPtr<SimplePermission>
  {
    return glib::make_refptr_for_instance<SimplePermission> (
        new SimplePermission (allowed));
  }

} // namespace gio
