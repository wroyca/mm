

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/simplepermission.hxx>
#include <libmm-gio/simplepermission_p.hxx>

#include <gio/gio.h>

namespace Gio
{
}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSimplePermission* object, const bool take_copy) -> RefPtr<Gio::SimplePermission>
  {
    return Glib::make_refptr_for_instance<Gio::SimplePermission> (
        dynamic_cast<Gio::SimplePermission*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  SimplePermission_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
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
      Permission (Glib::ConstructParams (simplepermission_class_.init (),
                                         "allowed",
                                         allowed,
                                         nullptr))
  {
  }

  auto
  SimplePermission::create (const bool allowed) -> Glib::RefPtr<SimplePermission>
  {
    return Glib::make_refptr_for_instance<SimplePermission> (
        new SimplePermission (allowed));
  }

} // namespace Gio
