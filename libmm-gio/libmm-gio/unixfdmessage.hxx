// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_UNIXFDMESSAGE_H
#define _GIOMM_UNIXFDMESSAGE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/socketcontrolmessage.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GUnixFDMessage = struct _GUnixFDMessage;
using GUnixFDMessageClass = struct _GUnixFDMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT UnixFDMessage_Class;
}
#endif

namespace Gio
{

  class LIBMM_GIO_SYMEXPORT UnixFDList;

  class LIBMM_GIO_SYMEXPORT UnixFDMessage : public SocketControlMessage
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = UnixFDMessage;
    using CppClassType = UnixFDMessage_Class;
    using BaseObjectType = GUnixFDMessage;
    using BaseClassType = GUnixFDMessageClass;

    UnixFDMessage (const UnixFDMessage&) = delete;
    auto
    operator= (const UnixFDMessage&) -> UnixFDMessage& = delete;

  private:
    friend class UnixFDMessage_Class;
    static CppClassType unixfdmessage_class_;

  protected:
    explicit UnixFDMessage (const Glib::ConstructParams& construct_params);
    explicit UnixFDMessage (GUnixFDMessage* castitem);

#endif

  public:
    UnixFDMessage (UnixFDMessage&& src) noexcept;
    auto
    operator= (UnixFDMessage&& src) noexcept -> UnixFDMessage&;

    ~UnixFDMessage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GUnixFDMessage*
    {
      return reinterpret_cast<GUnixFDMessage*> (gobject_);
    }

    auto
    gobj () const -> const GUnixFDMessage*
    {
      return reinterpret_cast<GUnixFDMessage*> (gobject_);
    }

    auto
    gobj_copy () -> GUnixFDMessage*;

  private:
  protected:
    UnixFDMessage ();
    explicit UnixFDMessage (const Glib::RefPtr<UnixFDList>& fd_list);

  public:
    static auto
    create () -> Glib::RefPtr<UnixFDMessage>;

    static auto
    create (const Glib::RefPtr<UnixFDList>& fd_list)
        -> Glib::RefPtr<UnixFDMessage>;

    auto
    get_fd_list () -> Glib::RefPtr<UnixFDList>;

    auto
    get_fd_list () const -> Glib::RefPtr<const UnixFDList>;

    auto
    append_fd (int fd) -> bool;

    auto
    steal_fds () -> std::vector<int>;

    auto
    property_fd_list () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<UnixFDList>>;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GUnixFDMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::UnixFDMessage>;
} // namespace Glib

#endif
