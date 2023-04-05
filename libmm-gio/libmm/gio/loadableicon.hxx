// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_LOADABLEICON_H
#define _GIOMM_LOADABLEICON_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/inputstream.hxx>
#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GLoadableIconIface GLoadableIconIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GLoadableIcon = struct _GLoadableIcon;
using GLoadableIconClass = struct _GLoadableIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT LoadableIcon_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT LoadableIcon : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = LoadableIcon;
    using CppClassType = LoadableIcon_Class;
    using BaseObjectType = GLoadableIcon;
    using BaseClassType = GLoadableIconIface;

    LoadableIcon (const LoadableIcon&) = delete;
    auto
    operator= (const LoadableIcon&) -> LoadableIcon& = delete;

  private:
    friend class LoadableIcon_Class;
    static CppClassType loadableicon_class_;

#endif
  protected:
    LoadableIcon ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit LoadableIcon (const glib::Interface_Class& interface_class);

  public:
    explicit LoadableIcon (GLoadableIcon* castitem);

  protected:
#endif

  public:
    LoadableIcon (LoadableIcon&& src) noexcept;
    auto
    operator= (LoadableIcon&& src) noexcept -> LoadableIcon&;

    ~LoadableIcon () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GLoadableIcon*
    {
      return reinterpret_cast<GLoadableIcon*> (gobject_);
    }

    auto
    gobj () const -> const GLoadableIcon*
    {
      return reinterpret_cast<GLoadableIcon*> (gobject_);
    }

  private:
  public:
    auto
    load (int size,
          glib::ustring& type,
          const glib::RefPtr<Cancellable>& cancellable)
        -> glib::RefPtr<InputStream>;

    auto
    load (int size, glib::ustring& type) -> glib::RefPtr<InputStream>;

    auto
    load_async (int size,
                const SlotAsyncReady& slot,
                const glib::RefPtr<Cancellable>& cancellable) -> void;

    auto
    load_async (int size, const SlotAsyncReady& slot) -> void;

  protected:
  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GLoadableIcon* object, bool take_copy = false) -> glib::RefPtr<gio::LoadableIcon>;

} // namespace glib

#endif
