// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CHARSETCONVERTER_H
#define _GIOMM_CHARSETCONVERTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/converter.hxx>
#include <libmm-gio/initable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GCharsetConverter = struct _GCharsetConverter;
using GCharsetConverterClass = struct _GCharsetConverterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT CharsetConverter_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT CharsetConverter : public Glib::Object,
                                     public Converter,
                                     public Initable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = CharsetConverter;
    using CppClassType = CharsetConverter_Class;
    using BaseObjectType = GCharsetConverter;
    using BaseClassType = GCharsetConverterClass;

    CharsetConverter (const CharsetConverter&) = delete;
    auto
    operator= (const CharsetConverter&) -> CharsetConverter& = delete;

  private:
    friend class CharsetConverter_Class;
    static CppClassType charsetconverter_class_;

  protected:
    explicit CharsetConverter (const Glib::ConstructParams& construct_params);
    explicit CharsetConverter (GCharsetConverter* castitem);

#endif

  public:
    CharsetConverter (CharsetConverter&& src) noexcept;
    auto
    operator= (CharsetConverter&& src) noexcept -> CharsetConverter&;

    ~CharsetConverter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GCharsetConverter*
    {
      return reinterpret_cast<GCharsetConverter*> (gobject_);
    }

    auto
    gobj () const -> const GCharsetConverter*
    {
      return reinterpret_cast<GCharsetConverter*> (gobject_);
    }

    auto
    gobj_copy () -> GCharsetConverter*;

  private:
  protected:
    explicit CharsetConverter (const Glib::ustring& to_charset,
                               const Glib::ustring& from_charset);

  public:
    static auto
    create (const Glib::ustring& to_charset, const Glib::ustring& from_charset)
        -> Glib::RefPtr<CharsetConverter>;

    auto
    set_use_fallback (bool use_fallback) -> void;

    auto
    get_use_fallback () const -> bool;

    auto
    get_num_fallbacks () const -> guint;

    auto
    property_from_charset () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_to_charset () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_fallback () -> Glib::PropertyProxy<bool>;

    auto
    property_use_fallback () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GCharsetConverter* object, bool take_copy = false) -> Glib::RefPtr<Gio::CharsetConverter>;
} // namespace Glib

#endif
