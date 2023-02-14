
#ifndef _GIOMM_CONVERTERINPUTSTREAM_H
#define _GIOMM_CONVERTERINPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/filterinputstream.hxx>
#include <libmm-gio/pollableinputstream.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GConverterInputStream = struct _GConverterInputStream;
using GConverterInputStreamClass = struct _GConverterInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API ConverterInputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Converter;
  class GIOMM_API InputStream;

  class GIOMM_API ConverterInputStream : public FilterInputStream,
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
        const Glib::ConstructParams& construct_params);
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
    explicit ConverterInputStream (const Glib::RefPtr<InputStream>& base_stream,
                                   const Glib::RefPtr<Converter>& converter);

  public:
    static auto
    create (const Glib::RefPtr<InputStream>& base_stream,
            const Glib::RefPtr<Converter>& converter)
        -> Glib::RefPtr<ConverterInputStream>;

    auto
    get_converter () -> Glib::RefPtr<Converter>;

    auto
    get_converter () const -> Glib::RefPtr<const Converter>;

    auto
    property_converter () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Converter>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GConverterInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::ConverterInputStream>;
} // namespace Glib

#endif
