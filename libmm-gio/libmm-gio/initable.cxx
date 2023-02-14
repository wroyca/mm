

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/initable.hxx>
#include <libmm-gio/initable_p.hxx>

#include <gio/gio.h>
#include <libmm-glib/error.hxx>
#include <libmm-glib/exceptionhandler.hxx>

namespace Gio
{

}

namespace
{
}

namespace Glib
{

  auto
  wrap (GInitable* object, const bool take_copy) -> RefPtr<Gio::Initable>
  {
    return Glib::make_refptr_for_instance<Gio::Initable> (
        Glib::wrap_auto_interface<Gio::Initable> ((GObject*) object,
                                                  take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  Initable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Initable_Class::iface_init_function;

      gtype_ = g_initable_get_type ();
    }

    return *this;
  }

  auto
  Initable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);

    klass->init = &init_vfunc_callback;
  }

  auto
  Initable_Class::init_vfunc_callback (GInitable* self,
                                       GCancellable* cancellable,
                                       GError** error) -> gboolean
  {
    const auto obj_base =
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self);

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          return obj->init_vfunc (Glib::wrap (cancellable), error);
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const BaseClassType* const base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (self),
                                   CppObjectType::get_type ())));

    if (base && base->init)
      return (*base->init) (self, cancellable, error);

    using RType = gboolean;
    return RType ();
  }

  auto
  Initable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Initable ((GInitable*) object);
  }

  Initable::Initable ()
    : Interface (initable_class_.init ())
  {
  }

  Initable::Initable (GInitable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Initable::Initable (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Initable::Initable (Initable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Initable::operator= (Initable&& src) noexcept -> Initable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Initable::~Initable () noexcept = default;

  auto
  Initable::add_interface (const GType gtype_implementer) -> void
  {
    initable_class_.init ().add_interface (gtype_implementer);
  }

  Initable::CppClassType Initable::initable_class_;

  auto
  Initable::get_type () -> GType
  {
    return initable_class_.init ().get_type ();
  }

  auto
  Initable::get_base_type () -> GType
  {
    return g_initable_get_type ();
  }

  auto
  Initable::init (const Glib::RefPtr<Cancellable>& cancellable) -> void
  {
    GError* gerror = nullptr;
    g_initable_init (gobj (), Glib::unwrap (cancellable), &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Initable::init () -> void
  {
    GError* gerror = nullptr;
    g_initable_init (gobj (), nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
  }

  auto
  Initable::init_vfunc (const Glib::RefPtr<Cancellable>& cancellable,
                        GError** error) -> bool
  {
    const auto base =
        static_cast<BaseClassType*> (g_type_interface_peek_parent (
            g_type_interface_peek (G_OBJECT_GET_CLASS (gobject_),
                                   get_type ())));

    if (base && base->init)
    {
      const bool retval (
          (*base->init) (gobj (), Glib::unwrap (cancellable), error));
      return retval;
    }

    using RType = bool;
    return RType ();
  }

} // namespace Gio
