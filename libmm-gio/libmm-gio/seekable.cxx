

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/seekable.hxx>
#include <libmm-gio/seekable_p.hxx>

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
  wrap (GSeekable* object, const bool take_copy) -> RefPtr<Gio::Seekable>
  {
    return Glib::make_refptr_for_instance<Gio::Seekable> (
        Glib::wrap_auto_interface<Gio::Seekable> ((GObject*) object,
                                                  take_copy));
  }

} // namespace Glib

namespace Gio
{

  auto
  Seekable_Class::init () -> const Interface_Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &Seekable_Class::iface_init_function;

      gtype_ = g_seekable_get_type ();
    }

    return *this;
  }

  auto
  Seekable_Class::iface_init_function (void* g_iface, void*) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_iface);

    g_assert (klass != nullptr);
  }

  auto
  Seekable_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new Seekable ((GSeekable*) object);
  }

  Seekable::Seekable ()
    : Interface (seekable_class_.init ())
  {
  }

  Seekable::Seekable (GSeekable* castitem)
    : Interface ((GObject*) castitem)
  {
  }

  Seekable::Seekable (const Glib::Interface_Class& interface_class)
    : Interface (interface_class)
  {
  }

  Seekable::Seekable (Seekable&& src) noexcept
    : Interface (std::move (src))
  {
  }

  auto
  Seekable::operator= (Seekable&& src) noexcept -> Seekable&
  {
    Interface::operator= (std::move (src));
    return *this;
  }

  Seekable::~Seekable () noexcept = default;

  auto
  Seekable::add_interface (const GType gtype_implementer) -> void
  {
    seekable_class_.init ().add_interface (gtype_implementer);
  }

  Seekable::CppClassType Seekable::seekable_class_;

  auto
  Seekable::get_type () -> GType
  {
    return seekable_class_.init ().get_type ();
  }

  auto
  Seekable::get_base_type () -> GType
  {
    return g_seekable_get_type ();
  }

  auto
  Seekable::tell () const -> goffset
  {
    return g_seekable_tell (const_cast<GSeekable*> (gobj ()));
  }

  auto
  Seekable::can_seek () const -> bool
  {
    return g_seekable_can_seek (const_cast<GSeekable*> (gobj ()));
  }

  auto
  Seekable::seek (const goffset offset,
                  Glib::SeekType type,
                  const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_seekable_seek (gobj (),
                                           offset,
                                           static_cast<GSeekType> (type),
                                           Glib::unwrap (cancellable),
                                           &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Seekable::seek (const goffset offset, Glib::SeekType type) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_seekable_seek (gobj (),
                                           offset,
                                           static_cast<GSeekType> (type),
                                           nullptr,
                                           &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Seekable::can_truncate () const -> bool
  {
    return g_seekable_can_truncate (const_cast<GSeekable*> (gobj ()));
  }

  auto
  Seekable::truncate (const goffset offset,
                      const Glib::RefPtr<Cancellable>& cancellable) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue = g_seekable_truncate (gobj (),
                                               offset,
                                               Glib::unwrap (cancellable),
                                               &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

  auto
  Seekable::truncate (const goffset offset) -> bool
  {
    GError* gerror = nullptr;
    const auto retvalue =
        g_seekable_truncate (gobj (), offset, nullptr, &gerror);
    if (gerror)
      Glib::Error::throw_exception (gerror);
    return retvalue;
  }

} // namespace Gio
