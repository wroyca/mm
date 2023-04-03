// SPDX-License-Identifier: LGPL-2.1-or-later

#include <glib-object.h>
#include <glib.h>
#include <libmm/glib/mm-glibconfig.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/glib/quark.hxx>
#include <libmm/glib/wrap.hxx>
#include <vector>

namespace
{

  using WrapFuncTable = std::vector<Glib::WrapNewFunction>;

  WrapFuncTable* wrap_func_table = nullptr;

} // namespace

namespace Glib
{

  auto
  wrap_register_init () -> void
  {
    if (!quark_)
    {
      quark_ = g_quark_from_string ("glibmm__Glib::quark_");
      quark_cpp_wrapper_deleted_ =
          g_quark_from_string ("glibmm__Glib::quark_cpp_wrapper_deleted_");
    }

    if (!wrap_func_table)
    {
      wrap_func_table = new WrapFuncTable (1);
    }
  }

  auto
  wrap_register_cleanup () -> void
  {
    if (wrap_func_table)
    {
      delete wrap_func_table;
      wrap_func_table = nullptr;
    }
  }

  auto
  wrap_register (const GType type, WrapNewFunction func) -> void
  {
    if (type == 0)
      return;

    const guint idx = wrap_func_table->size ();
    wrap_func_table->emplace_back (func);

    g_type_set_qdata (type, quark_, GUINT_TO_POINTER (idx));
  }

  static auto
  wrap_create_new_wrapper (GObject* object) -> ObjectBase*
  {
    g_return_val_if_fail (wrap_func_table != nullptr, nullptr);

    const bool gtkmm_wrapper_already_deleted =
        (bool) g_object_get_qdata (object, quark_cpp_wrapper_deleted_);
    if (gtkmm_wrapper_already_deleted)
    {
      g_warning ("Glib::wrap_create_new_wrapper: Attempted to create a 2nd C++ "
                 "wrapper for a C "
                 "instance whose C++ wrapper has been deleted.");
      return nullptr;
    }

    for (GType type = G_OBJECT_TYPE (object); type != 0;
         type = g_type_parent (type))
    {
      if (const gpointer idx = g_type_get_qdata (type, quark_))
      {
        const WrapNewFunction func = (*wrap_func_table)[GPOINTER_TO_UINT (idx)];
        return (*func) (object);
      }
    }

    return nullptr;
  }

  static auto
  gtype_wraps_interface (const GType implementer_type,
                         const GType interface_type) -> gboolean
  {
    guint n_ifaces = 0;
    GType* ifaces = g_type_interfaces (implementer_type, &n_ifaces);

    gboolean found = FALSE;
    while (n_ifaces-- && !found)
    {
      found = ifaces[n_ifaces] == interface_type;
    }

    g_free (ifaces);

    return found;
  }

  auto
  wrap_create_new_wrapper_for_interface (GObject* object,
                                         const GType interface_gtype) -> ObjectBase*
  {
    g_return_val_if_fail (wrap_func_table != nullptr, nullptr);

    const bool gtkmm_wrapper_already_deleted =
        (bool) g_object_get_qdata (object, quark_cpp_wrapper_deleted_);
    if (gtkmm_wrapper_already_deleted)
    {
      g_warning ("Glib::wrap_create_new_wrapper: Attempted to create a 2nd C++ "
                 "wrapper for a C "
                 "instance whose C++ wrapper has been deleted.");
      return nullptr;
    }

    for (GType type = G_OBJECT_TYPE (object); type != 0;
         type = g_type_parent (type))
    {
      const gpointer idx = g_type_get_qdata (type, quark_);
      if (idx && gtype_wraps_interface (type, interface_gtype))
      {
        const WrapNewFunction func = (*wrap_func_table)[GPOINTER_TO_UINT (idx)];
        return (*func) (object);
      }
    }

    return nullptr;
  }

  auto
  wrap_auto (GObject* object, const bool take_copy) -> ObjectBase*
  {
    if (!object)
      return nullptr;

    ObjectBase* pCppObject = ObjectBase::_get_current_wrapper (object);

    if (!pCppObject)
    {
      pCppObject = wrap_create_new_wrapper (object);

      if (!pCppObject)
      {
        g_warning ("Failed to wrap object of type '%s'. Hint: this error is "
                   "commonly caused by "
                   "failing to call a library init() function.",
                   G_OBJECT_TYPE_NAME (object));
        return nullptr;
      }
    }

    if (take_copy)
      pCppObject->reference ();

    return pCppObject;
  }

  auto
  wrap (GObject* object, const bool take_copy) -> RefPtr<Object>
  {
    return Glib::make_refptr_for_instance<Object> (
        dynamic_cast<Object*> (wrap_auto (object, take_copy)));
  }

} // namespace Glib
