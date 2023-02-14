
#ifndef _GDKMM_PIXBUFANIMATION_H
#define _GDKMM_PIXBUFANIMATION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/pixbufanimationiter.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufAnimation = struct _GdkPixbufAnimation;
using GdkPixbufAnimationClass = struct _GdkPixbufAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API PixbufAnimation_Class;
}
#endif

namespace Gdk
{

  class GDKMM_API PixbufAnimation : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PixbufAnimation;
    using CppClassType = PixbufAnimation_Class;
    using BaseObjectType = GdkPixbufAnimation;
    using BaseClassType = GdkPixbufAnimationClass;

    PixbufAnimation (const PixbufAnimation&) = delete;
    auto
    operator= (const PixbufAnimation&) -> PixbufAnimation& = delete;

  private:
    friend class PixbufAnimation_Class;
    static CppClassType pixbufanimation_class_;

  protected:
    explicit PixbufAnimation (const Glib::ConstructParams& construct_params);
    explicit PixbufAnimation (GdkPixbufAnimation* castitem);

#endif

  public:
    PixbufAnimation (PixbufAnimation&& src) noexcept;
    auto
    operator= (PixbufAnimation&& src) noexcept -> PixbufAnimation&;

    ~PixbufAnimation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPixbufAnimation*
    {
      return reinterpret_cast<GdkPixbufAnimation*> (gobject_);
    }

    auto
    gobj () const -> const GdkPixbufAnimation*
    {
      return reinterpret_cast<GdkPixbufAnimation*> (gobject_);
    }

    auto
    gobj_copy () -> GdkPixbufAnimation*;

  private:
  protected:
  public:
    static auto
    create_from_file (const std::string& filename)
        -> Glib::RefPtr<PixbufAnimation>;

    static auto
    create_from_stream (const Glib::RefPtr<Gio::InputStream>& stream,
                        const Glib::RefPtr<Gio::Cancellable>& cancellable = {})
        -> Glib::RefPtr<PixbufAnimation>;

    static void
    create_from_stream_async (
        const Glib::RefPtr<Gio::InputStream>& stream,
        const Gio::SlotAsyncReady& slot,
        const Glib::RefPtr<Gio::Cancellable>& cancellable = {});

    static auto
    create_from_stream_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
        -> Glib::RefPtr<PixbufAnimation>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> Glib::RefPtr<PixbufAnimation>;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    is_static_image () const -> bool;

    auto
    get_static_image () -> Glib::RefPtr<Pixbuf>;

    auto
    get_iter (gint64 start_time = g_get_real_time ())
        -> Glib::RefPtr<PixbufAnimationIter>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{

  GDKMM_API
  auto
  wrap (GdkPixbufAnimation* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PixbufAnimation>;
} // namespace Glib

#endif
