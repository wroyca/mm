// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/property.hxx>

#include <cstddef>
#include <libmm-glib/class.hxx>
#include <libmm-glib/object.hxx>
#include <map>

#undef G_STRLOC
#define G_STRLOC __FILE__ ":" G_STRINGIFY (__LINE__)

namespace
{

  auto
  destroy_notify_obj_iface_props (void* data) -> void
  {
    const auto obj_iface_props =
        static_cast<Glib::Class::iface_properties_type*> (data);
    if (obj_iface_props)
    {
      for (Glib::Class::iface_properties_type::size_type i = 0;
           i < obj_iface_props->size ();
           i++)
      {
        g_value_unset ((*obj_iface_props)[i]);
        g_free ((*obj_iface_props)[i]);
      }
      delete obj_iface_props;
    }
  }

  struct custom_properties_type
  {
    std::vector<Glib::PropertyBase*> prop_base_vector;

    std::map<unsigned int, GValue*> prop_value_map;
  };

  const GQuark custom_properties_quark =
      g_quark_from_string ("gtkmm_CustomObject_custom_properties");

  auto
  destroy_notify_obj_custom_props (void* data) -> void
  {
    const auto obj_custom_props = static_cast<custom_properties_type*> (data);

    const auto map_end = obj_custom_props->prop_value_map.end ();
    for (auto it = obj_custom_props->prop_value_map.begin (); it != map_end;
         ++it)
    {
      g_value_unset (it->second);
      g_free (it->second);
    }
    delete obj_custom_props;
  }

  auto
  get_obj_custom_props (GObject* obj) -> custom_properties_type*
  {
    auto obj_custom_props = static_cast<custom_properties_type*> (
        g_object_get_qdata (obj, custom_properties_quark));
    if (!obj_custom_props)
    {
      obj_custom_props = new custom_properties_type ();
      g_object_set_qdata_full (obj,
                               custom_properties_quark,
                               obj_custom_props,
                               destroy_notify_obj_custom_props);
    }
    return obj_custom_props;
  }

} // namespace

namespace Glib
{

