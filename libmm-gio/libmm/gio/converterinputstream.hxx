// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_CONVERTERINPUTSTREAM_H
#define _GIOMM_CONVERTERINPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/filterinputstream.hxx>
#include <libmm/gio/pollableinputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverterInputStream = struct _GConverterInputStream;
using GConverterInputStreamClass = struct _GConverterInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT ConverterInputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT Converter;
  class LIBMM_GIO_SYMEXPORT InputStream;

  class LIBMM_GIO_SYMEXPORT ConverterInputStream : public FilterInputStream,
                                         public PollableInputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ConverterInputStream;
    using CppClassType = ConverterInputStream_Class;
    using BaseObjectType = GConverterInputStream;
    using BaseClassType = GConverterInputStreamClass;

    ConverterInputStream (const ConverterInputStream&) = delete;
    auto
    operator= (const ConverterInputStream&) -> ConverterInputStream& = delete;

  private:
    friend class ConverterInputStream_Class;
    static CppClassType converterinputstream_class_;

  protected:
    explicit ConverterInputStream (
        const glib::ConstructParams& construct_params);
    explicit ConverterInputStream (GConverterInputStream* castitem);

#endif

  public:
    ConverterInputStream (ConverterInputStream&& src) noexcept;
    auto
    operator= (ConverterInputStream&& src) noexcept -> ConverterInputStream&;

    ~ConverterInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GConverterInputStream*
    {
      return reinterpret_cast<GConverterInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GConverterInputStream*
    {
      return reinterpret_cast<GConverterInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GConverterInputStream*;

  private:
  protected:
    explicit ConverterInputStream (const glib::RefPtr<InputStream>& base_stream,
                                   const glib::RefPtr<Converter>& converter);

  public:
    static auto
    create (const glib::RefPtr<InputStream>& base_stream,
            const glib::RefPtr<Converter>& converter)
        -> glib::RefPtr<ConverterInputStream>;

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
  wrap (GConverterInputStream* object, bool take_copy = false) -> glib::RefPtr<gio::ConverterInputStream>;
} // namespace glib

#endif
