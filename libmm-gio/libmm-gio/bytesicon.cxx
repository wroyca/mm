

//#include <libmm-gio/mm-gio.hxx>

#include <libmm-gio/bytesicon.hxx>
#include <libmm-gio/bytesicon_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace Glib
{

  Glib::RefPtr<Gio::BytesIcon>
  wrap (GBytesIcon* object, bool take_copy)
  {
    return Glib::make_refptr_for_instance<Gio::BytesIcon> (
        dynamic_cast<Gio::BytesIcon*> (
            Glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace Glib

namespace Gio
{

  const Glib::Class&
  BytesIcon_Class::init ()
  {
    if (!gtype_)
    {
      class_init_func_ = &BytesIcon_Class::class_init_function;

      register_derived_type (g_bytes_icon_get_type ());

      Icon::add_interface (get_type ());
      LoadableIcon::add_interface (get_type ());
    }

    return *this;
  }

  void
  BytesIcon_Class::class_init_function (void* g_class, void* class_data)
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  Glib::ObjectBase*
  BytesIcon_Class::wrap_new (GObject* object)
  {
    return new BytesIcon ((GBytesIcon*) object);
  }

  GBytesIcon*
  BytesIcon::gobj_copy ()
  {
    reference ();
    return gobj ();
  }

  BytesIcon::BytesIcon (const Glib::ConstructParams& construct_params)
    : Glib::Object (construct_params)
  {
  }

  BytesIcon::BytesIcon (GBytesIcon* castitem)
    : Glib::Object ((GObject*) (castitem))
  {
  }

  BytesIcon::BytesIcon (BytesIcon&& src) noexcept
    : Glib::Object (std::move (src)),
      Icon (std::move (src)),
      LoadableIcon (std::move (src))
  {
  }

  BytesIcon&
  BytesIcon::operator= (BytesIcon&& src) noexcept
  {
    Glib::Object::operator= (std::move (src));
    Icon::operator= (std::move (src));
    LoadableIcon::operator= (std::move (src));
    return *this;
  }

  BytesIcon::~BytesIcon () noexcept {}

  BytesIcon::CppClassType BytesIcon::bytesicon_class_;

  GType
  BytesIcon::get_type ()
  {
    return bytesicon_class_.init ().get_type ();
  }

  GType
  BytesIcon::get_base_type ()
  {
    return g_bytes_icon_get_type ();
  }

  BytesIcon::BytesIcon (const Glib::RefPtr<const Glib::Bytes>& bytes)
    : Glib::ObjectBase (nullptr),
      Glib::Object (Glib::ConstructParams (
          bytesicon_class_.init (),
          "bytes",
          const_cast<GBytes*> (Glib::unwrap<Glib::Bytes> (bytes)),
          nullptr))
  {
  }

  Glib::RefPtr<BytesIcon>
  BytesIcon::create (const Glib::RefPtr<const Glib::Bytes>& bytes)
  {
    return Glib::make_refptr_for_instance<BytesIcon> (new BytesIcon (bytes));
  }

  Glib::RefPtr<const Glib::Bytes>
  BytesIcon::get_bytes () const
  {
    auto retvalue =
        Glib::wrap (g_bytes_icon_get_bytes (const_cast<GBytesIcon*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<Glib::Bytes>>::value,
      "Type Glib::RefPtr<Glib::Bytes> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::Bytes>>
  BytesIcon::property_bytes () const
  {
    return Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Glib::Bytes>> (this,
                                                                    "bytes");
  }

} // namespace Gio
