

//#include <libmm/gio/mm-gio.hxx>

#include <libmm/gio/bytesicon.hxx>
#include <libmm/gio/bytesicon_p.hxx>

#include <gio/gio.h>

namespace
{
}

namespace glib
{

  glib::RefPtr<gio::BytesIcon>
  wrap (GBytesIcon* object, bool take_copy)
  {
    return glib::make_refptr_for_instance<gio::BytesIcon> (
        dynamic_cast<gio::BytesIcon*> (
            glib::wrap_auto ((GObject*) (object), take_copy)));
  }

} // namespace glib

namespace gio
{

  const glib::Class&
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

  glib::ObjectBase*
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

  BytesIcon::BytesIcon (const glib::ConstructParams& construct_params)
    : glib::Object (construct_params)
  {
  }

  BytesIcon::BytesIcon (GBytesIcon* castitem)
    : glib::Object ((GObject*) (castitem))
  {
  }

  BytesIcon::BytesIcon (BytesIcon&& src) noexcept
    : glib::Object (std::move (src)),
      Icon (std::move (src)),
      LoadableIcon (std::move (src))
  {
  }

  BytesIcon&
  BytesIcon::operator= (BytesIcon&& src) noexcept
  {
    glib::Object::operator= (std::move (src));
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

  BytesIcon::BytesIcon (const glib::RefPtr<const glib::Bytes>& bytes)
    : glib::ObjectBase (nullptr),
      glib::Object (glib::ConstructParams (
          bytesicon_class_.init (),
          "bytes",
          const_cast<GBytes*> (glib::unwrap<glib::Bytes> (bytes)),
          nullptr))
  {
  }

  glib::RefPtr<BytesIcon>
  BytesIcon::create (const glib::RefPtr<const glib::Bytes>& bytes)
  {
    return glib::make_refptr_for_instance<BytesIcon> (new BytesIcon (bytes));
  }

  glib::RefPtr<const glib::Bytes>
  BytesIcon::get_bytes () const
  {
    auto retvalue =
        glib::wrap (g_bytes_icon_get_bytes (const_cast<GBytesIcon*> (gobj ())));
    if (retvalue)
      retvalue->reference ();
    return retvalue;
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<glib::Bytes>>::value,
      "Type glib::RefPtr<glib::Bytes> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Bytes>>
  BytesIcon::property_bytes () const
  {
    return glib::PropertyProxy_ReadOnly<glib::RefPtr<glib::Bytes>> (this,
                                                                    "bytes");
  }

} // namespace gio
