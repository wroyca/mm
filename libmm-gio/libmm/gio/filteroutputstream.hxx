// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILTEROUTPUTSTREAM_H
#define _GIOMM_FILTEROUTPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/outputstream.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFilterOutputStream = struct _GFilterOutputStream;
using GFilterOutputStreamClass = struct _GFilterOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT FilterOutputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT FilterOutputStream : public gio::OutputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FilterOutputStream;
    using CppClassType = FilterOutputStream_Class;
    using BaseObjectType = GFilterOutputStream;
    using BaseClassType = GFilterOutputStreamClass;

    FilterOutputStream (const FilterOutputStream&) = delete;
    auto
    operator= (const FilterOutputStream&) -> FilterOutputStream& = delete;

  private:
    friend class FilterOutputStream_Class;
    static CppClassType filteroutputstream_class_;

  protected:
    explicit FilterOutputStream (const glib::ConstructParams& construct_params);
    explicit FilterOutputStream (GFilterOutputStream* castitem);

#endif

  public:
    FilterOutputStream (FilterOutputStream&& src) noexcept;
    auto
    operator= (FilterOutputStream&& src) noexcept -> FilterOutputStream&;

    ~FilterOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFilterOutputStream*
    {
      return reinterpret_cast<GFilterOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GFilterOutputStream*
    {
      return reinterpret_cast<GFilterOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GFilterOutputStream*;

  private:
  protected:
    explicit FilterOutputStream (const glib::RefPtr<OutputStream>& base_stream);

  public:
    auto
    get_base_stream () -> glib::RefPtr<OutputStream>;

    auto
    get_base_stream () const -> glib::RefPtr<const OutputStream>;

    auto
    get_close_base_stream () const -> bool;

    auto
    set_close_base_stream (bool close_base = true) -> void;

    auto
    property_base_stream () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<OutputStream>>;

    auto
    property_close_base_stream () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFilterOutputStream* object, bool take_copy = false) -> glib::RefPtr<gio::FilterOutputStream>;
} // namespace glib

#endif
