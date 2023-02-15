// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm-glib/mm-glib.hxx>

#include <libmm-gio/charsetconverter.hxx>
#include <libmm-gio/charsetconverter_p.hxx>

#include <gio/gio.h>

namespace Gio
{

  CharsetConverter::CharsetConverter (const Glib::ustring& to_charset,
                                      const Glib::ustring& from_charset)
    : ObjectBase (nullptr),
      Object (Glib::ConstructParams (charsetconverter_class_.init (),
                                     "to-charset",
                                     to_charset.c_str (),
                                     "from-charset",
                                     from_charset.c_str (),
                                     nullptr))
  {
    init ();
  }

} // namespace Gio

namespace
{
}

namespace Glib
{

  auto
  wrap (GCharsetConverter* object, const bool take_copy) -> RefPtr<Gio::CharsetConverter>
  {
    return Glib::make_refptr_for_instance<Gio::CharsetConverter> (
        dynamic_cast<Gio::CharsetConverter*> (
            wrap_auto ((GObject*) object, take_copy)));
  }

} // namespace Glib

namespace Gio
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
  CharsetConverter_Class::wrap_new (GObject* object) -> Glib::ObjectBase*
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
      const Glib::ConstructParams& construct_params)
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
  CharsetConverter::create (const Glib::ustring& to_charset,
                            const Glib::ustring& from_charset) -> Glib::RefPtr<CharsetConverter>
  {
    return Glib::make_refptr_for_instance<CharsetConverter> (
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
  CharsetConverter::property_from_charset () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "from-charset"};
  }

  auto
  CharsetConverter::property_to_charset () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return {this, "to-charset"};
  }

  auto
  CharsetConverter::property_use_fallback () -> Glib::PropertyProxy<bool>
  {
    return {this, "use-fallback"};
  }

  auto
  CharsetConverter::property_use_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "use-fallback"};
  }

} // namespace Gio
