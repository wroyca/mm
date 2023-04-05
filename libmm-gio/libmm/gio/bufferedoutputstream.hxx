// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_BUFFEREDOUTPUTSTREAM_H
#define _GIOMM_BUFFEREDOUTPUTSTREAM_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/filteroutputstream.hxx>
#include <libmm/gio/seekable.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GBufferedOutputStream = struct _GBufferedOutputStream;
using GBufferedOutputStreamClass = struct _GBufferedOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT BufferedOutputStream_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT BufferedOutputStream : public gio::FilterOutputStream,
                                         public gio::Seekable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BufferedOutputStream;
    using CppClassType = BufferedOutputStream_Class;
    using BaseObjectType = GBufferedOutputStream;
    using BaseClassType = GBufferedOutputStreamClass;

    BufferedOutputStream (const BufferedOutputStream&) = delete;
    auto
    operator= (const BufferedOutputStream&) -> BufferedOutputStream& = delete;

  private:
    friend class BufferedOutputStream_Class;
    static CppClassType bufferedoutputstream_class_;

  protected:
    explicit BufferedOutputStream (
        const glib::ConstructParams& construct_params);
    explicit BufferedOutputStream (GBufferedOutputStream* castitem);

#endif

  public:
    BufferedOutputStream (BufferedOutputStream&& src) noexcept;
    auto
    operator= (BufferedOutputStream&& src) noexcept -> BufferedOutputStream&;

    ~BufferedOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GBufferedOutputStream*
    {
      return reinterpret_cast<GBufferedOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GBufferedOutputStream*
    {
      return reinterpret_cast<GBufferedOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GBufferedOutputStream*;

  private:
  protected:
    explicit BufferedOutputStream (
        const glib::RefPtr<OutputStream>& base_stream);

    explicit BufferedOutputStream (
        const glib::RefPtr<OutputStream>& base_stream,
        gsize buffer_size);

  public:
    static auto
    create (const glib::RefPtr<OutputStream>& base_stream)
        -> glib::RefPtr<BufferedOutputStream>;

    static auto
    create_sized (const glib::RefPtr<OutputStream>& base_stream,
                  gsize buffer_size) -> glib::RefPtr<BufferedOutputStream>;

    auto
    get_buffer_size () const -> gsize;

    auto
    set_buffer_size (gsize size) -> void;

    auto
    set_auto_grow (bool auto_grow = true) -> void;

    auto
    get_auto_grow () const -> bool;

    auto
    property_buffer_size () -> glib::PropertyProxy<guint>;

    auto
    property_buffer_size () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_auto_grow () -> glib::PropertyProxy<bool>;

    auto
    property_auto_grow () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GBufferedOutputStream* object, bool take_copy = false) -> glib::RefPtr<gio::BufferedOutputStream>;
} // namespace glib

#endif
