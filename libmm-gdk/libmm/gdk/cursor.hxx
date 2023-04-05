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
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Cursor_Class;
}
#endif

namespace gdk
{

  class LIBMM_GDK_SYMEXPORT Cursor : public glib::Object
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
    explicit Cursor (const glib::ConstructParams& construct_params);
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
    create (const glib::RefPtr<const Texture>& texture,
            int hotspot_x,
            int hotspot_y,
            const glib::RefPtr<Cursor>& fallback = {}) -> glib::RefPtr<Cursor>;

    static auto
    create (const glib::ustring& name,
            const glib::RefPtr<Cursor>& fallback = {}) -> glib::RefPtr<Cursor>;

    auto
    get_fallback () -> glib::RefPtr<Cursor>;

    auto
    get_fallback () const -> glib::RefPtr<const Cursor>;

    auto
    get_name () const -> glib::ustring;

    auto
    get_texture () -> glib::RefPtr<Texture>;

    auto
    get_texture () const -> glib::RefPtr<const Texture>;

    auto
    get_hotspot_x () const -> int;

    auto
    get_hotspot_y () const -> int;

    auto
    property_fallback () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Cursor>>;

    auto
    property_hotspot_x () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_hotspot_y () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_texture () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Texture>>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkCursor* object, bool take_copy = false) -> glib::RefPtr<gdk::Cursor>;
} // namespace glib

#endif
