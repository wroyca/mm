
#ifndef _GIOMM_FILTERINPUTSTREAM_H
#define _GIOMM_FILTERINPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/inputstream.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFilterInputStream = struct _GFilterInputStream;
using GFilterInputStreamClass = struct _GFilterInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FilterInputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API FilterInputStream : public Gio::InputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FilterInputStream;
    using CppClassType = FilterInputStream_Class;
    using BaseObjectType = GFilterInputStream;
    using BaseClassType = GFilterInputStreamClass;

    FilterInputStream (const FilterInputStream&) = delete;
    auto
    operator= (const FilterInputStream&) -> FilterInputStream& = delete;

  private:
    friend class FilterInputStream_Class;
    static CppClassType filterinputstream_class_;

  protected:
    explicit FilterInputStream (const Glib::ConstructParams& construct_params);
    explicit FilterInputStream (GFilterInputStream* castitem);

#endif

  public:
    FilterInputStream (FilterInputStream&& src) noexcept;
    auto
    operator= (FilterInputStream&& src) noexcept -> FilterInputStream&;

    ~FilterInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFilterInputStream*
    {
      return reinterpret_cast<GFilterInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GFilterInputStream*
    {
      return reinterpret_cast<GFilterInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GFilterInputStream*;

  private:
  protected:
    explicit FilterInputStream (const Glib::RefPtr<InputStream>& base_stream);

  public:
    auto
    get_base_stream () -> Glib::RefPtr<InputStream>;

    auto
    get_base_stream () const -> Glib::RefPtr<const InputStream>;

    auto
    get_close_base_stream () const -> bool;

    void
    set_close_base_stream (bool close_base = true);

    auto
    property_base_stream () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<InputStream>>;

    auto
    property_close_base_stream () -> Glib::PropertyProxy<bool>;

    auto
    property_close_base_stream () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFilterInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::FilterInputStream>;
} // namespace Glib

#endif
