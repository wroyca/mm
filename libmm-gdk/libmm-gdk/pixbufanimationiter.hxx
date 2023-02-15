// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFANIMATIONITER_H
#define _GDKMM_PIXBUFANIMATIONITER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufAnimationIter = struct _GdkPixbufAnimationIter;
using GdkPixbufAnimationIterClass = struct _GdkPixbufAnimationIterClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class GDKMM_API PixbufAnimationIter_Class;
}
#endif

namespace Gdk
{

  class GDKMM_API PixbufAnimationIter : public Glib::Object
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
        const Glib::ConstructParams& construct_params);
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
    get_pixbuf () -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    get_pixbuf () const -> Glib::RefPtr<const Gdk::Pixbuf>;

    auto
    on_currently_loading_frame () const -> bool;

    auto
    advance (gint64 current_time = g_get_real_time ()) -> bool;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  GDKMM_API auto
  wrap (GdkPixbufAnimationIter* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PixbufAnimationIter>;
} // namespace Glib

#endif
