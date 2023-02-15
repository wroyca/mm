// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_DROP_H
#define _GDKMM_DROP_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gdk/enums.hxx>
#include <libmm-gio/asyncresult.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkDrop = struct _GdkDrop;
using GdkDropClass = struct _GdkDropClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Drop_Class;
}
#endif

namespace Gio
{
  class LIBMM_GDK_SYMEXPORT Cancellable;
  class LIBMM_GDK_SYMEXPORT InputStream;
} // namespace Gio

namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT ContentFormats;
  class LIBMM_GDK_SYMEXPORT Device;
  class LIBMM_GDK_SYMEXPORT Drag;
  class LIBMM_GDK_SYMEXPORT Display;
  class LIBMM_GDK_SYMEXPORT Surface;

  class LIBMM_GDK_SYMEXPORT Drop : public Glib::Object
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
    explicit Drop (const Glib::ConstructParams& construct_params);
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
    get_display () -> Glib::RefPtr<Display>;

    auto
    get_display () const -> Glib::RefPtr<const Display>;

    auto
    get_device () -> Glib::RefPtr<Device>;

    auto
    get_device () const -> Glib::RefPtr<const Device>;

    auto
    get_surface () -> Glib::RefPtr<Surface>;

    auto
    get_surface () const -> Glib::RefPtr<const Surface>;

    auto
    get_formats () -> Glib::RefPtr<ContentFormats>;

    auto
    get_formats () const -> Glib::RefPtr<const ContentFormats>;

    auto
    get_actions () const -> DragAction;

    auto
    get_drag () -> Glib::RefPtr<Drag>;

    auto
    get_drag () const -> Glib::RefPtr<const Drag>;

    auto
    status (DragAction actions, DragAction preferred) -> void;

    auto
    refuse () -> void;

    auto
    finish (DragAction action) -> void;

    auto
    failed () -> void;

    auto
    read_async (const std::vector<Glib::ustring>& mime_types,
                int io_priority,
                const Gio::SlotAsyncReady& slot,
                const Glib::RefPtr<Gio::Cancellable>& cancellable) -> void;

    auto
    read_async (const std::vector<Glib::ustring>& mime_types,
                int io_priority,
                const Gio::SlotAsyncReady& slot) -> void;

    auto
    read_finish (const Glib::RefPtr<Gio::AsyncResult>& result,
                 Glib::ustring& out_mime_type)
        -> Glib::RefPtr<Gio::InputStream>;

    auto
    read_value_async (GType type,
                      int io_priority,
                      const Gio::SlotAsyncReady& slot,
                      const Glib::RefPtr<Gio::Cancellable>& cancellable)
        -> void;

    auto
    read_value_async (GType type,
                      int io_priority,
                      const Gio::SlotAsyncReady& slot) -> void;

    auto
    read_value_finish (const Glib::RefPtr<Gio::AsyncResult>& result)
        -> Glib::ValueBase;

    auto
    property_actions () const -> Glib::PropertyProxy_ReadOnly<DragAction>;

    auto
    property_device () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Device>>;

    auto
    property_display () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Display>>;

    auto
    property_drag () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Drag>>;

    auto
    property_formats () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<ContentFormats>>;

    auto
    property_surface () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Surface>>;

  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkDrop* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Drop>;
} // namespace Glib

#endif
