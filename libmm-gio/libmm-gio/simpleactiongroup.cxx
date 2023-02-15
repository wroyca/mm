// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/simpleactiongroup.hxx>
#include <libmm-gio/simpleactiongroup_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/action.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GSimpleActionGroup* object, const bool take_copy) -> RefPtr<Gio::SimpleActionGroup>
  {
    return Glib::make_refptr_for_instance<Gio::SimpleActionGroup> (
        dynamic_cast<Gio::SimpleActionGroup*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  SimpleActionGroup_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &SimpleActionGroup_Class::class_init_function;

      register_derived_type (g_simple_action_group_get_type ());

      ActionGroup::add_interface (get_type ());
      ActionMap::add_interface (get_type ());
    }

    return *this;
  }

  auto
  SimpleActionGroup_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  SimpleActionGroup_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new SimpleActionGroup ((GSimpleActionGroup*) object);
  }

  auto
  SimpleActionGroup::gobj_copy () -> GSimpleActionGroup*
  {
    reference ();
    return gobj ();
  }

  SimpleActionGroup::SimpleActionGroup (
      const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  SimpleActionGroup::SimpleActionGroup (GSimpleActionGroup* castitem)
    : Object ((GObject*) castitem)
  {
  }

  SimpleActionGroup::SimpleActionGroup (SimpleActionGroup&& src) noexcept
    : Object (std::move (src)),
      ActionGroup (std::move (src)),
      ActionMap (std::move (src))
  {
  }

  auto
  SimpleActionGroup::operator= (SimpleActionGroup&& src) noexcept -> SimpleActionGroup&
  {
    Object::operator= (std::move (src));
    ActionGroup::operator= (std::move (src));
    ActionMap::operator= (std::move (src));
    return *this;
  }

  SimpleActionGroup::~SimpleActionGroup () noexcept = default;

  SimpleActionGroup::CppClassType SimpleActionGroup::simpleactiongroup_class_;

  auto
  SimpleActionGroup::get_type () -> GType
  {
    return simpleactiongroup_class_.init ().get_type ();
  }

  auto
  SimpleActionGroup::get_base_type () -> GType
  {
    return g_simple_action_group_get_type ();
  }

  SimpleActionGroup::SimpleActionGroup ()
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (simpleactiongroup_class_.init ()))
  {
  }

  auto
  SimpleActionGroup::create () -> Glib::RefPtr<SimpleActionGroup>
  {
    return Glib::make_refptr_for_instance<SimpleActionGroup> (
        new SimpleActionGroup ());
  }

} // namespace Gio
