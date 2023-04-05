// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/interface.hxx>
#include <libmm/glib/interface_p.hxx>

namespace glib
{

  auto
  Interface_Class::add_interface (const GType instance_type) const -> void
  {
#if GLIB_CHECK_VERSION(2, 70, 0)

    if (G_TYPE_IS_FINAL (instance_type))
      return;
#endif

    const GInterfaceInfo interface_info = {
        class_init_func_,
        nullptr,
        nullptr,
    };

    g_type_add_interface_static (instance_type, gtype_, &interface_info);
  }

  Interface::Interface (const Interface_Class& interface_class)
  {
    if (custom_type_name_ && !is_anonymous_custom_ ())
    {
      if (gobject_)
      {
        GObjectClass* const instance_class = G_OBJECT_GET_CLASS (gobject_);
        const GType iface_type = interface_class.get_type ();

        if (!g_type_interface_peek (instance_class, iface_type))
        {
          void* const g_iface = g_type_default_interface_ref (iface_type);

          const GType custom_type = G_OBJECT_CLASS_TYPE (instance_class);
          Class::iface_properties_type* props =
              static_cast<Class::iface_properties_type*> (
                  g_type_get_qdata (custom_type,
                                    Class::iface_properties_quark));

          if (!props)
          {
            props = new Class::iface_properties_type ();
            g_type_set_qdata (custom_type,
                              Class::iface_properties_quark,
                              props);
          }

          const guint n_existing_props = props->size ();

          guint n_iface_props = 0;
          GParamSpec** iface_props =
              g_object_interface_list_properties (g_iface, &n_iface_props);

          for (guint p = 0; p < n_iface_props; p++)
          {
            GValue* g_value = g_new0 (GValue, 1);
            g_value_init (g_value, iface_props[p]->value_type);
            g_param_value_set_default (iface_props[p], g_value);
            props->emplace_back (g_value);

            const gchar* prop_name = g_param_spec_get_name (iface_props[p]);
            GParamSpec* new_spec = g_param_spec_override (prop_name,
                                                          iface_props[p]);
            g_object_class_install_property (instance_class,
                                             p + 1 + n_existing_props,
                                             new_spec);
          }

          interface_class.add_interface (custom_type);

          g_type_default_interface_unref (g_iface);
          g_free (iface_props);
        }
      }
      else
      {
        add_custom_interface_class (&interface_class);
      }
    }
  }

  Interface::Interface (GObject* castitem)
  {
    initialize (castitem);
  }

  Interface::Interface () = default;

  Interface::Interface (Interface&& src) noexcept
    : trackable (std::move (src)),
      ObjectBase (std::move (src))
  {
  }

  auto
  Interface::operator= (Interface&&) noexcept -> Interface&
  {
    return *this;
  }

  Interface::~Interface () noexcept = default;

  auto
  Interface::get_type () -> GType
  {
    return G_TYPE_INTERFACE;
  }

  auto
  Interface::get_base_type () -> GType
  {
    return G_TYPE_INTERFACE;
  }

  auto
  wrap_interface (GObject* object, const bool take_copy) -> RefPtr<ObjectBase>
  {
    return glib::make_refptr_for_instance<ObjectBase> (
        wrap_auto (object, take_copy));
  }

} // namespace glib
