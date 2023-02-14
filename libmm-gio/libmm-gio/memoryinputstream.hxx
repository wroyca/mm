
#ifndef _GIOMM_MEMORYINPUTSTREAM_H
#define _GIOMM_MEMORYINPUTSTREAM_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/inputstream.hxx>
#include <libmm-gio/pollableinputstream.hxx>
#include <libmm-gio/seekable.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMemoryInputStream = struct _GMemoryInputStream;
using GMemoryInputStreamClass = struct _GMemoryInputStreamClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API MemoryInputStream_Class;
}
#endif

namespace Gio
{

  class GIOMM_API MemoryInputStream : public Gio::InputStream,
                                      public Seekable,
                                      public PollableInputStream
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MemoryInputStream;
    using CppClassType = MemoryInputStream_Class;
    using BaseObjectType = GMemoryInputStream;
    using BaseClassType = GMemoryInputStreamClass;

    MemoryInputStream (const MemoryInputStream&) = delete;
    auto
    operator= (const MemoryInputStream&) -> MemoryInputStream& = delete;

  private:
    friend class MemoryInputStream_Class;
    static CppClassType memoryinputstream_class_;

  protected:
    explicit MemoryInputStream (const Glib::ConstructParams& construct_params);
    explicit MemoryInputStream (GMemoryInputStream* castitem);

#endif

  public:
    MemoryInputStream (MemoryInputStream&& src) noexcept;
    auto
    operator= (MemoryInputStream&& src) noexcept -> MemoryInputStream&;

    ~MemoryInputStream () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMemoryInputStream*
    {
      return reinterpret_cast<GMemoryInputStream*> (gobject_);
    }

    auto
    gobj () const -> const GMemoryInputStream*
    {
      return reinterpret_cast<GMemoryInputStream*> (gobject_);
    }

    auto
    gobj_copy () -> GMemoryInputStream*;

  private:
  protected:
    MemoryInputStream ();

  public:
    static auto
    create () -> Glib::RefPtr<MemoryInputStream>;

    void
    add_data (const void* data, gssize len, GDestroyNotify destroy);

    using SlotDestroyData = sigc::slot<void (void*)>;

    void
    add_data (const void* data,
              gssize len,
              const SlotDestroyData& destroy_slot);

    void
    add_bytes (const Glib::RefPtr<const Glib::Bytes>& bytes);

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GMemoryInputStream* object, bool take_copy = false) -> Glib::RefPtr<Gio::MemoryInputStream>;
} // namespace Glib

#endif
