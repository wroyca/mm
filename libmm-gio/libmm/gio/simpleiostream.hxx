// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEIOSTREAM_H
#define _GIOMM_SIMPLEIOSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/iostream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimpleIOStream = struct _GSimpleIOStream;
using GSimpleIOStreamClass = struct _GSimpleIOStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SimpleIOStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SimpleIOStream : public gio::IOStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SimpleIOStream;
    using CppClassType = SimpleIOStream_Class;
    using BaseObjectType = GSimpleIOStream;
    using BaseClassType = GSimpleIOStreamClass;

    SimpleIOStream (const SimpleIOStream&) = delete;
    auto
    operator= (const SimpleIOStream&) -> SimpleIOStream& = delete;

  private:
    friend class SimpleIOStream_Class;
    static CppClassType simpleiostream_class_;

  protected:
    explicit SimpleIOStream (const glib::ConstructParams& construct_params);
    explicit SimpleIOStream (GSimpleIOStream* castitem);

#endif

  public:
    SimpleIOStream (SimpleIOStream&& src) noexcept;
    auto
    operator= (SimpleIOStream&& src) noexcept -> SimpleIOStream&;

    ~SimpleIOStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSimpleIOStream*
    {
      return reinterpret_cast<GSimpleIOStream*> (gobject_);
    }

    auto
    gobj () const -> const GSimpleIOStream*
    {
      return reinterpret_cast<GSimpleIOStream*> (gobject_);
    }

    auto
    gobj_copy () -> GSimpleIOStream*;

  private:
  protected:
    explicit SimpleIOStream (const glib::RefPtr<InputStream>& input_stream,
                             const glib::RefPtr<OutputStream>& output_stream);

  public:
    static auto
    create (const glib::RefPtr<InputStream>& input_stream,
            const glib::RefPtr<OutputStream>& output_stream)
        -> glib::RefPtr<SimpleIOStream>;

    auto
    property_input_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<InputStream>>;

    auto
    property_output_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<OutputStream>>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSimpleIOStream* object, bool take_copy = false) -> glib::RefPtr<gio::SimpleIOStream>;
} // namespace glib

#endif
