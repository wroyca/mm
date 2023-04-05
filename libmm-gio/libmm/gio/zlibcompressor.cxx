// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/zlibcompressor.hxx>
#include <libmm/gio/zlibcompressor_p.hxx>

#include <gio/gio.h>
#include <libmm/gio/fileinfo.hxx>

namespace gio
{

}

namespace
{
}

auto
glib::Value<gio::ZlibCompressorFormat>::value_type () -> GType
{
  return g_zlib_compressor_format_get_type ();
}

namespace glib
{

  auto
  wrap (GZlibCompressor* object, const bool take_copy) -> RefPtr<gio::ZlibCompressor>
  {
    return glib::make_refptr_for_instance<gio::ZlibCompressor> (
        dynamic_cast<gio::ZlibCompressor*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
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
  ZlibCompressor_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new ZlibCompressor ((GZlibCompressor*) object);
  }

  auto
  ZlibCompressor::gobj_copy () -> GZlibCompressor*
  {
    reference ();
    return gobj ();
  }

  ZlibCompressor::ZlibCompressor (const glib::ConstructParams& construct_params)
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
      Object (glib::ConstructParams (zlibcompressor_class_.init (),
                                     "format",
                                     format,
                                     "level",
                                     level,
                                     nullptr))
  {
  }

  auto
  ZlibCompressor::create (const ZlibCompressorFormat format, const int level) -> glib::RefPtr<ZlibCompressor>
  {
    return glib::make_refptr_for_instance<ZlibCompressor> (
        new ZlibCompressor (format, level));
  }

  auto
  ZlibCompressor::get_file_info () -> glib::RefPtr<FileInfo>
  {
    return glib::wrap (g_zlib_compressor_get_file_info (gobj ()));
  }

  auto
  ZlibCompressor::get_file_info () const -> glib::RefPtr<const FileInfo>
  {
    return const_cast<ZlibCompressor*> (this)->get_file_info ();
  }

  auto
  ZlibCompressor::set_file_info (const glib::RefPtr<FileInfo>& file_info) -> void
  {
    g_zlib_compressor_set_file_info (gobj (), glib::unwrap (file_info));
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          glib::RefPtr<FileInfo>>::value,
      "Type glib::RefPtr<FileInfo> cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ZlibCompressor::property_file_info () -> glib::PropertyProxy<glib::RefPtr<FileInfo>>
  {
    return {this, "file-info"};
  }

  auto
  ZlibCompressor::property_file_info () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<FileInfo>>
  {
    return {this, "file-info"};
  }

  static_assert (
      glib::Traits::ValueCompatibleWithWrapProperty<
          ZlibCompressorFormat>::value,
      "Type ZlibCompressorFormat cannot be used in _WRAP_PROPERTY. "
      "There is no suitable template specialization of glib::Value<>.");

  auto
  ZlibCompressor::property_format () const -> glib::PropertyProxy_ReadOnly<ZlibCompressorFormat>
  {
    return {this, "format"};
  }

  auto
  ZlibCompressor::property_level () const -> glib::PropertyProxy_ReadOnly<int>
  {
    return {this, "level"};
  }

} // namespace gio
