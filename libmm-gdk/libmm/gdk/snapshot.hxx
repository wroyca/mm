// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GDKMM_SNAPSHOT_H
#define _GDKMM_SNAPSHOT_H

#include <libmm/gdk/mm-gdkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkSnapshot = struct _GdkSnapshot;
using GdkSnapshotClass = struct _GdkSnapshotClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{
  class LIBMM_GDK_SYMEXPORT Snapshot_Class;
}
#endif

namespace Gdk
{

  class LIBMM_GDK_SYMEXPORT Snapshot : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Snapshot;
    using CppClassType = Snapshot_Class;
    using BaseObjectType = GdkSnapshot;
    using BaseClassType = GdkSnapshotClass;

    Snapshot (const Snapshot&) = delete;
    auto
    operator= (const Snapshot&) -> Snapshot& = delete;

  private:
    friend class Snapshot_Class;
    static CppClassType snapshot_class_;

  protected:
    explicit Snapshot (const Glib::ConstructParams& construct_params);
    explicit Snapshot (GdkSnapshot* castitem);

#endif

  public:
    Snapshot (Snapshot&& src) noexcept;
    auto
    operator= (Snapshot&& src) noexcept -> Snapshot&;

    ~Snapshot () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GdkSnapshot*
    {
      return reinterpret_cast<GdkSnapshot*> (gobject_);
    }

    auto
    gobj () const -> const GdkSnapshot*
    {
      return reinterpret_cast<GdkSnapshot*> (gobject_);
    }

    auto
    gobj_copy () -> GdkSnapshot*;

  private:
  public:
  public:
  public:
  protected:
  };

} // namespace Gdk

namespace Glib
{
  LIBMM_GDK_SYMEXPORT auto
  wrap (GdkSnapshot* object, bool take_copy = false) -> Glib::RefPtr<Gdk::Snapshot>;
} // namespace Glib

#endif