  auto
  custom_get_property_callback (GObject* object,
                                const unsigned int property_id,
                                GValue* value,
                                GParamSpec* param_spec) -> void
  {
    g_return_if_fail (property_id != 0);

    const GType custom_type = G_OBJECT_TYPE (object);

    const auto iface_props = static_cast<Class::iface_properties_type*> (
        g_type_get_qdata (custom_type, Class::iface_properties_quark));

    Class::iface_properties_type::size_type iface_props_size = 0;

    if (iface_props)
      iface_props_size = iface_props->size ();

    if (property_id <= iface_props_size)
    {
      const auto obj_iface_props = static_cast<Class::iface_properties_type*> (
          g_object_get_qdata (object, Class::iface_properties_quark));
      if (obj_iface_props)
        g_value_copy ((*obj_iface_props)[property_id - 1], value);
      else
        g_value_copy ((*iface_props)[property_id - 1], value);
    }
    else
    {
      const auto obj_custom_props = get_obj_custom_props (object);
      const unsigned index = property_id - iface_props_size - 1;

      if (const ObjectBase* const wrapper =
              ObjectBase::_get_current_wrapper (object))
      {
        if (obj_custom_props &&
            index < obj_custom_props->prop_base_vector.size ())
        {
          const PropertyBase* prop_base =
              obj_custom_props->prop_base_vector[index];
          if (prop_base->object_ == wrapper &&
              prop_base->param_spec_ == param_spec)
            g_value_copy (prop_base->value_.gobj (), value);
          else
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, param_spec);
        }
        else
          G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, param_spec);
      }
      else
      {
        const auto it = obj_custom_props->prop_value_map.find (index);
        if (it != obj_custom_props->prop_value_map.end ())
          g_value_copy (it->second, value);
        else

          g_value_copy (g_param_spec_get_default_value (param_spec), value);
      }
    }
  }

  auto
  custom_set_property_callback (GObject* object,
                                const unsigned int property_id,
                                const GValue* value,
                                GParamSpec* param_spec) -> void
  {
    g_return_if_fail (property_id != 0);

    const GType custom_type = G_OBJECT_TYPE (object);

    const auto iface_props = static_cast<Class::iface_properties_type*> (
        g_type_get_qdata (custom_type, Class::iface_properties_quark));

    Class::iface_properties_type::size_type iface_props_size = 0;

    if (iface_props)
      iface_props_size = iface_props->size ();

    if (property_id <= iface_props_size)
    {
      auto obj_iface_props = static_cast<Class::iface_properties_type*> (
          g_object_get_qdata (object, Class::iface_properties_quark));
      if (!obj_iface_props)
      {
        obj_iface_props = new Class::iface_properties_type ();
        g_object_set_qdata_full (object,
                                 Class::iface_properties_quark,
                                 obj_iface_props,
                                 destroy_notify_obj_iface_props);
        for (Class::iface_properties_type::size_type p = 0;
             p < iface_props_size;
             ++p)
        {
          GValue* g_value = g_new0 (GValue, 1);
          g_value_init (g_value, G_VALUE_TYPE ((*iface_props)[p]));
          g_value_copy ((*iface_props)[p], g_value);
          obj_iface_props->emplace_back (g_value);
        }
      }

      g_value_copy (value, (*obj_iface_props)[property_id - 1]);
      g_object_notify_by_pspec (object, param_spec);
    }
    else
    {
      const auto obj_custom_props = get_obj_custom_props (object);
      const unsigned index = property_id - iface_props_size - 1;

      if (const ObjectBase* const wrapper =
              ObjectBase::_get_current_wrapper (object))
      {
        if (obj_custom_props &&
            index < obj_custom_props->prop_base_vector.size ())
        {
          PropertyBase* prop_base = obj_custom_props->prop_base_vector[index];
          if (prop_base->object_ == wrapper &&
              prop_base->param_spec_ == param_spec)
          {
            g_value_copy (value, prop_base->value_.gobj ());
            g_object_notify_by_pspec (object, param_spec);
          }
          else
            G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, param_spec);
        }
        else
          G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, param_spec);
      }
      else
      {
        const auto it = obj_custom_props->prop_value_map.find (index);
        if (it != obj_custom_props->prop_value_map.end ())
          g_value_copy (value, it->second);
        else
        {
          GValue* g_value = g_new0 (GValue, 1);
          g_value_init (g_value, G_VALUE_TYPE (value));
          g_value_copy (value, g_value);
          obj_custom_props->prop_value_map[index] = g_value;
        }
        g_object_notify_by_pspec (object, param_spec);
      }
    }
  }

  PropertyBase::PropertyBase (Object& object, const GType value_type)
    : object_ (&object),
      value_ (),
      param_spec_ (nullptr)
  {
    value_.init (value_type);
  }

  PropertyBase::~PropertyBase () noexcept
  {
    if (param_spec_)
      g_param_spec_unref (param_spec_);
  }

  auto
  PropertyBase::lookup_property (const ustring& name) -> bool
  {
    g_assert (param_spec_ == nullptr);

    param_spec_ = g_object_class_find_property (
        G_OBJECT_GET_CLASS (object_->gobj ()),
        name.c_str ());

    if (param_spec_)
    {
      g_assert (G_PARAM_SPEC_VALUE_TYPE (param_spec_) ==
                G_VALUE_TYPE (value_.gobj ()));
      g_param_spec_ref (param_spec_);

      const auto obj_custom_props = get_obj_custom_props (object_->gobj ());
      const unsigned int pos_in_obj_custom_props =
          obj_custom_props->prop_base_vector.size ();
      obj_custom_props->prop_base_vector.emplace_back (this);

      const auto it =
          obj_custom_props->prop_value_map.find (pos_in_obj_custom_props);
      if (it != obj_custom_props->prop_value_map.end ())
        g_value_copy (it->second, value_.gobj ());
    }

    return param_spec_ != nullptr;
  }

  auto
  PropertyBase::install_property (GParamSpec* param_spec) -> void
  {
    g_return_if_fail (param_spec != nullptr);

    const GType gtype = G_OBJECT_TYPE (object_->gobj ());
    const auto iface_props = static_cast<Class::iface_properties_type*> (
        g_type_get_qdata (gtype, Class::iface_properties_quark));

    Class::iface_properties_type::size_type iface_props_size = 0;
    if (iface_props)
      iface_props_size = iface_props->size ();

    const auto obj_custom_props = get_obj_custom_props (object_->gobj ());

    const unsigned int pos_in_obj_custom_props =
        obj_custom_props->prop_base_vector.size ();
    obj_custom_props->prop_base_vector.emplace_back (this);

    const unsigned int property_id = pos_in_obj_custom_props +
                                     iface_props_size + 1;

    g_object_class_install_property (G_OBJECT_GET_CLASS (object_->gobj ()),
                                     property_id,
                                     param_spec);

    param_spec_ = param_spec;
    g_param_spec_ref (param_spec_);
  }

  auto
  PropertyBase::get_name_internal () const -> const char*
  {
    const char* const name = g_param_spec_get_name (param_spec_);
    g_return_val_if_fail (name != nullptr, "");
    return name;
  }

  auto
  PropertyBase::get_name () const -> ustring
  {
    return {get_name_internal ()};
  }

  auto
  PropertyBase::get_nick () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_param_spec_get_nick (param_spec_));
  }

  auto
  PropertyBase::get_blurb () const -> ustring
  {
    return convert_const_gchar_ptr_to_ustring (
        g_param_spec_get_blurb (param_spec_));
  }

  auto
  PropertyBase::notify () -> void
  {
    g_object_notify_by_pspec (object_->gobj (), param_spec_);
  }

} // namespace Glib
