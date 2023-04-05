// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/zlibdecompressor.hxx>
#include <libmm/gio/zlibdecompressor_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/fileinfo.hxx>

namespace gio
{

}

namespace
{
}

namespace glib
{

  auto
  wrap (GZlibDecompressor* object, const bool take_copy) -> RefPtr<gio::ZlibDecompressor>
  {
    return glib::make_refptr_for_instance<gio::ZlibDecompressor> (
        dynamic_cast<gio::ZlibDecompressor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  ZlibDecompressor_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ZlibDecompressor_Class::class_init_function;

      register_derived_type (g_zlib_decompressor_get_type ());

      Converter::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ZlibDecompressor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ZlibDecompressor_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ZlibDecompressor ((GZlibDecompressor*) object);
  }

  auto
  ZlibDecompressor::gobj_copy () -> GZlibDecompressor*
  {
    reference ();
    return gobj ();
  }

  ZlibDecompressor::ZlibDecompressor (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ZlibDecompressor::ZlibDecompressor (GZlibDecompressor* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ZlibDecompressor::ZlibDecompressor (ZlibDecompressor&& src) noexcept
    : Object (std::move (src)),
      Converter (std::move (src))
  {
  }

  auto
  ZlibDecompressor::operator= (ZlibDecompressor&& src) noexcept -> ZlibDecompressor&
  {
    Object::operator= (std::move (src));
    Converter::operator= (std::move (src));
    return *this;
  }

  ZlibDecompressor::~ZlibDecompressor () noexcept = default;

  ZlibDecompressor::CppClassType ZlibDecompressor::zlibdecompressor_class_;

  auto
  ZlibDecompressor::get_type () -> GType
  {
    return zlibdecompressor_class_.init ().get_type ();
  }

  auto
  ZlibDecompressor::get_base_type () -> GType
  {
    return g_zlib_decompressor_get_type ();
  }

  ZlibDecompressor::ZlibDecompressor (const ZlibCompressorFormat format)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (zlibdecompressor_class_.init (),
                                     "format",
                                     format,
                                     nullptr))
  {
  }

  auto
  ZlibDecompressor::create (const ZlibCompressorFormat format) -> glib::RefPtr<ZlibDecompressor>
  {
    return glib::make_refptr_for_instance<ZlibDecompressor> (
        new ZlibDecompressor (format));
  }

  auto
  ZlibDecompressor::get_file_info () -> glib::RefPtr<FileInfo>
  {
    return glib::wrap (g_zlib_decompressor_get_file_info (gobj ()));
  }

  auto
  ZlibDecompressor::get_file_info () const -> glib::RefPtr<const FileInfo>
  {
    return const_cast<ZlibDecompressor*> (this)->get_file_info ();
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FileInfo>>::value,
      "Type glib::RefPtr<FileInfo> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ZlibDecompressor::property_file_info () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileInfo>>
  {
    return {this, "file-info"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          ZlibCompressorFormat>::value,
      "Type ZlibCompressorFormat cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ZlibDecompressor::property_format () const -> glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>
  {
    return {this, "format"};
  }

} // namespace gio
