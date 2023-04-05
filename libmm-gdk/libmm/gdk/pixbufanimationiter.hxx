// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFANIMATIONITER_H
#define _GDKMM_PIXBUFANIMATIONITER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include <libmm/gdk/pixbuf.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufAnimationIter = struct _GdkPixbufAnimationIter;
using GdkPixbufAnimationIterClass = struct _GdkPixbufAnimationIterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT PixbufAnimationIter_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufAnimationIter : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PixbufAnimationIter;
    using CppClassType = PixbufAnimationIter_Class;
    using BaseObjectType = GdkPixbufAnimationIter;
    using BaseClassType = GdkPixbufAnimationIterClass;

    PixbufAnimationIter (const PixbufAnimationIter&) = delete;
    auto
    operator= (const PixbufAnimationIter&) -> PixbufAnimationIter& = delete;

  private:
    friend class PixbufAnimationIter_Class;
    static CppClassType pixbufanimationiter_class_;

  protected:
    explicit PixbufAnimationIter (
        const glib::ConstructParams& construct_params);
    explicit PixbufAnimationIter (GdkPixbufAnimationIter* castitem);

#endif

  public:
    PixbufAnimationIter (PixbufAnimationIter&& src) noexcept;
    auto
    operator= (PixbufAnimationIter&& src) noexcept -> PixbufAnimationIter&;

    ~PixbufAnimationIter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPixbufAnimationIter*
    {
      return reinterpret_cast<GdkPixbufAnimationIter*> (gobject_);
    }

    auto
    gobj () const -> const GdkPixbufAnimationIter*
    {
      return reinterpret_cast<GdkPixbufAnimationIter*> (gobject_);
    }

    auto
    gobj_copy () -> GdkPixbufAnimationIter*;

  private:
  protected:
  public:
    auto
    get_delay_time () const -> int;

    auto
    get_pixbuf () -> glib::RefPtr<gdk::Pixbuf>;

    auto
    get_pixbuf () const -> glib::RefPtr<const gdk::Pixbuf>;

    auto
    on_currently_loading_frame () const -> bool;

    auto
    advance (gint64 current_time = g_get_real_time ()) -> bool;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPixbufAnimationIter* object, bool take_copy = false) -> glib::RefPtr<gdk::PixbufAnimationIter>;
} // namespace glib

#endif
