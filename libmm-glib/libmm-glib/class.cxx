

#include <libmm-glib/class.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/interface_p.hxx>
#include <libmm-glib/property.hxx>
#include <libmm-glib/ustring.hxx>
#include <libmm-glib/utility.hxx>

namespace Glib
{

  auto
  Class::register_derived_type (const GType base_type) -> void
  {
    return register_derived_type (base_type, nullptr);
  }

  auto
  Class::register_derived_type (const GType base_type, GTypeModule* module) -> void
  {
    if (gtype_)
      return;

    if (base_type == 0)
      return;

#if GLIB_CHECK_VERSION(2, 70, 0)

    if (G_TYPE_IS_FINAL (base_type))
    {
      gtype_ = base_type;
      return;
    }
#endif

    GTypeQuery base_query = {
        0,
        nullptr,
        0,
        0,
    };
    g_type_query (base_type, &base_query);

    const guint16 class_size = (guint16) base_query.class_size;

    const guint16 instance_size = (guint16) base_query.instance_size;

    const GTypeInfo derived_info = {
        class_size,
        nullptr,
        nullptr,
        class_init_func_,
        nullptr,
        nullptr,
        instance_size,
        0,
        nullptr,
        nullptr,
    };

    if (!base_query.type_name)
    {
      g_critical (
          "Class::register_derived_type(): base_query.type_name is NULL.");
      return;
    }

    gchar* derived_name =
        g_strconcat ("gtkmm__", base_query.type_name, nullptr);

    if (module)
      gtype_ = g_type_module_register_type (module,
                                            base_type,
                                            derived_name,
                                            &derived_info,
                                            GTypeFlags (0));
    else
      gtype_ = g_type_register_static (base_type,
                                       derived_name,
                                       &derived_info,
                                       GTypeFlags (0));

    g_free (derived_name);
  }

  auto
  Class::clone_custom_type (const char* custom_type_name,
                            const interface_classes_type* interface_classes,
                            const class_init_funcs_type* class_init_funcs,
                            const GInstanceInitFunc instance_init_func) const -> GType
  {
    std::string full_name ("gtkmm__CustomObject_");
    append_canonical_typename (full_name, custom_type_name);

    GType custom_type = g_type_from_name (full_name.c_str ());

    if (!custom_type)
    {
      g_return_val_if_fail (gtype_ != 0, 0);

      const GType base_type = g_type_parent (gtype_);

      GTypeQuery base_query = {
          0,
          nullptr,
          0,
          0,
      };
      g_type_query (base_type, &base_query);

      const guint16 class_size = (guint16) base_query.class_size;

      const guint16 instance_size = (guint16) base_query.instance_size;

      const auto all_class_init_funcs = new class_init_funcs_type (
          1,
          std::tuple<GClassInitFunc, void*> (class_init_func_, nullptr));
      if (class_init_funcs)
        all_class_init_funcs->insert (all_class_init_funcs->end (),
                                      class_init_funcs->begin (),
                                      class_init_funcs->end ());

      const GTypeInfo derived_info = {
          class_size,
          nullptr,
          &Class::custom_class_base_finalize_function,
          &Class::custom_class_init_function,
          nullptr,
          all_class_init_funcs,
          instance_size,
          0,
          instance_init_func,
          nullptr,
      };

      custom_type = g_type_register_static (base_type,
                                            full_name.c_str (),
                                            &derived_info,
                                            GTypeFlags (0));

      if (interface_classes)
      {
        for (const auto interface_class : *interface_classes)
        {
          if (interface_class)
          {
            interface_class->add_interface (custom_type);
          }
        }
      }
    }

    return custom_type;
  }

  GQuark Class::iface_properties_quark =
      g_quark_from_string ("gtkmm_CustomObject_iface_properties");

  auto
  Class::custom_class_base_finalize_function (void* g_class) -> void
  {
    const GType gtype = G_TYPE_FROM_CLASS (g_class);

    const iface_properties_type* props = static_cast<iface_properties_type*> (
        g_type_get_qdata (gtype, iface_properties_quark));

    if (props)
    {
      for (iface_properties_type::size_type i = 0; i < props->size (); i++)
      {
        g_value_unset ((*props)[i]);
        g_free ((*props)[i]);
      }
      delete props;
    }
  }

  auto
  Class::custom_class_init_function (void* g_class, void* class_data) -> void
  {
    const class_init_funcs_type& class_init_funcs =
        *static_cast<class_init_funcs_type*> (class_data);

    g_return_if_fail (!class_init_funcs.empty () &&
                      std::get<GClassInitFunc> (class_init_funcs[0]) !=
                          nullptr);

    const auto init_func = std::get<GClassInitFunc> (class_init_funcs[0]);
    (*init_func) (g_class, nullptr);

    GObjectClass* const gobject_class = static_cast<GObjectClass*> (g_class);
    gobject_class->get_property = &custom_get_property_callback;
    gobject_class->set_property = &custom_set_property_callback;

    for (std::size_t i = 1; i < class_init_funcs.size (); ++i)
    {
      if (const auto extra_init_func =
              std::get<GClassInitFunc> (class_init_funcs[i]))
      {
        const auto extra_class_data = std::get<void*> (class_init_funcs[i]);
        (*extra_init_func) (g_class, extra_class_data);
      }
    }

    delete static_cast<class_init_funcs_type*> (class_data);

    const GType object_type = G_TYPE_FROM_CLASS (g_class);

    iface_properties_type* props = static_cast<iface_properties_type*> (
        g_type_get_qdata (object_type, iface_properties_quark));
    if (!props)
    {
      props = new iface_properties_type ();
      g_type_set_qdata (object_type, iface_properties_quark, props);
    }

    guint n_interfaces = 0;
    GType* iface_types = g_type_interfaces (object_type, &n_interfaces);

    for (guint i = 0; i < n_interfaces; ++i)
    {
      void* const g_iface = g_type_default_interface_ref (iface_types[i]);

      guint n_iface_props = 0;
      GParamSpec** iface_props =
          g_object_interface_list_properties (g_iface, &n_iface_props);

      for (guint p = 0; p < n_iface_props; p++)
      {
        const gchar* prop_name = g_param_spec_get_name (iface_props[p]);

        if (!g_object_class_find_property (gobject_class, prop_name))
        {
          GValue* g_value = g_new0 (GValue, 1);
          g_value_init (g_value, iface_props[p]->value_type);
          g_param_value_set_default (iface_props[p], g_value);
          props->emplace_back (g_value);

          g_object_class_override_property (gobject_class,
                                            props->size (),
                                            prop_name);
        }
      }

      g_type_default_interface_unref (g_iface);
      g_free (iface_props);
    }

    g_free (iface_types);
  }

} // namespace Glib
