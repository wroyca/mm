// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONVERTER_H
#define _GIOMM_CONVERTER_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GConverterIface GConverterIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverter = struct _GConverter;
using GConverterClass = struct _GConverterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT Converter_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT Converter : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Converter;
    using CppClassType = Converter_Class;
    using BaseObjectType = GConverter;
    using BaseClassType = GConverterIface;

    Converter (const Converter&) = delete;
    auto
    operator= (const Converter&) -> Converter& = delete;

  private:
    friend class Converter_Class;
    static CppClassType converter_class_;

#endif
  protected:
    Converter ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Converter (const Glib::Interface_Class& interface_class);

  public:
    explicit Converter (GConverter* castitem);

  protected:
#endif

  public:
    Converter (Converter&& src) noexcept;
    auto
    operator= (Converter&& src) noexcept -> Converter&;

    ~Converter () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GConverter*
    {
      return reinterpret_cast<GConverter*> (gobject_);
    }

    auto
    gobj () const -> const GConverter*
    {
      return reinterpret_cast<GConverter*> (gobject_);
    }

  private:
  public:
    enum class Result
    {
      ERROR,
      CONVERTED,
      FINISHED,
      FLUSHED
    };

    enum class Flags
    {
      NO_FLAGS = 0x0,
      INPUT_AT_END = (1 << 0),
      FLUSH = (1 << 1)
    };

    auto
    convert (const void* inbuf,
             gsize inbuf_size,
             void* outbuf,
             gsize outbuf_size,
             Flags flags,
             gsize& bytes_read,
             gsize& bytes_written) -> Result;

    auto
    reset () -> void;

  protected:
    virtual auto
    convert_vfunc (const void* inbuf,
                   gsize inbuf_size,
                   void* outbuf,
                   gsize outbuf_size,
                   Flags flags,
                   gsize& bytes_read,
                   gsize& bytes_written) -> Result;

    virtual auto
    reset_vfunc () -> void;

  public:
  public:
  protected:
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Converter::Result>
    : public Glib::Value_Enum<Gio::Converter::Result>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  inline auto
  operator| (Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  {
    return static_cast<Converter::Flags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  {
    return static_cast<Converter::Flags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (Converter::Flags lhs, Converter::Flags rhs) -> Converter::Flags
  {
    return static_cast<Converter::Flags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(Converter::Flags flags) -> Converter::Flags
  {
    return static_cast<Converter::Flags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  {
    return (lhs = static_cast<Converter::Flags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  {
    return (lhs = static_cast<Converter::Flags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (Converter::Flags& lhs, Converter::Flags rhs) -> Converter::Flags&
  {
    return (lhs = static_cast<Converter::Flags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }
} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::Converter::Flags>
    : public Glib::Value_Flags<Gio::Converter::Flags>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GConverter* object, bool take_copy = false) -> Glib::RefPtr<Gio::Converter>;

} // namespace Glib

#endif
