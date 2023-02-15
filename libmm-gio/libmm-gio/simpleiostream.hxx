// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SIMPLEIOSTREAM_H
#define _GIOMM_SIMPLEIOSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/iostream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSimpleIOStream = struct _GSimpleIOStream;
using GSimpleIOStreamClass = struct _GSimpleIOStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API SimpleIOStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API SimpleIOStream : public Gio::IOStream
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
    explicit SimpleIOStream (const Glib::ConstructParams& construct_params);
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
    explicit SimpleIOStream (const Glib::RefPtr<InputStream>& input_stream,
                             const Glib::RefPtr<OutputStream>& output_stream);

  public:
    static auto
    create (const Glib::RefPtr<InputStream>& input_stream,
            const Glib::RefPtr<OutputStream>& output_stream)
        -> Glib::RefPtr<SimpleIOStream>;

    auto
    property_input_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<InputStream>>;

    auto
    property_output_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<OutputStream>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSimpleIOStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::SimpleIOStream>;
} // namespace Glib

#endif
