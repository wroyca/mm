// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_CURSOR_H
#define _GDKMM_CURSOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/texture.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkCursor = struct _GdkCursor;
using GdkCursorClass = struct _GdkCursorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Cursor_Class;
}
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT Cursor : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Cursor;
    using CppClassType = Cursor_Class;
    using BaseObjectType = GdkCursor;
    using BaseClassType = GdkCursorClass;

    Cursor (const Cursor&) = delete;
    auto
    operator= (const Cursor&) -> Cursor& = delete;

  private:
    friend class Cursor_Class;
    static CppClassType cursor_class_;

  protected:
    explicit Cursor (const Glib::ConstructParams& construct_params);
    explicit Cursor (GdkCursor* castitem);

#endif

  public:
    Cursor (Cursor&& src) noexcept;
    auto
    operator= (Cursor&& src) noexcept -> Cursor&;

    ~Cursor () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkCursor*
    {
      return reinterpret_cast<GdkCursor*> (gobject_);
    }

    auto
    gobj () const -> const GdkCursor*
    {
      return reinterpret_cast<GdkCursor*> (gobject_);
    }

    auto
    gobj_copy () -> GdkCursor*;

  private:
  protected:
  public:
    static auto
    create (const Glib::RefPtr<const Texture>& texture,
            int hotspot_x,
            int hotspot_y,
            const Glib::RefPtr<Cursor>& fallback = {}) -> Glib::RefPtr<Cursor>;

    static auto
    create (const Glib::ustring& name,
            const Glib::RefPtr<Cursor>& fallback = {}) -> Glib::RefPtr<Cursor>;

    auto
    get_fallback () -> Glib::RefPtr<Cursor>;

    auto
    get_fallback () const -> Glib::RefPtr<const Cursor>;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_texture () -> Glib::RefPtr<Texture>;

    auto
    get_texture () const -> Glib::RefPtr<const Texture>;

    auto
    get_hotspot_x () const -> int;

    auto
    get_hotspot_y () const -> int;

    auto
    property_fallback () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Cursor>>;

    auto
    property_hotspot_x () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_hotspot_y () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_texture () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Texture>>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkCursor* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Cursor>;
} // namespace Glib

#endif
