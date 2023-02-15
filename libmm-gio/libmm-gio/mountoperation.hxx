// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GIOMM_MOUNTOPERATION_H
#define _GIOMM_MOUNTOPERATION_H

#include <libmm-gio/mm-gioconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GMountOperation = struct _GMountOperation;
using GMountOperationClass = struct _GMountOperationClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{
  class LIBMM_GIO_SYMEXPORT MountOperation_Class;
}
#endif

namespace Gio
{

  enum class AskPasswordFlags
  {
    NEED_PASSWORD = (1 << 0),
    NEED_USERNAME = (1 << 1),
    NEED_DOMAIN = (1 << 2),
    SAVING_SUPPORTED = (1 << 3),
    ANONYMOUS_SUPPORTED = (1 << 4),
    TCRYPT = (1 << 5)
  };

  inline auto
  operator| (AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  {
    return static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) |
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator& (AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  {
    return static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) &
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator^ (AskPasswordFlags lhs, AskPasswordFlags rhs) -> AskPasswordFlags
  {
    return static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) ^
                                          static_cast<unsigned> (rhs));
  }

  inline auto
  operator~(AskPasswordFlags flags) -> AskPasswordFlags
  {
    return static_cast<AskPasswordFlags> (~static_cast<unsigned> (flags));
  }

  inline auto
  operator|= (AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  {
    return (lhs = static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) |
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator&= (AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  {
    return (lhs = static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) &
                                                 static_cast<unsigned> (rhs)));
  }

  inline auto
  operator^= (AskPasswordFlags& lhs, AskPasswordFlags rhs) -> AskPasswordFlags&
  {
    return (lhs = static_cast<AskPasswordFlags> (static_cast<unsigned> (lhs) ^
                                                 static_cast<unsigned> (rhs)));
  }

  enum class PasswordSave
  {
    NEVER,
    FOR_SESSION,
    PERMANENTLY
  };

} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GIO_SYMEXPORT Value<Gio::PasswordSave>
    : public Glib::Value_Enum<Gio::PasswordSave>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gio
{

  enum class MountOperationResult
  {
    HANDLED,
    ABORTED,
    UNHANDLED
  };

  class LIBMM_GIO_SYMEXPORT MountOperation : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = MountOperation;
    using CppClassType = MountOperation_Class;
    using BaseObjectType = GMountOperation;
    using BaseClassType = GMountOperationClass;

    MountOperation (const MountOperation&) = delete;
    auto
    operator= (const MountOperation&) -> MountOperation& = delete;

  private:
    friend class MountOperation_Class;
    static CppClassType mountoperation_class_;

  protected:
    explicit MountOperation (const Glib::ConstructParams& construct_params);
    explicit MountOperation (GMountOperation* castitem);

#endif

  public:
    MountOperation (MountOperation&& src) noexcept;
    auto
    operator= (MountOperation&& src) noexcept -> MountOperation&;

    ~MountOperation () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GMountOperation*
    {
      return reinterpret_cast<GMountOperation*> (gobject_);
    }

    auto
    gobj () const -> const GMountOperation*
    {
      return reinterpret_cast<GMountOperation*> (gobject_);
    }

    auto
    gobj_copy () -> GMountOperation*;

  private:
  protected:
    MountOperation ();

  public:
    static auto
    create () -> Glib::RefPtr<MountOperation>;

    auto
    get_username () const -> Glib::ustring;

    auto
    set_username (const Glib::ustring& username) -> void;

    auto
    get_password () const -> Glib::ustring;

    auto
    set_password (const Glib::ustring& password) -> void;

    auto
    get_anonymous () const -> bool;

    auto
    set_anonymous (bool anonymous = true) -> void;

    auto
    get_domain () const -> Glib::ustring;

    auto
    set_domain (const Glib::ustring& domain) -> void;

    auto
    get_password_save () const -> PasswordSave;

    auto
    set_password_save (PasswordSave save) -> void;

    auto
    get_choice () const -> int;

    auto
    set_choice (int choice) -> void;

    auto
    reply (MountOperationResult result) -> void;

    auto
    signal_ask_password () -> Glib::SignalProxy<void (const Glib::ustring&,
                                                      const Glib::ustring&,
                                                      const Glib::ustring&,
                                                      AskPasswordFlags)>;

    auto
    signal_ask_question ()
        -> Glib::SignalProxy<void (const Glib::ustring&,
                                   const std::vector<Glib::ustring>&)>;

    auto
    signal_reply () -> Glib::SignalProxy<void (MountOperationResult)>;

    auto
    signal_aborted () -> Glib::SignalProxy<void ()>;

    auto
    signal_show_unmount_progress ()
        -> Glib::SignalProxy<void (const Glib::ustring&, gint64, gint64)>;

    auto
    property_username () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_username () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_password () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_password () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_anonymous () -> Glib::PropertyProxy<bool>;

    auto
    property_anonymous () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_domain () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_domain () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_password_save () -> Glib::PropertyProxy<PasswordSave>;

    auto
    property_password_save () const
        -> Glib::PropertyProxy_ReadOnly<PasswordSave>;

    auto
    property_choice () -> Glib::PropertyProxy<int>;

    auto
    property_choice () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
    virtual auto
    on_ask_password (const Glib::ustring& message,
                     const Glib::ustring& default_user,
                     const Glib::ustring& default_domain,
                     AskPasswordFlags flags) -> void;

    virtual auto
    on_ask_question (const Glib::ustring& message,
                     const std::vector<Glib::ustring>& choices) -> void;

    virtual auto
    on_reply (MountOperationResult result) -> void;

    virtual auto
    on_aborted () -> void;

    virtual auto
    on_show_unmount_progress (const Glib::ustring& message,
                              gint64 time_left,
                              gint64 bytes_left) -> void;
  };

} // namespace Gio

namespace Glib
{

  LIBMM_GIO_SYMEXPORT
  auto
  wrap (GMountOperation* object, bool take_copy = false) -> Glib::RefPtr<Gio::MountOperation>;
} // namespace Glib

#endif
