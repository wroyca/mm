// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEICON_H
#define _GIOMM_FILEICON_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/file.hxx>
#include <libmm-gio/icon.hxx>
#include <libmm-gio/loadableicon.hxx>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileIcon = struct _GFileIcon;
using GFileIconClass = struct _GFileIconClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API FileIcon_Class;
}
#endif

namespace Gio
{

  class GIOMM_API FileIcon : public Glib::Object,
                             public Icon,
                             public LoadableIcon
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileIcon;
    using CppClassType = FileIcon_Class;
    using BaseObjectType = GFileIcon;
    using BaseClassType = GFileIconClass;

    FileIcon (const FileIcon&) = delete;
    auto
    operator= (const FileIcon&) -> FileIcon& = delete;

  private:
    friend class FileIcon_Class;
    static CppClassType fileicon_class_;

  protected:
    explicit FileIcon (const Glib::ConstructParams& construct_params);
    explicit FileIcon (GFileIcon* castitem);

#endif

  public:
    FileIcon (FileIcon&& src) noexcept;
    auto
    operator= (FileIcon&& src) noexcept -> FileIcon&;

    ~FileIcon () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileIcon*
    {
      return reinterpret_cast<GFileIcon*> (gobject_);
    }

    auto
    gobj () const -> const GFileIcon*
    {
      return reinterpret_cast<GFileIcon*> (gobject_);
    }

    auto
    gobj_copy () -> GFileIcon*;

  private:
  protected:
    FileIcon ();

  public:
    static auto
    create () -> Glib::RefPtr<FileIcon>;

    auto
    get_file () -> Glib::RefPtr<File>;

    auto
    get_file () const -> Glib::RefPtr<const File>;

    auto
    property_file () const -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<File>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GFileIcon* object, bool take_copy = false) -> Glib::RefPtr<Gio::FileIcon>;
} // namespace Glib

#endif
