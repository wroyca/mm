// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/object.hxx>
#include <libmm-glib/object_p.hxx>
#include <libmm-glib/property.hxx>

#include <glib-object.h>
#include <gobject/gvaluecollector.h>

#include <cstdarg>
#include <cstring>

#include <string.h>

namespace Glib
{

  ConstructParams::ConstructParams (const Class& glibmm_class_)
    : glibmm_class (glibmm_class_),
      n_parameters (0),
      parameter_names (nullptr),
      parameter_values (nullptr)
  {
  }

  ConstructParams::ConstructParams (const Class& glibmm_class_,
                                    const char* first_property_name,
                                    ...)
    : glibmm_class (glibmm_class_),
      n_parameters (0),
      parameter_names (nullptr),
      parameter_values (nullptr)
  {
    va_list var_args;
    va_start (var_args, first_property_name);

    GObjectClass* const g_class = static_cast<GObjectClass*> (
        g_type_class_ref (glibmm_class.get_type ()));

    unsigned int n_alloced_params = 0;
    char* collect_error = nullptr;

    for (const char* name = first_property_name; name != nullptr;
         name = va_arg (var_args, char*))
    {
      GParamSpec* const pspec = g_object_class_find_property (g_class, name);

      if (!pspec)
      {
        g_warning ("Glib::ConstructParams::ConstructParams(): "
                   "object class \"%s\" has no property named \"%s\"",
                   g_type_name (glibmm_class.get_type ()),
                   name);
        break;
      }

      if (n_parameters >= n_alloced_params)
      {
        n_alloced_params += 8;
        parameter_names =
            g_renew (const char*, parameter_names, n_alloced_params);
        parameter_values = g_renew (GValue, parameter_values, n_alloced_params);
      }

      auto& param_name = parameter_names[n_parameters];
      auto& param_value = parameter_values[n_parameters];
      param_name = name;
      param_value.g_type = 0;

      g_value_init (&param_value, G_PARAM_SPEC_VALUE_TYPE (pspec));
      G_VALUE_COLLECT (&param_value, var_args, 0, &collect_error);

      if (collect_error)
      {
        g_warning ("Glib::ConstructParams::ConstructParams(): %s",
                   collect_error);
        g_free (collect_error);
        g_value_unset (&param_value);
        break;
      }

      ++n_parameters;
    }

    g_type_class_unref (g_class);

    va_end (var_args);
  }

  ConstructParams::~ConstructParams () noexcept
  {
    while (n_parameters > 0)
    {
      auto& param_value = parameter_values[--n_parameters];
      g_value_unset (&param_value);
    }

    g_free (parameter_names);
    g_free (parameter_values);
  }

  auto
  Object_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Object_Class::class_init_function;
      register_derived_type (G_TYPE_OBJECT);
    }

    return *this;
  }

  auto
  Object_Class::class_init_function (void*, void*) -> void
  {
  }

  auto
  Object_Class::wrap_new (GObject* object) -> Object*
  {
    return new Object (object);
  }

  Object::CppClassType Object::object_class_;

  Object::Object ()
  {
    GType object_type = G_TYPE_OBJECT;

    if (custom_type_name_ && !is_anonymous_custom_ ())
    {
      object_class_.init ();

      object_type = object_class_.clone_custom_type (
          custom_type_name_,
          get_custom_interface_classes (),
          get_custom_class_init_functions (),
          get_custom_instance_init_function ());
      custom_class_init_finished ();
    }

    GObject* const new_object =
        g_object_new_with_properties (object_type, 0, nullptr, nullptr);

    initialize (new_object);
  }

  Object::Object (const ConstructParams& construct_params)
  {
    GType object_type = construct_params.glibmm_class.get_type ();

    if (custom_type_name_ && !is_anonymous_custom_ ())
    {
      object_type = construct_params.glibmm_class.clone_custom_type (
          custom_type_name_,
          get_custom_interface_classes (),
          get_custom_class_init_functions (),
          get_custom_instance_init_function ());
      custom_class_init_finished ();
    }

    GObject* const new_object = g_object_new_with_properties (
        object_type,
        construct_params.n_parameters,
        construct_params.parameter_names,
        construct_params.parameter_values);

    initialize (new_object);
  }

  Object::Object (GObject* castitem)
  {
    initialize (castitem);
  }

  Object::Object (Object&& src) noexcept
    : trackable (std::move (src)),
      ObjectBase (std::move (src))
  {
    src.notify_callbacks ();
    initialize_move (src.gobject_, &src);
  }

  auto
  Object::operator= (Object&& src) noexcept -> Object&
  {
    ObjectBase::operator= (std::move (src));
    return *this;
  }

  Object::~Object () noexcept
  {
    cpp_destruction_in_progress_ = true;
  }

  auto
  Object::get_type () -> GType
  {
    return object_class_.init ().get_type ();
  }

  auto
  Object::get_base_type () -> GType
  {
    return G_TYPE_OBJECT;
  }

  auto
  Object::get_data (const QueryQuark& id) -> void*
  {
    return g_object_get_qdata (gobj (), id);
  }

  auto
  Object::set_data (const Quark& id, void* data) -> void
  {
    g_object_set_qdata (gobj (), id, data);
  }

  auto
  Object::set_data (const Quark& id, void* data, const DestroyNotify destroy) -> void
  {
    g_object_set_qdata_full (gobj (), id, data, destroy);
  }

  auto
  Object::remove_data (const QueryQuark& id) -> void
  {
    g_return_if_fail (id.id () > 0);
    g_datalist_id_remove_data (&gobj ()->qdata, id);
  }

  auto
  Object::steal_data (const QueryQuark& id) -> void*
  {
    return g_object_steal_qdata (gobj (), id);
  }

} // namespace Glib
