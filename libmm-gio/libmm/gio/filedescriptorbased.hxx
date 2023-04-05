// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_FILEDESCRIPTORBASED_H
#define _GIOMM_FILEDESCRIPTORBASED_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GFileDescriptorBasedIface GFileDescriptorBasedIface;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GFileDescriptorBased = struct _GFileDescriptorBased;
using GFileDescriptorBasedClass = struct _GFileDescriptorBasedClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT FileDescriptorBased_Class;
}
#endif

namespace gio
{

  class FileDescriptorBased : public glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = FileDescriptorBased;
    using CppClassType = FileDescriptorBased_Class;
    using BaseObjectType = GFileDescriptorBased;
    using BaseClassType = GFileDescriptorBasedIface;

    FileDescriptorBased (const FileDescriptorBased&) = delete;
    auto
    operator= (const FileDescriptorBased&) -> FileDescriptorBased& = delete;

  private:
    friend class FileDescriptorBased_Class;
    static CppClassType filedescriptorbased_class_;

#endif
  protected:
    FileDescriptorBased ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit FileDescriptorBased (const glib::Interface_Class& interface_class);

  public:
    explicit FileDescriptorBased (GFileDescriptorBased* castitem);

  protected:
#endif

  public:
    FileDescriptorBased (FileDescriptorBased&& src) noexcept;
    auto
    operator= (FileDescriptorBased&& src) noexcept -> FileDescriptorBased&;

    ~FileDescriptorBased () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GFileDescriptorBased*
    {
      return reinterpret_cast<GFileDescriptorBased*> (gobject_);
    }

    auto
    gobj () const -> const GFileDescriptorBased*
    {
      return reinterpret_cast<GFileDescriptorBased*> (gobject_);
    }

  private:
  public:
    auto
    get_fd () const -> int;

  protected:
    virtual auto
    get_fd_vfunc () const -> int;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GFileDescriptorBased* object, bool take_copy = false) -> glib::RefPtr<gio::FileDescriptorBased>;

} // namespace glib

#endif
