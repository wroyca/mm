// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONVERTEROUTPUTSTREAM_H
#define _GIOMM_CONVERTEROUTPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/filteroutputstream.hxx>
#include <libmm/gio/pollableoutputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverterOutputStream = struct _GConverterOutputStream;
using GConverterOutputStreamClass = struct _GConverterOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ConverterOutputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Converter;
  class LIBMM_GIO_SYMEXPORT OutputStream;

  class LIBMM_GIO_SYMEXPORT ConverterOutputStream : public FilterOutputStream,
                                          public PollableOutputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ConverterOutputStream;
    using CppClassType = ConverterOutputStream_Class;
    using BaseObjectType = GConverterOutputStream;
    using BaseClassType = GConverterOutputStreamClass;

    ConverterOutputStream (const ConverterOutputStream&) = delete;
    auto
    operator= (const ConverterOutputStream&) -> ConverterOutputStream& = delete;

  private:
    friend class ConverterOutputStream_Class;
    static CppClassType converteroutputstream_class_;

  protected:
    explicit ConverterOutputStream (
        const glib::ConstructParams& construct_params);
    explicit ConverterOutputStream (GConverterOutputStream* castitem);

#endif

  public:
    ConverterOutputStream (ConverterOutputStream&& src) noexcept;
    auto
    operator= (ConverterOutputStream&& src) noexcept -> ConverterOutputStream&;

    ~ConverterOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GConverterOutputStream*
    {
      return reinterpret_cast<GConverterOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GConverterOutputStream*
    {
      return reinterpret_cast<GConverterOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GConverterOutputStream*;

  private:
  protected:
    explicit ConverterOutputStream (
        const glib::RefPtr<OutputStream>& base_stream,
        const glib::RefPtr<Converter>& converter);

  public:
    static auto
    create (const glib::RefPtr<OutputStream>& base_stream,
            const glib::RefPtr<Converter>& converter)
        -> glib::RefPtr<ConverterOutputStream>;

    auto
    get_converter () -> glib::RefPtr<Converter>;

    auto
    get_converter () const -> glib::RefPtr<const Converter>;

    auto
    property_converter () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Converter>>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GConverterOutputStream* object, bool take_copy = false) -> glib::RefPtr<gio::ConverterOutputStream>;
} // namespace glib

#endif
