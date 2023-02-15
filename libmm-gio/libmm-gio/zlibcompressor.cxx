// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/zlibcompressor.hxx>
#include <libmm-gio/zlibcompressor_p.hxx>

#include <gio/gio.h>
#include <libmm-gio/fileinfo.hxx>

namespace Gio
{

}

namespace
{
}

auto
Glib::Value<Gio::ZlibCompressorFormat>::value_type () -> GType
{
  return g_zlib_compressor_format_get_type ();
}

namespace Glib
{

  auto
  wrap (GZlibCompressor* object, const bool take_copy) -> RefPtr<Gio::ZlibCompressor>
  {
    return Glib::make_refptr_for_instance<Gio::ZlibCompressor> (
        dynamic_cast<Gio::ZlibCompressor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
{

  auto
  ZlibCompressor_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &ZlibCompressor_Class::class_init_function;

      register_derived_type (g_zlib_compressor_get_type ());

      Converter::add_interface (get_type ());
    }

    return *this;
  }

  auto
  ZlibCompressor_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  ZlibCompressor_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
  {
    return new ZlibCompressor ((GZlibCompressor*) object);
  }

  auto
  ZlibCompressor::gobj_copy () -> GZlibCompressor*
  {
    reference ();
    return gobj ();
  }

  ZlibCompressor::ZlibCompressor (const Glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  ZlibCompressor::ZlibCompressor (GZlibCompressor* castitem)
    : Object ((GObject*) castitem)
  {
  }

  ZlibCompressor::ZlibCompressor (ZlibCompressor&& src) noexcept
    : Object (std::move (src)),
      Converter (std::move (src))
  {
  }

  auto
  ZlibCompressor::operator= (ZlibCompressor&& src) noexcept -> ZlibCompressor&
  {
    Object::operator= (std::move (src));
    Converter::operator= (std::move (src));
    return *this;
  }

  ZlibCompressor::~ZlibCompressor () noexcept = default;

  ZlibCompressor::CppClassType ZlibCompressor::zlibcompressor_class_;

  auto
  ZlibCompressor::get_type () -> GType
  {
    return zlibcompressor_class_.init ().get_type ();
  }

  auto
  ZlibCompressor::get_base_type () -> GType
  {
    return g_zlib_compressor_get_type ();
  }

  ZlibCompressor::ZlibCompressor (const ZlibCompressorFormat format,
                                  const int level)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (zlibcompressor_class_.init (),
                                     "format",
                                     format,
                                     "level",
                                     level,
                                     nullptr))
  {
  }

  auto
  ZlibCompressor::create (const ZlibCompressorFormat format, const int level) -> Glib::RefPtr<ZlibCompressor>
  {
    return Glib::make_refptr_for_instance<ZlibCompressor> (
        new ZlibCompressor (format, level));
  }

  auto
  ZlibCompressor::get_file_info () -> Glib::RefPtr<FileInfo>
  {
    return Glib::wrap (g_zlib_compressor_get_file_info (gobj ()));
  }

  auto
  ZlibCompressor::get_file_info () const -> Glib::RefPtr<const FileInfo>
  {
    return const_cast<ZlibCompressor*> (this)->get_file_info ();
  }

  auto
  ZlibCompressor::set_file_info (const Glib::RefPtr<FileInfo>& file_info) -> void
  {
    g_zlib_compressor_set_file_info (gobj (), Glib::unwrap (file_info));
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          Glib::RefPtr<FileInfo>>::value,
      "Type Glib::RefPtr<FileInfo> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ZlibCompressor::property_file_info () -> Glib::PropertyProxy<Glib::RefPtr<FileInfo>>
  {
    return {this, "file-info"};
  }

  auto
  ZlibCompressor::property_file_info () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<FileInfo>>
  {
    return {this, "file-info"};
  }

  static_assert (
      Glib::Traits::ValueCompatibleWithWrapProperty<
          ZlibCompressorFormat>::value,
      "Type ZlibCompressorFormat cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of Glib::Value<>.");

  auto
  ZlibCompressor::property_format () const -> Glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>
  {
    return {this, "format"};
  }

  auto
  ZlibCompressor::property_level () const -> Glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "level"};
  }

} // namespace Gio
