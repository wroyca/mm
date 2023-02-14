
#ifndef _GIOMM_SOCKETCONTROLMESSAGE_H
#define _GIOMM_SOCKETCONTROLMESSAGE_H

#include <libmm-gio/gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>
#include <set>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GSocketControlMessage = struct _GSocketControlMessage;
using GSocketControlMessageClass = struct _GSocketControlMessageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class GIOMM_API SocketControlMessage_Class;
}
#endif

namespace Gio
{

  class GIOMM_API SocketControlMessage : public Glib::Object
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
        const Glib::ConstructParams& construct_params);
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
        -> Glib::RefPtr<SocketControlMessage>;

    auto
    get_level () const -> int;

    auto
    get_msg_type () const -> int;

    auto
    get_size () const -> gsize;

    void
    serialize (gpointer data);

  protected:
    using DeserializeFunc =
        Glib::RefPtr<SocketControlMessage> (*) (int level,
                                                int type,
                                                gsize size,
                                                gpointer data);

    static void
    add_deserialize_func (DeserializeFunc func);

    virtual auto
    get_size_vfunc () const -> gsize;

    virtual auto
    get_level_vfunc () const -> int;

    virtual auto
    get_type_vfunc () const -> int;

    virtual void
    serialize_vfunc (gpointer data);

  private:
    static std::set<DeserializeFunc> m_deserialize_funcs;

  public:
  public:
  protected:
  };

} // namespace Gio

namespace Glib
{

  GIOMM_API
  auto
  wrap (GSocketControlMessage* object, bool take_copy = false) -> Glib::RefPtr<Gio::SocketControlMessage>;
} // namespace Glib

#endif
