
#ifndef _GIOMM_SEEKABLE_H
#define _GIOMM_SEEKABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/cancellable.hxx>
#include <libmm-glib/interface.hxx>
#include <libmm-glib/iochannel.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GSeekableIface GSeekableIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSeekable = struct _GSeekable;
using GSeekableClass = struct _GSeekableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API Seekable_Class;
}
#endif

namespace Gio
{

  class GIOMM_API Seekable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Seekable;
    using CppClassType = Seekable_Class;
    using BaseObjectType = GSeekable;
    using BaseClassType = GSeekableIface;

    Seekable (const Seekable&) = delete;
    auto
    operator= (const Seekable&) -> Seekable& = delete;

  private:
    friend class Seekable_Class;
    static CppClassType seekable_class_;

#endif
  protected:
    Seekable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Seekable (const Glib::Interface_Class& interface_class);

  public:
    explicit Seekable (GSeekable* castitem);

  protected:
#endif

  public:
    Seekable (Seekable&& src) noexcept;
    auto
    operator= (Seekable&& src) noexcept -> Seekable&;

    ~Seekable () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSeekable*
    {
      return reinterpret_cast<GSeekable*> (gobject_);
    }

    auto
    gobj () const -> const GSeekable*
    {
      return reinterpret_cast<GSeekable*> (gobject_);
    }

  private:
  public:
    auto
    tell () const -> goffset;

    auto
    can_seek () const -> bool;

    auto
    seek (goffset offset,
          Glib::SeekType type,
          const Glib::RefPtr<Cancellable>& cancellable) -> bool;

    auto
    seek (goffset offset, Glib::SeekType type) -> bool;

    auto
    can_truncate () const -> bool;

    auto
    truncate (goffset offset, const Glib::RefPtr<Cancellable>& cancellable)
        -> bool;

    auto
    truncate (goffset offset) -> bool;

  protected:
  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSeekable* object, bool take_copy = false) -> Glib::RefPtr<Gio::Seekable>;

} // namespace Glib

#endif
