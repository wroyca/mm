// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DROP_H
#define _GDKMM_DROP_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/enums.hxx>
#include <libmm/gio/asyncresult.hxx>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrop = struct _GdkDrop;
using GdkDropClass = struct _GdkDropClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gdk
{
  class LIBMM_GDK_SYMEXPORT Drop_Class;
}
#endif

namespace gio
{
  class LIBMM_GDK_SYMEXPORT Cancellable;
  class LIBMM_GDK_SYMEXPORT InputStream;
} // namespace gio

namespace gdk
{
  class LIBMM_GDK_SYMEXPORT ContentFormats;
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT Drag;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Drop : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Drop;
    using CppClassType = Drop_Class;
    using BaseObjectType = GdkDrop;
    using BaseClassType = GdkDropClass;

    Drop (const Drop&) = delete;
    auto
    operator= (const Drop&) -> Drop& = delete;

  private:
    friend class Drop_Class;
    static CppClassType drop_class_;

  protected:
    explicit Drop (const glib::ConstructParams& construct_params);
    explicit Drop (GdkDrop* castitem);

#endif

  public:
    Drop (Drop&& src) noexcept;
    auto
    operator= (Drop&& src) noexcept -> Drop&;

    ~Drop () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkDrop*
    {
      return reinterpret_cast<GdkDrop*> (gobject_);
    }

    auto
    gobj () const -> const GdkDrop*
    {
      return reinterpret_cast<GdkDrop*> (gobject_);
    }

    auto
    gobj_copy () -> GdkDrop*;

  private:
  public:
    auto
    get_display () -> glib::RefPtr<Display>;

    auto
    get_display () const -> glib::RefPtr<const Display>;

    auto
    get_device () -> glib::RefPtr<Device>;

    auto
    get_device () const -> glib::RefPtr<const Device>;

    auto
    get_surface () -> glib::RefPtr<Surface>;

    auto
    get_surface () const -> glib::RefPtr<const Surface>;

    auto
    get_formats () -> glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> glib::RefPtr<const ContentFormats>;

    auto
    get_actions () const -> DragAction;

    auto
    get_drag () -> glib::RefPtr<Drag>;

    auto
    get_drag () const -> glib::RefPtr<const Drag>;

    auto
    status (DragAction actions, DragAction preferred) -> void;

    auto
    refuse () -> void;

    auto
    finish (DragAction action) -> void;

    auto
    failed () -> void;

    auto
    read_async (const std::vector<glib::ustring>& mime_types,
                int io_priority,
                const gio::SlotAsyncReady& slot,
                const glib::RefPtr<gio::Cancellable>& cancellable) -> void;

    auto
    read_async (const std::vector<glib::ustring>& mime_types,
                int io_priority,
                const gio::SlotAsyncReady& slot) -> void;

    auto
    read_finish (const glib::RefPtr<gio::AsyncResult>& result,
                 glib::ustring& out_mime_type)
        -> glib::RefPtr<gio::InputStream>;

    auto
    read_value_async (GType type,
                      int io_priority,
                      const gio::SlotAsyncReady& slot,
                      const glib::RefPtr<gio::Cancellable>& cancellable)
        -> void;

    auto
    read_value_async (GType type,
                      int io_priority,
                      const gio::SlotAsyncReady& slot) -> void;

    auto
    read_value_finish (const glib::RefPtr<gio::AsyncResult>& result)
        -> glib::ValueBase;

    auto
    property_actions () const -> glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_device () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Device>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Display>>;

    auto
    property_drag () const -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Drag>>;

    auto
    property_formats () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<ContentFormats>>;

    auto
    property_surface () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Surface>>;

  public:
  public:
  protected:
  };

} // namespace gdk

namespace glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDrop* object, bool take_copy = false) -> glib::RefPtr<gdk::Drop>;
} // namespace glib

#endif
