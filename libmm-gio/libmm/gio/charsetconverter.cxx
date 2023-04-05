// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gio/charsetconverter.hxx>
#include <libmm/gio/charsetconverter_p.hxx>

#include <gio/gio.h>

namespace gio
{

  CharsetConverter::CharsetConverter (const glib::ustring& to_charset,
                                      const glib::ustring& from_charset)
    : ObjectBase (nullptr),
      Object (glib::ConstructParams (charsetconverter_class_.init (),
                                     "to-charset",
                                     to_charset.c_str (),
                                     "from-charset",
                                     from_charset.c_str (),
                                     nullptr))
  {
    init ();
  }

} // namespace gio

namespace
{
}

namespace glib
{

  auto
  wrap (GCharsetConverter* object, const bool take_copy) -> RefPtr<gio::CharsetConverter>
  {
    return glib::make_refptr_for_instance<gio::CharsetConverter> (
        dynamic_cast<gio::CharsetConverter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace glib

namespace gio
{

  auto
  CharsetConverter_Class::init () -> const Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &CharsetConverter_Class::class_init_function;

      register_derived_type (g_charset_converter_get_type ());

      Converter::add_interface (get_type ());
      Initable::add_interface (get_type ());
    }

    return *this;
  }

  auto
  CharsetConverter_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  CharsetConverter_Class::wrap_new (GObject* object) -> glib::ObjectBase*
  {
    return new CharsetConverter ((GCharsetConverter*) object);
  }

  auto
  CharsetConverter::gobj_copy () -> GCharsetConverter*
  {
    reference ();
    return gobj ();
  }

  CharsetConverter::CharsetConverter (
      const glib::ConstructParams& construct_params)
    : Object (construct_params)
  {
  }

  CharsetConverter::CharsetConverter (GCharsetConverter* castitem)
    : Object ((GObject*) castitem)
  {
  }

  CharsetConverter::CharsetConverter (CharsetConverter&& src) noexcept
    : Object (std::move (src)),
      Converter (std::move (src)),
      Initable (std::move (src))
  {
  }

  auto
  CharsetConverter::operator= (CharsetConverter&& src) noexcept -> CharsetConverter&
  {
    Object::operator= (std::move (src));
    Converter::operator= (std::move (src));
    Initable::operator= (std::move (src));
    return *this;
  }

  CharsetConverter::~CharsetConverter () noexcept = default;

  CharsetConverter::CppClassType CharsetConverter::charsetconverter_class_;

  auto
  CharsetConverter::get_type () -> GType
  {
    return charsetconverter_class_.init ().get_type ();
  }

  auto
  CharsetConverter::get_base_type () -> GType
  {
    return g_charset_converter_get_type ();
  }

  auto
  CharsetConverter::create (const glib::ustring& to_charset,
                            const glib::ustring& from_charset) -> glib::RefPtr<CharsetConverter>
  {
    return glib::make_refptr_for_instance<CharsetConverter> (
        new CharsetConverter (to_charset, from_charset));
  }

  auto
  CharsetConverter::set_use_fallback (const bool use_fallback) -> void
  {
    g_charset_converter_set_use_fallback (gobj (), use_fallback);
  }

  auto
  CharsetConverter::get_use_fallback () const -> bool
  {
    return g_charset_converter_get_use_fallback (
        const_cast<GCharsetConverter*> (gobj ()));
  }

  auto
  CharsetConverter::get_num_fallbacks () const -> guint
  {
    return g_charset_converter_get_num_fallbacks (
        const_cast<GCharsetConverter*> (gobj ()));
  }

  auto
  CharsetConverter::property_from_charset () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "from-charset"};
  }

  auto
  CharsetConverter::property_to_charset () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "to-charset"};
  }

  auto
  CharsetConverter::property_use_fallback () -> glib::PropertyProxy<bool>
  {
    return {this, "use-fallback"};
  }

  auto
  CharsetConverter::property_use_fallback () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-fallback"};
  }

} // namespace gio
