
#ifndef _GIOMM_MEMORYOUTPUTSTREAM_H
#define _GIOMM_MEMORYOUTPUTSTREAM_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gio/gio.h>
#include <libmm-gio/outputstream.hxx>
#include <libmm-gio/pollableoutputstream.hxx>
#include <libmm-gio/seekable.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMemoryOutputStream = struct _GMemoryOutputStream;
using GMemoryOutputStreamClass = struct _GMemoryOutputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API MemoryOutputStream_Class;
}
#endif

namespace Glib
{

  class GLIBMM_API Bytes;

}

namespace Gio
{

  class GIOMM_API MemoryOutputStream : public OutputStream,
                                       public Seekable,
                                       public PollableOutputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MemoryOutputStream;
    using CppClassType = MemoryOutputStream_Class;
    using BaseObjectType = GMemoryOutputStream;
    using BaseClassType = GMemoryOutputStreamClass;

    MemoryOutputStream (const MemoryOutputStream&) = delete;
    auto
    operator= (const MemoryOutputStream&) -> MemoryOutputStream& = delete;

  private:
    friend class MemoryOutputStream_Class;
    static CppClassType memoryoutputstream_class_;

  protected:
    explicit MemoryOutputStream (const Glib::ConstructParams& construct_params);
    explicit MemoryOutputStream (GMemoryOutputStream* castitem);

#endif

  public:
    MemoryOutputStream (MemoryOutputStream&& src) noexcept;
    auto
    operator= (MemoryOutputStream&& src) noexcept -> MemoryOutputStream&;

    ~MemoryOutputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMemoryOutputStream*
    {
      return reinterpret_cast<GMemoryOutputStream*> (gobject_);
    }

    auto
    gobj () const -> const GMemoryOutputStream*
    {
      return reinterpret_cast<GMemoryOutputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GMemoryOutputStream*;

  private:
  protected:
    MemoryOutputStream ();

    explicit MemoryOutputStream (void* data,
                                 gsize size,
                                 GReallocFunc realloc_function,
                                 GDestroyNotify destroy_function);

  public:
    static auto
    create () -> Glib::RefPtr<MemoryOutputStream>;

    static auto
    create (void* data,
            gsize size,
            GReallocFunc realloc_function,
            GDestroyNotify destroy_function)
        -> Glib::RefPtr<MemoryOutputStream>;

    auto
    get_data () -> void*;

    auto
    get_data () const -> const void*;

    auto
    steal_data () -> void*;

    auto
    get_size () const -> gsize;

    auto
    get_data_size () const -> gsize;

    auto
    steal_as_bytes () -> Glib::RefPtr<Glib::Bytes>;

    auto
    property_data () const -> Glib::PropertyProxy_ReadOnly<void*>;

    auto
    property_data_size () const -> Glib::PropertyProxy_ReadOnly<gulong>;

    auto
    property_size () const -> Glib::PropertyProxy_ReadOnly<gulong>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GMemoryOutputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::MemoryOutputStream>;
} // namespace Glib

#endif
