// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_PIXBUFLOADER_H
#define _GDKMM_PIXBUFLOADER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/pixbuf.hxx>
#include <libmm-gdk/pixbufanimation.hxx>
#include <libmm-gdk/pixbufformat.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkPixbufLoader = struct _GdkPixbufLoader;
using GdkPixbufLoaderClass = struct _GdkPixbufLoaderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT PixbufLoader_Class;
}
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT PixbufLoader : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = PixbufLoader;
    using CppClassType = PixbufLoader_Class;
    using BaseObjectType = GdkPixbufLoader;
    using BaseClassType = GdkPixbufLoaderClass;

    PixbufLoader (const PixbufLoader&) = delete;
    auto
    operator= (const PixbufLoader&) -> PixbufLoader& = delete;

  private:
    friend class PixbufLoader_Class;
    static CppClassType pixbufloader_class_;

  protected:
    explicit PixbufLoader (const Glib::ConstructParams& construct_params);
    explicit PixbufLoader (GdkPixbufLoader* castitem);

#endif

  public:
    PixbufLoader (PixbufLoader&& src) noexcept;
    auto
    operator= (PixbufLoader&& src) noexcept -> PixbufLoader&;

    ~PixbufLoader () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkPixbufLoader*
    {
      return reinterpret_cast<GdkPixbufLoader*> (gobject_);
    }

    auto
    gobj () const -> const GdkPixbufLoader*
    {
      return reinterpret_cast<GdkPixbufLoader*> (gobject_);
    }

    auto
    gobj_copy () -> GdkPixbufLoader*;

  private:
  protected:
    PixbufLoader ();

    explicit PixbufLoader (const Glib::ustring& image_type,
                           bool mime_type = false);

  public:
    static auto
    create () -> Glib::RefPtr<PixbufLoader>;

    static auto
    create (const Glib::ustring& image_type, bool mime_type = false)
        -> Glib::RefPtr<PixbufLoader>;

    auto
    set_size (int width, int height) -> void;

    auto
    write (const guint8* buf, gsize count) -> void;

    auto
    close () -> void;

    auto
    get_pixbuf () -> Glib::RefPtr<Gdk::Pixbuf>;

    auto
    get_animation () -> Glib::RefPtr<Gdk::PixbufAnimation>;

    auto
    get_format () const -> PixbufFormat;

    auto
    signal_area_prepared () -> Glib::SignalProxy<void ()>;

    auto
    signal_area_updated () -> Glib::SignalProxy<void (int, int, int, int)>;

    auto
    signal_closed () -> Glib::SignalProxy<void ()>;

    auto
    signal_size_prepared () -> Glib::SignalProxy<void (int, int)>;

  public:
  public:
  protected:
    virtual auto
    on_area_prepared () -> void;

    virtual auto
    on_area_updated (int x, int y, int width, int height) -> void;

    virtual auto
    on_closed () -> void;

    virtual auto
    on_size_prepared (int width, int height) -> void;
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkPixbufLoader* object, bool take_copy = false) -> Glib::RefPtr<Gdk::PixbufLoader>;
} // namespace Glib

#endif
