// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_SOCKETCONTROLMESSAGE_H
#define _GIOMM_SOCKETCONTROLMESSAGE_H

#include <libmm/gio/mm-gioconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <set>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketControlMessage = struct _GSocketControlMessage;
using GSocketControlMessageClass = struct _GSocketControlMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gio
{
  class LIBMM_GIO_SYMEXPORT SocketControlMessage_Class;
}
#endif

namespace gio
{

  class LIBMM_GIO_SYMEXPORT SocketControlMessage : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SocketControlMessage;
    using CppClassType = SocketControlMessage_Class;
    using BaseObjectType = GSocketControlMessage;
    using BaseClassType = GSocketControlMessageClass;

    SocketControlMessage (const SocketControlMessage&) = delete;
    auto
    operator= (const SocketControlMessage&) -> SocketControlMessage& = delete;

  private:
    friend class SocketControlMessage_Class;
    static CppClassType socketcontrolmessage_class_;

  protected:
    explicit SocketControlMessage (
        const glib::ConstructParams& construct_params);
    explicit SocketControlMessage (GSocketControlMessage* castitem);

#endif

  public:
    SocketControlMessage (SocketControlMessage&& src) noexcept;
    auto
    operator= (SocketControlMessage&& src) noexcept -> SocketControlMessage&;

    ~SocketControlMessage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GSocketControlMessage*
    {
      return reinterpret_cast<GSocketControlMessage*> (gobject_);
    }

    auto
    gobj () const -> const GSocketControlMessage*
    {
      return reinterpret_cast<GSocketControlMessage*> (gobject_);
    }

    auto
    gobj_copy () -> GSocketControlMessage*;

  private:
  protected:
    SocketControlMessage ();

  public:
    static auto
    deserialize (int level, int type, gsize size, gpointer data)
        -> glib::RefPtr<SocketControlMessage>;

    auto
    get_level () const -> int;

    auto
    get_msg_type () const -> int;

    auto
    get_size () const -> gsize;

    auto
    serialize (gpointer data) -> void;

  protected:
    using DeserializeFunc =
        glib::RefPtr<SocketControlMessage> (*) (int level,
                                                int type,
                                                gsize size,
                                                gpointer data);

    static auto
    add_deserialize_func (DeserializeFunc func) -> void;

    virtual auto
    get_size_vfunc () const -> gsize;

    virtual auto
    get_level_vfunc () const -> int;

    virtual auto
    get_type_vfunc () const -> int;

    virtual auto
    serialize_vfunc (gpointer data) -> void;

  private:
    static std::set<DeserializeFunc> m_deserialize_funcs;

  public:
  public:
  protected:
  };

} // namespace gio

namespace glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GSocketControlMessage* object, bool take_copy = false) -> glib::RefPtr<gio::SocketControlMessage>;
} // namespace glib

#endif
