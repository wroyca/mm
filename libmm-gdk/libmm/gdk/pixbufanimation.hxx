// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFANIMATION_H
#define _GDKMM_PIXBUFANIMATION_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libmm/gdk/pixbuf.hxx>
#include <libmm/gdk/pixbufanimationiter.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufAnimation = struct _GdkPixbufAnimation;
using GdkPixbufAnimationClass = struct _GdkPixbufAnimationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT PixbufAnimation_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufAnimation : public glib::Object
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
    explicit PixbufAnimation (const glib::ConstructParams& construct_params);
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
        -> glib::RefPtr<PixbufAnimation>;

    static auto
    create_from_stream (const glib::RefPtr<gio::InputStream>& stream,
                        const glib::RefPtr<gio::Cancellable>& cancellable = {})
        -> glib::RefPtr<PixbufAnimation>;

    static auto
    create_from_stream_async (
        const glib::RefPtr<gio::InputStream>& stream,
        const gio::SlotAsyncReady& slot,
        const glib::RefPtr<gio::Cancellable>& cancellable = {}) -> void;

    static auto
    create_from_stream_finish (const glib::RefPtr<gio::AsyncResult>& result)
        -> glib::RefPtr<PixbufAnimation>;

    static auto
    create_from_resource (const std::string& resource_path)
        -> glib::RefPtr<PixbufAnimation>;

    auto
    get_width () const -> int;

    auto
    get_height () const -> int;

    auto
    is_static_image () const -> bool;

    auto
    get_static_image () -> glib::RefPtr<Pixbuf>;

    auto
    get_iter (gint64 start_time = g_get_real_time ())
        -> glib::RefPtr<PixbufAnimationIter>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPixbufAnimation* object, bool take_copy = false) -> glib::RefPtr<gdk::PixbufAnimation>;
} // namespace glib

#endif
